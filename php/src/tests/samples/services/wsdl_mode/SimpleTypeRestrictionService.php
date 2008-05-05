<?php

// define PHP functions that maps to WSDL operations 
function myDemo($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type string
    //NOTE: $input should follow the following restrictions
    /* You can have one of the following value
     * a
     * ab
     * abc
     * abcd
     */
    /* Your length of the value should be 
       Greater than 2
       Less than 3
     */

    // NOTE: should return an object of (type: int)
    return strlen($input);
}


// define the operations map
$operations = array(
 "myDemo" => "myDemo");

// define the actions => operations map
$actions = array(
 "urn:myDemo" => "myDemo");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"SimpleTypeRestriction.wsdl",
        "operations" => $operations,
        "actions" => $actions,
                            ));

// process client requests and reply 
$service->reply();

?>
