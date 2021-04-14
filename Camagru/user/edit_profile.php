<?php
    session_start();
    require_once("../utilities/db_config.php");
    $redirect_pass = "/index.php";
    $error = 0;
    $success = 0;
    $_POST["login"] = get_valid_input($_POST["login"]);
    $_POST["email"] = get_valid_input($_POST["email"]);
    $_POST["password"] = htmlspecialchars($_POST["password"]);
    if ($_POST['login'] != "" && $_POST["send"] === "Submit") {
        $user = $_SESSION['auth_data']["user"];
        $dbq = $dbh->prepare("UPDATE users SET login = '" . $_POST['login'] . "' WHERE login = '$user'");
        if (!($dbq->execute())) {$error = 1;} else {
            $_SESSION['auth_data']["user"] = $_POST['login'];
            $success += 1;
        }
    }
    if ($_POST["send"] == "Submit" && $_POST["password"] != "" && $_POST["password"] == $_POST["repeat"]) {
        $user = $_SESSION['auth_data']["user"];
//        $dbq = $dbh->prepare("SELECT id FROM users WHERE login = '$user'");
//        $dbq->execute();
//        $user_id = $dbq->fetchColumn();
        $dbq = $dbh->prepare("UPDATE users SET pwd = '" . hash("whirlpool", $_POST["password"], FALSE) . "' WHERE login = '$user'");
        if (!($dbq->execute())) {$error = 1;} else {$success += 1;}
    }
    if ($_POST['email'] != "" && $_POST["send"] === "Submit") {
        $user = $_SESSION['auth_data']["user"];
        $dbq = $dbh->prepare("UPDATE users SET email = '" . $_POST['email'] . "' WHERE login = '$user'");
        if (!($dbq->execute())) {$error = 1;} else {$success += 1;}
    }
    if ($success >= 1) {
        echo "success";
    } else {
        echo "ops";
    }

