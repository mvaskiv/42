<?php
	include "../send_db_request.php";

	function getRights()
	{
		if (!$_POST["rights"])
			return ("buyer");
		return ($_POST["rights"]);
	}
	
	if ($_POST["name"] === "" || $_POST["password"] || $_POST["submit"] !== "OK")
		exit("Please fill all the fields in\n");
	if (empty(mysqli_fetch_all(send_db_request("SELECT name FROM users WHERE name ='" . $_POST["name"] . "';", ""), MYSQLI_ASSOC))) {
		$sql = "INSERT INTO users(name, password, rights) VALUES ('" . $_POST["name"] . "','" . hash("whirlpool", $_POST["passwd"], FALSE) . "','" . getRights() . "');";
		$result = send_db_request($sql, "Error creating user");
		echo "The user has been created";
	} else {
		echo "The user already exists";
	}
?>
