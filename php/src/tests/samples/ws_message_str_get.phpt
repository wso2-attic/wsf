--TEST--
Test for ws_message_str_get sample
--FILE--

<?php

$reqPayloadString = <<<XML
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
XML;

$doc = new DOMDocument();
$doc->loadXML($reqPayloadString);
$req = new WSMessage($doc);
echo $req->str;

?>

--EXPECT--
Response = <ns1:echo xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echo>