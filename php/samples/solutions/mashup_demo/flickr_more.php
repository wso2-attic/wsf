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

$today = getdate();
?>
<div style="text-align:center">
    <h4>Uploaded Date</h4>
</div>
<div height="15px">&nbsp;</div>
<div>
<div style="float:left; width:50%">
From 
<?php 
echo print_date("uploaded_start", 1970, 1, 1 ); 
?>
</div>
<div style="float:right: width:50%;">
To
<?php echo print_date("uploaded_end", $today["year"], $today["mon"], $today["mday"] ); ?>
</div>
</div>

<div height="25px">&nbsp;</div>
<div style="text-align:center">
    <h4>Taken Date</h4>
</div>
<div height="15px">&nbsp;</div>
<div>
<div style="float:left; width:50%">
From 
<?php 
echo print_date("taken_start", 1970, 1, 1 ); 
?>
</div>
<div style="float:right: width:50%;">
To
<?php echo print_date("taken_end", $today["year"], $today["mon"], $today["mday"] ); ?>
</div>
</div>

<div height="25px">&nbsp;</div>

<div id="flickrMoreResults">
</div>


<?php

function print_date($label, $year, $mon, $mday)
{
    $year_id = $label."_year";
    $month_id = $label."_month";
    $day_id = $label."_day";

echo "
			<input id=\"${year_id}\" value=\"${year}\" type=\"text\"
						style=\"vertical-align:middle; width:50px\">
			</input>
			<select id=\"${month_id}\" style=\"vertical-align:middle\">";

            $months = array("Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec");

            $month_no = 1;
            foreach($months as $month)
            {
                $selected_text = "";
                if($month_no == $mon)
                {
                    $selected_text = "selected = \"true\"";
                }
                echo "<option ${selected_text} value=\"${month_no}\">${month}</option>";
                $month_no++;
            }
echo "
			</select>
            <select id=\"${day_id}\" style=\"vertical-align:middle\">
";
            for($i = 1; $i <= 31; $i ++)
            {
                $selected_text = "";
                if($mday == $i)
                {
                    $selected_text = "selected = \"true\"";
                }
                echo "<option ${selected_text} value=\"${i}\">${i}</option>";
            }
echo "
            </select>";
}

