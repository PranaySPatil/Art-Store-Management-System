<?php
require_once ('db_connect.php');
$db = new DB_CONNECT();
$pid=mysqli_escape_string($db->con,$_REQUEST['pid']);
$query="Select pid,date,price from painting where pid = '$pid' ";
$result = mysqli_query($db->con,$query);
if ($row=mysqli_fetch_array($result)) {
	date_default_timezone_set('Asia/Kolkata');
	$date=date_create($row["date"]);
	$price=$row["price"];
	$curr_date=date_create();
	$diff=date_diff($date,$curr_date);
	$period = $diff->format("%m")/12;
	$newprice=round($price*pow(1.085,$period));
	echo $newprice;
} 
else{
	echo "Sorry, no data exists for selected painting";
	
}
?>