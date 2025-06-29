

function unloadAlert() {

    // alert("Please save it to update your cart");
    // e.preventDefault();
    // e.returnValue = '';
    // e.returnValue = true;
    window.scrollTo(0, document.body.scrollHeight);

}


var EmailAddress;
EmailAddress = sessionStorage.getItem("EmailAddress");
// alert(EmailAddress);

if(EmailAddress === null || EmailAddress ===undefined){
// we can also get it from local storage
EmailAddress = localStorage.getItem("EmailAddress");
// alert(EmailAddress);
}

var cart = document.getElementsByClassName("productsList")[0].firstElementChild;

if (param != "") {
    

    var cloneCart = cart.cloneNode(true);
    // this will not take script functions from another file ,


    cloneCart.firstElementChild.firstElementChild.firstElementChild.src = mainImagOfThisProduct;
    // alert(mainImagOfThisProduct);

    cloneCart.firstElementChild.firstElementChild.lastElementChild.innerHTML = productName;
    // alert(productName);

    cloneCart.getElementsByClassName("productCode")[0].innerHTML = productNumber;

    cloneCart.firstElementChild.lastElementChild.firstElementChild.nextElementSibling.firstElementChild.innerHTML = productPrice;

    cloneCart.firstElementChild.lastElementChild.firstElementChild.nextElementSibling.nextElementSibling.firstElementChild.src = mainImagOfThisProduct;

    if (param.get('sizeSelected')) {
        sizeSelected = param.get('sizeSelected');
        // product.getElementsByClassName("productSize")[0].innerHTML += "<br>Size : " + sizeSelected;
        cloneCart.getElementsByClassName("productSize")[0].innerHTML = sizeSelected;

    }
    else {
        sizeSelected = "free size";
        cloneCart.getElementsByClassName("productSize")[0].innerHTML = sizeSelected;

    }


    // clone.getElementsByClassName("productSize")[0].innerHTML += "<br>Size : " + sizeSelected;

    // clone.getElementsByClassName("priceOfEach")[0].innerHTML += "<br>per:&#8377;" + productPrice;

    cloneCart.getElementsByClassName("priceOfEach")[0].innerHTML += productPrice;

    // we can put sizes

    cloneCart.getElementsByClassName("remove-item ")[0].classList.add("addToCart");

    // cloneCart.getElementsByClassName("remove-item ")[0].innerHTML = "Add to Cart";

    // cloneCart.getElementsByClassName("remove-item ")[0].classList.remove("remove-item");

    var addToCartSave = cloneCart.getElementsByClassName("addToCart")[0];

    
    // // innerHTML is Add
    addToCartSave.innerHTML = "Add to Cart";
    addToCartSave.classList.remove("remove-item");

    // clone.firstElementChild.lastElementChild.lastElementChild.previousElementSibling.innerHTML=productPrice;

    document.getElementsByClassName("productsList")[0].innerHTML = "";
    document.getElementsByClassName("productsList")[0].appendChild(cloneCart);

    calculateTotal();//to update after inserting the product.
    // activeEvery();

}
else {

    console.log("Viewing the cart");
    // alert("Viewing the cart");

}


var orderedProductsArray = [];

function cartProducts() {
    var email = { email: EmailAddress }

    email = JSON.stringify(email);

    // alert(email);

    var CartProducts = new XMLHttpRequest();

    CartProducts.onload = function () {

        

        if (CartProducts.status >= 200 && CartProducts.status < 300) {

            if (this.responseText == "[]" && param !="") {

                document.getElementById("buyMethodOutput").style.display = "flex";
                document.getElementById("buyMethodOutput").innerHTML = "Nothing in cart items, Click 'Add to Cart 'to put this product into your cart ";
                document.getElementById("buyMethodOutput").style.color = "red";
                document.getElementById("buyMethodOutput").style.fontWeight = "bold";

                // document.getElementsByClassName("productsList")[0].innerHTML="";

            }
            else if(this.responseText == "[]" && param ==""){
                document.getElementById("buyMethodOutput").style.display = "flex";
                document.getElementById("buyMethodOutput").innerHTML = "Sorry, we could not find any cart items";
                document.getElementById("buyMethodOutput").style.color = "red";
                document.getElementById("buyMethodOutput").style.fontWeight = "bold";
                document.getElementsByClassName("productsList")[0].innerHTML="";

            }
            else {

            //    not good // 

                // hello stash

                

                var clonebox = document.getElementsByClassName("productsList")[0];

                var clone2 = cart.cloneNode(true);

               

                if (param == "") {
                    clonebox.innerHTML = "";

                    // window.addEventListener("load", allCartBuy);
                }

                var responseOfDataBase = JSON.parse(this.responseText);

                var numOfCartProducts = responseOfDataBase.length;

               


                for (var i = 0; i < numOfCartProducts; i++) {

                    if (responseOfDataBase[i] !== null) {
                        // now it works //earlier due to nul , it stucked after executing once

                        productfit(i);
                    }
                }


                function productfit(i) {

                    //  var clone2 = cart.cloneNode(true);

                    // clone2.firstElementChild.firstElementChild.firstElementChild.src = responseOfDataBase[i].mainProductImage;


                    if (responseOfDataBase[i].colorMainImage === null) {
                        clone2.getElementsByClassName("buyCart")[0].src = responseOfDataBase[i].mainProductImage;

                        // clone2.getElementsByClassName("buyCart")[0].src = responseOfDataBase[i].colorMainImage;
                        // alert(mainImagOfThisProduct);
                    }
                    else {
                        clone2.getElementsByClassName("buyCart")[0].src = responseOfDataBase[i].colorMainImage;
                    }



                    // clone2.firstElementChild.firstElementChild.getElementsByClassName("productCode")[0].innerHTML = responseOfDataBase[i].productCode;

                    clone2.getElementsByClassName("productCode")[0].innerHTML = responseOfDataBase[i].productCode;

                    clone2.getElementsByClassName("orderNumber")[0].innerHTML = responseOfDataBase[i].orderNumber;

                    orderedProductsArray.push(responseOfDataBase[i].orderNumber);

                    // clone2.firstElementChild.firstElementChild.lastElementChild.innerHTML = responseOfDataBase[i].productName;

                    clone2.getElementsByClassName("productName")[0].innerHTML = responseOfDataBase[i].productName;

                    // clone2.getElementsByClassName("quantity-number")[0].value = responseOfDataBase[i].quantityOrdered;//not works

                    // .setAttribute('value', 'defaultValue');
                    clone2.getElementsByClassName("quantity-number")[0].setAttribute('value', responseOfDataBase[i].quantityOrdered);//works
                    // alert(clone2.getElementsByClassName("quantity-number")[0].value );

                    // alert(productName);

                    // clone2.firstElementChild.lastElementChild.firstElementChild.nextElementSibling.firstElementChild.innerHTML = Number(responseOfDataBase[i].buyPrice).toFixed(0);

                    clone2.getElementsByClassName("quantity-total")[0].innerHTML = Number(responseOfDataBase[i].totalCost).toFixed(0);

                    clone2.getElementsByClassName("productSize")[0].innerHTML = responseOfDataBase[i].productSize;

                    // clone2.firstElementChild.lastElementChild.firstElementChild.nextElementSibling.nextElementSibling.firstElementChild.src = responseOfDataBase[i].mainProductImage;

                    clone2.getElementsByClassName("small-item")[0].src = responseOfDataBase[i].mainProductImage;

                    clone2.getElementsByClassName('priceOfEach')[0].innerHTML = Number(responseOfDataBase[i].buyPrice).toFixed(0);

                    // document.getElementsByClassName("productsList")[0].appendChild(clone2);
                    // document.getElementsByClassName("productsList")[0].appendChild(clone2);

                    // clonebox.appendChild(clone2);//it will not consider the others

                    clonebox.innerHTML += clone2.outerHTML;

                    // activeEvery();
                    // calculateTotal();//to

                }


                // var itemcount = document.getElementsByClassName("itemcount");
                // alert(itemcount.length);

                calculateTotal();

               

                allCartBuy();//this works in letting to call all the functions actively , otherwise load event is taking at start and shows everything 1.

            }
        }

    }


    CartProducts.open("POST", "cart.php", true);
    CartProducts.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    // activeEvery();

    CartProducts.send("email=" + email);
}



cartProducts();//to load the cart items











function updateOrderDetails() {

    var itemcount = document.getElementsByClassName("itemcount");//it may create problem in case the unsaved cart data at index 0 is deleted

   
    if (param != "") {

        for (var i = 1; i < itemcount.length; i++) {

            // if(itemcount[i].innerHTML !== "" || itemcount[i].innerHTML !==null){

            var updateCart = new XMLHttpRequest();

            var OrderNumberOfProduct = document.getElementsByClassName("orderNumber")[i].innerHTML;


            var productCode = document.getElementsByClassName("productCode")[i].innerHTML; //we will delete those products or orderNumber which are not present

            //    deleted orerderNumbers are those which are present in responseOrder but not here

            var quantity = document.getElementsByClassName("quantity-number")[i].value;

          
            var totalCost = document.getElementsByClassName("quantity-total")[i].innerHTML;


            var dbparam = {
                email: EmailAddress,
                orderNumber: OrderNumberOfProduct,
                productCode: productCode,
                quantity: quantity,
                // size: sizeSelected,
                // productPrice: productPrice,
                totalCost: totalCost,
                orderDate: orderDate,
                update: 1,
                // modeOfPayment:modeOfPayment,
                // colorMainImage:mainImagOfThisProduct
            };

            // stringify 
            dbparam = JSON.stringify(dbparam);

            updateCart.open("POST", "cart.php", true);
            updateCart.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            updateCart.send("dbparam=" + dbparam);

        }
    }
    else {
        for (var i = 0; i < itemcount.length; i++) {

            // if(itemcount[i].innerHTML !== "" || itemcount[i].innerHTML !==null){

            var updateCart = new XMLHttpRequest();

            var OrderNumberOfProduct = document.getElementsByClassName("orderNumber")[i].innerHTML;


            var productCode = document.getElementsByClassName("productCode")[i].innerHTML; //we will delete those products or orderNumber which are not present

            //    deleted orerderNumbers are those which are present in responseOrder but not here

            var quantity = document.getElementsByClassName("quantity-number")[i].value;

            // var productSize = document.getElementsByClassName("productSize")[i].innerHTML;

            // var productPrice = document.getElementsByClassName("priceOfEach")[i].innerHTML;

            var totalCost = document.getElementsByClassName("quantity-total")[i].innerHTML;


            var dbparam = {
                email: EmailAddress,
                orderNumber: OrderNumberOfProduct,
                productCode: productCode,
                quantity: quantity,
                // size: sizeSelected,
                // productPrice: productPrice,
                totalCost: totalCost,
                orderDate: orderDate,
                update: 1,
                // modeOfPayment:modeOfPayment,
                // colorMainImage:mainImagOfThisProduct
            };

            // stringify 
            dbparam = JSON.stringify(dbparam);

            updateCart.onload= function () {
                if (this.status == 200) {
                  
                    // alert(this.responseText);
                    
                }
            }

            updateCart.open("POST", "cart.php", true);
            updateCart.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            updateCart.send("dbparam=" + dbparam);

        }
    }

    

}






function deleteOrderCarts() {

    var itemcount = document.getElementsByClassName("itemcount");
 
    var OrderNumberOfProduct = [];

    if (param != "") {
        for (var i = 1; i < itemcount.length; i++) {
            // get list of all ordernumbers
            OrderNumberOfProduct.push(document.getElementsByClassName("orderNumber")[i].innerHTML);
        }
    }

    else {
        for (var i = 0; i < itemcount.length; i++) {
            // get list of all ordernumbers
            OrderNumberOfProduct.push(document.getElementsByClassName("orderNumber")[i].innerHTML);
        }
    }

   
    OrderNumberOfProductForThis = { OrderNumberOfProduct: OrderNumberOfProduct, orderedProductsArray: orderedProductsArray, email: EmailAddress }
    // OrderNumberOfProduct for current after deletion//orderedProductsArray before deletion

    OrderNumberOfProductForThis = JSON.stringify(OrderNumberOfProductForThis);

    // alert(OrderNumberOfProductForThis);

    var deleteProductFromCart = new XMLHttpRequest();

    deleteProductFromCart.onload = function () {

        // alert(deleteProductFromCart.responseText);

        if (deleteProductFromCart.status == 200) {
            // alert("Cart");
            // alert(this.responseText);
            // alert("Your cart is updated");
        }
    }



    deleteProductFromCart.open("POST", "cart.php", true);
    deleteProductFromCart.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    deleteProductFromCart.send("currentOrderList=" + OrderNumberOfProductForThis);

}
// 


function saveCart() {

    // we will interact with database here
    updateOrderDetails();
    deleteOrderCarts();

}
