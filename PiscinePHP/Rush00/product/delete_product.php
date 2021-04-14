<?php
	session_start();

	require_once("../utils.php");
	
	if ($_POST["name"] === "" || $_POST["submit"] !== "OK") {
		set_session_coookie_and_redirect("delete-product-status", "Please fill all the fields in", "/product_man.php");
	}
	send_db_request("DELETE FROM products WHERE name = '" .  $_POST["name"] . "';");
	set_session_coookie_and_redirect("delete-product-status", "The product has been deleted", "/product_man.php");
?>
