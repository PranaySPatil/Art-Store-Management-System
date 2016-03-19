<?php

//***Username is not encoded as json but only displayed on the page***

require ('db_connect.php');
$db = new DB_CONNECT();
$response=array();
$purchase_report=array();
//Sellers name is sent by post
$name=mysqli_escape_string($db->con,$_POST['name']);
$query="Select username 
		From login
		Where owner='$name'";
$result = mysqli_query($db->con,$query);
if ($row=mysqli_fetch_array($result)) {
	$username=$row['username'];
	echo $username;
}
else{
	echo "No such user exists";
}
?>