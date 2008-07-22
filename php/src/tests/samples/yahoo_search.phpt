--TEST--
Test for Yahoo sample
--FILE--
<?php
$reqPayloadString = <<<XML
<webSearch><appid>ApacheRestDemo</appid><query>SriLanka</query><form/></webSearch>
XML;

try {

    $client = new WSClient(
        array("to"=>"http://search.yahooapis.com/WebSearchService/V1/webSearch",
	      "HTTPMethod"=>"GET",
	      "useSOAP"=>FALSE));
				
    $resMessage = $client->request($reqPayloadString);
    
    if($resMessage->str){
		echo "Search Successfull";
    }
    

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}

?>

--EXPECT--
Search Successfull