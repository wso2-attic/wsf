--TEST--
Class Map Test
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class myDemo {

    /**
     * @var int
     */
    public $demo1;

    /**
     * @var string
     */
    public $demo2;

}

class myDemoResponse2 {

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
    "myDemo" => "myDemo",
    "myDemoResponse" => "myDemo"); //we are mapping myDemo

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/ClassmapTestService.php?wsdl",
        "classmap" => $class_map));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new myDemo();
    //TODO: fill in the class fields of $input to match your business logic
    $input->demo1 = 3;
    $input->demo2 = "test";

    // call the operation
    $response = $proxy->myDemo($input);
    //TODO: Implement business logic to consume $response, which is of type myDemoResponse

    print_r($response);

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
myDemo Object
(
    [demo1] => 3
    [demo2] => test
)

