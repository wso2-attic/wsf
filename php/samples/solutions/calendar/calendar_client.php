
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en-US" lang="en-US">
<head>
<title>WSO2 Calendar</title>
<meta http-equiv="content-type" content="text/html; charset=iso-8859-1">
<link rel="stylesheet" type="text/css" href="./assets/style/initial.css" media="screen, projection" />
<link rel="stylesheet" type="text/css" href="./assets/style/wso2cal.css" media="screen, projection" />
<script type="text/javascript" src="./assets/scripts/basic_cal.js"></script>
</head>
<body>
<div id="container">
  <div id="header">
    <h1><img src="./assets/images/wso2.png" alt="wso2" /></h1><p>Keep track your fact</p>
	<hr class="hidden clear" />
  </div>
  <div id="wrapper">
    <div id="content">
		<div id="cal_menu">
                        <?php
                           session_start();
                           if($_SESSION["member_id"]){  
                           $user_id=$_SESSION["member_id"];   
                           echo"welcome &nbsp<b>$user_id<b>";
                          }
                         ?>
                        <a href="logout.php"><b><i>logout</i></b></a>
		<ul><li><a href="add_event_client.php">Create Event</a></li><li><a href="update_event_client.php">Update Event</a></li><li><a href="delete_event_client.php">Delete Event</a></li></ul>
		</div>
		<div id="main">
<?php 

if (!($_SESSION["member_id"]) || ($_SESSION["member_id"] == "")) {
    Header("Location: ./login.php");
    exit();
  } 
?>
<table class="cal_table">
   <tr>
    <td class="cal_day no_border">&nbsp;</td>
    <td class="cal_day">Sun</td>
    <td class="cal_day">Mon</td>
    <td class="cal_day">Tue</td>
    <td class="cal_day">Wed</td>
    <td class="cal_day">Thu</td>
    <td class="cal_day">Fri</td>
    <td class="cal_day">Sat</td>
  </tr>

<?php

//get the values from url

$week_no = $_GET["week"];

$year = $_GET["year"];

//create three soap messages for read values if time, event and day
$reqPayloadString1=<<<XML
<ns1:readtime xmlns:ns1="http://php.axis2.org/samples">
<userId>$user_id</userId>
<week>$week_no</week>
<year>$year</year>
</ns1:readtime>
XML;

$reqPayloadString2=<<<XML
<ns1:readevent xmlns:ns1="http://php.axis2.org/samples">
<userId>$user_id</userId>
<week>$week_no</week>
<year>$year</year>
</ns1:readevent>
XML;


$reqPayloadString3=<<<XML
<ns1:readday xmlns:ns1="http://php.axis2.org/samples">
<userId>$user_id</userId>
<week>$week_no</week>
<year>$year</year>
</ns1:readday>
XML;

try
    {
            $client = new WSClient(array("to"=>"http://localhost/samples/solutions/calendar/calendar_service.php"));
            $response1 = $client->request($reqPayloadString1);
            $response2 = $client->request($reqPayloadString2);   
            $response3 = $client->request($reqPayloadString3);

            $time=array();
            $i=0;

//read incoming SOAP messages
           if ($response1)
            {

     
           $simplexml = new SimpleXMLElement($response1->str);
           $i=0;
           while($temp=$simplexml->time[$i])
           {

             $time[] = trim($temp);
             $i++;
           }
   
           }



           if ($response2)
            {

            $simplexml = new SimpleXMLElement($response2->str);
            $i=0;
            while($temp=$simplexml->event[$i])
            {

             $event[] = trim($temp);
             $i++;
           }
           }



           if ($response3)
            {
            $simplexml = new SimpleXMLElement($response3->str);
           $i=0;
           while($temp=$simplexml->day[$i])
           {

             $day[] = trim($temp);
             $i++;
           }
          
           }


   }


catch (Exception $e)
       {
            if ($e instanceof WSFault)
            {
             printf("Soap Fault: %s\n", $e->Reason);
            }
         else
           {
             printf("Message = %s\n",$e->getMessage());
           }
      }



 $counter=0;
 $days=array('time','Sunday','Monday','Tuesday','Wendesday','Thursday','Friday','Saturday');

 $times=array('12am','1am','2am','3am','4am','5am','6am','7am','8am','9am','10am','11am','12pm','1pm','2pm','3pm','4pm','5pm','6pm','7pm','8pm','9pm','10pm','11pm');

$dlength=sizeof($days);
$tlength=sizeof($times);

if(!empty($day)){

 $daytime=array_combine($time,$day);

 for($i=0; $i < $tlength; $i++){

       for($j=0; $j < $dlength; $j++){

            if($j%8==0)
            {
             echo"<tr><td>$times[$i]</td>";
            } 

            elseif(in_array($days[$j],$day))
            {
             $val=false;

                   foreach($time as $key => $value)
                    {
                      if(($value==$times[$i])&&($day[$key]==$days[$j])){
                      echo"<td>$event[$key]</td>";$val=true;
                    }
                    }

                  if($val==false)
                  {
                    echo"<td>&nbsp;</td>";
                  }

           }     
          else
              {
              echo"<td>&nbsp;</td>";
              }
        if(($j+1)%8==0){echo"</tr>";} 
   } 
}
}
else{
echo"you have not added any event for this week yet";


for($i=0; $i < $tlength; $i++){

       for($j=0; $j < $dlength; $j++){

            if($j%8==0)
            {
             echo"<tr><td>$times[$i]</td>";
            }
          else
              {
              echo"<td>&nbsp;</td>";
              }
        if(($j+1)%8==0){echo"</tr>";}
   }
}
}


?>

  </table>
  </div>
  </div><!-- /content -->
  </div><!-- /wrapper -->
  <div id="navigation">
    <p><strong>Dispaly Calendar.</strong></p>

<?php
global $day,$month,$year;

$day = $_GET["day"];
$month = $_GET["month"];
$year = $_GET["year"];
$sel = $_GET["sel"];
$what = $_GET["what"];


if($day == "")
$day = date("j");

if($month == "")
$month = date("m");

if($year == "")
$year = date("Y");

$currentTimeStamp = strtotime("$year-$month-$day");
$monthName = date("F", $currentTimeStamp);
$numDays = date("t", $currentTimeStamp);
$counter = 0;
$numEventsThisMonth = 0;
$hasEvent = false;
$todaysEvents = "";

?>
	<table class="tab1">
		<tr>
		<td width='50' align='left'>
		<input type='button' value=' < 'onClick='goLastMonth(<?php echo $month . ", " . $year ; ?>)'>
		</td>
		<td width='90' align="center">
		<span class='title'><?php echo $monthName . " " . $year; ?></span><br>
		</td>
		<td width='50' align='left'>
		<input type='button' value=' > ' onClick='goNextMonth(<?php echo $month . ", " . $year  ; ?>)'>
		</td>
		</tr> 
</table>
<form>

<table width='190' border='0' cellspacing='0' cellpadding='0'>
<tr>
<td class='head'>WK</td>
<td class='head'>S</td>
<td class='head'>M</td>
<td class='head'>T</td>
<td class='head'>W</td>
<td class='head'>T</td>
<td class='head'>F</td>
<td class='head'>S</td>
</tr>

<?php

//--------------Dispaly dates of the months-------------

$numDays = date("t", $currentTimeStamp); 

for($i = 1; $i < $numDays+1; $i++, $counter++)
{
$timeStamp = strtotime("$year-$month-$i");
$week= strftime("%V",$timeStamp);

if($i == 1)
{
// Workout when the first day of the month is
$firstDay = date("w", $timeStamp);
echo"<td>&nbsp;</td>";

for($j = 0; $j < $firstDay; $j++, $counter++)
echo "<td>&nbsp;</td>";
} 
if($counter % 7 == 0)

echo "</tr><tr><td><input type='button' value= '$week' onClick='display($month,$year,this.value);'></td>"; 

if(date("w", $timeStamp) == 0 || date("w", $timeStamp) == 6){
echo "<td class='weekend' width='50'>$i</td>";
} elseif($i == date("d") && $month == date("m") && $year == date("Y")){
echo "<td class='today' width='50'>$i</td>";
} else{  
echo "<td class='normal' width='50'>$i</td>";
}
}
?>
</table>
  </div><!-- /navigation -->
  <div id="footer">
    
  </div><!-- /footer -->
</div><!-- /container -->
</body>
</html>
