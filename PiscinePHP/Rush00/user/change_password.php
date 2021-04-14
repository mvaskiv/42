<?php
	session_start();

	require_once("../utils.php");
	
	$_POST["password"] = htmlspecialchars($_POST["password"]);
	if ($_POST["password"] !== "" && $_POST["submit"] === "OK") {
		send_db_request("UPDATE users SET password = '" . hash("whirlpool", $_POST["password"], FALSE) . "' WHERE name = '" . $_SESSION["auth_data"]["user"] . "';");
		$_SESSION["change-password-status"] = "Your password has been changed";
	}
	if ($_SESSION["auth_data"]["rights"] === "admin")
		header("Location: /admin_panel.php");
	else
		header("Location: /index.php");
?>
