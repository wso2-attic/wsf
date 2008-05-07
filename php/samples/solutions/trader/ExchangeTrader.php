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

    $fp;
    if (stristr(PHP_OS, 'WIN')) {
	    $fp = @fopen('emembers.xml','r+');
    }else{
    	    $fp = @fopen('/tmp/emembers.xml','r+');
    }
    if(!$fp) 
      {
       $clients = array();
       $clients [] = array(
       'UserID' => $userid,
       'Password' => $password,
       );

       $doc = new DOMDocument("1.0");
       $doc->formatOutput = true;
       $r = $doc->createElement( "clients" );
       $doc->appendChild( $r );

       foreach( $clients as $client )
         {
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
	 if (stristr(PHP_OS, 'WIN')) {
		 print $doc->save("emembers.xml");
	 }else{
	    print $doc->save("/tmp/emembers.xml");    }
         }
     else
      {
       $clients = array();
       $clients [] = array(
       'UserID' => $userid,
       'Password' => $password,
       );

	if (stristr(PHP_OS, 'WIN')) {
		$doc =DOMDocument::load("emembers.xml");
	}else{
		$doc =DOMDocument::load("/tmp/emembers.xml");       
       	}
       
       $doc->formatOutput = true;
       $r = $doc->firstChild;

       foreach( $clients as $client )
         {
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

    $Result = $password;  
    $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
    $returnMessage = new WSMessage($resPayload);
    return $returnMessage;
}


function buyFunction($inMessage) {

    $simplexml = new SimpleXMLElement($inMessage->str);
    $userid = $simplexml->param1[0];
    $password = $simplexml->param2[0];
    $symbol = $simplexml->param3[0];
    $amount = $simplexml->param4[0];


//user validate goes here

    $doc = new DOMDocument();
    if (stristr(PHP_OS, 'WIN')) {
    	$doc =DOMDocument::load("emembers.xml");
    }else{
    	$doc =DOMDocument::load("/tmp/emembers.xml");
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
	
       	   if (stristr(PHP_OS, 'WIN')) {
		   $doc =DOMDocument::load("portfolio.xml");
	   }else{
	   	   $doc =DOMDocument::load("/tmp/portfolio.xml");
	   }
           $doc->formatOutput = true;
           $r = $doc->firstChild;

           $items = $doc->getElementsByTagName( "item" );

           foreach( $items as $item )
             {
              $Symbols = $item->getElementsByTagName( "Symbol" );
              $Symbol = $Symbols->item(0)->nodeValue;
  
              $Amounts = $item->getElementsByTagName( "Amount" );
              $Amount = $Amounts->item(0)->nodeValue;

              if ($symbol == $Symbol)
                 {     
// calculation and its validation goes here
                  $Newamount = $Amount - $amount;

                  if ($Newamount < 0)
                     { 
                      $Message = "You can't buy more than exist";
                      $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Message</ns1:result>
XML;
                      $returnMessage = new WSMessage($resPayload);
                      return $returnMessage;
                     }

                  else
                     { 
  		      $Amount = $Amounts->item(0)->nodeValue=$Newamount;		
	              if (stristr(PHP_OS, 'WIN')) {
			      $doc->save("portfolio.xml");
		      }else{
		      	      $doc->save("/tmp/portfolio.xml");
		      }
		      $Result="Match";
                     }
                 }
             }
           
           if($Result=="")
             {
              $Result="The Symbol is not in use";
             }

           $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
           $returnMessage = new WSMessage($resPayload);
           return $returnMessage;

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


function sellFunction($inMessage) {

    $simplexml = new SimpleXMLElement($inMessage->str);
    $userid = $simplexml->param1[0];
    $password = $simplexml->param2[0];
    $symbol = $simplexml->param3[0];
    $amount = $simplexml->param4[0];


//user validate goes here

    $doc = new DOMDocument();
    if (stristr(PHP_OS, 'WIN')) {
	    $doc =DOMDocument::load("emembers.xml");
    }else{
   	    $doc =DOMDocument::load("/tmp/emembers.xml");
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
   	   if (stristr(PHP_OS, 'WIN')) {
                $doc =DOMDocument::load("portfolio.xml");
	   }else{
	           $doc =DOMDocument::load("/tmp/portfolio.xml");
	   }
           $doc->formatOutput = true;
           $r = $doc->firstChild;

           $items = $doc->getElementsByTagName( "item" );
  
           foreach( $items as $item )
             {
              $Symbols = $item->getElementsByTagName( "Symbol" );
              $Symbol = $Symbols->item(0)->nodeValue;
  
              $Amounts = $item->getElementsByTagName( "Amount" );
              $Amount = $Amounts->item(0)->nodeValue;

              if ($symbol == $Symbol)
                 {   
                  $Newamount = $Amount + $amount;     
                  $Amount = $Amounts->item(0)->nodeValue=$Newamount;	
		  if (stristr(PHP_OS, 'WIN')) {       
			  $doc->save("portfolio.xml");
		  }else{
   	                  $doc->save("/tmp/portfolio.xml");
		  }
                  $Result="Match";
                 } 
             }

           if($Result=="")
             {
              $Result="The Symbol is not in use";
             }

           $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
           $returnMessage = new WSMessage($resPayload);
           return $returnMessage;

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

function getPortfolioFunction($inMessage) {

    $simplexml = new SimpleXMLElement($inMessage->str);
    $userid = $simplexml->param1[0];
    $password = $simplexml->param2[0];

// check user id and passsword

    $doc = new DOMDocument();
    if (stristr(PHP_OS, 'WIN')) {
         $doc =DOMDocument::load("emembers.xml");
    }else{
	$doc =DOMDocument::load("/tmp/emembers.xml");
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
           $Result="Match";
          }
      }

    if($Result == "")
      {
       $Result="Wrong User ID or Password";
      }
  
    $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/trader">$Result</ns1:result>
XML;
    $returnMessage = new WSMessage($resPayload);
    return $returnMessage;

}


$operations = array("create-account" => "createaccountFunction",
                    "buy" => "buyFunction",
                    "sell" => "sellFunction",
                    "getPortfolio" => "getPortfolioFunction");

$svr = new WSService(array("operations" => $operations));
        
$svr->reply();

?>
