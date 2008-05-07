<!--
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
 -->

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
                       
