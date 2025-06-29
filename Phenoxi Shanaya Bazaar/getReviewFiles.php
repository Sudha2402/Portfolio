<?php

header("Content-Type: application/json; charset=UTF-8");

$productCode = json_decode($_POST["productCode"], false);

// Database connection setup
$conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");

// Check connection
if ($conn->connect_error) {
    echo json_encode(["error" => "Database connection failed: " . $conn->connect_error]);
    exit();
}

$stmt = $conn->prepare("SELECT * FROM customersreviewimages WHERE prd_code ='$productCode'");


if (!$stmt) {
    echo json_encode(["error" => "Statement preparation failed: " . $conn->error]);
    exit();
}

$stmt->execute();
$result = $stmt->get_result();
$images = array();
while ($row = $result->fetch_assoc()) {
    $images[] = $row['img_url'];
}

echo json_encode (["images" => $images]);
// works


$stmt->close();

$conn->close();

?>