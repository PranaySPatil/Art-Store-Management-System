<?php
require ('db_connect.php');
$db = new DB_CONNECT();
$response=array();
$sale_report=array();
//Currently logged in users id is sent by post
$username=mysqli_escape_string($db->con,$_POST['username']);

$query="Select P.name as p_name, A.name as a_name, subject, s_price, opt_price, date
		From ($username" . "_sold natural join painting as P) join artist as A on P.id = A.id";
$result = mysqli_query($db->con,$query);
while ($row=mysqli_fetch_array($result)) {
	$painting_name=$row["p_name"];
	$artist_name=$row["a_name"];
	$subject=$row["subject"];
	$selling_price=$row["s_price"];
	$optimal_price=$row["opt_price"];
	$date=$row["date"];
	$sale_report[]=array('painting_name'=> $painting_name, 'artist_name'=> $artist_name, 'subject'=> $subject, 'selling_price'=> $selling_price, 'optimal_price'=> $optimal_price, 'date'=> $date );
}
$response['sale_report'] =$sale_report;
echo json_encode($response);
?>