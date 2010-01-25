<?php

require_once("constants.php");
define("DB_HOST", "localhost");
define("DB_NAME", "Calendar");

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

/**
 * call back function.
 * verify the validity of user enterd password with
 * the actual password which is kept in the database.
 */
$current_username = "";
function get_password($username)
{

    $dbhost = DB_HOST;
    $dbname = DB_NAME;
    $dbuname = DB_USERNAME;
    $dbpass = DB_PASSWORD;
    $link=mysql_connect($dbhost,  $dbuname,  $dbpass);
    mysql_select_db($dbname, $link);

    $sql="SELECT password FROM `customer_details` WHERE `user_name` = '".$username."'";
    $result=mysql_query($sql,$link);
    $password=mysql_fetch_array($result, MYSQL_NUM);

    global $current_username;
    if($password) {
         $current_username = $username;
         return $password[0];
    }
    else {
         $current_username = "";
         return NULL;
    }
}


// define PHP functions that maps to WSDL operations 
/**
 * Service function login
 * @param object of login $input 
 * @return object of loginResponse 
 */
function login($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type login
    // NOTE: should return an object of type loginResponse

    global $current_username;
    $res = new loginResponse();
    if(!empty($current_username)) {
        $res->success = "SUCCESS";
    }
    else {
        $res->success = "FAILS";
    }
    return $res;
}


/**
 * Service function register
 * @param object of register $input 
 * @return object of registerResponse 
 */
function register($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type register
    // NOTE: should return an object of type registerResponse
    $dbhost = DB_HOST;
    $dbname = DB_NAME;
    $dbuname = DB_USERNAME;
    $dbpass = DB_PASSWORD;

    $link=mysql_connect($dbhost,  $dbuname,  $dbpass);
    mysql_select_db($dbname, $link);

    $username = $input->username;
    $password = $input->password;
    $first_name = $input->firstName;
    $last_name = $input->lastName;
    $email = $input->email;
    $address = $input->address;
    $country = $input->country;
    $postal_code = $input->postalCode;
    

    $sql="SELECT `password` FROM `customer_details` WHERE `user_name` = '$username'";
    $result=mysql_query($sql,$link);
    $name=mysql_fetch_array($result, MYSQL_NUM);

    $res = new registerResponse();

    if(empty($name))
    {
        $query = "INSERT INTO `customer_details`(`user_name`,`password`,`first_name`,".
				" `last_name`, `email`, `address`, `country`, `postel_code`) VALUES ('".
                      $username."', '".$password."', '".$firstName."', '".$lastName.
					"', '".$email."', '".$address."', '".$country."', '".$postalCode."')";

        $resutl=mysql_query($query,$link);

        if($result)  {
            $res->success = "SUCCESS";
        }
        else  {
            $res->success = "FAILS";
        }
    }

    else {
         $res->success = "USERNAME_ALREADY_EXISTS";
    }

    return $res;
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
    $dbhost = DB_HOST;
    $dbname = DB_NAME;
    $dbuname = DB_USERNAME;
    $dbpass = DB_PASSWORD;
    $link=mysql_connect($dbhost,  $dbuname,  $dbpass);
    mysql_select_db($dbname, $link);
    
    global $current_username;
    $username = $current_username;
    $start_date_time = $input->startDateTime;
    $end_date_time = $input->endDateTime;

    function convert($datetime)
    {
        $date=substr($datetime,0,10);
        return $date;
    }

    $sql="SELECT user_id FROM `customer_details` WHERE `user_name` = '".$username."'";
    $result1=mysql_query($sql,$link);
    $userid=mysql_fetch_array($result1, MYSQL_NUM);
    $user_id=$userid[0];

    $start_date=convert($start_date_time);
    $end_date=convert($end_date_time);


    $sql2="SELECT * FROM `events` WHERE `user_id`='".$user_id."' AND `start_time` > '".
			$start_date."' AND `end_time` < '".$end_date."'";
    $result2=mysql_query($sql2,$link);

    $res = new getEventsResponse();

    $events = array();

    while($db_event=mysql_fetch_array($result2, MYSQL_NUM)){
        $event = new Event();
        
        $event->startDateTime = str_replace(" ", "T", $db_event[0]);
        $event->endDateTime = str_replace(" ", "T", $db_event[1]);
        $event->name = $db_event[2];
        $event->description = $db_event[3];
        
        $events[] = $event;    
    }
    
    $res->return = $events;
    return $res;
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
    $dbhost = DB_HOST;
    $dbname = DB_NAME;
    $dbuname = DB_USERNAME;
    $dbpass = DB_PASSWORD;
    $link=mysql_connect($dbhost,$dbuname,$dbpass);
    mysql_select_db($dbname,$link);

    global $current_username;
    $user_name = $current_username;
    $start_date_time = $input->startDateTime;
    $end_date_time = $input->endDateTime;
    
    $sql="SELECT user_id FROM `customer_details` WHERE `user_name` = '".$user_name."'";
    $result1=mysql_query($sql,$link);
    $userId=mysql_fetch_array($result1, MYSQL_NUM);
    $user_id=$userId[0];
    
    
    $query="DELETE FROM `events` WHERE `user_id`='".$user_id."' AND `start_time`='".
			$start_date_time."' AND `end_time`='".$end_date_time."'";
    $result = mysql_query($query,$link);

    $res = new deleteEventsResponse();
    if($result)
    {
        $res->success = "SUCCESS";
    }
    else{
        $res->success = "FAILS";
    }

    return $res; 
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
    $dbhost = DB_HOST;
    $dbname = DB_NAME;
    $dbuname = DB_USERNAME;
    $dbpass = DB_PASSWORD;
    $link=mysql_connect($dbhost,  $dbuname,  $dbpass);
    mysql_select_db($dbname, $link);

    global $current_username;
    
    $username=$current_username;
    $event = $input->event;
    $name = $event->name;
    $start_date_time = $event->startDateTime;
    $end_date_time = $event->endDateTime;
    $description = $event->description;


    $sql="SELECT user_id FROM `customer_details` WHERE `user_name` = '".$username."'";
    $result1=mysql_query($sql,$link);
    $userid=mysql_fetch_array($result1, MYSQL_NUM);
    $user_id=$userid[0];
  
    $query2="SELECT name FROM `events` WHERE `user_id`='".$user_id."' AND `start_time`='".
			$start_date_time."' AND `end_time`='".$end_date_time."'";
    $events=mysql_query($query2,$link);
    $event=mysql_fetch_array($events, MYSQL_NUM);
 
    $res = new addEventResponse(); 
    $res->success = "FAILS";
    if(empty($event))
    {
        $query = "INSERT INTO `events` (`start_time`,`end_time`,`name`, `description`, `user_id`) VALUES ('".
                $start_date_time."', '".$end_date_time."', '".$name."', '".$description."', '".$user_id."');";
        $db_ret=mysql_query($query,$link);
        if($db_ret){
            $res->success = "SUCCESS";
        }
    }
    else
    {
        $query= "UPDATE `events` SET `name`= '".$name."', `description`='".$description."' WHERE `user_id`= '".
					$user_id."' AND `start_time`= '".$start_date_time."' AND `end_time`= '".$end_date_time."'";
        $db_ret =mysql_query($query,$link);

        if($db_ret){
            $res->success = "SUCCESS";
        }
    }

    return $res;
}


// define the operations map
$operations = array(
    "login" => "login",
    "register" => "register",
    "getEvents" => "getEvents",
    "deleteEvents" => "deleteEvents",
    "addEvent" => "addEvent");

// define the actions => operations map
$actions = array(
    "urn:login" => "login",
    "urn:register" => "register",
    "urn:getEvents" => "getEvents",
    "urn:deleteEvents" => "deleteEvents",
    "urn:addEvent" => "addEvent");

// Security options
$security_options = array("useUsernameToken" => TRUE);
$policy = new WSPolicy(array("security"=>$security_options));

// our security token
$security_token = new WSSecurityToken(array("passwordCallback" => "get_password",
                                      "passwordType" => "plain"));
// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"Calendar.wsdl",
        "actions" => $actions,
        "classmap" => $class_map,
        "securityToken" => $security_token,
		"policy" => $policy,
        "operations" => $operations));

// process client requests and reply 
$service->reply();

?>
