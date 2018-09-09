<?php
    session_start();
    require_once("../utilities/db_config.php");
    $redirect_pass = "/index.php";
    $_POST["login"] = get_valid_input($_POST["login"]);
    $_POST["first"] = get_valid_input($_POST["first"]);
    $_POST["last"] = get_valid_input($_POST["last"]);
    $_POST["email"] = get_valid_input($_POST["email"]);
    $_POST["password"] = htmlspecialchars($_POST["password"]);
    if ($_POST["login"] == "" || $_POST["password"] == "" || $_POST["send"] !== "Submit" || $_POST["password"] !== $_POST["repeat"]) {
//        set_session_coookie_and_redirect("user-creation", "fail", $redirect_pass);
        echo ("nomatch");
    }
    else if (empty(mysqli_fetch_all(send_db_request("SELECT login FROM users WHERE login ='" . $_POST["login"] . "';"), MYSQLI_ASSOC))) {
        $token = bin2hex(random_bytes(16));
        send_db_request("INSERT INTO users(login, pwd, first, last, email, token, joined) VALUES ('" . $_POST["login"] . "','" . hash("whirlpool", $_POST["password"], FALSE) . "','" . $_POST["first"] . "','" . $_POST["last"] . "','" . $_POST["email"] . "','$token', NOW());");
//        set_session_coookie_and_redirect("user-creation", "success", $redirect_pass);
        require_once("../utilities/mail_body.php");
        $to = $_POST['email'];
        if (!(mail($to, $subject, $message, $headers))) {echo "mailfail" . PHP_EOL;}
        echo ("success");
    }
//    set_session_coookie_and_redirect("user-creation", "duplicate", $redirect_pass);
?>
