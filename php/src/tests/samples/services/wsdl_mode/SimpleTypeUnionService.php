<?php

// define PHP functions that maps to WSDL operations 
function myDemo($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type string/string
    //NOTE: $input should follow the following restrictions
    // type string hold the following restrictions
    /* You can have one of the following value
     * banana
     * oragne
     */
    // type string hold the following restrictions
    /* You can have one of the following value
     * ice cream
     * salad
     */

    // NOTE: should return an object of (type: string)
    return $input;
}


// define the operations map
$operations = array(
 "myDemo" => "myDemo");

// define the actions => operations map
$actions = array(
 "urn:myDemo" => "myDemo");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"SimpleTypeUnion.wsdl",
        "operations" => $operations,
        "actions" => $actions,
                            ));

// process client requests and reply 
$service->reply();

?>
