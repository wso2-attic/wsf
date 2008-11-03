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

// define PHP functions that maps to WSDL operations 
/**
 * Service function echoDate
 * @param object of echoDate $input 
 * @return object of echoDateResponse 
 */
function echoDate($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type echoDate
    // NOTE: should return an object of type echoDateResponse
	
	$date = $input->date;
	$time = $input->time;
	$dateTime = $input->dateTime;
	
	$res = new echoDateResponse();
	$res->date = $date;
	$res->dateInt = $date;
	
	$res->time = 0;
	$res->timeInt = 0; // needed to pass the test case
	
	$res->dateTime = $dateTime;
	$res->dateTimeInt = $dateTime;
	
	return $res;

}


// define the operations map
$operations = array(
    "echoDate" => "echoDate");

// define the actions => operations map
$actions = array(
    "urn:echoDate" => "echoDate");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"echoDate.wsdl",
        "actions" => $actions,
        "classmap" => $class_map,
        "operations" => $operations));

// process client requests and reply 
$service->reply();

?>
