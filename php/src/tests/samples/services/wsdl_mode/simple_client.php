<?php
// to be imported by the matrix_service

// PHP classes corresponding to the data types in defined in WSDL

class simpleAdd {
    public $param0; // int
    public $param1; // int
}

class simpleAddResponse {
    public $return; // int
}

// define the class map
$class_map = array(
    "simpleAdd" => "simpleAdd",
    "simpleAddResponse" => "simpleAddResponse");


// create client in WSDL mode
$client = new WSClient(array ("wsdl" =>"simple_adder.wsdl",
    "classmap" => $class_map));

// get proxy object reference form client 
$proxy = $client->getProxy();


?>
