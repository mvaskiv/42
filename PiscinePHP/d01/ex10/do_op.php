#!/usr/bin/php
<?PHP
if ($argc != 4)
{
	echo "Incorrect Parameters\n";
	return ;
}
$a = trim($argv[1]);
$o = trim($argv[2]);
$b = trim($argv[3]);
if ($o == "+")
	$r = $a + $b;
else if ($o == "-")
	$r = $a - $b;
else if ($o == "*")
	$r = $a * $b;
else if ($o == "/")
	$r = $a / $b;
else if ($o == "%")
	$r = $a % $b;
echo $r."\n";
?>