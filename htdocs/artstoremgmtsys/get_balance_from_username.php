<?php
require ('db_connect.php');
$db = new DB_CONNECT();
//Currently logged in users id is sent by post
$username=mysqli_escape_string($db->con,$_POST['username']);

$query="Select balance 
		From login
		Where username='$username'";
$result = mysqli_query($db->con,$query);
if($row=mysqli_fetch_array($result)) {
	$balance=$row["balance"];
	echo $balance;
}
else{
	echo "Username not found";
}
?>