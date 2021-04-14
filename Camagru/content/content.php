<?php
    session_start();
    if (file_exists("../utilities/db_config.php")) {require_once("../utilities/db_config.php");}
    else {require_once("utilities/db_config.php");}
    $sql = "SELECT * FROM img ORDER BY id DESC LIMIT 5";
    $result = send_db_request($sql);
?>
<?php
    if (file_exists("../utilities/db_config.php")) {require_once("../utilities/db_config.php");}
    else {require_once("utilities/db_config.php");}
    if (file_exists("content/user_post.php")) {require_once("content/user_post.php");}
    else {require_once("user_post.php");}
?>
