<?php

// PHP classes corresponding to the data types in defined in WSDL

class myDemo {

    // You may set only one from the following set
    // ---------------Start Choice----------------
    public $demo1; // int
    public $demo2; // string
    // ----------------End Choice---------------

}

// define the class map
$class_map = array(
 "anyType" => "anyType", "myDemo" => "myDemo");

// define PHP functions that maps to WSDL operations 
function myDemo($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type myDemo
    // NOTE: should return an object of (type: string)

    return print_r($input, TRUE);
}


// define the operations map
$operations = array(
 "myDemo" => "myDemo");

// define the actions => operations map
$actions = array(
 "urn:myDemo" => "myDemo");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"ComplexTypeChoice.wsdl",
        "operations" => $operations,
        "actions" => $actions,
        "classmap" => $class_map,
                            ));

// process client requests and reply 
$service->reply();

?>
