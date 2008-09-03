<?php

// PHP classes corresponding to the data types in defined in WSDL

class myDemo {

    /**
     * @var int
     */
    public $demo1;

    /**
     * @var string
     */
    public $demo2;

}

class myDemoResponse {

    /**
     * @var int
     */
    public $demo1;

    /**
     * @var string
     */
    public $demo2;

}

// define the class map
$class_map = array(
    "myDemo" => "myDemo",
    "myDemoResponse" => "myDemoResponse");

// define PHP functions that maps to WSDL operations 
/**
 * Service function myDemo
 * @param object of myDemo $input 
 * @return object of myDemoResponse 
 */
function myDemo($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type myDemo
    // NOTE: should return an object of type myDemoResponse
    
    $res = new myDemoResponse();

    $res->demo1 = $input->demo1;
    $res->demo2 = $input->demo2;

    return $res;
}


// define the operations map
$operations = array(
    "myDemo" => "myDemo");

// define the actions => operations map
$actions = array(
    "urn:myDemo" => "myDemo");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"ClassmapTest.wsdl",
        "actions" => $actions,
        "classmap" => $class_map,
        "operations" => $operations));

// process client requests and reply 
$service->reply();

?>
