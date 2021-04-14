#!/usr/bin/php
<?PHP
if (!($argv[2]))
{
	$line = trim($argv[1]);
	$arr = preg_split('/\s+/', $line);
	$line = implode(" ", $arr);
	$line = trim($line);
	if ($line)
		echo $line."\n";
}
?>