<?php
	include "../send_db_request.php";

	if ($_POST["name"] === "" || $_POST["price"] === "" || $_POST["price"] < 0 || empty($_POST["categories"]) || $_POST["submit"] !== "OK")
		exit("Please fill all the fields in\n");
	if (empty(mysqli_fetch_all(send_db_request("SELECT name FROM products WHERE name ='" . $_POST["name"] . "';", ""), MYSQLI_ASSOC))) {
		send_db_request("INSERT INTO products(name, price) VALUES ('" . $_POST["name"] . "','" . $_POST["price"] . "');", "Error creating user");
		$result = send_db_request("SELECT id FROM products WHERE name = '" . $_POST["name"] . "';", "Error getting product ID");
		$product_id = mysqli_fetch_all($result, MYSQLI_ASSOC)[0]["id"];
		foreach($_POST["categories"] as $category) {
			$result = send_db_request("SELECT id FROM categories WHERE name = '" . $category . "';", "Error getting a category");
			$category_id = mysqli_fetch_all($result, MYSQLI_ASSOC)[0]["id"];
			send_db_request("INSERT INTO product_category(productID, categoryID) VALUES ('" . $product_id . "','" . $category_id .  "');",
							"Error getting product ID");
		}
		echo "The product has been created";
	} else {
		echo "The product already exists";
	}
?>
