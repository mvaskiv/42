<?php
	$mysql_user = 'root';

	$mysql_path = "~/mamp/mysql/bin/mysql";

	$command = $mysql_path . " -u " . $mysql_user . " -p < ./db_shop.sql";

	exec($command);
?>
