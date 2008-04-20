--TEST--
SimpleType Restriction
--FILE--
<?php

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost://services/wsdl_mode/SimpleTypeRestriction.wsdl",
                            ));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    //TODO: fill $input with (data type: string) data to match your business logic
    //NOTE: $input should follow the following restrictions
    /* You can have one of the following value
     * a
     * ab
     * abc
     * abcd
     */
    /* Your length of the value should be 
       Greater than 2
       Less than 3
     */
    $input = "ab";

    // call the operation
    $response = $proxy->myDemo($input);
    //TODO: Implement business logic to consume $response, which is of type int


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
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope"><soapenv:Header></soapenv:Header><soapenv:Body><ns1:myDemo xmlns:ns1="http://wso2.org/dyn/codegen/demo">ab</ns1:myDemo></soapenv:Body></soapenv:Envelope>
2

