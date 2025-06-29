
var EmailAddress;
EmailAddress = sessionStorage.getItem("EmailAddress");


// alert(EmailAddress);
// alert
// alert
// alert
// alert
// alert

if(EmailAddress === null || EmailAddress ===undefined){
// we can also get it from local storage
EmailAddress = localStorage.getItem("EmailAddress");
// alert(EmailAddress);
}


// works but it creates reload and irritation
// window.onbeforeunload = function() {
//     return "Are you sure you want to leave?";
// };


var modeOfPayment;

var generatedRandomOrderNum;
// alert(generatedRandomOrderNum);

function decidedTogeneratedRandomOrderNum() {

    var RegisteredOrderNum = new XMLHttpRequest();

    RegisteredOrderNum.onload = function () {
        if (this.status == 200) {

            var arrOfAllPassed = JSON.parse(this.responseText);
            arrOfAllOrderNum = arrOfAllPassed[0];

            const arrOfAllOrderNumLength = arrOfAllOrderNum.length;
            // alert(arrOfAllOrderNumLength);

            while (arrOfAllOrderNum.length != arrOfAllOrderNumLength + 1) {

                var orderNumInt = Math.floor(Math.random() * 2147483647) + 1;

                if (arrOfAllOrderNum.indexOf(orderNumInt) === -1) {

                    // arrOfAllOrderNum.push(orderNumInt);

                    // alert(orderNumInt);//4572286975475936
                    // alert(typeof(orderNumInt));//number

                    generatedRandomOrderNum = orderNumInt;

                    return orderNumInt;


                }

            }


        }

        else {
            document.getElementById("buyMethodOutput").style.display = "flex";
            document.getElementById("buyMethodOutput").innerHTML = "Unable to get Order Number";

            setTimeout(
                function () {
                    document.getElementById("buyMethodOutput").style.display = "none";
                }, 3000
            );

        }
    }

    RegisteredOrderNum.open("GET", "getAlreadyRegisteredOrderNum.php");
    RegisteredOrderNum.send();

}



decidedTogeneratedRandomOrderNum();



var productNumber;//productCode
var totalCostvalue;
// var quantityNumber = 1;//not be helpful in case of cart where list of products are present
var sizeSelected;
var productPrice;




var param = new URLSearchParams(window.location.search);
// alert(param);

// if(document.getElementById("cartMethod") === undefined || document.getElementById("cartMethod") === null)
// alert(document.getElementById("cartMethod"));//null


if (param != "") {
    // alert("inside param");

    productNumber = param.get('productID');
    var productName = param.get('productName');
    productPrice = param.get('priceOfThisProduct');
    var mainImagOfThisProduct = param.get('mainImagOfThisProduct');
    // alert(mainImagOfThisProduct);

    var mainImagOfThisProduct = String(mainImagOfThisProduct);
                mainImagOfThisProduct= mainImagOfThisProduct.substring
                    (mainImagOfThisProduct.indexOf("product/"), mainImagOfThisProduct.length);
                    // alert(mainImagOfThisProduct);

    if (param.get('sizeSelected')) {
        sizeSelected = param.get('sizeSelected');
        // product.getElementsByClassName("productSize")[0].innerHTML += "<br>Size : " + sizeSelected;
        // product.getElementsByClassName("productSize")[0].innerHTML = sizeSelected;

        // http://localhost:3000/cart.html?productID=WWAW1&productName=%20Flowered%20Dial%20Megnet%20Watch&priceOfThisProduct=264&mainImagOfThisProduct=http://localhost:3000/product/women/women%20accessories/watch/Flowered%20Dial%20Megnet%20Watch/colors%20option/ssr1i_512.png

    }
    else {
        sizeSelected = "free size";
        // product.getElementsByClassName("productSize")[0].innerHTML = sizeSelected;
    }



    if (document.getElementById("cartMethod") === undefined || document.getElementById("cartMethod") === null) {

        var product = document.getElementsByClassName("productsList")[0].firstElementChild;


        // product.firstElementChild.firstElementChild.firstElementChild.src = mainImagOfThisProduct;


        product.firstElementChild.firstElementChild.getElementsByClassName("buyCart")[0].src = mainImagOfThisProduct;


        product.getElementsByClassName("productCode")[0].innerHTML = productNumber;


        // alert(mainImagOfThisProduct);

        product.getElementsByClassName("productName")[0].innerHTML = productName;



        // alert(productName);
        if (param.get('sizeSelected')) {
            sizeSelected = param.get('sizeSelected');
            // product.getElementsByClassName("productSize")[0].innerHTML += "<br>Size : " + sizeSelected;
            product.getElementsByClassName("productSize")[0].innerHTML = sizeSelected;

            // http://localhost:3000/buymethods.html?productID=WWAW1&productName=%20Flowered%20Dial%20Megnet%20Watch&priceOfThisProduct=264&mainImagOfThisProduct=http://localhost:3000/product/women/women%20accessories/watch/Flowered%20Dial%20Megnet%20Watch/colors%20option/ssr1i_512.png

        }
        else {
            sizeSelected = "free size";
            product.getElementsByClassName("productSize")[0].innerHTML = sizeSelected;
        }

        product.firstElementChild.lastElementChild.firstElementChild.nextElementSibling.firstElementChild.innerHTML = productPrice;

        product.firstElementChild.lastElementChild.firstElementChild.nextElementSibling.nextElementSibling.firstElementChild.src = mainImagOfThisProduct;

        // product.firstElementChild.lastElementChild.lastElementChild.previousElementSibling.innerHTML=productPrice;


        // document.getElementsByClassName("productsList")[0].appendChild(product);


        product.getElementsByClassName("priceOfEach")[0].innerHTML = productPrice;


        calculateTotal();//to update after inserting the product.




        allCartBuy();

    }

}
else {
    console.log("Viewing the product");
    // alert("Viewing the product");
}




var placeOrder = document.getElementsByClassName("place-order");
// alert(placeOrder.length);

var payoutmethods = document.getElementsByClassName("payoutmethods"); //since in cart , we are not updating all these lengths hence it will not be affected
// alert(payoutmethods.length);

for (var i = 0; i < placeOrder.length; i++) {
    // document.getElementsByClassName("payoutmethods").style.display="none";
    var payshow = payoutmethods[i];
    placeOrder[i].addEventListener("click", function () {
        // we need to check if there is atleast an ordered product

        // alert(this.className);
        // placeOrder.style.display="inline";
        // document.getElementsByClassName("payoutmethods")[i].style.display="block";//here i will not be passed hence not works
        payshow.style.display = "block";
        this.style.display = "none";

    })

}






function trackLocation() {
    document.getElementById("demogeolocation").style.display = "flex";
    if (navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(showPosition);//calls showPosition() function .
    } else {
        // document.getElementById("demogeolocation").innerHTML = "Geolocation is not supported by this browser.";
        document.getElementById("demogeolocation").innerHTML = "Geolocation is not supported by this browser."

    }

}


function showPosition(position) {
    // document.getElementById("demogeolocation").innerHTML =
    //     "Latitude: " + position.coords.latitude + "<br>" +
    //     "Longitude: " + position.coords.longitude;


    document.getElementById("demogeolocation").innerHTML = `
        Latitude:   ${position.coords.latitude}<br>
        Longitude:  ${position.coords.longitude}`
    document.getElementById("geolocationLatitude").innerHTML = position.coords.latitude;
    document.getElementById("geolocationLongitude").innerHTML = position.coords.longitude;

}



var checkoutclick = document.getElementsByClassName("check-out");
// creating an event Eventlistner on radio checked button onchange

for (var i = 0; i < checkoutclick.length; i++) {

    checkoutclick[i].addEventListener("click", function () {

        // this.style.display="flex";

        document.getElementById("thisOrderedDetails").style.display = "none";

        document.getElementById("payNow").style.display = "none";

        if (document.getElementById("upiScanner")) {

            document.getElementById("upiScanner").style.display = "none";


        }

        // we need to undo the changes that are done here



        if (document.getElementById("card").checked) {

            modeOfPayment = "card";

            // this.style.display="none";//not made it capable of changing the choice


            // alert("card");
            // window.open("payment.html","payment","_blank");
            // window.open("payment.html","payment","_self");

            document.getElementById("thisOrderedDetails").style.display = "block";

            document.getElementById("trackLocation").click();

            // window.location.href = "payment.html"; //it is helpful in opening the payment app in same tab

            // we will put razorpay here

        }


        else if (document.getElementById("cash").checked) {

            modeOfPayment = "cash";

            // alert("cash");
            // this.style.display="none";

            document.getElementById("trackLocation").click();

            document.getElementById("thisOrderedDetails").style.display = "block";


        }

        else if (document.getElementById("upi").checked) {

            modeOfPayment = "upi";

            document.getElementById("trackLocation").click();

            // this.style.display="none";

            var div = document.createElement("div");
            // adding class upiScanner
            // div.className="upiScanner";
            // adding id upiScanner
            div.id = "upiScanner";


            // document.getElementById("thisOrderedDetails").getElementsByClassName("form-group")[0].appendChild(document.createElement("div"));

            document.getElementById("thisOrderedDetails").getElementsByClassName("form-group")[0].appendChild(div);

            document.getElementById("thisOrderedDetails").style.display = "block";


            var div = document.getElementById("thisOrderedDetails").getElementsByClassName("form-group")[0].lastChild;
            // div.innerHTML = upipay;

            // div.innerHTML = `<img src="UPI ID.jpg" style="height:90vh;width:100vw;max-width:428px;position:fixed;top: 50%;left: 50%;transform: translate(-50%, -50%);z-index:3" ></img>`;

            div.innerHTML = `<img src="UPI ID.jpg" style="height:90vh;width:100vw;max-width:428px;" ></img>`;//OK but how to detect if amount is received , hence we are commenting it.//uncomment later

            // we will put razorpay here.


        }
        else {
            // alert("please select one method");
            // document.body.appendChild(document.createElement("div"));
            // var div = document.body.lastChild;

            document.getElementById("buyMethodOutput").style.display = "flex";
            document.getElementById("buyMethodOutput").innerHTML = "Please select one payment method";

            setTimeout(
                function () {
                    document.getElementById("buyMethodOutput").style.display = "none";
                }, 3000
            );

        }
    });
}



var firstname;
var lastname;
var email;
var phone;
var address;
var latitude;
var longitude;
var city;
var state;
var zip;
var country;

var orderDate;
orderDate = new Date().toISOString().slice(0, 10);
orderDate = orderDate.split('-').join('/');

//we need to track the value of allinput fields in the form
function getValues() {
    //get the values of all input fields in the form


    firstname = document.orderDetails.firstname.value;
    // alert(firstname);
    lastname = document.orderDetails.lastname.value;
    // alert(lastname);
    email = document.orderDetails.email.value;
    // alert(email);
    phone = document.orderDetails.phone.value;
    // alert(phone);
    address = document.orderDetails.address.value;
    // alert(address);
    latitude = document.getElementById("geolocationLatitude").innerHTML;
    longitude = document.getElementById("geolocationLongitude").innerHTML;

    city = document.orderDetails.city.value;
    // alert(city);
    state = document.orderDetails.state.value;
    // alert(state);
    zip = document.orderDetails.zip.value;
    // alert(zip);

    country = document.orderDetails.country.value;
    // alert(country);

    orderDate = new Date().toISOString().slice(0, 10);
    // format like yyyy-mm-dd



    // alert(orderDate);
    // we want in format of dd/mm/year

    // var orderDate = orderDate.split('-').reverse().join('/');//it will create error when inserting value into mysql
    // alert(orderDate);
    orderDate = orderDate.split('-').join('/');
    // INSERT INTO orders(orderNumber,orderDate,customerNumber) VALUES(24,'2025/03/09',1856176940);//works


}




var updateActive = 0;

var updateAccountDetails = document.getElementById('UpdateAccount');
updateAccountDetails.addEventListener('click', function () {
    getValues();
    if (firstname == "" || firstname === undefined || lastname == ""
        || lastname === undefined || email == "" || email === undefined ||
        phone == "" || phone === undefined || address == "" ||
        address === undefined || city == "" || city === undefined ||
        state == "" || state === undefined || zip == "" ||
        zip === undefined || country == "" || country === undefined) {

        alert("Please fill all the fields");
    }
    else {

        if (updateActive == 0) {

            updateActive = 1;
            alert("On checkout your account details will be permanently updated. If you don't want to update the details and keep this details only for this order then kindly Click \'Not update details\'");
            updateAccountDetails.value = "Not update details";

            // updateAccountDetails.style.display = "none";
        }
        else {
            // updateAccountDetails.style.display = "block";
            updateActive = 0;
            alert("Your filled details are only for this order and it will not be updated in your account.You can checkout. ")
            updateAccountDetails.value = 'Update Account Details';
        }


    }


});







var checkoutFinal = document.getElementById("checkOutFinal");

checkoutFinal.addEventListener("click", function () {

    getValues();

    if (firstname == "" || firstname === undefined || lastname == ""
        || lastname === undefined || email == "" || email === undefined ||
        phone == "" || phone === undefined || address == "" ||
        address === undefined || city == "" || city === undefined ||
        state == "" || state === undefined || zip == "" ||
        zip === undefined || country == "" || country === undefined) {
        // alert("Please fill in all fields");
        document.getElementById("buyMethodOutput").style.display = "flex";
        document.getElementById("buyMethodOutput").innerHTML = "Please fill in all fields";
        setTimeout(
            function () {
                document.getElementById("buyMethodOutput").style.display = "none";
            }, 3000
        );
        return false;
    }
    else {

        if (email == EmailAddress) {
            // alert("Thank you for your order");
            // alert("Your order has been placed");

            // let's write some more
            var newOrderNumberDecided = generatedRandomOrderNum;

            // alert("newOrderNumberDecided:"+newOrderNumberDecided);

            // var useOrderNumber = new XMLHttpRequest();

            if (document.getElementById("cartMethod") === undefined || document.getElementById("cartMethod") === null) {

                var mainImagOfThisProductColor = String(mainImagOfThisProduct);
                mainImagOfThisProductColor = mainImagOfThisProductColor.substring
                    (mainImagOfThisProductColor.indexOf("product/"), mainImagOfThisProductColor.length);

                var quantityNumber = document.getElementsByClassName("quantity-number")[0].value;
                // alert(quantityNumber);

                var productPrice = document.getElementsByClassName("priceOfEach")[0].innerHTML;

                var useOrderNumber = new XMLHttpRequest();

                var dbparam = {

                    orderNumber: newOrderNumberDecided,//
                    productNumber: productNumber,//
                    quantity: quantityNumber,//
                    size: sizeSelected,//
                    productPrice: productPrice,//
                    totalCost: totalCostvalue,//
                    orderDate: orderDate,//
                    firstname: firstname,
                    lastname: lastname,
                    email: email,//
                    phone: phone,
                    address: address,
                    city: city,
                    state: state,
                    zip: zip,
                    country: country,
                    latitude: latitude,
                    longitude: longitude,
                    updateActive: updateActive,
                    buy: 1,//
                    modeOfPayment: modeOfPayment,
                    colorMainImage: mainImagOfThisProductColor//

                };

                dbparam = JSON.stringify(dbparam);

               
                useOrderNumber.onload = function () {
                    // useOrderNumber.onfocus = function () {
    
                    // document.getElementById("buyMethodOutput").style.display = "flex";
                    // document.getElementById("buyMethodOutput").innerHTML = this.responseText;
    
    
    
    
                    if (this.status == 200) {
    
                        // alert(this.responseText);
    
                        if (this.responseText == "You successfully ordered this product") {
    
                            // submitButtonOutput();
    
                            document.getElementById("buyMethodOutput").style.display = "flex";
    
    
                            if (document.getElementById("upi").checked || document.getElementById("card").checked) {
    
    
    
                                checkoutFinal.style.display = "none";
                                updateAccountDetails.style.display = "none";
    
                                document.getElementById("buyMethodOutput").innerHTML = "Thank you for your order but your order will be delivered only once we receive the payment, if you want you can continue to pay or use cash on delivery";
                                setTimeout(
                                    function () {
                                        document.getElementById("buyMethodOutput").style.display = "none";
                                        alert("Thank you for your order but your order will be delivered only once we receive the payment, if you want you can continue to pay or use cash on delivery");
                                    }, 2000
                                );
    
    
    
                                document.getElementById("payNow").style.display = "flex";


                                var jsConfetti = new JSConfetti();

                                jsConfetti.addConfetti();
                            
                                jsConfetti.addConfetti({
                                    emojis: ['🌈', '⚡️', '💥', '✨', '💫', '🌸'],
                                })
                            
                            
                                // Customize confetti colors:
                                jsConfetti.addConfetti({
                                    confettiColors: [
                                        'blue', 'red', 'yellow',
                                    ],
                                })
    
    
    
                            }
                            else {
                                document.getElementById("payNow").style.display = "none";
                                document.getElementById("buyMethodOutput").innerHTML = "You successfully ordered this product";
                                setTimeout(
                                    function () {
                                        document.getElementById("buyMethodOutput").style.display = "none";
                                    }, 3000
                                );


                                var jsConfetti = new JSConfetti();

                                jsConfetti.addConfetti();
                            
                                jsConfetti.addConfetti({
                                    emojis: ['🌈', '⚡️', '💥', '✨', '💫', '🌸'],
                                })
                            
                            
                                // Customize confetti colors:
                                jsConfetti.addConfetti({
                                    confettiColors: [
                                        'blue', 'red', 'yellow',
                                    ],
                                })


                                document.body.appendChild(document.createElement("div"));

                                var div = document.body.lastChild;
    
                                div.innerHTML = '<a href="index.php"><video src="files acc/thanks for shopping.mp4" style="max-width: 95vw;max-height:50vh;position:fixed;left: 50%;top: 50%;transform: translate(-50%, -50%);" autoplay loop ></video></a>';
    
    
    
    
                            }
    
    
                        }
                        else {
    
                            document.getElementById("buyMethodOutput").innerHTML = this.responseText;
                            return;
    
                        }
    
                    }
    
                    setTimeout(
                        function () {
                            document.getElementById("buyMethodOutput").style.display = "none";
                        }, 3000
                    );
                }



                useOrderNumber.open("POST", "orders.php");

                useOrderNumber.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

                useOrderNumber.send("dbparam=" + dbparam);


            }
            else {

                // now we have to pass the list of products with productCode, quantity, price, and totalCost
                //    we will run for loop for all cart list



                var itemcount = document.getElementsByClassName("itemcount");

                // alert(itemcount.length);

                // var dbparam = "{";

                for (var i = 0; i < itemcount.length; i++) {
                // for (var i = 0; i < 1; i++) {

                    // var useOrderNumber = new XMLHttpRequest();

                    var productCode = document.getElementsByClassName("productCode")[i].innerHTML;
                    // we also want to send the ordernumber
                    var orderNumberCart = document.getElementsByClassName("orderNumber")[i].innerHTML;

                    var quantity = document.getElementsByClassName("quantity-number")[i].value;

                    var productSize = document.getElementsByClassName("productSize")[i].innerHTML;

                    var productPrice = document.getElementsByClassName("priceOfEach")[i].innerHTML;

                    var totalCost = document.getElementsByClassName("quantity-total")[i].innerHTML;


                    // alert("productCode: "+productCode+" quantity: "+quantity+" productSize: "+ productSize+" productPrice: "+productPrice+" totalCost: "+totalCost);

                    // productCode: undefined quantity: 1 productSize: XL productPrice: 495 totalCost: 495


                    var mainImagOfThisProductColor = document.getElementsByClassName("buyCart")[i].src;

                    mainImagOfThisProductColor = String(mainImagOfThisProductColor);
                    mainImagOfThisProductColor = mainImagOfThisProductColor.substring
                        (mainImagOfThisProductColor.indexOf("product/"), mainImagOfThisProductColor.length);


                    var useOrderNumber = new XMLHttpRequest();

                    var dbparamCart = {

                        orderNumber: newOrderNumberDecided,//
                        orderNumberCart: orderNumberCart,//we need this to remove it from both orders and order_details so that not dublicacy remains once it is transfered to orderedbuycart table

                        productNumber: productCode,//
                        quantity: quantity,//
                        size: productSize,//
                        productPrice: productPrice,//
                        totalCost: totalCost,//
                        orderDate: orderDate,//
                        firstname: firstname,
                        lastname: lastname,
                        email: email,
                        phone: phone,
                        address: address,
                        city: city,
                        state: state,
                        zip: zip,
                        country: country,
                        latitude: latitude,
                        longitude: longitude,
                        updateActive: updateActive,
                        buy: 1,//
                        cartOrder: 1,//
                        modeOfPayment: modeOfPayment,//
                        colorMainImage: mainImagOfThisProductColor//


                    };


                    dbparamCart = JSON.stringify(dbparamCart);
                    // alert(dbparamCart);

                    useOrderNumber.open("POST", "orders.php");

                    useOrderNumber.onload = function () {
                        
        
        
                        if (this.status == 200) {
        
                            // alert(this.responseText);
        
                            if (this.responseText == "You successfully ordered this product") {
        
                                // submitButtonOutput();
        
                                document.getElementById("buyMethodOutput").style.display = "flex";
        
        
                                if (document.getElementById("upi").checked || document.getElementById("card").checked) {
        
        
        
                                    checkoutFinal.style.display = "none";
                                    updateAccountDetails.style.display = "none";
        
                                    document.getElementById("buyMethodOutput").innerHTML = "Thank you for your order but your order will be delivered only once we receive the payment, if you want you can continue to pay or use cash on delivery";
                                    setTimeout(
                                        function () {
                                            document.getElementById("buyMethodOutput").style.display = "none";
                                            alert("Thank you for your order but your order will be delivered only once we receive the payment, if you want you can continue to pay or use cash on delivery");
                                        }, 2000
                                    );
        
        
        
                                    document.getElementById("payNow").style.display = "flex";
    
    
                                    var jsConfetti = new JSConfetti();
    
                                    jsConfetti.addConfetti();
                                
                                    jsConfetti.addConfetti({
                                        emojis: ['🌈', '⚡️', '💥', '✨', '💫', '🌸'],
                                    })
                                
                                
                                    // Customize confetti colors:
                                    jsConfetti.addConfetti({
                                        confettiColors: [
                                            'blue', 'red', 'yellow',
                                        ],
                                    })
        
        
        
                                }
                                else {
                                    document.getElementById("payNow").style.display = "none";
                                    document.getElementById("buyMethodOutput").innerHTML = "You successfully ordered this product";
                                    setTimeout(
                                        function () {
                                            document.getElementById("buyMethodOutput").style.display = "none";
                                        }, 3000
                                    );
    
    
                                    var jsConfetti = new JSConfetti();
    
                                    jsConfetti.addConfetti();
                                
                                    jsConfetti.addConfetti({
                                        emojis: ['🌈', '⚡️', '💥', '✨', '💫', '🌸'],
                                    })
                                
                                
                                    // Customize confetti colors:
                                    jsConfetti.addConfetti({
                                        confettiColors: [
                                            'blue', 'red', 'yellow',
                                        ],
                                    })
    
    
                                    document.body.appendChild(document.createElement("div"));
    
                                    var div = document.body.lastChild;
        
                                    div.innerHTML = '<a href="index.php"><video src="files acc/thanks for shopping.mp4" style="max-width: 95vw;max-height:50vh;position:fixed;left: 50%;top: 50%;transform: translate(-50%, -50%);" autoplay loop ></video></a>';
        
        
        
        
                                }
        
        
                            }
                            else {
        
                                document.getElementById("buyMethodOutput").innerHTML = this.responseText;
                                return;
        
                            }
        
                        }
        
                        setTimeout(
                            function () {
                                document.getElementById("buyMethodOutput").style.display = "none";
                            }, 3000
                        );
                    }



                    useOrderNumber.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

                    useOrderNumber.send("dbparamCart=" + dbparamCart);


                }



            }




        }
        else {
            // alert("Invalid Email");
            document.getElementById("buyMethodOutput").style.display = "flex";
            document.getElementById("buyMethodOutput").innerHTML = "Invalid Email";
            setTimeout(
                function () {
                    document.getElementById("buyMethodOutput").style.display = "none";
                }, 3000
            );


            return false;
        }



    }




});






function upadatequantityNumber(element, price, isIncreasing) {


    if (isIncreasing) { //this isIncresing is true in quantityplus
        var quantityInput = element.previousElementSibling;
        var quantityNumberOfThis = quantityInput.value;//1
        quantityNumberOfThis = parseInt(quantityNumberOfThis) + 1;
    }

    else { //executeds in quantityminus
        var quantityInput = element.nextElementSibling;
        var quantityNumberOfThis = quantityInput.value;
        if (quantityNumberOfThis > 1) {

            // alert(quantityInput.value);

            quantityNumberOfThis = parseInt(quantityNumberOfThis) - 1;

        }
    }



    quantityInput.value = quantityNumberOfThis; //works

  
    var quantityTotalPrice = element.parentElement.parentElement.getElementsByClassName("quantity-total")[0];//quantity-total

    // alert(quantityTotalPrice.className);//quantity-total
    // alert(quantityTotalPrice.innerHTML);//quantity-total

    // quantityTotalPrice.innerText = quantityNumber * price;
    quantityTotalPrice.innerHTML = quantityNumberOfThis * price;

    // alert(quantityTotal);

    calculateTotal();

}




function calculateTotal() {
    // var quantityTotal = getInputvalue('quantity') * 1219;
    // var quantityTotal = getInputvalue('quantity') * 59;

    var totalCost = document.getElementsByClassName("quantity-total");
    totalCostvalue = Number(0);
    for (var i = 0; i < totalCost.length; i++) {
        totalCostvalue += Number(totalCost[i].innerText);
    }

    // update on the html 
    document.getElementsByClassName('sub-total')[0].innerText = totalCostvalue;
    document.getElementsByClassName('tax-amount')[0].innerText = 0;
    document.getElementsByClassName('total-price')[0].innerText = totalCostvalue;

}














function allCartBuy() {

    if (document.getElementById("cartMethod") !== null) {

        //   this also works better
        if (param != "") {
            // alert("inside param");
            var addToCartSave = document.getElementsByClassName("addToCart")[0];

            addToCartSave.addEventListener("click", function () {
                // alert("inside add to cart");//it works here

                var quantityNumber = document.getElementsByClassName("quantity-number")[0].value;
                var productNumber = document.getElementsByClassName("productCode")[0].innerHTML;
                var quantityNumber = document.getElementsByClassName("quantity-number")[0].value;
                var sizeSelected = document.getElementsByClassName("productSize")[0].innerHTML;
                var productPrice = document.getElementsByClassName("priceOfEach")[0].innerHTML;
                var totalCostvalue = document.getElementsByClassName("quantity-total")[0].innerHTML;

                var mainImagOfThisProductColor = String(mainImagOfThisProduct);//http://localhost:3000/product/women/ethnic%20wear/kurta%20sets/Pakistani%20Suit%20%20Women%20Kurta%20Pair/colors%20option/green/main.png
                // be have to take substring from product to last 
                mainImagOfThisProductColor = mainImagOfThisProductColor.substring
                    (mainImagOfThisProductColor.indexOf("product/"), mainImagOfThisProductColor.length);//error
                // we want to remove http://localhost:3000 from  mainImagOfThisProduct
                // var mainImagOfThisProduct=mainImagOfThisProduct.replace("http://localhost:3000/","");



                var newOrderNumberDecided = generatedRandomOrderNum;
                var useOrderNumber = new XMLHttpRequest();
                
                var cartParam = {
                    orderNumber: newOrderNumberDecided,//
                    productNumber: productNumber,//
                    quantity: quantityNumber,//
                    size: sizeSelected,//
                    productPrice: productPrice,//
                    totalCost: totalCostvalue,//
                    email: EmailAddress,//
                    colorMainImage: mainImagOfThisProductColor,//              
                    buy: 0,//

                }

                // onload of useOrderNumber
                useOrderNumber.onload = function () {
                    if (this.status == 200) {
                        // this responsetext
                        // var response = this.responseText;
                        // alert(response);
                        // alert("Product Added to your cart");
                        // console.log("Order Added");
                        // addToCartSave.innerHTML="Remove";
                        window.location.href = "http://localhost:3000/cart.html";

                    }
                }

                cartParam = JSON.stringify(cartParam);

                useOrderNumber.open("POST", "orders.php");

                useOrderNumber.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

                useOrderNumber.send("cartParam=" + cartParam);



            });
        }
        else {
            // alert("no param");
        }
    }


    var removeItem = document.getElementsByClassName("remove-item");//at start it is one.
    // var removeItemLength = removeItem.length;
    // alert(removeItemLength);

    for (var i = 0; i < removeItem.length; i++) {
        // for (var i = 1; i < removeItem.length; i++) {

        removeItem[i].addEventListener("click", function () {
            alert("this product will be removed from your cart");

            this.parentElement.parentElement.parentElement.parentElement.remove();

            calculateTotal();

            // placeOrder[0].style.display="none";//it would be not good practice because we would not be able to use this code in cart.

            if (document.getElementsByClassName("itemcount").length < 1) {
                placeOrder[0].style.display = "none";
            }


            Undo();
        });

    }


    var undo = document.getElementsByClassName("undo");

    function Undo() {

        for (var i = 0; i < undo.length; i++) {
            undo[i].style.display = "block";
            undo[i].addEventListener("click", function () {

                //we just need to refresh the page
                location.reload();
            }
            );
        }
    }



    var quantityplus = document.getElementsByClassName('quantity-plus');//undefined as class has ; and it will not take it as class , it will take quantity-plus ; btn as class 
    
    for (var i = 0; i < quantityplus.length; i++) {
        // priceSet = Number(priceOfOne[i].innerText);
        // alert(priceSet);//600
        quantityplus[i].addEventListener('click', function () {

            // alert("inside");
            //    var priceSet =priceOfOne[i].innerHTML;//not works
            var priceSet = this.parentElement.parentElement.getElementsByClassName('priceOfEach')[0].innerText;//works

          
            upadatequantityNumber(this, priceSet, true);
        });

    }


    var quantityminus = document.getElementsByClassName('quantity-minus');
    // alert(quantityminus.length);//it will give only one at start

    for (var i = 0; i < quantityminus.length; i++) {

        quantityminus[i].addEventListener('click', function () {

            var priceSet = this.parentElement.parentElement.getElementsByClassName('priceOfEach')[0].innerText;


            upadatequantityNumber(this, priceSet, false);
            // upadatequantityNumber('quantity', priceSet, 59, false);
        });
    }

   

    var thisCartImage = document.getElementsByClassName("itemcount");

    for (var i = 0; i < thisCartImage.length; i++) {
        var itemImage = thisCartImage[i].getElementsByTagName("img");
        
        for (var j = 0; j < itemImage.length; j++) {
            itemImage[j].addEventListener("click", function () {
    
                var fileSrc = this.getAttribute("src");//product/women/ethnic wear/lahenga/Solid Semi Stitched Lehenga Choli/colors option/rama/Screenshot 2025-02-10 214918.png
    
                // alert(fileSrc);
                // we want to send this to getThisFileDetail.php
    
                fileSrc = JSON.stringify(fileSrc);
    
                var getProductCode = new XMLHttpRequest();
    
    
                getProductCode.onload = function () {
    
                    // alert(this.responseText);//{"productCode":{"product_Code":"WEWL1"}}////{"product_Code":"WEWL1"}
    
                    if (getProductCode.status >= 200 && getProductCode.status < 300) {
    
                        var ProductCodeOfThisFile = JSON.parse(this.responseText);
    
                        // alert(ProductCodeOfThisFile.productCode.product_Code);//in {"productCode":{"product_Code":"WEWL1"}}
    
                        ProductCodeOfThisFile = ProductCodeOfThisFile[0].product_Code;//in //{"product_Code":"WEWL1"}
    
                        // alert(ProductCodeOfThisFile);//WEWL1
    
                        // if (ProductCodeOfThisFile !== "") {
                        if (ProductCodeOfThisFile != null) {
                            // alert(ProductCodeOfThisFile);
                            navigateProductClick(ProductCodeOfThisFile);
    
                        }
                        else {
                            alert("Product not found");
                        }
    
                    }
                    else {
                        alert("Error");
                    }
                }
    
    
    
    
                getProductCode.open("POST", "getThisFileDetail.php");
                getProductCode.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
                getProductCode.send("fileSrc=" + fileSrc);
    
            });
        }
    }
    

}
// );


setTimeout(function () {
    // window.addEventListener("load", allCartBuy);
}, 2000);


// I want to call this allCartBuy only when param != null
if (param != null) {
    // allCartBuy();
    // window.addEventListener("load", allCartBuy);
}






