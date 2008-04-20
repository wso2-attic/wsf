--TEST--
ComplexType Complex Content Extension
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class inheritedType {
    public $demo3; // int
    public $demo4; // string
}

class myDemo extends inheritedType {
    public $demo1; // int
    public $demo2; // string
}

// define the class map
$class_map = array(
 "anyType" => "anyType", "inheritedType" => "inheritedType", "myDemo" => "myDemo");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/ComplexTypeComplexExtensionService.php?wsdl",
        "classmap" => $class_map,
                            ));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new myDemo();
    //TODO: fill in the class fields of $input to match your business logic
    $input->demo1 = 3;
    $input->demo2 = "Test string 2";

    $input->demo3 = 5;
    $input->demo4 = "Test string 4";
    

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
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope"><soapenv:Header></soapenv:Header><soapenv:Body><ns1:myDemo xmlns:ns1="http://wso2.org/dyn/codegen/demo"><ns1:demo3>5</ns1:demo3><ns1:demo4>Test string 4</ns1:demo4><ns1:demo1>3</ns1:demo1><ns1:demo2>Test string 2</ns1:demo2></ns1:myDemo></soapenv:Body></soapenv:Envelope>
myDemo Object
(
    [demo1] => 3
    [demo2] => Test string 2
    [demo3] => 5
    [demo4] => Test string 4
)

