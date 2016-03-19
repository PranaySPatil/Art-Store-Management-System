<?php
require ('db_connect.php');
$db = new DB_CONNECT();
$response=array();
$available=array();
//Currently logged in users id is sent by post
$username=mysqli_escape_string($db->con,$_POST['username']);

$query="Select P.name as p_name, medium, A.name as a_name, sold_to, Q.price, url 
		From ( ( available as Q join painting as P on Q.pid = P.pid)  join artist as A on P.id = A.id) 
		Where sold_to <> '$username'";
$result = mysqli_query($db->con,$query);
while ($row=mysqli_fetch_array($result)) {
	$painting_name=$row["p_name"];
	$medium=$row["medium"];
	$artist_name=$row["a_name"];
	$sold_to=$row["sold_to"];
	$price=$row["price"];
	$url=$row["url"];
	$available[]=array('painting_name'=> $painting_name, 'medium'=> $medium, 'artist_name'=> $artist_name, 'sold_to'=> $sold_to, 'price'=> $price, 'url'=> $url );
}
$response['available'] =$available;
echo json_encode($response);
?>