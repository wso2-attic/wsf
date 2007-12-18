
<?php
session_start();
if($_SESSION["member_id"]){
$user_id=$_SESSION["member_id"];
echo"welcome &nbsp<b>$user_id<b>";
}
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

                       <div><label for="year">Year<em>*</em></label> <input id="year" name="year" size="45" type="text" value="<?php echo $year; ?>"/><?php echo"Ex: 2008"?></div>
                        <div><label for="week">Week<em>*</em></label> <input id="week" name="week" size="45" type="text" value="<?php echo $week; ?>"/><?php echo"Ex: 07(Week of the year)"?></div>


			<div><label for="event">Even Time<em>*</em></label> <input id="time" name="time" size="45" type="text" value="<?php echo $time; ?>"/><?php echo"Ex: 10am"?></div>

		       <div><label for="code">Day of the week</label> <input id="date" name="date" size="10" type="text" value="<?php echo $date; ?>"/><?php echo"Ex: Sunday"?></div>
	</fieldset>
	<div class="buttonrow">
		<input value="Save" class="button" type="submit" name="Submit"/>
	</div>

</fieldset>

	</form>

	
	</div><!-- /form-container -->
	
	
	  
<!-- End of Content  -->

<?php

if(isset($_POST['Submit']))
{ 
 $time = $_POST['time'];
 $date=$_POST['date'];
 $week=$_POST['week'];
 $year=$_POST['year'];


$reqPayloadString = <<<XML
<ns1:delete xmlns:ns1="http://ws.apache.org/axis2/php/math">
      <param1>$time</param1>
      <param2>$date</param2>
      <param3>$user_id</param3> 
      <param4>$week</param4>
      <param5>$year</param5>
 </ns1:delete>
XML;

}

try { 

    $client = new WSClient(
        array("to"=>"http://localhost/samples/solutions/calendar/calendar_service.php"));
          
    $resMessage = $client->request($reqPayloadString);
        

     printf($resMessage->str);
      


} catch (Exception $e) { 
    
    

        if ($e instanceof WSFault) {
    
                printf("Soap Fault: %s\n", $e->Reason);
    
        } /*else {

                printf("Message = %s\n",$e->getMessage());

        }

*/

}

?>
<br>
<br>
<a href="calendar_client.php">Back to the calender</a>
</body>
</html>
