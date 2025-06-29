
var EmailAddress;
EmailAddress = sessionStorage.getItem("EmailAddress");
// alert(EmailAddress);

if(EmailAddress === null || EmailAddress ===undefined){
// we can also get it from local storage
EmailAddress = localStorage.getItem("EmailAddress");
// alert(EmailAddress);
}

var email = { email: EmailAddress }
email = JSON.stringify(email);


oderedItems = new XMLHttpRequest();
oderedItems.onload = function () {
   
    document.getElementById("orderedlist").innerHTML = this.responseText;

    // alert("inserted");

}


// oderedItems.open("GET", "needs_db.php?custNumb=" + cusNum);
oderedItems.open("GET", "needs_db.php?email=" + email);


oderedItems.send();




var returnProducts=document.getElementsByClassName("returnOrder");

function initiateReturn(orderNumber, productCode) {
    // Open return page with order details

    window.location.href = `return_page.html?orderNumber=${encodeURIComponent(orderNumber)}&productCode=${encodeURIComponent(productCode)}`;
}

/*
CREATE TABLE returns (
    returnId INT AUTO_INCREMENT PRIMARY KEY,
    orderNumber int,
    productCode varchar(50),
    returnDate DATETIME DEFAULT CURRENT_TIMESTAMP,
    returnReason ENUM('quality_issue', 'damaged', 'part_missing', 'wrong_item', 'size_issue', 'color_issue'),
    returnOption ENUM('return', 'replace', 'refund'),
    description TEXT,
    photoPath VARCHAR(255),
    status ENUM('return_placed', 'pickup_scheduled', 'picked_up', 'return_processed', 'refund_processed', 'replacement_sent'),
    customerId INT,
    FOREIGN KEY (orderNumber) REFERENCES orders(orderNumber)
);
*/ 