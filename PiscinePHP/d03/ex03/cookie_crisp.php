<?php
if ($_GET['action'] == 'set'){
	setcookie($_GET['name'], $_GET['value'], time() + (86400 * 30), "/");
}
else if ($_GET['action'] == 'get'){
	$temp = $_COOKIE[$_GET['name']];
	if ($temp != NULL)
		echo $_COOKIE[$_GET['name']]."\n";
}
else if ($_GET['action'] == 'del')
	setcookie($_GET['name'], "", time() - 3600);
?>