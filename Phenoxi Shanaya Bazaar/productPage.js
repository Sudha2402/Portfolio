
// Optimized product page JavaScript
'use strict';

// Cache DOM elements and variables
var EmailAddress = sessionStorage.getItem("EmailAddress") || localStorage.getItem("EmailAddress");
var productIdOfThisPage = document.body.getAttribute("id").trim();
var mainPageHrefOrSrc = document.getElementById("mainPageHrefOrSrc").innerHTML.trim();
var SearchProductInnerHTML = document.querySelector(".similarproducts a").innerHTML;
var bodyOfThisPage = document.getElementsByClassName("productPage");
var lowerpopedUpPage = document.querySelector(".lowerpopedUpPage");
var clickedReviewImgOpener = document.querySelector(".clickedReviewImg");

// Product variables
var productName, priceOfThisProduct, mainImagOfThisProduct, sizeSelected, colorSelected, finalPrice;

// Initialize on window load
// window.addEventListener('load', () => {
//     console.log("Product page fully loaded");

//     document.getElementsByTagName("iframe")[0].setAttribute('loading', 'lazy');
//     //  headerFunction();

//     // Initialize header and other components
//     // document.getElementById("mainHeader").addEventListener("load", headerFunction);


//     // Initialize product details
//     productName = bodyOfThisPage[0].querySelector(".thisProductName").textContent;
//     mainImagOfThisProduct = bodyOfThisPage[0].querySelector(".sidesmallproducts img").src;

//     // Process path for similar products search
//     let pathsearch = window.location.href
//         .replace(/%20/g, " ")
//         .replace(/\s+/g, " ")
//         .toLowerCase();

//     pathsearch = pathsearch.substring(pathsearch.indexOf("/product") + 9);
//     pathsearch = pathsearch.substring(0, pathsearch.lastIndexOf('/')).replace(/&/g, "");

//     var pathsearch1 = pathsearch.substring(pathsearch.lastIndexOf('/') + 1);
//     var pathsearch4 = pathsearch.substring(pathsearch.indexOf("/") + 1);
//     var pathsearch3 = pathsearch4.substring(pathsearch4.indexOf("/") + 1);
//     var pathsearch2 = pathsearch3.substring(pathsearch3.indexOf("/") + 1);

//     // Search for similar products
//     searchGivenProduct(`${pathsearch1} /${pathsearch2} /${pathsearch3} /${pathsearch4} /${pathsearch} trendy`, 
//                       "similarproductsoptions", mainPageHrefOrSrc, SearchProductInnerHTML);

//     // Check for similar products after delay
//     setTimeout(() => {
//         var similarProductsContainer = document.getElementById("similarproductsoptions");
//         if (similarProductsContainer && !similarProductsContainer.querySelector("div:nth-child(2)")) {
//             similarProductsContainer.innerHTML = "<h4>Sorry, no similar products</h4>";
//             similarProductsContainer.removeAttribute("id");
//         }
//     }, 10000);
//     // }, 1000);



// (document.getElementsByTagName("iframe")[0]).style.display="block";



//     imgChange();
//     // initSizeSelection();
//     // initBuyNowButtons();
//     // initAddToCartButtons();
//     // initColorOptions();
//     // applyDiscounts();
//     reviewSet();

//     // Add product policy image if container exists
//     var productshortdetail = document.querySelector(".productshortdetail");
//     if (productshortdetail) {
//         var allproductpolicy = document.createElement('img');
//         allproductpolicy.className = 'allproductpolicy';
//         allproductpolicy.src = `${mainPageHrefOrSrc}files acc/allproductpolicy.jpg`;
//         productshortdetail.insertBefore(allproductpolicy, productshortdetail.querySelector("h4:nth-child(2)"));
//     }
// });







// window.alert("productjs");
var EmailAddress;

EmailAddress = sessionStorage.getItem("EmailAddress");
// alert(EmailAddress);

if (EmailAddress == null || EmailAddress == undefined) {
    // we can also get it from local storage
    EmailAddress = localStorage.getItem("EmailAddress");
}

// window.sessionStorage.setItem("previousPage", window.location.href);

// var  previousPage = sessionStorage.getItem("previousPage");
//                   alert(previousPage);


var productIdOfThisPage = document.body.getAttribute("id");
productIdOfThisPage = productIdOfThisPage.trim();

// alert(productIdOfThisPage);

// mainPageHrefOrSrc
var mainPageHrefOrSrc = document.getElementById("mainPageHrefOrSrc").innerHTML;

mainPageHrefOrSrc = mainPageHrefOrSrc.trim();
// window.alert(mainPageHrefOrSrc);


var SearchProductInnerHTML = document.getElementsByClassName("similarproducts")[0].firstElementChild.getElementsByTagName("a")[0].innerHTML;



document.getElementById("mainHeader").addEventListener("load", headerFunction);//it totally works
// document.body.addEventListener("load", headerFunction);//it totally works



// importing headerpart of main website
var headerOfProduct;

function getSecondLastSlashIndex(str) {
    const lastIndex = str.lastIndexOf('/');
    if (lastIndex === -1) {
        return -1; // No slashes found
    }
    return str.lastIndexOf('/', lastIndex - 1);
}



// document.body.setAttribute("onscroll","removeDropDown()");//as it will work only if at the top of page
document.body.setAttribute("ondblclick", "removeDropDown()");//as it will work only if at the top of page


function headerFunction() {



    var mainHeader = document.getElementById("mainHeader").contentWindow.document.getElementsByTagName("header")[0];
    var mainWelcome = document.getElementById("mainHeader").contentWindow.document.getElementById("Welcome");

    var mainHeaderAdopted = document.adoptNode(mainHeader);
    var mainWelcomeAdopted = document.adoptNode(mainWelcome);

    // document.body.getElementById("mainHeader").innerHTML=mainHeaderAdopted;//not works

    headerOfProduct = document.getElementById("mainHeaderNode");

    headerOfProduct.appendChild(mainHeaderAdopted);//works
    headerOfProduct.appendChild(mainWelcomeAdopted);//works

    var headertitle = headerOfProduct.getElementsByClassName("headertitle")[0];


    headertitle.style.display = "none";//uncomment if you want the productpage to see this title

    headertitle = headertitle.getElementsByTagName("img")[0];
    var titlelogo = headertitle.src;
    // alert(titlelogo);//http://localhost:3000/product/men/top%20wear/Stylish%20Glamorous%20Men%20Shirts/title%20logo.png

    // titlelogo = titlelogo.substring(titlelogo.lastIndexOf("/") + 1, titlelogo.length);
    // alert(titlelogo);
    //  titlelogo = titlelogo.substring(titlelogo.lastIndexOf("/") + 1, titlelogo.length);
    // replace %20 to " "


    titlelogo = titlelogo.substring(getSecondLastSlashIndex(titlelogo) + 1, titlelogo.length);


    titlelogo = titlelogo.replace(/%20/g, " ");
    // alert(titlelogo);//files acc/title logo.png
    // alert(titlelogo );//title%20logo.png
    //title logo.png
    headertitle.src = mainPageHrefOrSrc + titlelogo;
    // alert(headertitle.src);




    // headertitle.innerHTML = "";

    // var colorTheme = document.getElementById("colorTheme");
    // colorTheme.innerHTML = "";


    // we need to remove colorTheme from headerOfProduct
    // headerOfProduct.removeChild(colorTheme);//not works

    // to remove it 




    var headerinputs = headerOfProduct.getElementsByClassName("headerinputs")[0].getElementsByTagName("img")[0];
    var logo = headerinputs.src;
    // alert(logo);//http://localhost:3000/product/accessories/general%20products/Four%20Sided%20Folding%20Mirror/logo_enhanced.png
    //we need only the last /
    var logo = logo.substring(getSecondLastSlashIndex(logo) + 1, logo.length);

    // alert(logo);///logo_enhanced.png

    headerinputs.src = mainPageHrefOrSrc + logo;


    // element.remove();

    setTimeout(function () {

        var element = document.getElementsByTagName("iframe")[0];
        element.remove();
    }, 10000);

    //     var element = document.getElementsByTagName("iframe")[0];
    //      element.addEventListener('load', function () {
    //      alert(element.length);
    //         element.remove();
    //         alert(element.length);
    //  alert(element.length);
    // });



    var headerSearch = headerOfProduct.getElementsByClassName("headerinputs")[0];

    document.getElementById("mySelect").addEventListener("change", searchoutputInPage);



    headerSearch.addEventListener("click", headerPage);

    function headerPage() {

        // window.location.href = mainPageHrefOrSrc + "index.php";//we want that user can get the search from home with all ideas.


        if (document.searchProduct) {


            // document.searchProduct.searchProductEnteredbyTyping.addEventListener('keyup', function(event) {
            // filterFunction();
            // });

            // document.searchProduct.searchProductEnteredbyTyping.setAttribute("onkeyup","filterFunction()");


            //  filterFunction();

            document.searchProduct.searchProductEnteredbyTyping.addEventListener("keypress", function (event) {
                if (event.key === "Enter") {

                    event.preventDefault();



                    // document.getElementsByClassName("search")[0].click();

                    removeDropDown();

                    //                  window.location.href = mainPageHrefOrSrc + "index.php";//we want that user can get the search from home with all ideas.
                    searchoutputInPage();


                }
            });

            document.getElementsByClassName("search")[0].addEventListener("click", function (event) {
                event.preventDefault();


                // document.getElementsByClassName("search")[0].click();

                removeDropDown();

                searchoutputInPage();

            });
        }

    }

}


function searchoutputInPage() {

    if (document.getElementById("similarproductsoptions").style.display == "none") {

        document.getElementById("similarproductsoptions").style.display = "flex";

        //  document.getElementById("similarproductsoptions").setAttribute('id', 'similarproductsoptions');
        //  document.getElementsByClassName("similarproducts")[0].firstElementChild.setAttribute('id', 'similarproductsoptions');
        //  document.getElementsByClassName("similarproducts")[0].firstElementChild.setAttribute('id', 'similarproductsoptions');
        //  document.getElementById("similarproductsoptions").style.display="none";
        // var element=document.getElementsByClassName("similarproducts")[0].getElementsByTagName("h4")[0];
        document.getElementsByClassName("similarproducts")[0].removeChild(document.getElementsByClassName("similarproducts")[0].lastElementChild);


        //  alert("no");



    }

    if (document.getElementById("mySelect").value !== "allCategory") {
        var productEntered = document.getElementById("mySelect").value;
    }
    else {

        var productEntered = document.searchProduct.searchProductEnteredbyTyping.value;
    }

    // productEntered = productEntered.trim();
    // productEntered = productEntered.toLowerCase();
    // productEntered = productEntered.replace(/[^a-z0-9\s]/g, ''); //this line is used to remove all special symbols d%w3 changes to  dw3

    productEntered = productEntered.replace(/\s+/g, ' '); //this line is used to remove all extra spaces between words

    // alert(productEntered);

    if (productEntered == "") {




        document.getElementById("resultOutput").style.display = "flex";

        document.getElementById("resultOutput").innerHTML = "Please type the product you want to search for";
        // alert("empty");//ok


        setTimeout(function () {
            document.getElementById("resultOutput").style.display = "none";

        }, 5000);
        // return;
    }
    else {

        document.getElementsByClassName("similarproducts")[0].previousElementSibling.innerHTML = "Your search result for '" + productEntered + "' is ready";

        searchGivenProduct(productEntered, "similarproductsoptions", mainPageHrefOrSrc, SearchProductInnerHTML);
        document.getElementById("similarproductsoptions").scrollIntoView({ behavior: "smooth", block: "center" });

    }



}


var productID = document.body.getAttribute("id");
// alert(productID);
var productName;
var priceOfThisProduct;
var mainImagOfThisProduct;
var sizeSelected;
var colorSelected;

var bodyOfThisPage = document.getElementsByClassName("productPage");
var finalPrice;


window.onload = () => {

    console.log("page is fully loaded");
    // alert("page is fully loaded");


    document.getElementsByTagName("iframe")[0].setAttribute('loading', 'lazy');

    EmailRelatedLogin(mainPageHrefOrSrc, EmailAddress);//function is connected

    productName = bodyOfThisPage[0].getElementsByClassName("thisProductName")[0].textContent;//works

    // mainImagOfThisProduct = bodyOfThisPage[0].getElementsByClassName("bigproductimag")[0].src;
    mainImagOfThisProduct = bodyOfThisPage[0].getElementsByClassName("sidesmallproducts")[0].getElementsByTagName("img")[0].src;//it is in case we have selected not the main image in bigimag



    var pathsearch = window.location.href;
    // remove upto /product

    pathsearch = pathsearch.replace(/%20/g, " ");
    // remove extra white space in between
    pathsearch = pathsearch.replace(/\s+/g, " ");
    pathsearch = pathsearch.toLowerCase();

    pathsearch = pathsearch.substring(pathsearch.indexOf("/product") + 9);

    pathsearch = pathsearch.substring(0, pathsearch.lastIndexOf('/'));//women/ethnic wear/lahenga/solid semi stitched lehenga choli

    // alert(pathsearch);
    //maybe & symbol is creating problem , let's remove it too
    pathsearch = pathsearch.replace(/&/g, "");
    // alert(pathsearch);//kids/girl wear/stylish partywear multicolor cotton girls frocks  dresses

    var pathsearch1 = pathsearch.substring(pathsearch.lastIndexOf("/") + 1, pathsearch.length);//solid semi stitched lehenga choli
    // alert(pathsearch1);

    // pathsearch2 = pathsearch.substring(pathsearch.indexOf("/"),pathsearch.lastIndexOf('/'));///Beautifull Embroidey Zari Work Lehenga For Women With Blouse Piece And Dupatta.html

    // we want substring from second index of / to last

    var pathsearch4 = pathsearch.substring(pathsearch.indexOf("/") + 1);//ethnic wear/lahenga/solid semi stitched lehenga choli
    // alert()
    // alert("pathsearch4 : " + pathsearch4);//pathsearch4 : girl wear/stylish partywear multicolor cotton girls frocks  dresses

    var pathsearch3 = pathsearch4.substring(pathsearch4.indexOf("/") + 1);

    var pathsearch2 = pathsearch3.substring(pathsearch3.indexOf("/") + 1);//incase if not / is present then
    // alert(pathsearch2);//stylish partywear multicolor cotton girls frocks  dresses

    // i want it to return a promise and that promise to be listen by this then we will said no similar products after when no product is returned

    // getSimilarProducts(pathsearch2).then((similarProducts) => {
    //     if (similarProducts.length === 0) {
    //         console.log("No similar products found");
    //     } else {
    //         console.log("Similar products found");
    //         // console.log(similarProducts);
    //     }
    // }).catch((error) => {
    //     console.error(error);
    // });


    // searchGivenProduct(pathsearch1 + " /" + pathsearch2 + " /" + pathsearch3 + " /" + pathsearch4 + " /" + pathsearch + " trendy", "similarproductsoptions", mainPageHrefOrSrc, SearchProductInnerHTML).then((similarProducts) => {
    //     if (similarProducts.length === 0) {

    //         console.log("No similar products found");

    //         if (document.getElementById("similarproductsoptions").getElementsByTagName("div")[2] == null) {

    //             document.getElementById("similarproductsoptions").innerHTML = "<h2>Sorry, no similar products</h2>";
    //         }

    //     } else {
    //         console.log("Similar products found");
    //         // console.log(similarProducts);

    //     }
    // }).catch((error) => {
    //     console.error(error);
    // });



    // alert(pathsearch1 + " /" + pathsearch2 + " /" + pathsearch3 + " /" + pathsearch4 + " /" + pathsearch + " trendy");

    searchGivenProduct(pathsearch1 + " /" + pathsearch2 + " /" + pathsearch3 + " /" + pathsearch4 + " /" + pathsearch + " trendy", "similarproductsoptions", mainPageHrefOrSrc, SearchProductInnerHTML);


    // reloadSimilar();

    // function reloadSimilar() {


    setTimeout(function () {
        // alert(document.getElementById("similarproductsoptions").getElementsByTagName("div")[2]);



        if (document.getElementById("similarproductsoptions").getElementsByTagName("div")[2] == null) {

            // document.getElementById("similarproductsoptions").innerHTML = "<h4>Sorry, no similar products</h4>";
            // document.getElementById("similarproductsoptions").write += "<h4>Sorry, no similar products</h4>";
            // document.getElementById("similarproductsoptions").innerHTML += "<h4>Sorry, no similar products</h4>";

            // searchGivenProduct("trendy", "similarproductsoptions", mainPageHrefOrSrc, SearchProductInnerHTML);

            // document.getElementById("similarproductsoptions").removeAttribute("id");//if no reload we want

            document.getElementById("similarproductsoptions").style.display = "none";

            document.getElementsByClassName("similarproducts")[0].innerHTML += "<h4>Sorry, no similar products</h4>";



            // function autoRefresh() {
            //         window.location = window.location.href;
            //     }
            // setInterval(autoRefresh, 1000);//it's reloading it again and again
            //  <meta http-equiv="refresh" content="10">//in head part of the page to refresh after every 10s


            // searchGivenProduct(pathsearch1 + " /" + pathsearch2 + " /" + pathsearch3 + " /" + pathsearch4 + " /" + pathsearch + " trendy", "similarproductsoptions", mainPageHrefOrSrc, SearchProductInnerHTML);

            // reloadSimilar();
        }

        else {
            // document.getElementById("similarproductsoptions").style.display="flex";
        }

    }, 10000);
    // }



};







var clickedReviewImgOpener = document.getElementsByClassName("clickedReviewImg")[0];




function imgopener() {

    var reviewboximg = document.getElementsByClassName("reviewBoxes")[0].getElementsByTagName("img");


    for (var i = 0; i < reviewboximg.length; i++) {

        reviewboximg[i].addEventListener("click", function () {
            //we want to see the full size in window      



            clickedReviewImgOpener.style.display = "block";

            clickedReviewImgOpener.getElementsByClassName("imgOpener")[0].src = this.src;

            // clickedReviewImgOpener.getElementsByClassName("imgOpener")[0].src = this.firstElementChild.src;


        });
    }
}



if (document.getElementsByClassName("sizeOpen")) {


    var sizeOpen = document.getElementsByClassName("sizeOpen")[0];
    // alert(sizeOpen);

    if (sizeOpen != undefined) {

        sizeOpen.addEventListener("click", function () {
            document.getElementsByClassName("sizeSelect")[0].style.display = "block";

        });
    }

}


if (document.getElementsByClassName("sizeSelect")) {
    var sizeSelectButton = document.getElementsByClassName("sizeSelectButton");
    for (var i = 0; i < sizeSelectButton.length; i++) {

        // sizeSelectButton[i].style.backgroundColor="white";
        sizeSelectButton[i].addEventListener("click", function () {
            for (var i = 0; i < sizeSelectButton.length; i++) {
                sizeSelectButton[i].style.backgroundColor = "white";
            }

            this.style.backgroundColor = "lightgreen";
            if (document.getElementsByClassName("sizeValue")[0]) {

                sizeSelected = this.getElementsByClassName("sizeValue")[0].innerText;

                // priceWithSize
                var priceWithSize = this.getElementsByClassName("priceWithSize")[0].innerText;
                // alert(priceWithSize);
                var currentpricePerSize = document.getElementsByClassName("finalPriceDecided")[0];

                currentpricePerSize.innerHTML = priceWithSize;

            }
            else {
                sizeSelected = this.innerText;
            }


            // alert(sizeSelected);

        }



        );
    }

}





var lowerpopedUpPage = document.getElementsByClassName("lowerpopedUpPage")[0];

var buyNowClicked = document.getElementsByClassName("buyNow");

// alert(buyNowClicked.length);//2

var parentHrefOfProductOfBuy = buyNowClicked[0].parentElement.href;//we want cart also //uncomment if stuck
// alert(parentHrefOfProductOfBuy);

for (var i = 0; i < buyNowClicked.length; i++) {



    // AddToCartClicked[i].parentElement.removeAttribute("href");
    buyNowClicked[i].parentElement.removeAttribute("href");

    buyNowClicked[i].addEventListener("click", function () {
        // alert("buy now clicked");

        // alert(document.getElementsByClassName("sizeSelectButton")[0]);

        if (productName != undefined && mainImagOfThisProduct != undefined && priceOfThisProduct != undefined) {




            if ((sizeSelected === undefined || sizeSelected === null) && document.getElementsByClassName("sizeSelectButton")[0] !== undefined) {

                //check document has sizeSelectButton classname
                // document.hasChild

                // buyNowClicked[i].parentElement.removeAttribute("href");

                // alert("Please select a size");
                document.getElementsByClassName("sizeSelectedOutput")[0].innerHTML = "Please select a size";

                this.parentElement.href = "#";

                lowerpopedUpPage.style.display = "flex";
                lowerpopedUpPage.innerHTML = "Please select a size";

                setTimeout(function () {
                    document.getElementsByClassName("sizeSelectedOutput")[0].innerHTML = "";
                }, 3000);





                setTimeout(function () {
                    lowerpopedUpPage.style.display = "none";
                }, 3000);



            }

            else {

                buyNowClicked[i].parentElement.removeAttribute("href");

                // if(mainImagOfThisProduct == undefined){
                //     alert("Server is slow . Retry after few seconds");

                //     // return ;   
                // }


                // alert("check email");

                if (EmailAddress === undefined || EmailAddress === null) {



                    document.getElementsByClassName("sizeSelectedOutput")[0].innerHTML = "Please login to buy";

                    lowerpopedUpPage.style.display = "flex";
                    lowerpopedUpPage.innerHTML = "Please login to buy";

                    setTimeout(function () {
                        lowerpopedUpPage.style.display = "none";
                    }, 3000);

                    this.parentElement.href = "#";

                    // add attribute href which was removed earlier



                    // buyNowClicked[i].parentElement.


                }
                else {
                    // alert(sizeSelected);//undefined
                    // if(sizeSelected !== undefined || sizeSelected !== null){ //keeping null will take here.

                    if (sizeSelected !== undefined) {

                        if (document.getElementsByClassName("finalPriceDecided")[0] !== undefined) {

                            finalPrice = document.getElementsByClassName("finalPriceDecided")[0].innerHTML;
                            finalPrice = Number(finalPrice.replace("₹", ""));


                            this.parentElement.href = parentHrefOfProductOfBuy + "?" + "productID=" + productID + "&productName=" + productName + "&priceOfThisProduct=" + finalPrice + "&mainImagOfThisProduct=" + mainImagOfThisProduct + "&sizeSelected=" + sizeSelected;


                        }
                        else {


                            // alert("buy now");
                            this.parentElement.href = parentHrefOfProductOfBuy + "?" + "productID=" + productID + "&productName=" + productName + "&priceOfThisProduct=" + priceOfThisProduct + "&mainImagOfThisProduct=" + mainImagOfThisProduct + "&sizeSelected=" + sizeSelected;//
                            // alert(this.parentElement.href);

                        }


                    }
                    else {



                        if (document.getElementsByClassName("finalPriceDecided")[0] !== undefined) {

                            finalPrice = document.getElementsByClassName("finalPriceDecided")[0].innerHTML;
                            // remove rs symbol from it and only numbers are taken
                            finalPrice = Number(finalPrice.replace("₹", ""));

                            this.parentElement.href = parentHrefOfProductOfBuy + "?" + "productID=" + productID + "&productName=" + productName + "&priceOfThisProduct=" + finalPrice + "&mainImagOfThisProduct=" + mainImagOfThisProduct + "&sizeSelected=" + sizeSelected;

                            // http://localhost:3000/cart.html?productID=KGW4&productName=Baby%20Girls%20trendy%20western%20Dress&priceOfThisProduct=%E2%82%B9325&mainImagOfThisProduct=http://localhost:3000/product/kids/girl%20wear/Baby%20Girls%20trendy%20western%20Dress/colors%20option/red/main.webp&sizeSelected=13-14%20years

                        }

                        else {


                            this.parentElement.href = parentHrefOfProductOfBuy + "?" + "productID=" + productID + "&productName=" + productName + "&priceOfThisProduct=" + priceOfThisProduct + "&mainImagOfThisProduct=" + mainImagOfThisProduct;


                            // http://localhost:3000/buymethods.html?productID=WWAW1&productName=%20Flowered%20Dial%20Megnet%20Watch&priceOfThisProduct=264&mainImagOfThisProduct=http://localhost:3000/product/women/women%20accessories/watch/Flowered%20Dial%20Megnet%20Watch/colors%20option/ssr1i_512.png
                        }

                    }
                }

            }
        }
        else {
            lowerpopedUpPage.style.display = "flex";
            lowerpopedUpPage.innerHTML = "Server is slow. Please wait to load the page completely.";

            setTimeout(function () {
                lowerpopedUpPage.style.display = "none";
            }, 3000);

        }


    });
}

// }, 3000);


if (document.getElementsByClassName("productshortdetail")[0]) {
    var productshortdetailImgPolicy = document.getElementsByClassName("productshortdetail")[0];
    var allproductpolicy = document.createElement('img'); // Container for progress bar and file name
    allproductpolicy.className = 'allproductpolicy';
    // allproductpolicy.src = mainPageHrefOrSrc + "files acc/allproductpolicy.webp";
    allproductpolicy.src = mainPageHrefOrSrc + "files acc/allproductpolicy.jpg";
    // productshortdetailImgPolicy.insertAdjacentElement(allproductpolicy);
    productshortdetailImgPolicy.insertBefore(allproductpolicy, productshortdetailImgPolicy.getElementsByTagName("h4")[1]);
}





var AddToCartClicked = document.getElementsByClassName("addToCart");

var parentHrefOfProductOfCart = AddToCartClicked[0].parentElement.href;

for (var i = 0; i < AddToCartClicked.length; i++) {

    AddToCartClicked[i].parentElement.removeAttribute("href");
    // buyNowClicked[i].parentElement.removeAttribute("href");

    // if(mainImagOfThisProduct == undefined){
    //     alert("Server is slow . Retry after few seconds");
    //     return ;   
    // }

    AddToCartClicked[i].addEventListener("click", function () {

        if (productName != undefined && mainImagOfThisProduct != undefined && priceOfThisProduct != undefined) {

            if ((sizeSelected === undefined || sizeSelected === null) && document.getElementsByClassName("sizeSelectButton")[0] !== undefined) {

                // alert("Please select a size");
                document.getElementsByClassName("sizeSelectedOutput")[0].innerHTML = "Please select a size";

                // document.getElementsByClassName("lowerpopedUpPage")[0].style.display = "flex";
                // document.getElementsByClassName("lowerpopedUpPage")[0].innerHTML = "Please select a size";

                this.parentElement.href = "#";

                lowerpopedUpPage.style.display = "flex";
                lowerpopedUpPage.innerHTML = "Please select a size";

                setTimeout(function () {
                    lowerpopedUpPage.style.display = "none";
                    document.getElementsByClassName("sizeSelectedOutput")[0].innerHTML = "";
                }, 3000);



            }


            else {

                AddToCartClicked[i].parentElement.removeAttribute("href");

                if (EmailAddress === undefined || EmailAddress === null) {
                    // alert("Please enter your email");
                    document.getElementsByClassName("sizeSelectedOutput")[0].innerHTML = "Please login to buy";

                    // document.getElementsByClassName("lowerpopedUpPage")[0].style.display = "flex";
                    // document.getElementsByClassName("lowerpopedUpPage")[0].innerHTML = "Please login to buy";

                    lowerpopedUpPage.style.display = "flex";
                    lowerpopedUpPage.innerHTML = "Please login to buy";

                    setTimeout(function () {
                        lowerpopedUpPage.style.display = "none";
                        document.getElementsByClassName("sizeSelectedOutput")[0].innerHTML = "";
                    }, 3000);

                    this.parentElement.href = "#";

                }

                else {

                    if (sizeSelected !== undefined) {

                        if (document.getElementsByClassName("finalPriceDecided")[0] !== undefined) {

                            finalPrice = document.getElementsByClassName("finalPriceDecided")[0].innerHTML;
                            finalPrice = Number(finalPrice.replace("₹", ""));

                            this.parentElement.href = parentHrefOfProductOfCart + "?" + "productID=" + productID + "&productName=" + productName + "&priceOfThisProduct=" + finalPrice + "&mainImagOfThisProduct=" + mainImagOfThisProduct + "&sizeSelected=" + sizeSelected;

                        }


                        else {
                            this.parentElement.href = parentHrefOfProductOfCart + "?" + "productID=" + productID + "&productName=" + productName + "&priceOfThisProduct=" + priceOfThisProduct + "&mainImagOfThisProduct=" + mainImagOfThisProduct + "&sizeSelected=" + sizeSelected;//http://localhost:3000/buymethods.html?productID=WBW1&productName=Anara%20Fashion%20Women%27s%20Solid%20Bell%20Bottoms%20Black%20Trousers%20&%20Pants&priceOfThisProduct=180&mainImagOfThisProduct=http://localhost:3000/product/women/bottom%20wear/Anara%20Fashion%20Women%20Solid%20Bell%20Bottoms%20Black%20Trousers%20&%20Pants/colors%20option/black/rj4nc_512.png&sizeSelected=30?EmailAddress=undefined


                        }
                    }
                    else {

                        if (document.getElementsByClassName("finalPriceDecided")[0] !== undefined) {
                            finalPrice = document.getElementsByClassName("finalPriceDecided")[0].innerHTML;
                            finalPrice = Number(finalPrice.replace("₹", ""));

                            this.parentElement.href = parentHrefOfProductOfCart + "?" + "productID=" + productID + "&productName=" + productName + "&priceOfThisProduct=" + finalPrice + "&mainImagOfThisProduct=" + mainImagOfThisProduct + "&sizeSelected=" + sizeSelected;

                        }
                        else {
                            this.parentElement.href = parentHrefOfProductOfCart + "?" + "productID=" + productID + "&productName=" + productName + "&priceOfThisProduct=" + priceOfThisProduct + "&mainImagOfThisProduct=" + mainImagOfThisProduct;
                        }
                    }
                }
            }

        }
        else {
            lowerpopedUpPage.style.display = "flex";
            lowerpopedUpPage.innerHTML = "Server is slow. Please wait to load the page completely.";

            setTimeout(function () {
                lowerpopedUpPage.style.display = "none";
            }, 3000);

        }
    });
}





//showing sidesmallproducts in mainproductimg
//we will just update the src


var smallimg = document.getElementsByClassName("productcolumn");



imgChange();

function imgChange() {
    for (var i = 0; i < smallimg.length; i++) {

        // alert(smallimg[i].src);//http://127.0.0.1:5500/Hair%20cap%20steamer/Hair-Care-Thermal-Head-Spa-Cap4-1653281008.jpg //for the first i=0 then it will show for i=2 etc..


        smallimg[i].addEventListener("click", function () {


            var srcsmallimg = this.src;


            var mainimg = this.parentElement.parentElement.getElementsByClassName("mainproductimg")[0].firstElementChild;//mainproductimg ;bigproductimag





            mainimg.src = srcsmallimg; //this works

            for (var i = 0; i < smallimg.length; i++) {

                smallimg[i].style.backgroundColor = "white";
                smallimg[i].style.border = "none";

            }

            // this.style.backgroundColor="#dcdcdc";
            // alert(mainimg);
            this.style.border = "solid black 4px";

        });
    }
}












for (var i = 0; i < document.getElementsByClassName("row").length; i++) {
    // document.getElementsByClassName("row")[i].style.display="block";
}



if (document.getElementsByClassName("colorOptions")[0]) {
    var colorOptions = document.getElementsByClassName("colorOptions")[0].innerHTML;
    var colorOptionsDiv = document.createElement('div'); // Container for progress bar and file name
    colorOptionsDiv.className = 'colorOptions sidecolors';
    colorOptionsDiv.innerHTML = colorOptions;

    var productshortdetailcolorOptionsContainer = document.getElementsByClassName("productshortdetail")[0];
    var colorOptionsContainer = document.getElementsByClassName("discountcut")[0].parentElement.nextElementSibling;

    productshortdetailcolorOptionsContainer.insertBefore(colorOptionsDiv, colorOptionsContainer);

}


var colorsGivenOptions = document.getElementsByClassName("colorsGiven");

for (var i = 0; i < colorsGivenOptions.length; i++) {

    colorsGivenOptions[i].addEventListener("click", function () {
        var srccolorsGivenOptions = this.src;
        // var mainimg = this.parentElement.parentElement.getElementsByClassName("mainproductimg")[0].firstElementChild;
        var mainimg = document.getElementsByClassName("mainproductimg")[0].firstElementChild;
        mainimg.src = srccolorsGivenOptions;
        mainImagOfThisProduct = mainimg.src;


        // we also need to change the sidesmallproducts 


        var fileSrc = this.getAttribute("src");
        fileSrc = fileSrc.trim();
        fileSrc = JSON.stringify(fileSrc);

        // productIdOfThisPage needs to be encoded
        var productIdOfThisPagePassed = JSON.stringify(productIdOfThisPage);


        // alert(fileSrc);//"colors option/violet/ynhi3_512.png"

        var getProductCodeWithColor = new XMLHttpRequest();

        getProductCodeWithColor.onload = function () {




            if (getProductCodeWithColor.status >= 200 && getProductCodeWithColor.status < 300) {

                // alert(this.responseText);

                var colorProduct = JSON.parse(this.responseText);


                colorProduct = colorProduct[1];//

                // alert(colorProduct);
                // alert(JSON.stringify(colorProduct));

                //[object Object],[object Object],[object Object],[object Object],[object Object],[object Object],[object Object],[object Object]

                // if (colorProduct !== "") {

                // if (colorProduct !== null) {//when we not used IFNULL

                var sidesmallproductsContainer = document.getElementsByClassName("sidesmallproducts")[0];
                var sidesmallproductsClone = document.getElementsByClassName("sidesmallproducts")[0].getElementsByTagName("img")[0];

                // making clone of sidesmallproductsClone
                sidesmallproductsClone = sidesmallproductsClone.cloneNode(true);




                // if (colorProduct !== undefined) {
                // if (colorProduct !== null) {//this null will create error in main php hence , we changed it to 'null' in php

                sidesmallproductsContainer.innerHTML = "";

                if (colorProduct !== 'null') {

                    // sidesmallproductsContainer.innerHTML = "";
                    // "file_src"

                    //for loop to get each row of colorProduct
                    for (var j = 0; j < colorProduct.length; j++) {

                        var colorSrc = colorProduct[j].file_src;
                        //alert(fileSrc);
                        sidesmallproductsClone.src = mainPageHrefOrSrc + colorSrc;

                        sidesmallproductsContainer.innerHTML += sidesmallproductsClone.outerHTML;


                    }

                    if (colorProduct[0].Quantity_Pack_Name !== null) {
                        var quantityPackName = colorProduct[0].Quantity_Pack_Name;
                        var quantityPackPrice = colorProduct[0].Quantity_Pack_Price;

                        // productName=quantityPackName;

                        bodyOfThisPage[0].getElementsByClassName("thisProductName")[0].innerText = quantityPackName;

                        var currentpricePerQuantity = document.getElementsByClassName("finalPriceDecided")[0];

                        // currentpricePerQuantity.innerHTML = quantityPackPrice;
                        currentpricePerQuantity.innerHTML = `<span class="pricesystem">&#8377;</span>` + quantityPackPrice;




                        var discountselect = discountpercent[0];

                        var discountselectedval = Number(discountselect.innerHTML);

                        var currentprice = discountselect.parentElement.previousElementSibling.innerText;
                        currentprice = Number(currentprice.replace("₹", ""));

                        var price = (100 * currentprice) / (100 - discountselectedval);
                        // alert(price);//OK
                        // currentprice.innerText = "₹" + price.toFixed(2);


                        discountselect.parentElement.nextElementSibling.innerHTML = `<span class="discountcut"><span class="pricesystem">&#8377;</span>` + price.toFixed(0) + `</span>`;

                        // <span class="discountcut"><span class="pricesystem">&#8377;</span>499</span> 


                        // we want to replace innerhtml of class priceWithSize with this currentprice
                        var priceWithSize = document.getElementsByClassName("priceWithSize");
                        // start a for loop
                        for (var i = 0; i < priceWithSize.length; i++) {
                            priceWithSize[i].innerHTML = `<span class="pricesystem">&#8377;</span>
        ` + currentprice;
                        }






                    }

                }
                else {

                    // alert("Product not found");

                    // sidesmallproductsClone.src = fileSrc;

                    // sidesmallproductsClone.src = this.getAttribute("src");



                    sidesmallproductsClone.src = colorsGivenOptions[i].getAttribute("src");

                    sidesmallproductsContainer.innerHTML += sidesmallproductsClone.outerHTML;

                }

            }
            else {
                alert("Error");
            }

            imgChange();


        }



        // getProductCode.open("POST", "getThisFileDetail.php?fileSrc=" + fileSrc, true);

        // getProductCode.send();

        getProductCodeWithColor.open("POST", mainPageHrefOrSrc + "getThisFileDetail.php");
        getProductCodeWithColor.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        // getProductCodeWithColor.send("fileSrc=" + fileSrc);
        // getProductCodeWithColor.send("productCode=" + productIdOfThisPage);
        //we have to send them combined
        getProductCodeWithColor.send("fileSrc=" + fileSrc + "&productCode=" + productIdOfThisPagePassed);





    });
}





var discountpercent = document.getElementsByClassName("discountpercent");

for (var i = 0; i < discountpercent.length; i++) {
    var discountselect = discountpercent[i];
    var discountselectedval = Number(discountselect.innerHTML);

    var price = discountselect.parentElement.nextElementSibling.innerText;
    // price=price.replace("₹", "");
    price = Number(price.replace("₹", ""));
    // alert(price);
    // price=document.getElementsByClassName("discountcut");



    var currentprice = discountselect.parentElement.previousElementSibling;
    var price = (100 - discountselectedval) * price / 100;
    // alert(price);//OK
    // currentprice.innerText = "₹" + price.toFixed(2);

    priceOfThisProduct = price.toFixed(0);//to store this value globally


    currentprice.innerHTML = `<span class="pricesystem">&#8377;</span>` + price.toFixed(0);
    // alert(currentprice);


}


var CustomerimagesUploaded;
var reviewImagesBoxOfReviewer = document.getElementsByClassName("absoluteAllReviewImage")[0];
reviewImagesBoxOfReviewer.style.display = "none";
var reviewBoxesClone = reviewImagesBoxOfReviewer.firstElementChild;

// in main , it is with onclick


function openAllCustomerReviewFiles() {

    var productCode = productIdOfThisPage;
    // alert(productCode);

    productCode = JSON.stringify(productCode);

    var UploadCustomersImages = new XMLHttpRequest();

    UploadCustomersImages.onload = function () {
        if (this.status == 200) {

            // alert(this.responseText);

            CustomerimagesUploaded = JSON.parse(this.responseText);


            //https://www.meesho.com/pack-of-6-pure-cotton-briefs-for-women-and-girls-for-every-day-use-comfortable-multicoloured-pantys/p/6jglme


            reviewImagesBoxOfReviewer.style.display = "flex";

            if (CustomerimagesUploaded.images.length > 1) {
                reviewImagesBoxOfReviewer.innerHTML = "";

            }
            else {

                reviewImagesBoxOfReviewer.innerHTML = "Sorry, No review files loadable";
            }



            for (var i = 0; i < CustomerimagesUploaded.images.length; i++) {

                // alert(CustomerimagesUploaded.images[i]);//perfect

                // CustomerimagesUploaded.images[i].indexOf("review");//2

                // var img = document.createElement("img");//not good looking

                // img.src = CustomerimagesUploaded.images[i].substring(CustomerimagesUploaded.images[i].lastIndexOf('/').lastIndexOf('/') + 1);//product/women/ethnic wear/kurta sets/Pakistani Suit  Women Kurta Pair/review/67c1aec4a91d7_5star.png.gif

                // we want image src from /review/67c1aec4a91d7_5star.png.gif that is to fing second last index of / 

                // customerreviewfiles = document.getElementsByClassName("customerReviewImage")[0];//uncomment

                var image = CustomerimagesUploaded.images[i].substring(CustomerimagesUploaded.images[i].indexOf("review"));


                // alert(image);


                reviewBoxesClone.getElementsByTagName("img")[0].src = image;

                reviewImagesBoxOfReviewer.innerHTML += reviewBoxesClone.outerHTML;

            }

            allReviewFilesImageOpener();


        }

    }



    UploadCustomersImages.open("POST", mainPageHrefOrSrc + "getReviewFiles.php");

    UploadCustomersImages.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

    UploadCustomersImages.send("productCode=" + productCode);



}




function allReviewFilesImageOpener() {


    var reviewboximg = document.getElementsByClassName("reviewImages")[0].getElementsByTagName("img");

    for (var i = 0; i < reviewboximg.length; i++) {

        reviewboximg[i].addEventListener("click", function () {
            //we want to see the full size in window      

            var clickedReviewImgOpener = document.getElementsByClassName("clickedReviewImg")[0];


            clickedReviewImgOpener.style.display = "block";

            clickedReviewImgOpener.getElementsByClassName("imgOpener")[0].src = this.src;

            // clickedReviewImgOpener.getElementsByClassName("imgOpener")[0].src = this.firstElementChild.src;


        });
    }

}





//innerHTML
var data;
function showReviewForm(element) {



    data = element.parentElement.getElementsByClassName("addYourReview")[0];

    // element.page

    // alert(data.className);

    data.style.display = "block";

    // location.hash = "#AddYourReviewSelected";//perfect way of calling hash.//also works
    location.hash = "AddYourReviewSelected";//works for calling hash.

    if (link.indexOf("#") != -1) {
        var id = link.substring(1);
        var element = document.getElementById(id);
        if (element) {
            element.scrollIntoView({ behavior: "smooth", block: "center" });
            //smooth scroll to id
        }
    }


}





var form = document.querySelector('form');
form.addEventListener('submit', function (event) {
    event.preventDefault(); //we used this to prevent reload of page after XMLHttpRequest
    // Your form submission logic here 
});


var productCode;
var reviewEmail = document.getElementsByName("email")[0].value;
var checkedValueOfReviewOfProdct;

function submitReview() {


    for (var i = 0; i < document.getElementsByName("rate").length; i++) {

        if (document.getElementsByName("rate")[i].checked) {

            // this method which we tried using post directly not works, now let's try to use ajax
            // productCode = document.getElementsByName("productCode")[0];
            // productCode.value = productIdOfThisPage;

            checkedValueOfReviewOfProdct = document.getElementsByName("rate")[i].value;

            // alert(checkedValueOfReviewOfProdct);//it works here

        }
    }



    productCode = productIdOfThisPage;

    var reviewName = document.getElementsByName("name")[0].value;

    // document.getElementsByName("name")[0].value=EmailAddress;

    reviewEmail = document.getElementsByName("email")[0].value;

    var reviewText = document.getElementsByName("comment")[0].value;


    if (checkedValueOfReviewOfProdct) {
        // alert(checkedValueOfReviewOfProdct);//4

        if (reviewEmail) {

            // var email = JSON.stringify(EmailAddress);

            // var checkedValueOfReviewOfProdctP = JSON.stringify(checkedValueOfReviewOfProdct);

            // var dbparam = {productCode:productCode, EmailAddress: reviewEmail, reviewName: reviewName, reviewText: reviewText, checkedValueOfReviewOfProdct: checkedValueOfReviewOfProdct,files:files };

            var dbparam = { productCode: productCode, EmailAddress: reviewEmail, reviewName: reviewName, reviewText: reviewText, checkedValueOfReviewOfProdct: checkedValueOfReviewOfProdct };
            // alert(dbparam);//[object object]

            dbparam = JSON.stringify(dbparam);

            // alert(dbparam);//{"EmailAddress":"sudhakumarichauhan24@gmail.com","reviewName":"Sudha Kumari","reviewText":"ho","checkedValueOfReviewOfProdct":"2"}



            var UploadCustomersReview = new XMLHttpRequest();

            UploadCustomersReview.onload = function () {
                if (this.status == 200) {

                    var response = JSON.parse(this.responseText);

                    if (response.status == "true") {
                        // alert("Review Added Successfully");
                        document.getElementById("resultOutput").style.display = "flex";
                        document.getElementById("resultOutput").innerHTML = response.message;

                        setTimeout(function () {
                            document.getElementById("resultOutput").style.display = "none";
                        }, 4000);
                    } else {

                        // alert(response.message);
                        document.getElementById("resultOutput").style.display = "flex";
                        document.getElementById("resultOutput").innerHTML = response.message;

                        setTimeout(function () {
                            document.getElementById("resultOutput").style.display = "none";
                        }, 4000);

                    }



                }

            }



            UploadCustomersReview.open("POST", mainPageHrefOrSrc + "uploadCustomersReview.php");

            UploadCustomersReview.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

            UploadCustomersReview.send("dbparam=" + dbparam);
            // UploadCustomersReview.send(formData);
            // we need to send dbparam and formData together.
            // UploadCustomersReview.send("dbparam=" + dbparam + "&formData=" + formData);




            setTimeout(function () {
                document.getElementById("resultOutput").style.display = "none";
            }, 10000);

            // document.getElementById("resultOutput").innerHTML = checkedValueOfReviewOfProdct;
        }

        else {
            document.getElementById("resultOutput").style.display = "flex";
            document.getElementById("resultOutput").innerHTML = "Please fill all the data carefully";
        }
    }
    else {
        // alert("Please select a rating");//when undefined 
        document.getElementById("resultOutput").style.display = "flex";
        document.getElementById("resultOutput").innerHTML = "Please select a rating";
    }

    setTimeout(function () {

        document.getElementById("resultOutput").style.display = "none";

    }, 4000);



}


// https://bootstrapfriendly.com/blog/uploading-multiple-files-with-progress-bar-via-ajax-and-php

var path;
path = window.location.pathname;
path = path.replace(/%20/g, " ");
path = path.substring(0, path.lastIndexOf('/'));
path = path.substring(1);


function uploadFiles() {

    var fileInput = document.getElementById('fileUpload');
    var files = fileInput.files;//list of all the files uploaded

    // tracking path of the page from where this function is called

    path = window.location.pathname;//product/women/ethnic wear/kurta sets/Pakistani Suit  Women Kurta Pair/Embroidery Gaithering Anarkali kurtis.php  gives relative address after  replace(/%20/g, " ")



    path = path.replace(/%20/g, " ");

    for (var i = 0; i < files.length; i++) {

        var allowedExtensions = ['.jpg', '.jpeg', '.png', '.pdf', '.svg', '.zip', '.docx', '.xlsx', 'image/*', ' video/*', '.mp4', '.gif'];
        var fileExtension = files[i].name.substring(files[i].name.lastIndexOf('.')).toLowerCase();

        if (allowedExtensions.includes(fileExtension)) {
            uploadFile(files[i]);//passing one file from the list at a time
        } else {
            alert('Invalid file type: ' + fileExtension);
        }
    }

}


function uploadFile(file) {

    var formData = new FormData();

    formData.append('file', file);
    // it will take file as name and files[i] is the value passed
    // formData.append('file', files[i]);//this is also correct but not used here

    formData.append('path', path);//path of the page from where this function is called

    // formData.append('path', window.location.pathname);//this is also correct but not used here

    // we also need to send emailaddress
    // formData.append('EmailAddress', reviewEmail);
    formData.append('EmailAddress', EmailAddress);
    formData.append('productCode', productIdOfThisPage);

    var progressBarContainer = document.createElement('div'); // Container for progress bar and file name
    progressBarContainer.className = 'progress-container';

    var fileName = document.createElement('div'); // Display file name
    fileName.className = 'file-name';
    fileName.textContent = file.name;
    //progressBarContainer.appendChild(fileName);

    var progressBar = document.createElement('div'); // Create a new progress bar element
    progressBar.className = 'progress-bar';
    progressBar.id = 'progressBar_' + file.name;

    progressBarContainer.appendChild(progressBar);

    var progressBarsContainer = document.getElementById('progressBarsContainer');

    var newRow = document.createElement('tr'); // Create a new table row
    var newCell = document.createElement('td'); // Create a new table cell
    var newCell2 = document.createElement('td'); // Create a new table cell

    newCell.appendChild(fileName);
    newCell2.appendChild(progressBarContainer);
    newRow.appendChild(newCell);
    newRow.appendChild(newCell2);
    progressBarsContainer.appendChild(newRow);

    var xhr = new XMLHttpRequest();

    xhr.upload.addEventListener('progress', function (event) {
        if (event.lengthComputable) {
            var percent = Math.round((event.loaded / event.total) * 100);
            progressBar.style.width = percent + '%';
            progressBar.innerHTML = percent + '%';
        }
    });

    xhr.addEventListener('load', function (event) {
        var uploadStatus = document.getElementById('uploadStatus');
        uploadStatus.innerHTML = event.target.responseText;
        // Reset the input field of type "file"
        document.getElementById('fileUpload').value = '';

    });

    xhr.open('POST', mainPageHrefOrSrc + 'upload.php', true);
    //we also want to send the href of mainpage from where file is being uploaded and asked the onclick method

    // xhr.setRequestHeader('X-Requested-With', 'XMLHttpRequest');
    // xhr.setRequestHeader('X-File-Name', file.name);

    // // we want to send path also to the upload.php 
    // xhr.setRequestHeader('X-File-Path', file.path);

    xhr.send(formData);
    // we have to sent this variable path also




}


if (document.getElementsByClassName("ratingShow")[0]) {
    var reviewStars = document.getElementsByClassName("ratingShow")[0].innerHTML;
    var starAdding = document.getElementsByClassName("productshortdetail")[0].getElementsByTagName("h4")[0];
    starAdding.getElementsByTagName("button")[0].innerHTML = reviewStars;
    // alert(starAdding.firstChild);

    if (starAdding.getElementsByTagName("br")[0]) {
        var br = starAdding.getElementsByTagName("br")[0];
        starAdding.removeChild(br);
        if (document.getElementsByClassName("productshortdetail")[0].getElementsByTagName("br")[0]) {
            var br = document.getElementsByClassName("productshortdetail")[0].getElementsByTagName("br")[0];
            document.getElementsByClassName("productshortdetail")[0].removeChild(br);
        }

    }


}







function reviewSet() {

    // alert("reviewSet");
    var reviewLines;
    reviewLines = new XMLHttpRequest();

    var productCode = productIdOfThisPage;
    // alert(productCode);

    productCode = JSON.stringify(productCode);
    //  reviewLines.addEventListener('progress', function (event) {
    //   reviewLines.addEventListener('load', function (event) {


    reviewLines.onload = function () {

        if (this.status == 200) {

            // alert(this.responseText); //if we will pass $review then it will also be received

            var UpdateOutput = JSON.parse(this.responseText);


            if (UpdateOutput.totalNumberOfReview > 0) {

                document.getElementsByClassName("ratingPointsOutOfFive")[0].innerHTML = (UpdateOutput.sumOfReview / (UpdateOutput.totalNumberOfReview * 5) * 5).toFixed(1);

                // if output is NaN then set it 0
                if (isNaN(document.getElementsByClassName("ratingPointsOutOfFive")[0].innerHTML)) {
                    document.getElementsByClassName("ratingPointsOutOfFive")[0].innerHTML = 0;
                }


                document.getElementsByClassName("totalNumberOfReview")[0].innerHTML = UpdateOutput.totalNumberOfReview;




                var starcolor = document.getElementsByClassName("ratingPointsOutOfFive")[0].innerHTML;

                //    starcolor=parseInt(starcolor);

                for (var i = 1; i <= starcolor; i++) {
                    document.getElementsByClassName("fa-star")[i - 1].classList.add("checked");
                    document.getElementsByClassName("fa-star")[i + 5 - 1].classList.add("checked");
                }



                document.getElementsByClassName("ratingPointsOutOfFive")[0].style.color = "orange";
                document.getElementsByClassName("ratingPointsOutOfFive")[0].style.fontSize = "30px";
                document.getElementsByClassName("ratingPointsOutOfFive")[0].style.fontWeight = "bold";
                document.getElementsByClassName("ratingPointsOutOfFive")[0].style.textAlign = "center";
                document.getElementsByClassName("ratingPointsOutOfFive")[0].style.marginTop = "20px";
                document.getElementsByClassName("ratingPointsOutOfFive")[0].style.marginBottom = "20px";



                document.getElementsByClassName("totalNumberOfReview")[0].innerHTML = UpdateOutput.totalNumberOfReview;
                document.getElementsByClassName("countOfFiveStar")[0].innerHTML = UpdateOutput.star5;
                document.getElementsByClassName("countOfFourStar")[0].innerHTML = UpdateOutput.star4;
                document.getElementsByClassName("countOfThreeStar")[0].innerHTML = UpdateOutput.star3;
                document.getElementsByClassName("countOfTwoStar")[0].innerHTML = UpdateOutput.star2;
                document.getElementsByClassName("countOfOneStar")[0].innerHTML = UpdateOutput.star1;

                // document.getElementsByClassName("bar-5")[0].style.width=(UpdateOutput.totalNumberOfReview*5)/(UpdateOutput.totalNumberOfReview*5)*100+ '%';//just to test if we setted it right

                document.getElementsByClassName("bar-5")[0].style.width = (UpdateOutput.star5 * 5) / (UpdateOutput.totalNumberOfReview * 5) * 100 + '%';

                document.getElementsByClassName("bar-4")[0].style.width = (UpdateOutput.star4 * 4) / (UpdateOutput.totalNumberOfReview * 5) * 100 + '%';
                document.getElementsByClassName("bar-3")[0].style.width = (UpdateOutput.star3 * 3) / (UpdateOutput.totalNumberOfReview * 5) * 100 + '%';
                document.getElementsByClassName("bar-2")[0].style.width = (UpdateOutput.star2 * 2) / (UpdateOutput.totalNumberOfReview * 5) * 100 + '%';
                document.getElementsByClassName("bar-1")[0].style.width = (UpdateOutput.star1 * 1) / (UpdateOutput.totalNumberOfReview * 5) * 100 + '%';

            }

            var reviews = UpdateOutput.reviews;

            // alert(reviews);//[object Object],[object Object],[object Object]

            var reviewImages = UpdateOutput.reviewImages;
            // alert(reviewImages);//[object Object],[object Object],[object Object],[object Object],[object Object],[object Object],[object Object],[object Object],[object Object],[object Object],[object Object]

            var clonebox = document.getElementsByClassName("reviewBoxes")[0];
            var clone = document.getElementsByClassName("review")[0].cloneNode(true);



            var numOfReviews = reviews.length;


            if (numOfReviews > 0) {
                clonebox.innerHTML = "";
                // alert(clonebox.innerHTML);
            }

            for (var i = 0; i < numOfReviews; i++) {
                reviewfit(i);
            }


            var reviewImagesBoxOfReviewer;
            function reviewfit(i) {




                clone.getElementsByClassName("profilePhoto")[0].getElementsByTagName("img")[0].src = mainPageHrefOrSrc + reviews[i].CustomersProfilePhoto;

                clone.getElementsByClassName("customerName")[0].innerHTML = reviews[i].FirstName;

                clone.getElementsByClassName("emailOfReviewer")[0].innerHTML = reviews[i].EmailAddress;

                clone.getElementsByClassName("reviewDescription")[0].innerHTML = reviews[i].comments;

                // clone.getElementsByClassName("ratingShow")[0].innerHTML = reviews[i].ratingOfStars;


                for (var k = 1; k <= reviews[i].ratingOfStars; k++) {
                    clone.getElementsByClassName("fa-star")[k - 1].classList.add("checked");
                }


                reviewImagesBoxOfReviewer = clone.getElementsByClassName("absoluteAllReviewImage")[0];
                var reviewBoxesClone = reviewImagesBoxOfReviewer.firstElementChild;


                // if(reviewImages.EmailAddress== reviews[i].EmailAddress)



                // for loop for images

                if (reviewImages.length > 0) {
                    reviewImagesBoxOfReviewer.innerHTML = "";
                }

                for (var j = 0; j < reviewImages.length; j++) {
                    if (reviewImages[j].EmailAddress == reviews[i].EmailAddress) {
                        reviewBoxesClone.getElementsByTagName("img")[0].src = mainPageHrefOrSrc + reviewImages[j].img_url;

                        reviewImagesBoxOfReviewer.innerHTML += reviewBoxesClone.outerHTML;

                    }

                }
                if (reviewImagesBoxOfReviewer.firstElementChild) {
                    // alert(reviewImagesBoxOfReviewer.firstElementChild);
                }
                else {
                    reviewImagesBoxOfReviewer.remove();
                    // alert("no child");

                }



                clonebox.innerHTML += clone.outerHTML;



            }


            imgopener();



        };


        // reviewLines.open("POST", "../../../../../reviewOfProduct.php?productCode=" + productCode);
        // reviewLines.send();

    }

    // reviewLines.open("POST", mainPageHrefOrSrc+reviewOfProduct.php');//works
    reviewLines.open("POST", mainPageHrefOrSrc + 'reviewOfProduct.php');

    reviewLines.setRequestHeader("Content-type", "application/x-www-form-urlencoded");//neccessary to send some value to php file otherwise it will not take that anything is being send

    reviewLines.send("productCode=" + productCode);




}

// setTimeout(reviewSet,1000);
reviewSet();

