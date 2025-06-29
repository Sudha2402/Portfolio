<?php
header("Content-Type: application/json; charset=UTF-8");

if ( !isset($_POST["dbparam"])) {
    echo json_encode(["error" => "Required inputs not provided"]);
    exit();
}



$dbparam = json_decode($_POST["dbparam"], false);

if (!isset($dbparam->customerNumber) || !isset($dbparam->custName) || !isset($dbparam->custEmail)|| !isset($dbparam->custPassword)) {
    echo json_encode(["error" => "Invalid parameter"]);
    exit();
}

$customerNumberS = $dbparam->customerNumber;
$customerNumber = intval($customerNumberS);
// $customerNumber = intval($dbparam->customerNumber);
$custName = $dbparam->custName;
$custEmail = $dbparam->custEmail;
$custPassword = $dbparam->custPassword;



// Database connection setup
$conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");


// Check connection
if ($conn->connect_error) {
    echo json_encode(["error" => "Database connection failed: " . $conn->connect_error]);
    exit();
}

$stmt1 = $conn->prepare("INSERT INTO customers(customerNumber) VALUES($customerNumber)");
$stmt2 = $conn->prepare("INSERT INTO customers_data(CustomerNumber,FirstName,EmailAddress,Password) VALUES($customerNumber,'$custName','$custEmail','$custPassword')");


if (!$stmt1 || !$stmt2) {
    echo json_encode(["error" => "Statement preparation failed: " . $conn->error]);
    exit();
}

$stmt1->execute();
$stmt2->execute();

// $result = $stmt->get_result();

echo "You are successfully registered";

$stmt1->close();
$stmt2->close();
$conn->close();

?>

