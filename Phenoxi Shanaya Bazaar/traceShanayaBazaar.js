//activeElement




function myFunctionactive() {
    // this myFunctionactive() function need to called onload in body , or you can call it here directly
    var element = document.activeElement.tagName;


    var elementId = document.activeElement.id;



    // finally we have decided to use this
    console.log("active Element:" + element + " " + elementId);



}

myFunctionactive();



// to get current url
function getCurrentURL () {
    return window.location.href
  }

//   now function is being called
  const url = getCurrentURL()
  
  console.log("getCurrentURL ()     url : "+url);

