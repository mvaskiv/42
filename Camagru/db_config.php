<?php
	$dbh = new PDO('mysql:host=fdb21.awardspace.net; dbname=2700527_camagru', '2700527_camagru','qweqwe123');
	$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$mysqli = new mysqli('fdb21.awardspace.net', '2700527_camagru','qweqwe123', '2700527_camagru');
	function send_db_request($sql) {
		$conn = mysqli_connect('fdb21.awardspace.net', '2700527_camagru', 'qweqwe123', "2700527_camagru");
		if (!$conn) {
			echo "Error: Unable to connect to MySQL." . PHP_EOL;
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
