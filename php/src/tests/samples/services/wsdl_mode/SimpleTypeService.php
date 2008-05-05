<?php

// define PHP functions that maps to WSDL operations 
function myDemo($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type int

    // NOTE: should return an object of (type: int)
    return $input;
}


// define the operations map
$operations = array(
 "myDemo" => "myDemo");

// define the actions => operations map
$actions = array(
 "urn:myDemo" => "myDemo");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"SimpleType.wsdl",
        "operations" => $operations,
        "actions" => $actions,
                            ));

// process client requests and reply 
$service->reply();

?>
