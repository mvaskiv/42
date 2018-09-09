<?php
    if (isset($_COOKIE['user']) && !(isset($_SESSION['auth_data']))) {
        $_SESSION['auth_data'] = array();
        $_SESSION['auth_data']["user"] = $_COOKIE["user"];
    }