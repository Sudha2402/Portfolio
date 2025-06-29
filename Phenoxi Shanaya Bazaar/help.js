// issues



//onblur//onfocus
var issue = document.getElementById("issues");
issue.addEventListener("focus", myFocusFunction, true);//focus event acts
issue.addEventListener("blur", myBlurFunction, true);//blur event acts

function myFocusFunction() {
    // document.getElementById("issues").style.backgroundColor = "#B2BEB5";

    document.getElementById("issues").style.backgroundColor = "rgb(240, 251, 255)";
}
function myBlurFunction() {
    document.getElementById("issues").style.backgroundColor = "";
}









var requestAnimationSlideSmooth = document.getElementById("requestAnimationFrameId");

// alert(requestAnimationSlideSmooth.offsetWidth);
// alert(screen.availWidth);
// alert(window.innerWidth);

var leftPosi = 0;



// function moveDiv(timestamp) {
// 
function moveDiv() {
    // var rightpos = requestAnimationSlideSmooth.style.right;



    if (leftPosi == (100)) {
        // if (leftPosi == (window.innerWidth - requestAnimationSlideSmooth.offsetWidth)) {

        leftPosi = 0;
        requestAnimationSlideSmooth.style.left = leftPosi + "vw";
        // requestAnimationSlideSmooth.style.left = leftPosi + "px";
        requestAnimationFrame(moveDiv);//Your callback routine must itself call requestAnimationFrame() if you want to animate another frame at the next repaint.


    } else {

        leftPosi += 0.25;

        requestAnimationSlideSmooth.style.left = leftPosi + "vw";
        // requestAnimationSlideSmooth.style.left = leftPosi + "px";
        requestAnimationFrame(moveDiv);



    }

}

// requestAnimationFrame(moveDiv);
window.requestAnimationFrame(moveDiv);











function sendEmail(element) {



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




function submitIssueMentioned() {

    var issue = document.getElementById("issues").value;
    //    alert(issue);

    setTimeout(function () {
        // var link = "shanayabazaar@gmail.com"
        var link = "mailto:" + 'shanayabazaar@gmail.com'
            + "?cc=shanayabazaar@gmail.com"
            + "&subject=" + encodeURIComponent("Add an Issue on Shanaya Bazaar")
            + "&body=" + encodeURIComponent("My Issue is : " + issue);
        // window.location.href = link;
        window.open(link, "_self");
    }, 60);

}



{/* <label for="badquality"><input type="checkbox" name="complaints" value="badquality">Bad Quality</label>
        <label for="damaged"><input type="checkbox" name="complaints" value="damaged">Damaged</label>
        <label for="missing"><input type="checkbox" name="complaints" value="missing">Missing products</label>
        <label for="wrong"><input type="checkbox" name="complaints" value="wrong">Wrong products</label>
        <label for="other"><input type="checkbox" name="complaints" value="other">Other</label> */}














function submitComplainMentioned() {

    var complaints = document.getElementsByName("complaints");
    var complainsTypes = "";
    for (var i = 0; i < complaints.length; i++) {
        if (complaints[i].checked) {
            var complainsType = complaints[i].value;
            //    var complainsType=complaints[i].innerHTML;

            //  alert(complainsType);

            complainsTypes += complainsType + ", ";
        }
    }

    // alert(complainsTypes);

    var complaintdescription = document.getElementById("complaintdescription").value;
    //    alert(issue);

    setTimeout(function () {
        // var link = "shanayabazaar@gmail.com"
        var link = "mailto:" + 'shanayabazaar@gmail.com'
            + "?cc=shanayabazaar@gmail.com"
            + "&subject=" + encodeURIComponent("Add an Issue on Shanaya Bazaar")
            + "&body=" + encodeURIComponent("My complain is related to : " + complainsTypes + ' \n\n' + complaintdescription);
        // window.location.href = link;
        window.open(link, "_self");
    }, 60);

}



