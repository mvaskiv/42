<?php
	include "../send_db_request.php";

	function auth($name, $passwd) {
		$sql = "SELECT name, password FROM users WHERE name = '" . $name . "' AND password = '" . hash("whirlpool", $passwd, false) . "';";
		if (empty(mysqli_fetch_all(send_db_request($sql, "User name or password is incorrect", MYSQLI_ASSOC)))) {
			return false;
		}
		return mysqli_fetch_all(send_db_request("SELECT rights FROM users WHERE name = '" . $name . "';", "Unable to get user rights"), MYSQLI_ASSOC)[0]["rights"];
	}
?>
