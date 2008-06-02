<?php

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

// define PHP functions that maps to WSDL operations 
function simpleAdd($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type simpleAdd
    // NOTE: should return an object of type simpleAddResponse

    $result= $input->param0 + $input->param1;

    $res = new simpleAddResponse();
    $res->return = $result;

    return $res;
}


// define the operations map
$operations = array(
    "simpleAdd" => "simpleAdd");

// define the actions => operations map
$actions = array(
    "urn:simpleAdd" => "simpleAdd");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"simple_adder.wsdl",
        "actions" => $actions,
        "classmap" => $class_map,
        "operations" => $operations));

// process client requests and reply 
$service->reply();

?>
