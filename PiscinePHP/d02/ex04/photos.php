#!/usr/bin/php
<?php
$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $argv[1]);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
$file = curl_exec($ch);
$imgs = preg_replace_callback('/(\<img src=")(.*)(")/sU', function ($w) {
	$image = $w[2];
	$content = file_get_contents($image);
	file_put_contents("image", $content);
	return "done";}
	, $file);
?>