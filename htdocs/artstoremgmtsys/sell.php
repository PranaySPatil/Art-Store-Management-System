<?php

//***username(current_user) pid and price***
//is sent by post
require_once ('db_connect.php');
$db = new DB_CONNECT();

//Currently logged in users id is sent by post
$username=mysqli_escape_string($db->con,$_POST['username']);
$pid=mysqli_escape_string($db->con,$_POST['pid']);
$price=mysqli_escape_string($db->con,$_POST['price']);

//Update username_available
$query="Update $username" ."_available 
		Set sell = 1
		Where pid = $pid ;" ;

$query .="Delete from available
		  Where pid=$pid;" ;
		

$query .="Insert into available
		  Values ( $pid, $price ) ;" ;
		  
mysqli_multi_query($db->con,$query);

?>