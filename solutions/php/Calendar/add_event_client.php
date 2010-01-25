<?php 
require_once("CalendarClient.php");
session_start();
ob_start();
$username=$_SESSION["username"];
$password=$_SESSION["password"];
ob_end_flush();
echo"welcome &nbsp<b>$username<b>";
echo"<br/>";
$day=$_GET['day'];
$time=$_GET['time'];
$year=$_GET['year'];
$week_no=$_GET['week-no'];

 switch($day){
   case "Sunday":
     $day_name="0";
     break;
   case "Monday":
     $day_name="1";
     break;
   case "Tuesday":
     $day_name="2";
     break;
   case "Wendesday":
     $day_name="3";
     break;
   case "Thursday":
     $day_name="4";
     break;
   case "Friday":
     $day_name="5";
     break;
   case "Saturday":
     $day_name="6";
     break;
}

 switch($time){
   case "1pm":
     $time="13pm";
     break;
   case "2pm":
     $time="14pm";
     break;
   case "3pm":
     $time="15pm";
     break;
   case "4pm":
     $time="16pm";
     break;
   case "5pm":
     $time="17pm";
     break;
   case "6pm":
     $time="18pm";
     break;
   case "7pm":
     $time="19pm";
     break;
   case "8pm":
     $time="20pm";
     break;
   case "9pm":
     $time="21pm";
     break;
  case "10pm":
     $time="22pm";
     break;
 case "11pm":
     $time="23pm";
     break;
 case "12pm":
     $time="24pm";
     break;
}

$date = new DateTime();
$date_by_week = $date->setISODate($year,$week_no,$day_name);
$day=$date->format("Y-m-d");
$time_begin=substr($time,0,-2);
$time_end=$time_begin+1;
//file_put_contents("/tmp/month.txt",$day);
$colon=":";
$zero="00";
$space=" ";
$timestamp_begin=$day.$space.$time_begin.$colon.$zero.$colon.$zero;
$timestamp_end=$day.$space.$time_end.$colon.$zero.$colon.$zero;
file_put_contents("/tmp/month.txt",$timestamp);
?>
<html>
<head>
<link href="./assets/style/style3.css" rel="stylesheet" type="text/css" />
</head>
<br />
<br />
<!-- Content  -->
<a href="logout.php"><b><i>logout</i></b></a>
<?php //<a href="logout.php"><b><i>logout</i></b></a>?>
<fieldset>
      <h1>You are here to add events</h1>
      <h2></h2>
      <div class="form-container">
      <form action="#" method="post">
      <p class="legend"><strong>Note:</strong> Required fields are marked with an asterisk (<em>*</em>)</p>

	<fieldset>

		<legend>Event Information</legend>

                 <div><label for="event">Event Name<em>*</em></label> <input id="name" name="event" size="50" type="text" value="<?php echo $name; ?>"/><?php echo"Ex: Birth day"?></div> 
               <div><label for="start_time">Start Time<em>*</em></label> <input id="start_time" name="start_time" size="50" type="text" value="<?php echo $timestamp_begin; ?>"/><?php echo"EX:  2008-02-08 11:30:00"?></div>  
               <div><label for="event">End Time<em>*</em></label> <input id="end_time" name="end_time" size="50" type="text" value="<?php echo $timestamp_end; ?>"/><?php echo"Ex:  2008-02-08 11:30:00"?></div>      
             <div><label for="description">Description<em>*</em></label> <textarea id="description" name="description" cols="60"><?php echo $description; ?> </textarea><?php echo"Ex: There is a party at 2 pm"?></div>	
                 
	</fieldset>
	<div class="buttonrow">
		<input value="Save" class="button" type="submit" name="Submit"/>
	</div>

</fieldset>

	</form>

	
	</div>
	
	
	  
<!-- End of Content  -->

<?php

/*get the values from the form and send them to the service to add values.*/

if(isset($_POST['Submit']))
{ 
 $name=$_POST['event'];
 $start_time = $_POST['start_time'];
 $end_time=$_POST['end_time'];
 $description=$_POST['description'];

 $event=new Event();
 $event->name = $name;
 $event->startDateTime = $start_time;
 $event->endDateTime = $end_time;
 $event->description = $description;

 $client = new CalendarClient($username,$password);
 $returnMessage=$client->addEvent($event);
 print_r($returnMessage);

}
?>
<br>
<br>
<a href="get_event_client.php">Back to the calender</a>
</body>
</html>
