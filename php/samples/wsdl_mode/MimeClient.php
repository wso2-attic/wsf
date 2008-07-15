<?php
/*
 * Copyright 2005,2008 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


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
    $client = new WSClient(array ("wsdl" =>"http://localhost/samples/wsdl_mode/MimeService.php?wsdl",
        "to" =>"http://localhost/samples/wsdl_mode/MimeService.php",
        "classmap" => $class_map,
        "useMTOM" => FALSE,
                            ));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new getPerson();
    $input->param0 = 3;

    // call the operation
    $response = $proxy->getPerson($input);
    echo "Received Person Object values ";
    var_dump($response);

    $input = new setPerson();

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
    echo "Received Person Object vlaues";
    var_dump($response);

} catch (Exception $e) {
    // in case of an error, process the fault
    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n", $e->getMessage());
    }
}
?>
