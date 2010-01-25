<?php

session_start();

$_SESSION["wsf_php_demo_site_username"] = NULL;
$_SESSION["wsf_php_demo_site_password"] = NULL;

session_destroy();

header("Location: http://" . $_SERVER['HTTP_HOST']
		 . dirname($_SERVER['PHP_SELF'])
		 . "/index.php"); 
?>
