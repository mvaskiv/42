<?php
$conn =new mysqli('localhost', 'root', 'qweqwe');

$query = '';
$sqlScript = file('db_camagru.sql');
foreach ($sqlScript as $line)	{

    $startWith = substr(trim($line), 0 ,2);
    $endWith = substr(trim($line), -1 ,1);

    if (empty($line) || $startWith == '--' || $startWith == '/*' || $startWith == '//') {
        continue;
    }

    $query = $query . $line;
    if ($endWith == ';') {
        mysqli_query($conn,$query) or die('<div class="error-response sql-import-response">Problem in executing the SQL query <b>' . $query. '</b></div>');
        $query= '';
    }
}
sleep(6);
header("Location: /");
