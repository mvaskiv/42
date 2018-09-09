<?php
    require_once("../utilities/db_config.php");
    $redirect_pass = "/index.php";
    $email_ver = get_valid_input($_GET["mail"]);
    $token_ver = get_valid_input($_GET["token"]);
    $user_ver = get_valid_input($_GET['user']);
    $dbq = $dbh->prepare("SELECT email FROM users WHERE token = '" . $token_ver . "' AND login = '" . $user_ver . "'");
    $dbq->execute();
    $verify = $dbq->fetchColumn();
    if ($verify === $email_ver) {
        $dbq = $dbh->prepare("UPDATE users SET confirmed = '1' WHERE email = '" . $email_ver . "' AND login = '" . $user_ver . "'");
        $dbq->execute();
        $message = '<html><body style="width: 100%;">';
        $message .= '<div style="padding: 0px;position: relative;margin-top: 30px;margin-left: auto;margin-right: auto;background-color: #fff;border-top: 1px;border-bottom: 1px;border-left: 1px;border-right: 1px;border-radius: 10px;
        border-style: solid;border-color: #aaa;width: 300px;height: 330px;text-align: center;box-shadow: 1px 11px 95px #aaa;">';
        $message .= '<p style="color: #03519b;font-family: "PT Sans", sans-serif;font-size: 25px;font-weight: bold;line-height: 35px;text-align: center;">';
        $message .= '<br><br><br><br><br><br>Nice, now you can access all features.<br><br><br>';
        $message .= '<a href="/" style="text-decoration: none;">click here to get to the gallery</a>';
        $message .= '</p>';
        $message .= '</div>';
        $message .= '</body></html>';
        echo $message;
    } else {
        header("Location: /broken.php");
    }