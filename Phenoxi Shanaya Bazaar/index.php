<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="Phenoxi Shanaya Bazaar - Your premier ecommerce destination for fashion, accessories, home goods and more. Buy with intention, live with purpose.">
    <meta name="keywords" content="ecommerce, shopping, fashion, accessories, home decor, beauty products, India shopping">
    <title>Phenoxi Shanaya Bazaar</title>

    <!-- Preload critical resources -->
    <link rel="preload" href="/allPageCommonStyle.css" as="style">
    <link rel="preload" href="/style2.css" as="style">
    <link rel="preload" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css" as="style">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>

    <!-- CSS -->
    <link rel="stylesheet" href="/allPageCommonStyle.css">
    <link rel="stylesheet" href="/style2.css">
    <link href="https://fonts.googleapis.com/css2?family=Playwrite+CU:wght@100..400&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

    <!-- Preload scripts -->
    <link rel="preload" href="script.js" as="script">
    <link rel="preload" href="traceShanayaBazaar.js" as="script">
    <link rel="preload" href="shanayaBazaarCookie.js" as="script">
    <link rel="preload" href="allPageCommonScript.js" as="script">
    <link rel="preload" href="pagesnavigation.js" as="script">
</head>

<!-- <script src="script.js"></script> -->
<!-- write downward -->




<body onload="progressbar()" alink="660099" link="0000FF" vlink="" id="home" ondblclick="removeDropDown()">
    <!-- <body onprogress="progressbar()"> -->
    <!-- note that on progress is for video not for progrees bar , for progressbar ,use onload, onopen, onshow, and for unload , use onunload -->

    <!-- onload="checkCookie()" -->

    <div> <!--for header to be scrolled upto footer-->

        <!-- <a id="top"></a> -->
        <a title="top"></a>
        <!-- Header of this page -->

        <header class="header" id="headerIdCommon">

            <div class="headertitle" id="colorToggle">


                <div style="display: flex; justify-content: center;align-items:center;width:100vw">
                    <!-- <img class="titlelogo" src="title logo.png" alt="title logo"> -->
                    <!-- alt will create symbol if not present and no symbol if nothing written -->
                    <img class="titlelogo" src="files acc/title logo.png" alt="">

                    <div style="display: block;">


                        <h3>Phenoxi Shanaya Bazaar</h3>
                        <h5>Buy with intention, live with purpose</h5>
                    </div>


                </div>

                <div id="colorTheme">
                    <ul id="switcher" style="display: flex;align-items:center;">
                        <li id="blueButton" onclick="chBackcolor('rgb(184, 184, 244)');"></li>
                        <li id="greyButton" onclick="chBackcolor('rgb(128, 128, 128)');">
                        </li>
                        <li id="chocolateButton" onclick="chBackcolor('rgb(76, 38, 11)');"></li>
                        <li id="whiteButton" onclick="chBackcolor('white');"
                            style="border: 2px solid red; background-color: White;"></li>
                    </ul>

                    <!-- later on apply js here -->
                </div>

            </div>

            <div class="mobiletop">


                <div class="menuitems">
                    <!-- <a href="index.php" class="topmenu underlineremover home">Home</a> -->
                    <a href="http://localhost:3000/index.php" class="topmenu underlineremover home">Home</a>
                    <!-- <a href="about.html" class="topmenu underlineremover about">About</a> -->
                    <a href="http://localhost:3000/about.html" class="topmenu underlineremover about">About</a>
                    <!-- <a href="contact.html" class="topmenu  underlineremover contact">Contact</a> -->
                    <a href="http://localhost:3000/contact.html" class="topmenu  underlineremover contact">Contact</a>
                    <!-- <a href="need.html" class="topmenu underlineremover needs">Needs</a> -->
                    <a href="http://localhost:3000/need.html" class="topmenu underlineremover needs">Needs</a>
                    <!-- <a href="help.html" class="topmenu underlineremover help">Help</a> -->
                    <a href="http://localhost:3000/help.html" class="topmenu underlineremover help">Help</a>
                    <!-- <a href="login.html" class="topmenu underlineremover">Login</a> -->
                    <!-- <a href="animatedLogin.html" class="topmenu underlineremover"> -->
                    <a href="http://localhost:3000/HTMLGame.html" class="topmenu underlineremover">
                        <p>Play/Win</p>
                        <!-- <img src="files acc/logo_enhanced.png" height="10px"></img> -->
                    </a>
                    <a href="http://localhost:3000/animatedLogin.html" class="topmenu underlineremover">
                        <p class="loginCollapsed">Login</p>
                    </a>
                </div>



                <div class="headerinputs">

                    <img src="files acc/logo_enhanced.png" alt="" id="shanayabazaar">
                    <div class="optioninputbox">
                        <select class="boxstyling" id="mySelect" onchange="myFunctionOnChange()"
                            onhashchange="myFunctiononhashchange()">
                            <option value="allCategory">All</option>
                            <option value="women">Women</option>
                            <option value="men">Men</option>
                            <option value="kids">Kids</option>
                            <option value="beautyHealth">Beauty and Health</option>
                            <option value="accessories">Accessories</option>
                            <option value="homeGarden">Home and Garden</option>




                        </select>


                        <form name="searchProduct" >
                            <div class="searchbox boxstyling" >


                                <!-- <input type="text" name="searchProductEnteredbyTyping" placeholder="Search..." class=""
                                    class="truncate" type="search" autocomplete="off" spellcheck="false" role="combobox"
                                    aria-controls="matches" aria-expanded="false" aria-live="polite"> -->


                                <!-- <input type="text" name="searchProductEnteredbyTyping" placeholder="Search..."
                                    id="myInput" onkeyup="filterFunction()" onclick="myDropdownOpen()" class="dropbtn"
                                    type="search" autocomplete="off" spellcheck="false" role="combobox"
                                    aria-controls="matches" aria-expanded="false" aria-live="polite" onblur="removeDropDown()" > -->
                                <input type="text" name="searchProductEnteredbyTyping" placeholder="Search..."
                                    id="myInput" onkeyup="filterFunction()" onclick="myDropdownOpen()" class="dropbtn"
                                    type="search" autocomplete="off" spellcheck="false" role="combobox"
                                    aria-controls="matches" aria-expanded="false" aria-live="polite" ondblclick="removeDropDown()"
                                    
                                    >

                                <button class="search" onclick="searchEnteredProduct(),removeDropDown()"><i class="fa  fa-search"
                                        type="submit"></i></button>

                            </div>


                            <!-- <div id="myDropdownSearch" class="dropdownSearch-content" onclick="removeDropDown()"> -->
                            <div id="myDropdownSearch" class="dropdownSearch-content">
                                <!-- <p >About</p>
                                <p >login</p>
                                <p >Blog</p>
                                <p >Contact</p>
                                <p >Custom</p>
                                <p>Support</p> -->
                                <p>Women</p>
                                <p>Men</p>
                                <p>kids</p>
                                <p>Beauty and health</p>
                                <p>Accessories</p>
                                <p>home and kitchen</p>


                            </div>
                        </form>
                    </div>

                </div>

            </div>



            <div id="offline1" class="mahalootdesclaimer">




                <div class="mahalootscrollingsection ">




                    <p>Welcome to Maha loot, your go-to destination for all things fabulous! Step into a world of style
                        and
                        savings with our wide range of products. Shop now and stand a chance to win big - one lucky
                        customer
                        walks away with a Rs 1001 coupon every day! Don't miss out on this exciting opportunity to shop
                        and
                        win with Maha loot. Start browsing now and treat yourself to something special!</p>
                </div>
            </div>





        </header>




        <!-- Loading/refresh page -->
        <div class="progressbar" onprogress="progressbar()"> </div>

        <!-- <br> -->

        <div id="Welcome">

            <div> Welcome
                <p id="user" style="color: aqua;font-size: medium;font-weight: bolder;">......... </p> to Shanaya
                Bazaar.
            </div>

            <p class="icon">
                <!-- <a href="cart.html"> <i class="fa fa-shopping-cart"></i></a> -->
                <a href="http://localhost:3000/cart.html"> <i class="fa fa-shopping-cart visitCart"></i></a>

                <!-- <a href="animatedLogin.html"> -->
                <a href="http://localhost:3000/animatedLogin.html">
                    <!-- <img class="profileImage profileBackground"  style="height: 25px;width:25px"> 
                      -->

                    <i class="fa fa-user loginCollapsed " aria-hidden="true"></i>



                </a>


            </p>
            <div class="loginHoveredDetails">



                <form class="loginDetailOfUser" method="POST" action="" enctype="multipart/form-data">

                    <input type="text" name="hiddenCustomerNumber" class="CustomerNumber" style="display: none;" />
                    <h3 class="userName">Name</h3>
                    <div>
                        <img class="profileImage profileBackground">
                        <br>
                        <!-- Profile -->
                    </div>
                    <div class="profilePhotoSet">

                        <h6>Customize Profile</h6>

                        <?php include 'uploadProfileImage.php'; ?>
                        <!-- either we can use include or write full php code here -->

                        <input type="file" name="uploadfile" onchange="getFileData(this);"></input>


                        <!-- <input style="cursor: pointer;display: none;color: aqua;" name="submit">
                        <span>&#9977;</span> Upload</input> -->
                        <input style="cursor: pointer;display: none;color: aqua;" type="submit" name="submit"></input>


                    </div>

                    <!-- add the gallery or storage folder here or apply camera -->

                    <p class="emailOfThisUser">Email : </p>
                    <h6>Highest Score : <p class="score"></p>
                    </h6>
                    <h6>Win Amount : &#8377;<p class="credit"></p>
                    </h6>


                    <br>
                    <!-- <a href="animatedLogin.html"> -->
                    <a href="http://localhost:3000/animatedLogin.html">
                        <button type="button">Switch User</button>
                    </a>

                </form>


            </div>


            <div class="clickedReviewImg" style="display: none;">
                <button type="button" class="cuttab" onclick="cutImgbutton(this)">✖</button>
                <img src="" class="imgOpener"
                    style="height:90vh;width:100vw;max-width:428px;position:fixed;top: 50%;left: 50%;transform: translate(-50%, -50%);z-index:3" />
            </div>




        </div>

        <div class="topcategoryProduct">

            <div class="topcategoryProductOption">
                <button type="button" class="leftscrollsmall" onclick="leftscrollBut(this)">&lt;</button>
                <button type="button" class="rightscrollsmall" onclick="righttscrollBut(this)">&gt;</button>

                <!-- <div class="topcategoryProductOptionBox">
                    <a href="#"> <img src="">
                        <p>1</p>
                    </a>
                </div> -->

                <div class="topcategoryProductOptionBox">
                    <span> <img src="files acc/lahenganb.png" alt="">
                        <p>Women</p>
                    </span>

                </div>

                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/accessories/footwear/Patent Leather Heel Sandals/colors option/peach/tggz6_512.png"
                            alt="">
                        <p>footwear</p>
                    </span>

                </div>

                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/accessories/handbags/Graceful Stylish Slingbags Luxury High Quality PU Leather Women Shoulder Bag/colors option/light green/main.png">
                        <p>handbags</p>
                    </span>

                </div>

                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/beauty and health/makeup/7-in-1-cosmetics-bottle Catelog - 250208111013/7-in-1-cosmetics-bottle2-1714370462.jpg">
                        <p>Costmetics</p>
                    </span>

                </div>

                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="/product/beauty and health/health care/Relax Spin Tone Body Full Body Massager Electric Machine with 3 Massage Heads for Pain Relief/relax-spin-tone-body-full-body-m.png"
                            alt="">
                        <p>Relax</p>
                    </span>

                </div>

                <div class="topcategoryProductOptionBox">
                    <span> <img src="product/gifts/Artificial Red Rose 24K Gold Plated/colors option/red/anzmz_512.png"
                            alt="">
                        <p>Gift</p>
                    </span>

                </div>

                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/home and kitchen/daily use/Foldable-Mini-Capsule-Umbrella Catelog - 250208021353/Foldable-Mini-Capsule-Umbrella-1720498695 Main.jpg"
                            alt="">
                        <p>home</p>
                    </span>

                </div>

                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/kids/girl wear/Stylish Partywear Multicolor Cotton Girls Frocks Dresses/colors option/brown/g3gkk_512.png"
                            alt="">
                        <p>kids</p>
                    </span>

                </div>

                <div class="topcategoryProductOptionBox">
                    <span> <img src="product/men/men.jpg" alt="">
                        <p>men</p>
                    </span>

                </div>

                <div class="topcategoryProductOptionBox">
                    <span>
                        <!-- <img
                            src="product/women/bottom wear/Anara Fashion Women Solid Bell Bottoms Black Trousers Pants/colors option/black/rj4nc_512.png"
                            alt=""> -->


                        <img src="product/women/bottom wear/Anara Fashion Women Solid Bell Bottoms Black Trousers Pants/colors option/black/rj4nc_512.png"
                            alt="">
                        <p>bottomwear</p>
                    </span>

                </div>
                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/women/ethnic wear/kurta sets/Pakistani Suit  Women Kurta Pair/colors option/green/main.png"
                            alt="">
                        <p>kurta_set</p>
                    </span>

                </div>
                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/women/ethnic wear/kurtis/Embroidery Gaithering Anarkali kurtis/colors option/maroon/spnia_512.png"
                            alt="">
                        <p>kurtis</p>
                    </span>

                </div>
                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/women/ethnic wear/saree/Two-Tone Georgette Saree With Blouse/colors option/grey/xguqx_512.png"
                            alt="">
                        <p>saree</p>
                    </span>

                </div>
                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/women/ethnic wear/saree/Banarsi/banarasi saree/colors option/green/fufrj_512.png"
                            alt="">
                        <p>Banarsi</p>
                    </span>

                </div>
                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/women/top wear/White embroidery short top/colors option/white/qi2ap_512.png"
                            alt="">
                        <p>top</p>
                    </span>

                </div>
                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/women/top wear/latest trending classic check shirt and top/colors option/black/main.png"
                            alt="">
                        <p>trendy</p>
                    </span>

                </div>
                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/home and kitchen/kitchen and appliances/Electric Capsule Cutter Grinder Machine Kitchenware/Electric-Capsule-Cutter-Grinde- Main.jpg"
                            alt="">
                        <p>Kitchen</p>
                    </span>

                </div>
                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/beauty and health/health care/Earpick-Cleaner-Tool-Set-Beauty-Mackup-Tool Catelog - 250207090729/Earpick-Cleaner-Tool-Set-Main.jpg"
                            alt="">
                        <p>Accesories</p>
                    </span>

                </div>
                <div class="topcategoryProductOptionBox">
                    <span> <img
                            src="product/men/men accessories/sports shocks/SPORTS SOCKS FOR MEN 12 PAIR/colors option/20gjn_512.png"
                            alt="">
                        <p>Shocks</p>
                    </span>

                </div>



            </div>
        </div>


        <br>

        <!-- <video src="welcome to shanaya bazaar.mp4" autoplay loop style="max-width: 95vw;max-height:50vh;position:fixed;transform: translate(-50%, -50%);z-index:5"> -->


        <div class="mobilepopover">
            <div class="popover" id="surpriseSection">
                <button type="button" class="cuttab" onclick="cutbutton()">&#10006;</button>

                <!-- <a href="index.php"><img src="magasalebanner.png" alt="banner"></a> -->
                <!-- <span onclick='document.getElementById("mahaloot").scrollIntoView({ behavior: "smooth", block: "end" });
                this.parentElement.parentElement.style.display="none"'>
                    <img src="magasalebanner.png" alt="banner">
                </span> -->

                <span onclick='document.getElementById("mahaloot").scrollIntoView({ behavior: "smooth", block: "end" });
                this.parentElement.parentElement.style.display="none"'>




                    <!-- <video src="welcome to shanaya bazaar.mp4" autoplay loop style="max-width: 95vw;max-height:50vh;position:fixed;left: 50%;top: 50%;transform: translate(-50%, -50%);z-index:5"> -->
                    <!-- <video src="welcome to shanaya bazaar.mp4" autoplay muted controls playsinline> -->
                    <video src="files acc/welcome to shanaya bazaar.mp4" autoplay muted playsinline loop>
                        <!-- autoplay and muted works together otherwise it will be a paused video -->




                        <!-- it's not looping -->
                        <!-- <source src="welcome to shanaya bazaar.mp4" type="video/mp4" /> -->





                </span>

            </div>
        </div>



        <main class="bannersection">

            <div class="banner">






                <span class="mahaloot"><img src="files acc/magasalebanner.png" alt="banner" class="bannerphoto mobilebanner"></span>
               
                <span class="women"><img src="files acc/Fashion Sale Banner Post - Made with PosterMyWall.jpg"
                        alt="banner" class="bannerphoto mobilebanner"></span>
                        
                <!-- <span class="women"><img src="files acc/1500x375_Nayi-wali-hindi._CB546793321_.jpg"
                        alt="banner" class="bannerphoto mobilebanner"></span> -->
                        
                <!-- <a href="about.html"><img src="banner3.png" alt="banner" class="bannerphoto mobilebanner"></a> -->
                <span class="men"><img src="files acc/Men's Wear.jpg" alt="banner"
                        class="bannerphoto mobilebanner"></span>
                <span class="kids"><img src="files acc/kids wear.jpg" alt="banner"
                        class="bannerphoto mobilebanner"></span>
                <span class="beautyHealth"><img src="files acc/Health and Beauty.jpg" alt="banner"
                        class="bannerphoto mobilebanner"></span>
                <span class="homeGarden"><img src="/files acc/home and kitchen.jpg" alt="banner"
                        class="bannerphoto mobilebanner"></span>
            </div>

            <br>

            <!-- <div class="swap" onclick="pauseslide()" > -->
            <div class="swap">

                <div class="swapslide" id="swapslide1" onclick="openBanner1()"> </div>
                <div class="swapslide" id="swapslide2" onclick="openBanner2()"> </div>
                <div class="swapslide" id="swapslide3" onclick="openBanner3()"> </div>
                <div class="swapslide" id="swapslide4" onclick="openBanner4()"> </div>
                <div class="swapslide" id="swapslide5" onclick="openBanner5()"> </div>
                <div class="swapslide" id="swapslide6" onclick="openBanner6()"> </div>

            </div>
            <section>
                <!-- <h3>Top Products</h3> -->
                <div class="gridSectionContainer" id="">

                    <div class="gridSection">
                        <div class="colgrid1">

                            <h4>Most popular</h4>
                            <span> <img
                                    src="product/women/ethnic wear/lahenga/Solid Semi Stitched Lehenga Choli/colors option/rama/Screenshot 2025-02-10 214918.png"
                                    alt="" class="gridbigimg"></span>

                            <span> <img
                                    src="product/accessories/footwear/Patent Leather Heel Sandals/colors option/peach/tggz6_512.png"
                                    alt="" class="gridsmallimg"></span>
                            <span> <img
                                    src="product/women/top wear/latest trending classic check shirt and top/colors option/black/main.png"
                                    alt="" class="gridsmallimg"></span>

                            <span> <img
                                    src="product/gifts/Artificial Red Rose 24K Gold Plated/colors option/red/anzmz_512.png"
                                    alt="" class="gridsmallimg"></span>

                        </div>

                        <div class="colgrid2">
                            <div class="smallgridContainer">


                                <h4>New arrivals</h4>
                                <div class="smallgrid">

                                    <div>
                                        <span> <img
                                                src="product/home and kitchen/daily use/Foldable-Mini-Capsule-Umbrella Catelog - 250208021353/Foldable-Mini-Capsule-Umbrella-1720498695 Main.jpg"
                                                alt="" class="smallsquareimg"></span>
                                    </div>

                                    <div>
                                        <span> <img
                                                src="product/women/ethnic wear/saree/satin silk saree with Blouse/colors option/violet/main.png"
                                                alt="" class="smallsquareimg"></span>
                                    </div>

                                    <div>

                                        <span> <img
                                                src="product/women/top wear/White embroidery short top/colors option/white/qi2ap_512.png"
                                                alt="" class="smallsquareimg"></span>
                                    </div>
                                    <div>
                                        <span> <img
                                                src="product/women/western wear/Women Floral V-neck Multicolor Dresses/colors option/black/nm3lu_512.png"
                                                alt="" class="smallsquareimg"></span>
                                    </div>
                                </div>


                            </div>

                            <div class="gridrowcontainer">


                                <div class="gridrow">
                                    <div class="gridrowimagecontaianer">
                                        <span> <img
                                                src="product/women/ethnic wear/saree/Banarsi/banarasi saree/colors option/green/fufrj_512.png"
                                                alt="" class="gridrowimage"></span>
                                    </div>

                                    <div>
                                        <h4>New this week</h4>
                                    </div>


                                </div>
                            </div>



                        </div>
                        <div class="colgrid3">
                            <div class="gridrowcontainer">


                                <div class="gridrow">
                                    <div class="gridrowimagecontaianer">
                                        <span> <img
                                                src="product/women/ethnic wear/kurta sets/Pakistani Suit  Women Kurta Pair/colors option/green/main.png"
                                                alt="" class="gridrowimage"></span>
                                    </div>

                                    <div>
                                        <h4>Deals on best seller</h4>
                                    </div>


                                </div>
                            </div>

                            <div class="smallgridContainer">

                                <span> <img
                                        src="product/women/ethnic wear/saree/Two-Tone Georgette Saree With Blouse/colors option/grey/xguqx_512.png"
                                        alt="" class="gridsquareimage">
                                </span>


                                <h4>affordable products for the day</h4>



                            </div>

                        </div>
                        <div class="colgrid4">

                            <h4>Trending</h4>
                            <span> <img
                                    src="product/kids/girl wear/Girls Silk Frocks Dresses/colors option/aqua green/main.webp"
                                    alt="" class="gridbigimg"></span>

                            <span> <img
                                    src="product/kids/girl wear/roshani frock blue/colors option/blue/main.webp"
                                    alt="" class="gridsmallimg"></span>
                            <span> <img
                                    src="product/kids/girl wear/Baby Girls trendy western Dress/colors option/red/main.webp"
                                    alt="" class="gridsmallimg"></span>

                            <span> <img
                                    src="product/gifts/Artificial Red Rose 24K Gold Plated/colors option/red/anzmz_512.png"
                                    alt="" class="gridsmallimg"></span>

                        </div>

                    </div>



            </section>
        </main>



        <div class="categoryoptions searchOutBlock">

            <h4>searchOut</h4>

            <div class="completeonecategory">
                <div id="searchOut">

                    <!-- <button type="button" class="leftscroll" onclick="this.scrollLeft +=50 ">&lt;</button> -->

                    <button type="button" class="leftscroll" onclick="leftscrollBut(this)">&lt;</button>
                    <button type="button" class="rightscroll" onclick="righttscrollBut(this)">&gt;</button>



                    <a href="index.php" class="underlineremover">
                        <div class="completeproductbox">
                            <img src="files acc/magasalebanner.png" alt="productimg" class="productimg" />

                            <div class="productheighlight">

                                <h4>&#8377;<span class="priceOfProduct">Rs. 199</span></h4>
                                <p class="productCode" style="display: none;"></p>
                                <h5 class="productName">Shanaya bazaar</h5>
                            </div>
                        </div>
                    </a>


                </div>
            </div>

        </div>





        <div class="categoryoptions searchOutMoreBlock">

            <h4>searchOutMore</h4>

            <div class="completeonecategory">
                <div id="searchOutMore">

                    <!-- <button type="button" class="leftscroll" onclick="this.scrollLeft +=50 ">&lt;</button> -->

                    <button type="button" class="leftscroll" onclick="leftscrollBut(this)">&lt;</button>
                    <button type="button" class="rightscroll" onclick="righttscrollBut(this)">&gt;</button>

                    <a href="index.php" class="underlineremover">
                        <div class="completeproductbox">
                            <img src="files acc/magasalebanner.png" alt="productimg" class="productimg" />

                            <div class="productheighlight">

                                <h4>&#8377;<span class="priceOfProduct">Rs. 199</span></h4>
                                <p class="productCode" style="display: none;"></p>
                                <h5 class="productName">Shanaya bazaar</h5>
                            </div>
                        </div>
                    </a>

                </div>
            </div>

        </div>



        <div class="categoryoptions">

            <h4>Women</h4>

            <div class="completeonecategory">
                <div id="women">

                    <!-- <button type="button" class="leftscroll" onclick="this.scrollLeft +=50 ">&lt;</button> -->

                    <button type="button" class="leftscroll" onclick="leftscrollBut(this)">&lt;</button>
                    <button type="button" class="rightscroll" onclick="righttscrollBut(this)">&gt;</button>

                    <a href="index.php" class="underlineremover">
                        <div class="completeproductbox">
                            <img src="files acc/magasalebanner.png" alt="productimg" class="productimg" />

                            <div class="productheighlight">

                                <h4>&#8377;<span class="priceOfProduct">Rs. 199</span></h4>
                                <p class="productCode" style="display: none;"></p>
                                <h5 class="productName">Shanaya bazaar</h5>
                            </div>
                        </div>
                    </a>



                </div>
            </div>

        </div>












        <div class="categoryoptions">
            <h4>men</h4>
            <div class="completeonecategory">
                <div id="men">
                    <button type="button" class="leftscroll" onclick="leftscrollBut(this)">&lt;</button>
                    <button type="button" class="rightscroll" onclick="righttscrollBut(this)">&gt;</button>

                    <a href="index.php" class="underlineremover">
                        <div class="completeproductbox">
                            <img src="files acc/magasalebanner.png" alt="productimg" class="productimg" />

                            <div class="productheighlight">

                                <h4>&#8377;<span class="priceOfProduct">Rs. 199</span></h4>
                                <p class="productCode" style="display: none;"></p>
                                <h5 class="productName">Shanaya bazaar</h5>
                            </div>
                        </div>
                    </a>







                </div>
            </div>

        </div>









        <div class="categoryoptions">
            <h4>Kids</h4>
            <div class="completeonecategory">
                <div id="kids">
                    <button type="button" class="leftscroll" onclick="leftscrollBut(this)">&lt;</button>
                    <button type="button" class="rightscroll" onclick="righttscrollBut(this)">&gt;</button>

                    <a href="index.php" class="underlineremover">
                        <div class="completeproductbox">
                            <img src="files acc/magasalebanner.png" alt="productimg" class="productimg" />

                            <div class="productheighlight">

                                <h4>&#8377;<span class="priceOfProduct">Rs. 199</span></h4>
                                <p class="productCode" style="display: none;"></p>
                                <h5 class="productName">Shanaya bazaar</h5>
                            </div>
                        </div>
                    </a>





                </div>
            </div>

        </div>



        <section>
            <h3>Personal Cares</h3>
            <div class="gridSectionContainer" id="beautyHealth">

                <div class="gridSection">
                    <div class="colgrid1">

                        <h4>Most popular</h4>
                        <span> <img
                                src='product/beauty and health/health care/Relax Spin Tone Body Full Body Massager Electric Machine with 3 Massage Heads for Pain Relief/relax-spin-tone-body-full-body-m.png'
                                alt="" class="gridbigimg"></span>

                        <span> <img
                                src="product/beauty and health/health care/Electric-Hot-Water-Bag-for-Pain-Relief Catelog - 250208125716/Electric-Hot-Water-Bag-for-Pai1-1678772917.jpg"
                                alt="" class="gridsmallimg"></span>
                        <span> <img
                                src="product/beauty and health/health care/Relax Spin Tone Body Full Body Massager Electric Machine with 3 Massage Heads for Pain Relief/tm9zc_512.png"
                                alt="" class="gridsmallimg"></span>
                        <span> <img
                                src="product/beauty and health/health care/Head-Massager-for-Pain-Relief Catelog - 250207112506/Head-Massager-for-Pain-Relief6-1678773522.jpg"
                                alt="" class="gridsmallimg"></span>


                    </div>

                    <div class="colgrid2">
                        <div class="smallgridContainer">


                            <h4>New arrivals</h4>
                            <div class="smallgrid">

                                <div>
                                    <span> <img
                                            src="product/beauty and health/health care/Electric Velvet heating bags for Pain Relief Personal Care/Electric-Velvet-heating-bags-f6-1678777060.jpg"
                                            alt="" class="smallsquareimg
                            "></span>
                                </div>

                                <div>
                                    <span> <img
                                            src="product/beauty and health/health care/Earpick-Cleaner-Tool-Set-Beauty-Mackup-Tool Catelog - 250207090729/Earpick-Cleaner-Tool-Set-Main.jpg"
                                            alt="" class="smallsquareimg
                        "></span>
                                </div>

                                <div>

                                    <span> <img
                                            src="product/beauty and health/health care/Head-Massager-for-Pain-Relief Catelog - 250207112506/Head-Massager-for-Pain-Main.jpg"
                                            alt="" class="smallsquareimg"></span>
                                </div>
                                <div>
                                    <span> <img
                                            src="product/beauty and health/skin care/The Derma Co Kojic Acid Face Serum/main.png"
                                            alt="" class="smallsquareimg"></span>
                                </div>
                            </div>


                        </div>

                        <div class="gridrowcontainer">


                            <div class="gridrow">
                                <div class="gridrowimagecontaianer">
                                    <span> <img
                                            src="product/beauty and health/makeup/7-in-1-cosmetics-bottle Catelog - 250208111013/7-in-1-cosmetics-bottle-1714370461 Main.jpg"
                                            alt="" class="gridrowimage"></span>
                                </div>

                                <div>
                                    <h4>New this week</h4>
                                </div>
                            </div>
                        </div>



                    </div>
                    <div class="colgrid3">
                        <div class="gridrowcontainer">


                            <div class="gridrow">
                                <div class="gridrowimagecontaianer">
                                    <span> <img
                                            src="product/beauty and health/skin care/Matico Brightening Whitening Vitamin C Face Serum/main.png"
                                            alt="" class="gridrowimage"></span>
                                </div>

                                <div>
                                    <h4>Deals on best seller</h4>
                                </div>


                            </div>
                        </div>

                        <div class="smallgridContainer">

                            <span> <img
                                    src="product/beauty and health/skin care/3 In 1 Electric Face Massager/pgigs_512.png"
                                    alt="" class="gridsquareimage">
                            </span>


                            <h4>affordable products for the day</h4>



                        </div>

                    </div>
                    <div class="colgrid4">

                        <h4>Trending</h4>
                        <span> <img
                                src="product/beauty and health/health care/Electric-Hot-Water-Bag-for-Pain-Relief Catelog - 250208125716/Electric-Hot-Water-Bag-for-Pai3-1678772918.jpg"
                                alt="" class="gridbigimg"></span>

                        <span> <img
                                src="product/kids/girl wear/roshani frock blue/colors option/blue/main.webp"
                                alt="" class="gridsmallimg"></span>
                        <span> <img
                                src="product/kids/girl wear/Baby Girls trendy western Dress/colors option/red/main.webp"
                                alt="" class="gridsmallimg"></span>

                        <span> <img
                                src="product/gifts/Artificial Red Rose 24K Gold Plated/colors option/red/anzmz_512.png"
                                alt="" class="gridsmallimg"></span>

                    </div>
                </div>



        </section>




        <section>
            <h3>Accessories</h3>
            <div class="gridSectionContainer" id="accessories">

                <div class="gridSection">
                    <div class="colgrid1">

                        <h4>Most popular</h4>
                        <span> <img
                                src="product/accessories/handbags/Beautiful Sling Bags for women and girls/colors option/white/main.png"
                                alt="" class="gridbigimg"></span>

                        <span> <img
                                src="product/accessories/footwear/Patent Leather Heel Sandals/colors option/black/ppzvq_512.png"
                                alt="" class="gridsmallimg"></span>
                        <span> <img
                                src="product/accessories/general products/Four Sided Folding Mirror/GPW0001-Four-Sided-Folding-Mirror.jpeg"
                                alt="" class="gridsmallimg"></span>
                        <span> <img
                                src="product/kids/girl wear/Baby Girls trendy western Dress/colors option/red/main.webp"
                                alt="" class="gridsmallimg"></span>
                                

                    </div>

                    <div class="colgrid2">
                        <div class="smallgridContainer">


                            <h4>New arrivals</h4>
                            <div class="smallgrid">

                                <div>
                                    <span> <img
                                            src="product/accessories/footwear/Patent Leather Heel Sandals/colors option/peach/tggz6_512.png"
                                            alt="" class="smallsquareimg
                            "></span>
                                </div>

                                <div>
                                    <span> <img
                                            src="product/beauty and health/health care/Earpick-Cleaner-Tool-Set-Beauty-Mackup-Tool Catelog - 250207090729/Earpick-Cleaner-Tool-Set-Main.jpg"
                                            alt="" class="smallsquareimg
                        "></span>
                                </div>

                                <div>

                                    <span> <img
                                            src="product/accessories/handbags/Graceful Stylish Slingbags Luxury High Quality PU Leather Women Shoulder Bag/colors option/white/main.png"
                                            alt="" class="smallsquareimg"></span>
                                </div>
                                <div>
                                    <span> <img
                                            src="product/women/women accessories/perfume/Ramsons - U R LOVELY Eau De Parfume/colors option/xqawd_512.png"
                                            alt="" class="smallsquareimg"></span>
                                </div>
                            </div>


                        </div>

                        <div class="gridrowcontainer">


                            <div class="gridrow">
                                <div class="gridrowimagecontaianer">
                                    <span> <img
                                            src="product/accessories/handbags/Graceful Stylish Slingbags Luxury High Quality PU Leather Women Shoulder Bag/colors option/pink/main.png"
                                            alt="" class="gridrowimage"></span>
                                </div>

                                <div>
                                    <h4>New this week</h4>
                                </div>


                            </div>
                        </div>



                    </div>
                    <div class="colgrid3">
                        <div class="gridrowcontainer">


                            <div class="gridrow">
                                <div class="gridrowimagecontaianer">
                                    <span> <img
                                            src="product/men/men accessories/sports shocks/SPORTS SOCKS FOR MEN 12 PAIR/colors option/2wzfz_512.png"
                                            alt="" class="gridrowimage"></span>
                                </div>

                                <div>
                                    <h4>Deals on best seller</h4>
                                </div>


                            </div>
                        </div>

                        <div class="smallgridContainer">

                            <span> <img
                                    src="product/women/women accessories/watch/Flowered Dial Megnet Watch/colors option/ssr1i_512.png"
                                    alt="" class="gridsquareimage">
                            </span>


                            <h4>affordable products for the day</h4>



                        </div>

                    </div>
                      <div class="colgrid1">

                            <h4>Most popular</h4>
                            <span> <img
                                    src="product/women/western wear/Women Floral V-neck Multicolor Dresses/colors option/white/nhjzm_512.png"
                                    alt="" class="gridbigimg"></span>

                            <span> <img
                                    src="product/women/bottom wear/Anara Fashion Women Solid Bell Bottoms Black Trousers Pants/colors option/black/de5it_512.png"
                                    alt="" class="gridsmallimg"></span>
                            <span> <img
                                    src="product/women/top wear/latest trending classic check shirt and top/colors option/black/main.png"
                                    alt="" class="gridsmallimg"></span>

                            <span> <img
                                    src="product/gifts/Artificial Red Rose 24K Gold Plated/colors option/red/anzmz_512.png"
                                    alt="" class="gridsmallimg"></span>

                        </div>

                </div>



        </section>

        <div class="categoryoptions">

            <h4>Home and Garden</h4>
            <div class="completeonecategory">
                <div id="homeGarden">

                    <button type="button" class="leftscroll" onclick="leftscrollBut(this)">&lt;</button>
                    <button type="button" class="rightscroll" onclick="righttscrollBut(this)">&gt;</button>

                    <a href="index.php" class="underlineremover">
                        <div class="completeproductbox">
                            <img src="files acc/magasalebanner.png" alt="productimg" class="productimg" />



                            <div class="productheighlight">

                                <h4>&#8377;<span class="priceOfProduct">Rs. 199</span></h4>
                                <p class="productCode" style="display: none;"></p>
                                <h5 class="productName">Shanaya bazaar</h5>
                            </div>
                        </div>
                    </a>



                </div>
            </div>

        </div>


















        <div class="shanayabazaarvideo">
            <h3>How Shanaya Bazaar adds values in your life</h3>
            <h5>Experience the transformational impact of Shanaya Bazaar on your life! Discover how it adds value and
                enhances your daily experiences in ways you never imagined. Watch the video now!</h5>
            <video src="/files acc/shanayabazaarvideo.mp4" controls>error
            </video>
        </div>






        <div>
            <h3>Ready for maha loot of the day</h3>
            <br>
            <h5>Get ready for the maha loot of the day. We have a wide range
                of products at discounted prices. Don't miss out on this amazing opportunity to save big!<br><br>Deal
                will off after 24:00:00</h5>









            <div class="categoryoptions">
                <h4 class="text-center" onclick="qSelectorAllHeadingCenter()" id="stickContent">first 5 lucky customers
                    90%
                    off on given
                    products.
                    <span id="time"></span>
                </h4>
                <div class="completeonecategory">
                    <div id="mahaloot">
                        <button type="button" class="leftscroll" onclick="leftscrollBut(this)">&lt;</button>
                        <button type="button" class="rightscroll" onclick="righttscrollBut(this)">&gt;</button>

                        <a href="index.php" class="underlineremover">
                            <div class="completeproductbox">
                                <img src="files acc/magasalebanner.png" alt="productimg" class="productimg" />

                                <div class="productheighlight">

                                    <h4>&#8377;<span class="priceOfProduct">Rs. 199</span></h4>
                                    <p class="productCode" style="display: none;"></p>
                                    <h5 class="productName">Shanaya bazaar</h5>
                                </div>
                            </div>
                        </a>




                    </div>
                </div>

            </div>



            <br>


            <p id="setTimeOutSurprise"> Hey, You will receive a bumper surprise ,Are you excited &#128516;

                <!-- <button onclick="mySurprise()">Yes</button>  <button onclick="noSurprise()">No</button></p> -->
                <button onclick="mySurprise()">Yes</button>
                <button onclick="noSurprise()">No</button>
            </p>
            <br>
            <!-- <h2 id="colorToggle">&#128264; Hurry up <button><a href="#"> Shop Now</a></button></h2> -->



            <!-- <br>
            <h3>You must need to be logged in <button class="HoverLogin" onmouseover="hoverLogin()"
                    onmouseout="hoverLoginClose()">login</button></h3>
            <br> -->
            <!-- it works but we don't need this -->











            <br>
            <h3 style="color: aqua; background-color: black;display: inline-block;" lang="en">Play and win discounts
                &#128516; &#128525; &#128522;</h3>
            <h2 style="display: inline-block;" lang="hi">खेलो और जीतो !!</h2>
            <br>
            <br>
            <a href="HTMLGame.html"><button style="background-color: indigo;">
                    <h3>Play the below game</h3>
                </button></a>
            <br>

            <!--             
            <div style="display: flex;align-items: center;">


                <button type="text" style="font-size: larger;margin: 5px 20px; " onmouseover="hoverPlay()"
                    onmouseout="hoverPlayClose()" onclick="playGameTabOpen()">Play</button>
                <p id="gameStatus">Your Game Status</p>
            </div> -->


          <!-- Suppose the div you want to iframe has the ID my-div on the source website located at https://example.com.

In the target website, you would add the following HTML code:

<iframe src="https://example.com?iframe-div=my-div" width="100%" height="500"></iframe> -->


                <!-- <iframe src="HTMLGame.html" width="500" height="270" style="overflow: hidden;"></iframe> -->
                <iframe scrolling="no" id="gameiframe" width="100%" src="HTMLGame.html" style="overflow: hidden;"></iframe>
                <!-- <iframe src="HTMLGame.html" id="gameFrame" style="display:none"></iframe> -->
               <!-- <div id="gamecanvas">
               </div> -->

      







            <br>
            <br>

            <div class="rateExperience">
                <h2>Rate Your Experience</h2>

                <div class="rate">
                    <!-- <h2 class="star1"> we have used it js but we made plan to change it-->

                    <!-- <div id="reviewOut">
                    <img src="/Animation - 1737808526862.gif" alt="Waiting for review">
                </div> -->

                    <div class="reviewOut">
                        <img src="/files acc/Animation - 1737808526862.gif" alt="Waiting for review">

                    </div>

                    <h2 class="stars">

                        <p class="star1">
                            <input type="radio" name="rate" value="1" ondblclick="star1()" onclick="displayReview()">
                            <label for="star1">1
                                <span id="star1"> &bigstar;</span> <br>
                            </label>
                        </p>
                        <p class="star2">
                            <input type="radio" id="star2" name="rate" value="2" onclick="displayReview()">
                            <label for="star2">2 &bigstar; &bigstar;<br></label>
                        </p>

                        <p class="star3">
                            <input type="radio" id="star3" name="rate" value="3" onclick="displayReview()">
                            <label for="star3">3 &bigstar; &bigstar; &bigstar;<br></label>
                        </p>

                        <p class="star4">
                            <input type="radio" id="star4" name="rate" value="4" onclick="displayReview()">
                            <label for="star4">4 &bigstar; &bigstar; &bigstar; &bigstar;<br></label>
                        </p>

                        <p class="star5">
                            <!-- <input type="radio" id="star5" name="rate" value="5" onclick="displayReview()" checked> -->
                            <input type="radio" id="star5" name="rate" value="5" onclick="displayReview()">
                            <label for="star5">5 &bigstar; &bigstar; &bigstar; &bigstar; &bigstar;</label>
                        </p>
                    </h2>
                </div>

                <button type="submit" onclick="submitExperience()"
                    style="margin: 3vh;padding: 10px;background-color: rgb(203, 56, 198);color: white;">Submit</button>

            </div>




        </div>

        <!-- <br>&bigstar; &bigstar; &bigstar; &bigstar; &bigstar;
        <br> &star;&star;&star;&star;&star; -->

        <div id="searchedOutput" style="display: none;
        position: fixed;
        bottom: 5vh;
        left: 50%;
transform: translateX(-50%);
        min-width: 30vw;
        max-width: 80vw;
        padding: 1vh;
        min-height: 5vh;
        max-height: 50vh;
        background-color: black;
        color: white;
        z-index: 10;
        text-align: center;
        align-items: center;
        justify-content: center;
        overflow-wrap: break-word;">

        </div>


        <br>
        <br>
        <br>



        <br>
        <br>






        <footer style="float: none;">
            <div id="footer">


                <section id="footer1">
                    <div>
                        <h3>Our Products</h3>
                        <p>Our products are made with love and care. We have a wide
                            range of products
                        </p>


                        <a href="index.php" class="underlineremover">
                            <p><img src="/files acc/title logo.png" alt="instagram logo" width="30"></img>Click here to
                                get the
                                best
                                deal of the day</p>
                            <h3>
                                <i class="fa fa-home"></i> Ready for maha loot of the day
                            </h3>
                        </a>

                        <a href="#"><i class="fa fa-twitter"></i></a>
                        <a href="#"><i class="fa fa-linkedin"></i></a>
                        <a href="#"><i class="fa fa-facebook"></i></a>


                    </div>

                    <a href="index.php#top">Go to the top</a>
                </section>
                <section id="footer2">
                    <h2>Follow Us</h2>
                    <a href="https://www.facebook.com/" class="underlineremover" target="_blank"><img
                            src="files acc/facebook.png" alt="
                " width="50" height="50"></a>
                    <a href="https://www.instagram.com/" class="underlineremover" target="_blank"><img
                            src="/files acc/instagram.png" alt="
                    " width="50" height="50"></a>
                    <a href="https://www.twitter.com/" target="_blank" class="underlineremover"><img
                            src="files acc/twitter.png" alt="
                        " width="50" height="50"></a>
                    <a href="https://www.youtube.com/" target="_blank" class="underlineremover"><img
                            src="files acc/youtube.jpeg" alt=" " width="40" height="40

                            "></a>

                    <div>
                        <h2>Address</h2>
                        <p>Address: Revtapur, Vijaynagar Chauraha, Nilmatha, Lucknow
                        </p>
                        <p>Phone: 9305483852</p>
                        <!-- <p>Email: <a href="https://mail.google.com/mail/u/0/#sent?compose=new"
                            class="underlineremover">sudhakumarichauhan24@gmail.com</a>
                    </p> -->
                        <!-- for direct linking
                      -->
                        <!-- <p>Email: <a href="mailto:sudhakumarichauhan24@gmail.com"
                        class="underlineremover">Sudha</a>
                </p> -->
                        <!-- To set even default values -->
                        <p>Email: <a href="mailto:sudhakumarichauhan24@gmail.com?subject=Feedback&body=Message"
                                class="underlineremover">Sudha</a>
                        </p>
                    </div>
                </section>


            </div>


        </footer>
        

 <!-- Scripts loaded at bottom -->
    <script src="script.js" defer></script>
    <script src="traceShanayaBazaar.js" defer></script>
    <script src="shanayaBazaarCookie.js" defer></script>
    <script src="allPageCommonScript.js" defer></script>
    <script src="pagesnavigation.js" defer></script>
    <script src="https://cdn.jsdelivr.net/npm/js-confetti@latest/dist/js-confetti.browser.js" defer></script>

    <!-- Structured data for SEO -->
    <!-- <script type="application/ld+json">
    {
        "@context": "https://schema.org",
        "@type": "WebSite",
        "name": "Phenoxi Shanaya Bazaar",
        "url": "https://phenoxi.com",
        "potentialAction": {
            "@type": "SearchAction",
            "target": "https://phenoxi.com/search?q={search_term_string}",
            "query-input": "required name=search_term_string"
        }
    }
    </script> -->


<!-- Added proper meta tags for SEO

Implemented resource preloading//The loading="preload" attribute is used to optimize website loading speed by instructing the browser to fetch a resource in advance, before it's actually needed. This is particularly helpful for critical resources that might be discovered late in the page parsing process, such as fonts or images referenced within CSS files. By preloading these resources, the browser can start fetching them earlier, leading to a faster user experience and potentially improved Core Web Vitals metrics like First Contentful Paint and Largest Contentful Paint. 

Added structured data for search engines

Moved all scripts to bottom with defer//Scripts with the defer attribute will execute in the order in which they appear in the document. This attribute allows the elimination of parser-blocking JavaScript where the browser would have to load and evaluate scripts before continuing to parse.

Added lazy loading for iframe //Lazy-loading of <iframe> elements defers offscreen iframes from being loaded until the user scrolls near them. This saves data, speeds up the loading of other parts of the page, and reduces memory usage. As with lazy-loading for images, use the loading attribute to tell the browser you want to lazy-load an iframe.-->








</body>
</html>