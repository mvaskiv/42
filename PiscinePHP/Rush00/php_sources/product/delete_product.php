<?php
	include "../send_db_request.php";
	
	if ($_POST["name"] === "" || $_POST["submit"] !== "OK")
			exit("Please fill all the fields in\n");
	$product_id = mysqli_fetch_all(send_db_request("SELECT id FROM products WHERE name = '" . $_POST["name"] . "';", "Error getting product ID"), MYSQLI_ASSOC)[0]["id"];
	send_db_request("DELETE FROM product_category WHERE productID = '" .  $product_id . "';", "Error deleting product 1");
	send_db_request("DELETE FROM products WHERE name = '" .  $_POST["name"] . "';", "Error deleting product 2");
	echo "The product has been deleted";
?>
