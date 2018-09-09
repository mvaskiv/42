<?php
	session_start();
	unset($_SESSION['auth_data']);
	setcookie("user", "", time() - 3600, "/");
	echo "success";
?>
