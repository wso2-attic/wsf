--TEST--
Test for ws_message_dom_get_echo_client.phpt sample
--FILE--

<?php

$reqPayloadString = <<<XML
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
XML;
/*
$doc = new DOMDocument();
$doc->loadXML($reqPayloadString);
$req = new WSMessage($doc);
echo $req->str;
*/

$msg = new WSMessage($reqPayloadString);
echo $msg->dom->saveXML();

?>


--EXPECT--
Response = &lt;ns1:echo xmlns:ns1=&quot;http://php.axis2.org/samples&quot;&gt;
		&lt;text&gt;Hello World!&lt;/text&gt;
	&lt;/ns1:echo&gt;