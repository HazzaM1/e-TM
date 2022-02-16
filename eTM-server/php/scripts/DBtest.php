<?php

$db_host='localhost';
$db_port='3306';
$db_user = 'root';
$db_pass = '';
$db_name = 'etm';

$conn = mysqli_connect($db_host,$db_user,$db_pass)OR die('Unable to connect to database! Please try again later.');
		mysqli_select_db($conn, $db_name);
	
$result = $conn->query("SELECT * FROM orders");

if ($result->num_rows > 0) 
	{echo "\n";
	while($row = $result->fetch_assoc()) 
		{while ($property = $result->fetch_field())	
			{echo $property->name . " : " . $row[$property->name]. " | ";}
		echo "\n";}} 
else 
	{echo "0 results";}

$conn->close();
?>