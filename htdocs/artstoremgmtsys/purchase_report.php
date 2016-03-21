<?php
require ('db_connect.php');
$db = new DB_CONNECT();
$response=array();
$purchase_report=array();
//Currently logged in users id is sent by post
$username=mysqli_escape_string($db->con,$_POST['username']);

$query="Select P.name as p_name, A.name as a_name, subject, p_price, opt_price, date
		From ($username" . "_purchased natural join painting as P) join artist as A on P.id = A.id
		ORDER BY date DESC";
$result = mysqli_query($db->con,$query);
while ($row=mysqli_fetch_array($result)) {
	$painting_name=$row["p_name"];
	$artist_name=$row["a_name"];
	$subject=$row["subject"];
	$purchase_price=$row["p_price"];
	$optimal_price=$row["opt_price"];
	$date=$row["date"];
	$purchase_report[]=array('painting_name'=> $painting_name, 'artist_name'=> $artist_name, 'subject'=> $subject, 'purchase_price'=> $purchase_price, 'optimal_price'=> $optimal_price, 'date'=> $date );
}
$response['purchase_report'] =$purchase_report;
echo json_encode($response);
?>