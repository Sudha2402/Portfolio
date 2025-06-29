<?php
header("Content-Type: application/json; charset=UTF-8");





// MySQL CREATE TABLE Command
// sql
// Copy
// Edit
// CREATE TABLE returned_ordered_products (
//     returnId INT AUTO_INCREMENT PRIMARY KEY,
//     returned_Date DATE NOT NULL,
//     return_Issue VARCHAR(100) NOT NULL,
//     return_Description TEXT,
//     orderNumber INT NOT NULL,
//     productCode VARCHAR(50) NOT NULL,
//     CustomerNumber INT NOT NULL,
//     Return_Success BOOLEAN DEFAULT FALSE,

//     -- Optional constraints assuming foreign key relationships
//     CONSTRAINT fk_order FOREIGN KEY (orderNumber) REFERENCES orders(orderNumber),
//     CONSTRAINT fk_product FOREIGN KEY (productCode) REFERENCES products(productCode),
//     CONSTRAINT fk_customer FOREIGN KEY (customerNumber) REFERENCES customers(customerNumber)
// );
// 🔍 Explanation of Constraints:
// Id: Primary key with AUTO_INCREMENT to uniquely identify each return.

// Returned_Date: NOT NULL ensures return date must be entered.

// Return_Issue: NOT NULL, max 100 characters for brief issue.

// Return_Description: Optional, stores a detailed description.

// OrderNumber, ProductCode, CustomerNumber: NOT NULL with foreign key constraints for referential integrity (assuming you have orders, products, and customers tables).

// Return_Success: Boolean field with default as FALSE.

// Would you like help adding sample data or creating the referenced tables too?





// Get and decode JSON input, ensure it's a valid request
// if (!isset($_GET["custNumb"])) {
if (!isset($_GET["email"])) {
    echo json_encode(["error" => "No input provided"]);
    exit();
}

// $obj = json_decode($_GET["custNumb"], false);
$obj = json_decode($_GET["email"], false);

// if (!isset($obj->customerNumber) || !is_numeric($obj->customerNumber)) {

if (!isset($obj->email)) {
    echo json_encode(["error" => "Invalid email parameter"]);
    exit();
}

// Sanitize and convert customerNumber to integer
// $customerNumberPassed = intval($obj->customerNumber);

$email = $obj->email;

// Database connection setup
$conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");

// Check connection
if ($conn->connect_error) {
    echo json_encode(["error" => "Database connection failed: " . $conn->connect_error]);
    exit();
}



$stmt = $conn->prepare("SELECT CustomerNumber FROM customers_data WHERE EmailAddress='$email'");

$stmt->execute();
$result = $stmt->get_result();
$customerNumberPassed = $result->fetch_assoc()['CustomerNumber'];
// echo $customerNumberPassed;//1856176940



// Prepare SQL statement
// $stmt1 = "SELECT order_details.productCode,products.productName,products.productLine,products.productVendor,order_details.quantityOrdered,products.buyPrice from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber AND orders.customerNumber = $customerNumberPassed and order_details.modeOfPayment != 'cart' and order_details.productCode !='cartItems')"; //write it in capital.
$stmt1 = "SELECT order_details.orderNumber,order_details.productCode,order_details.colorMainImage,products.productName,orders.orderDate,order_details.quantityOrdered,products.buyPrice,orders.status ,orders.shippedDate,order_details.modeOfPayment  from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber AND orders.customerNumber = $customerNumberPassed and order_details.modeOfPayment != 'cart' and order_details.productCode !='cartItems')"; //write it in capital.
// // using query union

// $stmt1 .= "UNION SELECT cartplaceorder.productCode,products.productName,products.productLine,products.productVendor,cartplaceorder.quantityOrdered,products.buyPrice FROM cartplaceorder, products,orders,order_details  where (products.productCode = cartplaceorder.productCode AND orders.orderNumber=cartplaceorder.orderNumber AND orders.customerNumber = $customerNumberPassed and cartplaceorder.modeOfPayment != 'cart' and order_details.productCode ='cartItems') ";//it gives only one.//removes dublicate data, hence we will use UNION ALL instead of UNION

$stmt1 .= "UNION ALL SELECT cartplaceorder.orderNumber, cartplaceorder.productCode,cartplaceorder.colorMainImage,products.productName,orders.orderDate,cartplaceorder.quantityOrdered,products.buyPrice,cartplaceorder.status ,orders.shippedDate ,cartplaceorder.modeOfPayment FROM cartplaceorder, products,orders,order_details  where (products.productCode = cartplaceorder.productCode AND order_details.orderNumber=orders.orderNumber  AND orders.orderNumber=cartplaceorder.orderNumber AND orders.customerNumber = $customerNumberPassed and cartplaceorder.modeOfPayment != 'cart' and order_details.productCode ='cartItems') ";


$stmt1 .= " ORDER BY orderDate Desc"; //works great


// When tracking an order, you'll typically encounter statuses like Order Received, Order Picked, Order In Transit, Out For Delivery, and Reached Destination or delivered//we have to add this atatus too.



// To set A button for Delivery agent should do this :
// Update order_details set amountReceived=totalCost , amountPending=0;
// Update orders set status='Delivered' where ratingOfStars IS NOT NULL;
// Update cartplaceorder set amountReceived=totalCost ,amountPending=0 ,status='Delivered'
// Update order_details,orders set status='Order Received' where  order_details.orderNumber=orders.orderNumber and productCode !='cartItems';
//  Update orders set shippedDate=DATE_ADD(orderDate, INTERVAL +7 day) where shippedDate='2025-05-23';

/*
The correct name for the function in MySql is DATE_ADD(), but you also use SQL Server syntax for it.
Change to this:

UPDATE my_table
SET created_at = DATE_ADD(delivery_estimate, INTERVAL -30 day) 

or simpler:

UPDATE my_table
SET created_at = delivery_estimate - INTERVAL 30 day
*/



// $stmt1= $conn->prepare($stmt1);


// $stmt1 = "SELECT order_details.productCode,products.productName,products.productLine,products.productVendor,order_details.quantityOrdered,products.buyPrice from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber AND orders.customerNumber = $customerNumberPassed)"; //write it in capital.

$stmt1 = $conn->prepare($stmt1);

// $stmt1 = $conn->prepare("SELECT order_details.productCode,products.productName,products.productLine,products.productVendor,order_details.quantityOrdered,products.buyPrice from products,orders,order_details where (products.productCode = order_details.productCode AND order_details.orderNumber=orders.orderNumber AND customerNumber = 114 )"); //write it in capital.

if (!$stmt1) {
    echo json_encode(["error" => "Statement preparation failed: " . $conn->error]);
    exit();
}

// Bind parameters
// $stmt1->bind_param("i", $customerNumberPassed);//i used as intval is used to convert into integer but if it had not been used then s can also be used
// $stmt1->bind_param("i", $customerNumberPassed);//i used as intval is used to convert into integer but if it had not been used then s can also be used
// $stmt1->bind_param("s", $limit);//i used as intval is used to convert into integer but if it had not been used then s can also be used

// Execute and get result
$stmt1->execute();
$result1 = $stmt1->get_result();
$outp = $result1->fetch_all(MYSQLI_ASSOC);

// Close connections //but for lower one to get execute , don't close the connection but not necessary to not to close 
$stmt1->close();
$conn->close();

// Output the result as JSON
// echo json_encode($outp);//to get result in json format [{},{}...]

?>



<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title></title>
    <!-- <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">   -->
    <!-- yhis bootstrap gives table structure bold and big -->
    <!-- this bootstrap was creating alignment disorder -->

    <link rel="stylesheet" type="" href="styleneeds.css">

</head>

<body>
    <div class="container mt-5">
        <!-- <h2 class="mb-4">Your Orders</h2>   -->
        <table class="table table-bordered">
            <thead>
                <caption>Your ordered products that you have need</caption>
                <tr>
                    <th rowspan="2">products id</th>
                    <th colspan="3">product description</th>
                    <th rowspan="2">Quantity</th>
                    <th rowspan="2">product price</th>
                    <th rowspan="2">Status</th>
                    <!-- <th rowspan="2">Shipped Date</th> -->
                    <th rowspan="2">Mode of Payment</th>

                </tr>

                <tr>
                    <th>Product</th>
                    <th>product name</th>
                    <!-- <th>product category</th> -->
                    <!-- <th>product brand</th> -->
                    <th>Ordered Date</th>
                    <!-- <th></th> -->

                </tr>

            </thead>
            <tbody>
                <?php foreach ($outp as $row): ?>
                    <tr>
                        <td onclick="findHref(this)" style="color:aqua;cursor:pointer">
                            <?php echo htmlspecialchars($row['productCode']); ?></td>
                        <!-- <td><?php //echo htmlspecialchars($row['colorMainImage']); ?></td>   -->
                        <!-- we want to set this as src of image tag -->
                        <td style="cursor:pointer">
                            <div>
                                <p style="font-size:0px" onclick="findHref(this)">
                                    <?php echo htmlspecialchars($row['productCode']); ?>
                                    <img src='<?php echo htmlspecialchars($row['colorMainImage']); ?>'
                                        style="height: 100px;width:auto">
                                </p>
                            </div>
                        </td>
                        <td><?php echo htmlspecialchars($row['productName']); ?></td>
                        <!-- <td><?php //echo htmlspecialchars($row['productLine']); ?></td>   -->
                        <!-- <td><?php //echo htmlspecialchars($row['productVendor']); ?></td>   -->

                        <td><?php echo htmlspecialchars(date('d-m-Y', strtotime($row['orderDate']))); ?></td>
                        <td><?php echo htmlspecialchars($row['quantityOrdered']); ?></td>
                        <td><?php echo htmlspecialchars($row['buyPrice']); ?></td>

                        <td><?php echo htmlspecialchars($row['status']);

                        if ($row['status'] == 'Delivered') {

                            // echo '<br> On ' . htmlspecialchars($row['shippedDate']);
                    
                            echo '<br> On ' . htmlspecialchars(date('d-m-Y', strtotime($row['shippedDate'])));




                            // $past = new DateTime("18 May 2021");
                            // $now = new DateTime("now");
                            // $dist_past = new DateTime("2002-09-21 18:15:00");
                            // $dist_future = new DateTime("12-09-2036");






                            // echo date("d-m-Y");//today
                            // echo date('d-m-Y', strtotime($row['shippedDate'].'+7 days'));//7 days after


                            // $today=date("d-m-Y");//not works
                            // $LastDateToReturn=date('d-m-Y', strtotime($row['shippedDate'] . '+7 days'));


                            // only string based data compare and only in this format.
//                             $date1 = "1998-11-24";
// $date2 = "1997-03-26";

// // Use comparison operator to 
// // compare dates
// if ($date1 > $date2)
                            

                            $today=new DateTime("now");
                            $LastDateToReturn= new DateTime (date('d-m-Y', strtotime($row['shippedDate'] . '+7 days'))); //comarisons works only with new object
                    
                            // if (date("d-m-Y")< date('d-m-Y', strtotime($row['shippedDate'] . '+7 days'))) { 









                            if ($today < $LastDateToReturn) { //uncomment when operation on return button is performed
 
                                
                                ?>
                                    <!-- <button type="button" class="returnOrder" onclick="initiateReturn('ORD12345', 'PROD67890')">Return</button>  -->

                                  
                                    <button type="button" class="returnOrder" onclick="initiateReturn('<?php echo htmlspecialchars($row['orderNumber']); ?>', '<?php echo htmlspecialchars($row['productCode']); ?>')">Return</button> 

                                    
                                   
                                    <?php

                                //    select *from yourTableName where DATE(yourColumnName) > (NOW() - INTERVAL 7 DAY); Note : Let's say the current date is '2019-06-02' Let us first create a table.
                    
                                // php // Add days to current date and display it echo date('d.m.Y H:i:s', strtotime('+7 days', time()));
                    
                               // Add days to date and display it
                               // echo date('Y-m-d', strtotime($Date. ' + 10 days'));
                    
                                // Update orders SET shippedDate='2025-03-17' where status='Delivered';
                    
                            } //uncomment when if is uncommented



                            /*
                            Complete Workflow Explanation
Initiation:

Customer clicks "Return" button on order/product page

JavaScript function opens return page with orderNumber and productCode as URL parameters

Return Page:

Displays order information

Provides return options (return, replace, refund)

Lists possible return reasons

Allows photo upload for verification

Submits data to process_return.php

Processing (process_return.php):

Validates and stores uploaded photo

Checks payment mode (cash/card) to determine which table to update

Updates order status to 'return_placed'

Creates record in returns table

Returns success/error response

Pickup Completion:

When item is picked up, admin system calls update_return_status.php

Updates status to 'returned_successfully' in both returns and order tables

Additional Logic:

For replacements: System would need to create a new order

For refunds: Payment system would need to process the refund based on original payment method

Email notifications would typically be sent at each stage

This implementation covers all the requested functionality including different return options, reasons, photo verification, and proper database updates based on payment method.
                            */

                        }

                        ?>
                        </td>
                        <td><?php echo htmlspecialchars($row['modeOfPayment']); ?></td>
                    </tr>
                <?php endforeach; ?>
            </tbody>
        </table>
    </div>
</body>
<script src="allPageCommonScript.js"></script>
<script src="needdatabase.js"></script>
<script src="pagesnavigation.js"></script>











</html>