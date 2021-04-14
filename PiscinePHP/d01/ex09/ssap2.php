#!/usr/bin/php
<?PHP
unset($argv[0]);
$line = implode(" ", $argv);
$arr = preg_split('/\s+/', $line);
$j = 0;
$l = 0;
$k = 0;
for ($i = 0; $arr[$i]; $i++) {
	if (is_numeric($arr[$i])) {
		$num[$j] = $arr[$i];
		$j++;
	}
	else if (ctype_alpha($arr[$i][0])) {
		$alp[$l] = $arr[$i];
		$l++;
	}
	else {
		$oth[$k] = $arr[$i];
		$k++;
	}
}
function ft_sort($a, $b) {
	$a = strtolower($a);
	$b = strtolower($b);
	for ($i = 0; $a[$i] || $b[$i]; $i++) {
		if (is_numeric($a[$i]) || is_numeric($b[$i]) || !(ctype_alnum($b[$i])))
			return 1;
		if ($a[$i] != $b[$i])
			return ($a[$i] < $b[$i]) ? -1: 1;
	}
	return 0;
}
rsort($num);
usort($alp, ft_sort);
sort($oth);
for ($i = 0; $alp[$i]; $i++) {
	echo $alp[$i]."\n";
}
for ($i = 0; $num[$i]; $i++) {
	echo $num[$i]."\n";
}
for ($i = 0; $oth[$i]; $i++) {
	echo $oth[$i]."\n";
}
?>