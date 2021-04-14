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
		height: 200px;
		width: 400px;
	}
	</style>
	<link type="text/css" rel="stylesheet" href="styles.css">
	<link rel="stylesheet" type="text/css" href="styles/home.css" />
	<link rel="stylesheet" type="text/css" href="styles/menu.css" />
	<link rel="stylesheet" type="text/css" href="styles/goods.css" />
	<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Raleway" />
	<link href="https://fonts.googleapis.com/css?family=Open+Sans" rel="stylesheet">
</head>
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
				<a href="#"><button class="dropbutton"><h1 class="menu">Contacts</h1>
					</button></a>
			</div>
			<div class="about menu">
				<a href="#"><button class="dropbutton"><h1 class="menu">About</h1>
					</button></a>
			</div>
			<hr color="darkred" size="1">
		</div>
		<div class="header">
			<div style="width:350px;position:relative;float:left;">
				<h1 class="logo">Furniture Shop <strong style="color: darkred"><em>4</em>2</strong></h1>
			</div>
	 	</div>
		<div class="home">
			<div class="newuser" style="width:400px;">
				<form action='user/create_user.php' method='post'>
					<h1 class="sidebar">Create an account</h1>
					<table style="position:relative;margin-left:auto;margin-right:auto;text-align:right;margin-bottom:5px;">
						<tr>
							<th>
								<h1 class="sidebar" style="font-size:15px;">Name: </h1>
							</th>
							<th>
								<input style="width:200px;" type="text"name='name' value=''/>
							</th>
						</tr>
						<tr>
							<th>
								<h1 class="sidebar" style="font-size:15px;">Password: </h1>
							</th>
							<th>
								<input style="width:200px;" type='password' name='password' value=''/>
							</th>
						</tr>
					</table>
					<input style="width:200px;" type='submit' name='submit' value='OK'/>
				</form>
			</div>
		</div>
	</div>
</div>
