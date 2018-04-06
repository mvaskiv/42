#!/usr/bin/php
<?php
date_default_timezone_set('Europe/Kiev');
$file = '/var/run/utmpx';
$fd = fopen($file, 'r');
$i = 0;
while ($info = fread($fd, 628)){
	$arr = unpack('a256user/a4id/a32line/ipid/itype/I2time/a256host/', $info);
	if (!(preg_match('/utmpx.*/', $arr['user'])) && (preg_match('/^[a-z]/', $arr['user'])) && $arr[type] == 7) {
		$data[$i] = $arr;
		$i++;
	}
}
sort($data);
for ($i = 0; $data[$i]; $i++) {
	echo $data[$i]['user'];
	echo "  ";
	echo $data[$i]['line'];
	echo "  ";
	echo strftime("%b %e %H:%M", $data[$i]['time1']);
	echo "\n";
}
?>