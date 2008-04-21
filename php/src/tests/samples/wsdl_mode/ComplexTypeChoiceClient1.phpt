--TEST--
ComplexType Choice 1
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class myDemo {

    // You may set only one from the following set
    // ---------------Start Choice----------------
    public $demo1; // int
    public $demo2; // string
    // ----------------End Choice---------------

}

// define the class map
$class_map = array(
 "anyType" => "anyType", "myDemo" => "myDemo");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/ComplexTypeChoiceService.php?wsdl",
        "classmap" => $class_map,
                            ));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new myDemo();
    $input->demo1 = 3;
    //TODO: fill in the class fields of $input to match your business logic

    // call the operation
    $response = $proxy->myDemo($input);

    echo $response."\n";
    //TODO: Implement business logic to consume $response, which is of type string

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
    [demo2] => 
)

