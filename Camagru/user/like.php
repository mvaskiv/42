<?php
    session_start();
    require_once("../utilities/db_config.php");
    if (empty($_SESSION['auth_data']["user"])) {
        echo "loggedout";
    }
    if (isset($_POST['like']) && isset($_SESSION['auth_data']["user"]) && empty($_POST['new_comment'])) {
        $user = $_SESSION['auth_data']["user"];
        $photoid = $_POST['photoid'];
        $user_id = mysqli_fetch_row(send_db_request("SELECT id FROM users WHERE login = '$user'"));
        if (empty(mysqli_fetch_row(send_db_request("SELECT id FROM likes WHERE user = '" . $user_id[0] . "' AND photo = '$photoid'")))) {
            $sql = "UPDATE img SET likes = likes + 1 WHERE id = '$photoid';";
            $sql2 = "INSERT INTO likes(user, photo) VALUES('" . $user_id[0] . "', '$photoid');";
            send_db_request($sql);
            send_db_request($sql2);
        } else if (!(empty(mysqli_fetch_row(send_db_request("SELECT id FROM likes WHERE user = '" . $user_id[0] . "' AND photo = '$photoid'"))))) {
            $sql = "UPDATE img SET likes = likes - 1 WHERE id = '$photoid';";
            $sql2 = "DELETE FROM likes WHERE user = '" . $user_id[0] . "' AND photo = '$photoid';";
            send_db_request($sql);
            send_db_request($sql2);
    }
    echo "success";
}