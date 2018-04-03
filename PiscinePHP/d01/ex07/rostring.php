#!/usr/bin/php
<?PHP
$line = trim($argv[1]);
$arr = preg_split('/\s+/', $line);
for($i = 0; $arr[$i]; $i++);
$temp = $arr[$i];
$arr[$i] = $arr[0];
$arr[0] = $temp;
unset($line);
$line = implode(" ", $arr);
$line = trim($line);
if ($line)
	echo $line."\n";
?>