<?php
require ('db_connect.php');
$db = new DB_CONNECT();

//Currently logged in users ***username ,name ,owner ,address ,balance ,no_of_emp is sent by post***
$username=mysqli_escape_string($db->con,$_POST['username']);
$name=mysqli_escape_string($db->con,$_POST['name']);
$owner=mysqli_escape_string($db->con,$_POST['owner']);
$address=mysqli_escape_string($db->con,$_POST['address']);
$balance=mysqli_escape_string($db->con,$_POST['balance']);
$no_of_emp=mysqli_escape_string($db->con,$_POST['no_of_emp']);


//Update login table
$query="Update login
		Set Name='$name' , owner='$owner' , address='$address' , balance=$balance , no_of_emp=$no_of_emp
		Where username='$username'";

//Run query
mysqli_query($db->con,$query);


?>