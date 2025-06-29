<?php
header('Content-Type: application/json');

// Database connection
// $conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");
$servername = "localhost";
$username = "root";
$password = "#sudha@2402";
$dbname = "shanayabazaar";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die(json_encode(['success' => false, 'message' => 'Database connection failed']));
}


$orderNumber = $_POST['orderNumber'];
$productCode = $_POST['productCode'];

// Start transaction
$conn->begin_transaction();

try {
    // Update returns table
    $updateReturnStmt = $conn->prepare("UPDATE returns SET status = 'returned_successfully' WHERE orderNumber = ? AND productCode = ?");
    $updateReturnStmt->bind_param("ss", $orderNumber, $productCode);
    $updateReturnStmt->execute();
    
    // Check payment mode and update appropriate order table
    $paymentMode = null;
    
    // Check orders table first
    $stmt = $conn->prepare("SELECT modeOfPayment FROM orders WHERE orderNumber = ? AND productCode = ?");
    $stmt->bind_param("ss", $orderNumber, $productCode);
    $stmt->execute();
    $result = $stmt->get_result();
    
    if ($result->num_rows > 0) {
        $row = $result->fetch_assoc();
        $paymentMode = $row['modeOfPayment'];
        
        // Update orders table
        $updateStmt = $conn->prepare("UPDATE orders SET status = 'returned_successfully' WHERE orderNumber = ? AND productCode = ?");
        $updateStmt->bind_param("ss", $orderNumber, $productCode);
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
            $updateStmt = $conn->prepare("UPDATE cartplaceorder SET status = 'returned_successfully' WHERE orderNumber = ? AND productCode = ?");
            $updateStmt->bind_param("ss", $orderNumber, $productCode);
            $updateStmt->execute();
        } else {
            throw new Exception("Order not found");
        }
    }
    
    // Commit transaction
    $conn->commit();
    
    echo json_encode(['success' => true, 'message' => 'Return status updated successfully']);
} catch (Exception $e) {
    // Rollback transaction on error
    $conn->rollback();
    echo json_encode(['success' => false, 'message' => 'Error updating return status: ' . $e->getMessage()]);
}

$conn->close();
?>