<?php
	require ('sql_connect.php');
	$result = mysql_query("SELECT * FROM `paintings`");
	$json = array();
	if(mysql_num_rows($result)){
	    while($row=mysql_fetch_assoc($result)){
	        //  cast results to specific data types
	        $json['testData'][]=($row);
	    }

	echo json_encode($json);   
}
?>