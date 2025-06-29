
var thanksvideoplay;
var upipay;




var EmailAddress;
EmailAddress = sessionStorage.getItem("EmailAddress");
// alert(EmailAddress);

if (EmailAddress === null || EmailAddress === undefined) {
    // we can also get it from local storage
    EmailAddress = localStorage.getItem("EmailAddress");
    // alert(EmailAddress);
}











thanksvideoplay = '<div class="mobilepopover"><div id="surpriseSection" onmouseover="stopOpacity()"><a href="index.php"><button type="button" class="cuttab" style="position:fixed;top: 21vh" onclick="cutbutton()">&#10006;</button><video src="files acc/thanks for shopping.mp4" style="width: 95vw;position:fixed;top: 20vh;left: 2.5vw;" autoplay loop ></video></a></div></div>';


upipay = '<div class="mobilepopover"><div id="surpriseSection" onmouseover="stopOpacity()"><button type="button" class="cuttab" style="position:fixed;top: 6%;right: 20%;z-index:4" onclick="cutbutton()">&#10006;</button><img src="files acc/UPI ID.jpg" style="height:90vh;width:100vw;max-width:428px;position:fixed;top: 50%;left: 50%;transform: translate(-50%, -50%);z-index:3" ></img></div></div>'; //perfect settings and can be used everywhere where we need to position fixed and align center.



function popup() {
    var popup = document.getElementsByClassName("popup");
    for (let index = 0; index < popup.length; index++) {
        var element = popup[index];

    }
}
// need to complete and we will do later on




//innertext
function validate() {
    var msg;
    // if (document.myFormin.userPass.value.length > 5) {
    if (document.getElementsByClassName("password")[0].value.length > 5) {
        // minimum 6 characters required
        msg = "good";
        document.getElementsByClassName('myPassWordStrength')[0].innerText = "Strength : " + msg;
        document.getElementsByClassName('myPassWordStrength')[0].style.color = "green";

    }
    else {
        msg = "poor";
        document.getElementsByClassName('myPassWordStrength')[0].innerText = "Strength : " + msg;
        document.getElementsByClassName('myPassWordStrength')[0].style.color = "red";
    }

    // document.getElementsByClassName('myPassWordStrength')[0].style.display="block";//works
    document.getElementsByClassName('myPassWordStrength')[0].style.display = "";//also works to remove display none
    // document.getElementsByClassName('myPassWordStrength')[0].innerText = "Strength : "+msg;

    document.getElementsByClassName('myPassWordStrength')[0].style.fontWeight = "boldd";
    document.getElementsByClassName('myPassWordStrength')[0].style.margin = "0px";
    document.getElementsByClassName('myPassWordStrength')[0].style.padding = "0px";

    setTimeout(function () {
        document.getElementsByClassName('myPassWordStrength')[0].style.display = "none";
    }, 5000);

}




var traceClicks = document.getElementsByTagName("a");

function myFunctionTraceClicks() {

    for (let index = 0; index < traceClicks.length; index++) {
        var element = traceClicks[index];

        element.addEventListener("click", myConsoleTraceFunction(element))


    }

}

myFunctionTraceClicks();


function myConsoleTraceFunction(element) {
    console.trace();

}



var settedColor;
function chBackcolor(BackColor) {

    window.removeEventListener("wheel", wheelevent);

    console.log("back color changed");

    settedColor = document.getElementsByTagName("body")[0].style.backgroundColor;



    // alert(settedColor);

    document.getElementsByTagName("body")[0].style.backgroundImage = "";

    if (settedColor !== BackColor) {

        //here this colors can be equated only if it is in rgb henece we checked rgb value using alert and updated the value in html , now this works.

        // document.body.style.backgroundColor = BackColor;

        document.getElementsByTagName("body")[0].style.backgroundColor = BackColor;

        // this.style.border="2px solid green";//not works

        if (BackColor == "rgb(76, 38, 11)") {
            document.body.style.color = "white";
        }
        else {
            document.body.style.color = "black";
        }



    }



    else {
        window.addEventListener("wheel", wheelevent);

    }


}





function leftscrollBut(element) {

    var width = element.parentElement.clientWidth;//not works

    // element.scrollLeft -= (width - 10); //not works
    element.parentElement.scrollLeft -= (width - 10); //works

}


function righttscrollBut(element) {

    var width = element.parentElement.clientWidth;

    element.parentElement.scrollLeft += (width - 10); //works

}






let divHistory = document.createElement("div");
divHistory.setAttribute("class", "historyButton");


document.body.insertBefore(divHistory, document.body.childNodes[10]);


var history = window.history;
var historyLength = history.length;
console.log("the history length is :" + historyLength);

let backbtn = document.createElement("button");
backbtn.setAttribute("id", "backbtn");


backbtn.setAttribute("onclick", "goBack()");//goBack() is a function which is defined below
backbtn.innerHTML = "Back";
// backbtn.style.float = "left";
backbtn.style.position = "fixed";
backbtn.style.bottom = "2vh";
backbtn.style.left = "2vw";
backbtn.style.zIndex = "6";
backbtn.style.display = "none";


// backbtn.style.margin = "2vh 7vw";
backbtn.style.fontSize = "4vh";



document.getElementsByClassName("historyButton")[0].appendChild(backbtn)

function goBack() {
    window.history.back();//goes back to previous page
}




//forward button
let forwardbtn = document.createElement("button");
forwardbtn.setAttribute("id", "forwardbtn");

forwardbtn.setAttribute("onclick", "goForward()");//goForward() is a function which is defined below
forwardbtn.innerHTML = "Forward";
// forwardbtn.style.float = "right";
forwardbtn.style.position = "fixed";
forwardbtn.style.zIndex = "6";
forwardbtn.style.bottom = "2vh";
forwardbtn.style.right = "2vw";
// forwardbtn.style.margin = "2vh 7vw";
forwardbtn.style.fontSize = "4vh";
forwardbtn.style.display = "none";

document.getElementsByClassName("historyButton")[0].appendChild(forwardbtn);

document.write("<br>");
function goForward() {
    window.history.forward();//goes forward to next page
}








//tracking location
navigator.geolocation.getCurrentPosition(position => {
    console.log(position)
}, error => {
    console.log(error)
},
    {
        timeout: 5000, // 5 seconds timeout
        maximumAge: 10000, // accept only position, that are not older than 10 seconds
        enableHighAccuracy: true // high accuracy
    })

// Watch the geo location of a user

var idWatchPosition = navigator.geolocation.watchPosition(position => {
    console.log(position)
});



// stop watching after 1 minute

setTimeout(() => {
    navigator.geolocation.clearWatch(idWatchPosition)
}, 60 * 1000)








function clickCounterSession() {

    if (sessionStorage.clickcountF) {
        sessionStorage.clickcountF = Number(sessionStorage.clickcountF) + 1;
    } else {
        sessionStorage.clickcountF = 1;
    }
    // document.writeln("<br>sessionStorage.clickcountF : " + sessionStorage.clickcountF)
    document.getElementById("sessionStorageCountF").innerHTML = "sessionStorageCountF :" + sessionStorage.clickcountF;
    console.log("sessionStorage.clickcountF : " + sessionStorage.clickcountF);
    console.log(sessionStorage.clickcountF);
}





function clickCounterLocal() {
    if (typeof (Storage) !== "undefined") {

        if (localStorage.clickcount) {
            localStorage.clickcount = Number(localStorage.clickcount) + 1;
        } else {
            localStorage.clickcount = 1;
        }
        document.getElementById("result").innerHTML = "You have clicked the button " + localStorage.clickcount + " time(s).";
    } else {
        document.getElementById("result").innerHTML = "Sorry, your browser does not support web storage...";
    }
}




// var myIntervalColorToggle = setInterval(setColor, 500);

if (document.getElementById("colorToggle") != null) {
    var myIntervalColorToggle = setInterval(setColor, 5000);
}


if (document.getElementsByClassName("scorePoint")[0] != null) {

    var scorePoint = document.getElementsByClassName("scorePoint");
    var cashPrice = document.getElementsByClassName("cashPrice");

    setInterval(function () {
        for (var i = 0; i < scorePoint.length; i++) {

            scorePoint[i].style.color = scorePoint[i].style.color == "blue" ? "purple" : "blue";

            cashPrice[i].style.color = cashPrice[i].style.color == "red" ? "#020f75" : "red";

        }

    }, 1000);







}



function setColor() {

    // document.getElementById("colorToggle").style.backgroundColor = document.getElementById("colorToggle").style.backgroundColor == "chartreuse" ? "pink" : "chartreuse";


    // here since we are using iframe hence many id in same one file5

    if (document.getElementById("colorToggle") != null) {

        // https://www.color-meanings.com/shades-of-green-color-names-html-hex-rgb-codes/

        // document.getElementById("colorToggle").style.backgroundColor = document.getElementById("colorToggle").style.backgroundColor == "chartreuse" ? "#014421" : "chartreuse";//we uncomment later


        // document.getElementById("colorToggle").style.color = document.getElementById("colorToggle").style.color == "black" ? "#f8f7e7" : "black";//uncomment later


        // document.getElementById("colorToggle").style.color = "black";


        // document.getElementById("colorToggle").style.paddingBottom = "6px";//uncomment later
        // document.getElementById("colorToggle").style.display="inline-flex";
    }

}

function stopColor() {
    clearInterval(myIntervalColorToggle);
}
function resumeColor() {
    setInterval(setColor, 500);
}






function printPage() {
    // window.print();

    var buttonsOnPrint = document.getElementsByTagName("button");
    for (var i = 0; i < buttonsOnPrint.length; i++) {
        buttonsOnPrint[i].style.display = "none";


    }
    window.print();
    //it works only when below
}













//you can't edit the page

window.addEventListener("contextmenu", function () {
    //show nothing on right click , like inspect
    // return false;

    console.error("You can't edit the page according to policy");
    // return false;

});






console.warn("This is a warning! Don't trace");





window.addEventListener("beforeunload", function (e) {

    return "You are about to leave this page";
});



function star1() {
    document.getElementById("star1").style.color = "blue";
}



//remove empty textnodes and merge extra textnode
document.normalize();






//login otp
//try this later on






// document.addEventListener("click", myOtp);

function myOtp() {

    var mobileNumber = document.getElementById("mobileNumber").value;
    // var otp = document.getElementById("copiedOtp").value;//you can set copyied get pasted on click that you learned in execCommand

    document.getElementById("otp").innerHTML = Math.random();//otp is send on mobile with message 
    var otpSend = document.getElementById("otp").innerHTML;
    var otpEnter = document.getElementById("otpEntered").value;
    if (otpEnter == otpSend) {
        // alert("otp is correct");
        document.getElementById("otpStatus").innerHTML = "otp is correct";

    }
    else {
        // alert("otp is incorrect");
        document.getElementById("otpStatus").innerHTML = "otp is incorrect";
    }

}




//setting live timer

if (document.getElementById("time") != null) {
    let timeid = document.getElementById("time"); //timidId should be global for outer function to work inside like mytimidfunction(), as it is called   inside setinverval and event onclick
    setInterval(function () {
        var date = new Date();
        timeid.innerText = (date.getHours()).toString().padStart(2, "0") + ":" + (date.getMinutes()).toString().padStart(2, "0") + ":" + (date.getSeconds()).toString().padStart(2, "0");

        timeid.style.backgroundColor = "yellow"
        timeid.style.color = "red"



        timeid.onclick = mytimidfunction


    }, 1000);
}

function mytimidfunction() {
    timeid.style.backgroundColor = "red"
    timeid.style.color = "yellow"
}

