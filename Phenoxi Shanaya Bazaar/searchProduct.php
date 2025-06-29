<?php
header("Content-Type: application/json; charset=UTF-8");

$product = json_decode($_GET["product"], false);

// Database connection setup
$conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");

// Check connection
if ($conn->connect_error) {
    echo json_encode(["error" => "Database connection failed: " . $conn->connect_error]);
    exit();
}



// for splitting the words of product
$keywords = explode(" ", $product);



$keywords = array_map('trim', $keywords);//used to remove leading and trailing spaces from the keywords array

$keywords = array_filter($keywords, 'strlen'); // remove empty strings

$keywords = array_map('strtolower', $keywords); // convert to lowercase
// hgf gcg h H B  gives this in keywords["hgf","gcg","h","h","b"]

//now storing explode keywords in different variable

//let's check the size of this exploded keywords
$size = count($keywords);//gives the counting of explode result





// we also want to check in the mainProductImage;
// we will use a loop to create a query for each keyword
for ($i = 0; $i < $size; $i++) {
    $query = "SELECT * FROM products WHERE mainProductImage LIKE '%/$keywords[$i]%'";
    // if this / is not used then women if found first will be shown first
}



// case sensitive search even in like according to table
$query .= "UNION SELECT * FROM products WHERE mainProductImage LIKE '%$product%' OR  productName LIKE '%$product%' OR productDescription LIKE '%$product%' OR productLine LIKE '%$product%' ";

// now we want to split keywords further with combination of 3 words
// we will use a loop to create a query for each combination of 3 words

for ($i = 0; $i < $size; $i++) {
    for ($j = $i + 1; $j < $size; $j++) {
        for ($k = $j + 1; $k < $size; $k++)
            $query .= "OR mainProductImage LIKE '%$keywords[$i]%$keywords[$j]%$keywords[$k]%' OR productName LIKE '%$keywords[$i]%$keywords[$j]%$keywords[$k]%' OR productDescription LIKE '%$keywords[$i]%$keywords[$j]%$keywords[$k]%' OR productLine LIKE '%$keywords[$i]%$keywords[$j]%$keywords[$k]%' ";
    }
}




// now we want to split keywords further with combination of 2 words
// we will use a loop to create a query for each combination of 2 words
for ($i = 0; $i < $size; $i++) {
    for ($j = $i + 1; $j < $size; $j++) {
        $query .= "OR productName LIKE '%$keywords[$i]%$keywords[$j]%' OR productDescription LIKE '%$keywords[$i]%$keywords[$j]%' OR productLine LIKE '%$keywords[$i]%$keywords[$j]%' ";
    }
}




// we also want to check in the mainProductImage;
// we will use a loop to create a query for each keyword
for ($i = 0; $i < $size; $i++) {
    $query .= "UNION SELECT * FROM products WHERE mainProductImage LIKE '%/$keywords[$i]%'";
    // if this / is not used then women if found first will be shown first
}





//for each keyword we will create a query and union them together
for ($i = 0; $i < $size; $i++) {
    $query .= "UNION SELECT * FROM products WHERE productName LIKE '%$keywords[$i]%' ";
    // we also want first whole keywords combination then one keyword less key combination like adjacent then seperate    
}

// for each keyword in the array of keywords
foreach ($keywords as $keyword) {

    // create a query for the current keyword
    $query .= "OR productName LIKE '%$keyword%' OR productDescription LIKE '%$keyword%' OR productLine LIKE '%$keyword%' ";
    // we want 4 consecutive letters from $keyword then find the match in like 

    for ($i = 0; $i < strlen($keyword); $i++) {
        // it is creating error this way , letter check is below

        // $query .= "OR productName LIKE '%$keyword[$i]%$keyword[$i+1]%
        // OR productDescription LIKE '%$keyword[$i]%$keyword[$i+1]%' OR product
        // Line LIKE '%$keyword[$i]%$keyword[$i]%' ";//errors
        // // without error of above line






       

    }
}








// it works for give result even after spelling mistake
// size of $keyword word
$size = strlen($keyword);
for ($p = 0; $p < $size; $p++) {
    for ($i = $p; $i < $size; $i++) {
        for ($j = $i + 1; $j < $size; $j++) {
            for ($k = $j + 1; $k < $size; $k++) {
                for ($l = $k + 1; $l < $size; $l++) {
                    for ($m = $l + 1; $m < $size; $m++)
                        $query .= "OR productName LIKE '%$keyword[$i]$keyword[$j]$keyword[$k]$keyword[$l]$keyword[$m]%' OR productDescription LIKE '%$keyword[$i]$keyword[$j]$keyword[$k]$keyword[$l]$keyword[$m]%' OR productLine LIKE '%$keyword[$i]$keyword[$j]$keyword[$k]$keyword[$l]$keyword[$m]%' ";
                }
            }
        }

    }
}












// execute the query
$stmt = $conn->prepare($query);
$stmt->execute();

// let take the result
$result = $stmt->get_result();

$productsResult = array();
while ($row = $result->fetch_assoc()) {
    $productsResult[] = $row;
}

echo json_encode($productsResult);//this will show the exact result


$stmt->close();


$conn->close();


?>