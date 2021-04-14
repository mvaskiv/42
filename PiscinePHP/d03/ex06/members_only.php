<?php
$img = base64_encode(file_get_contents("../img/42.png"));
$name = $_SERVER[PHP_AUTH_USER];
$pwd = $_SERVER[PHP_AUTH_PW];
$pass = "jaimelespetitsponeys";
if ($name == "zaz" && $pass == $pwd) {
	header('Content-Type: text/html');
	echo "<html><body>\nHello Zaz<br />\n<img src='data:image/png;base64,$img'>\n</body></html>\n";
}
else {
	header('Content-Type: text/html');
	echo "<html><body>That area is accessible for members only</body></html>\n";
}
?>