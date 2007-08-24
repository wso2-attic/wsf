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