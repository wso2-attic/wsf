<?php

// PHP classes corresponding to the data types in defined in WSDL

class login {

}

class loginResponse {

    /**
     * @var string
     *     NOTE: success should follow the following restrictions
     *     You can have one of the following value
     *     SUCCESS
     *     FAILS
     */
    public $success;

}

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
    public $firstName;

    /**
     * @var string
     */
    public $lastName;

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
    public $postalCode;

}

class registerResponse {

    /**
     * @var string
     *     NOTE: success should follow the following restrictions
     *     You can have one of the following value
     *     SUCCESS
     *     FAILS
     *     USERNAME_ALREADY_EXISTS
     *     INVALID
     */
    public $success;

}

class getEvents {

    /**
     * @var dateTime
     */
    public $startDateTime;

    /**
     * @var dateTime
     */
    public $endDateTime;

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
    public $startDateTime;

    /**
     * @var dateTime
     */
    public $endDateTime;

    /**
     * @var string
     */
    public $description;

}

class deleteEvents {
    /**
     * @var dateTime
     */
    public $startDateTime;

    /**
     * @var dateTime
     */
    public $endDateTime;

}

class deleteEventsResponse {

    /**
     * @var string
     *     NOTE: success should follow the following restrictions
     *     You can have one of the following value
     *     SUCCESS
     *     FAILS
     */
    public $success;

}

class addEvent {

    /**
     * @var (object)Event
     */
    public $event;

}

class addEventResponse {

    /**
     * @var string
     *     NOTE: success should follow the following restrictions
     *     You can have one of the following value
     *     SUCCESS
     *     FAILS
     */
    public $success;

}

class CalendarClient extends WSClient
{
    const ENDPOINT = "http://localhost:8080/solutions/Calendar/CalendarService.php";
    const ADDEVENT_METHOD = "addEvent";
    const DELETE_METHOD = "deleteEvents";
    const SOAP_FAULT = "soap-fault";
    const SOAP_FAULT_REASON = "soap-fault-reason";
    const ERROR = "error";
    const ERROR_MSG = "error-msg";

    private $proxy;
    private $username;
    private $password;
  
    public function __construct($username,$password)
    {
        
   	    parent::__construct(array("wsdl"=> "Calendar.wsdl",
				                  "securityToken" => new WSSecurityToken(array("user" => $username,
                                                    "password" => $password,
                                                    "passwordType" => "plain")), 
                                  "classmap" => $this->getClassmap(),
                                  "to" => self::ENDPOINT));

        $this->proxy = $this->getProxy();

    
        $this->username=$username;
        $this->password=$password;

    }

    public function login()
    {
        return $this->proxy->login();
    }


    public static function register($name,$password,$first, $last, $email, $address, $country, $postal_code)
    {

        // we need to create a static function for the register, since it doesn't need any signed in
		$client = new WSClient(array("wsdl"=> "Calendar.wsdl",
                                     "classmap" => CalendarClient::getClassmap(),
                                     "to" => self::ENDPOINT));
 
        $proxy = $client->getProxy();

         
        $return_val = $proxy->register(array( "username" => $name,
                                                      "password" => $password,
                                                      "firstName" => $first,
                                                      "lastName" => $last,
                                                      "email" => $email,
                                                      "address" => $address,
                                                      "country" => $country,
                                                      "postalCode" => $postal_code,
                                                  ));
        return $return_val;
    }


    public function addEvent(Event $event)
    {
	 
        $add_event = new addEvent();
        $add_event->event = $event;

        
        $add_event_res = $this->proxy->addEvent($add_event);
        return $add_event_res;
    } 

    public function deleteEvents($start_date_time, $end_date_time)
    {
        $delete_events = new deleteEvents();
        $delete_events->startDateTime = $start_date_time;
        $delete_events->endDateTime = $end_date_time;
        
        $return_val = $this->proxy->deleteEvents($delete_events);

        return $return_val;
       
    }


    public function getEvents($start_date_time,$end_date_time)
    {
    
        $get_events = new getEvents();
        $get_events->startDateTime = $start_date_time;
        $get_events->endDateTime = $end_date_time;
    
        $return_val = $this->proxy->getEvents($get_events);
        return $return_val;
    }

    public static function getClassmap() {

        // define the class map
        $class_map = array(
            "login" => "login",
            "loginResponse" => "loginResponse",
            "register" => "register",
            "registerResponse" => "registerResponse",
            "getEvents" => "getEvents",
            "getEventsResponse" => "getEventsResponse",
            "Event" => "Event",
            "deleteEvents" => "deleteEvents",
            "deleteEventsResponse" => "deleteEventsResponse",
            "addEvent" => "addEvent",
            "addEventResponse" => "addEventResponse");
        return $class_map;
    }


    public function handleException($e) 
    {
        
        if ($e instanceof WSFault) {
            return $e->Reason;;
        }
        else {
            return $e->getMessage();
        }
    }
}
?>
