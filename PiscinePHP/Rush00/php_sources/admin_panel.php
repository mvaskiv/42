<?php
	session_start();
	
	include "send_db_request.php";

	function getOptionList($contentArray)
	{
		$optionList = "";
		
		if (!empty($contentArray))
			foreach ($contentArray as $entry)
				$optionList = $optionList . "<option value=" . $entry["name"] . ">" . $entry["name"] . "</option>";
		return ($optionList);
	}
	
	function get_select_category_list($contentArray)
	{
		$optionList = "";
		
		if (!empty($contentArray))
			foreach ($contentArray as $entry)
				$optionList = $optionList . "<option name='categories' value='" . $entry["name"] . "'>" . $entry["name"] . "</option>";
		return ($optionList);
	}

	if ($_SESSION["auth_data"]["user"] === NULL || $_SESSION["auth_data"]["rights"] !== "admin") {
		header("Location: /");
		exit();
	}

	function get_product_list($products) {
		// $html = "<div id='order-list'>"
		// foreach($products as $product) {
		// 	<div><p>1</p></div>
		// }
		// $html = $html . "</div>";
	}

	$productList = getOptionList(array_values(mysqli_fetch_all(send_db_request("SELECT name FROM products;", ""), MYSQLI_ASSOC)));
	$dbCategories = array_values(mysqli_fetch_all(send_db_request("SELECT name FROM categories;", ""), MYSQLI_ASSOC));
	$categoryList = getOptionList($dbCategories);
	$select_category_list = get_select_category_list($dbCategories);
	$userList = getOptionList(array_values(mysqli_fetch_all(send_db_request("SELECT name FROM users;", ""), MYSQLI_ASSOC)));
	$orders = mysqli_fetch_all(send_db_request("SELECT * FROM orders;", ""), MYSQLI_ASSOC);
?>

<!DOCTYPE html>
<html>
	<head>
		<title>Admin Panel</title>
		<link type="text/css" rel="stylesheet" href="styles.css">
		<body>
			<h1>Hello, <?php echo $_SESSION["auth_data"]["user"]; ?></h1>

			<form action="user/modify_user.php" method="post">
				<p>Change your account password</p>
				New password: <input name="passwd" value=""/>
				<input type="submit" name="submit" value="OK"/>
			</form>

			<form action="login/logout.php" method="post">
				<input type="submit" name="submit" value="Log out"/>
			</form>

			<h1>Product</h1>

			<form action="../product/create_product.php" method="post">
				<p>Create product</p>
				Name: <input name="name" value="" />
				Price <input type="number" step="0.01" name="price" value="" />
				Product categories:
				<select name="categories[]" multiple>
					<?php echo $select_category_list; ?>
				</select>
				<input type="submit" name="submit" value="OK" />
			</form>

			<!-- <form action="../product/modify_product.php" method="post">
				<p>Modify product</p>
				Product name:
				<select name="name">
					<?php echo $productList; ?>
				</select>
				Product categories:
				<select name="categories[]" multiple>
					<?php echo $select_category_list; ?>
				</select>
				<input type="submit" name="submit" value="OK" />
			</form> -->

			<form action="../product/delete_product.php" method="post">
				<p>Delete product</p>
				Product name:
				<select name="name">
					<?php echo $productList;?>
				</select>
				<input type="submit" name="submit" value="OK" />
			</form>

			<h1>Category</h1>
			<form action="../category/create_category.php" method="post">
				<p>Create category</p>
				Category name: <input name="name" value="" />
				<input type="submit" name="submit" value="OK" />
			</form>
			<form action="../category/delete_category.php" method="post">
				<p>Delete category</p>
				Category name:
				<select name="name">
					<?php echo $categoryList; ?>
				</select>
				<input type="submit" name="submit" value="OK" />
			</form>

			<h1>User</h1>
			<form action="../user/create_user.php" method="post">
				<p>Create user</p>
				Name: <input name="name" value="" />
				Password: <input name="passwd" value="" />
				Rights:
				<select name="rights">
					<option value="admin">admin</option>
					<option value="buyer">buyer</option>
				</select>
				<input type="submit" name="submit" value="OK" />
			</form>

			<!-- <form action="../user/modify_user.php" method="post">
				<p>Modify user</p>
				Name:
				<select name="name">
					<?php echo $userList; ?>
				</select>
				Password: <input name="passwd" value="" />
				Rights: 
				<select name="rights">
					<option value="admin">admin</option>
					<option value="buyer">buyer</option>
				</select>
				<input type="submit" name="submit" value="OK" />
			</form> -->

			<form action="../user/delete_user.php" method="post">
				<p>Delete user</p>
				Name:
				<select name="name">
					<?php echo $userList; ?>
				</select>
				<input type="submit" name="submit" value="OK" />
			</form>
			<h1>Orders</h1>
			<div id="order-list">
				<?php print_r($orders); ?>
			</div>
		</body>
	</head>
</html>
