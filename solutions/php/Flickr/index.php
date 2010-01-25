<?php

require_once("FlickrClient.php");
session_start();
ob_start();
$_SESSION["key"]=$_POST["api_key"];
$_SESSION["shared"]=$_POST["shared"];
ob_end_flush();
?>
<html>
<head>
<link href="./assets/style/css.css" rel="stylesheet" type="text/css" />
<title>Flickr Client</title>
</head>
<body class="content">
<h2 class="topic"><b>Flicker web service with web services framework<b></h2>
<br>
 <form method="post" action="#">
 <br>
  <div class="form1">
   <b>API Key</b><br>
    <p>
     <div class="id" style="">
       <input name="api_key" type="text" value="<?php echo $api_key?>"/> 
     </div>
     <div class="id" style="">
       <i>You can get a key from <a href="http://www.flickr.com/services/api/keys/">here</a></i>
     </div>
    </p>
 </div>
 <br>
 <br>
    <div class="form2">
   <b>Shared secret</b><br>
    <p>
     <div class="shared" style="">
       <input name="shared" type="text" value="<?php echo $shared?>"/>
     </div>
    </p>
 </div>
<br>
<br>
 <input value="Submit" name="Submit" class="button" type="submit" />
</form>
<br>
<br>
<?php
if(isset($_POST['Submit']))
{
 $relative_url="flickr_interface1.php";
 header( "Location: http://".$_SERVER['HTTP_HOST'].dirname($_SERVER['PHP_SELF'])."/".$relative_url);
 exit();
}
?>
</body>
</html>

