<?php
require ('db_connect.php');
$db = new DB_CONNECT();
$username=mysqli_escape_string($db->con,$_POST['username']);
$password=mysqli_escape_string($db->con,$_POST['password']);

$response=array();
$login=array();
$status="Success";
$query="Select password from login where username = '$username' ";
$result = mysqli_query($db->con,$query);
if ($row=mysqli_fetch_array($result)) {
	$saved_password=$row["password"];
	if(strcmp($saved_password,$password)==0){
		$status="Success";
		$query="Select owner,address,balance,no_of_emp,name from login where username='$username'";
		$result = mysqli_query($db->con,$query);
		$row=mysqli_fetch_array($result);
		$owner=$row["owner"];
		$address=$row["address"];
		$balance=$row["balance"];
		$no_of_emp=$row["no_of_emp"];
		$name=$row["name"];
		$login[]=array('status'=> $status, 'owner'=> $owner, 'address'=> $address, 'balance'=> $balance, 'no_of_emp'=> $no_of_emp, 'name'=> $name );
	}
	else{
		$status="Incorrect Password";
		$login[]=array('status'=> $status);
	}
} 
else{
	$status="Incorrect Username";
	$login[]=array('status'=> $status);
}
$response['login'] =$login;
echo json_encode($response);

?>