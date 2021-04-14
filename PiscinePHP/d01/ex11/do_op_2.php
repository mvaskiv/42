#!/usr/bin/php
<?PHP
if ($argc != 2)
{
	echo "Incorrect Parameters\n";
	return ;
}
$line = trim($argv[1]);
$arr = preg_split('/\s+/', $line);
$a = trim($arr[0]);
$o = trim($arr[1]);
$b = trim($arr[2]);
if (!(is_numeric($a)) || !(is_numeric($b)))
{
	echo "Syntax Error\n";
	return ;
}
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
else
{
	echo "Syntax Error\n";
	return ;
}
echo $r."\n";
?>