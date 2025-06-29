<?php
header('Content-Type: application/json');

// Database connection
$servername = "localhost";
$username = "root";
$password = "#sudha@2402";
$dbname = "shanayabazaar";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die(json_encode(['success' => false, 'message' => 'Database connection failed']));
}

// Process form data
$orderNumber = $_POST['orderNumber'];
$productCode = $_POST['productCode'];
$returnOption = $_POST['returnOption'];
$returnReason = $_POST['returnReason'];
$description = $_POST['description'];

//  <!-- Error: Error processing return: Unknown column 'modeOfPayment' in 'field list' -->

// Handle file upload
$targetDir = "uploads/returns/";
if (!file_exists($targetDir)) {
    mkdir($targetDir, 0777, true);
}

$fileName = basename($_FILES["productPhoto"]["name"]);
$targetFilePath = $targetDir . uniqid() . '_' . $fileName;
$uploadOk = 1;
$imageFileType = strtolower(pathinfo($targetFilePath, PATHINFO_EXTENSION));

// Check if image file is a actual image or fake image
$check = getimagesize($_FILES["productPhoto"]["tmp_name"]);
if($check === false) {
    echo json_encode(['success' => false, 'message' => 'File is not an image.']);
    exit;
}

// Check file size (5MB max)
if ($_FILES["productPhoto"]["size"] > 5000000) {
    echo json_encode(['success' => false, 'message' => 'Sorry, your file is too large.']);
    exit;
}

// Allow certain file formats
$allowedTypes = ['jpg', 'png', 'jpeg', 'gif'];
if (!in_array($imageFileType, $allowedTypes)) {
    echo json_encode(['success' => false, 'message' => 'Sorry, only JPG, JPEG, PNG & GIF files are allowed.']);
    exit;
}

// Try to upload file
if (!move_uploaded_file($_FILES["productPhoto"]["tmp_name"], $targetFilePath)) {
    echo json_encode(['success' => false, 'message' => 'Sorry, there was an error uploading your file.']);
    exit;
}

// Start transaction
$conn->begin_transaction();

try {
    // Check payment mode and update appropriate table
    $paymentMode = null;
    
    // Check orders table first
    $stmt = $conn->prepare("SELECT modeOfPayment FROM order_details WHERE orderNumber = ? AND productCode = ?");
    $stmt->bind_param("ss", $orderNumber, $productCode);
    $stmt->execute();
    $result = $stmt->get_result();
    
    if ($result->num_rows > 0) {
        $row = $result->fetch_assoc();
        $paymentMode = $row['modeOfPayment'];
        
        // Update orders table
        $updateStmt = $conn->prepare("UPDATE orders,order_details SET orders.status = 'return_placed' WHERE order_details.orderNumber = ? AND orders.orderNumber = ? AND order_details.productCode = ? AND order_details.orderNumber=orders.orderNumber" );
        $updateStmt->bind_param("ss", $orderNumber , $orderNumber, $productCode);
        $updateStmt->execute();
    } else {
        // Check cartplaceorder table
        $stmt = $conn->prepare("SELECT modeOfPayment FROM cartplaceorder WHERE orderNumber = ? AND productCode = ?");
        $stmt->bind_param("ss", $orderNumber, $productCode);
        $stmt->execute();
        $result = $stmt->get_result();
        
        if ($result->num_rows > 0) {
            $row = $result->fetch_assoc();
            $paymentMode = $row['modeOfPayment'];
            
            // Update cartplaceorder table
            $updateStmt = $conn->prepare("UPDATE cartplaceorder SET status = 'return_placed' WHERE orderNumber = ? AND productCode = ?");
            $updateStmt->bind_param("ss", $orderNumber, $productCode);
            $updateStmt->execute();
        } else {
            throw new Exception("Order not found");
        }
    }
    
    // Insert into returns table
    $insertStmt = $conn->prepare("INSERT INTO returns (orderNumber, productCode, returnReason, returnOption, description, photoPath, status) 
                                 VALUES (?, ?, ?, ?, ?, ?, 'return_placed')");
    $insertStmt->bind_param("ssssss", $orderNumber, $productCode, $returnReason, $returnOption, $description, $targetFilePath);
    $insertStmt->execute();
    
    // Commit transaction
    $conn->commit();
    
    // echo json_encode(['success' => true, 'message' => 'Return request processed successfully']);
    //now move to need_db.php page


    // Note:
     // Return success with redirect URL
    echo json_encode([
        'success' => true, 
        'message' => 'Return request processed successfully',
        'redirect' => 'need.html?return_success=1&orderNumber=' . urlencode($orderNumber)
    ]);

} catch (Exception $e) {
    // Rollback transaction on error
    $conn->rollback();
    
    // Delete uploaded file if there was an error
    if (file_exists($targetFilePath)) {
        unlink($targetFilePath);
    }
    
    echo json_encode(['success' => false, 'message' => 'Error processing return: ' . $e->getMessage()]);
    // 
}




$conn->close();

//  <script type="text/javascript">
//      window.location.href = `return_page.html?orderNumber=${encodeURIComponent(orderNumber)}&productCode=${encodeURIComponent(productCode)}`;
//      </script>

?>