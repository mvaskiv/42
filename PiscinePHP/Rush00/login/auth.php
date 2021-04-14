<?php
	require_once("../utils.php");

	function auth($name, $password) {
		$sql = "SELECT name, password FROM users WHERE name = '" . $name . "' AND password = '" . hash("whirlpool", $password, false) . "';";
		if (empty(mysqli_fetch_all(send_db_request($sql), MYSQLI_ASSOC))) {
			return false;
		}
		return mysqli_fetch_all(send_db_request("SELECT rights FROM users WHERE name = '" . $name . "';"), MYSQLI_ASSOC)[0]["rights"];
	}
?>
