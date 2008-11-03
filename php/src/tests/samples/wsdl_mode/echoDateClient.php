--TEST--
Data Time serialization and deserialization test
--FILE---
<?php

// PHP classes corresponding to the data types in defined in WSDL

class echoDate {

    /**
     * @var dateTime
     */
    public $dateTime;

    /**
     * @var time
     */
    public $time;

    /**
     * @var date
     */
    public $date;

}

class echoDateResponse {

    /**
     * @var dateTime
     */
    public $dateTime;

    /**
     * @var time
     */
    public $time;

    /**
     * @var date
     */
    public $date;

    /**
     * @var int
     */
    public $dateTimeInt;

    /**
     * @var int
     */
    public $timeInt;

    /**
     * @var int
     */
    public $dateInt;

}

// define the class map
$class_map = array(
    "echoDate" => "echoDate",
    "echoDateResponse" => "echoDateResponse");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/echoDateService.php?wsdl",
        "classmap" => $class_map));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new echoDate();
    //TODO: fill in the class fields of $input to match your business logic
	$input->date = $input->dateTime = $input->time = strtotime("2008-11-03 09:45:49");

    // call the operation
    $response = $proxy->echoDate($input);
    //TODO: Implement business logic to consume $response, which is of type echoDateResponse
	
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
echoDateResponse Object
(
    [dateTime] => 1225705549
    [time] => 0
    [date] => 1225670400
    [dateTimeInt] => 1225705549
    [timeInt] => 0
    [dateInt] => 1225670400
)

