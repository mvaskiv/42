<?php
	session_start();

	require_once("../utils.php");

	$_POST["name"] = get_valid_input($_POST["name"]);
	$_POST["price"] = floatval($_POST["price"]);
	if ($_POST["name"] === "" || $_POST["price"] === "" || $_POST["picture"] === "" || $_POST["price"] < 0 || empty($_POST["categories"]) || $_POST["submit"] !== "OK") {
		set_session_coookie_and_redirect("create-product-status", "Please fill all the fields in", "/product_man.php");
	}
	if (empty(mysqli_fetch_all(send_db_request("SELECT name FROM products WHERE name ='" . $_POST["name"] . "';"), MYSQLI_ASSOC))) {
		send_db_request("INSERT INTO products(name, price, picture) VALUES ('" . $_POST["name"] . "','" . $_POST["price"] . "','" . $_POST["picture"] . "');", "Error creating user");
		$result = send_db_request("SELECT id FROM products WHERE name = '" . $_POST["name"] . "';", "Error getting product ID");
		$product_id = mysqli_fetch_all($result, MYSQLI_ASSOC)[0]["id"];
		foreach($_POST["categories"] as $category) {
			$result = send_db_request("SELECT id FROM categories WHERE name = '" . $category . "';", "Error getting a category");
			$category_id = mysqli_fetch_all($result, MYSQLI_ASSOC)[0]["id"];
			send_db_request("INSERT INTO product_category(productID, categoryID) VALUES ('" . $product_id . "','" . $category_id .  "');");
		}
		set_session_coookie_and_redirect("create-product-status", "The product has been created", "/product_man.php");
	}
	set_session_coookie_and_redirect("create-product-status", "The product already exists", "/product_man.php");
?>
