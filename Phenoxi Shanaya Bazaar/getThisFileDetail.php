<?php
header("Content-Type: application/json; charset=UTF-8");



// Database connection setup
$conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");

// Check connection

if ($conn->connect_error) {

    echo json_encode(["error" => "Database connection failed: " . $conn->connect_error]);
    exit();

}


// delimiter &&
// Create trigger safely_delete_products Before Delete on products FOR EACH ROW
// Begin if old.productCode IS NOT NULL THEN Signal sqlstate '45000'
// SET message_text='ERROR:This product holds a productCode' ;
// End if;
// End ;&&
// delimiter ;






// delimiter &&
// Create trigger safely_delete_product_files Before Delete on product_files FOR EACH ROW
// Begin if old.product_Code IS NOT NULL THEN Signal sqlstate '45000'
// SET message_text='ERROR:This productfile holds a productCode' ;
// End if;
// End ;&&
// delimiter ;



// delimiter &&
// Create trigger safely_delete_orders Before Delete on orders FOR EACH ROW
// Begin if old.status IS NOT NULL THEN Signal sqlstate '45000'
// SET message_text='ERROR:This orders is delivered' ;
// End if;
// End ;&&
// delimiter ;




// delimiter &&
// Create trigger safely_delete_order_details Before Delete on order_details FOR EACH ROW
// Begin if old.modeOfPayment != 'cart' THEN Signal sqlstate '45000'
// SET message_text='ERROR:This orders is delivered' ;
// End if;
// End ;&&
// delimiter ;




// delimiter &&
// Create trigger safely_delete_cartplaceorder Before Delete on cartplaceorder FOR EACH ROW
// Begin if old.modeOfPayment IS NOT NULL THEN Signal sqlstate '45000'
// SET message_text='ERROR:This cartplaceorder holds complete payment' ;
// End if;
// End ;&&
// delimiter ;





// delimiter &&
// Create trigger safely_delete_customers Before Delete on customers FOR EACH ROW
// Begin if old.customerNumber IS NOT NULL THEN Signal sqlstate '45000'
// SET message_text='ERROR:This customer holds customerNumber' ;
// End if;
// End ;&&
// delimiter ;





// delimiter &&
// Create trigger safely_delete_customers_data Before Delete on customers_data FOR EACH ROW
// Begin if old.CustomerNumber IS NOT NULL THEN Signal sqlstate '45000'
// SET message_text='ERROR:This customer holds customerNumber' ;
// End if;
// End ;&&
// delimiter ;






// delimiter &&
// Create trigger safely_delete_customersreviewimages Before Delete on customersreviewimages FOR EACH ROW
// Begin if old.prd_Code IS NOT NULL THEN Signal sqlstate '45000'
// SET message_text='ERROR:This review holds productCode' ;
// End if;
// End ;&&
// delimiter ;




$fileSrc = json_decode($_POST["fileSrc"], false);
//we want to replace \\ to / if any in the $fileSrc.
// $fileSrc = str_replace('\\', '/', $fileSrc);
// $fileSrc = str_replace('\\', '', $fileSrc);//not helpful


// $stmt = $conn->prepare("select IFNULL((SELECT product_Code FROM product_files WHERE file_src like '%$fileSrc%' limit 1),'null') as product_Code");

$stmt = $conn->prepare("select IFNULL((SELECT product_Code FROM product_files WHERE file_src = '$fileSrc'),'null') as product_Code");

if (!$stmt) {
    echo json_encode(["error" => "Statement preparation failed: " . $conn->error]);
    exit();
}

$stmt->execute();
$result = $stmt->get_result();

if (isset($_POST["fileSrc"]) && !isset($_POST["productCode"])) {

  
    $productCode = $result->fetch_assoc();


    $stmt1 = $conn->prepare("SELECT * FROM product_files WHERE product_Code = ? and file_src like '%$fileSrc'");

    $stmt1->bind_param("s", $productCode['product_Code']);//works



}



if (isset($_POST["productCode"])) {
    //we have to decode
    $productCode = json_decode($_POST["productCode"], false);

    // echo $productCode;//it is valid //WEWK1
    $stmt1 = $conn->prepare("SELECT * FROM product_files WHERE product_Code ='$productCode'
    AND file_src like '%$fileSrc%'");



}




$stmt1->execute();//it gives array to string conversion warning for that


$result1 = $stmt1->get_result();
$result1 = $result1->fetch_all(MYSQLI_ASSOC);

// $colorsOfProduct=array();
foreach ($result1 as $row) {
    $productCodeColor = $row['product_Code'];
    $color = $row['color'];
    $Quantity_Pack= $row['Quantity_Pack'];
    $Quantity_Pack_Price= $row['Quantity_Pack_Price'];
    $Quantity_Pack_Name= $row['Quantity_Pack_Name'];


    if ($color != 'null') {
        // color is '' empty but not null, hence it will always enter in this condition
        $stmt2 = $conn->prepare("SELECT * FROM product_files WHERE product_Code='$productCodeColor' and color='$color'");
        $stmt2->execute();
        $result2 = $stmt2->get_result();
        $result2 = $result2->fetch_all(MYSQLI_ASSOC);

        //if result2 is null then set it 'null'
    }

    if($Quantity_Pack_Name  !== null) {
        $stmt2 = $conn->prepare("SELECT * FROM product_files WHERE product_Code='$productCodeColor' and Quantity_Pack_Name='$Quantity_Pack_Name'");
        $stmt2->execute();
        $result2 = $stmt2->get_result();
        $result2 = $result2->fetch_all(MYSQLI_ASSOC);

        //if result2 is null then set it 'null'

    }



}

if (empty($result2)) {
    $result2 = 'null';//[{"product_Code":"null"},"null"]//otherwise created error like [{"product_Code":"null"},null]
}


// if (empty($result3)) {
//     $result3 = 'null';//[{"product_Code":"null"},"null"]//otherwise created error like [{"product_Code":"null"},null]
// }



echo json_encode(array($productCode, $result2));//[{"product_Code":"WEWL1"},[{"file_Id":214,"product_Code":"WEWL1","color":"blue pink","file_src":"product\/women\/ethnic wear\/lahenga\/Solid Semi Stitched Lehenga Choli\/colors option\/blue\/Screenshot 2025-02-10 214459.png"},{"file_Id":215,"product_Code":"WEWL1","color":"blue pink","file_src":"produc





$stmt->close();

$conn->close();

?>