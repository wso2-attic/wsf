<?php

require_once("defines.php");
require_once(REGISTRY_PATH. "RemoteRegistry.php");

session_start();

$username = $_POST["username"];
$password = $_POST["password"];

$login_failed = FALSE;
if($username !== NULL && !empty($username))
{
	$rr = new RemoteRegistry(REGISTRY_ATOM_INTERFACE, $username, $password);
	$response = $rr->rateResource(LABS_PHP_HOME, 5);
	
	if($response == "200")
	{
		$_SESSION["wsf_php_demo_site_username"] = $username;
		$_SESSION["wsf_php_demo_site_password"] = $password;
		header("Location: http://" . $_SERVER['HTTP_HOST']
				 . dirname($_SERVER['PHP_SELF'])
				 . "/index.php"); 
	}
	else
	{
		$login_failed = true;
	}
}



?>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<?php
if(WEB_VERSION == "php")
{
?>
    <title>Login - PHP Web Services - Code, Samples, Demos and Tutorials</title>
<?php
}
else if(WEB_VERSION == "c")
{
?>
    <title>Login - C Web Services - Code, Samples, Demos and Tutorials</title>
<?php
}
?>
	<link rel="Shortcut Icon" href="favicon.ico" type="image/x-icon" />
	<link href="styles/template.css" rel="stylesheet" type="text/css"/>
</head>
<body>
	<div id="page">

		<?php
			require("template/template_header.php");
		 ?>
		<?php
			require("template/start_content.php");
		 ?>
		<div id="content">
			<div id="welcome">
            <?php
            if(WEB_VERSION == "php")
            {
            ?>
                <h2> Login to WSO2 WSF/PHP Demonstartions</h2>
            <?php
            }
            else if(WEB_VERSION == "c")
            {
            ?>
                <h2> Login to WSO2 WSF/C Demonstartions</h2>
            <?php
            }
            ?>
				<p> 
				  <?php
					if($login_failed)
					{
					   echo '<font color="red">Login failed, Please try again with correct username and password. </font>';
					}
				   ?>
				</p>
			</div>

		                                     <form action="login.php" method="post" id="login">
												<div>
		                                            <div class="login_button_left">&nbsp;</div>
		                                            <div class="login_button">
		                                            	<table>
		                                            		<tr>
		                                            			<td>Name</td>
		                                            			<td>
		                                            				<input name="username" type="text"/>
		                                            			</td>
		                                            		</tr>
		                                            		<tr>
		                                            			<td>Password</td>
		                                            			<td>
		                                            				<input name="password" type="password"/>
		                                            			</td>
		                                            		</tr>
		                                            	</table>
		                                             </div>
		                                             <div class="login_button_right">&nbsp;</div>
		   										 </div>
		   										 <div class="clear">&nbsp;</div>
                                            	 <div>
                                            		 <div class="submit_button_left">&nbsp;</div>
                                              		 <div class="submit_button"><input type="submit" value="submit"/></div>
                                            		 <div class="submit_button_right">&nbsp;</div>
                                            	 </div>
		   										 <div class="clear">&nbsp;</div>
                                            </form>
		</div>

		<?php
			require("template/end_content.php");
		 ?>
	</div>
	
		<?php
			require("template/template_footer.php");
		 ?>
    <?php require("tracker.php"); ?>

</body>
</html>
