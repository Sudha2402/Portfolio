<?php
header("Content-Type: application/json; charset=UTF-8");



if (!isset($_POST["email"]) && !isset($_POST["dbparam"]) && !isset($_POST["currentOrderList"])) {
    echo json_encode(["error" => "Required inputs not provided"]);
    // atleast one input should be given
    exit();
}

if (isset($_POST["email"])) {
    $dbparam = json_decode($_POST["email"], false);
    $email = $dbparam->email;
}


$update = 0;

if (isset($_POST["dbparam"])) {

    $dbparam = json_decode($_POST["dbparam"], false);
    $email = $dbparam->email;
    // orderNumber: OrderNumberOfProduct,
    // productCode: productCode,
    // quantity: quantity,
    // totalCost: totalCost,
    // orderDate: orderDate,
    // buy: 0,

    $orderNumberSt = $dbparam->orderNumber;
    $orderNumber = intval($orderNumberSt);
    $productNumber = $dbparam->productCode;
    $quantity = $dbparam->quantity;
    $quantity = intval($dbparam->quantity);
    $totalCost = $dbparam->totalCost;
    $update = $dbparam->update;

}


if (isset($_POST["currentOrderList"])) {

    $currentOrderList = json_decode($_POST["currentOrderList"], false);

    $email = $currentOrderList->email;
    $orderNumbersIn = $currentOrderList->orderedProductsArray;

    $currentOrderList = $currentOrderList->OrderNumberOfProduct;



    $currentOrderList = "(" . implode(",", $currentOrderList) . ")";
    // now we can use this in our query
// echo $currentOrderList;


    $orderNumbersIn = "(" . implode(",", $orderNumbersIn) . ")";

    // echo $orderNumbersIn;

}







// Database connection setup
$conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");

// Check connection
if ($conn->connect_error) {
    echo json_encode(["error" => "Database connection failed: " . $conn->connect_error]);
    exit();
}


$stmt = $conn->prepare("SELECT CustomerNumber FROM customers_data WHERE EmailAddress='$email';");
$stmt->execute();
$result = $stmt->get_result();
$customerNumber = $result->fetch_assoc()['CustomerNumber'];

// $stmt1 = $conn->prepare("select orderNumber from orders where customerNumber='$customerNumber'");




$stmt1 = $conn->prepare("select orderNumber from orders where customerNumber='$customerNumber'");
// $stmt1 = $conn->prepare("select orderNumber from orders where customerNumber=1856176940");
$stmt1->execute();
$result1 = $stmt1->get_result();

$orderNumbers = array();

while ($row = $result1->fetch_assoc()) {
    $orderNumbers[] = $row;
    // convert $row into sting

}



$stmt2 = $conn->prepare("SELECT productCode FROM order_details  WHERE OrderNumber=? and amountPending>0 and modeOfPayment='cart'");//outside also works
// $stmt2->bind_param("i", $orderNumbers[0]['orderNumber']);
// let's use for loop to execute stmt2 for each OrderNumber





$productCodes = array();
for ($i = 0; $i < count($orderNumbers); $i++) {
    // $stmt2 = $conn->prepare("SELECT productCode FROM order_details  WHERE OrderNumber=?"); //inside also works
    $stmt2->bind_param("i", $orderNumbers[$i]['orderNumber']);
    $stmt2->execute();
    $result2 = $stmt2->get_result();
    $productCodes[] = $result2->fetch_assoc();
}





// we want quantity,and totalcost also along with productCode FROM order_details 

// orderNumber,productCode,quantityOrdered,priceEach,totalCost
$stmt4 = $conn->prepare("SELECT productCode,quantityOrdered,totalCost FROM order_details  WHERE OrderNumber=? and amountPending>0 and modeOfPayment='cart'");
// 

for ($i = 0; $i < count($orderNumbers); $i++) {
    $stmt4->bind_param("i", $orderNumbers[$i]['orderNumber']);
    $stmt4->execute();
    $result4 = $stmt4->get_result();
    $productDetails = $result4->fetch_assoc();



}



// ALTER TABLE order_details ADD modeOfPayment varchar(100) default "cart";

$stmt3 = $conn->prepare("SELECT * 
    FROM products WHERE productCode = ?");
$products = array();
for ($i = 0; $i < count($productCodes); $i++) {
    // $stmt2 = $conn->prepare("SELECT productCode FROM order_details  WHERE OrderNumber=?"); //inside also works
    $stmt3->bind_param("i", $productCodes[$i]['productCode']);
    $stmt3->execute();
    $result3 = $stmt3->get_result();
    $products[] = $result3->fetch_assoc();
}


// now we want to echo both $productDetails and $products innerjoin by their productCode
$stmt5 = $conn->prepare("SELECT *
FROM order_details
INNER JOIN products ON order_details.productCode = products.productCode
WHERE order_details.OrderNumber = ? and amountPending>0 and modeOfPayment='cart'");



// ALTER TABLE order_details ADD productSize varchar(50) default "free size";

// 


$orderDetails = array();//for array

for ($i = 0; $i < count($orderNumbers); $i++) {
    $stmt5->bind_param("i", $orderNumbers[$i]['orderNumber']);
    $stmt5->execute();
    $result5 = $stmt5->get_result();
    // $orderDetails = $result5->fetch_assoc();//gives only one
    $orderDetails[] = $result5->fetch_assoc();
}



if ($update && isset($_POST["dbparam"])) {
    // if(isset($_POST["dbparam"])){

    $stmt6 = $conn->prepare("Update order_details set quantityOrdered=$quantity,totalCost=$totalCost where (orderNumber =$orderNumber and productCode='$productNumber')");
    $stmt6->execute();


}



if (isset($_POST["currentOrderList"])) {

    $stmt7 = $conn->prepare("DELETE from order_details where orderNumber IN $orderNumbersIn  AND orderNumber NOT IN $currentOrderList AND productCode != 'cartItems' ");

    // if (! $stmt7 || !$stmt8) {
    if (! $stmt7) {
        echo json_encode(["error" => "Statement preparation failed: " . $conn->error]);
        exit();
    }

    $stmt7->execute();//error as 

    // The MySQL error code 1644 indicates an issue with a user-defined subroutine, often related to triggers or constraints. It suggests that the code is attempting an action that's not allowed, like updating a column protected by a trigger or constraint. In the case of the provided error message, the "orders" table likely has a trigger or constraint preventing it from being updated to a "delivered" status if specific conditions are not met, such as a previous status of "pending" or "in transit". 



    // $stmt8 = $conn->prepare("DELETE from orders where (orderNumber IN $orderNumbersIn ) AND (orderNumber NOT IN $currentOrderList) and customerNumber='$customerNumber'");


    $stmt8 = $conn->prepare("DELETE from orders where orderNumber NOT IN (Select orderNumber from order_details)");//works


    $stmt8->execute();




}


echo json_encode($orderDetails);
// now it is giving everything , all details




$conn->close();
?>