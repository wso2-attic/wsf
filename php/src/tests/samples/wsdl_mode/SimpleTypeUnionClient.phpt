--TEST--
Simple Type union
--FILE--
<?php

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/SimpleTypeUnionService.php?wsdl",
                            ));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    //TODO: fill $input with (data type: string/string) data to match your business logic
    //NOTE: $input should follow the following restrictions
    // type string hold the following restrictions
    /* You can have one of the following value
     * banana
     * oragne
     */
    // type string hold the following restrictions
    /* You can have one of the following value
     * ice cream
     * salad
     */
    $input = "banana";

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
banana

