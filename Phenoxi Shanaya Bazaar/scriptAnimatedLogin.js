var form = document.querySelector('form');
for (var i = 0; i < form.length; i++) {
    form[i].addEventListener('submit', function (event) {
        event.preventDefault();
        // var formData = new FormData(this);
        // var xhr = new XMLHttpRequest();
    });
}

var arrOfAllCustomersNumber;
var arrOfAllEmailAddress;//we will store all the registered emails in this variable.
var generatedRandom;

function decidedToRegisteredNewCustomer() {

    // var myPromise = new Promise(function (resolve) {

    RegisteredCustomer = new XMLHttpRequest();

    RegisteredCustomer.onload = function () {
        if (this.status == 200) {

           

            var arrOfAllPassed = JSON.parse(this.responseText);//it gives completele array of customerNumber as per we setted in php.

            
            // var arrOfAllCustomersNumber = arrOfAllPassed[0];
            arrOfAllCustomersNumber = arrOfAllPassed[0]; //we want to store it globally
            // var arrOfAllEmailAddress = arrOfAllPassed[1];
            arrOfAllEmailAddress = arrOfAllPassed[1];
            // alert( arrOfAllEmailAddress);//works

           

            const arrCustLength = arrOfAllCustomersNumber.length;//124


            while (arrOfAllCustomersNumber.length != arrCustLength + 1) {

                
                var candidateInt = Math.floor(Math.random() * 2147483647) + 1;

                if (arrOfAllCustomersNumber.indexOf(candidateInt) === -1) {

                   

                    generatedRandom = candidateInt;


                    return candidateInt;
                    // return new Promise((resolve) => {

                   

                }

            }



        }

        else {
            document.getElementById("registerOutput").innerHTML = "Unable to get registered Customers";
        }
    }

    RegisteredCustomer.open("GET", "getAlreadySetCustomerNumber.php");
    RegisteredCustomer.send();

    // });

}


decidedToRegisteredNewCustomer();



setTimeout(function () {
    document.getElementById("registerOutput").style.display = "none";
}, 5000);


// function registerThisUser() {
function registerThisUser(name, email, password) {
    // async function registerThisUser() {


    document.getElementById("registerOutput").style.display = "none";

   
    const newCustomerNumberDecidedForThisUser = generatedRandom; //now as function tooked almost 60ms , till time we will be involved in typing the inputs


   

    useCustomer = new XMLHttpRequest();

    // var dbparam = { "customerNumber": newCustomerNumberDecidedForThisUser , "custName": name,"custEmail": email,"custPassword": password};
    var dbparam = { customerNumber: newCustomerNumberDecidedForThisUser, custName: name, custEmail: email, custPassword: password };

    var dbparam = JSON.stringify(dbparam);

    
    useCustomer.onload = function () {
        
        // useCustomer.onfocus = function () {

        document.getElementById("registerOutput").style.display = "flex";

        // document.getElementById("registerOutput").innerHTML = this.responseText;

        if (this.status == 200) {

            alert(this.responseText);

            document.getElementById("registerOutput").innerHTML = this.responseText;

                submitButtonOutput();

            // if (this.responseText === "You are successfully registered") {

            //     document.getElementById("registerOutput").innerHTML = this.responseText;

            //     submitButtonOutput();

             
            // }
            // else {
               

            //     // document.getElementById("registerOutput").innerHTML = this.responseText;

            //     document.getElementById("registerOutput").innerHTML = "Already registered";
            // }

        }

        setTimeout(function () {
            document.getElementById("registerOutput").style.display = "none";
        }, 5000);
    }

    useCustomer.open("POST", "customerDetailsF.php");
    useCustomer.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

    // useCustomer.send(dbparam);
    useCustomer.send("dbparam=" + dbparam);

   

}



// function register(element) {

function register() {


    var name = document.signUpForm.nameEnteredByTyping.value;//  
    // alert(name);//Sudha Kumari
    var email = document.signUpForm.emailEnteredByTyping.value;//
    // alert(email);
    var password = document.signUpForm.passwordEnteredByTyping.value;//
    var emailverified = document.getElementById("enterOTPSend").childElementCount;



    document.getElementById("registerOutput").style.display = "flex";

    if (emailverified !== 0) {

        var otp = document.signUpForm.OTPEnteredByTyping.value;//

        // registerThisUser(name, email, password);

        if (otp == generatedRandom) {
            // alert('OTP is correct');


            // document.getElementById("registerOutput").innerHTML = "OTP is correct";

            if (arrOfAllEmailAddress.indexOf(email) != -1) {
                document.getElementById("registerOutput").innerHTML = "Email already exists.Please login";
                return;
            }

            else {
                registerThisUser(name, email, password);//we want to pass this parameter into called function.
            }


        }
        else {

            // alert('Invalid OTP');
            document.getElementById("registerOutput").innerHTML = "Invalid OTP";
        }


    }
    else {
        // alert("Please verify email");
        document.getElementById("registerOutput").innerHTML = "Please verify email";
    }




    

    setTimeout(function () {
        document.getElementById("registerOutput").style.display = "none";
    }, 10000);


}




function sendEmail(element) {

    element.removeAttribute("value");
    element.setAttribute("value", "Resend the OTP");
  
    generatedRandomToSend = JSON.stringify(generatedRandom); //if not stringify then it will not work.

    // alert(generatedRandomToSend);

    setTimeout(function () {
        // var link = "mailto:sudhakumarichauhan24@gmail.com"
        var link = "mailto:" + document.signUpForm.emailEnteredByTyping.value
            + "?cc=shanayabazaar@gmail.com"
            + "&subject=" + encodeURIComponent("OTP for registering at Shanaya Bazaar")
            + "&body=" + encodeURIComponent("To login at shanaya bazaar. Your otp  is : " + generatedRandomToSend);
        // window.location.href = link;
        window.open(link, "_self");
    }, 60);





    
    document.getElementById("enterOTPSend").innerHTML = `<input id="otpOut" type="text" inputmode="numeric" placeholder="Enter OTP send to Email"  name="OTPEnteredByTyping" required></input>`;

}



var arrOfReceivedDetails;
function signInThisUser() {

    var email = document.signInForm.enteredSignedInEmail.value;

    var password = document.signInForm.enteredSignedInPassword.value;
    // alert(password=="");
    var forgotOtp = "";
    // alert(forgotOtp=="");//true

   
    if (document.signInForm.OTPEnteredByTyping !== undefined) {
        forgotOtp = document.signInForm.OTPEnteredByTyping.value;
        // alert(forgotOtp);

    }

  

    if (arrOfAllEmailAddress.indexOf(email) === -1) {
        // else if (arrOfAllEmailAddress.indexOf(email) === -1) {

        // alert("Please Sign Up");
        document.getElementById("registerOutput").style.display = "flex";
        document.getElementById("registerOutput").innerHTML = "Sorry, You are not registered.<br>Please Sign Up.";

    }
  
    else if (arrOfAllEmailAddress.indexOf(email) !== -1 && password == "" && forgotOtp == "") {
        // alert("Please enter password");

        // alert(forgotOtp);
        document.getElementById("registerOutput").style.display = "flex";
        document.getElementById("registerOutput").innerHTML = "Please enter password or click on forget password";
    }
    else {


        // after this , it get's reloaded hence we need to prevet this

        // alert("let's check it");

        var email = JSON.stringify(email);


        var RegisteredCustomerDetail = new XMLHttpRequest();

        RegisteredCustomerDetail.onload = function () {
            // var result = JSON.parse(this.responseText);
            // alert(this.responseText);//gives whole dictionary


            if (this.status == 200) {

                // alert(this.responseText);

                // we will uncomment
                arrOfReceivedDetails = JSON.parse(this.responseText);//it gives completele array of customerNumber as per we setted in php.


                
              

                Receivedpassword = arrOfReceivedDetails.Password;
               

                document.getElementById("registerOutput").style.display = "none";


                // if (Receivedpassword == password) {
                if (Receivedpassword == password || forgotOtp == generatedRandom) {

                    // alert("Welcome");

                    // alert("welcome");


                    if (document.getElementById("rememberMeCheck").checked) {
                      


                        var emailLocal = document.signInForm.enteredSignedInEmail.value;
                        localStorage.setItem("EmailAddress", emailLocal);


                    }
                    else {
                       
                        var EmailAddress = localStorage.getItem("EmailAddress");
                        if (EmailAddress != null) {

                            localStorage.removeItem("EmailAddress");
                        }

                        window.sessionStorage.setItem("EmailAddress", arrOfReceivedDetails.EmailAddress);

                    }


                  

                    document.getElementById("registerOutput").style.display = "flex";

                    document.getElementById("registerOutput").innerHTML = "welcome";

                    

                  

                    if (document.referrer) {

                        // alert(document.referrer);//http://localhost:3000/index.php
                        // alert(window.location.href);//http://localhost:3000/animatedLogin.html

                        if (document.referrer != window.location.href) {
                            window.location = document.referrer;
                        }
                        else {
                            window.location.href = "index.php";
                        }


                    } else {
                        // window.history.back();
                        window.location.href = "index.php"
                    }

                   

                }
                else {
                    // alert("Wrong Password");
                    document.getElementById("registerOutput").style.display = "flex";
                    document.getElementById("invalidSignIn").style.display = "flex";
                    document.getElementById("registerOutput").innerHTML = "Wrong Password";



                    // prevent reload from here
                    // event.preventDefault();
                    // return false;

                }
            }

            else {
                // document.getElementById("registerOutput").style.display = "flex";
                document.getElementById("registerOutput").innerHTML = "Try Again";
                // return false;
            }
        }


        RegisteredCustomerDetail.open("GET", "getThisCustomerDetail.php?EmailAddress=" + email);

        RegisteredCustomerDetail.send();

    }

    setTimeout(function () {
        document.getElementById("registerOutput").style.display = "none";
        document.getElementById("invalidSignIn").style.display = "none";
    }, 5000);

    // return false;
}



function forgotPassword(element) {


    element.innerHTML = "Resend the OTP";

    generatedRandomToSend = JSON.stringify(generatedRandom); //if not stringify then it will not work.

    // alert(generatedRandomToSend);

    setTimeout(function () {
        // var link = "mailto:sudhakumarichauhan24@gmail.com"
        var link = "mailto:" + document.signInForm.enteredSignedInEmail.value
            + "?cc=shanayabazaar@gmail.com"
            + "&subject=" + encodeURIComponent("OTP for accountRecovery at Shanaya Bazaar")
            + "&body=" + encodeURIComponent("To login at shanaya bazaar. Your otp  is : " + generatedRandomToSend);
        // window.location.href = link;
        window.open(link, "_self");
    }, 60);


    document.getElementById("enterOTPSendForget").innerHTML = `<input type="text" inputmode="numeric" placeholder="Enter OTP send to Email"  name="OTPEnteredByTyping" required></input>`;

}




const container = document.getElementById('container');//whole body content div just below body used only once

const registerBtn = document.getElementById('register');
registerBtn.addEventListener('click', () => {
    container.classList.add("active");
}); //when registerBtn is clicked then class active will be added in container and active class code will be seen 


const loginBtn = document.getElementById('login');
loginBtn.addEventListener('click', () => {
    container.classList.remove("active");
});






//to print the signupdata
function printvalue() {

    // alert("inside printvalue ");

    var name = document.signUpForm.nameEnteredByTyping.value;//  

    // alert(name);//Sudha Kumari


    //   alert("Welcome: " + name + `$<br>`+"You have successfully sign up to Shanaya Bazaar");//irritating start it later on

    alert("Welcome " + name + "\n\nYou have successfully signed up on Shanaya Bazaar");//irritating start it later on

}


function mobileFriendly() {
    // if ()
    // create like if maximum width of screen is 480 px then .sign in widht should be 0px and call this only affer double click to switch

}






setInterval(innerWidthCheck, 1);
// innerWidthCheck();
// var innerWidthFound=
function innerWidthCheck() {
    if (window.innerWidth <= 450) {
        

        // document.getElementsByClassName("sign-in")[0].addEventListener("mouseover",openSignUp , true);
        document.getElementsByClassName("sign-in")[0].addEventListener("click", openSignUp, true);
       
        //for sign-up now
        document.getElementsByClassName("sign-up")[0].addEventListener("click", openSignIn, true);


    }
    else {
        
    }
}



function openSignUp() {



    //creating blue highlighted text to toggle signup page
    var openSignup1 = document.createElement("div");
    openSignup1.className = "open-signup";

    openSignup1.innerHTML = "<h3>Sign Up</h3>";
    openSignup1.style.position = "absolute";
    openSignup1.style.top = "50px";
    openSignup1.style.right = "5vw";
    openSignup1.style.color = "blue";
    // openSignup1.style.transform="translate(30)";
    openSignup1.style.background = "#f0f0f0";



    openSignup1.onmouseover = function () {
        openSignup1.style.color = "red";

    }; //it works but below one is not working
    openSignup1.onmouseout = function () {
        openSignup1.style.color = "blue";
        //     openSignup1.style.display="none";
    }

    openSignup1.onclick = function () {
        document.getElementsByClassName("toggle-container")[0].style.display = "block";


    };

   
    document.getElementsByClassName("form-container")[1].appendChild(openSignup1);



    
    document.getElementsByClassName("form-container")[1].style.width = "100%";//same as sign in class
   
    
    document.getElementsByClassName("sign-in")[0].style.transition = "none";//as it causes slow up expand hence transition removed
    
    document.getElementsByClassName("toggle-container")[0].style.display = "none";

    document.getElementsByClassName("sign-in")[0].addEventListener("dblclick", toggleSignUp, false); //works good //don't use mouse out otherwise it will trace from the current position and if out , then it will be triggered



}





function openSignIn() {


    //creating to open signin toggle with blue highlight above
    var openSignin1 = document.createElement("div");
    //   openSignin1.innerHTML="<br>"
    openSignin1.className = "open-signin";

    openSignin1.innerHTML = "<h3>Sign In</h3>";
    openSignin1.style.position = "absolute";
    // openSignin1.style.position="relative";

    // openSignin1.style.top = "40px";
    openSignin1.style.top = "30px";
    // openSignin1.style.left="80vw"
    // openSignin1.style.right = "-80vw" //ok according to work and it don't create Sign in in seperate line
    openSignin1.style.left = "70vw";
    openSignin1.style.color = "blue";
    // openSignin1.style.display="flex";
    openSignin1.style.background = "#f0f0f0";



    openSignin1.onmouseover = function () {
        openSignin1.style.color = "red";

    }; //it works but below one is not working
    openSignin1.onmouseout = function () {
        openSignin1.style.color = "blue";
        //    openSignin1.style.display="none";
    }

    openSignin1.onclick = function () {
        document.getElementsByClassName("toggle-container")[0].style.display = "block";

    };

    // document.getElementsByClassName("open-signup")[0].addEventListener("mouseover",function(event){
    //     // openSignup.style.display="block";
    //     openSignup.style.color="red";

    // },true);//not working because document don't contain any such classname but if you want 

    document.getElementsByClassName("sign-up")[0].appendChild(openSignin1);




    document.getElementsByClassName("toggle-container")[0].style.display = "none";

  
    document.getElementsByClassName("sign-up")[0].style.left = "-100%";
    document.getElementsByClassName("sign-up")[0].style.width = "100vw";
    document.getElementsByClassName("sign-up")[0].style.transition = "none";//as it causes slow up expand hence transition removed


    document.getElementsByClassName("sign-up")[0].addEventListener("dblclick", toggleSignUp, false);
}


function toggleSignUp() {
    // document.getElementsByClassName("toggle-container")[0].style.display = "block";
    document.getElementsByClassName("toggle-container")[0].style.display = "block";
    // document.getElementsByClassName("toggle")[0].style.display = "block";

}




// toggling green part is creating problem



function invalidDataCheck() {
    var invalidInputData = document.getElementsByClassName("invalidFormFilled");
    for (let invalidData; invalidInputData.length; invalidData++) {
        invalidData.addEventListener("invalid", function () {
            document.getElementById("invalidSignIn").innerHTML = "Please fill correct data";
        });
    }

}

var elem = document.getElementById("Re-Enter-Password");
elem.addEventListener("keydown", function (e) {
    if (e.code === "Enter") {  //checks whether the pressed key is "Enter"
        // alert("enter pressed");
        // validateReEnter(this);
        validateReEnter();
    }

});

// function validateReEnter(element) {

function validateReEnter() {

    // var reEnterPassword = element.value;
    var reEnterPassword = document.getElementById("Re-Enter-Password").value;
    var password = document.getElementById("password").value;
    if (reEnterPassword !== password || password == "") {
        document.getElementById("registerOutput").style.display = "flex";
        document.getElementById("registerOutput").innerHTML = "Check the form. It is invalid";
        return;
    }
    else {

        document.getElementById("registerOutput").style.display = "none";
        // document.getElementById("registerOutput").innerHTML = "";
        // register(this);
        // var elem = document.getElementById("submitEnteredData");

        // register(elem);



        register();

        // return;


        // elem.addEventListener("click", function () {
        //     register(this);//this created the complication of clicking again two times.
        //     return;
        // });


    }

    // var elem = document.getElementById("submitEnteredData");
    // elem.addEventListener("click", function () {
    //     register(this);
    // });
}


function myFunctionreset() {
    // document.getElementsByName("signUpForm").reset();
    document.getElementById("registerOutput").style.display = "flex";
    // document.getElementById("resetOut").innerHTML = "form just reseted ";
    document.getElementById("registerOutput").innerHTML = "form just reseted ";
    setTimeout(function () {
        document.getElementById("registerOutput").style.display = "none";
    }, 10000);

}





//submit button output
function submitButtonOutput() {

    // alert("inside submit button");



    document.getElementById("registerOutput").style.display = "flex";
    var registerOutput = document.getElementById("registerOutput");
    // registerOutput.innerHTML = "Your details has been submitted";

    registerOutput.innerHTML = "Welcome " + name + "\n\nYou have successfully signed up on Shanaya Bazaar";

    registerOutput.style.color = "green";
    // now we need to set display back to none after 10 seconds


    var name = document.signUpForm.nameEnteredByTyping.value;//  


    setTimeout(function () {
        document.getElementById("registerOutput").style.display = "none";
        //we want to move to index.php

        document.getElementById("registerOutput").style.display = "none";

        // window.location.href="index.php";

        window.location.href="http://localhost:3000/index.php";


    }, 10000);

    // necessary to put the timeout inside because it will not rerun the js to tract it from outside.






    if (document.referrer) {

        // alert(document.referrer);//http://localhost:3000/index.php
        // alert(window.location.href);//http://localhost:3000/animatedLogin.html

        if (document.referrer != window.location.href) {
            window.location = document.referrer;
        }
        else {
            window.location.href = "index.php";
        }


    } else {
        // window.history.back();
        window.location.href = "index.php"
    }








}



//check mobile no.
function checkMobileNo() {
    var mobileNo = document.getElementsByName("phone")[0].value; //works
    if (mobileNo.length < 10 || mobileNo.length > 12) {
        alert("Please enter valid mobile no.");//works
    }
}
