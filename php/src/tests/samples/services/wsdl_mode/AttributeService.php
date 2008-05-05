<?php

// PHP classes corresponding to the data types in defined in WSDL

class myDemo {
    public $demo1; // string
    public $demo2; // string
    //NOTE:  should follow the following restrictions
    /* Your value should be 
       Greater than or equal to 2
       Less than or equal to 5
     */
    public $demo3; // int
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
$service = new WSService(array ("wsdl" =>"Attribute.wsdl",
        "operations" => $operations,
        "actions" => $actions,
        "classmap" => $class_map,
                            ));

// process client requests and reply 
$service->reply();

?>
