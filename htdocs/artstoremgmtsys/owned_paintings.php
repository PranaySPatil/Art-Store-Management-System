<?php
require ('db_connect.php');
$db = new DB_CONNECT();
$response=array();
$owned=array();
//Currently logged in users id is sent by post
$username=mysqli_escape_string($db->con,$_POST['username']);

$query="Select P.name as p_name, medium, A.name as a_name, url, sell 
		From (painting as P join artist as A on P.id =A.id ) natural join $username" . "_available";
$result = mysqli_query($db->con,$query);
while ($row=mysqli_fetch_array($result)) {
	$painting_name=$row["p_name"];
	$medium=$row["medium"];
	$artist_name=$row["a_name"];
	$url=$row["url"];
	$sell=$row["sell"];
	$owned[]=array('painting_name'=> $painting_name, 'medium'=> $medium, 'artist_name'=> $artist_name, 'url'=> $url, 'sell'=> $sell );
}
$response['owned'] =$owned;
echo json_encode($response);
?>