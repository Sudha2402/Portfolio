<?php
header("Content-Type: application/json; charset=UTF-8");

// Database connection setup
$conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");

// Check connection
if ($conn->connect_error) {
    echo json_encode(["error" => "Database connection failed: " . $conn->connect_error]);
    exit();
}

// Prepare SQL statement
$stmt1 = $conn->prepare("SELECT orderNumber from orders");
if (!$stmt1) {
    echo json_encode(["error" => "Statement preparation failed: " . $conn->error]);
    exit();
}

$stmt2 = $conn->prepare("SELECT EmailAddress from customers_data");
if (!$stmt2) {
    echo json_encode(["error" => "Statement preparation failed: " . $conn->error]);
    exit();
}


$stmt1->execute();
$result1 = $stmt1->get_result();
$orderNumber = array();
while ($row = $result1->fetch_assoc()) {
    $orderNumber[] = $row['orderNumber'];
}

$stmt2->execute();
$result2 = $stmt2->get_result();
$emailAddresses = array();
while ($row = $result2->fetch_assoc()) {
    $emailAddresses[] = $row['EmailAddress'];
}

// echo json_encode($orderNumber);

// echo json_encode($cemailAddresses);

echo json_encode(array($orderNumber,$emailAddresses));


$stmt1->close();
$stmt2->close();

$conn->close();

?>