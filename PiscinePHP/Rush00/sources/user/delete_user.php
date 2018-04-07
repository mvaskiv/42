<?php
	include "../send_db_request.php";

	if ($_POST["name"] === "" || $_POST["submit"] !== "OK")
		exit("Please fill all the fields in\n");
	
	send_db_request("DELETE FROM users_orders WHERE user_name = '" .  $_POST["name"] . "';", "Error deleting product 1");
	send_db_request("DELETE FROM users WHERE name = '" .  $_POST["name"] . "';", "Error deleting user");
	echo "The product has been deleted";
?>
