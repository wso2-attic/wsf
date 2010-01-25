<?php
require_once("CalendarClient.php");
session_start();
ob_start();
$username=$_SESSION["username"];
$password=$_SESSION["password"];
ob_end_flush();
echo"welcome &nbsp<b>$username<b>";
echo"<br/>";
?>
<html>
<title>delete</title>
<head>
<link href="./assets/style/style3.css" rel="stylesheet" type="text/css" />
</head>
<body>
<!-- Content  -->
<a href="logout.php"><b><i>logout</i></b></a>
<fieldset>
	  <h1>You are here to delete events</h1>
      <h2></h2>
	<div class="form-container">


	<form action="#" method="post">
	
	<p class="legend"><strong>Note:</strong> Required fields are marked with an asterisk (<em>*</em>)</p>

	<fieldset>
		<legend>Event Information</legend>

                       <div><label for="Start_date_time">Start Time<em>*</em></label> <input id="start_time" name="start_time" size="45" type="text" value="<?php echo $start_time; ?>"/><?php echo"Ex: 2008-02-08 11:30:00"?></div>
                        <div><label for="End_date_time">End Time<em>*</em></label> <input id="end_time" name="end_time" size="45" type="text" value="<?php echo $end_time; ?>"/><?php echo"Ex: 2008-02-08 11:30:00"?></div>


	</fieldset>
	<div class="buttonrow">
		<input value="Delete" class="button" type="submit" name="Submit"/>
	</div>

</fieldset>

	</form>

	
	</div><!-- /form-container -->
	
	
	  
<!-- End of Content  -->

<?php

if(isset($_POST['Submit']))
{ 
 $start_time = $_POST['start_time'];
 $end_time=$_POST['end_time'];

 $client = new CalendarClient($username,$password);
 $return_val=$client->deleteEvents($start_time,$end_time);
 print_r($return_val);

}

?>
<br>
<br>
<a href="get_event_client.php">Back to the calendar</a>
</body>
</html>
