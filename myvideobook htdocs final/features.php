<?php
header('Content-Type: application/json');
require_once 'db_connect.php';

try {
    //JSON data
    $json = file_get_contents('php://input');
    $data = json_decode($json, true);
    
    if (!isset($data['action'])) {
        throw new Exception("Action parameter is required.");
    }

    switch ($data['action']) {
        case 'saveBookmark':
            handleSaveBookmark($data);
            break;
            
        case 'getBookmark':
            handleGetBookmark($data);
            break;
            
        default:
            throw new Exception("Invalid action specified.");
    }
    
} catch(PDOException $e) {
    echo json_encode(['success' => false, 'message' => 'Database error: ' . $e->getMessage()]);
} catch(Exception $e) {
    echo json_encode(['success' => false, 'message' => $e->getMessage()]);
}

function handleSaveBookmark($data) {
    // Validating required fields
    if (!isset($data['userID']) || !isset($data['bookmarkPage'])) {
        throw new Exception("Required fields (userID and bookmarkPage) are missing.");
    }
    
    global $conn;
    $userID = $data['userID'];
    $bookmarkPage = $data['bookmarkPage'];
    $bookID = isset($data['bookID']) ? $data['bookID'] : 0;
    $categoryName = isset($data['categoryName']) ? $data['categoryName'] : null;
    
    // Checking if bookmark exists
    if ($bookID) {
        $stmt = $conn->prepare("SELECT bookmarkID FROM bookmark WHERE userID = :userID AND bookID = :bookID");
        $stmt->bindParam(':userID', $userID);
        $stmt->bindParam(':bookID', $bookID);
    } else {
        $stmt = $conn->prepare("SELECT bookmarkID FROM bookmark WHERE userID = :userID AND CategoryName = :categoryName");
        $stmt->bindParam(':userID', $userID);
        $stmt->bindParam(':categoryName', $categoryName);
    }
    
    $stmt->execute();
    $existing = $stmt->fetch(PDO::FETCH_ASSOC);
    
    if ($existing) {
        // Updating existing bookmark
        $stmt = $conn->prepare("UPDATE bookmark SET bookmarkPage = :bookmarkPage WHERE bookmarkID = :bookmarkID");
        $stmt->bindParam(':bookmarkPage', $bookmarkPage);
        $stmt->bindParam(':bookmarkID', $existing['bookmarkID']);
        $stmt->execute();
    } else {
        // Inserting new bookmark
        $stmt = $conn->prepare("INSERT INTO bookmark (userID, bookID, CategoryName, bookmarkPage) 
                              VALUES (:userID, :bookID, :categoryName, :bookmarkPage)");
        $stmt->bindParam(':userID', $userID);
        $stmt->bindParam(':bookID', $bookID);
        $stmt->bindParam(':categoryName', $categoryName);
        $stmt->bindParam(':bookmarkPage', $bookmarkPage);
        $stmt->execute();
    }
    
    echo json_encode(['success' => true, 'message' => 'Bookmark saved successfully']);
}

function handleGetBookmark($data) {
    // Validating required fields
    if (!isset($data['userId'])) {
        throw new Exception("User ID is required.");
    }
    
    global $conn;
    $userId = $data['userId'];
    $bookId = isset($data['bookId']) ? $data['bookId'] : null;
    $categoryName = isset($data['categoryName']) ? $data['categoryName'] : null;
    
  
    if ($bookId) {
        $stmt = $conn->prepare("SELECT bookmarkPage FROM bookmark WHERE userID = :userId AND bookID = :bookId");
        $stmt->bindParam(':userId', $userId);
        $stmt->bindParam(':bookId', $bookId);
    } else {
        $stmt = $conn->prepare("SELECT bookmarkPage FROM bookmark WHERE userID = :userId AND CategoryName = :categoryName");
        $stmt->bindParam(':userId', $userId);
        $stmt->bindParam(':categoryName', $categoryName);
    }
    
    $stmt->execute();
    $result = $stmt->fetch(PDO::FETCH_ASSOC);
    
    if ($result && isset($result['bookmarkPage'])) {
        echo json_encode([
            'success' => true,
            'bookmarkPage' => (int)$result['bookmarkPage']
        ]);
    } else {
        echo json_encode([
            'success' => true,
            'bookmarkPage' => null
        ]);
    }
}
?>