


// we want a png to show in background untill page is loaded fully
// so we use a background image with eventlistener
// when page is loaded we change the background image to a solid color
document.addEventListener("DOMContentLoaded", function () {
    // document.body.style.backgroundImage = "url('loadingImage.png')";
    document.body.style.backgroundSize = "contain";
    document.body.style.backgroundRepeat = "no-repeat";
    document.body.style.backgroundPosition = "center";


    // setTimeout(function(){
    //     document.body.style.backgroundImage = "none";
    // },500);

});





// alert(EmailAddress);

var EmailAddress;

EmailAddress = sessionStorage.getItem("EmailAddress");
// alert(EmailAddress);

if (EmailAddress == null || EmailAddress == undefined) {
    // we can also get it from local storage
    EmailAddress = localStorage.getItem("EmailAddress");
}

if (EmailAddress == null || EmailAddress == undefined) {
    // id="Gamelogin"
    document.getElementById("Gamelogin").style.display = "block";
}
else {
    document.getElementById("Gamelogin").style.display = "block";
    document.getElementById("Gamelogin").firstElementChild.innerHTML = "Welcome " + EmailAddress + "</br></br>";
}

// alert(EmailAddress);


var mainPageHrefOrSrc = document.getElementById("mainPageHrefOrSrc").innerHTML;

mainPageHrefOrSrc = mainPageHrefOrSrc.trim();


document.getElementById("mainHeader").addEventListener("load", headerFunction);//it totally works



// importing headerpart of main website
var headerOfProduct;


function headerFunction() {

    // var mainHeader = document.getElementById("mainHeader").contentWindow.document.getElementsByTagName("header")[0];
    var mainHeader = document.getElementById("mainHeader").contentWindow.document.getElementsByTagName("header")[0].getElementsByClassName("menuitems")[0];
    // var mainWelcome = document.getElementById("mainHeader").contentWindow.document.getElementById("Welcome");
    var mainHeaderAdopted = document.adoptNode(mainHeader);
    // var mainWelcomeAdopted = document.adoptNode(mainWelcome);
    // document.body.getElementById("mainHeader").innerHTML=mainHeaderAdopted;//not works
    headerOfProduct = document.getElementById("mainHeaderNode");
    headerOfProduct.appendChild(mainHeaderAdopted);//works

    //         // headerOfProduct.appendChild(mainWelcomeAdopted);//works
    //         var headertitle = headerOfProduct.getElementsByClassName("headertitle")[0];
    //   headertitle.style.display = "none";//uncomment if you want the productpage to see this title
    //         headertitle = headertitle.getElementsByTagName("img")[0];
    //         var titlelogo = headertitle.src;
    //         titlelogo = titlelogo.substring(titlelogo.lastIndexOf("/") + 1, titlelogo.length);
    //         titlelogo = titlelogo.replace(/%20/g, " ");
    //         headertitle.src = mainPageHrefOrSrc + titlelogo;
    //         var headerinputs = headerOfProduct.getElementsByClassName("headerinputs")[0].getElementsByTagName("img")[0];
    //         var logo = headerinputs.src;
    //         var logo = logo.substring(logo.lastIndexOf("/") + 1, logo.length);
    //         headerinputs.src = mainPageHrefOrSrc + logo;
    //         var headerSearch = headerOfProduct.getElementsByClassName("headerinputs")[0];
    //         headerSearch.addEventListener("click", headerPage);

    function headerPage() {
        window.location.href = mainPageHrefOrSrc + "index.php";//we want that user can get the search from home with all ideas.
    }
}



var myGamePiece;


var myBackground;



var crashed = false;


var myObstacles = [];

var myScore;

// First make a score component:



var mySound; //to play the sound on moving
// alert(mySound);
var mySoundCrash; //to play sound on crash

var mySoundAfter; //to play sound after crash


// var jsConfetti = new JSConfetti();


function startGame() {

    //if sounds are already present then stop it
    if (mySound) {
        // if (true) {
        mySound.stop();
        mySoundCrash.stop();
        mySoundAfter.stop();
        //remvoe initial mygamepeice
        // clear all like gamearea
        // myGameArea.clear();

    }


    //clear initial mygamearea update
    // updateGameArea()

    // if (!crashed) {
    //     //clear all initial
    //     updateGameArea.clear();

    // }



    myGamePiece = new component(30, 30, "files acc/emoji1.gif", 10, 120, "image");

    // we want  myGamePiece.image.src = "wink-sweet-n-sassy.gif"; once the crash takes place and game is over






    //for in top bottom center
    // myUpBtn = new component(30, 30, "blue", 50, 100);
    // we want center position of the canvas

    if (window.innerWidth > 700) {
        // get relative position of the outer canvas
        myUpBtn = new component(30, 30, "blue", 50, 100);
        myDownBtn = new component(30, 30, "blue", 50, 160);//bottom
        myLeftBtn = new component(30, 30, "blue", 20, 130);//left
        myRightBtn = new component(30, 30, "blue", 80, 130);//right




    }

    else {
        myUpBtn = new component(30, 30, "blue", 50, 100);
        myDownBtn = new component(30, 30, "blue", 50, 160);//bottom
        myLeftBtn = new component(30, 30, "blue", 20, 130);//left
        myRightBtn = new component(30, 30, "blue", 80, 130);//right
    }







    mySound = new sound("files acc/fm-freemusic-happy-and-joyful-children(chosic.com).mp3"); //this is used to  call sound object constructor function 
    // src is


    mySound.play(); //it is also like non stopable , so apply a condition in updateGameArea() to stop it after crash



    //for horror sound
    //  https://motionarray.com/learn/royalty-free-music/horror-background-music/




    mySoundCrash = new sound("files acc/no-luck-too-bad-disappointing-sound-effect-112943.mp3");




    mySoundAfter = new sound("files acc/Luke-Bergs-Bliss(chosic.com).mp3"); //now it fullfills the requirement 


    myScore = new component("30px", "Consolas", "red", 0, 40, "text");//we can also use the long code that we learned in java 



    myGameArea.start(); //myGameArea is an object which is defined below and start is the prop0rty defined for this object and it contains a function hence () used with start


    // document.getElementById("restart").style.display = "block";




}



var myGameArea = {


    canvas: document.createElement("canvas"),
    start: function () {

        // this.canvas.width = 480;//default we set //this refers to myGameArea


        // if (document.getElementsByTagName("canvas")[0]) {//it takes time to load
        // setTimeout(() => {

        // document.getElementsByTagName("body")[0].addEventListener("load", gameSize);

        // function gameSize() {

        if (window.innerWidth !== 0) {
            if (window.innerWidth > 700) {
                this.canvas.width = 690;

                // alert(window.innerWidth);
                document.body.appendChild(document.createElement("div"));

                var div = document.body.lastChild;

                div.innerHTML = '<a href="index.php"><video src="files acc/welcome to shanaya bazaar.mp4" style="max-height:50vh;position: fixed;right: 5vh;top: 5vh;max-width:calc(100vw - 750px )" autoplay loop  muted playsinline></video></a>';



            }
            else {
                // alert(window.innerWidth);

                // this.canvas.width = (window.innerWidth - 15);
                // alert(window.innerWidth);
                // alert(window.innerWidth - 15);
                this.canvas.width = window.innerWidth;

                //let's get the width of screen


                // this.canvas.width = 100 +"vw" ;//not works
                // this.canvas.height = 270;
                // this.canvas.height = window.innerHeight - 15;//full screen




            }

        }
        // }
        // }, 2000);


        // }

        if (window.innerWidth < 500) {

            this.canvas.height = 270;//more in case of mobile
        }
        else {
            this.canvas.height = 380;//full screen
        }
        // this.canvas.height = 600;


        // set id of this canvas
        this.canvas.id = "canvasGame";


        this.context = this.canvas.getContext("2d");//as we always set

        document.body.insertBefore(this.canvas, document.body.childNodes[0]);

        // document.body.insertBefore(this.canvas, document.body.childNodes[0].childNodes[0]);


        this.frameNo = 0;//uncomment //property for counting frames
        // this.frameNo = 9423; //comment//property for counting frames
        //frameNo is used for animation //it is a property we are defining in myGameArea and it is used in the function hence this. is used

        this.interval = setInterval(updateGameArea, 20);//In the myGameArea object, add an interval which will run the updateGameArea() function every 20th millisecond (50 times per second).


        window.addEventListener('keydown', function (e) {//keydown track not which key is being pressed 
            myGameArea.key = e.keyCode; //hence myGameArea.key property will track the keycode to check which key has been pressed

            //Then we can move the red square if one of the arrow keys are pressed:

            myGamePiece.image.src = "files acc/wink-sweet-n-sassy.gif";

            e.preventDefault();

            myGameArea.keys = (myGameArea.keys || []);//ya toh object property ya fir array
            myGameArea.keys[e.keyCode] = (e.type == "keydown");


        });

        window.addEventListener('keyup', function (e) {
            myGameArea.key = false; //it is even though affected , but not makes any change due to 20 times call//jo key pahle selected tha uska effect nullify kare fir dusre key ka function dale//ye key uthane par h

            myGamePiece.image.src = "files acc/emoji1.gif";
            myGameArea.keys[e.keyCode] = (e.type == "keydown");

            //here key will be e,keyCode and value is true or false


        })




        window.addEventListener('keydown', function (e) {
            myGameArea.keys = (myGameArea.keys || []); //at start , myGameArea.keys will be empty string but there after it will be updated to it's initial value // myGameArea.keys = myGameArea.keys

            //Create a keys array for the myGameArea object,


            myGameArea.keys[e.keyCode] = true;//insert one element for each key that is pressed, and give it the value true

            //or 

            myGameArea.keys[e.keyCode] = (e.type == "keydown"); //e.type is keydown here because this is being passed as event 



        })



        //mousemove for moving on blue screen touch button
        window.addEventListener('mousemove', function (e) {
            myGameArea.x = e.pageX;//myGameArea utna khasak jaiga jitna usse pageX ko trigger karta, note yaha page bhi khaskega kyuki ye inbuilt event h  
            myGameArea.y = e.pageY;
        })







        window.addEventListener('touchmove', function (e) {
            myGameArea.x = e.touches[0].screenX; //I haven't studied this touchmove 
            myGameArea.y = e.touches[0].screenY;
        });



        window.addEventListener('mousedown', function (e) {
            myGameArea.x = e.pageX;
            myGameArea.y = e.pageY;
        })
        window.addEventListener('mouseup', function (e) {
            myGameArea.x = false;
            myGameArea.y = false;
        })
        window.addEventListener('touchstart', function (e) {
            myGameArea.x = e.pageX;
            myGameArea.y = e.pageY;
        })
        window.addEventListener('touchend', function (e) {
            myGameArea.x = false;
            myGameArea.y = false;
        })




    },

    clear: function () {//Also add a function called clear(), that clears the entire canvas.
        this.context.clearRect(0, 0, this.canvas.width, this.canvas.height);//stop at it's position

    },   //clear is a property of myGameArea object and it is used in the function hence









    stop: function () {
        clearInterval(this.interval);

    },   //Also add a stop() method to the myGameArea object, which clears the 20 milliseconds interval.



}




function component(width, height, color, x, y, type) {

    //In the component constructor we test if the component is of type "text", and use the fillText method instead of the fillRect method:

    this.type = type;//this refers to the current object which is being created and it will be like var objname = new component() and this will be refered to objname




    //In the component constructor we test if the component is of type "image", and create an image object by using the built-in "new Image()" object constructor.









    if (type == "image" || type == "background") {//for both backgound image and gamePiece, image object will be created as background is also an object image hence it needs Image()
        this.image = new Image();
        this.image.src = color;

    }



    //agar sirf backound chahiya , alag se aur drw object alag se create karna h toh , image aur background ko alag alag initiate karo





    if (type == "image") {//it is only for mygamepiece , hence lower one is adviceable to use
        this.image = new Image();//Image constructor 
        this.image.src = color;//color ke position par hum src denge .


        //to set zIndex of a component in canva
        this.image.style.zIndex = 3;//3 is the value of zIndex ,


    } //issi conditions se drawing object banana chahiya update method me








    this.score = 0;//uncomment//it is used to keep track of the score of the player
    // this.score = 9423;//comment//it is used to keep track of the score of the player
    //it is a property of the component object and it is used in the function hence this. is used


    //  this.gamearea = myGameArea; //not necessary for kyboard control

    this.width = width;
    this.height = height;
    // this.speed = 1;
    this.speedX = 0;//speed of the component in x and y direction , 0 at start
    this.speedY = 0;//speed of the component in x and y direction
    this.x = x;//initial coordinate
    this.y = y;






    this.update = function () {

        ctx = myGameArea.context;


        if (this.type == "text") {
            ctx.font = this.width + " " + this.height;
            ctx.fillStyle = color;
            ctx.fillText(this.text, this.x, this.y);
            // border of text to be white
            ctx.strokeStyle = "white";


            //to set zIndex of a component in canva
            ctx.globalCompositeOperation = this.zIndex; //necessary for zIndex





        }






        if (this.type == "image") {
            // else if (this.type == "image") { //ab image or background me se kuchh bhi ho drawImage will be activated

            ctx.drawImage(this.image, this.x, this.y, this.width, this.height);
            //we are comenting this for now so that dublicate myPiece not created at the time of rotation
            //
            //for now I am going to overlab the dublicate image without commenting it  but in main game , be careful with this




            //to set zIndex of a component in canva
            ctx.globalCompositeOperation = this.zIndex; //necessary for zIndex





        }





        if (type == "background") {
            // else if (type == "background") {//agar ye else if me raha toh pahle wala toh pahle hi execute go gaya h , issliya ye execute nahi ho payega , agar execute karna h vo bhi else if me , toh uppar se type == "background" hatana padega
            ctx.drawImage(this.image, this.x + this.width, this.y, this.width, this.height);

            //to adjust Opacity of image in canva
            ctx.globalAlpha = this.opacity; //necessary for opacity


            //to set zIndex of a component in canva
            ctx.globalCompositeOperation = this.zIndex; //necessary for zIndex








        }








        if (this == myObstacles[i] || this == myUpBtn || this == myDownBtn || this == myLeftBtn || this == myRightBtn) {
            // else {
            ctx.fillStyle = color;
            ctx.fillRect(this.x, this.y, this.width, this.height);//(x,y) is coordinate 


        };




        this.clicked = function () { //here this refers to variable using component //if blue component is there then it refers to blue compent height

            var myleft = this.x;//it refers to left edge of square in term of x distance 
            var myright = this.x + (this.width);//right edge x+30
            var mytop = this.y;//top edge
            var mybottom = this.y + (this.height);//bootom edge
            //circular edges
            var myleftcircle = this.x + (this.width / 2);
            var myrightcircle = this.x + (this.width / 2);


            var clicked = true;//at start maan lo fir setinval ke run karne se pahle hi clicked ki value update karlo , issliye hamne click check jus iske niche rakha h

            if ((mybottom < myGameArea.y) || (mytop > myGameArea.y) || (myright < myGameArea.x) || (myleft > myGameArea.x)) {
                //it means agar touch ya mouse iss area ke bahar h toh clicked ko false kar do nahi toh ye if condition false hoga aur clicked ki value true remain rahegi 
                clicked = false;
            }
            return clicked;
        }

        //myGameArea.y is refered to current position of mouse or click , matlab agar ye click uss blue region se bahar h to uss region ka clicked false rahega



        //   In the updateGameArea function, we take the neccessarry actions if one of the blue buttons is clicked:










        //for rotation

        //now if we want only to rotate the myGamePiece then we have to put in if condition

        ctx.save(); //it can be either insside or outside the if , effect of both same , ye sare component ko hi translate kar deta h initial position store karne ke liye hi save method use hota h.


        if (this == myGamePiece) {//The component myGamePiece is the only thing that is rotated:

            //now it makes only myGamePiece to be rotated


            ctx.save();  //save the current canvas context object: // either here or above required



            ctx.restore(); //When we are finished, we must restore the context object back to its saved position, using the restore method:




            // ab 0,0 wapas gameArea ke left top ko bola jayega 



        }


    }




    //Add a function in the component constructor, called newPos(), which uses the speedX and speedY properties to change the component's position.


    this.newPos = function () {



        this.x += this.speedX;//new cordinate of x for this component //it is responsible to update x value every time but every time it is adding this.speedX when no button is triggered but once any button will change it's value from zero then it will not stop by moving in that direction unless it is changed in it's dirction by another click but set value of x and y will only update by up , down ,left and right  


        //it's stop method is at last with clearmove() 

        this.y += this.speedY; //y sirf speedY se nahi badhta balki issme gravity speed bhi add karna padta h  //hit top me y = 0 st karenge aur speedX humne hare step me pahle hi 0 liya h toh top par effect show nahi ho paye ga to drop


        this.hitBottom();

        // Hit the Bottom
        // To prevent the red square from falling forever, stop the falling when it hits the bottom of the game area:

        //it is in newPos method funtion property



        this.hitTop();
        // Hit the Top
        // To prevent the red square from going up forever, stop the rising when it hits the top of the game area:


        //condition to check if this is refering to myGamePiece then only it gets executed

        //without condition it would have stopped the background move also
        if (this === myGamePiece) {
            this.hitLeft();
        }

        // Hit the Left
        // To prevent the red square from moving left forever, stop the movement when it hits the left edge of the game area:


        if (this === myGamePiece) {
            this.hitRight();
        }




    }


    this.hitBottom = function () {
        var rockbottom = myGameArea.canvas.height - this.height;//height of gamearea- height of component , for here component is myGamePiece , this means rockbottom stores the maximum value of freespace available to move vertically downward from top
        if (this.y > rockbottom) { //agar newPos myGamePiece ka jaida hoga toh usse baar baar update kar rockbottom ke barrabar kar dena 
            this.y = rockbottom;

            //   this.gravitySpeed = 0;


        }
    }




    this.hitTop = function () {
        if (this.y < 0) { //agar newPos myGamePiece ka jaida h


            //   this.y = 0;//top ko touch karne par y 0 ho jati h //it makes it stick there

            this.y = 0; //chipka rahega kyuki , speedX bhi 0 h abd only gravity can impact this 

            //Now if we want to come back towards ground afetr heating the top then we sh0uld use this code
            //   this.gravitySpeed = -this.gravitySpeed; //this will make it bounce back towards ground

            if (this.y == 0) {
                // this.gravitySpeed = -this.gravitySpeed;





                this.speedY = 0; //sabse pahle ye aur uppar nahi jane dega to top par strike karte hi ye aur aage badne ke capable nahi hoga  ye turant girega niche aur esliye bhi use karte h taki girte wakt esska value na badhe nahi to bottom hit karte wakt iski speed bahut jaida hogi aur ye wapas top par chala jayega 




            }


            // this.gravitySpeed = -(this.gravitySpeed * this.bounce); //this will make it
            //bounce back towards ground with some speed











        }
    }



    this.hitLeft = function () {
        if (this.x < 0) { //agar newPos myGamePiece ka jaida h
            this.x = 0; //yaha this ke karan background image bhi move nahi karega , issleye component specify is better option in case of left and right hit stop and for that put the condition in newPos to class hitLeft only when this refers to myGamePiece




        }
    }







    this.hitRight = function () {
        if (this.x > myGameArea.canvas.width - this.width) { //agar newPos my
            this.x = myGameArea.canvas.width - this.width; //right ko touch karne par
            //  this.speedX = 0;//right ko touch karne par x 0 ho jati h
        }
    }




















    this.crashWith = function (otherobj) {//when it is called then parameter otherobj is given with component object myObstacle
        //myGamePiece.crashWith(myObstacle)





        //below are all same as we did to identify myGamePiece position square edges

        var myleft = this.x;//left egde//this refers to object which is calling this component new //here "this" is for myGamePiece
        var myright = this.x + (this.width);//right edge of myGamePiece
        var mytop = this.y; //top edge og myGamePiece
        var mybottom = this.y + (this.height);//bottom edge og myGamePiece

        // myGamePiece.image.src = "wink-sweet-n-sassy.gif";


        //hum obstacles ka edge value store karna chahte h  , it is done in the same way as per above 

        var otherleft = otherobj.x;//otherobj.x is myObstacle.x //left edge of obstacle
        var otherright = otherobj.x + (otherobj.width); //rightt edge of obstacle
        var othertop = otherobj.y; //top edge of obstacle
        var otherbottom = otherobj.y + (otherobj.height); //bottom edge of obstacle  



        var crash = true;//just like we initiated clicked and then put it into if , to get the cureent value of crash
        // crash = true;//just like we initiated clicked and then put it into if , to get the cureent value of crash


        //if put the opposite colliding conditions as per requirement in if statement
        if ((mybottom < othertop) || (mytop > otherbottom) || (myright < otherleft) || (myleft > otherright)) {//myleft > otherright means left edge of obstacle greater hona chahiye 
            crash = false; //matlab crash nahi hua h 
        }





        return crash;//ye value ab // if (myGamePiece.crashWith(myObstacle)) {myGameArea.stop();  } else {....} //see in updateGameArea() //  me crash ki value return hogi , agar true hua to stop call hoga 







    }


}






function updateGameArea() {//The updateGameArea() function calls the clear() and the update() method.


    var x, height, gap, minHeight, maxHeight, minGap, maxGap;

    //myObstacles.length is array length 

    for (i = 0; i < myObstacles.length; i += 1) {//rhink i here the the obstacle array index

        if (myGamePiece.crashWith(myObstacles[i])) {

            // myGamePiece.image.src = "wink-sweet-n-sassy.gif";

            // mySound.pause();//ye niche wale ko play nahi honedega kyuki hamne pause jaise kuch decide hi nahi kiya h //instead of this write


            document.body.appendChild(document.createElement("div"));

            var div = document.body.lastChild;

            // div.innerHTML = '<a href="index.php"><video src="thanks for shopping.mp4" style="max-width: 95vw;max-height:50vh;position:fixed;left: 50%;top: 50%;transform: translate(-50%, -50%);" autoplay loop ></video></a>';
            // div.innerHTML = '<video src="thanks for shopping.mp4" style="max-width: 95vw;max-height:50vh;position:fixed;left: 50%;top: 50%;transform: translate(-50%, -50%);" autoplay loop ></video>';


            crashed = true;

            mySound.sound.pause();//now it works

            mySound.stop(); //now it works according to the requirement function we defined above

            mySoundCrash.play(); //works


            if (crashed) {

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



                if (EmailAddress != null || EmailAddress != undefined) {

                    var yourScore = document.getElementById("score").innerHTML;


                    // condition of creditEarned

                    var creditEarned;

                    if (yourScore > 10000) {
                        creditEarned = 20;
                    }
                    else if (yourScore > 15000) {
                        creditEarned = 50;
                    }
                    else if (yourScore > 20000) {
                        creditEarned = 80;
                    }
                    else if (yourScore > 30000) {
                        creditEarned = 100;
                    }
                    else if (yourScore > 100000) {
                        creditEarned = 500;
                    }
                    else if (yourScore > 500000) {
                        creditEarned = 1000;
                    }
                    else {
                        creditEarned = 0;
                    }





                    CreditScore = new XMLHttpRequest();


                    yourScore = { score: yourScore, creditEarned: creditEarned, EmailAddress: EmailAddress };



                    var yourScore = JSON.stringify(yourScore);

                    // alert(yourScore);

                    CreditScore.onload = function () {



                        if (this.status == 200) {

                            // alert(this.responseText);



                        }


                    }

                    CreditScore.open("POST", "PhenoxiGame.php");

                    CreditScore.setRequestHeader("Content-type", "application/x-www-form-urlencoded");


                    CreditScore.send("score=" + yourScore);

                }





                // setTimeout for this below code//
                setTimeout(function () {

                    var yourScore = document.getElementById("score").innerHTML;
                    // alert(yourScore);
                    // alert("Your score is " + yourScore);

                    document.body.appendChild(document.createElement("div"));

                    var div = document.body.lastChild;

                    if (yourScore > 10000) {
                        div.innerHTML = '<div id="scorecard"><videoe src="files acc/thanks for shopping.mp4" style="max-width: 95vw;max-height:50vh;position:fixed;left: 50%;top: 50%;transform: translate(-50%, -50%);z-index:5" autoplay loop  muted playsinline></videoe></div>';
                    }
                    else {
                        div.innerHTML = '<div id="scorecard"><video src="files acc/score more.mp4"style="max-width: 95vw;max-height:50vh;position:fixed;left: 50%;top: 50%;transform: translate(-50%, -50%);z-index:5" loop autoplay muted playsinline ></video></div>';


                    }

                    // we want to remove anchors parent element previous element
                    // var inicanvas = document.getElementById("scorecard").parentElement.previousElementSibling;
                    // //remove inicanvas
                    // inicanvas.remove();

                    // settimeout for this scorecard
                    setTimeout(function () {
                        // remove the scorecard
                        var scorecard = document.getElementById("scorecard");
                        scorecard.remove();
                    }, 5000);


                }, 2000);




            }







            // myGamePiece.image.src = "wink-sweet-n-sassy.gif"; 
            myGameArea.stop();

            //  mySound.play();//ye stop ke method ko overwrite kar dega to fir isse iss block se bahar rakhe


            // myGamePiece.image.src = "wink-sweet-n-sassy.gif"; 
            // document.getElementById("restart").style.display = "block";

            // document.getElementById("fast").style.display = "none";

            mySoundAfter.play();//to play the sound after playing 




            return; // crash true h to return 0 ho jayega updateGameArea se 
        }
    }












    myGameArea.clear();//clear is called//Why Clear The Game Area?
    // myGamePiece.image.src = "wink-sweet-n-sassy.gif";
    // It might seem unnecessary to clear the game area at every update. However, if we leave out the clear() method, all movements of the component will leave a trail of where it was positioned in the last frame:









    //for controlling both
    if (myGameArea.key && myGameArea.key == 37 && myGameArea.keys && myGameArea.keys[37]) {

        myGamePiece.speedX = -1;
        // set speedy =0
        myGamePiece.speedY = 0;//works



        // myGamePiece.x -= 1;
        // newPos();

        // myGamePiece.moveAngle = -1;//uncomment later


    }


    if (myGameArea.key && myGameArea.key == 39 && myGameArea.keys && myGameArea.keys[39]) {
        myGamePiece.speedX = 1;
        myGamePiece.speedY = 0;
        // myGamePiece.moveAngle = 1;////uncomment later
    }

    if (myGameArea.key && myGameArea.key == 38 && myGameArea.keys && myGameArea.keys[38]) {
        myGamePiece.speedY = -1;
        myGamePiece.speedX = 0;
        // myGamePiece.y -= 1;
        // myGamePiece.speed = 1;////uncomment later
    }//sara khel gravity kharab kar rahi h , 


    if (myGameArea.key && myGameArea.key == 40 && myGameArea.keys && myGameArea.keys[40]) {
        myGamePiece.speedY = 1;
        myGamePiece.speedX = 0;
        // myGamePiece.speed = -1;
    }





    if (myGameArea.x && myGameArea.y) { //dono true ho matlab x aur y ki value not equal to zero ho , matlab , cursor mygamearea ke andar hona chahiya tabhi ye blue clicks kaaam karenge

        if (myUpBtn.clicked()) {//clicked value ussne component method se uthaya h 
            // myGamePiece.y -= 1;//
            // myGamePiece.speedY = 0;

            myGamePiece.speedY = -1;
            myGamePiece.speedX = 0;


            // accelerate(-2);
            if (this.y <= 0) {
                hitTop();
            }


        }
        if (myDownBtn.clicked()) {
            // myGamePiece.y += 1;

            myGamePiece.speedY = 1;
            myGamePiece.speedX = 0;

            // accelerate(0.05);
        }
        if (myLeftBtn.clicked()) {
            // myGamePiece.x += -1;
            myGamePiece.speedX = -1;
            // set speedy =0
            myGamePiece.speedY = 0;//works
        }
        if (myRightBtn.clicked()) {
            // myGamePiece.x += 1;
            myGamePiece.speedX = 1;
            myGamePiece.speedY = 0;
        }
    }

    myUpBtn.update();//this( myUpBtn) ko update method me sent kar diya //    ctx.fillRect(this.x, this.y, this.width, this.height); //bante h , initially jo h vahi h 
    //ye update sirf uss blue component ko dikhte rahne ke lye h , kyuki vo baar baar repaint hota  , agar nahi use kiya toh blue component gayab ho jayega par uss area ka effect abhi bhi hoga 
    //uss area ke blank par bhi click karke dekh sakte h , sab kaam karega

    myDownBtn.update();
    myLeftBtn.update();
    myRightBtn.update();

    myGamePiece.update();//ab game piece bhi toh update hoga //  ctx.fillRect(this.x, this.y, this.width, this.height);










    //iske pahle ka updateGameArea ke to par content h

    myGameArea.frameNo += 1;//ye value current se update hoti h

    if (myGameArea.frameNo == 1 || everyinterval(150)) {//at start par frameNo 1 h  //and jab ((myGameArea.frameNo / n) % 1 == 0) , true value return karega jab ye 0 ke barabar hoga //((myGameArea.frameNo / n) % 1 == 0) will be true for all frameno except 1

        //150 n is passed , 
        x = myGameArea.canvas.width;
        //  y = myGameArea.canvas.height - 200
        minHeight = 20;//for obstacle t size not position 
        maxHeight = 200;

        height = Math.floor(Math.random() * (maxHeight - minHeight + 1) + minHeight); //return rsndom height // Math.random() gives random no. between 0 and 1 // maxHeight - minHeight  =  (200-20=180) //maxHeight - minHeight + 1 = 181 //Math.random() * (maxHeight - minHeight + 1) is almost parts of 181, like 0.2 part or 0.5 or 0.8 any no. possible hence we add minheight to keep height atleast 20
        // Math.floor() function returns the largest integer less than or equal to a given number 

        minGap = 50;//these gaps we are deciding for top obstacles from lower obstcles which we created at first 
        maxGap = 200;

        gap = Math.floor(Math.random() * (maxGap - minGap + 1) + minGap); //same way of logic we used above for bottom random height //maxGap - minGap + 1 = 200-50+1 = 151 , iska kuchh bhi part select hoga toh maximum value jo// Math.random() * (maxGap - minGap + 1) gives is 201 and min 50


        // x = myGameArea.canvas.width;
        // y = myGameArea.canvas.height - 200

        // myObstacles.push(new component(10, 200, "green", x, y)); 

        //eska matlab green obstacle game area ke bahar se banega , kyuki x ki value bilkul end tak h , means vo gamearea ke bahar se banega starting hone par . aur y coordinate gamearea ke height se 200 uppar hoga , matlab obstacle ka height 200 ke barabar h. 

        //used for all obstacle of same size    //200 is height and 10 is width , (x,y) is the cooordinate

        // myObstacles.push(new component(10, height, "green", x, 0));//for bottom obstacles 
        // myObstacles.push(new component(10, height, "black", x, 0));//for bottom obstacles 

        // alert(myGameArea.frameNo );
        // alert(maxGap);
 if(myGameArea.frameNo >="9272" && myGameArea.frameNo <="9572" || myGameArea.frameNo >="9872" && myGameArea.frameNo <="9972"){
        maxGap = 35;
        minGap = 30;
    // minHeight = 900;//for obstacle t size not position 
        // maxHeight = 400;
        height = Math.floor(Math.random() * (maxHeight - minHeight + 1) + minHeight);
         gap = Math.floor(Math.random() * (maxGap - minGap + 1) + minGap);
        }





        myObstacles.push(new component(10, height, "white", x, 0));//for bottom obstacles 


        // myObstacles.push(new component(10, x - height - gap, "green", x, height + gap)); //for top obstacles
        myObstacles.push(new component(10, x - height - gap, "white", x, height + gap)); //for top obstacles


     
    }

      




    for (i = 0; i < myObstacles.length; i += 1) {

        myObstacles[i].x += -1;//this is for position of green obstacle not for size of obstacle , size vahi rahega , bas ab vo left side move karega kyuki x axis decrease ho raha h.

        myObstacles[i].update(); //

        //setting z index of obstacle
        myObstacles[i].zIndex = 3; //this is for drawing obstacle on top



    }




    myScore.text = "SCORE: " + myGameArea.frameNo; //do obstacle ke gap ko paar karne par 150 score hoga
    // document.getElementById("score").innerHTML = "SCORE: " + myGameArea.frameNo;
    document.getElementById("score").innerHTML = myGameArea.frameNo;

    //At first this code will be written in updateGameArea() , above codes are written after feeling the needs for it

    myScore.update();



    myGamePiece.newPos();//  myGamePiece.x += 1;//Make it Move
    // To prove that the red square is being drawn 50 times per second, we will change the x position (horizontal) by one pixel every time we update the game area:

    //   myGamePiece.zIndex=3;


    myGamePiece.update();//update() method. is called to handle the drawing of the component.


    


}



function everyinterval(n) { //The everyinterval function returns true if the current framenumber corresponds with the given interval.
    /// if (myGameArea.frameNo == 1 || everyinterval(150)) , n=150
    if ((myGameArea.frameNo / n) % 1 == 0) { return true; }
    return false;//else part
}





function accelerate(n) {
    // myGamePiece.gravity = n;
} //it is in script dictly not in other fuctions



function moveup() {

    myGamePiece.speedY -= 1;//it will run for every updates on click means once it sets speedY to be -1 then it will be stored in speedY then as updateGameArea() is running with setinterval it will track speedY value and this value will be passed to  myGameArea.clear(); myGamePiece.newPos(); myGamePiece.update(); and once speedY is no more zero then its value will keep updating x by adding this speedY and hence once initiated will not stop due to newPos .

    myGamePiece.speedX = 0;


    // for image change on 
    myGamePiece.image.src = "files acc/wink-sweet-n-sassy.gif"; //works for called button controller



}


function movedown() {
    myGamePiece.speedY += 1;//same story as above will be here 

    myGamePiece.speedX = 0;
    // for image change on 
    myGamePiece.image.src = "files acc/wink-sweet-n-sassy.gif";  //works for called button controller
}

function moveleft() {
    myGamePiece.speedX -= 1;
    myGamePiece.speedY = 0;

    // for image change on 
    myGamePiece.image.src = "files acc/wink-sweet-n-sassy.gif";  //works for called button controller

}

function moveright() {
    myGamePiece.speedX += 1;
    myGamePiece.speedY = 0;


    // for image change on 
    myGamePiece.image.src = "files acc/wink-sweet-n-sassy.gif";  //works for called button controller
}



function move(dir) {
    myGamePiece.image.src = "files acc/wink-sweet-n-sassy.gif"; //move karte wakt ye image show ho
    if (dir == "up") { myGamePiece.speedY = -1; }
    if (dir == "down") { myGamePiece.speedY = 1; }
    if (dir == "left") { myGamePiece.speedX = -1; }
    if (dir == "right") { myGamePiece.speedX = 1; }
}




function clearmove() {


    myGamePiece.image.src = "files acc/emoji1.gif";  //works for all controllers

}




function sound(src) {
    this.sound = document.createElement("audio");
    this.sound.src = src;

    this.sound.setAttribute("preload", "auto");
    this.sound.setAttribute("controls", "none");

    this.sound.style.display = "none";
    document.body.appendChild(this.sound);


    this.play = function () {
        // this.sound.play();
    }
    this.stop = function () {
        this.sound.pause();//when you write mySound.pause() will not work but when we write mySound.stop() then it might work 
    }
}












