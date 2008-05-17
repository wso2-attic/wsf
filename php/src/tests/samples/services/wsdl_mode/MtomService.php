<?php

// PHP classes corresponding to the data types in defined in WSDL

class getPerson {
    public $param0; // int
}

class getPersonResponse {
    public $return; // Person
}

class Person {
    public $age; // int
    public $images; // array[0, unbounded] of base64Binary
    public $someInts; // array[0, unbounded] of int
    public $name; // string
    public $someStrings; // array[0, unbounded] of string
}

class base64Binary {
    //NOTE:  should follow the following restrictions
    /* Your length of the value should be 
       Greater than 3
     */
    public $contentType; // string
    // The "value" represents the element 'images' value..
    public $value; // base64Binary
}

class setPerson {
    public $param0; // Person
}

class setPersonResponse {
    public $return; // int
}

// define the class map
$class_map = array(
 "anyType" => "anyType", "getPerson" => "getPerson", "getPersonResponse" => "getPersonResponse", "Person" => "Person", "base64Binary" => "base64Binary", "setPerson" => "setPerson", "setPersonResponse" => "setPersonResponse");

// define PHP functions that maps to WSDL operations 
function getPerson($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type getPerson
    // NOTE: should return an object of type getPersonResponse

    $ppl = new Person();
    $ppl->age = 3;
    $bin1 = new base64Binary();
    $bin1->contentType = "image/jpeg";
    $bin1->value = "xxxxx";

    $bin2 = new base64Binary();
    $bin2->contentType = "image/jpeg";
    $bin2->value = "yyyy";
    $ppl->images = array($bin1, $bin2);
    $ppl->someInts = array(5, 6);
    $ppl->name = "test";
    $ppl->someStrings = array("test1", "test2");

    $ret = new getPersonResponse();
    $ret->return = $ppl;

    return $ret;
}


function setPerson($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type setPerson
    // NOTE: should return an object of type setPersonResponse

    $x =new setPersonResponse();
    $x->return = 5;
    return $x;
}


// define the operations map
$operations = array(
 "getPerson" => "getPerson", "setPerson" => "setPerson");

// define the actions => operations map
$actions = array(
 "urn:getPerson" => "getPerson", "urn:setPerson" => "setPerson");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"Mime.wsdl",
        "operations" => $operations,
        "actions" => $actions,
        "useMTOM" => TRUE,
        "classmap" => $class_map,
                            ));

// process client requests and reply 
$service->reply();

?>
