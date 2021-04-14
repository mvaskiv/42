<?php
    if (file_exists("../utilities/db_config.php")) {
        require_once("../utilities/db_config.php");}
    else {require_once("utilities/db_config.php");}
    $sql = "SELECT * FROM img WHERE id = '" . $_GET['id'] . "'";
    $result = $mysqli->query($sql);
    $json = include("upostu.php");
?>