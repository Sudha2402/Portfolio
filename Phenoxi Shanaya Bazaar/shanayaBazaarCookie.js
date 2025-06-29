

        //javascript function for cookie

        function setCookie(cname, cvalue, exdays) {//setCookie("username", Sudha, 365);
            const d = new Date();
            console.log("d is : " + d)//d is : Fri Jul 26 2024 22:53:59 GMT+0530 (India Standard Time)
            d.setTime(d.getTime() + (exdays * 24 * 60 * 60 * 1000));
            console.log("new d is : " + d)//new d is : Sat Jul 26 2025 22:43:42 GMT+0530 (India Standard Time)//it is the time set for cookie //depends on parameter exdays
            let expires = "expires=" + d.toUTCString();//here d will be according to above expery and format changed to UTCString from GMT format
            console.log("expire data is : " + expires)//expire data is : expires=Sat, 26 Jul 2025 17:26:24 GMT
            document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";// document.cookie = "username=Sudha kumari; expires=Thu, 18 Dec 2024 12:00:00 UTC; path=/";
        }
    


    
    function getCookie(cname) {//takes"cname=username"
        let name = cname + "=";//username=//depend on paramerter cname//format of displaying cookie is being set
        let ca = document.cookie.split(';');//stores array of splited data
        for (let i = 0; i < ca.length; i++) {
            let c = ca[i];

            while (c.charAt(0) == ' ') {
                c = c.substring(1);//array index data of string is fetched and if index 0 of string is empty then it set substring from 1st index of string in c //overall it tries to remove white spaces and gaps in cookie after split before the actual character starts eg.           name=sudha
                //space in start needs to be removed to become name=sidha
            }
            if (c.indexOf(name) == 0) {//it takes as c.indexOf(username=)==0
                //If the cookie is found (c.indexOf(name) == 0), return the value of the cookie (c.substring(name.length, c.length).
                return c.substring(name.length, c.length);//it will get out of function //substring(start,end)//name is the key of cookie and if it's index is 0 means when all starting spaces is removed
            }
        }
        return "";//If the cookie is not found, return "".
        //final return value of function if inside return is not catched (or true)
    }

    //checkCookie is called in body on onload//it checks if a cookie is set.
    //it can be directly called
    function checkCookie(key) {
        let user = getCookie(`${key}`);
        if (user != "") {//checks the return value of getCookie function//if not null then it use the cookie
            // user = prompt(`Please enter your ${key}:`, "");
          //   alert("Welcome again " + user);//irritating use later on

        } else {//user is null
            user = prompt(`Please enter your ${key}:`, "");
            if (user != "" && user != null) {

                setCookie("username", user, 365);// setCookie("username", Sudha, 365);//setCookie is called


                document.getElementById("user").innerHTML= user;
            }//at user write name in prompt message //here user is the prompt value
        }
    }

    checkCookie("username");
    // checkCookie("age");
    // it will keep checking hence we will comment it and 



