<?php
	session_start();

	include "../send_db_request.php";
	
	// echo ($_SESSION["auth_data"]["user"]);
	// echo(substr(str_replace("\"", "", $_POST["order"]), 1, -1));
	if ($_POST["order"] === "" || $_POST["submit"] !== "Submit order")
		echo "Please fill all the fields in\n";
	$name = $_SESSION["auth_data"]["user"];
	$order = $_POST["order"];
	// echo($order);
	// echo("INSERT INTO orders(user_name, sum, purchase) VALUES ('" . $name . "',0,'" . $order . "');");
	send_db_request("INSERT INTO orders(user_name, sum, purchase) VALUES ('" . $name . "',0,'" . $order . "');", "Error creating order 1");
	$result = send_db_request("SELECT id FROM orders WHERE user_name = '" . $_SESSION["auth_data"]["user"] . "';", "Error getting order ID");
	$order_id = mysqli_fetch_all($result, MYSQLI_ASSOC)[0]["id"];
	send_db_request("INSERT INTO users_orders(user_name, orderID) VALUES ('" . $_SESSION["auth_data"]["user"] . "'," . $order_id .");", "Error creating order 2");
?>
