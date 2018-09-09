<?php
    session_start();
    require_once("../utilities/db_config.php");
    if (isset($_POST['submit'])) {
//        $image = $_FILES['photo']['name'];
        $iname = rand(0,99999);
        while (file_exists("../user_posts/" . $iname)) {
            $iname = rand(0,9999999);
        }
        $target = "../user_posts/" . $iname;
        $user = $_SESSION["auth_data"]["user"];
        $user_id = mysqli_fetch_row(send_db_request("SELECT id FROM users WHERE login = '$user'"));
        $sql = "INSERT INTO img (photo, user, added) VALUES ('$iname', '" . $user_id[0] . "', NOW())";
        send_db_request($sql);
        if (move_uploaded_file($_FILES['photo']['tmp_name'], $target)) {
            header("Location: /");
        } else {
            echo "Failed to upload image";
        }
    }
?>