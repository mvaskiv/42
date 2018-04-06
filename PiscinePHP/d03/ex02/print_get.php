<?php
$keyst = implode(" ", array_keys($_GET));
$valt = implode(" ", $_GET);
$keys = explode(" ", $keyst);
$val = explode(" ", $valt);
for ($i = 0; $keys[$i] && $val[$i]; $i++) {
	echo $keys[$i].": ".$val[$i]."\n";
}
?>