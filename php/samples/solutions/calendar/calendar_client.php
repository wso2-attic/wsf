<?php
session_start();
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en-US" lang="en-US">
<head>
<title>WSO2 Calendar</title>
<meta http-equiv="content-type" content="text/html; charset=iso-8859-1">
<link rel="stylesheet" type="text/css" href="./assets/style/initial.css" media="screen, projection" />
<link rel="stylesheet" type="text/css" href="./assets/style/wso2cal.css" media="screen, projection" />
<script type="text/javascript" src="./assets/scripts/basic_cal.js"></script>
<script type="text/javascript" src="jquery-1.2.1.pack.js"></script>
<script language="javascript" type="text/javascript">
$(function() {
        
    var viewport = {
        o: function() {
            if (self.innerHeight) {
                        this.pageYOffset = self.pageYOffset;
                        this.pageXOffset = self.pageXOffset;
                        this.innerHeight = self.innerHeight;
                        this.innerWidth = self.innerWidth;
                } else if (document.documentElement && document.documentElement.clientHeight) {
                        this.pageYOffset = document.documentElement.scrollTop;
                        this.pageXOffset = document.documentElement.scrollLeft;
                        this.innerHeight = document.documentElement.clientHeight;
                        this.innerWidth = document.documentElement.clientWidth;
                } else if (document.body) {
                        this.pageYOffset = document.body.scrollTop;
                        this.pageXOffset = document.body.scrollLeft;
                        this.innerHeight = document.body.clientHeight;
                        this.innerWidth = document.body.clientWidth;
                }
                return this;
        },
        init: function(el) {
            $(el).css("left",Math.round(viewport.o().innerWidth/2) + viewport.o().pageXOffset - Math.round($(el).width()/2));
            $(el).css("top",Math.round(viewport.o().innerHeight/2) + viewport.o().pageYOffset - Math.round($(el).height()/2));
        }
    };
    $(".simple_popup_info").each(function(){
        $(this).css("display","none").siblings(".simple_popup").click(function(){
            $(".simple_popup_div").remove();
            var strSimple = "<div class='simple_popup_div'><div class='simple_popup_inner'>";
            strSimple += "<p class='simple_close'>[ x ] <a href='#'>Close</a></p>";
            strSimple += $(this).siblings(".simple_popup_info").html();
            strSimple += "</div></div>";
            $("body").append(strSimple);
            viewport.init(".simple_popup_div");
            $(".simple_close").click(function(){
                $(".simple_popup_div").remove();
                return false;
            });
            return false;
        });
    });

});
</script>

</head>
<body>
<div id="container">
  <div id="header">
    <h1><img src="./assets/images/wso2.png" alt="wso2" /></h1><p>Keep track your fact</p>
	<hr class="hidden clear" />
  </div>
  <script type="text/javascript">
  
  var d = new Date()
  var time = d.getHours()
  if (time<10)
  {
  document.write("<b>Good morning</b>");
  }
  else if(time>13)  {
  document.write("<b>Good Afternoon</b>");
  }
  else
 {
 document.write("<b>Good day</b>");
 }
 </script>

  <div id="wrapper">
    <div id="content">
		<div id="cal_menu">
                        <?php
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
$reqPayloadString=<<<XML
<ns1:getEvent xmlns:ns1="http://php.axis2.org/samples">
<userId>$user_id</userId>
<week>$week_no</week>
<year>$year</year>
</ns1:getEvent>
XML;

try
    {
            $client = new WSClient(array("to"=>"http://localhost/samples/solutions/calendar/calendar_service.php"));
            $response = $client->request($reqPayloadString);
            
            $time=array();
            $event=array();
            $day=array();
            $i=0;

//read incoming SOAP message
           if ($response)
            {
           $simplexml = new SimpleXMLElement($response->str);
           $i=0;$j=0;$q=0;
           while($temp=$simplexml->event[$i])
           {

            $event[]= trim($temp);  
             $i++;
           }

           while($temp1=$simplexml->event->time[$j])
           {

            $time[]= trim($temp1);  
             $j++;
           }
         
           while($temp2=$simplexml->event->day[$q])
           {

            $day[]= trim($temp2);  
             $q++;
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
                      echo"<td id='$j$i' onclick='function1(this);'>$event[$key]</td>";$val=true;
                    }
                    }

                  if($val==false)
                  {
                    echo"<td id='$j$i'  class='simple_popup' onclick='function1(this);'></td>";
                  }

           }     
          else
              {
              echo"<td id='$j$i' onclick='function1(this);'>&nbsp;</td>";
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
             echo"<tr><td  id='$j$i'>$times[$i]</td>";
            }
          else
              {
              echo"<td  id='$j$i' class='simple_popup' onclick='Popup.show()'>&nbsp</td>";
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
echo"</tr><tr><td><input type='button' style='background-color:white' value='$week' onClick='display($month,$year,this.value);'></td>"; 
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
