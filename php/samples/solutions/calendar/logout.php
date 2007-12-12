<?php
session_unset();
session_destroy();
header( "Location: login_client.php"); 
?>
