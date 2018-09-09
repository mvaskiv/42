<?php
    session_start();
    require_once("../utilities/db_config.php");
    function auth($login, $pwd) {
        $sql = "SELECT login, pwd FROM users WHERE login = '" . $login . "' AND pwd = '" . hash("whirlpool", $pwd, false) . "';";
        if (empty(mysqli_fetch_row(send_db_request($sql)))) {
            return false;
        }
        return true;
    }
    $_POST["login"] = get_valid_input($_POST["login"]);
    $login = $_POST['login'];
    $_POST["password"] = htmlspecialchars($_POST["password"]);
    $pwd = $_POST['password'];
    $sql2 = "SELECT confirmed FROM users WHERE login = '" . $login . "' AND pwd = '" . hash("whirlpool", $pwd, false) . "';";
    $dbq = $dbh->prepare("SELECT confirmed FROM users WHERE login = '" . $login . "' AND pwd = '" . hash("whirlpool", $pwd, false) . "'");
    $dbq->execute();
    $confirmed = $dbq->fetchColumn();
    if ($confirmed != 1 && $_POST["login"] !== "" && $_POST["password"] !== "" && $_POST["send"] === "Enter" && ($status = auth($_POST["login"], $_POST["password"])) ) {
        echo "confirmation";
    }
    else if ($confirmed == 1 && $_POST["login"] !== "" && $_POST["password"] !== "" && $_POST["send"] === "Enter" && ($status = auth($_POST["login"], $_POST["password"])) ) {
        $_SESSION['auth_data'] = array();
        $_SESSION['auth_data']["user"] = $_POST["login"];
        if (isset($_POST['cookie']) && $_POST['cookie'] === "setme") {
            setcookie("user", $_POST["login"], time() + (86400 * 30), "/");
        }
        echo "success";
    } else {
        echo "Please make sure that your login and pwd are correct";
    }
?>