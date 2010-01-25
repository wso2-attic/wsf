<?php
require_once("CalendarClient.php");

session_start();
ob_start();
$username = $_POST["username"];
$password = $_POST["password"];
$result = $_POST["Submit"];

/*Get the values entered by the form and send them to the service to check whether the user name and password are correct.*/

$message = "";
if (isset($_POST['Submit']))
{
    $_SESSION["username"]= $_POST['username'];
    $_SESSION["password"]= $_POST['password'];
    try {
        // create CalendarClient..
        $client = new CalendarClient($username, $password);
        $response = $client->login();
        if($response && $response->success == "SUCCESS") {
            header('Location: get_event_client.php');
        }
        else {

            $message .= "<div id=\"errors\">";
            $message .= "<p><em>Oops... the following errors were encountered:</em></p>";
            $message .= "<ul>";
            if($response == NULL) {
                $message .= "<li>login failed, There is a problem in the connnection</li>";
            }else {
                $message .= "<li>login failed, username or password is incorrect</li>";
            }
            $message .= "</ul>";
        }
    }
    catch(Exception $e){
        $message = CalendarClient::handleException($e);
    }

}
ob_end_flush();
?>

<html>
<head>
<link href="./assets/style/style3.css" rel="stylesheet" type="text/css" /></head>
<body>
<div class="form-container">
<?php echo $message; ?>
<table width="300" border="0" align="center" cellpadding="0" cellspacing="1" bgcolor="#CCCCCC">
<tr>
<form name="form1" method="post" action="#">
<td>
<table width="100%" border="0" cellpadding="3" cellspacing="1" bgcolor="#FFFFFF">
<tr>
<td colspan="3"><strong>Member Login </strong></td>
</tr>
<tr>
<td width="78">User Name</td>
<td width="6">:</td>
<td width="294"><input name="username" type="text" id="username"></td>
</tr>
<tr>
<td>Password</td>
<td>:</td>
<td><input name="password" type="password" id="password"></td>
</tr>
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
<td><input type="submit" name="Submit" value="Login"></td>
</tr>
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
<td><a href="register_client.php">Register now</a></td>
</tr>
</table>
</form>
</div>
</body>
</html>


