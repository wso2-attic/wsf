--TEST--
SimpleType List
--FILE--
<?php

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/SimpleTypeListService.php?wsdl",
                            "to" => "http://localhost:80/services/wsdl_mode/SimpleTypeListService.php",
                            ));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    //TODO: fill $input with (data type: array of int) data to match your business logic

    $input = array(3, 5, 8, 11);

    // call the operation
    $response = $proxy->myDemo($input);
    //TODO: Implement business logic to consume $response, which is of type int

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
27

