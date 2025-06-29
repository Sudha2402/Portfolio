<?php



$conn = new mysqli("localhost", "root", "#sudha@2402", "shanayabazaar");


if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_FILES['file'])) {

    $file = $_FILES['file'];
    // formData.append('path', path);
    // we want to trace this
    $filePath = $_POST['path'];
    $EmailAddress = $_POST['EmailAddress'];
    $ProductCode = $_POST['productCode'];



    $uploadDir = $filePath . '/review/';//works when "product/women/ethnic wear/kurta sets/Pakistani Suit  Women Kurta Pair/review/" directory is given
    // we want to create this review folder in case when review is not present
    if (!file_exists($uploadDir)) {
        mkdir($uploadDir, 0777, true);
    }




    // unique file name generated
    $fileName = uniqid() . '_' . $file['name'];

    $direc = $uploadDir . $fileName;
    // moving the uploaded file from temp location to our target location
    if (move_uploaded_file($file['tmp_name'], $uploadDir . $fileName)) {
        $stmt = $conn->prepare("INSERT INTO customersreviewimages (img_url, prd_code, EmailAddress) VALUES (?,?,?)");
        $stmt->bind_param("sss", $direc, $ProductCode, $EmailAddress);
        // execute the  $stmt
        $stmt->execute();



        echo 'File uploaded successfully.';
    } else {
        echo 'Failed to upload file.';
    }
}


$stmt->close();
$conn->close();

?>