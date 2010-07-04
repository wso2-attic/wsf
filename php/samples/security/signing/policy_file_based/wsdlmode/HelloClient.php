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

try {

    $my_cert = ws_get_cert_from_file("../../../keys/alice_cert.cert");
    $my_key = ws_get_key_from_file("../../../keys/alice_key.pem");
    $rec_cert = ws_get_cert_from_file("../../../keys/bob_cert.cert");
    
    $sec_token = new WSSecurityToken(array("privateKey" => $my_key,
                                           "certificate" => $my_cert,
                                           "receiverCertificate" => $rec_cert));
    
    $client = new WSClient(array ("wsdl" =>"HelloService.wsdl",
        "classmap" => $class_map,
    	"useWSA"=>TRUE,
    	"securityToken" => $sec_token));

    $proxy = $client->getProxy();

    $input = new greet();
    $input->name = "Hello";
    

    $response = $proxy->greet($input);
    echo $response->return;

} catch (Exception $e) {
    // in case of an error, process the fault
    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n", $e->getMessage());
    }
}
?>
