<!DOCTYPE html>
<html>
<head>
	<link type="text/css" rel="stylesheet" href="styles.css">
	<link rel="stylesheet" type="text/css" href="styles/home.css" />
	<link rel="stylesheet" type="text/css" href="styles/menu.css" />
	<link rel="stylesheet" type="text/css" href="styles/goods.css" />
	<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Raleway" />
	<link href="https://fonts.googleapis.com/css?family=Open+Sans" rel="stylesheet">
</head>
<?php
	session_start();

	require_once("utils.php");

	function get_option_list($content_array) {
		$option_list = "";

		if (!empty($content_array)) {
			foreach ($content_array as $entry) {
				$option_list = $option_list . "<option value=" . $entry["name"] . ">" . $entry["name"] . "</option>";
			}
		}
		return $option_list;
	}

	function get_select_category_list($content_array) {
		$option_list = "";

		if (!empty($content_array)) {
			foreach ($content_array as $entry) {
				$option_list = $option_list . "<option name='categories' value='" . $entry["name"] . "'>" . $entry["name"] . "</option>";
			}
		}
		return $option_list;
	}

	function get_product_list($products) {
		$html = "";
		foreach ($products as $product) {
			$html = $html . "<div><p>" . $product["id"] . "</p><p>" . $product["user_name"] . "</p><p>" . $product["sum"] . "</p><p> " . str_replace("\"", "", substr($product["purchase"], 1, -1)) . "</p></div>";
		}
		return $html;
	}

	if ($_SESSION["auth_data"]["user"] === NULL || $_SESSION["auth_data"]["rights"] !== "admin") {
		header("Location: /");
		exit();
	}
	$product_list = get_option_list(array_values(mysqli_fetch_all(send_db_request("SELECT name FROM products;"), MYSQLI_ASSOC)));
	$db_categories = array_values(mysqli_fetch_all(send_db_request("SELECT name FROM categories;"), MYSQLI_ASSOC));
	$category_list = get_option_list($db_categories);
	$select_category_list = get_select_category_list($db_categories);
	$user_list = get_option_list(array_values(mysqli_fetch_all(send_db_request("SELECT name FROM users;"), MYSQLI_ASSOC)));
	$orders = get_product_list(mysqli_fetch_all(send_db_request("SELECT * FROM orders;"), MYSQLI_ASSOC));
?>
	<body style="background-color: aliceblue;">
		<div class="home" style="background-color: aliceblue;">
			<div class="top_bar">
			<i style="color: darkred">Welcome,</i><br/><?php echo $_SESSION["auth_data"]["user"]; ?>
				<div class="contact menu">
					<a href="#"><button class="dropbutton"><h1 class="menu">Contacts</h1>
						</button></a>
				</div>
				<div class="about menu">
					<a href="#"><button class="dropbutton"><h1 class="menu">About</h1>
						</button></a>
				</div>
				<div class="login menu">
					<form action="login/logout.php" method="post"><button type="submit" name="submit"
						method="post" class="dropbutton" value="Log out"><h1 class="menu">Log out</h1>
					</button></form>
				</div>
				<hr color="darkred" size="1">
			</div>
		</div>
		<div class="home" style="background-color: aliceblue;">
			<div style="float:left;width:480px;"><h1 class="logo">Users and Stock Manager</h1></div>
				<div style="float:left;width:540px;">
				<?php show_session_cookie_and_unset("change-password-status"); ?>
				<form action="user/change_password.php" method="post">
					<h1 class="sidebar">To change your admin pass type it here: </h1>
					<input type="password" name="password" value=""/>
					<input type="submit" name="submit" value="OK"/>
				</form></div>
			<br><br><br>
			<hr size="1" width="100%" color="black">
			<div style="float:left;width:170px;background-color:aliceblue;">
				<div class="menu">
					<a href="admin_panel.php"><button class="dropbutton"><h1 class="menu">Orders & Stock</h1>
						</button></a>
				</div><br></br>
				<div class="menu">
					<a href="user_man.php"><button class="dropbutton"><h1 class="menu">Manage Users</h1>
					</button></a>
				</div><br></br>
				<div class="menu">
					<a href="product_man.php"><button class="dropbutton"><h1 class="menu">Manage Stock</h1>
						</button></a>
				</div>
			</div>
			<div class="content_cent" style="width:849px;float:left;background-color:aliceblue;">
			<h1 class="sidebar" style="font-size:25px;margin-top:10px;">Users Creation and Deletion</h1>
			<?php show_session_cookie_and_unset("create-account-status"); ?>
			<form action="../user/create_user.php" method="post"><span class="sidebar_l">
				<h1 class="sidebar">Create user</h1>
				Name: <input type="text" name="name" value="" />
				Password: <input type="password" name="password" value="" />
				Rights:
				<select style="font-size:12px;background-color:aliceblue;border:0px;" name="rights">
					<option value="admin">admin</option>
					<option value="buyer">buyer</option>
				</select>
				<input type="submit" name="submit" value="OK" />
			</form>
			<hr size=1 style="color:dimgrey;">
			<?php show_session_cookie_and_unset("delete-account-status"); ?>
			<form action="../user/delete_user.php" method="post">
				<h1 class="sidebar">Delete user</h1>
				Name:
				<select style="font-size:12px;background-color:aliceblue;border:0px;" name="name">
					<?php echo $user_list; ?>
				</select>
				<input type="submit" name="submit" value="OK" /></span>
			</form>
			<hr size=1 style="color:dimgrey;">
			</div>
			<a style="text-decoration:none;"href="index.php"><i style="color: darkred">Back to store</i><br/></a>
		</div>
		</body>
	</head>
</html>
