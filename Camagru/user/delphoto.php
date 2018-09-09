<?php
    session_start();
    require_once("../utilities/db_config.php");
    if (empty($_SESSION['auth_data']["user"])) {
        echo "loggedout";
    }
    else if (isset($_POST['photoid']) && $_POST['send'] === "Delete" && isset($_SESSION['auth_data']["user"])) {
        $user = $_SESSION['auth_data']["user"];
        $user_id = mysqli_fetch_row(send_db_request("SELECT id FROM users WHERE login = '$user'"));
        $user_id = $user_id[0];
        $photoid = $_POST['photoid'];
        $id[0] = $photoid;
        $photoid = preg_replace('/[^0-9]/', '', $photoid);
        $sql = "DELETE FROM img WHERE user = '$user_id' AND id = '$photoid';";
        $sql2 = "DELETE FROM comments WHERE user = '$user' AND photo = '$photoid';";
        $sql3 = "DELETE FROM likes WHERE user = '$user_id' AND photo = '$photoid';";
        send_db_request($sql);
        send_db_request($sql2);
        send_db_request($sql3);
        $dbq = $dbh->prepare("ALTER TABLE img AUTO_INCREMENT = 1");
        $dbq->execute();
        echo "success";
    } else {
        echo "fail";
    }