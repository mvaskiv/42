#!/usr/bin/php
<?PHP
while (42) {
	echo "Enter a number: ";
	$line = trim(fgets(STDIN));
	if (feof(STDIN))
	{
		echo "^D\n";
		break ;
	}
	if (!(is_numeric($line)))
	{
		echo "'".$line."'"." is not a number\n";
	} 
	else
	{	
		if ($line % 2 == 0) {
			echo "The number ".$line." is even\n";
		} else {
			echo "The number ".$line." is odd\n";
		}
	}
}
?>
