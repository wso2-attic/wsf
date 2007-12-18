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
        $userID=$_POST['userID'];
	$uname=$_POST['uname'];
	$password=$_POST['password'];
	$repassword=$_POST['repassword'];
	$firstName=$_POST['fname'];
	$lastName=$_POST['lname'];
	$email=$_POST['email'];
	
	$address=$_POST['address'];
	$country=$_POST['country'];
	$code=$_POST['code'];


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

	if ( isEmpty($uname) ||
		 isEmpty($password) ||
		 isEmpty($repassword) ||
		 isPassword($password, $repassword) ||
		 isEmpty($firstName) ||
		 isEmpty($lastName) ||
		 isEmpty($email) ||
		 !valid_email($email) ||
		 isEmpty($address) ||
		 isEmpty($country) ||
		 isEmpty($code) 
		)
	{
		echo ("<div id=\"errors\">");
		echo ("<p><em>Oops... the following errors were encountered:</em></p>");
		echo ("<ul>");

		if( isEmpty($uname) )
				{
					echo ("<li>User name cannot be empty</li>");
				}

		if( isPassword($password, $repassword) )
				{
					echo ("<li>Re Enter same password</li>");
				}
		if( isEmpty($firstName) )
				{
					echo ("<li>First Name cannot be empty</li>");
				}
		if( isEmpty($lastName) )
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
		if( isEmpty($code) )
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


  $userID=$_POST['userID'];
  $uname=$_POST['uname'];
  $password=$_POST['password'];
  $repassword=$_POST['repassword'];
  $firstName=$_POST['fname'];
  $lastName=$_POST['lname'];
  $email=$_POST['email'];
  $address=$_POST['address'];
  $country=$_POST['country'];
  $code=$_POST['code'];


$reqPayloadString = <<<XML
<ns1:register xmlns:ns1="http://php.axis2.org/samples">
<userID>$userID</userID>
<uname>$uname</uname>
<password>$password</password>
<firstName>$firstName</firstName>
<lastName>$lastName</lastName>
<email>$email</email>
<address>$address</address>
<country>$country</country>
<code>$code</code>
</ns1:register>
XML;

  
try { 

    $client = new WSClient(
        array("to"=>"http://localhost/samples/solutions/calendar/calendar_service.php"));
          
    $response = $client->request($reqPayloadString);
        

     if ($response)
                    {
                      $simplexml = new SimpleXMLElement($response->str);
                      $message =trim($simplexml->text);
                        if($message=='success'){
                              include 'detail_table_client.php';

                                               }
                        else{
                              print_r($message);
                             
                            }
                     }      


} catch (Exception $e) { 
    
    

        if ($e instanceof WSFault) {
    
                printf("Soap Fault: %s\n", $e->Reason);
    
        } else {

                printf("Message = %s\n",$e->getMessage());

        }



}
	
	} 
	
 ?>
<br />
<br />
<a href ="login_client.php">Back to the login page</a>

<?php

if( ! isset( $errorFree ) || !isset($_POST['posted'])){?>

	<form action="#" method="post">
	
	<p class="legend"><strong>Note:</strong> Required fields are marked with an asterisk (<em>*</em>)</p>
		<input type="hidden" name="posted" value="true" />
	<fieldset>
		<legend>User Details</legend>
		    <div><label for="uname">UserID<em>*</em></label> <input id="userID" name="userID" value="<?php echo $userID; ?>" type="text" /></div>
		
			<div><label for="uname">Username <em>*</em></label> <input id="uname" name="uname" value="<?php echo $uname; ?>" type="text" /></div>
			<div><label for="password">Password <em>*</em></label> <input id="password" name="password" value="<?php echo $password; ?>" size="45" type="password" /></div>
			<div><label for="repassword">Re-enter password <em>*</em></label> <input id="repassword" name="repassword" value="" size="45" type="password" /></div>
			<div><label for="fname">First Name <em>*</em></label> <input id="fname" name="fname" value="<?php echo $firstName; ?>" size="45" type="text" /></div>
			<div><label for="lname">Last Name <em>*</em></label> <input id="lname" name="lname" value="<?php echo $lastName; ?>" size="45" type="text" /></div>
			<div><label for="email">Email Address <em>*</em></label> <input id="email" name="email" value="<?php echo $email; ?>" type="text" />
			</div>
	</fieldset>
	
	<fieldset>
		<legend>Contact Information</legend>

			<div><label for="address">Address<em>*</em></label> <input id="address" name="address" size="45" type="text" value="<?php echo $address; ?>"/></div>
			<div><label for="country">Country <em>*</em></label> <input id="country" name="country" value="<?php echo $country; ?>" size="12" type="text" /></div>
			<div><label for="code">Postel Code <em>*</em></label> <input id="code" name="code" size="5" type="text" value="<?php echo $code; ?>"/></div>
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
