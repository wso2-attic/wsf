<?php

// PHP classes corresponding to the data types in defined in WSDL

class register {

    /**
     * @var string
     */
    public $username;

    /**
     * @var string
     */
    public $password;

    /**
     * @var string
     */
    public $first_name;

    /**
     * @var string
     */
    public $last_name;

    /**
     * @var string
     */
    public $email;

    /**
     * @var string
     */
    public $address;

    /**
     * @var string
     */
    public $country;

    /**
     * @var string
     */
    public $postal_code;

}

class registerResponse {

    /**
     * @var string
     */
    public $success;

}

class getEvents {

    /**
     * @var string
     */
    public $user_name;

    /**
     * @var dateTime
     */
    public $start_date_time;

    /**
     * @var dateTime
     */
    public $end_date_time;

}

class getEventsResponse {

    /**
     * @var array[0, unbounded] of (object)Event
     */
    public $return;

}

class Event {

    /**
     * @var string
     */
    public $name;

    /**
     * @var dateTime
     */
    public $start_date_time;

    /**
     * @var dateTime
     */
    public $end_date_time;

    /**
     * @var string
     */
    public $description;

}

class deleteEvents {

    /**
     * @var string
     */
    public $user_name;

    /**
     * @var dateTime
     */
    public $start_date_time;

    /**
     * @var dateTime
     */
    public $end_date_time;

}

class deleteEventsResponse {

    /**
     * @var string
     */
    public $success;

}

class addEvent {

    /**
     * @var string
     */
    public $user_name;

    /**
     * @var (object)Event
     */
    public $event;

}

class addEventResponse {

    /**
     * @var string
     */
    public $success;

}

// define the class map
$class_map = array(
    "register" => "register",
    "registerResponse" => "registerResponse",
    "getEvents" => "getEvents",
    "getEventsResponse" => "getEventsResponse",
    "Event" => "Event",
    "deleteEvents" => "deleteEvents",
    "deleteEventsResponse" => "deleteEventsResponse",
    "addEvent" => "addEvent",
    "addEventResponse" => "addEventResponse");

// define PHP functions that maps to WSDL operations 
/**
 * Service function register
 * @param object of register $input 
 * @return object of registerResponse 
 */
function register($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type register
    // NOTE: should return an object of type registerResponse
    

}


/**
 * Service function getEvents
 * @param object of getEvents $input 
 * @return object of getEventsResponse 
 */
function getEvents($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type getEvents
    // NOTE: should return an object of type getEventsResponse

}


/**
 * Service function deleteEvents
 * @param object of deleteEvents $input 
 * @return object of deleteEventsResponse 
 */
function deleteEvents($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type deleteEvents
    // NOTE: should return an object of type deleteEventsResponse

    return array("success" => print_r($input, TRUE));
}


/**
 * Service function addEvent
 * @param object of addEvent $input 
 * @return object of addEventResponse 
 */
function addEvent($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type addEvent
    // NOTE: should return an object of type addEventResponse

    return array("success" => print_r($input, TRUE));
}

function get_password($user) {
    return $user;
}

// define the operations map
$operations = array(
    "register" => "register",
    "getEvents" => "getEvents",
    "deleteEvents" => "deleteEvents",
    "addEvent" => "addEvent");

// define the actions => operations map
$actions = array(
    "urn:register" => "register",
    "urn:getEvents" => "getEvents",
    "urn:deleteEvents" => "deleteEvents",
    "urn:addEvent" => "addEvent");

$security_token = new WSSecurityToken(array("passwordCallback" => "get_password",
                                      "passwordType" => "Digest"));

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"Calendar.wsdl",
        "actions" => $actions,
        "classmap" => $class_map,
        "securityToken" => $security_token,
        "operations" => $operations));

// process client requests and reply 
$service->reply();

?>
