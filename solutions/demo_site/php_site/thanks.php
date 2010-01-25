<?php
require_once("defines.php");
session_start();

$username = $_SESSION["wsf_php_demo_site_username"];
 ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<?php
		if(WEB_VERSION == "php")
		{
			$title = "PHP Web Services - Code, Samples, Demos and Tutorials";
		}
		else if(WEB_VERSION == "c")
		{
			$title = "C Web Services - Code, Sample, Demos and Tutorials";
		}
	 ?>
	<title><?php echo $title; ?></title>
	<link rel="Shortcut Icon" href="favicon.ico" type="image/x-icon" />
	<link href="styles/template.css" rel="stylesheet" type="text/css"/>
</head>
<body>
	<div id="page">
		<?php
			require("template/template_header.php")
		 ?>
		<?php
			require("template/start_content.php");
		 ?>
		
		<div id="content">
			<div id="welcome">
				<h2>Thank You for Registering </h2>
				<p>
					Now you can login to the Web site from <a href="login.php">the login page</a>. Then you can comment and rate the demos.
				</p>
				<p>&nbsp;</p>
			</div>
		</div>
		
		<?php
			require("template/end_content.php");
		 ?>
		
	</div>
		<?php
			require("template/template_footer.php")
		 ?>
        <?php require("tracker.php"); ?>

</body>
</html>
