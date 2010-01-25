<?php
require_once("CalendarClient.php");

$message = "";
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
		$message .= "<div id=\"errors\">";
		$message .= "<p><em>Oops... the following errors were encountered:</em></p>";
		$message .= "<ul>";

		if( isEmpty($username) )
        {
            $message .= "<li>User name cannot be empty</li>";
        }

		if( isPassword($password, $repassword) )
        {
            $message .= "<li>Re Enter same password</li>";
        }
		if( isEmpty($first_name) )
        {
            $message .= "<li>First Name cannot be empty</li>";
        }
		if( isEmpty($last_name) )
        {
            $message .= "<li>Last Name cannot be empty</li>";
        }
		if( !valid_email($email) )
        {
            $message .= "<li>Email Address is not in correct format</li>";
        }
		if( isEmpty($email) )
        {
            $message .= "<li>Email Address cannot be empty</li>";
        }
		if( isEmpty($address) )
        {
            $message .= "<li>Address cannot be empty</li>";
        }
		if( isEmpty($postal_code) )
        {
            $message .= "<li>Code cannot be empty</li>";
        }

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

if($username!=NULL && $errorFree){
    $return_val = CalendarClient::register($username, $password, $first_name, $last_name, $email, $address, $country, $postal_code );
    if($return_val->success == "SUCCESS") {
        header('Location: login_client.php');
    }
    else if($return_val->success == "USERNAME_ALREADY_EXISTS") {
		$errorFree = false;
		$message .= "<div id=\"errors\">";
		$message .= "<p><em>Oops... the following errors were encountered:</em></p>";
		$message .= "<ul>";
        $message .= "<li>username already exists, please try another username</li>";
    }
    else {
		$errorFree = false;
		$message .= "<div id=\"errors\">";
		$message .= "<p><em>Oops... the following errors were encountered:</em></p>";
		$message .= "<ul>";
        $message .= "<li>registration failed</li>";
    }
}
if(!empty($message) && !$errorFree) {
    $message .= "</ul>";
    $message .= "<p>Please re-enter the data and submit</p></div>";
}
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
echo $message;
if( ! $errorFree || !isset($_POST['posted'])){?>

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
