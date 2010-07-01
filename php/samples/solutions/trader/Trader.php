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
if(isset($_POST["getResult"]))
$getResult = $_POST["getResult"];
if(isset($_POST["operation"]))
$operation = $_POST["operation"];
if(isset($_POST["epr"]))
$epr = $_POST["epr"];
if(isset($_POST["userid"]))
$userid = $_POST["userid"];
if(isset($_POST["password"]))
$password = $_POST["password"];
if(isset($_POST['symbol']))
$symbol = $_POST['symbol'];
if(isset($_POST["amount"]))
$amount = $_POST["amount"];		    
?>

<html>
<head>
<title> Trader Service </title>
</head>
<body>
<form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
<table cols="4" border="1" cellpadding="10" cellspacing="0" align="center" width="100%" style="background-image: url(/images/cse.jpg);background-repeat: no-repeat;background-position: center right" bgcolor="#9999FF">
<tr>
<td>
<h4>Trader</h4>
<h4>Operations</h4>

Create Account : <input type="radio" value="create-account" name="operation" checked ></br></br>

Buy: <input type="radio" value="buy" name="operation"></br></br>

Sell: <input type="radio" value="sell" name="operation"></br></br>

Get Portfolio: <input type="radio" value="getPortfolio" name="operation">
<br/><br/>
<h4>Target Endpoint</h4>
Endpoint:<input type="text" size="60" maxlength="60" name="epr" 
          value="http://localhost/samples/solutions/trader/TraderService.php"><br />

<h4>Parameters</h4>
User ID:<input type="text" size="6" maxlength="15" name="userid" value="">
Password:<input type="password" size="6" maxlength="15" name="password" value="">
Symbol:<input type="text" size="6" maxlength="15" name="symbol" value="">
Amount:<input type="text" size="6" maxlength="15" name="amount" value=""><br/>
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
        if (isset($_GET['userid']) && isset($_GET['password']))
           {
	    $epr = $_GET['epr'];
	    $userid = $_GET['userid'];
	    $password = $_GET['password'];
	    $operation  = $_GET['operation'];
	    $symbol = $_GET['symbol'];
	    $amount = $_GET['amount'];
           }
    
     
        if (isset($userid) &&  isset($password))
           {
            $reqPayloadString = <<<XML
            <ns1:$operation xmlns:ns1="http://ws.apache.org/axis2/php/trader">
            <param1>$userid</param1>
            <param2>$password</param2>
	    <param3>$symbol</param3>
	    <param4>$amount</param4>
</ns1:$operation>
XML;

            try
              {
	       $client = new WSClient(array(
				      "to"=>$epr));
	       $response = $client->request($reqPayloadString);
	 
	       if ($response)
	          {
	   // output according to the operation  
          	  if ($operation=="create-account")
                     {
         	      call_user_func ('resultcreateaccount', $response);
         	     }
  
          	  if ($operation=="getPortfolio")
                     {		 
         	      call_user_func ('resultgetPortfolio', $response,"","");
         	     }
		
		  if ($operation=="buy")
                     {
        	      call_user_func ('resultbuy', $response,$symbol);
       	   	     }

		  if ($operation=="sell")
                     {
       	              call_user_func ('resultsell', $response,$symbol);
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



    function resultcreateaccount($response)
      {
       echo  "$response->str";
      }


    function resultbuy($response,$symbol)
      {
       $op = "resultbuy";  
       call_user_func ('resultgetPortfolio', $response,$symbol,$op);
      
      }


    function resultsell($response,$symbol)
      {
       $op = "resultsell";
       call_user_func ('resultgetPortfolio', $response,$symbol,$op);
      }


    function resultgetPortfolio($response,$symbol1,$op)
      { 
       $strresponse = $response->str;

// Making the $strresponse to normal string type thus $output
       $dom = new DOMDocument();
       $dom->loadXML($strresponse);
       $result = $dom->getElementsByTagName( "result" );
       $output = $result->item(0)->nodeValue;
//
       if (strcmp($output,"Match") == 0)
          {
		  $doc = new DOMDocument();
	   if (stristr(PHP_OS, 'WIN')) {
	    	   $doc =DOMDocument::load("portfolio.xml");
	   }else{
	    	   $doc =DOMDocument::load("portfolio.xml");
	   }

   	   $items = $doc->getElementsByTagName( "item" );
?>
<form >
<table cols="4" border="1" cellpadding="10" cellspacing="0" align="left" width="50%" bgcolor="#eeeeee">
<tr>
<td>
           <?php   
           echo "Symbol ";
           ?>
           <td>
           <?php   
           echo "Amount";

           foreach( $items as $item )
             {
              $Symbols = $item->getElementsByTagName( "Symbol" );
              $Symbol = $Symbols->item(0)->nodeValue;

              $amounts = $item->getElementsByTagName( "Amount" );
              $amount = $amounts->item(0)->nodeValue;
           ?>
<tr>
<td>
           <?php   
           echo "$Symbol";
           ?>
</td>
<td>
           <?php
           echo "$amount";
           echo "million";
           ?>
</td>
</tr>
           <?php
             }

           if($op=="resultbuy" or $op=="resultsell")
             echo "Amount of $symbol1 changed";
                    
          }
       else
          echo "$strresponse";

           ?>
</table>
</form>
<?php
      }

?>
</body>
</html>
