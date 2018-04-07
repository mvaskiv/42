<?php
	session_start();

	include "auth.php";
	
	function getContent($rights)
	{
		if ($rights === "admin")
			header("Location: /admin_panel.php");
		else if ($rights === "buyer")
			header("Location: /index.php");
	}
	
	if ($_POST["name"] !== "" && $_POST["passwd"] !== "" && $_POST["submit"] === "OK" && ($rights = auth($_POST["name"], $_POST["passwd"])) ) {
		$_SESSION['auth_data'] = array();
		$_SESSION['auth_data']["user"] = $_POST["name"];
		$_SESSION['auth_data']["rights"] = $rights;
		getContent($rights);
	} else {
		echo "Please make sure that your name and password are correct\n";
	}
?>
