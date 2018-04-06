#!/usr/bin/php
<?php
$line = trim($argv[1]);
if (!($line))
{
	return ;
}
$line = preg_replace('/\t+/', " ", $line);
$arr = preg_split('/\s+/', $line);
$line = implode(" ", $arr);
echo $line."\n";
?>