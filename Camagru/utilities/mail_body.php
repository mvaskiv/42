<?php

$subject = 'Please, confirm your brand new account';

$headers = "From: admin@camagru.com" . "\r\n";
$headers .= "Reply-To: admin@camagru.com".  "\r\n";
$headers .= "MIME-Version: 1.0\r\n";
$headers .= "Content-Type: text/html; charset=iso-8859-1\r\n";

$message = '<html><body style="width: 100%;">';
$message .= '<div style="padding: 0px;position: relative;margin-top: 30px;margin-left: auto;margin-right: auto;background-color: #fff;border-top: 1px;border-bottom: 1px;border-left: 1px;border-right: 1px;border-radius: 10px;border-style: solid;border-color: #aaa;width: 300px;height: 330px;text-align: center;box-shadow: 1px 11px 95px #aaa;">';
$message .= '<a href="http://127.0.0.1:8080/user/verify.php?mail=' . $_POST["email"] . '&token=' . $token . '&user=' . $_POST["login"] . '">';
$message .= '<p style="color: #03519b;font-family: "PT Sans", sans-serif;font-size: 25px;font-weight: bold;line-height: 35px;text-align: center;">';
$message .= '<br><br><br>Press me to confirm your email<br>';
$message .= '</p></a>';
$message .= '<p style="color: #03519b;font-family: "PT Sans", sans-serif;font-size: 25px;font-weight: bold;line-height: 35px;text-align: center;"><br>to comment, like and<br>share your pictures with others!<br><br><br><br><br>See you soon!</p>';
$message .= '</div>';
$message .= '</body></html>';