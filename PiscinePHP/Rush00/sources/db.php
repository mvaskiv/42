#!/usr/bin/php
<?php
	$conn = mysqli_connect('127.0.0.1', 'root', '123456', "db_shop");

	if (!$conn) {
		echo "Error: Unable to connect to MySQL." . PHP_EOL;
		echo "Debugging errno: " . mysqli_connect_errno() . PHP_EOL;
		echo "Debugging error: " . mysqli_connect_error() . PHP_EOL;
		exit;
	}

	$sql = "SELECT * FROM `products`";

	if (!($result = mysqli_query($conn, $sql))) {
		echo "Error creating database: " . mysqli_connect_errno() . PHP_EOL;
	}
	else {
		// echo "Success";
		print_r(mysqli_fetch_all($result, MYSQLI_ASSOC));
		// print_r(mysqli_fetch_array($result));
		// print_r(mysqli_fetch_array($result));
		
		// var_dump($result);
	}
?>
