<!DOCTYPE html>
<html>
<head>
	<style>
	div.newuser {
		text-align: center;
		position: relative;
		margin-left: auto;
		margin-right: auto;
		top: 170px;
		border-radius: 10px;
		border-left: 1px;
		border-right: 1px;
		border-top: 1px;
		border-bottom: 1px;
		border-style: solid;
		border-color: darkslategray;
		background-color: aliceblue;
		height: 100px;
		width: 300px;
	}
	</style>
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

	function get_prod_cat_list($categories) {
		$prod_cat_list = "<ul>";

		foreach ($categories as $category)
			$prod_cat_list = $prod_cat_list . "#" . $category["name"] . " ";
		$prod_cat_list = $prod_cat_list . "</ul>";
		return $prod_cat_list;
	}

	function get_prod_list($chosen_category) {
		$product_list = "";
		if ($chosen_category === "all") {
			$products = mysqli_fetch_all(send_db_request("SELECT name, price, picture FROM products;"), MYSQLI_ASSOC);
		} else {
			$products = mysqli_fetch_all(send_db_request("SELECT products.name, price, picture FROM products JOIN product_category ON products.id = product_category.productID JOIN categories ON product_category.categoryID = categories.id WHERE categories.name = '" . $chosen_category . "';"), MYSQLI_ASSOC);
		}
		foreach ($products as $product) {
			if (!($raw_picture = file_get_contents($product["picture"]))) {
				$picture = "";
			} else {
				$picture = base64_encode($raw_picture);
			}
			$sql = "SELECT categories.name FROM products JOIN product_category ON products.id = product_category.productID JOIN categories ON product_category.categoryID = categories.id WHERE products.name = '" . $product["name"] . "';";
			$categories = mysqli_fetch_all(send_db_request($sql), MYSQLI_ASSOC);
			$product_list = $product_list . "<div style='float:left;margin-left:15px;margin-bottom:15px;width:190px;height:270px;'>
				<img style='width:190px;height:190px;display:block;' src='data:image/png;base64," . $picture . "'>
				<h1 class='sidebar' style='font-size:21px;margin-top:10px;margin-bottom:0px;line-height:0px;'><span>" . $product["name"] . "</span>
				<span style='font-size:15px;float:right;margin-right:5px;margin-top:5px;'>$" . $product["price"] . "</span>
				</h1><i style='font-size:13px;color:dimgrey;'>" . get_prod_cat_list($categories) . "</i><button class='buttonadd shop-add-to-cart-button'>Add to cart</button>" . "</div>";
		}
		return $product_list;
	}

	function get_cat_list() {
		$category_list = "<option value='all'>all</option>";

		$categories = mysqli_fetch_all(send_db_request("SELECT name FROM categories;"), MYSQLI_ASSOC);
		if (!empty($categories))
			foreach ($categories as $entry)
					$category_list = $category_list . "<option value=" . $entry["name"] . ">" . $entry["name"] . "</option>";
		return ($category_list);
	}

	if (isset($_POST["category"]))
		$chosen_category = $_POST["category"];
	else
		$chosen_category = "all";
	$product_list = get_prod_list($chosen_category);
	$category_list = get_cat_list();
	if (!isset($_SESSION["auth_data"]["user"])) {
		$login_form = "<div class='login_form'><form action='login/login.php' method='post'><input type='text' name='name' value='username' /><input type='password' name='password' value='password' /><input type='submit' name='submit' value='OK' /></form></div>";
		$create_account_form = "<form action='user/create_user.php' method='post'><p>Create an account</p>Name: <input name='name' value=''/>Password: <input type='password' name='password' value=''/><input type='submit' name='submit' value='OK'/></form>";
	} else {
		$hello = "<h1>Hello, " . $_SESSION["auth_data"]["user"] . "</h1>";
		$change_password_form = "<form action='user/change_password.php' method='post'><p>Change your account password</p>New password: <input type='password' name='password' value=''/><input type='submit' name='submit' value='OK'/></form>";
		$logout_form = "<form action='login/logout.php' method='post'><input type='submit' name='submit' value='Log out'/></form>";
	}
?>
<body style="background-color: beige;">
	<div class="verytop">
		<div class="hometop">
		<div class="top_bar">
		<i style="color: darkred">Welcome,</i><br/>
		<?php
		if (isset($_SESSION["auth_data"]["user"])) {
			echo $_SESSION["auth_data"]["user"];
		} else {
			echo 'Incognito shopper';
		}
		?>
			<div class="contact menu">
				<a href="index.php"><button class="dropbutton"><h1 class="menu">Back to store</h1>
					</button></a>
			</div>
			<hr color="darkred" size="1">
		</div>
		<div class="header">
			<div style="width:350px;position:relative;float:left;">
				<h1 class="logo">Furniture Shop <strong style="color: darkred"><em>4</em>2</strong></h1>
			</div>
	 	</div>
	</div>
</div>
	<div class="home">
		<?php
		if (isset($_SESSION["auth_data"]["user"]))
		{
			echo "<div class='newuser' style='width:400px;''><form action='user/change_password.php' method='post'><table style='margin-right:40px;'><tr><h1 class='sidebar'>Change your account password</h1><h1 class='sidebar' style='font-size:15px;'>New password:<input type='password' name='password' value=''/><input type='submit' name='submit' value='OK'/></tr></table></form></div>";
		}
		?>
	</div>
 </body>
</html>
