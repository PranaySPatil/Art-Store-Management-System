 <?php
require ('sql_connect.php');
$username=mysql_escape_string($_POST['uname']);
$password=mysql_escape_string($_POST['pass']);
if (!$_POST['uname'] | !$_POST['pass'])
 {
echo ("<SCRIPT LANGUAGE='JavaScript'>
        window.alert('You did not complete all of the required fields')
        window.location.href='htmlogin.html'
        </SCRIPT>");
exit();
     }
$sql= mysql_query("SELECT * FROM `login_users` WHERE `username` = '$username' AND `password` = '$password'");
if(mysql_num_rows($sql) > 0)
{
// echo ("<SCRIPT LANGUAGE='JavaScript'>
//         window.alert('Login Succesfully!.')
//         window.location.href='login_page.html'
//         </SCRIPT>");
echo ("<strong>You're Successfully Logged In.</strong>");
exit();
}
else{
// echo ("<SCRIPT LANGUAGE='JavaScript'>
//         window.alert('Wrong username password combination.Please re-enter.')
//         window.location.href='login_page.html'
//         </SCRIPT>");
echo ("<strong color='red'>Invalid username or password.</strong>");
exit();
}

?>