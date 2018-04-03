#!/usr/bin/php
<?PHP
function ft_split($str) {
	$arr = preg_split('/\s+/', $str);
	sort($arr);
	return $arr;
}
/*$qw = ft_split("Hello   World    AAA");
for($i = 0; $i < 3; $i++)
{
	echo $qw[$i]."\n";
}*/
?>
