<?php

// PHP classes corresponding to the data types in defined in WSDL

class myDemo_inner_nil {

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
    "myDemo_inner_nil" => "myDemo_inner_nil");

// define PHP functions that maps to WSDL operations 
/**
 * Service function myDemo_inner_nil
 * @param object of myDemo_inner_nil $input 
 * @return string 
 */
function myDemo_inner_nil($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type myDemo_inner_nil
    // NOTE: should return an object of (type: string)

    if($input === NULL) {
        return "\$input === NULL\n";
    }
    else if($input == NULL) {
        return "\$input == NULL\n";
    }

    if($input->demo1 === NULL) {
        return "\$input->demo1 === NULL\n";
    }
    else if($input->demo1 == NULL) {
        return "\$input->demo1 == NULL\n";
    }

    return "\$input nothing with NULL\n";
}


/**
 * Service function myDemo_root_nil
 * @param string $input 
 * @return string 
 */
function myDemo_root_nil($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type string

    // NOTE: should return an object of (type: string)

    if($input === NULL) {
        return "\$input === NULL\n";
    }
    else if($input == NULL) {
        return "\$input == NULL\n";
    }
    else if($input != NULL) {
        return "\$input != NULL\n";
    }

    return "\$input nothing with NULL\n";


}


// define the operations map
$operations = array(
    "myDemo_inner_nil" => "myDemo_inner_nil",
    "myDemo_root_nil" => "myDemo_root_nil");

// define the actions => operations map
$actions = array(
    "urn:myDemo" => "myDemo_root_nil");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"NullHandling.wsdl",
        "actions" => $actions,
        "classmap" => $class_map,
        "operations" => $operations));

// process client requests and reply 
$service->reply();

?>
