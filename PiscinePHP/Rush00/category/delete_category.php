<?php
	session_start();

	require_once("../utils.php");
	
	$_POST["name"] = get_valid_input($_POST["name"]);
	if ($_POST["name"] === "" || $_POST["submit"] !== "OK") {
		set_session_coookie_and_redirect("delete-category-status", "Please fill all the fields in", "/product_man.php");
	}
	$result = send_db_request("SELECT id FROM categories WHERE name = '" . $_POST["name"] . "';");
	$category_id = mysqli_fetch_all($result, MYSQLI_ASSOC)[0]["id"];
	send_db_request("DELETE FROM product_category WHERE categoryID = '" .  $category_id . "';");
	send_db_request("DELETE FROM categories WHERE name = '" .  $_POST["name"] . "';");
	set_session_coookie_and_redirect("delete-category-status", "The category has been deleted", "/product_man.php");	
?>
