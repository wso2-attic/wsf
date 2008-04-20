--TEST--
ComplexType ComplexContent Restriction
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class myDemo {
    public $demo1; // array of int
    public $demo2; // array of string
}

// define the class map
$class_map = array(
 "anyType" => "anyType", "myDemo" => "myDemo");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/ComplexTypeComplexRestrictionService.php?wsdl",
        "classmap" => $class_map,
                            ));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new myDemo();
    //TODO: fill in the class fields of $input to match your business logic
    $input->demo1 = array(1,2,3,4,5,6,7,8);
    $input->demo2 = array("a", "b", "c", "d", "e", "f", "g", "h", "i");

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
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope"><soapenv:Header></soapenv:Header><soapenv:Body><ns1:myDemo xmlns:ns1="http://wso2.org/dyn/codegen/demo"><ns1:demo1>1</ns1:demo1><ns1:demo1>2</ns1:demo1><ns1:demo1>3</ns1:demo1><ns1:demo1>4</ns1:demo1><ns1:demo1>5</ns1:demo1><ns1:demo1>6</ns1:demo1><ns1:demo1>7</ns1:demo1><ns1:demo1>8</ns1:demo1><ns1:demo2>a</ns1:demo2><ns1:demo2>b</ns1:demo2><ns1:demo2>c</ns1:demo2><ns1:demo2>d</ns1:demo2><ns1:demo2>e</ns1:demo2><ns1:demo2>f</ns1:demo2><ns1:demo2>g</ns1:demo2><ns1:demo2>h</ns1:demo2><ns1:demo2>i</ns1:demo2></ns1:myDemo></soapenv:Body></soapenv:Envelope>
myDemo Object
(
    [demo1] => Array
        (
            [0] => 1
            [1] => 2
            [2] => 3
            [3] => 4
            [4] => 5
            [5] => 6
            [6] => 7
            [7] => 8
        )

    [demo2] => Array
        (
            [0] => a
            [1] => b
            [2] => c
            [3] => d
            [4] => e
            [5] => f
            [6] => g
            [7] => h
            [8] => i
        )

)

