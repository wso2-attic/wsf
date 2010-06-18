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
  * This sample sends a Goole key and other relevant data to Google 
  * search service. 
  * If everyting goes right, it returns a set of search results.
  * You can control the number of results through maxResults parameter
  * in the request payload.
  * Google search uses SOAP 1.1.
 */

$apikey = "abc";
$search = 'WSO2';
if(isset($_POST['apikey']))
$apikey = $_POST['apikey'];
if(isset($_POST['search']))
$search = $_POST['search'];
?>


<html>
<head>
	<title>Google Search Sample</title>
</head>
<body>
<h2>Google Search</h2>
<form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
Your Google api key :<input type="text" size="60" maxlength="60" name="apikey"/><br/><br/>
Keywords for searching :<input type="text" size="60" maxlength="60" name="search"/><br/><br/>
<input style="margin-left:200px;" type="submit" value="submit" name="submit"/>
</form>
</body>
</html> 
<?php

if(isset($_POST['apikey']))
{
$requestPayloadString = <<<XML
<ns1:doGoogleSearch x:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/" xmlns:ns1="urn:GoogleSearch" xmlns:x="http://schemas.xmlsoap.org/soap/envelope/" xmlns:xsi="http://www.w3.org/1999/XMLSchema-instance" xmlns:xsd="http://www.w3.org/1999/XMLSchema">
    <key xsi:type="xsd:string">$apikey</key>
    <q xsi:type="xsd:string">$search</q>
    <start xsi:type="xsd:int">0</start>
    <maxResults xsi:type="xsd:int">10</maxResults>
    <filter xsi:type="xsd:boolean">true</filter>
    <restrict xsi:type="xsd:string"></restrict>
    <safeSearch xsi:type="xsd:boolean">false</safeSearch>
    <lr xsi:type="xsd:string"></lr>
    <ie xsi:type="xsd:string">latin1</ie>
    <oe xsi:type="xsd:string">latin1</oe>
</ns1:doGoogleSearch>
XML;

try {
    $client = new WSClient(array("to" => "http://api.google.com/search/beta2",
        "useSOAP"=>"1.1")); 

    $responsePayload = $client->request($requestPayloadString);
    printf("Response = %s <br/>\n", htmlspecialchars($responsePayload->str));
} catch (Exception $e) {
    if ($e instanceof WSFault) {
        printf("Please specify a correct google key");
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
}
}
?>
