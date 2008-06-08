<?php

// PHP classes corresponding to the data types in defined in WSDL

class Header1 {
    public $string; // string
    public $int; // int
}

class Header2 {
    public $int; // int
    public $string; // string
}

// define the class map
$class_map = array(
    "Header1" => "Header1",
    "Header2" => "Header2");

// define PHP functions that maps to WSDL operations 
/**
 * Service function echoString
 * @param string $input 
 * @param object of Header1 $header_in0 input header
 * @param object of Header2 $header_in1 input header
 * @param reference object of Header1 $header_out0 output header
 * @param reference object of Header2 $header_out1 output header
 * @return string 
 */
function echoString($input, $header_in0, $header_in1, &$header_out0, &$header_out1) {
    // TODO: fill in the business logic
    // NOTE: $input is of type string

    // NOTE: $header_in0 header is of type Header1
    // NOTE: $header_in1 header is of type Header2

    // NOTE: you should assign an object of type Header1 to $header_out0
    $header_out0 = $header_in0;
    // NOTE: you should assign an object of type Header2 to $header_out1
    $header_out1 = $header_in1;

    // NOTE: should return an object of (type: string)
    return $input;
    
}


// define the operations map
$operations = array(
    "echoString" => "echoString");

// define the actions => operations map
$actions = array(
    "http://soapinterop.org/" => "echoString");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"headers.wsdl",
        "actions" => $actions,
        "classmap" => $class_map,
        "operations" => $operations));

// process client requests and reply 
$service->reply();

?>
