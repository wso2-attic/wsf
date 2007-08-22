--TEST--
Test for echo_client_addr sample
--FILE--
<?php

function echoFunction($inMessage) {

    $returnMessage = new WSMessage($inMessage->str);

    return $returnMessage;
}

$operations = array("echoString" => "echoFunction");
$actions = array("http://php.axis2.org/samples/echoString" => "echoString");

$svr = new WSService(10, array("operations" => $operations, 
                              "actions" => $actions));
        
$svr->reply();

?>
--EXPECT--
Response = <ns1:echo xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echo>
