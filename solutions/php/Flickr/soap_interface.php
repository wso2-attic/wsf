<?php
require_once("FlickrClient.php");
session_start();
ob_start();
$api_key=$_SESSION["key"];
$_SESSION["method"]=$_POST["operation"];
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
    </p>
 </div>
 <br>
 <br>
 <div class="form2">
 <br>
 <b>Select the operation:<b><br>
 <br>
 <select id="operation" name="operation">
 <option id="operation1" name="op1" <?php echo $operation1; ?>>flickr.photos.search</option>
 <option id="operation2" name="op2" <?php echo $operation2; ?>>flickr.photos.getInfo</option>
 <option id="operation3" name="op3" <?php echo $operation3; ?>>flickr.photos.getFavorites</option>
 <option id="operation4" name="op4" <?php echo $operation4; ?>>flickr.photos.getPerms</option>
 <option id="operation5" name="op5" <?php echo $operation5; ?>>flickr.photos.getRecent</option>
 <option id="operation6" name="op6" <?php echo $operation6; ?>>flickr.photos.getSizes</option>
 <option id="operation7" name="op7" <?php echo $operation7; ?>>flickr.photos.getContext</option></select><br />
 <br>
 </div>
<br>
 <input value="Submit" class="button" type="submit" />
</form>
<br>
<br>
<?php
  $operation=$_POST['operation'];
  file_put_contents("/tmp/month.txt",$operation);
  
  switch($operation){
  
  case 'flickr.photos.getFavorites':
  header( "Location: http://".$_SERVER['HTTP_HOST'].dirname($_SERVER['PHP_SELF'])."/visit_soap.php");
  exit();
  break;
  
  case 'flickr.photos.getInfo':
  header("Location: http://".$_SERVER['HTTP_HOST'].dirname($_SERVER['PHP_SELF'])."/visit_soap.php");
  exit();
  break;

  case 'flickr.photos.getPerms':
  header("Location: http://".$_SERVER['HTTP_HOST'].dirname($_SERVER['PHP_SELF'])."/visit_soap.php");
  exit();
  break;

  case 'flickr.photos.getRecent':
  header("Location: http://".$_SERVER['HTTP_HOST'].dirname($_SERVER['PHP_SELF'])."/visit_soap.php");
  exit();
  break;

  case 'flickr.photos.getSizes':
  header( "Location: http://".$_SERVER['HTTP_HOST'].dirname($_SERVER['PHP_SELF'])."/visit_soap.php");
  exit();
  break;


 }
?>
</body>
</html>

