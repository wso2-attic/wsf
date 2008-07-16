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

function createaccountFunction($inMessage) {
    
    $simplexml = new SimpleXMLElement($inMessage->str);
    $userid = $simplexml->param1[0];
    $password = $simplexml->param2[0];

    if($userid=="" or $password==""){
       $Result="User ID or Password is required";
       $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
       $returnMessage = new WSMessage($resPayload);
       return $returnMessage;
    }
    
    $fp;
    if (stristr(PHP_OS, 'WIN')) {
	    $fp = @fopen('members.xml','r+');
    }else{
	    $fp = @fopen('/tmp/members.xml','r+');
    
    }
    if(!$fp) {   
       $clients = array();
       $clients [] = array(
       'UserID' => $userid,
       'Password' => $password,
       );

       $doc = new DOMDocument("1.0");
       $doc->formatOutput = true;
       $r = $doc->createElement( "clients" );
       $doc->appendChild( $r );

       foreach( $clients as $client ){
          $b = $doc->createElement( "client" );
  
          $UserID = $doc->createElement( "UserID" );
          $UserID->appendChild($doc->createTextNode( $client['UserID'] ));
          $b->appendChild( $UserID );
  
          $Password = $doc->createElement( "Password" );
          $Password->appendChild($doc->createTextNode( $client['Password']));
          $b->appendChild( $Password );
          $r->appendChild( $b );
       }
	   if (stristr(PHP_OS, 'WIN')) {
		    print $doc->save("members.xml");
	   }else{
		    print $doc->save("/tmp/members.xml");
	    
	  }
   }else{
	    $doc;
        if(stristr(PHP_OS, 'WIN')) {
	      $doc =DOMDocument::load("members.xml");
         }else{
     	      $doc =DOMDocument::load("/tmp/members.xml");
         }
        $doc->formatOutput = true;
        $r = $doc->firstChild;

        $clients = $doc->getElementsByTagName( "client" );

        foreach( $clients as $client ){
          $UserIDs = $client->getElementsByTagName( "UserID" );
          $UserID = $UserIDs->item(0)->nodeValue;
   
          if ($userid==$UserID){
              $Resultcheck="User ID alredy has been using";
              $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Resultcheck</ns1:result>
XML;
              $returnMessage = new WSMessage($resPayload);
              return $returnMessage;
          }
      } 

      if($Resultcheck==""){
          $clients = array();
          $clients [] = array(
          'UserID' => $userid,
          'Password' => $password,
          );

       foreach( $clients as $client ){
             $b = $doc->createElement( "client" );
  
             $UserID = $doc->createElement( "UserID" );
             $UserID->appendChild(
             $doc->createTextNode( $client['UserID'] )
             );
             $b->appendChild( $UserID );
  
             $Password = $doc->createElement( "Password" );
             $Password->appendChild(
             $doc->createTextNode( $client['Password'] )
             );
             $b->appendChild( $Password );
  
             $r->appendChild( $b );
         }
  
         fwrite($fp,$doc->savexml());
         fclose($fp);
      }
   }
   $epr = "http://localhost/samples/solutions/trader/ExchangeTrader.php";
   $operation = "create-account";
 
    $reqPayloadString = <<<XML
    <ns1:$operation xmlns:ns1="http://ws.apache.org/axis2/php/trader">
    <param1>$userid</param1>
    <param2>$password</param2>
    </ns1:$operation>
XML;

    try{
    	$client = new WSClient(array("to"=>$epr));
    	$response = $client->request($reqPayloadString);
		if ($response){      
            $Result = "Created";    
            $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
            $returnMessage = new WSMessage($resPayload);
            return $returnMessage;
	    } 
    }
    catch (Exception $e){
    	if ($e instanceof WSFault){
	        print"Soap Fault:\n".$e->Reason;
	    }else{
	        print"Message:\n".$e->getMessage();
	    }
    }
}


function buyFunction($inMessage) {

    $simplexml = new SimpleXMLElement($inMessage->str);
    $userid = $simplexml->param1[0];
    $password = $simplexml->param2[0];
    $symbol = $simplexml->param3[0];
    $amount = $simplexml->param4[0];

// check the validity of inputs
    if($userid=="" or $password=="" or $symbol=="" or $amount==""){
       $Result="Not all required data are provided";
       $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
       $returnMessage = new WSMessage($resPayload);
       return $returnMessage;
   }

// check the amount validity
    if ($amount < 0 or $amount == 0){
        $Result="Amount has not supplied as to valid";
        $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
        $returnMessage = new WSMessage($resPayload);
        return $returnMessage;
    } 


    $doc = new DOMDocument();
    if (stristr(PHP_OS, 'WIN')) {
	    $doc =DOMDocument::load("members.xml");
    }else{
            $doc =DOMDocument::load("/tmp/members.xml");
    }

    $epr = "http://localhost/ExchangeTrader.php";
    $operation = "buy";

    $clients = $doc->getElementsByTagName( "client" );
    foreach( $clients as $client ){
       $UserIDs = $client->getElementsByTagName( "UserID" );
       $UserID = $UserIDs->item(0)->nodeValue;
  
       $passwords = $client->getElementsByTagName( "Password" );
       $Password = $passwords->item(0)->nodeValue;
   
       if ($userid==$UserID and $password==$Password){
           $Result1="Match";

           $reqPayloadString = <<<XML
<ns1:$operation xmlns:ns1="http://ws.apache.org/axis2/php/trader">
     <param1>$userid</param1>
      <param2>$password</param2>
       <param3>$symbol</param3>
        <param4>$amount</param4>
</ns1:$operation>
XML;

        try{
	        $client = new WSClient(array("to"=>$epr));
            $response = $client->request($reqPayloadString);

            if ($response){      
                   $Result = $response->str;    
                   $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;

                   $returnMessage = new WSMessage($resPayload);
                   return $returnMessage;

            } 
         }catch (Exception $e){
    	       if ($e instanceof WSFault){
    	           print"Soap Fault:\n".$e->Reason;
	           }else{
	                print"Message:\n".$e->getMessage();
	           }
         }
      }
    }
    if($Result1 ==""){
       $Result="Wrong User ID or Password";
       $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
       $returnMessage = new WSMessage($resPayload);
       return $returnMessage;
   }
}
   

function sellFunction($inMessage) {
    
    $simplexml = new SimpleXMLElement($inMessage->str);
    $userid = $simplexml->param1[0];
    $password = $simplexml->param2[0];
    $symbol = $simplexml->param3[0];
    $amount = $simplexml->param4[0];

// check the validity of inputs
    if($userid=="" or $password=="" or $symbol=="" or $amount=="")
      {
       $Result="Not all required data are provided";

       $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
       $returnMessage = new WSMessage($resPayload);
       return $returnMessage;
      }

// check the amount validity
    if ($amount < 0 or $amount == 0)
       {
        $Result="Amount has not supplied as to valid";
        $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
        $returnMessage = new WSMessage($resPayload);
        return $returnMessage;
       } 


    $doc = new DOMDocument();
    if (stristr(PHP_OS, 'WIN')) {
    $doc =DOMDocument::load("members.xml");
    }else{
    $doc =DOMDocument::load("/tmp/members.xml");
    }
    $epr = "http://localhost/samples/solutions/trader/ExchangeTrader.php";
    $operation = "sell";

    $clients = $doc->getElementsByTagName( "client" );
    foreach( $clients as $client )
      {
       $UserIDs = $client->getElementsByTagName( "UserID" );
       $UserID = $UserIDs->item(0)->nodeValue;
  
       $passwords = $client->getElementsByTagName( "Password" );
       $Password = $passwords->item(0)->nodeValue;
  
  
       if ($userid==$UserID and $password==$Password)
          {
           $Result1="Match";

           $reqPayloadString = <<<XML
<ns1:$operation xmlns:ns1="http://ws.apache.org/axis2/php/trader">
     <param1>$userid</param1>
      <param2>$password</param2>
       <param3>$symbol</param3>
        <param4>$amount</param4>
</ns1:$operation>
XML;

           try{
	       $client = new WSClient(array(
				      "to"=>$epr));
	       $response = $client->request($reqPayloadString);
	 
	       if ($response)
	          {      
                   $Result = $response->str;    
                   $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;

                   $returnMessage = new WSMessage($resPayload);
                   return $returnMessage;
	          } 
              }

           catch (Exception $e)
              {
	       if ($e instanceof WSFault)
	          {
	           print"Soap Fault:\n".$e->Reason;
	          }
	       else
	          {
	           print"Message:\n".$e->getMessage();
	          }
              }
          }
      }
    if($Result1 =="")
      {
       $Result="Wrong User ID or Password";
       $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
       $returnMessage = new WSMessage($resPayload);
       return $returnMessage;
      }

}



function getPortfolioFunction($inMessage) {

    $simplexml = new SimpleXMLElement($inMessage->str);
    $userid = $simplexml->param1[0];
    $password = $simplexml->param2[0];
     
    $epr = "http://localhost/samples/solutions/trader/ExchangeTrader.php";
    $operation = "getPortfolio";

    $doc = new DOMDocument();
    if (stristr(PHP_OS, 'WIN')) {
	    $doc =DOMDocument::load("members.xml");
    }else{
    	    $doc =DOMDocument::load("/tmp/members.xml");
    }

    $clients = $doc->getElementsByTagName( "client" );
    foreach( $clients as $client )
      {
       $UserIDs = $client->getElementsByTagName( "UserID" );
       $UserID = $UserIDs->item(0)->nodeValue;
  
       $passwords = $client->getElementsByTagName( "Password" );
       $Password = $passwords->item(0)->nodeValue;
  
       if ($userid==$UserID and $password==$Password)
          {
           $Result1="Match";
           $reqPayloadString = <<<XML
<ns1:$operation xmlns:ns1="http://ws.apache.org/axis2/php/trader">
     <param1>$userid</param1>
      <param2>$password</param2>
</ns1:$operation>
XML;

           try{
	       $client = new WSClient(array(
				      "to"=>$epr));
	       $response = $client->request($reqPayloadString);
	 
	       if ($response)
	          {      
                   $Result = $response->str;    
                   $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;

                   $returnMessage = new WSMessage($resPayload);
                   return $returnMessage;
	          } 
              }
           catch (Exception $e)
              {
	       if ($e instanceof WSFault)
	          {
	           print"Soap Fault:\n".$e->Reason;
	          }
	       else
	          {
	           print"Message:\n".$e->getMessage();
	          }
              }

          }
      }

    if($Result1 == "")
      {
       $Result="Wrong User ID or Password";
       $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
       $returnMessage = new WSMessage($resPayload);
       return $returnMessage;
      }

}


$operations = array("create-account" => "createaccountFunction",
                    "buy" => "buyFunction",
                    "sell" => "sellFunction",
                    "getPortfolio" => "getPortfolioFunction");

$svr = new WSService(array("operations" => $operations));
        
$svr->reply();

?>


