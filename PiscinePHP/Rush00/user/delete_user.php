<?php
	session_start();

	require_once("../utils.php");

	if ($_POST["name"] === "" || $_POST["submit"] !== "OK") {
		set_session_coookie_and_redirect("delete-account-status", "Please fill all the fields in", "/user_man.php");
	}
	send_db_request("DELETE FROM users_orders WHERE user_name = '" .  $_POST["name"] . "';");
	send_db_request("DELETE FROM users WHERE name = '" .  $_POST["name"] . "';");
	set_session_coookie_and_redirect("delete-account-status", "The account has been deleted", "/user_man.php");
?>
