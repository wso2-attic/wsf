--TEST--
WSDL Generation - client with empt parameters
--FILE--
<?php
class Student {

    public $id; // string

}



// define the class map
$class_map = array("Student" => "Student");



$client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_generation/empty_param_service.php?wsdl",
            "classmap" => $class_map));


$proxy = $client->getProxy();
$response = $proxy->getStudents();

print_r($response);
?>
--EXPECT--
WSFUnknownSchemaConstruct Object
(
    [properties] => Array
        (
            [a] => Array
                (
                    [0] => Student Object
                        (
                            [id] => 0
                        )

                    [1] => Student Object
                        (
                            [id] => 1
                        )

                    [2] => Student Object
                        (
                            [id] => 2
                        )

                )

        )

)

