<?php
	session_start();

	require_once("../utils.php");

	function get_rights() {
		if (!$_POST["rights"])
			return ("buyer");
		return ($_POST["rights"]);
	}
	
	if ($_SESSION["auth_data"]["rights"] === "admin")
		$redirect_pass = "/user_man.php";
	else
		$redirect_pass = "/index.php";
	$_POST["name"] = get_valid_input($_POST["name"]);
	$_POST["password"] = htmlspecialchars($_POST["password"]);
	if ($_POST["name"] === "" || $_POST["password"] === "" || $_POST["submit"] !== "OK") {
		set_session_coookie_and_redirect("create-account-status", "Please fill all the fields in", $redirect_pass);
	}
	if (empty(mysqli_fetch_all(send_db_request("SELECT name FROM users WHERE name ='" . $_POST["name"] . "';"), MYSQLI_ASSOC))) {
		send_db_request("INSERT INTO users(name, password, rights) VALUES ('" . $_POST["name"] . "','" . hash("whirlpool", $_POST["password"], FALSE) . "','" . get_rights() . "');");
		set_session_coookie_and_redirect("create-account-status", "The account has been created", $redirect_pass);
	}
	set_session_coookie_and_redirect("create-account-status", "The account already exists. Please select another login", $redirect_pass);
?>
