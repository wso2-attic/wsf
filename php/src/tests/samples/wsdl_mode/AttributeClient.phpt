--TEST--
Attribute
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class myDemo {
    public $demo1; // string
    public $demo2; // string
    //NOTE:  should follow the following restrictions
    /* Your value should be 
       Greater than or equal to 2
       Less than or equal to 5
     */
    public $demo3; // int
}

// define the class map
$class_map = array(
 "anyType" => "anyType", "myDemo" => "myDemo");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/AttributeService.php?wsdl",
        "to" => "http://localhost/services/wsdl_mode/AttributeService.php",
        "classmap" => $class_map,
                            ));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new myDemo();
    //TODO: fill in the class fields of $input to match your business logic
    $input->demo1 = "test";
    $input->demo2 = "test";
    $input->demo3 = 5;

    // call the operation
    $response = $proxy->myDemo($input);
    //TODO: Implement business logic to consume $response, which is of type string
    
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
myDemo Object
(
    [demo1] => test
    [demo2] => test
    [demo3] => 5
)

