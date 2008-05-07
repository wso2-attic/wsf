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
<body>

<!-- Content  -->

	  <h1>Thank you for registration</h1>
      <h2></h2>
	<div class="form-container">
<?php 	
  
/* get variables from form */
      if (isset($_POST['posted'])) {
	$username=$_POST['username'];
	$password=$_POST['password'];
	$repassword=$_POST['repassword'];
	$first_name=$_POST['first_name'];
	$last_name=$_POST['last_name'];
	$email=$_POST['email'];
	
	$address=$_POST['address'];
	$country=$_POST['country'];
	$postal_code=$_POST['postal_code'];


/* PHP validation function gose here */

function isEmpty($post_sring)
{
	if ( $post_sring=="" )
	{
		return true;
	}
	return false;
}

function isPassword($password, $repassword)
{
	if ( $password ==  $repassword )
	{
		return false;
	}
	return true;
}


function valid_email($address)
{

  if (eregi ("^([a-z0-9_]|\\-|\\.)+@(([a-z0-9_]|\\-)+\\.)+[a-z]{2,4}$", $address))
    	{ 
		return true;
		}
  	else
    	return false;
} 

	if ( isEmpty($username) ||
		 isEmpty($password) ||
		 isEmpty($repassword) ||
		 isPassword($password, $repassword) ||
		 isEmpty($first_name) ||
		 isEmpty($last_name) ||
		 isEmpty($email) ||
		 !valid_email($email) ||
		 isEmpty($address) ||
		 isEmpty($country) ||
		 isEmpty($postal_code) 
		)
	{
		echo ("<div id=\"errors\">");
		echo ("<p><em>Oops... the following errors were encountered:</em></p>");
		echo ("<ul>");

		if( isEmpty($username) )
				{
					echo ("<li>User name cannot be empty</li>");
				}

		if( isPassword($password, $repassword) )
				{
					echo ("<li>Re Enter same password</li>");
				}
		if( isEmpty($first_name) )
				{
					echo ("<li>First Name cannot be empty</li>");
				}
		if( isEmpty($last_name) )
				{
					echo ("<li>Last Name cannot be empty</li>");
				}
		if( !valid_email($email) )
				{
					echo ("<li>Email Address is not in correct format</li>");
				}
		if( isEmpty($email) )
				{
					echo ("<li>Email Address cannot be empty</li>");
				}
		if( isEmpty($address) )
				{
					echo ("<li>Address cannot be empty</li>");
				}
		if( isEmpty($postal_code) )
				{
					echo ("<li>Code cannot be empty</li>");
				}

		echo ("</ul>");
		echo ("<p>Please re-enter the data and submit</p></div>");
	}
/* End of php validation  */

	else
	{	
		$errorFree = true;
		
       }

}

  $username=$_POST['username'];
  $password=$_POST['password'];
  $repassword=$_POST['repassword'];
  $first_name=$_POST['first_name'];
  $last_name=$_POST['last_name'];
  $email=$_POST['email'];
  $address=$_POST['address'];
  $country=$_POST['country'];
  $postal_code=$_POST['postal_code'];

if($username!=NULL){
$return_val = CalendarClient::register($username, $password, $first_name, $last_name, $email, $address, $country, $postal_code );
print_r($return_val);
}
?>
  
<?php

if( ! isset( $errorFree ) || !isset($_POST['posted'])){?>

	<form action="#" method="post">
	
	<p class="legend"><strong>Note:</strong> Required fields are marked with an asterisk (<em>*</em>)</p>
		<input type="hidden" name="posted" value="true" />
	<fieldset>
		<legend>User Details</legend>
		
			<div><label for="uname">Username <em>*</em></label> <input id="username" name="username" value="<?php echo $username; ?>" type="text" /></div>
			<div><label for="password">Password <em>*</em></label> <input id="password" name="password" value="<?php echo $password; ?>" size="45" type="password" /></div>
			<div><label for="repassword">Re-enter password <em>*</em></label> <input id="repassword" name="repassword" value="" size="45" type="password" /></div>
			<div><label for="fname">First Name <em>*</em></label> <input id="first_name" name="first_name" value="<?php echo $first_name; ?>" size="45" type="text" /></div>
			<div><label for="lname">Last Name <em>*</em></label> <input id="last_name" name="last_name" value="<?php echo $last_name; ?>" size="45" type="text" /></div>
			<div><label for="email">Email Address <em>*</em></label> <input id="email" name="email" value="<?php echo $email; ?>" type="text" />
			</div>
	</fieldset>
	
	<fieldset>
		<legend>Contact Information</legend>

			<div><label for="address">Address<em>*</em></label> <input id="address" name="address" size="45" type="text" value="<?php echo $address; ?>"/></div>
			<div><label for="country">Country <em>*</em></label> <input id="country" name="country" value="<?php echo $country; ?>" size="12" type="text" /></div>
			<div><label for="code">Postel Code <em>*</em></label> <input id="postal_code" name="postal_code" size="5" type="text" value="<?php echo $postal_code; ?>"/></div>
	</fieldset>
	<div class="buttonrow">
		<input value="Save" class="button" type="submit" />
	</div>

	</form>

	
	</div><!-- /form-container -->
	
	<?php  }  ?>
	  
<!-- End of Content  -->

</body>
</html>
