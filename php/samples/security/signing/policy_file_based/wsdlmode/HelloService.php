<?php

// PHP classes corresponding to the data types in defined in WSDL

class greet {

    /**
     * @var string
     */
    public $name;

}

class greetResponse {

    /**
     * @var string
     */
    public $return;

}

// define the class map
$class_map = array(
    "greet" => "greet",
    "greetResponse" => "greetResponse");

// define PHP functions that maps to WSDL operations 
/**
 * Service function greet
 * @param object of greet $input 
 * @return object of greetResponse 
 */
function greet($input) {
   $res = new greetResponse();
   $res->return = "HelloWorld";
   return $res;
}


// define the operations map
$operations = array(
    "greet" => "greet");

// define the actions => operations map
$actions = array(
    "urn:greet" => "greet");

$cert = ws_get_cert_from_file("../../../keys/bob_cert.cert");
$pvt_key = ws_get_key_from_file("../../../keys/bob_key.pem");

$sec_token = new WSSecurityToken(array("privateKey" => $pvt_key,
                                       "certificate" => $cert));

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"HelloService.wsdl",
        "actions" => $actions,
		"useWSA"=>TRUE,
		"securityToken"=>$sec_token,
        "classmap" => $class_map,
        "operations" => $operations));

// process client requests and reply 
$service->reply();

?>
