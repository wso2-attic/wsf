--TEST--
WSDL with policies and handling multiple requests
--FILE--
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

try {

    $security_token = new WSSecurityToken(array("user" => "user",
                                                "password" => "user",
                                                "passwordType" => "Digest"));
    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/CalendarService.php?wsdl",
        "to" =>"http://localhost/services/wsdl_mode/CalendarService.php",
        "securityToken" => $security_token,
        "classmap" => $class_map));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    //$input = new register();
    //TODO: fill in the class fields of $input to match your business logic

    // call the operation
    //$response = $proxy->register($input);
    //TODO: Implement business logic to consume $response, which is of type registerResponse

    //$input = new getEvents();
    //TODO: fill in the class fields of $input to match your business logic

    // call the operation
    //$response = $proxy->getEvents($input);
    //TODO: Implement business logic to consume $response, which is of type getEventsResponse

    $input = new deleteEvents();
    //TODO: fill in the class fields of $input to match your business logic

    $input->user_name = "dimuthu";
    $input->start_date_time = "2009-07-08Z18:00:00";
    $input->end_date_time = "2009-09-08Z18:00:00";

    // call the operation
    $response = $proxy->deleteEvents($input);
    //TODO: Implement business logic to consume $response, which is of type deleteEventsResponse

    print_r($response);

    $input = new addEvent();
    //TODO: fill in the class fields of $input to match your business logic

    $input->user_name = "dimuthu 2";

    $event= new Event();
    $event->name = "another event";
    $event->start_date_time = "2008-07-08Z18:00:00";
    $event->end_date_time = "2008-09-08Z18:00:00";

    $input->event = $event;

    // call the operation
    $response = $proxy->addEvent($input);
    //TODO: Implement business logic to consume $response, which is of type addEventResponse

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
deleteEventsResponse Object
(
    [success] => deleteEvents Object
(
    [user_name] => dimuthu
    [start_date_time] => 1247076000
    [end_date_time] => 1252432800
)

)
addEventResponse Object
(
    [success] => addEvent Object
(
    [user_name] => dimuthu 2
    [event] => Event Object
        (
            [name] => another event
            [start_date_time] => 1215540000
            [end_date_time] => 1220896800
            [description] => 
        )

)

)
