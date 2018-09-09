<?php
    session_start();
    require_once("../utilities/db_config.php");

    if (isset($_POST['submit'])) {
        $image = $_FILES['avatar']['name'];
        $image_text = "avatar";
        $target = "avatars/".basename($image);
        $user = $_SESSION["auth_data"]["user"];
        $user_id = mysqli_fetch_row(send_db_request("SELECT id FROM users WHERE login = '$user'"));
        if (isset($user_id)) {
            send_db_request("DELETE FROM avatars WHERE user = '" . $user_id[0] . "';");
        }
        $sql = "INSERT INTO avatars (user, image, image_text) VALUES ('" . $user_id[0] . "', '$image', '$image_text')";

        send_db_request($sql);

        if (move_uploaded_file($_FILES['avatar']['tmp_name'], $target)) {
            header("Location: /");
        } else {
            echo "Failed to upload image";
        }
    }
?>