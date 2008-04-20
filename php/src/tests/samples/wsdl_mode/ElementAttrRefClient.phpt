--TEST--
Element/ Attribute ref
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class myDemo {
    public $myReffered; // int
    public $myRefferedAttr; // string
}

// define the class map
$class_map = array(
 "anyType" => "anyType", "myDemo" => "myDemo");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/ElementAttrRefService.php?wsdl",
        "classmap" => $class_map,
                            ));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new myDemo();
    //TODO: fill in the class fields of $input to match your business logic
    $input->myReffered = 3;
    $input->myRefferedAttr = "test";

    // call the operation
    $response = $proxy->myDemo($input);
    //TODO: Implement business logic to consume $response, which is of type string

    echo $client->getLastRequest()."\n";
    echo $response."\n";

} catch (Exception $e) {
    // in case of an error, process the fault
    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n", $e->getMessage());
    }
}
?>
--EXPECT--
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope"><soapenv:Header></soapenv:Header><soapenv:Body><ns1:myDemo xmlns:ns1="http://wso2.org/dyn/codegen/demo" ns1:myRefferedAttr="test"><ns1:myReffered>3</ns1:myReffered></ns1:myDemo></soapenv:Body></soapenv:Envelope>
myDemo Object
(
    [myReffered] => 3
    [myRefferedAttr] => test
)

