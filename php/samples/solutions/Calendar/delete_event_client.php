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

 $client = new CalendarClient("Amal","aaa");
 $return_val=$client->deleteEvents($start_time,$end_time);
 print_r($return_val);

}

?>
<br>
<br>
<a href="get_event_client.php">Back to the calender</a>
</body>
</html>
