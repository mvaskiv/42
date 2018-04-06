#!/usr/bin/php
<?php
setlocale(LC_TIME, 'fr_FR.UTF-8');
date_default_timezone_set('Europe/Paris');
$line = trim($argv[1]);
if (!($line))
	return ;
if (!(preg_match('/^\w+ \d{1,2} \w+ \d{4} \d{2}:\d{2}:\d{2}$/', $line)))
	{
		echo "Wrong Format\n";
		return ;
	}
$arr = explode(" ", $line);
$time = explode(":", $arr[4]);
for ($i = 1; $i <= 12; $i++) {
	if (strftime("%B",mktime(0,0,0,$i,1,0)) == strtolower($arr[2])) {
		$month = $i;
		break ;
	}
}
if (strftime("%A", mktime($time[0], $time[1], $time[2], $month, (int)$arr[1], (int)$arr[3])) == $arr[0])
	echo mktime($time[0], $time[1], $time[2], $month, (int)$arr[1], (int)$arr[3])."\n";
else
	{
		echo "Wrong Format\n";
		return ;
	}
?>