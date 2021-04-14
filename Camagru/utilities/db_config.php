<?php
	$dbh = new PDO('mysql:host=localhost; dbname=db_camagru', 'root','qweqwe');
	$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$mysqli = new mysqli('localhost', 'root','qweqwe', 'db_camagru');
	PDO::ERRMODE_EXCEPTION;
	function send_db_request($sql) {
		$conn = mysqli_connect('localhost', 'root', 'qweqwe', "db_camagru");
		if (!$conn) {
			echo "Error: Unable to connect to MySQL db." . PHP_EOL;
			exit;
		}
		if (!($result = mysqli_query($conn, $sql))) {
			return null;
		}
		mysqli_close($conn);
		return $result;
	}
	function get_valid_input($inout) {
		return htmlspecialchars(mb_strtolower(trim(strip_tags($inout))));
	}
	function set_session_coookie_and_redirect($cookie_name, $cookie_value, $url) {
		$_SESSION[$cookie_name] = $cookie_value;
		header("Location: " . $url);
		exit;
	}
	function show_session_cookie_and_unset($cookie_name) {
		if (isset($_SESSION[$cookie_name])) {
			echo $_SESSION[$cookie_name];
			unset($_SESSION[$cookie_name]);
		}
	}
?>
