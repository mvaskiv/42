#!/usr/bin/php
<?php
$file = fopen($argv[1], 'r');
$buf = fread($file, filesize($argv[1]));
function ft_rep($word) {return strtoupper($word[1]);}
$buf = preg_replace_callback('/<a[^>]*>.*?<\/a>/ms', function ($w) {
	$x = preg_replace_callback('/(>)(.*)(<.*)/sU', function ($w) {
		$x = strtoupper($w[2]);
			return "$w[1]$x$w[3]";}, $w[0]);
	$x = preg_replace_callback('/(title=")(.*?)(")/ms', function ($w) {
		$x = strtoupper($w[2]);
		return "$w[1]$x$w[3]";}, $x);
	return "$x";}, $buf);
echo $buf."\n";
?>