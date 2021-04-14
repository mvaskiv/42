<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width">
    <meta name="apple-mobile-web-app-title" content="Camagru">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <!--        ICON-->
    <link rel="apple-touch-startup-image" href="apple-touch-icon.png">
    <link rel=”apple-touch-icon” href="apple-touch-icon.png">

    <!--        STYLESHEETS-->
    <link rel="stylesheet" type="text/css" media="screen and (min-width: 768px)" href="styles/desktop/icon.css">
    <link rel="stylesheet" type="text/css" media="screen and (max-width: 768px)" href="styles/mobile/icon-mobile.css">
    <link rel="stylesheet" type="text/css" media="screen and (min-width: 768px)" href="styles/desktop/font.css">
    <link rel="stylesheet" type="text/css" media="screen and (max-width: 768px)" href="styles/mobile/font-mobile.css">
    <link rel="stylesheet" type="text/css" media="screen and (min-width: 768px)" href="styles/desktop/field.css">
    <link rel="stylesheet" type="text/css" media="screen and (max-width: 768px)" href="styles/mobile/field-mobile.css">
    <link rel="stylesheet" type="text/css" media="screen and (min-width: 768px)" href="styles/desktop/main.css">
    <link rel="stylesheet" type="text/css" media="screen and (max-width: 768px)" href="styles/mobile/main-mobile.css">
    <link href="https://fonts.googleapis.com/css?family=Pacifico" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Open+Sans" rel="stylesheet">
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.0.10/css/all.css" integrity="sha384-+d0P83n9kaQMCwj8F4RJB66tzIwOKmrdb46+porD/OvrJ+37WqIM7UoBtwHO6Nlg" crossorigin="anonymous">
    <title>Camagru</title>
</head>
<body>
<header>
    <?php require_once("content/header.php"); ?>
</header>
<?php
$message .= '<div style="padding: 0px;position: relative;margin-top: 130px;margin-left: auto;margin-right: auto;background-color: #fff;border-top: 1px;border-bottom: 1px;border-left: 1px;border-right: 1px;border-radius: 10px;
border-style: solid;border-color: #aaa;width: 300px;height: 330px;text-align: center;box-shadow: 1px 11px 95px #aaa;">';
$message .= '<p style="color: #03519b;font-family: "PT Sans", sans-serif;font-size: 25px;font-weight: bold;line-height: 35px;text-align: center;">';
$message .= '<br><br><br><br><br><br>Ooops, seems like your link is broken<br>';
$message .= '</p>';
$message .= '</div>';
$message .= '</body></html>';
echo $message;
?>