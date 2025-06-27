// Global variables
let currentPage = 0;
let totalPages = 0;
let isBookOpen = false;
let autoPlayTimeout;
let isAutoPlaying = false;
let videoLoadCheckInterval;
let videoPlayers = {};
let activeVideos = {};
let currentCategory = 'educational';
let userBooks = {};
// http://localhost:3000/index.html?book=36
let currentBookMark = null;

let currentUser = null;
let isRegistering = false;
var EmailAddress;
var currentUserId;
var activeCategory = 1;
var current_bookId;

// Video durations in milliseconds (fallback if can't get actual duration)
const videoDurations = [
    25000, 10000, 9000, 12000, 11000, 15000,
    11000, 18000, 23000, 12000, 25000, 21000,
    26000, 56000
];

// Wisdom quotes for each page
const pageQuotes = [
    "Wisdom begins with wonder",
    "Knowledge is the light that dispels darkness",
    "Learning is a treasure that follows its owner everywhere",
    "The mind is not a vessel to be filled but a fire to be kindled",
    "True wisdom comes from understanding oneself",
    "Knowledge grows when shared",
    "The journey of learning never ends",
    "Curiosity is the wick in the candle of learning",
    "Education is the most powerful weapon",
    "An investment in knowledge pays the best interest",
    "Learning is a treasure that will follow its owner everywhere",
    "The beautiful thing about learning is that no one can take it away from you",
    "Education is not preparation for life; education is life itself",
    "The more that you read, the more things you will know"
];

// DOM elements
const menuBtn = document.getElementById('menuBtn');
const sidebar = document.getElementById('sidebar');
const categoryList = document.getElementById('categoryList');
const loginBtn = document.getElementById('loginBtn');
const createBookBtn = document.getElementById('createBookBtn');
const editBookBtn = document.getElementById('editBookBtn');
const loginModal = document.getElementById('loginModal');
const createBookModal = document.getElementById('createBookModal');

const authForm = document.getElementById('authForm');
const submitAuthBtn = document.getElementById('submitAuth');
const switchToRegisterBtn = document.getElementById('switchToRegister');
const submitBookBtn = document.getElementById('submitBook');
const bookLinkContainer = document.getElementById('bookLinkContainer');
const bookLink = document.getElementById('bookLink');
const copyLinkBtn = document.getElementById('copyLink');
const openBookNowBtn = document.getElementById('openBookNow');
const bookTitleElement = document.getElementById('bookTitleElement');
const bookAuthorElement = document.getElementById('bookAuthorElement');
const bookLogo = document.getElementById('bookLogo');
const bookCategorySelect = document.getElementById('bookCategory');
const toggleCategoryBtn = document.getElementById('toggleCategory');
const newCategoryInput = document.getElementById('newCategory');
const profilePhotoInput = document.getElementById('profilePhoto');
const openBtn = document.getElementById('openBtn');
const navControls = document.getElementById('navControls');
const pageIndicator = document.getElementById('pageIndicator');
const prevBtn = document.getElementById('prevBtn');
const nextBtn = document.getElementById('nextBtn');
const pagesContainer = document.getElementById('pages');
const cover = document.getElementById('cover');
const goToPageSearch = document.getElementById('goToPage');
var resultmessage;

function resultOutput(resultmessage) {

    var resultContainer = document.getElementsByClassName("resultContainer")[0];

    resultContainer.style.display = "flex";
    document.getElementsByClassName("result")[0].innerHTML = resultmessage;

    setTimeout(() => {
        resultContainer.style.display = "none";
    }, 3000);

}



// Initializing the application
function initApp() {
    loadCategories();
    setupEventListeners();
    checkMobileDevice();
    initBook();
    setupRealTimePreview();
    // Check if there's a book ID in the URL
    const urlParams = new URLSearchParams(window.location.search);
    const bookId = urlParams.get('book');



    // alert("login to start from your bookmarked Page");
    resultmessage = "login to start from your bookmarked Page";
    resultOutput(resultmessage);

    if (bookId && bookId !== 'undefined') {
        loadUserBook(bookId);
    } else {
        loadCategory(currentCategory);
    }
}

// https://support.stripe.com/questions/how-to-fix-syntaxerror-unexpected-token-in-json-at-position-0

function loadCategories() {
    let responseClone;
    fetch('backend.php?action=get_categories')
        .then(response => {
            // if (!response.ok) throw new Error('Network response was not ok');
            responseClone = response.clone();
            return response.json();
        })
        .then(categories => {
            categoryList.innerHTML = '';

            // Sort categories alphabetically by display name
            categories.sort((a, b) => a.display_name.localeCompare(b.display_name));

            categories.forEach(category => {
                const item = document.createElement('div');
                item.className = 'category-item';

                const img = document.createElement('img');
                img.src = category.logo || 'attachments/educational.jpg';
                img.alt = category.display_name;

                const span = document.createElement('span');
                span.innerHTML = category.display_name;

                item.appendChild(img);
                item.appendChild(span);

                item.addEventListener('click', () => loadCategory(category.name));
                categoryList.appendChild(item);
            });

            // Also populate the category select in create book modal
            bookCategorySelect.innerHTML = '';
            categories.forEach(category => {
                const option = document.createElement('option');
                option.value = category.name;
                option.innerHTML = category.display_name;
                bookCategorySelect.appendChild(option);
            });
        })
        .catch(error => {
            // console.error('Error loading categories:', error);
            console.log('Error loading categories:', error, responseClone);
            responseClone.text()
                .then(text => console.log('Received the following instead of valid JSON: ', text));
            loadDefaultCategories();
        });
}

function loadDefaultCategories() {
    const defaultCategories = {
        educational: {
            name: "educational",
            display_name: "Educational",
            // default_title: "Gyan Sangee",
            default_title: "Future Ready",
            default_author: "- By Sudha Kumari",
            // logo: "attachments/gyan_sangee.jpg"
            logo: "attachments/educational.jpg"
        }
    };

    categoryList.innerHTML = '';
    Object.keys(defaultCategories).forEach(categoryKey => {
        const category = defaultCategories[categoryKey];
        const item = document.createElement('div');
        item.className = 'category-item';

        const img = document.createElement('img');
        img.src = category.logo;
        img.alt = category.display_name;

        const span = document.createElement('span');
        span.innerHTML = category.display_name;

        item.appendChild(img);
        item.appendChild(span);

        item.addEventListener('click', () => loadCategory(categoryKey));
        categoryList.appendChild(item);
    });

    bookCategorySelect.innerHTML = '';
    Object.keys(defaultCategories).forEach(categoryKey => {
        const category = defaultCategories[categoryKey];
        const option = document.createElement('option');
        option.value = categoryKey;
        option.innerHTML = category.display_name;
        bookCategorySelect.appendChild(option);
    });
}



function loadCategory(category) {
    currentBookMark = null;
    currentCategory = category;
    activeCategory = 1;

    if (currentUserId !== undefined) {
        checkAndGoToBookmark();
    }

    if (isBookOpen == true) {
        closeBook();
    }

    fetch(`backend.php?action=get_category_videos&category=${category}`)
        .then(response => {
            if (!response.ok) throw new Error('Network response was not ok');
            return response.json();
        })
        .then(videos => {
            if (!videos || videos.length === 0) {
                if (category === 'educational') {
                    // Fallback to default educational videos
                    const defaultEducationalVideos = [
                        'https://www.youtube.com/embed/jWFAWvPGqt4?enablejsapi=1',
                        'https://www.youtube.com/embed/Kj7GQtkSKEA?enablejsapi=1',
                        'https://www.youtube.com/embed/sURTQXxrynQ?enablejsapi=1',
                        'https://www.youtube.com/embed/rUNCAacEalg?enablejsapi=1',
                        'https://www.youtube.com/embed/me4k9eqj2do?enablejsapi=1',
                        'https://www.youtube.com/embed/j3_Xr5aeu0Q?enablejsapi=1',
                        'https://www.youtube.com/embed/FceicupMmsE?enablejsapi=1',
                        'https://www.youtube.com/embed/ANEokonLIPg?enablejsapi=1',
                        'https://www.youtube.com/embed/fgsOUXFjceE?enablejsapi=1',
                        'https://www.youtube.com/embed/6BAFwhP0Wkw?enablejsapi=1',
                        'https://www.youtube.com/embed/GWRy-lb4goA?enablejsapi=1',
                        'https://www.youtube.com/embed/BhxFtcseoY8?enablejsapi=1',
                        'https://www.youtube.com/embed/_uWHLBv2R28?enablejsapi=1',
                        'https://www.youtube.com/embed/0NSBslUWsH8?enablejsapi=1'
                    ];
                    bookTitleElement.innerHTML = "Future Ready";
                    bookAuthorElement.innerHTML = "- By Sudha Kumari";
                    bookLogo.src = 'attachments/educational.jpg';
                    // Create empty page texts array with same length as videos
                    bookTitleElement.style.color = "#e6c050";
                    // cover.style.backgroundImage = "linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)";
                    cover.style.backgroundImage = "linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)";
                    bookAuthorElement.style.color = "#e6c050";
                    // const defaultPageTexts = Array(defaultEducationalVideos.length).fill("");


                    const defaultPageTexts = Array(videoUrls.length).fill(`Enjoy this ${category} content`);

                    createPagesFromPlaylist(defaultEducationalVideos, defaultPageTexts);
                } else {
                    bookTitleElement.innerHTML = "No Videos Found";
                    bookTitleElement.style.color = "#e6c050";
                    // cover.style.backgroundImage = "linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)";
                    cover.style.backgroundImage = "linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)";
                    bookAuthorElement.innerHTML = "- Please try another category";
                    bookAuthorElement.style.color = "#e6c050";

                    bookLogo.src = 'attachments/default_category.png';
                    createPagesFromPlaylist([], []);
                }
                closeSidebar();
                return;
            }

            // Get category details to set book title and author
            fetch('backend.php?action=get_categories')
                .then(response => response.json())
                .then(categories => {
                    const categoryData = categories.find(c => c.name === category);
                    if (categoryData) {
                        bookTitleElement.innerHTML = categoryData.default_title || "Future Ready";

                        bookTitleElement.style.color = book.titleColor;
                        bookAuthorElement.style.color = book.titleColor;
                        // cover.style.backgroundImage = book.bookCoverColor;
                        //             cover.style.backgroundImage = "none";
                        // cover.style.backgroundColor = book.bookCoverColor;



                        // For solid colors:
                        if (book.bookCoverColor && !book.bookCoverColor.includes('gradient')) {
                            cover.style.backgroundColor = book.bookCoverColor;
                        }
                        // For gradients:
                        else if (book.bookCoverColor && book.bookCoverColor.includes('gradient')) {
                            cover.style.backgroundImage = book.bookCoverColor;
                        }
                        // Fallback
                        else {
                            // cover.style.backgroundImage = "linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)";
                            cover.style.backgroundImage = "linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)";
                        }



                        bookAuthorElement.innerHTML = categoryData.default_author || "- By Sudha Kumari";
                        bookLogo.src = categoryData.logo || 'attachments/educational.jpg';
                        // cover.style.backgroundImage = categoryData.bookCoverColor;
                        // cover.style.backgroundColor = categoryData.bookCoverColor;
                        cover.style.backgroundImage = categoryData.bookCoverColor;
                        bookTitleElement.style.color = categoryData.titleColor;
                        bookAuthorElement.style.color = categoryData.titleColor;

                    }

                    const videoUrls = videos.map(video => `https://www.youtube.com/embed/${video.url}?enablejsapi=1`);

                    // For category videos, we don't have page texts, so create empty array
                    const emptyPageTexts = Array(videoUrls.length).fill("");

                    createPagesFromPlaylist(videoUrls, emptyPageTexts);

                    closeSidebar();
                });
        })
        .catch(error => {
            console.error('Error loading category videos:', error);
            loadCategory('educational'); // Fallback to educational category
        });
}








function applyCoverColor(color) {
    //  alert(color);

    const elementsToStyle = [
        cover,
        document.getElementById('previewCover') // Optional preview element
    ].filter(Boolean); // Remove null elements

    elementsToStyle.forEach(element => {
        // First completely reset all background properties
        element.style.backgroundImage = '';
        element.style.backgroundColor = '';
        element.style.backgroundImage = '';

        // Then apply the new color
        if (!color) {
            // Default gradient fallback
            element.style.backgroundImage = "linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)";
            element.style.zIndex = "1000";
        }
        else if (color.includes('gradient')) {
            element.style.backgroundImage = color;
            element.style.zIndex = "1000";
        }
        else {
            // For solid colors, ensure proper formatting
            const validColor = color.startsWith('#') ? color :
                CSS.supports('color', color) ? color :
                    `#${color}`;
            element.style.backgroundColor = validColor;
            element.style.zIndex = "1000";
        }
    });
}











// updating preview function
function updateBookPreview() {
   
    const title = document.getElementById('bookTitle').value || "My Video Book";
    const authorName = document.getElementById('bookAuthor').value || "User";
    // const BookCoverColor = document.getElementById('BookCover').value || "linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)";
    const BookCoverColor = document.getElementById('BookCover').value;


    applyCoverColor(BookCoverColor || "linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)");

    const BookCoverTitle = document.getElementById('BookCoverTitle').value || "#e6c050";
    const logoFile = document.getElementById('user_book_Logo').files[0];

    // updating the main book preview (what users will see after creation)
    bookTitleElement.innerHTML = title;
    bookAuthorElement.innerHTML = `- By ${authorName}`;
    bookTitleElement.style.color = BookCoverTitle;
    bookAuthorElement.style.color = BookCoverTitle;



    // Updating logo if selected
    if (logoFile) {
        const reader = new FileReader();
        reader.onload = function (e) {
            bookLogo.src = e.target.result;
        };
        reader.readAsDataURL(logoFile);
    }

   
    updateModalPreview(title, authorName, BookCoverColor, BookCoverTitle, logoFile);
}


function updateModalPreview(title, author, coverColor, titleColor, logoFile) {
    const previewTitle = document.getElementById('previewTitle');
    const previewAuthor = document.getElementById('previewAuthor');
    const previewCover = document.getElementById('previewCover');
    const previewLogo = document.getElementById('previewLogo');

    if (previewTitle) previewTitle.innerHTML = title;
    if (previewAuthor) previewAuthor.innerHTML = `- By ${author}`;
    if (previewTitle) previewTitle.style.color = titleColor;
    if (previewAuthor) previewAuthor.style.color = titleColor;

    if (previewCover) {
        if (coverColor.includes('gradient')) {
            previewCover.style.backgroundImage = coverColor;
            previewCover.style.backgroundColor = '';
        } else {
            previewCover.style.backgroundColor = coverColor;
            previewCover.style.backgroundImage = '';
        }
    }

    if (logoFile && previewLogo) {
        const reader = new FileReader();
        reader.onload = function (e) {
            previewLogo.src = e.target.result;
        };
        reader.readAsDataURL(logoFile);
    }
}





// Setting real-time preview listeners
function setupRealTimePreview() {
    const previewElements = {
        title: document.getElementById('bookTitle'),
        author: document.getElementById('bookAuthor'),
        coverColor: document.getElementById('BookCover'),
        titleColor: document.getElementById('BookCoverTitle'),
        logo: document.getElementById('user_book_Logo')
    };

    // Adding event listeners relevant inputs
    Object.values(previewElements).forEach(element => {
        if (element) {
            element.addEventListener('input', updateBookPreview);
            if (element.type === 'file') {
                element.addEventListener('change', updateBookPreview);
            }
        }
    });
}


function updateBookPreview() {

    const title = document.getElementById('bookTitle').value || "My Video Book";
    const authorName = document.getElementById('bookAuthor').value || "User";
    const BookCoverColor = document.getElementById('BookCover').value || "linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)";
    const BookCoverTitle = document.getElementById('BookCoverTitle').value || "#e6c050";
    const logoFile = document.getElementById('user_book_Logo').files[0];

    // updating the main book preview (what users will see after creation)
    bookTitleElement.innerHTML = title;
    bookAuthorElement.innerHTML = `- By ${authorName}`;
    bookTitleElement.style.color = BookCoverTitle;
    bookAuthorElement.style.color = BookCoverTitle;

    // updating cover background (handling both gradients and solid colors)
    if (BookCoverColor.includes('gradient')) {
        cover.style.backgroundImage = BookCoverColor;
        cover.style.backgroundColor = '';
    } else {
        cover.style.backgroundColor = BookCoverColor;
        cover.style.backgroundImage = '';
    }

    // updating logo if selected
    if (logoFile) {
        const reader = new FileReader();
        reader.onload = function (e) {
            bookLogo.src = e.target.result;
        };
        reader.readAsDataURL(logoFile);
    }

   
    updateModalPreview(title, authorName, BookCoverColor, BookCoverTitle, logoFile);
}


function updateModalPreview(title, author, coverColor, titleColor, logoFile) {
    const previewTitle = document.getElementById('previewTitle');
    const previewAuthor = document.getElementById('previewAuthor');
    const previewCover = document.getElementById('previewCover');
    const previewLogo = document.getElementById('previewLogo');

    if (previewTitle) previewTitle.innerHTML = title;
    if (previewAuthor) previewAuthor.innerHTML = `- By ${author}`;
    if (previewTitle) previewTitle.style.color = titleColor;
    if (previewAuthor) previewAuthor.style.color = titleColor;

    if (previewCover) {
        if (coverColor.includes('gradient')) {
            previewCover.style.backgroundImage = coverColor;
            previewCover.style.backgroundColor = '';
        } else {
            previewCover.style.backgroundColor = coverColor;
            previewCover.style.backgroundImage = '';
        }
    }

    if (logoFile && previewLogo) {
        const reader = new FileReader();
        reader.onload = function (e) {
            previewLogo.src = e.target.result;
        };
        reader.readAsDataURL(logoFile);
    }
}





function loadUserBook(bookId) {
    if (!bookId || bookId === 'undefined') {
        loadCategory('educational');
        return;
    }

    activeCategory = 0;
    // alert(activeCategory);
    // alert("activeCategory:" + activeCategory);//for checking
    // alert(bookId);
    // alert(currentCategory);

    current_bookId = bookId;
    currentBookMark = null;

    if (currentUserId !== undefined) {
        // initializeBookmark(currentUserId, current_bookId); // For book bookmark

        checkAndGoToBookmark();
    }






    fetch(`backend.php?action=get_user_book&book_id=${bookId}`)
        .then(response => {
            if (!response.ok) throw new Error('Network response was not ok');
            return response.json();
        })
        .then(book => {
            if (book.error) {
                resultmessage = book.error;
                resultOutput(resultmessage);
                loadCategory(currentCategory);
                return;
            }

            // Set book-specific properties first
            bookTitleElement.innerHTML = book.title || "My Video Book";
            bookAuthorElement.innerHTML = `- By ${book.author_name || 'User'}`;

            // Set colors - check if book has custom colors first
            const titleColor = book.titleColor || "#e6c050"; // Default gold
            bookTitleElement.style.color = titleColor;
            bookAuthorElement.style.color = titleColor;

            // Set cover - prioritize book color over category
            const coverColor = book.bookCoverColor ||
                (categoryData?.bookCoverColor ||
                    "linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)");

            applyCoverColor(coverColor); // Use helper function


            //  category data (only for logo fallback)
            fetch('backend.php?action=get_categories')
                .then(response => response.json())
                .then(categories => {
                    const categoryData = categories.find(c => c.name === book.category);

                    // Using book logo if available, otherwise category logo, otherwise default
                    bookLogo.src = book.logo ||
                        (categoryData?.logo || 'attachments/default_category.png');

                    // Parsing and creating pages
                    try {
                        const videoUrls = JSON.parse(book.videos);
                        const pageTexts = book.page_text ? JSON.parse(book.page_text) : [];
                        createPagesFromPlaylist(videoUrls, pageTexts);
                    } catch (e) {
                        console.error('Error parsing videos:', e);
                        loadCategory(currentCategory);
                    }
                });
        })
        .catch(error => {
            console.error('Error loading user book:', error);
            loadCategory('educational');
        });
}






function setupEventListeners() {
    menuBtn.addEventListener('click', toggleSidebar);
    loginBtn.addEventListener('click', openLoginModal);
    createBookBtn.addEventListener('click', openCreateBookModal);
    editBookBtn.addEventListener('click', editBookBtnMessage);

    document.querySelectorAll('.close-modal').forEach(btn => {
        btn.addEventListener('click', () => {
            loginModal.style.display = 'none';
            createBookModal.style.display = 'none';
        });
    });

    authForm.addEventListener('submit', handleAuth);
    switchToRegisterBtn.addEventListener('click', toggleAuthMode);

    toggleCategoryBtn.addEventListener('click', toggleNewCategoryInput);
    submitBookBtn.addEventListener('click', createUserBook);
    copyLinkBtn.addEventListener('click', copyBookLink);
    openBookNowBtn.addEventListener('click', openUserBook);

    openBtn.addEventListener('click', openBook);
    prevBtn.addEventListener('click', prevPage);
    nextBtn.addEventListener('click', nextPage);
    goToPageSearch.addEventListener('click', () => {
        var pagetyped = document.getElementById("goToPageTyped").value;
        if (pagetyped <= totalPages) {
            goToPage(pagetyped);
        }
        else {
            resultmessage = "Please Enter a valid number";
            resultOutput(resultmessage);
        }
    }
    );


    window.addEventListener('click', (e) => {
        if (e.target === loginModal) loginModal.style.display = 'none';
        if (e.target === createBookModal) createBookModal.style.display = 'none';
    });

    document.addEventListener('visibilitychange', handleVisibilityChange);
    window.addEventListener('message', handleYouTubeMessages);
}

function toggleSidebar() {
    menuBtn.classList.toggle('active');
    sidebar.classList.toggle('open');
}

function closeSidebar() {
    menuBtn.classList.remove('active');
    sidebar.classList.remove('open');
}

function openLoginModal() {
    loginModal.style.display = 'flex';
    closeSidebar();
}

function openCreateBookModal() {
    if (!currentUser) {
        // alert('Please login to create a book');
        resultmessage = 'Please login to create a book';
        resultOutput(resultmessage);
        openLoginModal();
        return;
    }
    createBookModal.style.display = 'flex';
    closeSidebar();
}


function editBookBtnMessage() {
    if (!currentUser) {
        // alert('Please login to create a book');
        resultmessage = 'Please login to edit a book';
        resultOutput(resultmessage);
        openLoginModal();
        return;
    }
    // createBookModal.style.display = 'flex';
    // closeSidebar();

    resultmessage = 'Sorry, this feature is not available since published books can\'t be edited.\n You can create new book instead';
    resultOutput(resultmessage);
}




function toggleAuthMode() {
    isRegistering = !isRegistering;
    submitAuthBtn.innerHTML = isRegistering ? 'Register' : 'Login';
    switchToRegisterBtn.innerHTML = isRegistering ? 'Already have an account? Login' : 'Create an account';
    profilePhotoInput.style.display = isRegistering ? 'block' : 'none';
}

function handleAuth(e) {
    e.preventDefault();
    const email = document.getElementById('email').value;

    const password = document.getElementById('password').value;
    const profilePhoto = profilePhotoInput.files[0];
    // For registration
    const nameEntered = document.getElementById('name').value;

    if (isRegistering) {
        if (profilePhoto) {
            const reader = new FileReader();
            reader.onload = function (e) {
                // registerUser(email, password, e.target.result);
                registerUser(nameEntered, email, password, e.target.result);
            };
            reader.readAsDataURL(profilePhoto);
        } else {
            // registerUser(email, password, null);
            registerUser(nameEntered, email, password, null);
        }
    } else {
        loginUser(email, password);
    }
}

// var nameReceived="";
function registerUser(nameEntered, email, password, profilePhoto) {
    // alert(nameEntered);
    fetch('backend.php', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({
            action: 'register',
            email: email,
            password: password,
            namePassed: nameEntered,
            profile_photo: profilePhoto
        })


    })

        .then(handleApiResponse)
        .then(data => {
            //   alert(body);
            currentUser = {
                id: data.user_id,
                nameReceived: data.user_name,
                email: data.email,
                profilePhoto: data.profile_photo || 'attachments/default_user.png'

            };

            // alert(JSON.stringify(currentUser));

            // if(data.email != undefined){
            // alert(`Welcome ${data.email}! Your account has been created.`);
            // alert(`Welcome ${data.user_name}! Your account has been created.`);
            resultmessage = `Welcome ${data.user_name}! Your account has been created.`;
            resultOutput(resultmessage);

            // alert(`Welcome ${nameReceived}! Your account has been created.`);
            // }else{
            // alert(`Welcome ${email}! Your account has been created.`);
            // }

            EmailAddress = data.email;
            currentUserId = data.user_id;

            loginModal.style.display = 'none';

            if (data.profile_photo) {
                bookLogo.src = data.profile_photo;
            }
        })
        .catch(error => {
            console.error('Error:', error);
            // alert(error.message || 'Registration failed. Please try again.');

            resultmessage = error.message || 'Registration failed. Please try again.';
            resultOutput(resultmessage);

        });
}

function loginUser(email, password) {
    if (!email || !password) {
        // alert('Please enter both email and password');
        resultmessage = 'Please enter both email and password';
        resultOutput(resultmessage);

        return;
    }

    const profilePhotoFile = profilePhotoInput.files[0];

    if (profilePhotoFile) {
        const reader = new FileReader();
        reader.onload = function (e) {
            performLogin({
                action: 'login',
                email: email,
                password: password,
                profile_photo: e.target.result
            });
        };
        reader.onerror = () => {
            performLogin({
                action: 'login',
                email: email,
                password: password
            });
        };
        reader.readAsDataURL(profilePhotoFile);
    } else {
        performLogin({
            action: 'login',
            email: email,
            password: password
        });
    }
}

function performLogin(requestData) {
    fetch('backend.php', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify(requestData)
    })
        .then(
            // handleApiResponse

            function handleApiResponse(response) {
                if (!response.ok) {
                    return response.json().then(err => {
                        throw new Error(err.message || 'Sorry, You are not registered, Please Register First.');
                    });
                }
                return response.json();
            }

        )
        .then(handleLoginSuccess)
        .catch(handleLoginError);
}

function handleApiResponse(response) {
    if (!response.ok) {
        return response.json().then(err => {
            throw new Error(err.message || 'Request failed');
        });
    }
    return response.json();
}

function handleLoginSuccess(data) {
    if (data.error) {
        throw new Error(data.message || data.error);
    }

    currentUser = {
        id: data.user_id,
        email: data.email,
        userName: data.userName_Data,
        profilePhoto: data.profile_photo || 'attachments/default_user.png'
    };

    // alert(`Welcome back ${data.email}!`);
    // alert(`Welcome back ${data.userName_Data}!`);

    resultmessage = `Welcome back ${data.userName_Data}!`;
    resultOutput(resultmessage);

    EmailAddress = data.email;
    currentUserId = data.user_id;




    checkAndGoToBookmark();


    loginModal.style.display = 'none';

    if (data.profile_photo) {
        bookLogo.src = data.profile_photo;
    }
    profilePhotoInput.value = '';
}

function handleLoginError(error) {
    console.error('Login Error:', error);
    // alert(error.message || 'Login failed. Please try again.');
    resultmessage = error.message || 'Login failed. Please try again.';
    resultOutput(resultmessage);
}

function toggleNewCategoryInput() {
    if (newCategoryInput.style.display === 'none') {
        newCategoryInput.style.display = 'block';
        bookCategorySelect.style.display = 'none';
        toggleCategoryBtn.innerHTML = 'Use Existing Category';
    } else {
        newCategoryInput.style.display = 'none';
        bookCategorySelect.style.display = 'block';
        toggleCategoryBtn.innerHTML = 'Add New Category';
    }
}






function extractYouTubeId(url) {
    const patterns = [
        /youtu\.be\/([^"&?\/\s]{11})/,                        // youtu.be links
        /youtube(?:-nocookie)?\.com\/shorts\/([^"&?\/\s]{11})/, // Shorts
        /youtube(?:-nocookie)?\.com\/(?:embed|v)\/([^"&?\/\s]{11})/, // Embed/v
        /youtube(?:-nocookie)?\.com\/watch\?.*v=([^"&?\/\s]{11})/, // Watch
        /youtube(?:-nocookie)?\.com\/[^\/]+\/[^\/]+\/([^"&?\/\s]{11})/ // Other paths
    ];

    for (const pattern of patterns) {
        const match = url.match(pattern);
        if (match && match[1]) return match[1];
    }
    return null;
}




function createUserBook() {
    const title = document.getElementById('bookTitle').value || "My Video Book";
    // For book creation
    const authorName = document.getElementById('bookAuthor').value;
    // const user_book_Logo_Passed = document.getElementById('user_book_Logo');

    const BookCoverColor = document.getElementById('BookCover').value;
    const BookCoverTitle = document.getElementById('BookCoverTitle').value;






    let category;
    let categoryKey;

    if (newCategoryInput.style.display === 'block' && newCategoryInput.value.trim() !== '') {
        category = newCategoryInput.value.trim();
        categoryKey = category.toLowerCase().replace(/\s+/g, '_');
    } else {
        categoryKey = bookCategorySelect.value;
        category = bookCategorySelect.options[bookCategorySelect.selectedIndex].text;
    }

    // Get URLs and process them//only for embed links
    const urlsText = document.getElementById('videoUrls').value;

   


    const urls = urlsText.split('\n')
        .map(url => url.trim())
        .filter(url => url)
        .map(url => {
            const videoId = extractYouTubeId(url);
            return videoId ? `https://www.youtube.com/embed/${videoId}?enablejsapi=1` : null;
        })
        .filter(url => url !== null);

    if (urls.length === 0) {
        // alert('Please enter valid YouTube URLs (one per line)');
        resultmessage = 'Please enter valid YouTube URLs (one per line)';
        resultOutput(resultmessage);
        return;
    }


    // Get page texts
    // const pageTexts = document.getElementById('videoPageText').value.split('\n')
    const pageTexts = document.getElementById('videoPageText').value.split('\n\n\n')
        .map(text => text.trim())
        .filter(text => text);

    // If no texts provided, create empty array with same length as URLs
    const finalPageTexts = pageTexts.length > 0 ?
        pageTexts :
        Array(urls.length).fill("");







    const user_book_Logo_try = document.getElementById('user_book_Logo');
    var user_book_Logo_Passed = user_book_Logo_try.files[0];
    //  alert(JSON.stringify(user_book_Logo_Passed));
    if (user_book_Logo_Passed) {
        const readerBook = new FileReader();
        readerBook.onload = function (e) {
            user_book_Logo_Passed = e.target.result;//You can't reassign a variable declared with const. Changed to use a new variable for the base64 string.
            // alert(JSON.stringify(user_book_Logo_Passed));
            fetch('backend.php', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({
                    action: 'save_book',
                    user_id: currentUser.id,
                    title: title,
                    category: categoryKey,
                    videos: urls,
                    page_text: finalPageTexts,
                    author_name: authorName,
                    book_cover_color: BookCoverColor,
                    book_cover_title: BookCoverTitle,
                    // author_email: currentUser.email,
                    user_book_Logo: user_book_Logo_Passed

                })
            })
                .then(handleApiResponse)
                .then(data => {
                    if (!data.success) {
                        throw new Error(data.error || 'Unknown error occurred');
                    }

                    if (!data.book_id) {
                        throw new Error('Book ID not returned from server');
                    }

                    const shareLink = `${window.location.origin}${window.location.pathname}?book=${data.book_id}`;
                    bookLink.value = shareLink;
                    bookLinkContainer.style.display = 'block';

                    userBooks[data.book_id] = {
                        title: title,
                        category: categoryKey,
                        videos: urls,
                        page_text: finalPageTexts,
                        createdAt: new Date().toISOString(),
                        userId: currentUser.id,
                        book_cover_color: BookCoverColor,
                        book_cover_title: BookCoverTitle,
                        logo_path: data.logo_path || null

                    };
                })
                .catch(error => {
                    console.error('Error:', error);
                    // alert(error.message || 'Failed to save book. Please try again.');
                    resultmessage = error.message || 'Failed to save book. Please try again.';
                    resultOutput(resultmessage);
                });
        };
        readerBook.readAsDataURL(user_book_Logo_Passed);

    } else {
        user_book_Logo_Passed = null;
        fetch('backend.php', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({
                action: 'save_book',
                user_id: currentUser.id,
                title: title,
                category: categoryKey,
                videos: urls,
                page_text: finalPageTexts,
                author_name: authorName,
                book_cover_color: BookCoverColor,
                book_cover_title: BookCoverTitle,
                // author_email: currentUser.email,
                user_book_Logo: user_book_Logo_Passed

            })
        })
            .then(handleApiResponse)
            .then(data => {
                if (!data.success) {
                    throw new Error(data.error || 'Unknown error occurred');
                }

                if (!data.book_id) {
                    throw new Error('Book ID not returned from server');
                }

                const shareLink = `${window.location.origin}${window.location.pathname}?book=${data.book_id}`;
                bookLink.value = shareLink;
                bookLinkContainer.style.display = 'block';

                userBooks[data.book_id] = {
                    title: title,
                    category: categoryKey,
                    videos: urls,
                    page_text: finalPageTexts,
                    createdAt: new Date().toISOString(),
                    userId: currentUser.id,
                    book_cover_color: BookCoverColor,
                    book_cover_title: BookCoverTitle,
                    logo_path: data.logo_path || null
                };
            })
            .catch(error => {
                console.error('Error:', error);
                // alert(error.message || 'Failed to save book. Please try again.');
                resultmessage = error.message || 'Failed to save book. Please try again.';
                resultOutput(resultmessage);
            });
    }

   
}



/*
https://www.youtube.com/embed/HoEVHKzlIGk?si=r7sWe7S1D5atvU_M
https://www.youtube.com/embed/Lx2TquDMYXc?si=fIaGfpJn3Xj8Z8Lf
*/










function copyBookLink() {
    bookLink.select();
    document.execCommand('copy');
    // alert('Link copied to clipboard!');
    resultmessage = 'Link copied to clipboard!';
    resultOutput(resultmessage);
}


function openUserBook() {
    const bookId = bookLink.value.split('book=')[1];
    if (bookId) {
        window.location.href = `${window.location.pathname}?book=${bookId}`;
        // current_bookId=bookId;
    }
}

function checkMobileDevice() {
    if (/Mobi|Android/i.test(navigator.userAgent)) {
        const decorations = document.querySelectorAll('.premium-decoration');
        decorations.forEach(decoration => decoration.remove());
    }
}

function initBook() {
    const starsContainer = document.getElementById('stars');
    for (let i = 0; i < 150; i++) {
        const star = document.createElement('div');
        star.classList.add('star');
        star.style.width = `${Math.random() * 4 + 1}px`;
        star.style.height = star.style.width;
        star.style.left = `${Math.random() * 100}%`;
        star.style.top = `${Math.random() * 100}%`;
        star.style.setProperty('--duration', `${Math.random() * 4 + 2}s`);
        star.style.setProperty('--opacity', `${Math.random() * 0.8 + 0.2}`);
        star.style.animationDelay = `${Math.random() * 6}s`;
        starsContainer.appendChild(star);
    }

    if (!/Mobi|Android/i.test(navigator.userAgent)) {
        for (let i = 0; i < 8; i++) {
            const decor = document.createElement('div');
            decor.classList.add('premium-decoration');
            decor.style.top = `${Math.random() * 90}%`;
            decor.style.left = `${Math.random() * 90}%`;
            decor.style.zIndex = 1;
            decor.style.transform = `rotate(${Math.random() * 360}deg) scale(${Math.random() * 0.5 + 0.5})`;
            document.body.appendChild(decor);
        }
    }
}


function createPagesFromPlaylist(videos = [], pageTexts = []) {
    pagesContainer.innerHTML = '';

    // Calculate total pages - each video may have multiple text pages
    let totalVideoPages = 0;
    const textPagesPerVideo = [];

    // First calculate how many pages each video's text will need
    for (let i = 0; i < videos.length; i++) {
        const text = pageTexts[i] || '';
        const textLength = text.length;

        let pagesNeeded = 1; // At least one page for each video

        if (textLength > 80) { // Adjust this threshold as needed
            // First page takes first 80 chars, remaining goes to additional pages
            const remainingChars = textLength - 80;
            pagesNeeded += Math.ceil(remainingChars / 450); // Adjust this value as needed
        }

        textPagesPerVideo.push(pagesNeeded);
        totalVideoPages += pagesNeeded;
    }

    totalPages = totalVideoPages + 1; // +1 for the final page

    let globalPageIndex = 0;

    for (let videoIndex = 0; videoIndex < videos.length; videoIndex++) {
        const videoUrl = videos[videoIndex];
        const text = pageTexts[videoIndex] || '';
        const pagesForThisVideo = textPagesPerVideo[videoIndex];

      
        let textChunks = [];
        if (text.length > 0) {
            if (text.length <= 80) {
                textChunks = [text];
            } else {
                // Handling first page (80 chars)
                const firstPageText = text.substring(0, 80);
                const lastSpaceInFirstPage = firstPageText.lastIndexOf(' ');

                let actualFirstPageText, remainingText;

                if (lastSpaceInFirstPage === -1 || lastSpaceInFirstPage === 79) {
                    // No space found or space at the very end
                    actualFirstPageText = firstPageText;
                    remainingText = text.substring(80);
                } else {
                    // Split at last space to avoid breaking words
                    actualFirstPageText = firstPageText.substring(0, lastSpaceInFirstPage);
                    remainingText = text.substring(lastSpaceInFirstPage + 1);
                }

                textChunks.push(actualFirstPageText);

                // Handling remaining pages (450 chars each)
                while (remainingText.length > 0) {
                    if (remainingText.length <= 450) {
                        textChunks.push(remainingText);
                        remainingText = '';
                    } else {
                        const chunk = remainingText.substring(0, 450);
                        const lastSpaceInChunk = chunk.lastIndexOf(' ');

                        if (lastSpaceInChunk === -1 || lastSpaceInChunk === 449) {
                            // No space found or space at the very end
                            textChunks.push(chunk);
                            remainingText = remainingText.substring(450);
                        } else {
                            // Split at last space to avoid breaking words
                            textChunks.push(chunk.substring(0, lastSpaceInChunk));
                            remainingText = remainingText.substring(lastSpaceInChunk + 1);
                        }
                    }
                }
            }
        } else {
            textChunks = [''];
        }

        for (let textPageIndex = 0; textPageIndex < pagesForThisVideo; textPageIndex++) {
            globalPageIndex++;
            const page = document.createElement('div');
            page.className = 'page';
            page.id = `page${globalPageIndex}`;

            const pageContent = document.createElement('div');
            pageContent.className = 'page-content';
            // pageContent.style.overflow = 'hidden'; // Prevent container overflow

            // Add video only on first page
            if (textPageIndex === 0) {
                const videoContainer = document.createElement('div');
                videoContainer.className = 'video-container';

                const iframe = document.createElement('iframe');
                iframe.id = `video${globalPageIndex}`;
                iframe.className = 'video';
                if (videoUrl.includes("embed")) {
                    iframe.src = videoUrl;// for embed only
                } else {
                    iframe.src = `https://www.youtube.com/embed/${videoUrl}?enablejsapi=1`;//for all
                }
                iframe.setAttribute('frameborder', '0');
                iframe.setAttribute('allowfullscreen', '');
                iframe.setAttribute('allow', 'accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture');

                videoContainer.appendChild(iframe);
                pageContent.appendChild(videoContainer);
            }

            // Create text element with overflow prevention
            const pageTextElement = document.createElement('div');
            pageTextElement.className = 'page-text';

            // Get the text chunk for this page
            let pageText = textChunks[textPageIndex] || '';

            // Add hyphen if the last character is not a space and there's more text after
            if (textPageIndex < textChunks.length - 1 &&
                pageText.length > 0 &&
                pageText[pageText.length - 1] !== ' ' &&
                textChunks[textPageIndex + 1].length > 0) {
                pageText += '-';
            }

            // pageTextElement.innerHTML = pageText;
            pageTextElement.innerHTML = pageText;
            // pageTextElement.style.overflow = 'hidden';
            pageTextElement.style.wordBreak = 'break-word';
            pageTextElement.style.overflowWrap = 'break-word';

            // Apply styling
            if (textPageIndex === 0) {
                // pageTextElement.style.textAlign = 'center';
                pageTextElement.style.textAlign = 'left';
                pageTextElement.style.margin = '20px auto';
                pageTextElement.style.maxWidth = '80%';
            } else {
                pageTextElement.style.textAlign = 'left';
                // pageTextElement.style.margin = '20px 40px';
                pageTextElement.style.maxWidth = '90%';
                // pageTextElement.style.overflowX = 'hidden';
            }

            const pageNumber = document.createElement('div');
            pageNumber.className = 'page-number';
            pageNumber.innerHTML = `Page ${globalPageIndex}`;

            const bookmark = document.createElement('div');
            bookmark.className = 'bookmark';
            bookmark.innerHTML = `BookMark Page ${globalPageIndex}`;

            pageContent.appendChild(pageTextElement);
            page.appendChild(pageContent);
            page.appendChild(pageNumber);
            page.appendChild(bookmark);

            bookmark.addEventListener('click', () => bookmarkPageFun(globalPageIndex));

            // Navigation buttons
            if (globalPageIndex > 1) {
                const prevBtn = document.createElement('button');
                prevBtn.className = 'page-nav prev-page';
                prevBtn.innerHTML = '&lt;';
                prevBtn.addEventListener('click', prevPage);
                page.appendChild(prevBtn);
            }

            if (globalPageIndex < totalPages) {
                const nextBtn = document.createElement('button');
                nextBtn.className = 'page-nav next-page';
                nextBtn.innerHTML = '&gt;';
                nextBtn.addEventListener('click', nextPage);
                page.appendChild(nextBtn);
            }

            pagesContainer.appendChild(page);
        }
    }

    // Adding final page for page turn good look
    const finalPageIndex = globalPageIndex + 1;
    const page = document.createElement('div');
    page.className = 'page';
    page.id = `page${finalPageIndex}`;

    const pageContent = document.createElement('div');
    pageContent.className = 'page-content';

    const imageContainer = document.createElement('div');
    imageContainer.className = 'image-container';

    const img = document.createElement('img');
    img.src = 'attachments/Gyan Sangee.png';
    img.alt = 'Gyan Sangee';
    img.className = 'final-page-image';

    imageContainer.appendChild(img);
    pageContent.appendChild(imageContainer);

    const pageNumber = document.createElement('div');
    pageNumber.className = 'page-number';
    pageNumber.innerHTML = `Page ${finalPageIndex}`;

    const bookmark = document.createElement('div');
    bookmark.className = 'bookmark';
    bookmark.innerHTML = `BookMark Page ${finalPageIndex}`;

    pageContent.appendChild(pageNumber);
    page.appendChild(pageContent);
    page.appendChild(bookmark);

    bookmark.addEventListener('click', () => bookmarkPageFun(finalPageIndex));

    if (finalPageIndex > 1) {
        const prevBtn = document.createElement('button');
        prevBtn.className = 'page-nav prev-page';
        prevBtn.innerHTML = '&lt;';
        prevBtn.addEventListener('click', prevPage);
        page.appendChild(prevBtn);
    }

    pagesContainer.appendChild(page);
    currentPage = 0;
    updatePageIndicator();
}


function handleYouTubeMessages(event) {
    try {
        const data = JSON.parse(event.data);
        if (data.event === 'onReady') {
            const iframeId = data.id;
            videoPlayers[iframeId] = true;
            activeVideos[iframeId] = true;
        }
    } catch (e) {
        // Not a YouTube API message
    }
}

function openBook() {



    isBookOpen = true;
    openBtn.classList.add('hidden');
    navControls.classList.remove('hidden');
    // navControls.style.display = 'flex';
    navControls.style.display = 'grid';
    cover.style.transform = 'rotateY(-160deg)';

    setTimeout(() => {

        // goToPage(1);

        if (currentBookMark != null) {
            goToPage(currentBookMark);
        }
        else {
            goToPage(1);
        }

    }, 1000);
}

function closeBook() {
    if (!isBookOpen) return;



    isBookOpen = false;
    clearTimeout(autoPlayTimeout);
    clearInterval(videoLoadCheckInterval);
    isAutoPlaying = false;

    Object.keys(activeVideos).forEach(videoId => {
        const iframe = document.getElementById(videoId);
        if (iframe && iframe.contentWindow) {
            iframe.contentWindow.postMessage('{"event":"command","func":"pauseVideo","args":""}', '*');
        }
    });
    activeVideos = {};

    const pages = document.querySelectorAll('.page');
    pages.forEach(page => {
        page.style.transform = 'rotateY(0deg)';
        page.classList.remove('turning');
        page.classList.remove('active');
    });


    setTimeout(() => {
        cover.style.transform = 'rotateY(0deg)';
        openBtn.classList.remove('hidden');
        navControls.classList.add('hidden');
        navControls.style.display = "none";

        // openBtn.classList.remove('hidden');
        // navControls.style.display = "none";

    }, 500);

    currentPage = 0;
}

function updatePageIndicator() {
    pageIndicator.innerHTML = `Page ${currentPage}/${totalPages}`;
}

function goToPage(pageNum) {
    if (pageNum < 1 || pageNum > totalPages) return;

    clearTimeout(autoPlayTimeout);
    clearInterval(videoLoadCheckInterval);
    isAutoPlaying = false;

    // alert(pageNum);

    if (currentPage > 0 && currentPage <= totalPages) {
        const currentVideo = document.getElementById(`video${currentPage}`);
        if (currentVideo && currentVideo.contentWindow) {
            currentVideo.contentWindow.postMessage('{"event":"command","func":"pauseVideo","args":""}', '*');
            delete activeVideos[`video${currentPage}`];
        }
    }

    const pages = document.querySelectorAll('.page');
    pages.forEach(page => {
        page.style.transform = 'rotateY(0deg)';
        page.classList.remove('turning');
        page.classList.remove('active');
    });

    for (let i = 1; i < pageNum; i++) {
        const prevPage = document.getElementById(`page${i}`);
        if (prevPage) {
            prevPage.style.transform = 'rotateY(-180deg)';
        }
    }

    const currentPageElement = document.getElementById(`page${pageNum}`);
    if (currentPageElement) {
        currentPageElement.classList.add('active');
    }

    currentPage = pageNum;
    updatePageIndicator();

    if (pageNum == totalPages) {
        autoPlayTimeout = setTimeout(() => {
            closeBook();
        }, 5000);
    } else {
        autoPlayCurrentPage();
    }
}

function autoPlayCurrentPage() {
    if (!isBookOpen || currentPage < 1 || currentPage >= totalPages) return;

    isAutoPlaying = true;
    const currentPageElement = document.getElementById(`page${currentPage}`);
    const iframe = currentPageElement ? currentPageElement.querySelector('iframe') : null;

    if (!iframe) return;

    clearTimeout(autoPlayTimeout);
    clearInterval(videoLoadCheckInterval);

    activeVideos[iframe.id] = true;
    iframe.contentWindow.postMessage('{"event":"command","func":"playVideo","args":""}', '*');

    let attempts = 0;
    const maxAttempts = 15;
    const checkInterval = 800;

    videoLoadCheckInterval = setInterval(() => {
        attempts++;

        try {
            iframe.contentWindow.postMessage('{"event":"command","func":"getPlayerState","args":""}', '*');

            const onMessage = function (e) {
                if (e.source !== iframe.contentWindow) return;

                try {
                    const data = JSON.parse(e.data);
                    if (data.info && data.info.duration) {
                        clearInterval(videoLoadCheckInterval);
                        window.removeEventListener('message', onMessage);

                        const duration = videoDurations[currentPage - 1] || (data.info.duration * 1000) + 1000;
                        autoPlayTimeout = setTimeout(() => {
                            if (currentPage < totalPages) {
                                turnPage(currentPage);
                            }
                        }, duration);
                    }
                } catch (err) {
                    console.log('Error parsing video data', err);
                }
            };

            window.addEventListener('message', onMessage);

        } catch (err) {
            console.log('Video not ready yet', err);
        }

        if (attempts >= maxAttempts) {
            clearInterval(videoLoadCheckInterval);
            const duration = videoDurations[currentPage - 1] || 30000;
            autoPlayTimeout = setTimeout(() => {
                if (currentPage < totalPages) {
                    // turnPage(currentPage);//tuning it of as duration is not put by users mainly
                }
            }, duration);
        }
    }, checkInterval);
}

function turnPage(pageNum) {
    if (pageNum < 1 || pageNum >= totalPages) return;

    const page = document.getElementById(`page${pageNum}`);
    if (!page) return;

    const iframe = page.querySelector('iframe');
    if (iframe && iframe.contentWindow) {
        iframe.contentWindow.postMessage('{"event":"command","func":"pauseVideo","args":""}', '*');
        delete activeVideos[iframe.id];
    }

    page.classList.add('turning');

    setTimeout(() => {
        page.style.transform = 'rotateY(-180deg)';
        page.classList.remove('turning');
        goToPage(pageNum + 1);
    }, 1000);
}

function prevPage() {
    if (currentPage <= 1) return;
    pauseCurrentVideo();
    goToPage(currentPage - 1);
}

function nextPage() {
    if (currentPage >= totalPages) return;
    pauseCurrentVideo();

    if (currentPage < totalPages) {
        turnPage(currentPage);
    }
}


function bookmarkPageFun(bookmarkPage) {



    if (currentUserId == undefined) {
        // alert("Please login to save your bookmark");
        resultmessage = "Please login to save your bookmark";
        resultOutput(resultmessage);
        return;
    }

    else {
        if (activeCategory) {
            // alert("bookmark " + currentCategory);

            saveBookmark(currentUserId, null, currentCategory, bookmarkPage);

        }
        else {
            // alert("bookmark " + current_bookId);

            saveBookmark(currentUserId, current_bookId, null, bookmarkPage);
        }


    }
}




function saveBookmark(userID, bookID, categoryName, bookmarkPage) {
    

    const data = {
        action: 'saveBookmark',
        userID: userID,
        bookmarkPage: bookmarkPage
    };

    // Only include bookID or categoryName if provided
    if (bookID) {
        data.bookID = bookID;
    } else if (categoryName) {
        data.categoryName = categoryName;
    }

    fetch('features.php', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify(data)
    })
        .then(response => response.json())
        .then(data => {
            if (data.success) {
                // alert(`Your bookmark on page ${bookmarkPage} is saved successfully!`);
                resultmessage = `Your bookmark on page ${bookmarkPage} is saved successfully!`;
                resultOutput(resultmessage);
            } else {
                // alert('Error saving bookmark: ' + data.message);
                resultmessage = 'Error saving bookmark: ' + data.message;
                resultOutput(resultmessage);
            }
        })
        .catch(error => {
            console.error('Error:', error);
            // alert('An error occurred while saving the bookmark.');
            resultmessage = 'An error occurred while saving the bookmark.';
            resultOutput(resultmessage);
        });
}






//to initialize bookmark


function initializeBookmark(userId, bookId = null, categoryName = null) {


    //To make the code wait for the result of initializeBookmark before checking currentBookMark, we need to make initializeBookmark return a Promise and then use async/await.

    return new Promise((resolve, reject) => {//for async/ await

        if (!userId) {
            console.log("User not logged in - cannot fetch bookmark");
            return;
        }

        if (!bookId && !categoryName) {
            console.log("Either bookId or categoryName must be provided");
            return;
        }

        const data = {
            action: 'getBookmark',
            userId: userId,
            bookId: bookId || null,
            categoryName: categoryName || null
        };

        fetch('features.php', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify(data)
        })
            .then(response => response.json())
            .then(data => {
                if (data.success && data.bookmarkPage !== null) {
                    currentBookMark = data.bookmarkPage;
                    console.log(`Bookmark initialized to page ${currentBookMark}`);
                    resolve(currentBookMark);//for async/ await
                } else {
                    currentBookMark = null;
                    console.log("No bookmark found for these parameters");
                    resolve(null);//for async/ await
                }
            })
            .catch(error => {
                console.error('Error fetching bookmark:', error);
                currentBookMark = null;
                reject(error);//for async/ await
            });
    });//   for async/ await
}



//To make the code wait for the result of initializeBookmark before checking currentBookMark, we need to make initializeBookmark return a Promise and then use async/await

async function checkAndGoToBookmark() {
    if (currentBookMark == null) {
        let bookmarkPageIni;

        if (activeCategory) {
            bookmarkPageIni = await initializeBookmark(currentUserId, null, currentCategory);
        } else {
            bookmarkPageIni = await initializeBookmark(currentUserId, current_bookId);
        }

        if (bookmarkPageIni !== null && isBookOpen) {
            goToPage(bookmarkPageIni);
        }
    } else if (isBookOpen) {
        // If we already have a bookmark and book is open
        goToPage(currentBookMark);
    }
}





function pauseCurrentVideo() {
    if (currentPage < 1 || currentPage > totalPages) return;
    const currentPageElement = document.getElementById(`page${currentPage}`);
    if (!currentPageElement) return;

    const iframe = currentPageElement.querySelector('iframe');
    if (iframe && iframe.contentWindow) {
        iframe.contentWindow.postMessage('{"event":"command","func":"pauseVideo","args":""}', '*');
        delete activeVideos[iframe.id];
    }

    clearTimeout(autoPlayTimeout);
    clearInterval(videoLoadCheckInterval);
    isAutoPlaying = false;
}

function handleVisibilityChange() {
    if (document.hidden) {
        pauseCurrentVideo();
    } else if (isBookOpen && isAutoPlaying) {
        autoPlayCurrentPage();
    }
}

document.addEventListener('DOMContentLoaded', initApp);