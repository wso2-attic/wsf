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

$apikey = "";
$search = "cars";
if(isset($_POST['apikey']))
$apikey = $_POST['apikey'];

?>

<html>
<head>
	<title>Flickr Search</title>
</head>
<body>
<h2>Flickr Search</h2>
<form method="post" action="<?php echo $PHP_SELF;?>">
Your Flickr api key :<input type="text" size="60" maxlength="60" name="apikey"/><br/><br/>
Keyword for searching :<input type="text" size="60" maxlength="60" name="search"/><br/><br/>
<input style="margin-left:200px;" type="submit" value="submit" name="submit"/>
</form>
</body>
</html>

<?php
if(isset($_POST['apikey']))
{

$requestPayloadString = <<<XML
<x:FlickrRequest xmlns:x="urn:flickr">
<method>flickr.test.echo</method>
<api_key>$apikey</api_key>
<name>$search</name>
</x:FlickrRequest>
XML;

try {

    $flicker_client = new WSClient(
        array("to" => "http://localhost:8081/services/soap/"));

                
    $responseMessage = $flicker_client->request($requestPayloadString);
    
    printf("Response = %s <br>", htmlspecialchars($responseMessage->str));

} catch (Exception $e) {

    if ($e instanceof WSFault) {
        printf("Request Failed, Please enter correct flickr api key \n");
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
}
}
?>






