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

/** 
  * Note: This is a simole example written just as a proof of concept. 
  * You may write a nice web interface to improve the usability.    
  * This sample sends a Goole key and a phrase to Google spell service. 
  * If everyting goes right, it returns a spell corrected version of 
  * the prase you submit.
  * Google spell uses SOAP 1.1.
 */
$apikey = "";
$spell_word ="temparatue";
if(isset($_POST['apikey']))
$apikey = $_POST['apikey'];
if(isset($_POST['spell_word']))
$spell_word = $_POST['spell_word'];
?>
<html>
<head>
<title>Google Spell</title>
</head>
<body>
<h2>Google Spell Service</h2>
<form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
Your Google api key :<input type="text" size="60" maxlength="60" name="apikey"/><br/><br/>
Word to Spell :<input type="text" size="60" maxlength="60" name="spell_word"/><br/><br/>

<input style="margin-left:200px;" type="submit" value="submit" name="submit"/>
</form>
</body>
</html>
<?php

if(isset($_POST['apikey']))
{
$requestPayloadString = <<<XML
<ns1:doSpellingSuggestion x:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/" xmlns:ns1="urn:GoogleSearch" xmlns:x="http://schemas.xmlsoap.org/soap/envelope/" xmlns:xsi="http://www.w3.org/1999/XMLSchema-instance" xmlns:xsd="http://www.w3.org/1999/XMLSchema">
    <key xsi:type="xsd:string">$apikey</key>
    <phrase xsi:type="xsd:string">$spell_word</phrase>
</ns1:doSpellingSuggestion>
XML;

try {
    $client = new WSClient(array( "to" => "http://api.google.com/search/beta2", 
                                  "useSOAP" => 1.1)); 
    $responseMessage = $client->request($requestPayloadString);

    printf("Response = %s <br/>\n", htmlspecialchars($responseMessage->str));

} catch (Exception $e) {
    if ($e instanceof WSFault) {
        printf("Please enter a correct API Key");
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
    
}
}

?>
