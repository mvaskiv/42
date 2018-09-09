<?php
    session_start();
    require_once("../utilities/db_config.php");
    if (empty($_SESSION['auth_data']["user"])) {
        echo "loggedout";
    }
    else if (isset($_POST['send']) && !(empty($_POST['new_comment'])) && isset($_SESSION['auth_data']["user"])) {
        $_POST['new_comment'] = get_valid_input($_POST['new_comment']);
        $dbq = $dbh->prepare("SELECT id FROM users WHERE login = '" . $_SESSION['auth_data']["user"] ."'");
        $dbq->execute();
        $user_id = $dbq->fetchColumn();
        $photoid = $_POST['photoid'];
        $sql = "INSERT INTO comments(photo, user, content, posted) VALUES ('$photoid', '$user_id', '" . $_POST['new_comment'] . "', NOW());";
        send_db_request($sql);
        echo "success";
    }
    else if (isset($_POST['delete_comment']) && isset($_SESSION['auth_data']["user"])) {
        $dbq = $dbh->prepare("SELECT id FROM users WHERE login = '" . $_SESSION['auth_data']["user"] ."'");
        $dbq->execute();
        $user_id = $dbq->fetchColumn();
        $comid = $_POST['commentid'];
        $sql = "DELETE FROM comments WHERE user = '$user_id' AND id = '$comid';";
        send_db_request($sql);
        echo "success";
    }

