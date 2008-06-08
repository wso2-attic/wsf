--TEST--
Simple Type
--FILE--
<?php

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/SimpleTypeService.php?wsdl",
                                  "to" => "http://localhost:80/services/wsdl_mode/SimpleTypeService.php",
                            ));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    //TODO: fill $input with (data type: int) data to match your business logic
    $input = 3;

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
3

