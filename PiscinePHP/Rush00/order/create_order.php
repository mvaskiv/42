<?php
	session_start();
	
	require_once("../utils.php");

	if (!isset($_SESSION["auth_data"]["user"])) {
		set_session_coookie_and_redirect("order-status", "Please log in for placing the order", "/index.php");
	}
	if ($_POST["order"] ==="{}" || $_POST["price"] == 0 || $_POST["submit"] !== "Submit order") {
		set_session_coookie_and_redirect("order-status", "The shopping cart is empty", "/index.php");
	}
	$order = json_decode(@$_POST["order"], true);
	$order = json_encode($order);
	if ($order == NULL) {
		set_session_coookie_and_redirect("order-status", "The order hasn't been found", "/index.php");
	}
	send_db_request("INSERT INTO orders(user_name, sum, purchase) VALUES ('" . $_SESSION["auth_data"]["user"] . "', " . $_POST["price"] . ",'" . $order . "');");
	$result = send_db_request("SELECT id FROM orders WHERE user_name = '" . $_SESSION["auth_data"]["user"] . "';");
	$order_id = mysqli_fetch_all($result, MYSQLI_ASSOC)[0]["id"];
	send_db_request("INSERT INTO users_orders(user_name, orderID) VALUES ('" . $_SESSION["auth_data"]["user"] . "'," . $order_id .");");
	set_session_coookie_and_redirect("order-status", "Your order has been placed", "/index.php");
?>
