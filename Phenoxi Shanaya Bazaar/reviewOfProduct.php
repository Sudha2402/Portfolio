<?php

$conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");

// Check connection
if (!$conn->connect_error) {

    if (isset($_POST["productCode"])) {
        // echo "inside";
        $productCode = json_decode($_POST["productCode"], false);


$stmt0=$conn->prepare("SELECT orders.orderNumber as orderNumber,order_details.productCode,orders.customerNumber,customers_data.FirstName,customers_data.CustomersProfilePhoto,customers_data.EmailAddress,orders.ratingOfStars,orders.comments,orders.status from products,orders,order_details,customers_data where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber and orders.customerNumber=customers_data.CustomerNumber and order_details.productCode !='cartItems' and orders.status='delivered'  and order_details.modeOfPayment != 'cart' and orders.ratingOfStars IS NOT NULL and order_details.productCode = '$productCode') UNION All SELECT cartplaceorder.orderNumberCart as orderNumber,cartplaceorder.productCode,orders.customerNumber,customers_data.FirstName,customers_data.CustomersProfilePhoto ,customers_data.EmailAddress,cartplaceorder.ratingOfStars,cartplaceorder.comments ,cartplaceorder.status FROM cartplaceorder, products,orders,order_details,customers_data  where (products.productCode = cartplaceorder.productCode AND order_details.orderNumber=orders.orderNumber and orders.customerNumber=customers_data.CustomerNumber AND  orders.orderNumber=cartplaceorder.orderNumber and cartplaceorder.modeOfPayment != 'cart'  and order_details.productCode ='cartItems' and cartplaceorder.status='delivered' and cartplaceorder.ratingOfStars  IS NOT NULL and cartplaceorder.productCode = '$productCode')");





        $stmt0->execute();
        $result0 = $stmt0->get_result();
        $review = $result0->fetch_all(MYSQLI_ASSOC);//here this review is an array and we want the next stmt to use this table to get ratingOfStars from this table//if we use select from this then it will not works and gives error




$reviewImages=$conn->prepare("SELECT * from customersreviewimages WHERE prd_code='$productCode'");
$reviewImages->execute();
$reviewImages = $reviewImages->get_result();
$reviewImages = $reviewImages->fetch_all(MYSQLI_ASSOC);
   







        $stmt = $conn->prepare("SELECT orders.ratingOfStars,count(*) from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber and order_details.productCode !='cartItems' and orders.status='delivered'  and order_details.modeOfPayment != 'cart' and orders.ratingOfStars IS NOT NULL) and order_details.productCode = '$productCode' GROUP BY ratingOfStars UNION All SELECT cartplaceorder.ratingOfStars,count(*) FROM cartplaceorder, products,orders,order_details  where (products.productCode = cartplaceorder.productCode AND order_details.orderNumber=orders.orderNumber AND  orders.orderNumber=cartplaceorder.orderNumber and cartplaceorder.modeOfPayment != 'cart'  and order_details.productCode ='cartItems' and cartplaceorder.status='delivered' and cartplaceorder.ratingOfStars  IS NOT NULL) and cartplaceorder.productCode = '$productCode' GROUP BY ratingOfStars;");




        $stmt5 = $conn->prepare("SELECT count(*) as 'count(*)' from (SELECT orders.orderNumber as orderNumber,order_details.productCode,orders.customerNumber,orders.ratingOfStars,orders.comments,orders.status from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber and order_details.productCode !='cartItems' and orders.status='delivered'  and order_details.modeOfPayment != 'cart' and orders.ratingOfStars IS NOT NULL) UNION All SELECT cartplaceorder.orderNumberCart as orderNumber,cartplaceorder.productCode,orders.customerNumber,cartplaceorder.ratingOfStars,cartplaceorder.comments ,cartplaceorder.status FROM cartplaceorder, products,orders,order_details  where (products.productCode = cartplaceorder.productCode AND order_details.orderNumber=orders.orderNumber AND  orders.orderNumber=cartplaceorder.orderNumber and cartplaceorder.modeOfPayment != 'cart'  and order_details.productCode ='cartItems' and cartplaceorder.status='delivered' and cartplaceorder.ratingOfStars  IS NOT NULL)) as review WHERE productCode='$productCode' and ratingOfStars=5 ;");//works

        $stmt4 = $conn->prepare("SELECT count(*) as 'count(*)' from (SELECT orders.orderNumber as orderNumber,order_details.productCode,orders.customerNumber,orders.ratingOfStars,orders.comments,orders.status from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber and order_details.productCode !='cartItems' and orders.status='delivered'  and order_details.modeOfPayment != 'cart' and orders.ratingOfStars IS NOT NULL) UNION All SELECT cartplaceorder.orderNumberCart as orderNumber,cartplaceorder.productCode,orders.customerNumber,cartplaceorder.ratingOfStars,cartplaceorder.comments ,cartplaceorder.status FROM cartplaceorder, products,orders,order_details  where (products.productCode = cartplaceorder.productCode AND order_details.orderNumber=orders.orderNumber AND  orders.orderNumber=cartplaceorder.orderNumber and cartplaceorder.modeOfPayment != 'cart'  and order_details.productCode ='cartItems' and cartplaceorder.status='delivered' and cartplaceorder.ratingOfStars  IS NOT NULL)) as review WHERE productCode='$productCode' and ratingOfStars=4");
        $stmt3 = $conn->prepare("SELECT count(*) as 'count(*)' from (SELECT orders.orderNumber as orderNumber,order_details.productCode,orders.customerNumber,orders.ratingOfStars,orders.comments,orders.status from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber and order_details.productCode !='cartItems' and orders.status='delivered'  and order_details.modeOfPayment != 'cart' and orders.ratingOfStars IS NOT NULL) UNION All SELECT cartplaceorder.orderNumberCart as orderNumber,cartplaceorder.productCode,orders.customerNumber,cartplaceorder.ratingOfStars,cartplaceorder.comments ,cartplaceorder.status FROM cartplaceorder, products,orders,order_details  where (products.productCode = cartplaceorder.productCode AND order_details.orderNumber=orders.orderNumber AND  orders.orderNumber=cartplaceorder.orderNumber and cartplaceorder.modeOfPayment != 'cart'  and order_details.productCode ='cartItems' and cartplaceorder.status='delivered' and cartplaceorder.ratingOfStars  IS NOT NULL)) as review WHERE productCode='$productCode' and ratingOfStars=3");
        $stmt2 = $conn->prepare("SELECT count(*) as 'count(*)' from (SELECT orders.orderNumber as orderNumber,order_details.productCode,orders.customerNumber,orders.ratingOfStars,orders.comments,orders.status from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber and order_details.productCode !='cartItems' and orders.status='delivered'  and order_details.modeOfPayment != 'cart' and orders.ratingOfStars IS NOT NULL) UNION All SELECT cartplaceorder.orderNumberCart as orderNumber,cartplaceorder.productCode,orders.customerNumber,cartplaceorder.ratingOfStars,cartplaceorder.comments ,cartplaceorder.status FROM cartplaceorder, products,orders,order_details  where (products.productCode = cartplaceorder.productCode AND order_details.orderNumber=orders.orderNumber AND  orders.orderNumber=cartplaceorder.orderNumber and cartplaceorder.modeOfPayment != 'cart'  and order_details.productCode ='cartItems' and cartplaceorder.status='delivered' and cartplaceorder.ratingOfStars  IS NOT NULL)) as review WHERE productCode='$productCode' and ratingOfStars=2 ");

        // $stmt1 = $conn->prepare("SELECT IFNULL(count(*),0) as 'count(*)' from order_details,orders WHERE order_details.orderNumber=orders.orderNumber and productCode='$productCode' and ratingOfStars=1");
        $stmt1 = $conn->prepare("SELECT count(*) as 'count(*)' from (SELECT orders.orderNumber as orderNumber,order_details.productCode,orders.customerNumber,orders.ratingOfStars,orders.comments,orders.status from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber and order_details.productCode !='cartItems' and orders.status='delivered'  and order_details.modeOfPayment != 'cart' and orders.ratingOfStars IS NOT NULL) UNION All SELECT cartplaceorder.orderNumberCart as orderNumber,cartplaceorder.productCode,orders.customerNumber,cartplaceorder.ratingOfStars,cartplaceorder.comments ,cartplaceorder.status FROM cartplaceorder, products,orders,order_details  where (products.productCode = cartplaceorder.productCode AND order_details.orderNumber=orders.orderNumber AND  orders.orderNumber=cartplaceorder.orderNumber and cartplaceorder.modeOfPayment != 'cart'  and order_details.productCode ='cartItems' and cartplaceorder.status='delivered' and cartplaceorder.ratingOfStars  IS NOT NULL)) as review WHERE productCode='$productCode' and ratingOfStars=1");






        // $totalNumberOfReview = $conn->prepare("SELECT count(*) from order_details,orders WHERE order_details.orderNumber=orders.orderNumber and productCode='$productCode'");

        // $sumOfReview = $conn->prepare("SELECT SUM(ratingOfStars) from order_details,orders WHERE order_details.orderNumber=orders.orderNumber and productCode='$productCode'");




        $totalNumberOfReview = $conn->prepare("SELECT count(*) as 'count(*)' from (SELECT orders.orderNumber as orderNumber,order_details.productCode,orders.customerNumber,orders.ratingOfStars,orders.comments,orders.status from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber and order_details.productCode !='cartItems' and orders.status='delivered'  and order_details.modeOfPayment != 'cart' and orders.ratingOfStars IS NOT NULL) UNION All SELECT cartplaceorder.orderNumberCart as orderNumber,cartplaceorder.productCode,orders.customerNumber,cartplaceorder.ratingOfStars,cartplaceorder.comments ,cartplaceorder.status FROM cartplaceorder, products,orders,order_details  where (products.productCode = cartplaceorder.productCode AND order_details.orderNumber=orders.orderNumber AND  orders.orderNumber=cartplaceorder.orderNumber and cartplaceorder.modeOfPayment != 'cart'  and order_details.productCode ='cartItems' and cartplaceorder.status='delivered' and cartplaceorder.ratingOfStars  IS NOT NULL)) as review WHERE productCode='$productCode'");

        $sumOfReview = $conn->prepare("SELECT SUM(ratingOfStars) from (SELECT orders.orderNumber as orderNumber,order_details.productCode,orders.customerNumber,orders.ratingOfStars,orders.comments,orders.status from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber and order_details.productCode !='cartItems' and orders.status='delivered'  and order_details.modeOfPayment != 'cart' and orders.ratingOfStars IS NOT NULL) UNION All SELECT cartplaceorder.orderNumberCart as orderNumber,cartplaceorder.productCode,orders.customerNumber,cartplaceorder.ratingOfStars,cartplaceorder.comments ,cartplaceorder.status FROM cartplaceorder, products,orders,order_details  where (products.productCode = cartplaceorder.productCode AND order_details.orderNumber=orders.orderNumber AND  orders.orderNumber=cartplaceorder.orderNumber and cartplaceorder.modeOfPayment != 'cart'  and order_details.productCode ='cartItems' and cartplaceorder.status='delivered' and cartplaceorder.ratingOfStars  IS NOT NULL)) as review WHERE productCode='$productCode'");


        





        $stmt->execute();
        $result = $stmt->get_result();
        $ratingStarCounts = $result->fetch_assoc();
        // echo $ratingStarCounts[0];//error
        // The fetch_assoc() / mysqli_fetch_assoc() function fetches a result row as an associative array.
       

        $stmt1->execute();
        $result1 = $stmt1->get_result();
        $star1 = $result1->fetch_assoc();

        $stmt2->execute();
        $result2 = $stmt2->get_result();
        $star2 = $result2->fetch_assoc();

        $stmt3->execute();
        $result3 = $stmt3->get_result();
        $star3 = $result3->fetch_assoc();

        $stmt4->execute();
        $result4 = $stmt4->get_result();
        $star4 = $result4->fetch_assoc();

        $stmt5->execute();
        $result5 = $stmt5->get_result();
        $star5 = $result5->fetch_assoc();

        $totalNumberOfReview->execute();
        $totalNumberOfReview = $totalNumberOfReview->get_result();
        $totalNumberOfReview = $totalNumberOfReview->fetch_assoc();

        $sumOfReview->execute();
        $sumOfReview = $sumOfReview->get_result();
        $sumOfReview = $sumOfReview->fetch_assoc();

      



        // works but raise error when any of data is null in case of error
        echo json_encode (array(
            "totalNumberOfReview" => (int)$totalNumberOfReview["count(*)"],
            "star1" => (int)$star1["count(*)"],
            "star2" => (int)$star2["count(*)"],
            "star3" => (int)$star3["count(*)"],
            "star4" => (int)$star4["count(*)"],
            "star5" => (int)$star5["count(*)"],
            "sumOfReview" => (int)$sumOfReview["SUM(ratingOfStars)"],
          
            "reviews" =>$review,//returns array with each row as object
            "reviewImages" =>$reviewImages//returns array with each row as object
        ));

       



        $stmt->close();
        $stmt1->close();
        $stmt2->close();
        $stmt3->close();
        $stmt4->close();
        $stmt5->close();
    } else {
        echo "Not passed product code";
    }
} else {
    echo json_encode(["error" => "Database connection failed: " . $conn->connect_error]);
    exit();
}
