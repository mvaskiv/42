<?php
	function send_db_request($sql, $error_msg) {
		$conn = mysqli_connect('127.0.0.1', 'root', '123456', "db_shop");
		if (!$conn) {
			echo "Error: Unable to connect to MySQL." . PHP_EOL;
			exit;
		}
		if (!($result = mysqli_query($conn, $sql))) {
			echo "$error_msg\n";
		}
		mysqli_close($conn);
		return $result;
	}
?>
