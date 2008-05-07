<?php
/*
 * Copyright 2005,2008 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

require_once("CalendarClient.php");
?>
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
 
 <script type="text/javascript">
  var d = new Date()
  var time = d.getHours()
  if (time<10)
  {
  document.write("<b>Good morning</b>");
  }
  else if(time>13) 
  {
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
	     <ul><li><a href="add_event_client.php">Create Event</a></li><li><a href="delete_event_client.php">Delete Event</a></li></ul>
           </div>
      <div id="main">

<?php
$week_no = $_GET["week"];
$year = $_GET["year"];
$dates=array();
echo"<table class=\"cal_table\"><tr>";
for($i=0;$i<7;$i++)
{
  $date = new DateTime();
  $date_by_week = $date->setISODate($year,$week_no,$i); //30th week 5th day
  $date=$date->format("Y-m-d");
  array_push($dates,$date);
}
?>

<table class="cal_table">
   <tr>
    <td class="cal_day no_border">&nbsp;</td>
    <td class="cal_day"><b>Sunday</b>(<?php echo "$dates[0]"; ?>)</td>
    <td class="cal_day"><b>Monday</b>(<?php echo "$dates[1]"; ?>)</td>
    <td class="cal_day"><b>Tuesday</b>(<?php echo "$dates[2]"; ?>)</td>
    <td class="cal_day"><b>Wednesday</b>(<?php echo "$dates[3]"; ?>)</td>
    <td class="cal_day"><b>Thursday</b>(<?php echo "$dates[4]"; ?>)</td>
    <td class="cal_day"><b>Friday</b>(<?php echo "$dates[5]"; ?>)</td>
    <td class="cal_day"><b>Saturday</b>(<?php echo "$dates[6]"; ?>)</td>
  </tr>

<?php
$date = new DateTime();
$date_by_week = $date->setISODate($year,$week_no,0); //30th week 5th day
$first=$date->format("Y-m-d");
$date_by_week = $date->setISODate($year,$week_no,6);
$last=$date->format("Y-m-d");
$subs="T00:00:00Z";
$first_date_of_week=$first.$subs;
$last_date_of_week=$last.$subs;

$client = new CalendarClient("Amal","aaa");
$resMessage=$client->getEvents("$first_date_of_week","$last_date_of_week");		

  if ($resMessage)
       {
             $simplexml = new SimpleXMLElement($resMessage->str);
             $i=0;
             $j=0;
             $k=0;
           
             while($temp=$simplexml->event[$i]->name)
             {
             $name[] = trim($temp);
             $i++;
             }
           
             while($temp=$simplexml->event[$j]->start_date_time)
             {
             $start_time[] = trim($temp);
             $j++;
             }
           
             while($temp=$simplexml->event[$k]->end_date_time)
             {
             $end_time[] = trim($temp);
             $k++;
             }
       }

$daysize=sizeof($name);
$day=array();
$time=array();
$event=array();
for($i=0;$i<$daysize;$i++)
{
   $day_number=strftime ("%w", strtotime($start_time[$i]));
   switch($day_number){
   case 0:
     $day_name="Sunday";
     break;
   case 1:
     $day_name="Monday";
     break;
   case 2:
     $day_name="Tuesday";
     break;
   case 3:
     $day_name="Wendesday";
     break;
   case 4:
     $day_name="Thursday";
     break;
   case 5:
     $day_name="Friday";
     break;
   case 6:
     $day_name="Saturday";
     break;
}
array_push($day,$day_name);
}     

$am="am";
$pm="pm";
for($j=0;$j<$daysize;$j++)
{
   $time1=substr($start_time[$j],-8);
   $time2=substr($time1,0,-6);
   if($time>12)
   {
    $time2=$time2.$am;
   }
   else
   {
    $time2=$time2.$pm;
   }
array_push($time,$time2);
}

$counter=0;
$days=array('time','Sunday','Monday','Tuesday','Wendesday','Thursday','Friday','Saturday');
$times=array('12am','01am','02am','03am','04am','05am','06am','07am','08am','09am','10am','11am','12pm','13pm','14pm','15pm','16pm','17pm','18pm','19pm','20pm','21pm','22pm','23pm');
$dlength=sizeof($days);
$tlength=sizeof($times);
if(!empty($day))
{
   for($i=0; $i < $tlength; $i++)
    {
       for($j=0; $j < $dlength; $j++)
         {
            if($j%8==0)
            {
             echo"<tr><td>$times[$i]</td>";
            } 
            elseif(in_array($days[$j],$day))
            {
             $val=false;

                   foreach($time as $key => $value)
                    {
                      if(($value==$times[$i])&&($day[$key]==$days[$j]))
                      {
                      echo"<td id='$j$i' onclick='function1(this);'>$name[$key]</td>";$val=true;
                      }
                    }

                  if($val==false)
                  {
                    echo"<td id='$j$i' onclick='function1(this);'></td>";
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
else
{
echo"you have not added any event for this week yet";


for($i=0; $i < $tlength; $i++){

       for($j=0; $j < $dlength; $j++){

            if($j%8==0)
            {
             echo"<tr><td  id='$j$i'>$times[$i]</td>";
            }
          else
              {
              echo"<td  id='$j$i' onclick='function1(<?php echo $j . ", " . $i ; ?>);'>&nbsp;</td>";
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

<table class="ex" width='190' border='0' cellspacing='0' cellpadding='0'>
<tr>
<td></td>
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




function is_leap_year($year)
{
if ((($year % 4) == 0 and ($year % 100)!=0) or ($year % 400) == 0)
return 1;
else
return 0;
}


function iso_week_days($yday, $wday) 
{
return $yday - (($yday - $wday + 382) % 7) + 3;
}


function get_week_number($timestamp) 
{
$d = getdate($timestamp);
$days = iso_week_days($d["yday"], $d["wday"]);

if ($days < 0) {
$d[ "yday"] += 365 + is_leap_year(--$d["year"]);
$days = iso_week_days($d["yday"], $d["wday"]);
}
else {
$d["yday"] -= 365 + is_leap_year($d["year"]);
$d2 = iso_week_days($d["yday"], $d["wday"]);
if (0 <= $d2)
$days = $d2;
}

return (int)($days / 7) + 2;
}


$numDays = date("t", $currentTimeStamp);

for($i = 1; $i < $numDays+1; $i++, $counter++)
{
$timeStamp = strtotime("$year-$month-$i 00:00:00");
   if($timeStamp==strtotime("$year-01-01 00:00:00"))
   {
    $week=1;
   }
   elseif($timeStamp==strtotime("$year-$month-01 00:00:00"))
   {
    $week= get_week_number($timeStamp);
    $week=$week-1;
   }
   else{ 
   $week= get_week_number($timeStamp);
    }

   if($i == 1)
   {
   $firstDay = date("w", $timeStamp);
   echo"</tr><tr class='showHideDiv' style=\"background-color:'$color';\" onmouseover=\"this.style.backgroundColor='#F6E497';\"this.style.cursor='hand';\" onmouseout=\"this.style.backgroundColor='$color';\" onClick='display($month,$year,$week);'><td>&nbsp;</td>";
     for($j =0; $j < $firstDay; $j++,$counter++)
     {
     echo "<td>&nbsp;</td>";
     } 
   }
   if($counter % 7 == 0 && $i>1)
   {
    echo"</tr><tr><tr class='showHideDiv' style=\"background-color:'$color';\" onmouseover=\"this.style.backgroundColor='#F6E497';\"this.style.cursor='hand';\" onmouseout=\"this.style.backgroundColor='$color';\" onClick='display($month,$year,$week);'><td></td>";}
   if(date("w", $timeStamp) == 0 || date("w", $timeStamp) == 6)
   {
    echo "<td class='weekend' width='50'>$i</td>";
   } 
   elseif($i == date("d") && $month == date("m") && $year == date("Y"))
   {
    echo "<td class='today' width='50'>$i</td>";
   } 
   else
   {
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
