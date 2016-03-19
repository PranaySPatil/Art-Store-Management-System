<?php

//***username(current_user) seller's username(from get_username_from_name.php) pid and price***
//is sent by post
require_once ('db_connect.php');
$db = new DB_CONNECT();

//Function to calculate optimal price
function get_opt_price($pid,$db){
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
		return $newprice;
	} 
	else{
		echo "Sorry, no data exists for selected painting";
	}
}

//Currently logged in users id is sent by post
$username=mysqli_escape_string($db->con,$_POST['username']);
$seller=mysqli_escape_string($db->con,$_POST['seller']);
$pid=mysqli_escape_string($db->con,$_POST['pid']);
$price=mysqli_escape_string($db->con,$_POST['price']);
$date=date_create();
$curr_date = $date->format('Y-m-d');
//Calculate optimal_price
$optimal_price=get_opt_price($pid,$db);

//Insert to buyers table
$query="Insert into $username" . "_available
		Values ( $pid, 0 );" ;
		
//Delete from sellers table
$query .="Delete from $seller" . "_available
		  Where pid = $pid;" ;
		
//Update painting
$query .="Update painting 
		  Set sold_by = sold_to, date = '$curr_date', price = $price
		  Where pid = $pid;";
		
$query .="Update painting 
		  Set sold_to = '$username'
		  Where pid = $pid;" ;	
		
//Delete from available for sale
$query .="Delete from available
		  Where pid = $pid;";
		
//Update buyers purchased table		
$query .="Insert $username" ."_purchased 
		  Values ( $pid, '$curr_date', $price, $optimal_price );";
		
//Update sellers sold table				
$query .="Insert $seller" . "_sold 
		  Values ( $pid, '$curr_date', $price, $optimal_price );";

//Update balance of buyer and seller
$query .="Update login
		  Set balance=balance - $price
		  Where username='$username';";
$query .="Update login
		  Set balance=balance + $price
		  Where username='$seller';";
//Run queries
mysqli_multi_query($db->con,$query);

?>