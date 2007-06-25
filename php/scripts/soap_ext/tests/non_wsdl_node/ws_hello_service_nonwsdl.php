<?php

include_once 'soap_ext/soap_ext.php';

function greet($param) {
    $retval = 'Hello '.$param; 
    return new WSSoapParam($retval, 'greetReturn');
}

$server = new WSSoapServer(null, array('uri' => 'http://localhost/axis/helloService'));

$server->addFunction('greet');

$server->handle();
?> 
