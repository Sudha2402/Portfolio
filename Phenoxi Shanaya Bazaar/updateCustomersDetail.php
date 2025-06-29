<?php

header("Content-Type: application/json; charset=UTF-8");

if ( !isset($_POST["dbparam"])) {
    echo json_encode(["error" => "Required inputs not provided"]);
    exit(); 
}

$dbparam = json_decode($_POST["dbparam"], false);

if (!isset($dbparam->EmailAddress) && !isset($dbparam->checkedValue) ) {
    echo json_encode(["error" => "Invalid parameter"]);
    exit();
}

$email =  $dbparam->EmailAddress;
$checkedValue =  $dbparam->checkedValue;


// if ( !isset($_POST["EmailAddress"])) {
//     echo json_encode(["error" => "Required inputs not provided"]);
//     exit();
// }

// $email = json_decode($_POST["EmailAddress"], false);
// $checkedValue = json_decode($_POST["checkedValue"], false);



$db = mysqli_connect("localhost", "root", "#sudha@2402", "shanayabazaar");

// Check connection
if ($db->connect_error) {

    echo json_encode(["error" => "Database connection failed: " . $db->connect_error]);

    exit();

}

// SQL query to update data from database
$stmt1 = $db->prepare("Update customers_data SET CustomersExperienceReview='$checkedValue' WHERE EmailAddress ='$email'");
$stmt1->execute();

echo "Thanks for Rating.Your Experience Review is recorded";

$stmt1->close();
$db->close();
?>