<?php
	session_start();

	include "send_db_request.php";

	function productToShow($categoryList, $neededCategory) {
		if ($neededCategory === "all")
			return true;
		return (in_array($neededCategory, $categoryList));
	}

	function getProductCategoryList($categories) {
		$productCategoryList = "<ul>";
		
		foreach ($categories as $category)
			$productCategoryList = $productCategoryList . "<li>" . $category["name"] . "</li>";
		$productCategoryList = $productCategoryList . "</ul>";
		return $productCategoryList;
	}

	function getProductList() {
		$product_list = "";
		$products = mysqli_fetch_all(send_db_request("SELECT name, price FROM products;", ""), MYSQLI_ASSOC);
		foreach ($products as $product) {
			$sql = "SELECT categories.name FROM products JOIN product_category ON products.id = product_category.productID JOIN categories ON product_category.categoryID = categories.id WHERE products.name = '" . $product["name"] . "';";
			$categories = mysqli_fetch_all(send_db_request($sql, ""), MYSQLI_ASSOC);
			$product_list = $product_list . "<div><p>" . $product["price"] . "</p><h2>" . $product["name"] . "</h2><button class='shop-add-to-cart-button'>Add to cart</button>" . getProductCategoryList($categories) . "</div>";
		}
		return $product_list;
	}

	function getSelectedAttr($currentCaterory, $selectedCategory)
	{
		if ($currentCaterory === $selectedCategory)
			return "selected='selected'";
		return "";
	}

	function getCategoryList() {
		$categoryList = "<option " . getSelectedAttr("all", $category) . " value='all'>all</option>";
		
		$categories = mysqli_fetch_all(send_db_request("SELECT name FROM categories;", ""), MYSQLI_ASSOC);
		if (!empty($categories))
			foreach ($categories as $entry)
					$categoryList = $categoryList . "<option " . getSelectedAttr($entry["name"], $category) . " value=" . $entry["name"] . ">" . $entry["name"] . "</option>";
		return ($categoryList);
	}

	if ($_POST["category"])
		$category = $_POST["category"];
	else
		$category = "all";

	$productList = getProductList();
	$categoryList = getCategoryList();
	if ($_SESSION["auth_data"]["user"] === NULL) {
		$login_form = "<form action='login/login.php' method='post'><p>Log into your account</p>Name: <input name='name' value='' />Password: <input name='passwd' value='' /><input type='submit' name='submit' value='OK' /></form>";
		$create_account_form = "<form action='user/create_user.php' method='post'><p>Create an account</p>Name: <input name='name' value=''/>Password: <input name='passwd' value=''/><input type='submit' name='submit' value='OK'/></form>";
	} else {
		$hello = "<h1>Hello, " . $_SESSION["auth_data"]["user"] . "</h1>";
		$change_password_form = "<form action='user/modify_user.php' method='post'><p>Change your account password</p>New password: <input name='passwd' value=''/><input type='submit' name='submit' value='OK'/></form>";
		$logout_form = "<form action='login/logout.php' method='post'><input type='submit' name='submit' value='Log out'/></form>";
	}
?>

<!DOCTYPE html>
<head>
	<link type="text/css" rel="stylesheet" href="styles.css">
</head>
<body>
	<?php echo $hello . $login_form . $create_account_form . $change_password_form . $logout_form ?> 
	<form action="index.php" method="post">
		<select name="category" id="shop-product-filter">
			<?php echo $categoryList; ?>
		</select>
		<input type="submit" name="submit" value="Filter" />
	</form>
	<div id="shop-product-list">
		<?php echo $productList; ?>
	</div>
	
	<div id="cart"></div>
	<form action="order/create_order.php" method="post">
		<input id="order-data-elem" type="hidden" name="order" value="">
		<input type="submit" name="submit" value="Submit order"/>
	</form>
	<script src="cart.js"></script>
</body>
</html>
