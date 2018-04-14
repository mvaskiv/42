<?php
	session_start();

	require_once("auth.php");
	require_once("../utils.php");
	
	function get_content($rights) {
		if ($rights === "admin")
			header("Location: /admin_panel.php");
		else if ($rights === "buyer")
			header("Location: /index.php");
	}

	$_POST["name"] = get_valid_input($_POST["name"]);
	$_POST["password"] = htmlspecialchars($_POST["password"]);
	if ($_POST["name"] !== "" && $_POST["password"] !== "" && $_POST["submit"] === "OK" && ($rights = auth($_POST["name"], $_POST["password"])) ) {
		$_SESSION['auth_data'] = array();
		$_SESSION['auth_data']["user"] = $_POST["name"];
		$_SESSION['auth_data']["rights"] = $rights;
		get_content($rights);
	} else {
		set_session_coookie_and_redirect("login-error", "Please make sure that your name and password are correct", "/index.php");
	}
?>
