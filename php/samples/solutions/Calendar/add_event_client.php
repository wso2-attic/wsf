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
<head>
<link href="./assets/style/style3.css" rel="stylesheet" type="text/css" />
</head>
<br />
<br />
<!-- Content  -->
<?php //<a href="logout.php"><b><i>logout</i></b></a>?>
<fieldset>
      <h1>You are here to add events</h1>
      <h2></h2>
      <div class="form-container">
      <form action="#" method="post">
      <p class="legend"><strong>Note:</strong> Required fields are marked with an asterisk (<em>*</em>)</p>

	<fieldset>

		<legend>Event Information</legend>

                 <div><label for="event">Event Name<em>*</em></label> <input id="name" name="event" size="100" type="text" value="<?php echo $name; ?>"/><?php echo"Ex: Birth day"?></div> 
               <div><label for="start_time">Start Time<em>*</em></label> <input id="start_time" name="start_time" size="100" type="text" value="<?php echo $start_time; ?>"/><?php echo"EX:  2008-02-08 11:30:00"?></div> 
                <div><label for="event">End Time<em>*</em></label> <input id="end_time" name="end_time" size="45" type="text" value="<?php echo $end_time; ?>"/><?php echo"Ex:  2008-02-08 11:30:00"?></div> 
                <div><label for="description">Description<em>*</em></label> <input id="description" name="description" size="60" value="<?php echo $description; ?>" /><?php echo"Ex: There is a party at 2 pm"?></div>	
                 
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
 
 $obj=new Event($name,$start_time,$end_time,$description);
 $client = new CalendarClient("Amal","aaa");
 $returnMessage=$client->addEvent($obj);
 print_r($returnMessage);

}
?>
<br>
<br>
<a href="get_event_client.php">Back to the calender</a>
</body>
</html>
