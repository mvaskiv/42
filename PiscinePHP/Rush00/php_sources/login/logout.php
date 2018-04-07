<?php
	session_start();
	unset($_SESSION['auth_data']);
	header("Location: /");
?>
