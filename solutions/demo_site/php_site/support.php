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
	<title><?php echo $title; ?> - Support</title>
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
				<h2>WSO2 WSF/PHP Demo Site - Support </h2>
<p>	
For support with technical aspects of running demonstrations powered by the WSO2 WSF/PHP extension, please visit our public <a href="http://wso2.org/forum/188">WSF/PHP Forum</a>.
</p>
<p>
If you have suggestions on how to improve WSO2 WSF/PHP Demo Site, please send them to <a href="mailto:wsf-php-user@wso2.org">wsf-php-user@wso2.org</a>.
</p>
<p>
For problems with your account, reporting spam or abuse, or legal inquiries, please contact <a href="mailto:wsf-php-user@wso2.org">wsf-php-user@wso2.org</a>.	
</p>
<p>
<em>Effective 01st March 2008</em>
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
