#!/usr/bin/php
<?PHP
function ft_is_sort($arr)
{
	$temp = $arr;
	sort($temp);

	for($i = 0; $arr[$i]; $i++)
	{
		if ($temp[$i] != $arr[$i])
			return false;
	}
	return true;
}
?>