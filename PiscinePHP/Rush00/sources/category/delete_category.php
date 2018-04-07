<?php
	include "../send_db_request.php";
	
	if ($_POST["name"] === "" || $_POST["submit"] !== "OK")
			exit("Please fill all the fields in\n");
	$result = send_db_request("SELECT id FROM categories WHERE name = '" . $_POST["name"] . "';", "Error getting category ID");
	$category_id = mysqli_fetch_all($result, MYSQLI_ASSOC)[0]["id"];
	send_db_request("DELETE FROM product_category WHERE categoryID = '" .  $category_id . "';", "Error deleting category");
	send_db_request("DELETE FROM categories WHERE name = '" .  $_POST["name"] . "';", "Error deleting category");
?>
