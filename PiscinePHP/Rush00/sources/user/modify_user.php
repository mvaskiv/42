<?php
	session_start();
	include "../send_db_request.php";

	function getRights()
	{
		if (!$_POST["rights"])
			return ("buyer");
		return ($_POST["rights"]);
	}
	
	if ($_POST["passwd"] === "" || $_POST["submit"] !== "OK")
		exit("Please fill all the fields in\n");
	$sql = "UPDATE users SET password = '" . hash("whirlpool", $_POST["passwd"], FALSE) . "' WHERE name = '" . $_SESSION["auth_data"]["user"] . "';";
	$res = send_db_request($sql, "Error editing password");
	echo "Your password has been changed";
?>
