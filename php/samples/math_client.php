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
$getResult = isset($_POST["getResult"]) ? $_POST['getResult'] : '';
$operation = isset($_POST["operation"]) ? $_POST['operation'] : '';
$epr = isset($_POST["epr"]) ? $_POST['epr'] : '';
$param1 = isset($_POST["param1"]) ? $_POST['param1'] : '';
$param2 = isset($_POST["param2"]) ? $_POST['param2'] : '';
		    
?>

<html>
<head>
<title> Math Sample </title>
</head>
<body>
<form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
<table cols="2" border="1" cellpadding="10" cellspacing="0" align="center" width="100%">
<tr>
<td>
<h4>Operations</h4>

Add : <input type="radio" value="add" name="operation" checked>

Subtract: <input type="radio" value="sub" name="operation">

Multiply: <input type="radio" value="mul" name="operation">

Divide: <input type="radio" value="div" name="operation">
<br/><br/>
<h4>Target Endpoint</h4>
Endpoint:<input type="text" size="60" maxlength="60" name="epr" 
          value="http://localhost/samples/math_service.php"><br />

<h4>Parameters</h4>
Parameter 1:<input type="text" size="6" maxlength="10" name="param1" value="10">
Parameter 2:<input type="text" size="6" maxlength="10" name="param2" value="20"><br/>
<br/>

<input type="submit" value="submit" name="getResult">
<input type="submit" value="Reset" name="reset">






</td>
</tr>
</table>

</form>
<?php
if (isset($_POST['getResult']))
{
      if (isset($_GET['param1']) && isset($_GET['param2']))
      {
	$epr = $_GET['epr'];
	$param1 = $_GET['param1'];
	$param2 = $_GET['param2'];
	$operation  = $_GET['operation'];
      }
    
     
if (isset($param1) &&  isset($param2))
    {
      /*
      echo $operation;
      echo $param1;
      echo $param2;
      */

$reqPayloadString = <<<XML
<ns1:$operation xmlns:ns1="http://ws.apache.org/axis2/php/math">
     <param1>$param1</param1>
      <param2>$param2</param2>
</ns1:$operation>
XML;

     try
       {
	    $client = new WSClient(array(
				      "to"=>$epr));
	    $response = $client->request($reqPayloadString);
	 
	    if ($response)
	    {
	         echo "Result : ".$response->str."";
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

?>




</body>
</html>

