<?php
	session_start();

	require_once("../utils.php");
	
	$_POST["name"] = get_valid_input($_POST["name"]);
	if ($_POST["name"] === "" || $_POST["submit"] !== "OK") {
		set_session_coookie_and_redirect("create-category-status", "Please fill all the fields in", "/product_man.php");
	}
	if (empty(mysqli_fetch_all(send_db_request("SELECT name FROM categories WHERE name ='" . $_POST["name"] . "';"), MYSQLI_ASSOC))) {
		send_db_request("INSERT INTO categories(name) VALUES ('" . $_POST["name"] . "');");
		set_session_coookie_and_redirect("create-category-status", "The category has been created", "/product_man.php");
	}
	set_session_coookie_and_redirect("create-category-status", "The category already exists", "/product_man.php");
?>
