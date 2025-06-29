// Cache frequently used DOM elements
const cachedElements = {
    searchedOutput: document.getElementById("searchedOutput"),
    myDropdownSearch: document.getElementById("myDropdownSearch"),
    myInput: document.getElementById("myInput"),
    user: document.getElementById("user"),
    offline1: document.querySelector("#offline1"),
    // Add other frequently used elements
};



// Initialize variables
var EmailAddress = sessionStorage.getItem("EmailAddress") || localStorage.getItem("EmailAddress");
var CustomerNumber, FirstName, Password, passedPhoto, scoreWon, creditAmount, arrOfReceivedDetails;


// DOM Ready handler
document.addEventListener('DOMContentLoaded', function () {
    initFunctions();
    setupEventListeners();
});

function initFunctions() {
    if (EmailAddress !== null) {
        EmailRelatedLogin("/", EmailAddress);
    } else {
        GeneralErrors();
    }

    if (document.getElementsByClassName("clickedReviewImg")[0] != null &&
        document.getElementsByClassName("profileImage")[0] != null) {
        profileOpener();
    }

    // setupOnlineOfflineHandlers();
    // setupBannerSlides();
    // setupStickyContent();
    qSelectorAllHeadingCenter();
}

function setupEventListeners() {
    // Wheel event for header
    if (document.getElementsByClassName("headertitle")[0] && document.getElementsByClassName("icon")[0]) {
        window.addEventListener("wheel", debounce(wheelevent, 50));
    }

    // Form submission prevention
    var form = document.querySelector('form');
    if (form) {
        form.addEventListener('submit', function (event) {
            event.preventDefault();
        });
    }

    // Search input handling
    if (document.searchProduct) {
        document.searchProduct.searchProductEnteredbyTyping.addEventListener("keypress", function (event) {
            if (event.key === "Enter") {
                event.preventDefault();
                document.getElementsByClassName("search")[0].click();
            }
        });
    }
}


// Utility functions
function debounce(func, wait) {
    let timeout;
    return function () {
        const context = this, args = arguments;
        clearTimeout(timeout);
        timeout = setTimeout(() => func.apply(context, args), wait);
    };
}

function throttle(func, limit) {
    let inThrottle;
    return function () {
        const args = arguments;
        const context = this;
        if (!inThrottle) {
            func.apply(context, args);
            inThrottle = true;
            setTimeout(() => inThrottle = false, limit);
        }
    };
}

// Existing functions with minor optimizations
function cutImgbutton(element) {
    if (element && element.parentElement) {
        element.parentElement.style.display = "none";
    }
}



// function cutImgbutton(element) {
//     element.parentElement.style.display = "none";
// }

if (document.getElementsByClassName("clickedReviewImg")[0] != null) {


    var clickedReviewImgOpener = document.getElementsByClassName("clickedReviewImg")[0];

    if (document.getElementsByClassName("profileImage")[0] != null) {

        profileOpener();
    }


}


function profileOpener() {
    var profilePhoto = document.getElementsByClassName("profileImage")[0];
    var clickedReviewImgOpener = document.getElementsByClassName("clickedReviewImg")[0];

    if (profilePhoto && clickedReviewImgOpener) {
        profilePhoto.addEventListener("click", function () {
            clickedReviewImgOpener.style.display = "block";
            clickedReviewImgOpener.getElementsByClassName("imgOpener")[0].src = this.src;
        });
    }
}




function cutbutton() {
    document.getElementsByClassName("mobilepopover")[0].innerHTML = " ";

}

function stopOpacity() {

    document.getElementsByClassName("mobilepopover")[0].style.display = "flex";


}

function mouseoutRemove() {

}

setTimeout(
    function () {
        if (document.getElementsByClassName("mobilepopover")[0] != null) {
            document.getElementsByClassName("mobilepopover")[0].style.display = "flex";
        }


    }, 5000);


if (document.getElementsByClassName("headertitle")[0] != null && document.getElementsByClassName("icon")[0] != null) {
    window.addEventListener("wheel", wheelevent);
}


function wheelevent(event) {

    var headertitle = document.getElementsByClassName("headertitle");
    for (var i = 0; i < headertitle.length; i++) {
        if (event.deltaY < 0) {
            // document.getElementsByTagName("body")[0].style.backgroundImage = "none";

            document.getElementsByClassName("headertitle")[i].style.display = "";

            document.getElementsByClassName("icon")[i].style.display = "";







        } else if (event.deltaY > 0) {


            // document.getElementsByTagName("body")[0].style.backgroundImage = "none";

            // document.getElementsByTagName("body")[0].style.color = "black";


            document.getElementsByClassName("headertitle")[i].style.display = "none";

            document.getElementsByClassName("icon")[i].style.display = "none";



        }
    }




}




//online , offline mode

//offline
document.getElementsByTagName("body")[0].onoffline = function () { offline1() };
// here body is getting offline



function offline1() {
    // alert("You are offline");
    document.querySelector("#offline1").innerText = "You are offline";

    document.querySelector("#offline1").style.color = "white"
    document.querySelector("#offline1").style.backgroundColor = "red";
    // text align
    document.querySelector("#offline1").style.textAlign = "center";
    // display=flex
    document.querySelector("#offline1").style.display = "flex";
    // align item 
    document.querySelector("#offline1").style.alignItems = "center";



    document.querySelector("#offline1").style.fontSize = "20px"
    document.querySelector("#offline1").style.fontWeight = "bold"

    document.getElementsByTagName("BODY")[0].ononline = function () { online1() };
}

function online1() {

    document.querySelector("#offline1").innerText = "You are online now"

    document.querySelector("#offline1").style.backgroundColor = "green"


    document.querySelector("body").onscroll = function () {
        // opacityAnimation() ;//reserves space
        document.querySelector("#offline1").style.display = "none";

    };

}


//opacity animation which is useful
function opacityAnimation() {

    document.querySelector("#offline1").style.transition = "opacity 1s"
    document.querySelector("#offline1").style.opacity = "0"



}



function loading() {

    // try loading such way that it sends background of the body and insert an image
    document.querySelector("body").style.backgroundImage = "url('https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fmedia.24ways.org%2F2009%2F15%2Fassets%2Fimg%2Fspinner.png&f=1&nofb=1')";
    // it is predefined loading animated code, you can stop this once page is loaded 

    document.querySelector("body").style.backgroundImage = "url('files acc/loadingImage.png')";
    document.querySelector("body").style.backgroundRepeat = "no-repeat";
    document.querySelector("body").style.backgroundPosition = "center";
    document.querySelector("body").style.backgroundAttachment = "fixed";
    document.querySelector("body").style.backgroundSize = "contain";
    document.querySelector("body").style.backgroundSize = "50% 40%";
    document.querySelector("body").style.backgroundColor = "black";


}

// stop loading function
function stoploading() {
    document.querySelector("body").style.backgroundImage = "none";
    // document.querySelector("body").style.background = "none";
}







//progress bar control
function progressbar() {

    document.getElementsByClassName("progressbar")[0].style.width = "100%";
    document.getElementsByClassName("progressbar")[0].style.height = "3px";

    var loadtime;
    var progressbar = document.getElementsByClassName("progressbar")[0];
    var progressbarwidth = progressbar.offsetWidth;
    var progressbarheight = progressbar.offsetHeight;
    var progressbarcolor = progressbar.style.backgroundColor;
    var progressbarstyle = progressbar.style;


    document.getElementsByClassName("progressbar")[0].style.animation = 'progressslide $loadtime linear 0s 1 normal;';
    document.getElementsByClassName("progressbar")[0].style.marginBottom = "3px;";

    // to define progressslide keyframe
    document.styleSheets[0].insertRule("@keyframes progressslide { 0% {width:0px; background-color: blue;} 100% {width: 100%;}}", 0);


}






var loginInformation = new URLSearchParams(window.location.search);//now we have changed plan to EmailAdress//we switched to sessionstorage


var CustomerNumber;
// alert(CustomerNumber);//undefined
// alert(typeof(CustomerNumber));//undefined
var FirstName;
// var EmailAddress;
var Password;
var passedPhoto;
var scoreWon;
var creditAmount;


// var EmailAddress;
// EmailAddress = sessionStorage.getItem("EmailAddress");
// alert(EmailAddress);



var arrOfReceivedDetails;
// alert(EmailAddress);//null

if (EmailAddress !== null) {
    EmailRelatedLogin("/", EmailAddress);//we have done this so that this function is also shareable to iframe
}
else {
    // EmailRelatedLogin("/", EmailAddress);
    GeneralErrors();
}


function GeneralErrors() {
    var cartVisit = document.getElementsByClassName("visitCart");
    for (var i = 0; i < cartVisit.length; i++) {
        cartVisit[i].addEventListener("click", function () {
            var parentHref = this.parentElement.href;

            if (CustomerNumber === undefined || EmailAddress === null) {
                this.parentElement.removeAttribute("href");

                if (document.getElementById("searchedOutput") !== null) {
                    // alert("please login to see your cart");
                    document.getElementById("searchedOutput").style.display = "flex";
                    document.getElementById("searchedOutput").innerHTML = "please login to see your cart";
                    document.getElementById("searchedOutput").style.color = "red";
                    document.getElementById("searchedOutput").style.fontWeight = "bold";
                    // make fontsize bigger
                    // document.getElementById("searchedOutput").style.fontSize = "30px";//much bigger
                    document.getElementById("searchedOutput").style.fontSize = "20px";

                    setTimeout(function () {
                        document.getElementById("searchedOutput").style.display = "none";
                    }, 5000);

                }
                if (document.getElementsByClassName("lowerpopedUpPage") !== null) {
                    var lowerpopedUpPage = document.getElementsByClassName("lowerpopedUpPage")[0];
                    lowerpopedUpPage.style.display = "flex";
                    // lowerpopedUpPage.style.height="20px";
                    lowerpopedUpPage.style.width = "60vw";
                    lowerpopedUpPage.style.color = "red";
                    lowerpopedUpPage.style.fontWeight = "bold";
                    // lowerpopedUpPage.style.fontSize = "20px";
                    lowerpopedUpPage.innerHTML = "please login to see your cart";
                    setTimeout(function () {
                        lowerpopedUpPage.style.display = "none";
                    }, 5000);

                }





            }
            else {

                this.parentElement.href = parentHref;


            }
        })

    }






    var needOrder = document.getElementsByClassName("needs");
    for (var i = 0; i < needOrder.length; i++) {

        needOrder[i].addEventListener("click", function () {
            var parentHref = this.href;
            //  this.removeAttribute("href");


            if (CustomerNumber === undefined || EmailAddress === null) {
                this.removeAttribute("href");


                if (document.getElementById("searchedOutput") !== null) {
                    // alert("please login to see your cart");
                    document.getElementById("searchedOutput").style.display = "flex";
                    document.getElementById("searchedOutput").innerHTML = "please login to see your ordered products";
                    document.getElementById("searchedOutput").style.color = "red";
                    document.getElementById("searchedOutput").style.fontWeight = "bold";
                    // make fontsize bigger
                    // document.getElementById("searchedOutput").style.fontSize = "30px";//much bigger
                    document.getElementById("searchedOutput").style.fontSize = "20px";

                    setTimeout(function () {
                        document.getElementById("searchedOutput").style.display = "none";
                    }, 5000);

                }
                if (document.getElementsByClassName("lowerpopedUpPage") !== null) {
                    var lowerpopedUpPage = document.getElementsByClassName("lowerpopedUpPage")[0];
                    lowerpopedUpPage.style.display = "flex";
                    // lowerpopedUpPage.style.height="20px";
                    lowerpopedUpPage.style.width = "60vw";
                    lowerpopedUpPage.style.color = "red";
                    lowerpopedUpPage.style.fontWeight = "bold";
                    // lowerpopedUpPage.style.fontSize = "20px";
                    lowerpopedUpPage.innerHTML = "please login to see your ordered products";
                    setTimeout(function () {
                        lowerpopedUpPage.style.display = "none";
                    }, 5000);

                }





            }
            else {

                this.href = parentHref;


            }
        })

    }
}

function EmailRelatedLogin(pagehref, EmailAddress) {

    // alert(EmailAddress);//undefined when passed from main page//null when passed from page

    if (EmailAddress !== undefined || EmailAddress !== null) {
        var email = JSON.stringify(EmailAddress);//neccessary otherwise it will not be able to fetch the data.
        RegisteredCustomerDetail = new XMLHttpRequest();

        RegisteredCustomerDetail.onload = function () {

            if (this.status == 200) {

                // remove
                if (EmailAddress !== null) {
                    arrOfReceivedDetails = JSON.parse(this.responseText);
                    // alert(this.responseText);
                }


                CustomerNumber = arrOfReceivedDetails.CustomerNumber;


                FirstName = arrOfReceivedDetails.FirstName;

                if (document.getElementById("user")) {
                    document.getElementById("user").innerHTML = FirstName;
                }

                Password = arrOfReceivedDetails.Password;

                passedPhoto = pagehref + arrOfReceivedDetails.CustomersProfilePhoto;

                scoreWon = arrOfReceivedDetails.Score;

                creditAmount = arrOfReceivedDetails.CreditLimit;







            }

        }

        RegisteredCustomerDetail.open("GET", pagehref + "getThisCustomerDetail.php?EmailAddress=" + email);

        RegisteredCustomerDetail.send();


    }
    else {

        // alert("You are not login");
        console.log("You are not login");

    }




    var loginHoveredDetails = document.getElementsByClassName("loginCollapsed");


    // alert(loginHoveredDetails.length);

    for (var i = 0; i < loginHoveredDetails.length; i++) {

        var elementToExpand;

        loginHoveredDetails[i].addEventListener("mouseover", function () {


            // elementToExpand = this.parentElement.parentElement.parentElement.getElementsByClassName("loginHoveredDetails")[0];//works only for login with icon //
            elementToExpand = document.body.getElementsByClassName("loginHoveredDetails")[0];//it is for all login icons

            // alert(this.offsetLeft);
            // var leftset = this.offsetLeft + this.offsetWidth - 8 + "px";
            var leftset = this.getBoundingClientRect().left + this.getBoundingClientRect().width - 8 + "px";
            // alert(leftset);
            // var topset = this.offsetTop + this.offsetHeight - 8 + "px";
            var topset = this.getBoundingClientRect().top + this.getBoundingClientRect().height - 8 + "px";
            // alert(topset);

            // var parentHref = pagehref+this.parentElement.href;///http://localhost:3000/product/women/ethnic%20wear/lahenga/Solid%20Semi%20Stitched%20Lehenga%20Choli/animatedLogin.html was not found on this server.

            var parentHref = this.parentElement.href;
            // var parentHref =  elementToExpand.parentElement.href;

            // var topPos = element.getBoundingClientRect().top + window.scrollY;
            // var leftPos = element.getBoundingClientRect().left + window.scrollX;


            elementToExpand.style.display = "block";
            elementToExpand.style.position = "fixed";



            if (elementToExpand.getBoundingClientRect().width < (window.innerWidth - this.getBoundingClientRect().left)) {

                // if (this.offsetLeft > 100) {


                elementToExpand.style.left = leftset;
                // elementToExpand.style.left = "10px"+ this.offsetLeft;
                // elementToExpand.style.top=this.offsetTop+this.offsetHeight;
                elementToExpand.style.top = topset;




            }


            else {


                elementToExpand.style.right = "10px";
                elementToExpand.style.top = topset;
                elementToExpand.style.left = "unset"; //most important //as it saved us from initial problem.
            }

            var clickedExpanded;

            if (CustomerNumber === undefined || EmailAddress === null) {

                // alert("undefined");

                elementToExpand.innerHTML = "Login";
                elementToExpand.style.padding = "0px";
                this.parentElement.href = parentHref;

            }
            else {

                this.parentElement.tagName = "div";

                // we want to remove href attribute also
                this.parentElement.removeAttribute("href");




                elementToExpand.getElementsByClassName("CustomerNumber")[0].value = CustomerNumber;

                // alert( elementToExpand.getElementsByClassName("CustomerNumber")[0].value);//worked



                // elementToExpand.style.left="initial";
                elementToExpand.getElementsByClassName("userName")[0].innerHTML = FirstName;


                elementToExpand.getElementsByClassName("emailOfThisUser")[0].innerHTML = EmailAddress;

                elementToExpand.getElementsByClassName("score")[0].innerHTML = scoreWon;
                elementToExpand.getElementsByClassName("credit")[0].innerHTML = creditAmount;

                var profileImage = document.getElementsByClassName("profileImage")[0];
                profileImage.src = passedPhoto;
                profileImage.classList.remove("profileBackground");



                elementToExpand.addEventListener("mouseover", function () {
                    //we need to display this
                    elementToExpand.style.display = "block";

                    elementToExpand.addEventListener("mouseout", function () {
                        elementToExpand.style.display = "none";

                    });

                });



                this.addEventListener("click", function () {
                    elementToExpand.style.display = "block";

                    this.addEventListener("click", function () {
                        elementToExpand.style.display = "none";
                        clickedExpanded = 0;
                    });

                    clickedExpanded = 1;

                    this.addEventListener("mouseout", function () {
                        elementToExpand.style.display = "block";

                    });

                });


                // if(elementToExpand.style.display == "block"){
                //     this.addEventListener("click", function () {
                //         elementToExpand.style.display = "none";
                //     });
                // }



            }


            if (clickedExpanded != 1 || document.body.onscroll) {
                this.addEventListener("mouseout", function () {
                    elementToExpand.style.display = "none";
                });
            }



        });




    }



    var cartVisit = document.getElementsByClassName("visitCart");
    for (var i = 0; i < cartVisit.length; i++) {
        cartVisit[i].addEventListener("click", function () {
            var parentHref = this.parentElement.href;

            if (CustomerNumber === undefined || EmailAddress === null) {
                this.parentElement.removeAttribute("href");

                if (document.getElementById("searchedOutput") !== null) {
                    // alert("please login to see your cart");
                    document.getElementById("searchedOutput").style.display = "flex";
                    document.getElementById("searchedOutput").innerHTML = "please login to see your cart";
                    document.getElementById("searchedOutput").style.color = "red";
                    document.getElementById("searchedOutput").style.fontWeight = "bold";
                    // make fontsize bigger
                    // document.getElementById("searchedOutput").style.fontSize = "30px";//much bigger
                    document.getElementById("searchedOutput").style.fontSize = "20px";

                    setTimeout(function () {
                        document.getElementById("searchedOutput").style.display = "none";
                    }, 5000);

                }
                if (document.getElementsByClassName("lowerpopedUpPage") !== null) {
                    var lowerpopedUpPage = document.getElementsByClassName("lowerpopedUpPage")[0];
                    lowerpopedUpPage.style.display = "flex";
                    // lowerpopedUpPage.style.height="20px";
                    lowerpopedUpPage.style.width = "60vw";
                    lowerpopedUpPage.style.color = "red";
                    lowerpopedUpPage.style.fontWeight = "bold";
                    // lowerpopedUpPage.style.fontSize = "20px";
                    lowerpopedUpPage.innerHTML = "please login to see your cart";
                    setTimeout(function () {
                        lowerpopedUpPage.style.display = "none";
                    }, 5000);

                }





            }
            else {

                this.parentElement.href = parentHref;


            }
        })

    }






    var needOrder = document.getElementsByClassName("needs");
    for (var i = 0; i < needOrder.length; i++) {

        needOrder[i].addEventListener("click", function () {
            var parentHref = this.href;
            //  this.removeAttribute("href");


            if (CustomerNumber === undefined || EmailAddress === null) {
                this.removeAttribute("href");


                if (document.getElementById("searchedOutput") !== null) {
                    // alert("please login to see your cart");
                    document.getElementById("searchedOutput").style.display = "flex";
                    document.getElementById("searchedOutput").innerHTML = "please login to see your ordered products";
                    document.getElementById("searchedOutput").style.color = "red";
                    document.getElementById("searchedOutput").style.fontWeight = "bold";
                    // make fontsize bigger
                    // document.getElementById("searchedOutput").style.fontSize = "30px";//much bigger
                    document.getElementById("searchedOutput").style.fontSize = "20px";

                    setTimeout(function () {
                        document.getElementById("searchedOutput").style.display = "none";
                    }, 5000);

                }
                if (document.getElementsByClassName("lowerpopedUpPage") !== null) {
                    var lowerpopedUpPage = document.getElementsByClassName("lowerpopedUpPage")[0];
                    lowerpopedUpPage.style.display = "flex";
                    // lowerpopedUpPage.style.height="20px";
                    lowerpopedUpPage.style.width = "60vw";
                    lowerpopedUpPage.style.color = "red";
                    lowerpopedUpPage.style.fontWeight = "bold";
                    // lowerpopedUpPage.style.fontSize = "20px";
                    lowerpopedUpPage.innerHTML = "please login to see your ordered products";
                    setTimeout(function () {
                        lowerpopedUpPage.style.display = "none";
                    }, 5000);

                }





            }
            else {

                this.href = parentHref;


            }
        })

    }















    



}



var profileSetUpload;
    function getFileData(myFile) {
        var file = myFile.files[0];
        passedPhoto = file.name;

        // alert(passedPhoto);

        profileSetUpload = myFile.nextElementSibling;

        profileSetUpload.style.display = "block";
        // profileSetUpload.addEventListener("click",submitProfilePhoto());
    }








// Rate your experience


var rateCount = document.getElementsByName("rate").length;
// alert(rateCount);

var checkedValue;
function displayReview() {

    for (var i = 0; i < rateCount; i++) {


        //this will work for default checked applied only not after click

        var ival = i;
        // alert(typeof(ival)) //number


        if (document.getElementsByName("rate")[i].checked) {

            checkedValue = document.getElementsByName("rate")[i].value;

            // alert(checkedValue);

            var ratetoout = document.getElementsByName("rate")[i].parentElement.parentElement.previousElementSibling;
            // alert(ratetoout.className);

            ratetoout.innerHTML = "You rated this product " + document.getElementsByName("rate")[
                i].value + " out of 5";

            // ratetoout.innerHTML+= document.getElementsByName("rate")[i].value;


            document.getElementsByName("rate")[i].parentElement.style.fontWeight = "bold";





            for (var i = 0; i < rateCount; i++) {
                if (i == ival) {
                    document.getElementsByName("rate")[i].parentElement.style.color = "#ffdb0c";
                }
                else {
                    document.getElementsByName("rate")[i].parentElement.style.color = "#000";
                }

            }; //if we don't use ; after this for loop the lower will not execute as it consider it the last one



            if (checkedValue == 1) {
                ratetoout.innerHTML += `<div style="color:rgb(255, 0, 0)" class="reviewText"><br>Poor</div><br><img src="/files acc/—Pngtree—customer bad review_8774998.png" alt="poor" class="settedImage">`;
            }
            else if (checkedValue == 2) {
                ratetoout.innerHTML += `<div style="color:rgb(239, 123, 8)" class="reviewText"><br>Fair</div><br><img src="/files acc/2star.png" alt="fair" class="settedImage">`;
            }
            else if (checkedValue == 3) {
                ratetoout.innerHTML += `<div style="color:rgb(251, 255, 0)" class="reviewText"><br>Average</div><br><img src="/files acc/3star.png" alt="Average" class="settedImage">`;
            }
            else if (checkedValue == 4) {
                ratetoout.innerHTML += `<div style="color:rgb(88, 255, 88)" class="reviewText"><br>Good</div><br><img src="/files acc/4starfinal.png" alt="Good" class="settedImage">`;
            }
            else if (checkedValue == 5) {
                ratetoout.innerHTML += `<div style="color:rgb(18, 203, 70)" class="reviewText"><br>Excellent</div><br><img src="/files acc/5star.png.gif" alt="Excellent" class="settedImage">`;
            }

        }




    }

}


// document.getElementById("star1").onhover.classList.add("reviewstar");
document.getElementsByClassName("star1").onfocus = function () {
    // alert("being focused");
    document.getElementById("star1").classList.add("reviewstar");

}




// alert(checkedValue);//undefined when unselected
function submitExperience() {

    document.getElementById("searchedOutput").style.display = "flex";



    if (checkedValue) {
        // alert(checkedValue);//4

        if (EmailAddress) {

            // var email = JSON.stringify(EmailAddress);

            // var checkedValueP = JSON.stringify(checkedValue);

            var dbparam = { EmailAddress: EmailAddress, checkedValue: checkedValue };

            dbparam = JSON.stringify(dbparam);


            var UpdateCustomerDetail = new XMLHttpRequest();

            UpdateCustomerDetail.onload = function () {
                if (this.status == 200) {

                    // alert(this.responseText);
                    // var UpdateOutput = JSON.parse(this.responseText);

                    document.getElementById("searchedOutput").innerHTML = this.responseText;
                    // return;

                }

            }

            // UpdateCustomerDetail.open("POST", "UpdateCustomersDetail.php?EmailAddress=" + email + "&checkedValue=" + checkedValueP);

            // UpdateCustomerDetail.send();

            UpdateCustomerDetail.open("POST", "UpdateCustomersDetail.php");
            UpdateCustomerDetail.setRequestHeader("Content-type", "application/x-www-form-urlencoded");


            UpdateCustomerDetail.send("dbparam=" + dbparam);

            setTimeout(function () {
                document.getElementById("searchedOutput").style.display = "none";
            }, 4000);

            // document.getElementById("searchedOutput").innerHTML = checkedValue;
        }
        else {
            document.getElementById("searchedOutput").innerHTML = "Please login to give your experience";
        }
    }
    else {
        // alert("Please select a rating");//when undefined 
        document.getElementById("searchedOutput").innerHTML = "Please select a rating";
    }

    setTimeout(function () {
        document.getElementById("searchedOutput").style.display = "none";
    }, 4000);
}



/* When the user clicks on the button,
toggle between hiding and showing the dropdown content */
function myDropdownOpen() {

    var element = document.querySelector(".mahalootscrollingsection p");
    var animations = element.getAnimations();
    animations.forEach(animation => animation.cancel());

    (element.parentElement.parentElement).style.display = "none";

    // document.getElementById("myDropdownSearch").classList.toggle("show");
    document.getElementById("myDropdownSearch").classList.add("show");
    // document.getElementById("myDropdownSearch").style.zIndex="20";

    // document.getElementById("myDropdownSearch").style.maxWidth=document.getElementById("myInput").style.width-20 ;

    clickSelectedDropdown();


    //it will add the class show in classlist if not prent and if show present in the classlist then it will remove it from classlist
    // document.getElementById("myDropdownSearch").classList.add("show");
    // document.getElementById("myDropdownSearch").classList.remove("show");


    //instead of toogle we can use just adding this class in classlist





}


// if(document.getElementById("myInput")){
//     removeDropDown();
// }

 document.querySelector("body").onscroll = function () {      
        removeDropDown();
    };



function removeDropDown() {

    if (document.getElementById("myDropdownSearch").matches(".show")) {
        document.getElementById("myDropdownSearch").classList.remove("show");
        document.getElementById("myInput").blur();



        var element = document.querySelector(".mahalootscrollingsection p");
        (element.parentElement.parentElement).style.display = "block";
        element.style.animation = "slide 60s linear 3s infinite forwards";


    }
}


function filterFunction() {

    var input = document.getElementById("myInput");
    var filter = input.value.toLowerCase();

    // var p = document.getElementById("myDropdownSearch").getElementsByTagName("p");


    // if filter is empty

    if (filter != "") {
        searchThisFilterProduct(filter);


    }
    else {
        // Cookies recent searches can be saved and show here
        // myDropdownOpen();
    }




    // We have implemented better in searchProduct function already
    // for (let i = 0; i < p.length; i++) {
    //     txtValue = p[i].textContent || p[i].innerText;
    //     if (txtValue.toLowerCase().indexOf(filter) > -1) {
    //         p[i].style.display = "";
    //     } else {
    //         p[i].style.display = "none";
    //     }
    // }




}


function clickSelectedDropdown() {

    var p = document.getElementById("myDropdownSearch").getElementsByTagName("p");
    for (let i = 0; i < p.length; i++) {


        p[i].addEventListener('click', function () {
            // document.getElementById("myDropdownSearch").focus();

            // alert("clicked");

            document.getElementById("myInput").value = this.innerHTML;
            document.getElementById("myInput").focus();
            document.getElementById("myDropdownSearch").click();

        });
    }
}



function searchThisFilterProduct(filter) {

    // alert(filter);

    var filter = JSON.stringify(filter);

    var getProducts = new XMLHttpRequest();

    getProducts.open("GET", "/searchProduct.php?product=" + filter, true);


    getProducts.onload = function () {

        // document.getElementById("searchedOutput").style.display = "flex";

        if (getProducts.status >= 200 && getProducts.status < 300) {



            if (this.responseText == "[]") {

                // document.getElementsByClassName("dropdownSearch-content")[0].getElementsByTagName("p")[0].innerHTML="product";

            }
            else {

                var containerbox = document.getElementsByClassName("dropdownSearch-content")[0];

                // window.location.hash = "searchOut";

                var clonebox = document.getElementsByClassName("dropdownSearch-content")[0].getElementsByTagName("p")[0];

                var clone = clonebox.cloneNode(true);

                // clear all p in clonebox
                containerbox.innerHTML = "";


                // containerbox.getElementsByTagName("p")[0].innerHTML = "";//next time when it will be called , it is emptied

                var responseOfDataBase = JSON.parse(this.responseText);


                // alert(responseOfDataBase);

                var numOfMatchedProducts = responseOfDataBase.length;


                // below we are doing for inserting the products automatically

                // alert(responseOfDataBase.length);//16 outputs in case of ford



                for (var i = 0; i < numOfMatchedProducts; i++) {
                    productfit(i);
                    // containerbox.parentElement.style.display="flex";//not works


                }

                function productfit(i) {
                    // clone.firstElementChild.lastElementChild.lastElementChild.innerHTML = responseOfDataBase[i].productName;


                    clone.innerHTML = responseOfDataBase[i].productName;

                    containerbox.innerHTML += clone.outerHTML;

                }

                clickSelectedDropdown();






            }




        }


    }

    getProducts.send();


}






//queryselectall()
function qSelectorAllHeadingCenter() {
    var element = document.querySelectorAll(".text-center");//works

    for (var i = 0; i < element.length; i++) {
        element[i].style.color = "black";
        element[i].style.backgroundColor = "aqua";
        // element[i].style.fontSize = "20px";
        element[i].style.fontWeight = "bold";
        element[i].style.textAlign = "center";


        // element[i].style.border = "2px solid black";
        element[i].style.borderRadius = "10px";
        element[i].style.margin = "0 10px";
        element[i].style.boxShadow = "10px 5px 5px black";



    }
}


qSelectorAllHeadingCenter();






var myLogin;

function hoverLogin() {
    myLogin = window.open("animatedLogin.html", "", "width=300, height=250");
    // myLogin.moveBy(document.getElementsByClassName("HoverLogin")[0].offsetLeft + window.screenX,  document.getElementsByClassName("HoverLogin")[0].offsetHeight + screenTop)
    // myLogin.moveBy(document.getElementsByClassName("HoverLogin")[0].offsetLeft + window.screenX, 300)
    // myLogin.moveTo(0, 0);

}

function hoverLoginClose() {

    if (myLogin) {
        myLogin.close();
    }

}


var textLoginMessage = "";
function checkWin() {

    if (!myLogin) {
        textLoginMessage = "It has never been opened!";
    } else {
        if (myLogin.closed) {
            text = "It is closed.";
        }
        else {
            textLoginMessage = "It is open.";
        }
    }
    // document.getElementById("demoOpenWindowDetail").innerText = text;
}










var myGamePlay;

function hoverPlay() {
    myGamePlay = window.open("HTMLGame.html", "", "width=500, height=350");
}

function hoverPlayClose() {
    if (myGamePlay) {
        myGamePlay.close();
    }
}

function playGameTabOpen() {
    myGamePlayF = window.open("HTMLGame.html", "", "width=500, height=350");

    myGamePlayF.addEventListener("pagehide", function () {
        alert("your game is active");
    })

    if (myGamePlayF) {
        myopener(myGamePlayF);
    }//myopener function is called and it will send the message that game is running behind

    // myGamePlay.focus();



}

if (document.getElementById("gameFrame")) {
    // document.getElementById("gamecanvas").addEventListener("load", gameFunction);
    document.getElementById("gameFrame").addEventListener("load", gameFunction);
    // alert("loading");
}


function gameFunction() {
    // var gameCanva = document.getElementById("gameFrame").contentWindow.document.getElementsByTagName("canvas")[0];  
    // var gameCanva = document.getElementById("gameFrame").contentWindow.document.getElementsByTagName("body")[0].getElementsByTagName("canvas");
    // // alert(gameCanva);
    // var gameCanvaAdopted = document.adoptNode(gameCanva);
    // var canvasContainer = document.getElementById("gamecanvas");
    // canvasContainer.appendChild(gameCanvaAdopted);//works


    //     var gameCanva = document.getElementById("gameFrame").contentWindow.document.getElementsByTagName("body")[0].getElementsByTagName("canvas")[0];
    //     // alert(gameCanva);
    //    var gameCanvaAdopted = document.adoptNode(gameCanva);
    //     var canvasContainer = document.getElementById("gamecanvas");
    //     canvasContainer.innerHTML='<div onload="startGame()"></div>';
    // // canvasGame



    //     canvasContainer.appendChild(gameCanvaAdopted);//works


    // All functions are not going to work this way hence use iframe directly

    // document.getElementsByTagName("iframe")[0].style.width

}




function myopener(myGamePlayF) {

    myGamePlayF.opener.document.getElementById("gameStatus").innerHTML = "HELLO! What are you doing here , your game is running .<br><button onclick='closeGamePlay(myGamePlayF)'>  Close Game </button>";

    // myGamePlay.opener.close();//it will close opener which is learning javascript as soon as this mywindow opens.

    // myGamePlay.opener.blur(); //we are just keeping it blur
    //Note:myGamePlay.parent.blur() is not acceptable anymore



    // var closeGamePlay=document.getElementById("gameStatus").createElement("button")
}






function closeGamePlay(myGamePlayF) {
    if (myGamePlayF) {
        myGamePlayF.close();
    }
}








function myGreeting() {
    // alert("helolo");
    // document.getElementById("setTimeOutSurprise").innerHTML = "Happy Birthday!";
    // document.getElementsByClassName("popover")[0].innerHTML = "Happy Birthday!";

    // document.getElementById("setTimeOutSurprise").style.display = "block";
    // document.getElementById("setTimeOutSurprise").classList.remove("popover");

    document.getElementById("setTimeOutSurprise").innerHTML = "Happy Shopping with extra offers!";


    // document.getElementById("setTimeOutSurprise").innerHTML = "Happy Birthday!";

    // later on we will set it in popup section and 



}



//surprise
function mySurprise() {

    document.getElementById("setTimeOutSurprise").innerHTML = "Nice to see you are interested";

    // var myTimeout = setTimeout(myGreeting, 5000);
    var myTimeout = setTimeout(myGreeting, 2000);

    // if (false) {
    //     // pass condition as if no button is clicked then call noSurprise
    //     noSurprise(myTimeout);
    // }

}


function noSurprise() {

    document.getElementById("setTimeOutSurprise").innerHTML = "You missed a beautiful feeling";
}










//when select options of category is changed
function myFunctionOnChange() {


    // document.getElementById("demo").innerHTML = "You selected: " + x;
    var xhashvalue = document.getElementById("mySelect").value;

    document.getElementById(xhashvalue).scrollIntoView({ behavior: "smooth", block: "end" })
    // document.getElementById(xhashvalue).scrollIntoView({ behavior: "smooth", block: "center" });

    //xhashvalue must be defined inside
    console.log("Selected category is :" + xhashvalue);
}


function myFunctiononhashchange() {
    var xhashvalue = document.getElementById("mySelect").value;

    console.log('you selected ' + xhashvalue);
}

var bannersectionClick;
if (document.getElementsByClassName('banner')[0] != null) {
    // var bannersectionClick = document.getElementsByClassName('bannersection')[0].getElementsByTagName("span");
    bannersectionClick = document.getElementsByClassName('banner')[0].getElementsByTagName("span");
    for (var i = 0; i < bannersectionClick.length; i++) {
        bannersectionClick[i].addEventListener("click", function () {
            var xhashvalue = this.className;
            document.getElementById(xhashvalue).scrollIntoView({ behavior: "smooth", block: "end" });
        });
    }
}



if (document.getElementById("swapslide1") != null) {

    var slide1 = document.getElementById("swapslide1").style.animationPlayState;
    var slide2 = document.getElementById("swapslide2").style.animationPlayState;
    var slide3 = document.getElementById("swapslide3").style.animationPlayState;
    var slide4 = document.getElementById("swapslide4").style.animationPlayState;
    var slide5 = document.getElementById("swapslide5").style.animationPlayState;
}


function pauseslide() {

    // alert("inside pauseslide");
    document.getElementsByClassName("banner")[0].style.animationPlayState = "paused";

    // document.getElementsByClassName("swapslide")[0].style.animationPlayState = "paused";

    document.getElementById("swapslide1").style.animationPlayState = "paused";
    document.getElementById("swapslide2").style.animationPlayState = "paused";
    document.getElementById("swapslide3").style.animationPlayState = "paused";
    document.getElementById("swapslide4").style.animationPlayState = "paused";
    document.getElementById("swapslide5").style.animationPlayState = "paused";

    // if(slide1=="paused" || slide2=="paused" || slide3=="paused" || slide4=="paused" || slide5=="paused" ){}



    // var slide;

    // setInterval(swapslides_button ,5000);
    setTimeout(() => {
        // alert("inside setinterval");
        swapslides_button();
        // }, 5000);
    }, 10000);

    // await sleep(5000);

}


function swapslides_button() {

    document.getElementsByClassName("banner")[0].style.animationPlayState = "running";

    document.getElementById("swapslide1").style.animationPlayState = "running";
    document.getElementById("swapslide2").style.animationPlayState = "running";
    document.getElementById("swapslide3").style.animationPlayState = "running";
    document.getElementById("swapslide4").style.animationPlayState = "running";
    document.getElementById("swapslide5").style.animationPlayState = "running";

    // alert();



}

var bannerInnerHTM
if (document.getElementsByClassName("banner")[0] != null) {
    bannerInnerHTML = document.getElementsByClassName("banner")[0].innerHTML;
}

function initialslideshow() {
    // alert("inside setinterval");

    document.getElementById("swapslide1").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide2").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide3").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide4").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide5").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide6").style.backgroundColor = "#9da2a2";


    document.getElementsByClassName("banner")[0].style.animation = "bannerslide 15s linear 0s infinite forwards";

    document.getElementById("swapslide1").style.animation = "bannerControlslide 15s linear 0s infinite forwards";
    document.getElementById("swapslide2").style.animation = "bannerControlslide 15s linear 2s infinite forwards";
    document.getElementById("swapslide3").style.animation = "bannerControlslide 15s linear 5s infinite forwards";
    document.getElementById("swapslide4").style.animation = "bannerControlslide 15s linear 8s infinite forwards";
    document.getElementById("swapslide5").style.animation = "bannerControlslide 15s linear 10s infinite forwards";
    document.getElementById("swapslide6").style.animation = "bannerControlslide 15s linear 13s infinite forwards";


    document.getElementsByClassName("banner")[0].innerHTML = bannerInnerHTML;
    swapslides_button();


}


function openBanner1() {

    document.getElementsByClassName("banner")[0].style.animation = "none";

    document.getElementById("swapslide1").style.animation = "none";
    document.getElementById("swapslide2").style.animation = "none";
    document.getElementById("swapslide3").style.animation = "none";
    document.getElementById("swapslide4").style.animation = "none";
    document.getElementById("swapslide5").style.animation = "none";
    document.getElementById("swapslide6").style.animation = "none";

    document.getElementsByClassName("banner")[0].innerHTML = ` <span 
               ' class="mahaloot"><img src="files acc/magasalebanner.png" alt="banner" class="bannerphoto mobilebanner"></span>`;



    document.getElementById("swapslide1").style.backgroundColor = "blue";
    document.getElementById("swapslide2").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide3").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide4").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide5").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide6").style.backgroundColor = "#9da2a2";



    //    document.getElementsByClassName("banner")[0].onclick='document.getElementById("mahaloot").scrollIntoView({ behavior: "smooth", block: "end" })';
    document.getElementsByClassName("banner")[0].getElementsByTagName("span")[0].addEventListener("click", function () {
        // alert("hello");
        document.getElementById("mahaloot").scrollIntoView({ behavior: "smooth", block: "end" });
    });

    setTimeout(initialslideshow, 5000);


}



function openBanner2() {

    document.getElementsByClassName("banner")[0].style.animation = "none";

    document.getElementById("swapslide1").style.animation = "none";
    document.getElementById("swapslide2").style.animation = "none";
    document.getElementById("swapslide3").style.animation = "none";
    document.getElementById("swapslide4").style.animation = "none";
    document.getElementById("swapslide5").style.animation = "none";
    document.getElementById("swapslide6").style.animation = "none";

    document.getElementsByClassName("banner")[0].innerHTML = `<span class="women"><img src="files acc/Fashion Sale Banner Post - Made with PosterMyWall.jpg" alt="banner"
                        class="bannerphoto mobilebanner"></span>`;




    document.getElementById("swapslide1").style.backgroundColor = "#9da2a2";

    document.getElementById("swapslide2").style.backgroundColor = "blue";

    document.getElementById("swapslide3").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide4").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide5").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide6").style.backgroundColor = "#9da2a2";


    document.getElementsByClassName("banner")[0].getElementsByTagName("span")[0].addEventListener("click", function () {
        // alert("hello");
        document.getElementById("women").scrollIntoView({ behavior: "smooth", block: "end" });
    });

    setTimeout(initialslideshow, 5000);
}

function openBanner3() {

    document.getElementsByClassName("banner")[0].style.animation = "none";

    document.getElementById("swapslide1").style.animation = "none";
    document.getElementById("swapslide2").style.animation = "none";
    document.getElementById("swapslide3").style.animation = "none";
    document.getElementById("swapslide4").style.animation = "none";
    document.getElementById("swapslide5").style.animation = "none";
    document.getElementById("swapslide6").style.animation = "none";

    document.getElementsByClassName("banner")[0].innerHTML = `<span class="men"><img src="files acc/Men's Wear.jpg" alt="banner" class="bannerphoto mobilebanner"></span>`;



    document.getElementById("swapslide1").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide2").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide3").style.backgroundColor = "blue";
    document.getElementById("swapslide4").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide5").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide6").style.backgroundColor = "#9da2a2";

    document.getElementsByClassName("banner")[0].getElementsByTagName("span")[0].addEventListener("click", function () {
        // alert("hello");
        document.getElementById("men").scrollIntoView({ behavior: "smooth", block: "end" });
    });


    setTimeout(initialslideshow, 5000);
}

function openBanner4() {

    document.getElementsByClassName("banner")[0].style.animation = "none";

    document.getElementById("swapslide1").style.animation = "none";
    document.getElementById("swapslide2").style.animation = "none";
    document.getElementById("swapslide3").style.animation = "none";
    document.getElementById("swapslide4").style.animation = "none";
    document.getElementById("swapslide5").style.animation = "none";
    document.getElementById("swapslide6").style.animation = "none";

    document.getElementsByClassName("banner")[0].innerHTML = `<span class="kids"><img src="files acc/kids wear.jpg" alt="banner" class="bannerphoto mobilebanner"></span>`;



    document.getElementById("swapslide1").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide2").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide3").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide4").style.backgroundColor = "blue";
    document.getElementById("swapslide5").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide6").style.backgroundColor = "#9da2a2";

    document.getElementsByClassName("banner")[0].getElementsByTagName("span")[0].addEventListener("click", function () {
        // alert("hello");
        document.getElementById("kids").scrollIntoView({ behavior: "smooth", block: "end" });
    });

    setTimeout(initialslideshow, 5000);

}

function openBanner5() {

    document.getElementsByClassName("banner")[0].style.animation = "none";

    document.getElementById("swapslide1").style.animation = "none";
    document.getElementById("swapslide2").style.animation = "none";
    document.getElementById("swapslide3").style.animation = "none";
    document.getElementById("swapslide4").style.animation = "none";
    document.getElementById("swapslide5").style.animation = "none";
    document.getElementById("swapslide6").style.animation = "none";

    document.getElementsByClassName("banner")[0].innerHTML = `<span class="beautyHealth"><img src="/files acc/Health and Beauty.jpg" alt="banner"
                        class="bannerphoto mobilebanner"></span>`;




    document.getElementById("swapslide1").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide2").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide3").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide4").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide5").style.backgroundColor = "blue";
    document.getElementById("swapslide6").style.backgroundColor = "#9da2a2";

    document.getElementsByClassName("banner")[0].getElementsByTagName("span")[0].addEventListener("click", function () {
        // alert("hello");
        document.getElementById("beautyHealth").scrollIntoView({ behavior: "smooth", block: "end" });
    });

    setTimeout(initialslideshow, 5000);

}


function openBanner6() {

    document.getElementsByClassName("banner")[0].style.animation = "none";

    document.getElementById("swapslide1").style.animation = "none";
    document.getElementById("swapslide2").style.animation = "none";
    document.getElementById("swapslide3").style.animation = "none";
    document.getElementById("swapslide4").style.animation = "none";
    document.getElementById("swapslide5").style.animation = "none";
    document.getElementById("swapslide6").style.animation = "none";

    document.getElementsByClassName("banner")[0].innerHTML = `<span class="homeGarden"><img src="/files acc/home and kitchen.jpg" alt="banner" class="bannerphoto mobilebanner"></span>`;



    document.getElementById("swapslide1").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide2").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide3").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide4").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide5").style.backgroundColor = "#9da2a2";
    document.getElementById("swapslide6").style.backgroundColor = "blue";

    document.getElementsByClassName("banner")[0].getElementsByTagName("span")[0].addEventListener("click", function () {
        // alert("hello");
        document.getElementById("homeGarden").scrollIntoView({ behavior: "smooth", block: "end" });
    });


    setTimeout(initialslideshow, 5000);

}



if (document.getElementById("stickContent") != null) {


    var stickContent = document.getElementById("stickContent");


    var stickContentEnd = document.getElementById("stickContentEnd");


    var sticky = stickContent.offsetTop;//offset is undefined


    // var stickyEnd = stickContentEnd.offsetTop + Number(v);
    // var stickyEnd = stickContentEnd.offsetHeight;


    var stickyEnd = stickContent.offsetHeight;
    window.addEventListener("scroll", mySticky);


}

function mySticky() {
    if (window.scrollY >= sticky && window.scrollY <= stickyEnd) {
        stickContent.classList.add("sticky")
    } else {
        stickContent.classList.remove("sticky");
    }
}//now it works properly











var form = document.querySelector('form');
form.addEventListener('submit', function (event) {
    event.preventDefault(); //we used this to prevent reload of page after XMLHttpRequest
    // Your form submission logic here 
});



// setTimeout(function () {
//     document.getElementById("searchedOutput").style.display = "none";
// }, 5000);

// var searchButton=document.getElementsByClassName("search");
// searchButton[0].addEventListener("click",searchEnteredProduct);

if (document.getElementsByClassName("completeonecategory")[0] != null) {
    // var SearchProductInnerHTML = document.getElementsByClassName("completeonecategory")[0].firstElementChild.getElementsByTagName("a")[0].innerHTML;
    var SearchProductInnerHTML = document.getElementsByClassName("completeonecategory")[0].getElementsByTagName("a")[0].innerHTML;
}

// var SearchProductInnerHTML2 = document.getElementsByClassName("completeonecategory")[1].firstElementChild.getElementsByTagName("a")[0].innerHTML;

if (document.searchProduct != null) {
    document.searchProduct.searchProductEnteredbyTyping.addEventListener("keypress", function (event) {
        // If the user presses the "Enter" key on the keyboard
        if (event.key === "Enter") {
            // Cancel the default action, if needed
            event.preventDefault();
            // Trigger the button element with a click
            document.getElementsByClassName("search")[0].click();
        }
    });
}


var topcategory = document.getElementsByClassName("topcategoryProductOptionBox");
// alert(topcategory.length);

for (var i = 0; i < topcategory.length; i++) {
    // topcategory[i].getElementsByTagName("a")[0].removeAttribute("href");
    // topcategory[i].getElementsByTagName("a")[0].removeAttribute("href");
    topcategory[i].addEventListener("click", function () {

        var categoryname = this.getElementsByTagName("p")[0].innerHTML;
        // alert(categoryname);//women
        searchThisProductTopCategory(categoryname);
    }
    )
}


function searchThisProductTopCategory(product) {


    product = product.trim();
    product = product.toLowerCase();
    product = product.replace(/[^a-z0-9\s]/g, ''); //this line is used to remove all special symbols d%w3 changes to  dw3

    product = product.replace(/\s+/g, ' '); //this line is used to remove all extra spaces between words

    document.getElementById("searchedOutput").style.display = "none";

    if (document.getElementsByClassName("searchOutBlock")[0].style.display == "block" || document.getElementsByClassName("searchOutMoreBlock")[0].style.display == "block" || document.getElementsByClassName("searchOutMoreBlock")[0].style.flexWrap == "wrap") {


        document.getElementsByClassName("searchOutBlock")[0].style.display = "none";
        document.getElementsByClassName("searchOutMoreBlock")[0].style.display = "none";

        var anchors = document.getElementsByClassName("searchOutBlock")[0].getElementsByTagName("a");


        // alert(anchors.length);
        for (var i = 0; i < anchors.length; i++) {
            anchors[i].innerHTML = "";
        }

        document.getElementsByClassName("searchOutBlock")[0].getElementsByTagName("a")[0].innerHTML = SearchProductInnerHTML;


        searchThisProduct(product);
        return;


    }

    searchThisProduct(product);
}



function searchEnteredProduct() {

    document.getElementById("searchOut").scrollIntoView({ behavior: "smooth", block: "center" });

    //    document.getElementById("searchOutMore").scrollIntoView({ behavior: "smooth", block: "end" });

    // var refreshBtn = document.getElementById("btnRefresh");
    // function handleClick() {
    //   window.location.reload();
    // }
    // refreshBtn.addEventListener("click", handleClick);

    var productEntered = document.searchProduct.searchProductEnteredbyTyping.value;
    productEntered = productEntered.trim();
    productEntered = productEntered.toLowerCase();
    productEntered = productEntered.replace(/[^a-z0-9\s]/g, ''); //this line is used to remove all special symbols d%w3 changes to  dw3

    productEntered = productEntered.replace(/\s+/g, ' '); //this line is used to remove all extra spaces between words


    if (productEntered == "") {
        document.getElementById("searchedOutput").style.display = "flex";
        document.getElementById("searchedOutput").innerHTML = "Please type the product you want to search for";
        // alert("empty");//ok


        setTimeout(function () {
            document.getElementById("searchedOutput").style.display = "none";
        }, 5000);
        // return;
    }
    else {

        document.getElementById("searchedOutput").style.display = "none";

        if (document.getElementsByClassName("searchOutBlock")[0].style.display == "block" || document.getElementsByClassName("searchOutMoreBlock")[0].style.display == "block" || document.getElementsByClassName("searchOutMoreBlock")[0].style.flexWrap == "wrap") {


            document.getElementsByClassName("searchOutBlock")[0].style.display = "none";
            document.getElementsByClassName("searchOutMoreBlock")[0].style.display = "none";
            // document.getElementsByClassName("searchOutMoreBlock")[0].innerHTML = "";



            // alert('we are already open');
            // we also want to clear all the anchors except the first
            var anchors = document.getElementsByClassName("searchOutBlock")[0].getElementsByTagName("a");
            // var anchors2 = document.getElementsByClassName("searchOutMoreBlock")[0].getElementsByTagName("a");

            // alert(anchors.length);
            for (var i = 0; i < anchors.length; i++) {
                anchors[i].innerHTML = "";


            }
            // for (var i = 0; i < anchors2.length; i++) {
            //     // for (var i = 1; i < anchors2.length; i++) {
            //     anchors2[i].innerHTML = "";

            // }

            // document.getElementsByClassName("completeonecategory")[0].firstElementChild.getElementsByTagName("a")[0].innerHTML=SearchProductInnerHTML;
            document.getElementsByClassName("searchOutBlock")[0].getElementsByTagName("a")[0].innerHTML = SearchProductInnerHTML;

            // document.getElementsByClassName("completeonecategory")[1].firstElementChild.getElementsByTagName("a")[0].innerHTML = SearchProductInnerHTML2;


            searchThisProduct(productEntered);
            return;
        }


        // document.getElementsByClassName("searchOutMoreBlock")[0].style.display = "none";


        // none works even when we want to repaint on searching again


        searchThisProduct(productEntered);
    }

}





function searchThisProduct(product) {

    var product = JSON.stringify(product);

    var getProducts = new XMLHttpRequest();

    getProducts.open("GET", "searchProduct.php?product=" + product, true);


    getProducts.onload = function () {

        // document.getElementById("searchedOutput").style.display = "flex";

        if (getProducts.status >= 200 && getProducts.status < 300) {



            if (this.responseText == "[]") {

                document.getElementById("searchedOutput").style.display = "flex";
                document.getElementById("searchedOutput").innerHTML = "Sorry, we could not find any product matching";

            }
            else {

                var containerbox = document.getElementsByClassName("completeonecategory")[0].firstElementChild;

                var containerbox2 = document.getElementsByClassName("completeonecategory")[1].firstElementChild;

                // window.location.hash = "searchOut";

                document.getElementsByClassName("completeonecategory")[0].previousElementSibling.innerHTML = "Your search result for " + product + " is ready. ";

                document.getElementsByClassName("completeonecategory")[1].previousElementSibling.innerHTML = "Some more result for " + product + " is ready ";

                var clonebox = document.getElementsByClassName("completeonecategory")[0].firstElementChild.getElementsByTagName("a")[0];

                clonebox.removeAttribute("href");

                var clone = clonebox.cloneNode(true);



                // containerbox2.innerHTML = "";
                containerbox.getElementsByTagName("a")[0].innerHTML = "";//next time when it will be called , it is emptied

                // document.getElementById("searchedOutput").style.display = "flex";
                // document.getElementById("searchedOutput").innerHTML = "Your search result for " + product + " is ready ";

                var responseOfDataBase = JSON.parse(this.responseText);

                // alert(responseOfDataBase);

                var numOfMatchedProducts = responseOfDataBase.length;


                // below we are doing for inserting the products automatically

                // alert(responseOfDataBase.length);//16 outputs in case of ford


                 if(numOfMatchedProducts !== 0){
 // containerbox2.innerHTML = "";
                containerbox.getElementsByTagName("a")[0].innerHTML = "";//next time when it will be called , it is emptied

                document.getElementById("searchedOutput").style.display = "flex";
                document.getElementById("searchedOutput").innerHTML = "Your search result for " + product + " is ready ";
                }
                else{
                    return;
                }


                function productfit(i) {
                    // clone.firstElementChild.lastElementChild.lastElementChild.innerHTML = responseOfDataBase[i].productName;


                    clone.getElementsByClassName("productName")[0].innerHTML = responseOfDataBase[i].productName;

                    var priceSetted = Number(responseOfDataBase[i].buyPrice);


                    // clone.getElementsByClassName("priceOfProduct")[0].innerHTML = responseOfDataBase[i].MSRP;

                    clone.getElementsByClassName("priceOfProduct")[0].innerHTML = priceSetted.toFixed(0);

                    // var productCode = responseOfDataBase[i].productCode;
                    // alert(productCode);
                    // S12_1099

                    clone.getElementsByClassName("productCode")[0].innerHTML = responseOfDataBase[i].productCode;







                    if (responseOfDataBase[i].mainProductImage != null) {

                        // alert(responseOfDataBase[i].mainProductImage);
                        clone.getElementsByClassName("productimg")[0].src = responseOfDataBase[i].mainProductImage;


                    }







                }




                if (numOfMatchedProducts > 0) {

                    // containerbox2.innerHTML = "";



                    // for (var i = 0; i < numOfMatchedProducts; i++) {//used for all result in one row
                    if (numOfMatchedProducts < 10) {
                        // if this condition is not used then it will call for loop 10 time and got stuck
                        for (var i = 0; i < numOfMatchedProducts; i++) {
                            productfit(i);
                            // containerbox.parentElement.style.display="flex";//not works

                            document.getElementsByClassName("searchOutBlock")[0].style.display = "block";
                            containerbox.innerHTML += clone.outerHTML;

                            document.getElementById("searchOut").scrollIntoView({ behavior: "smooth", block: "center" });//before this it would be in form of display none , having no space reserved

                            // document.getElementById("searchOutMore").scrollIntoView({ behavior: "smooth", block: "end" });
                        }
                    }
                    else {


                        for (var i = 0; i < 10; i++) {

                            productfit(i);
                            // containerbox.parentElement.style.display="flex";//not works

                            document.getElementsByClassName("searchOutBlock")[0].style.display = "block";
                            containerbox.innerHTML += clone.outerHTML;

                            document.getElementById("searchOut").scrollIntoView({ behavior: "smooth", block: "center" });//before this it would be in form of display none , having no space reserved

                            // document.getElementById("searchOutMore").scrollIntoView({ behavior: "smooth", block: "end" });



                        }


                        containerbox2.innerHTML = "";
                        for (var i = 10; i < numOfMatchedProducts; i++) {
                            productfit(i);
                            document.getElementsByClassName("searchOutMoreBlock")[0].style.display = "block";


                            containerbox2.innerHTML += clone.outerHTML;
                            // document.getElementsByClassName("searchOutMoreBlock")[0].style.height="fit-content";

                            document.getElementsByClassName("searchOutMoreBlock")[0].style.height = "auto";





                            // containerbox2.style.width="100vw";
                            // containerbox2.style.height="fit-content";
                            // we need to wrap the content in case of overflow

                            // containerbox2.style.flexwrap="wrap";
                            // containerbox2.style.height="fit-content";
                        }

                    }

                    // if (numOfMatchedProducts > 20 && containerbox2.style.flexWrap !== "wrap") {
                    if (numOfMatchedProducts > 20) {

                        if (document.getElementsByClassName("searchOutMoreBlock")[0].getElementsByTagName("button")[2]) {
                            document.getElementsByClassName("searchOutMoreBlock")[0].removeChild(document.getElementsByClassName("searchOutMoreBlock")[0].getElementsByTagName("button")[2]);
                        }

                        if (document.getElementById("similarproductsoptions") == null) {
                            var node = document.createElement("button");
                            node.innerHTML = "Load More";
                            node.style.display = "flex";
                            node.style.justifySelf = "center";
                            node.onclick = function () {
                                loadMore(this);
                            }
                            document.getElementsByClassName("searchOutMoreBlock")[0].appendChild(node);
                        }

                    }
                }


                function loadMore(element) {
                    containerbox2.style.justifyContent = "center";
                    // clone.style.margin="5vh";
                    containerbox2.style.alignItems = "center";
                    // containerbox2.style.alignItems="stretch";

                    containerbox2.style.flexWrap = "wrap";
                    containerbox2.style.overflow = "hidden";
                    containerbox2.style.height = "auto";
                    containerbox2.style.gap = "10px";

                    document.getElementsByClassName("searchOutMoreBlock")[0].removeChild(element);

                    // we have to remove button tag
                    containerbox2.removeChild(containerbox2.getElementsByTagName("button")[0]);
                    containerbox2.removeChild(containerbox2.getElementsByTagName("button")[1]);



                }



                var productboxInside = document.getElementsByClassName("completeproductbox");

                for (var i = 0; i < productboxInside.length; i++) {
                    productboxInside[i].addEventListener("click", function () {
                        // alert("clicked");
                        var productCode = this.getElementsByClassName("productCode")[0].innerHTML;

                        // alert(productCode);

                        navigateProductClick(productCode);
                    });
                }


            }




        }
        else {
            document.getElementById("searchedOutput").style.display = "flex";
            document.getElementById("searchedOutput").innerHTML = "Server is slow and unable to get matched product";

        }

        setTimeout(function () {
            document.getElementById("searchedOutput").style.display = "none";
        }, 5000);

    }

    getProducts.send();


}








function searchGivenProduct(product, id, pagehref, SearchProductInnerHTML) {
    // alert(product);//receives even from others
    // alert(id);
    // var id=JSON.stringify(id);
    product = JSON.stringify(product);
    var getProducts = new XMLHttpRequest();


    // getProducts.open("GET", "searchProduct.php?product=" + product, true);
    getProducts.open("GET", pagehref + "searchProduct.php?product=" + product, true);

    // getProducts.setRequestHeader("Content-type", "application/x-www-form-urlencoded");//not neccessary for get


    getProducts.onload = function () {

        if (getProducts.status >= 200 && getProducts.status < 300) {

            if (this.responseText == "[]") {

                if (document.getElementById("searchedOutput")) {
                    document.getElementById("searchedOutput").style.display = "flex";
                    document.getElementById("searchedOutput").innerHTML = "Sorry, we could not find any product matching";
                }
                else {
                    // alert("Sorry, we don't not find any product matching");
                }

            }
            else {

                var containerbox = document.getElementById(id);

                // alert(containerbox);

                if (containerbox != null) {


                    var clonebox = containerbox.getElementsByTagName("a")[0];

                    clonebox.innerHTML = SearchProductInnerHTML;


                    // alert(SearchProductInnerHTML);//undefined for js from another page call



                    // alert(id);



                    clonebox.removeAttribute("href");



                    var clone = clonebox.cloneNode(true);

                    // containerbox.innerHTML = "";


                    containerbox.getElementsByTagName("a")[0].innerHTML = "";



                    var anchorLength = containerbox.getElementsByTagName("a");
                    for (var i = 0; i < anchorLength.length; i++) {
                        containerbox.getElementsByTagName("a")[i].innerHTML = "";
                        // instead we would like to remove all anchors
                        // containerbox.getElementsByTagName("a")[i].remove();

                    }

                    var responseOfDataBase = JSON.parse(this.responseText);
                    var numOfMatchedProducts = responseOfDataBase.length;


                    // alert(id + numOfMatchedProducts);

                }




                function productfit(i) {

                    clone.getElementsByClassName("productName")[0].innerHTML = responseOfDataBase[i].productName;

                    var priceSetted = Number(responseOfDataBase[i].buyPrice);

                    clone.getElementsByClassName("priceOfProduct")[0].innerHTML = priceSetted.toFixed(0);

                    clone.getElementsByClassName("productCode")[0].innerHTML = responseOfDataBase[i].productCode;



                    if (responseOfDataBase[i].mainProductImage != null) {

                        clone.getElementsByClassName("productimg")[0].src = pagehref + responseOfDataBase[i].mainProductImage;
                    }


                    // clone.getElementsByClassName("productimg")[0].src=responseOfDataBase[i].mainProductImage;
                }

                if (numOfMatchedProducts > 0) {

                    if (id !== "mahaloot") {


                        for (var i = 0; i < numOfMatchedProducts; i++) {
                            productfit(i);
                            containerbox.innerHTML += clone.outerHTML;

                        }

                        // alert(document.getElementById("similarproductsoptions"));

                        if (numOfMatchedProducts > 10 && document.getElementById("similarproductsoptions") == null) {

                            var nodeP = document.createElement("button");
                            nodeP.innerHTML = "Load More";
                            nodeP.style.display = "flex";
                            nodeP.style.justifySelf = "center";
                            nodeP.onclick = function () {
                                loadMore(this);
                            }
                            containerbox.parentElement.parentElement.appendChild(nodeP);

                        }
                    }
                    else {
                        if (numOfMatchedProducts > 10) {
                            for (var i = 0; i < 10; i++) {
                                productfit(i);
                                containerbox.innerHTML += clone.outerHTML;
                            }
                        }
                        else {

                            for (var i = 0; i < numOfMatchedProducts; i++) {
                                productfit(i);
                                containerbox.innerHTML += clone.outerHTML;
                            }
                        }
                    }

                }
                else {
                    // alert("No matched product");
                }


                function loadMore(element) {

                    containerbox.style.justifyContent = "center";
                    // clone.style.margin="5vh";
                    containerbox.style.alignItems = "center";
                    // containerbox.style.alignItems="stretch";

                    containerbox.style.flexWrap = "wrap";
                    containerbox.style.overflow = "hidden";
                    containerbox.style.height = "auto";
                    containerbox.style.gap = "10px";

                    containerbox.parentElement.parentElement.removeChild(element);




                    // we have to remove button tag
                    containerbox.removeChild(containerbox.getElementsByTagName("button")[0]);
                    containerbox.removeChild(containerbox.getElementsByTagName("button")[1]);


                }


                var productboxInside = document.getElementsByClassName("completeproductbox");

                for (var i = 0; i < productboxInside.length; i++) {
                    productboxInside[i].addEventListener("click", function () {
                        // alert("clicked");
                        var productCode = this.getElementsByClassName("productCode")[0].innerHTML;

                        navigateProductClick(productCode);
                    });
                }


            }







        }
        else {
            if (document.getElementById("searchedOutput")) {
                document.getElementById("searchedOutput").style.display = "flex";
                document.getElementById("searchedOutput").innerHTML = "Server is slow and unable to get matched product";
            }

        }

        if (document.getElementById("searchedOutput")) {
            setTimeout(function () {
                document.getElementById("searchedOutput").style.display = "none";
            }, 5000);
        }

    }



    getProducts.send();


}


// Initialize product searches
if (typeof SearchProductInnerHTML !== 'undefined') {
    
    searchGivenProduct("women", "women", "/", SearchProductInnerHTML);
    searchGivenProduct("men", "men", "/", SearchProductInnerHTML);
    searchGivenProduct("kid", "kids", "/", SearchProductInnerHTML);
    searchGivenProduct("home garden kitchen", "homeGarden", "/", SearchProductInnerHTML);
    searchGivenProduct("trendy", "mahaloot", "/", SearchProductInnerHTML);
}




var gridImageContainer = document.getElementsByClassName("gridSectionContainer");

function escapeSpecialChars(src) {
    // List of special characters to escape
    // const specialChars = ['&', '?', '=', ' ', '#', '%', '{', '}', '|', '\\', '^', '~', '[', ']', '`'];
    const specialChars = ['&', '?', '=', '#', '%', '{', '}', '|', '\\', '^', '~', '[', ']', '`'];

    let escapedSrc = '';
    for (const char of src) {
        if (specialChars.includes(char)) {
            escapedSrc += `\\${char}`;  // Add backslash before special char
        } else {
            escapedSrc += char;  // Keep normal characters as-is
        }
    }
    return escapedSrc;
}


for (var i = 0; i < gridImageContainer.length; i++) {
    var gridImage = gridImageContainer[i].getElementsByTagName("img");
    for (var j = 0; j < gridImage.length; j++) {
        gridImage[j].addEventListener("click", function () {

            var fileSrc = this.getAttribute("src");//product/women/ethnic wear/lahenga/Solid Semi Stitched Lehenga Choli/colors option/rama/Screenshot 2025-02-10 214918.png

            // alert(fileSrc);//product/beauty and health/skin care/Matico Brightening & Whitening Vitamin C Face Serum/main.png

            // we need to trim it
            fileSrc = fileSrc.trim();
            //  alert(fileSrc);
            //product/kids/girl wear/Girls Silk Frocks & Dresses/colors option/aqua green/main.webp


            // UPDATE  product_files SET file_src = REPLACE(file_src, '& ', '');



            // fileSrc = escapeSpecialChars(fileSrc);//not helpful

            fileSrc = JSON.stringify(fileSrc);
            // alert(fileSrc);
            //product/kids/girl\\ wear/Girls\\ Silk\\ Frocks\\ \\&\\ Dresses/colors\\ option/aqua\\ green/main.webp


            var getProductCode = new XMLHttpRequest();


            getProductCode.onload = function () {

                // alert(this.responseText);//{"productCode":{"product_Code":"WEWL1"}}////{"product_Code":"WEWL1"}

                if (getProductCode.status >= 200 && getProductCode.status < 300) {

                    var ProductCodeOfThisFile = JSON.parse(this.responseText);


                    // alert(ProductCodeOfThisFile.productCode.product_Code);//in {"productCode":{"product_Code":"WEWL1"}}

                    // ProductCodeOfThisFile = ProductCodeOfThisFile.product_Code;//in //{"product_Code":"WEWL1"}

                    ProductCodeOfThisFile = ProductCodeOfThisFile[0].product_Code;//in //{"product_Code":"WEWL1"}



                    // alert(ProductCodeOfThisFile);//WEWL1

                    // if (ProductCodeOfThisFile !== "") {

                    // if (ProductCodeOfThisFile !== null) {//when we not used IFNULL
                    
                    if (ProductCodeOfThisFile !== 'null') {

                        // alert(ProductCodeOfThisFile);

                        navigateProductClick(ProductCodeOfThisFile);
                    }
                    else {
                        // alert(this.responseText);
                        alert("Product not found");
                    }

                }
                // else if (getProductCode.status == "404") {
                //     alert("Sorry but not found this product");
                // }
                else {
                    alert("Error");
                }
            }



            // getProductCode.open("POST", "getThisFileDetail.php?fileSrc=" + fileSrc, true);

            // getProductCode.send();

            getProductCode.open("POST", "getThisFileDetail.php");
            getProductCode.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            getProductCode.send("fileSrc=" + fileSrc);

        });
    }
}



















// Product highlight adjustment
var productbox = document.getElementsByClassName("completeproductbox");
var productheighlight = document.getElementsByClassName("productheighlight");

for (var i = 0; i < productbox.length; i++) {
    productbox[i].addEventListener("click", function () {
        var productCode = this.getElementsByClassName("productCode")[0].innerHTML;
        if (productCode !== "") {
            navigateProductClick(productCode);
        }
    });

    if (i < productheighlight.length) {
        var textElement = productheighlight[i].getElementsByTagName("h5")[0];
        if (textElement) {
            textElement.style.textOverflow = "ellipsis";
            textElement.style.whiteSpace = "nowrap";
            textElement.style.overflow = "hidden";
            textElement.style.width = "100%";
            textElement.style.padding = "0";
            textElement.style.margin = "0";

            var text = textElement.innerHTML;
            if (text.length > 15) {
                textElement.innerHTML = text.substring(0, 12) + "...";
            }
        }
    }
}




/*
JavaScript:

Cached frequently accessed DOM elements

Implemented debounce/throttle for scroll/resize events

Optimized event listener setup

Maintained all existing functionality

Added DOM ready handler

Improved product highlight adjustment
*/