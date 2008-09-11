<?php

// PHP classes corresponding to the data types in defined in WSDL

class getPerson {

    /**
     * @var int
     */
    public $param0;

}

class getPersonResponse {

    /**
     * @var (object)Person
     */
    public $return;

}

class Person {

    /**
     * @var int
     */
    public $age;

    /**
     * @var array[0, unbounded] of (object)base64Binary
     */
    public $images;

    /**
     * @var array[0, unbounded] of int
     */
    public $someInts;

    /**
     * @var string
     */
    public $name;

    /**
     * @var array[0, unbounded] of string
     */
    public $someStrings;

}

class base64Binary {

    /**
     * @var string
     *     NOTE: contentType should follow the following restrictions
     *     Your length of the value should be 
     *     Greater than 3
     */
    public $contentType;

    // The "value" represents the element 'images' value..

    // You need to set only one from the following two vars

    /**
     * @var Plain Binary
     */
    public $value;

    /**
     * @var base64Binary
     */
    public $value_encoded;


}

class setPerson {

    /**
     * @var (object)Person
     */
    public $param0;

}

class setPersonResponse {

    /**
     * @var int
     */
    public $return;

}

// define the class map
$class_map = array(
    "getPerson" => "getPerson",
    "getPersonResponse" => "getPersonResponse",
    "Person" => "Person",
    "base64Binary" => "base64Binary",
    "setPerson" => "setPerson",
    "setPersonResponse" => "setPersonResponse");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"Mtom.wsdl",
        "to" => "http://localhost/samples/wsdl_mode/MtomService.php",
        "classmap" => $class_map));

    // get proxy object reference form client 
    $proxy = $client->getProxy();


    // get proxy object reference form client 
    $proxy = $client->getProxy();

    echo "<h2>Invoking the getPerson operation\n</h2>";

    // create input object and set values
    $input = new getPerson();


    // create input object and set values
    $input = new getPerson();
    //TODO: fill in the class fields of $input to match your business logic
    $input->param0 = 3;

    // call the operation
    $response = $proxy->getPerson($input);
    //TODO: Implement business logic to consume $response, which is of type getPersonResponse


    $ppl = $response->return;
    $age = $ppl->age;
    $images = $ppl->images;
    $bin1 = $images[0]->value;
    $bin2 = $images[1]->value;

    echo "Person information retrieved\n<br/>";

    echo "person age is: $age\n<br/>";
    
    $image1name = "my_axis2_from_client.jpg";
    $image2name = "xml_from_client.xml";
    if(stristr(PHP_OS, 'WIN')) {
        file_put_contents($image1name, $bin1);
        file_put_contents($image2name, $bin2);
    }else{
        file_put_contents("/tmp/".$image1name, $bin1);
        file_put_contents("/tmp/".$image2name, $bin2);
    }

    echo "Image is saved\n"; 

    echo "<h2>Invoking the setPerson operation\n</h2>";

    $input = new setPerson();
    //TODO: fill in the class fields of $input to match your business logic

    $ppl = new Person();
    $ppl->age = 3;
    $bin1 = new base64Binary();
    $bin1->contentType = "image/jpeg";
    $bin1->value = file_get_contents("../resources/axis2.jpg");

    $bin2 = new base64Binary();
    $bin2->contentType = "text/xml";
    $bin2->value = "<test>xml</test>";
    $ppl->images = array($bin1, $bin2);
    $ppl->someInts = array(5, 6);
    $ppl->name = "test";
    $ppl->someStrings = array("test1", "test2");

    $input->param0 = $ppl;

    // call the operation
    $response = $proxy->setPerson($input);
    //TODO: Implement business logic to consume $response, which is of type setPersonResponse

    echo "setPerson called\n";

} catch (Exception $e) {
    // in case of an error, process the fault
    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n", $e->getMessage());
    }
}
?>
