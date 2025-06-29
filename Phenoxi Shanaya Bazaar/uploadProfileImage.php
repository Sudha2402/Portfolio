<?php
error_reporting(0);

// trying to upload by integrating both the above methods
if (isset($_POST['submit']) && isset($_POST['hiddenCustomerNumber'])) {



  $CustomerNumber = $_POST['hiddenCustomerNumber'];

  // echo $CustomerNumber; //1856176940 //it works to successfully receive the CustomerNumber


  if (!empty($_FILES["uploadfile"])) {

    


    // trying another way and it works
    $target_dir = "temporaryProfilePhoto/";
    $target_file = $target_dir . basename($_FILES["uploadfile"]["name"]);
    $imageFileType = pathinfo($target_file, PATHINFO_EXTENSION);
    // $imgname =  "abc.".$imageFileType;
    $imgname = $CustomerNumber . "." . $imageFileType;//it works



    // we want to check the file name exist with same CustomerNumber of any file type

    $files = scandir($target_dir);
    foreach ($files as $file) {
      if ($file != "." && $file != "..") {
        $filetype = pathinfo($file, PATHINFO_EXTENSION);
      }
    }

    $oldfile = $target_dir . $CustomerNumber . "." . $filetype;
    $newfile = $target_dir . $imgname;
    if (file_exists($oldfile)) {
      unlink($oldfile);
    }

    //now this will work for all types of file with customer number same.



    // $upload_success = move_uploaded_file($_FILES["uploadfile"]["tmp_name"], $target_dir . $imgname);//works
    $upload_success = move_uploaded_file($_FILES["uploadfile"]["tmp_name"], $newfile);

    if ($upload_success) {
      echo "&nbsp; Successfully uploaded image!";
    } else {
      echo "&nbsp; Failed to upload image!";
    }
    // echo $imgname;


    // intval($CustomerNumber);//no need here

    $db = mysqli_connect("localhost", "root", "#sudha@2402", "shanayabazaar");


    // Check connection
    if ($db->connect_error) {
      echo json_encode(["error" => "Database connection failed: " . $db->connect_error]);
      exit();
    }

    // ALTER TABLE customers_data ADD COLUMN CustomersProfilePhoto BLOB;

    // select * from customers_data WHERE CustomerNumber=1856176940;

    $sql = "update customers_data Set CustomersProfilePhoto='$newfile' where CustomerNumber='$CustomerNumber'";

    if (!$sql) {
      echo json_encode(["error" => "Statement preparation failed: " . $db->error]);
      exit();
    }

    // Execute query
    mysqli_query($db, $sql);


    // close the connection
    mysqli_close($db);






  }

} else {
  echo "&nbsp; Please select a profile photo to upload!";
}

?>