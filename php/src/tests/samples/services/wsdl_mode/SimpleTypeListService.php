<?php

// define PHP functions that maps to WSDL operations 
function myDemo($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type array of int

    $sum = 0;
    foreach($input as $in) {
        $sum += $in;
    }
    // NOTE: should return an object of (type: int)
    return $sum;
}


// define the operations map
$operations = array(
 "myDemo" => "myDemo");

// define the actions => operations map
$actions = array(
 "urn:myDemo" => "myDemo");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"SimpleTypeList.wsdl",
        "operations" => $operations,
        "actions" => $actions,
                            ));

// process client requests and reply 
$service->reply();

?>
