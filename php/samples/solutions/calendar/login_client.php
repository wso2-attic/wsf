<?php
$userID = $_POST["userID"];
$password = $_POST["mypassword"];
$result = $_POST["Submit"];
?>

<html>
<head></head>
<body>
<table width="300" border="0" align="center" cellpadding="0" cellspacing="1" bgcolor="#CCCCCC">
<tr>
<form name="form1" method="post" action="#">
<td>
<table width="100%" border="0" cellpadding="3" cellspacing="1" bgcolor="#FFFFFF">
<tr>
<td colspan="3"><strong>Member Login </strong></td>
</tr>
<tr>
<td width="78">UserID</td>
<td width="6">:</td>
<td width="294"><input name="userID" type="text" id="userID"></td>
</tr>
<tr>
<td>Password</td>
<td>:</td>
<td><input name="mypassword" type="password" id="mypassword"></td>
</tr>
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
<td><input type="submit" name="Submit" value="Login"></td>
</tr>
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
<td><a href="register_client.php">Register now</a></td>
</tr>     
</table> 
</form>  
</body> 
</html>


<?php

/*Get the values entered by the form and send them to the service to check whether the user name and password are correct.*/

if (isset($_POST['Submit']))
{
      if (isset($_GET['userID']) && isset($_GET['mypassword']))
      {
	$userID= $_GET['userID'];
	$password = $_GET['mypassword'];
      }


            if (isset($userID) &&  isset($password))
            {
  
              $reqPayloadString = <<<XML
              <ns1:login xmlns:ns1="http://ws.apache.org/axis2/php/math">
              <param1>$userID</param1>
              <param2>$password</param2>
              </ns1:login>
XML;
   
                   try
                      {
	                $client = new WSClient(array("to"=>"http://localhost/samples/solutions/calendar/calendar_service.php"));
	                $response = $client->request($reqPayloadString);

                        /*If the response is saying success then the user name and password are correct.Then user can enter to the system*/	 

	                if ($response)
	                {
                           $simplexml = new SimpleXMLElement($response->str);
                           $message =trim($simplexml->text);
                           if($message=='success'){
                           session_start();
                           $_SESSION["member_id"] = $_POST["userID"];
                           header('Location: calendar_client.php');
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


}


}






