<?php


$conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");

if ($conn->connect_error) {
    echo json_encode(["error" => "Database connection failed: " . $conn->connect_error]);
    exit();
}




if (isset($_POST["dbparam"])) {

    $dbparam = json_decode($_POST["dbparam"], false);
    

    if (!isset($dbparam->EmailAddress) && !isset($dbparam->checkedValueOfReviewOfProdct)) {

        echo json_encode(["error" => "Invalid parameter"]);
        exit();
    }

    $productCode = $dbparam->productCode;
    $email = $dbparam->EmailAddress;
    $reviewName = $dbparam->reviewName;
    $reviewText = $dbparam->reviewText;
    // there may be an issue when user use ' inbetween , hence we need to completely stringify it so that special characters will be stored as it is
    $reviewText = json_encode($reviewText);//it will work



    $checkedValueOfReviewOfProdct = $dbparam->checkedValueOfReviewOfProdct;

    // $files = (array) $dbparam->files;//it takes in the form of an object form,{"0":{},"1":{},"2":{}}
    // echo $files;

    $stmt1 = $conn->prepare("SELECT * FROM customers_data WHERE EmailAddress ='$email'");
    $stmt1->execute();
    $result1 = $stmt1->get_result();
    $row1 = $result1->fetch_assoc();
    $CustomerNumber = $row1['CustomerNumber']; //1






    if ($CustomerNumber == null) {
        echo "You need to register before giving your review";
        exit();
    }




   

    // Prepare SQL statement

    
    $stmt2 = "SELECT orders.orderNumber as orderNumber,order_details.productCode,orders.customerNumber,orders.ratingOfStars,orders.comments from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber AND orders.customerNumber = $CustomerNumber and order_details.modeOfPayment != 'cart' and orders.status='delivered' and order_details.productCode = '$productCode' and order_details.productCode !='cartItems')"; //write it in capital.

    $stmt2 .= "UNION All SELECT cartplaceorder.orderNumberCart as orderNumber,cartplaceorder.productCode,orders.customerNumber,cartplaceorder.ratingOfStars,cartplaceorder.comments FROM cartplaceorder, products,orders,order_details  where (products.productCode = cartplaceorder.productCode AND order_details.orderNumber=orders.orderNumber AND  orders.orderNumber=cartplaceorder.orderNumber AND orders.customerNumber = $CustomerNumber and cartplaceorder.modeOfPayment != 'cart'  and cartplaceorder.productCode = '$productCode' and order_details.productCode ='cartItems' and cartplaceorder.status='delivered') ";

   
    $stmt2 = $conn->prepare($stmt2); //it will give list of products ordered by this customernumber


    if (!$stmt2) {
        echo json_encode(["error" => "Statement preparation failed: " . $conn->error]);
        exit();
    }


    $stmt2->execute();
    $result2 = $stmt2->get_result();
    $outp = $result2->fetch_all(MYSQLI_ASSOC);
  

    // now we need update in each row of    $outp



    if (empty($outp)) {
        $response = array(
            "status" => "false",
            "message" => "No products ordered
    "
        );
        echo json_encode($response);
        exit();
    } else {
        $response = array(
            "status" => "true",
            "message" => "Products ordered",
            "data" => $outp
        );
    }
    // echo json_encode($response);


  

    // orderNumber,productCode,customerNumber,ratingOfStars,comments
    foreach ($outp as $row) {
        // echo htmlspecialchars($row['orderNumber']); //we need to store this in another variable orderNumber
        $orderNumber = $row['orderNumber'];
        $productCode = $row['productCode'];
        $customerNumber = $row['customerNumber'];
        $ratingOfStars = $row['ratingOfStars'];
        $comments = $row['comments'];

        $stmt3 = $conn->prepare("Update orders set ratingOfStars=$checkedValueOfReviewOfProdct,comments=$reviewText where orderNumber=$orderNumber");
        // similarly we have to update cartplaceorder
        $stmt4 = $conn->prepare("Update cartplaceorder set ratingOfStars=$checkedValueOfReviewOfProdct,comments=$reviewText where 
              orderNumberCart=$orderNumber");
        // $stmt3->bindParam(':orderNumber', $orderNumber);

        //now execute $stmt3 and $stmt4
        $stmt3->execute();
        $stmt4->execute();
    }


    // }



    // } catch (Exception $e) {
    //     echo json_encode(["error" => $e->getMessage()]);
    //     } finally {
    //         $conn->close();
    //         }

echo json_encode(["success" => true, "message" => "Review inserted successfully"]);
// echo json_encode($outp);//array of each row

// echo json_encode(["success" => true, "message" => "Review inserted successfully","reviews"=>$outp]);//it will open u only when review is inserted//not a good idea

    $conn->close();
} else {
    echo "No matching order found";
}



?>