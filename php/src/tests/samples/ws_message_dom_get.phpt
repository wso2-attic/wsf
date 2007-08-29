--TEST--
Test for ws_message_dom_get sample
--FILE--

<?php

$reqPayloadString = <<<XML
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
XML;

$messge = new WSMessage($reqPayloadString);
echo $messge->dom->saveXML();

?>


--EXPECT--
<?xml version="1.0"?>
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>