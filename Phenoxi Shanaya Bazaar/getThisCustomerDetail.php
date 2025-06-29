<?php
header("Content-Type: application/json; charset=UTF-8");



$email = json_decode($_GET["EmailAddress"], false);

// Database connection setup
$conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");

// Check connection
if ($conn->connect_error) {
    echo json_encode(["error" => "Database connection failed: " . $conn->connect_error]);
    exit();
}

$stmt = $conn->prepare("SELECT * FROM customers_data Natural JOIN customers WHERE EmailAddress ='$email'");

if (!$stmt) {
    echo json_encode(["error" => "Statement preparation failed: " . $conn->error]);
    exit();
}

$stmt->execute();

$result = $stmt->get_result();

while ($row = $result->fetch_assoc()) {
    $CustomerNumber = $row['CustomerNumber'];
    $Prefix = $row['Prefix'];
    $FirstName = $row['FirstName'];
    $LastName = $row['LastName'];
    $BirthDate = $row['BirthDate'];
    $MaritalStatus = $row['MaritalStatus'];
    $EmailAddress = $row['EmailAddress'];
    $Password = $row['Password'];
    $AnnualIncome = $row['AnnualIncome'];
    $Gender = $row['Gender'];
    $CustomersProfilePhoto = $row['CustomersProfilePhoto'];
    $score = $row['score'];
    $CreditLimit= $row['creditLimit'];
}


echo json_encode(array("CustomerNumber"=>$CustomerNumber,"Prefix"=>$Prefix,"FirstName"=>$FirstName,"LastName"=>$LastName,"BirthDate"=>$BirthDate,"MaritalStatus"=>$MaritalStatus,"EmailAddress"=>$EmailAddress,"Password"=>$Password,"AnnualIncome"=>$AnnualIncome,"Gender"=>$Gender,"CustomersProfilePhoto"=>$CustomersProfilePhoto,
"Score"=>$score,"CreditLimit"=>$CreditLimit));







// works


$stmt->close();

$conn->close();

?>