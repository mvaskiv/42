<?php
	include "../send_db_request.php";		
	
	if ($_POST["name"] === "" || $_POST["submit"] !== "OK")
		echo "Please fill all the fields in\n";
	if (empty(mysqli_fetch_all(send_db_request("SELECT name FROM categories WHERE name ='" . $_POST["name"] . "';", ""), MYSQLI_ASSOC))) {
		send_db_request("INSERT INTO categories(name) VALUES ('" . $_POST["name"] . "');", "Error creating category");
		echo "The category has been created";
	} else {
		echo "The category already exists";
	}
?>
