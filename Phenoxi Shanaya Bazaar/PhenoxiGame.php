<?php
header("Content-Type: application/json; charset=UTF-8");

if (!isset($_POST["score"])) {
    echo json_encode(["error" => "Required inputs not provided"]);
    exit();
}

$score = json_decode($_POST["score"], false);


//   yourScore = { score: yourScore, creditEarned: creditEarned,EmailAddress:EmailAddress };

if (!isset($score->score) || !isset($score->creditEarned) || !isset($score->EmailAddress)) {
    echo json_encode(["error" => "Invalid parameter"]);
    exit();
}

$scoreEarned = $score->score;
$scoreEarned = intval($scoreEarned);

$creditEarned = $score->creditEarned;
// convert into number
$creditEarned = intval($creditEarned);
// get emailaddress
$EmailAddress = $score->EmailAddress;




// Database connection setup
$conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");


// Check connection
if ($conn->connect_error) {
    echo json_encode(["error" => "Database connection failed: " . $conn->connect_error]);
    exit();
}


// we need to get CustomerNumber from customers_data where emailAddress is equal to EmailAddress from the score object
$CustomerNumberQuery = "SELECT CustomerNumber FROM customers_data WHERE EmailAddress = '$EmailAddress'";
$result = $conn->query($CustomerNumberQuery);
// check if query was successful
if (!$result) {
    echo json_encode([
        "error" => "Failed to execute query: " . $conn->error
    ]);
    exit();
}
// if query was successful, get the CustomerNumber from the result
$CustomerNumber = $result->fetch_assoc()["CustomerNumber"];
// check if CustomerNumber was found
if (!$CustomerNumber) {
    echo json_encode(["error" => "Customer not found with EmailAddress: $EmailAddress"]);
    exit();
}

// if CustomerNumber was found, get the score for it and if score is less than scoreEarned otherwise don't update
$scoreQuery = "SELECT score FROM customers WHERE customerNumber = '$CustomerNumber'";
$result = $conn->query($scoreQuery);
// check if query was successful
if (!$result) {
    echo json_encode([
        "error" => "Failed to execute query: " . $conn->error
    ]);
    exit();
}
// if query was successful, get the score from the result
$currentScore = $result->fetch_assoc()["score"];


// check if score is less than scoreEarned
if ($currentScore < $scoreEarned) {
    // if score is less than scoreEarned, update the score in the database // we also have to increment creditLimit by $creditEarned 

    $updateQuery = "UPDATE customers SET score = '$scoreEarned',creditLimit =creditLimit+'$creditEarned' WHERE CustomerNumber= '$CustomerNumber'";
    
//    ALTER TABLE customers ADD COLUMN creditLimit INT DEFAULT 0 AFTER score;
  
    $conn->query($updateQuery);
    // check if query was successful
    if (!$conn->query($updateQuery)) {
        echo json_encode([
            "error" => "Failed to execute query: " . $conn->error
        ]);
        exit();
    }
    // if query was successful, return success message
    // echo json_encode(["success" => "Score updated successfully for CustomerNumber: $CustomerNumber"]);
    // just return updated
    echo json_encode("Score updated successfully");
    exit();
}











$conn->close();

?>