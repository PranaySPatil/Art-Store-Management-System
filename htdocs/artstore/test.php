<?php
    $user = 'root';
    $pass = '';
    $db = 'artstore';

    $db = new mysqli('localhost', $user, $pass, $db) or die("Unable to Connect");
    //echo "Connected to DB";
    $mystring = exec('C:\\Python27\\python.exe C:\\xampp\\htdocs\\artstore\\process.py ICR1.jpg out.txt 2>&1');
   if(!$mystring){
       echo "python exec failed";
   } else {
       echo "<br />";
       echo "successfully executed!";
   }
?>