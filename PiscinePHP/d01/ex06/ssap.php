#!/usr/bin/php
<?PHP
unset($argv[0]);
$line = implode(" ", $argv);
$arr = preg_split('/\s+/', $line);
sort($arr);
for ($i = 0; $arr[$i]; $i++)
	echo $arr[$i]."\n";
?>