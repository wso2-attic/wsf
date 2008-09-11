<?php

// PHP classes corresponding to the data types in defined in WSDL

class getPerson {

    /**
     * @var int
     */
    public $param0;

}

class getPersonResponse {

    /**
     * @var (object)Person
     */
    public $return;

}

class Person {

    /**
     * @var int
     */
    public $age;

    /**
     * @var array[0, unbounded] of (object)base64Binary
     */
    public $images;

    /**
     * @var array[0, unbounded] of int
     */
    public $someInts;

    /**
     * @var string
     */
    public $name;

    /**
     * @var array[0, unbounded] of string
     */
    public $someStrings;

}

class base64Binary {

    /**
     * @var string
     *     NOTE: contentType should follow the following restrictions
     *     Your length of the value should be 
     *     Greater than 3
     */
    public $contentType;

    // The "value" represents the element 'images' value..

    // You need to set only one from the following two vars

    /**
     * @var Plain Binary
     */
    public $value;

    /**
     * @var base64Binary
     */
    public $value_encoded;


}

class setPerson {

    /**
     * @var (object)Person
     */
    public $param0;

}

class setPersonResponse {

    /**
     * @var int
     */
    public $return;

}

// define the class map
$class_map = array(
    "getPerson" => "getPerson",
    "getPersonResponse" => "getPersonResponse",
    "Person" => "Person",
    "base64Binary" => "base64Binary",
    "setPerson" => "setPerson",
    "setPersonResponse" => "setPersonResponse");

// define PHP functions that maps to WSDL operations 
/**
 * Service function getPerson
 * @param object of getPerson $input 
 * @return object of getPersonResponse 
 */
function getPerson($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type getPerson
    // NOTE: should return an object of type getPersonResponse

    $ppl = new Person();
    $ppl->age = 3;
    $bin1 = new base64Binary();
    $bin1->contentType = "image/jpeg";
    $bin1->value = file_get_contents("../resources/axis2.jpg");

    $bin2 = new base64Binary();
    $bin2->contentType = "text/xml";
    $bin2->value = "<test>xml</test>";
    $ppl->images = array($bin1, $bin2);
    $ppl->someInts = array(5, 6);
    $ppl->name = "test";
    $ppl->someStrings = array("test1", "test2");


    $ret = new getPersonResponse();
    $ret->return = $ppl;

    return $ret;
    
}


/**
 * Service function setPerson
 * @param object of setPerson $input 
 * @return object of setPersonResponse 
 */
function setPerson($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type setPerson
    // NOTE: should return an object of type setPersonResponse

   
    $ppl = $input->param0;

    $age = $ppl->age;
    $images = $ppl->images;

    $bin1 = $images[0]->value;
    $bin2 = $images[1]->value;

    $image1name = "my_axis2_from_service.jpg";
    $image2name = "xml_from_service.xml";
    if(stristr(PHP_OS, 'WIN')) {
        file_put_contents($image1name, $bin1);
        file_put_contents($image2name, $bin2);
    }else{
        file_put_contents("/tmp/".$image1name, $bin1);
        file_put_contents("/tmp/".$image2name, $bin2);
    }

     
    $x =new setPersonResponse();
    $x->return = 5;
    return $x;

}


// define the operations map
$operations = array(
    "getPerson" => "getPerson",
    "setPerson" => "setPerson");

// define the actions => operations map
$actions = array(
    "urn:getPerson" => "getPerson",
    "urn:setPerson" => "setPerson");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"Mtom.wsdl",
        "useMTOM" => TRUE,
        "actions" => $actions,
        "classmap" => $class_map,
        "operations" => $operations));

// process client requests and reply 
$service->reply();

?>
