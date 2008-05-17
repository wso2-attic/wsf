--TEST--
Mtom client - default (useMTOM = TRUE)
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class getPerson {
    public $param0; // int
}

class getPersonResponse {
    public $return; // Person
}

class Person {
    public $age; // int
    public $images; // array[0, unbounded] of base64Binary
    public $someInts; // array[0, unbounded] of int
    public $name; // string
    public $someStrings; // array[0, unbounded] of string
}

class base64Binary {
    //NOTE:  should follow the following restrictions
    /* Your length of the value should be 
       Greater than 3
     */
    public $contentType; // string
    // The "value" represents the element 'images' value..
    public $value; // base64Binary
}

class setPerson {
    public $param0; // Person
}

class setPersonResponse {
    public $return; // int
}

// define the class map
$class_map = array(
 "anyType" => "anyType", "getPerson" => "getPerson", "getPersonResponse" => "getPersonResponse", "Person" => "Person", "base64Binary" => "base64Binary", "setPerson" => "setPerson", "setPersonResponse" => "setPersonResponse");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/MtomService.php?wsdl",
        "to" =>"http://localhost:80/services/wsdl_mode/MtomService.php",
        "classmap" => $class_map,
                            ));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new getPerson();
    //TODO: fill in the class fields of $input to match your business logic
    $input->param0 = 3;

    // call the operation
    $response = $proxy->getPerson($input);
    //TODO: Implement business logic to consume $response, which is of type getPersonResponse
    print_r($response);

    $input = new setPerson();
    //TODO: fill in the class fields of $input to match your business logic

    $ppl = new Person();
    $ppl->age = 3;
    $bin1 = new base64Binary();
    $bin1->contentType = "image/jpeg";
    $bin1->value = "xxxxx";

    $bin2 = new base64Binary();
    $bin2->contentType = "image/jpeg";
    $bin2->value = "yyyy";
    $ppl->images = array($bin1, $bin2);
    $ppl->someInts = array(5, 6);
    $ppl->name = "test";
    $ppl->someStrings = array("test1", "test2");

    $input->param0 = $ppl;

    // call the operation
    $response = $proxy->setPerson($input);
    //TODO: Implement business logic to consume $response, which is of type setPersonResponse
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
getPersonResponse Object
(
    [return] => Person Object
        (
            [age] => 3
            [images] => Array
                (
                    [0] => base64Binary Object
                        (
                            [contentType] => image/jpeg
                            [value] => xxxxx
                            [value_encoded] => eHh4eHg=
                        )

                    [1] => base64Binary Object
                        (
                            [contentType] => image/jpeg
                            [value] => yyyy
                            [value_encoded] => eXl5eQ==
                        )

                )

            [someInts] => Array
                (
                    [0] => 5
                    [1] => 6
                )

            [name] => test
            [someStrings] => Array
                (
                    [0] => test1
                    [1] => test2
                )

        )

)
setPersonResponse Object
(
    [return] => 5
)
