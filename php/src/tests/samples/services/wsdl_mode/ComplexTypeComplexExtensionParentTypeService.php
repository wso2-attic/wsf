<?php

// PHP classes corresponding to the data types in defined in WSDL

class parentType {

    /**
     * @var int
     */
    public $demo3;

    /**
     * @var string
     */
    public $demo4;

}

class childType extends parentType {

    /**
     * @var int
     */
    public $demo1;

    /**
     * @var string
     */
    public $demo2;

}

class nextLevelChildType extends childType {

    /**
     * @var int
     */
    public $demo5;

    /**
     * @var string
     */
    public $demo6;

}

class anotherChildType extends parentType {

    /**
     * @var int
     */
    public $demo5;

    /**
     * @var string
     */
    public $demo6;

}

class myDemo {

    /**
     * @var int
     */
    public $demo3;

    /**
     * @var string
     */
    public $demo4;

}

// define the class map
$class_map = array(
    "parentType" => "parentType",
    "childType" => "childType",
    "nextLevelChildType" => "nextLevelChildType",
    "anotherChildType" => "anotherChildType",
    "myDemo" => "myDemo");

// define PHP functions that maps to WSDL operations 
/**
 * Service function myDemo
 * @param object of myDemo $input 
 * @return string 
 */
function myDemo($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type myDemo
    /**
     * You can expect $input to be an instance of following class(es) in addition to myDemo
     * childType
     * nextLevelChildType
     * anotherChildType
     */
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
$service = new WSService(array ("wsdl" =>"ComplexTypeComplexExtensionParentType.wsdl",
        "actions" => $actions,
        "classmap" => $class_map,
        "operations" => $operations));

// process client requests and reply 
$service->reply();

?>
