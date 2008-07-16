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

class CalendarClient extends WSClient
{
    const ENDPOINT = "http://localhost/samples/solutions/calendar/CalendarService.php";
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
                                                    "passwordType" => "Digest")), 
                                  "useSOAP" => 1.2,
                                  "policy" => new WSPolicy(array("security" => array("useUsernameToken" => TRUE ))),
                                  "useWSA" => true,
                                  "to" => self::ENDPOINT));

        $this->proxy = $this->getProxy();
    
        $this->username=$username;
        $this->password=$password;

    }


    public static function register($name,$password,$first, $last, $email, $address, $country, $postal_code)
    {

        
		$client = new WSClient(array("wsdl"=> "Calendar.wsdl",
                                     "useSOAP" => 1.2,
                                     "to" => "http://localhost/samples/solutions/calendar/CalendarService.php"));
 
                $proxy = $client->getProxy();

                $return_val = $proxy->register(array( "username" => $name,
                                                      "password" => $password,
                                                      "first_name" => $first,
                                                      "last_name" => $last,
                                                      "email" => $email,
                                                      "address" => $address,
                                                      "country" => $country,
                                                      "postal_code" => $postal_code,
                                                  ));
                return $return_val;
    }


    public function addEvent(Event $event)
   {
	 
       $name=$event->name;
       $start_date_time=$event->start_date_time;
       $end_date_time= $event->end_date_time;
       $description=$event->description;

       $addEventRequest=<<<XML
       <ns1:addEvent xmlns:ns1="http://php.axis2.org/samples">
       <username>$this->username</username>
       <event>
       <name>$name</name>
       <start_date_time>$start_date_time</start_date_time>
       <end_date_time>$end_date_time</end_date_time>
       <description>$description</description>
       </event>
       </ns1:addEvent>
XML;


            try {
                    $reqMessage = new WSMessage($addEventRequest,
                         array("to" => "http://localhost/samples/solutions/calendar/CalendarService.php",
                                "action"=>"urn:addEvent"));
 
                  // Send request and capture response
                    $resMessage = $this->request($reqMessage);
                    printf("Response = %s \n", $resMessage->str);          
          
                }
           
           catch (Exception $e) {

                   if ($e instanceof WSFault) {
                   printf("Soap Fault: %s\n", $e->Reason);
                   }
                   else {
                	printf("Message = %s\n",$e->getMessage());
                     	}
               }

} 

    public function deleteEvents($start_date_time,$end_date_time)
    { 
      $return_val = $this->proxy->deleteEvents(array(
             "user_name"=>$this->username,
             "start_date_time"=>$start_date_time,
             "end_date_time"=>$end_date_time,
              ));

     return $return_val;
   
    }


   public function getEvents($start_date_time,$end_date_time)
   {

     $getEventRequest=<<<XML
     <ns1:getEvents xmlns:ns1="http://php.axis2.org/samples">
     <username>$this->username</username>
     <start_date_time>$start_date_time</start_date_time>
     <end_date_time>$end_date_time</end_date_time>
     </ns1:getEvents>
XML;

   try {
           $reqMessage = new WSMessage($getEventRequest,
                         array("to" => "http://localhost/samples/solutions/calendar/CalendarService.php",
                                "action"=>"urn:getEvents"));

          // Send request and capture response
           $resMessage = $this->request($reqMessage);
           return $resMessage;
      }
   catch (Exception $e) {

           if ($e instanceof WSFault) {
           printf("Soap Fault: %s\n", $e->Reason);
           } else {
                printf("Message = %s\n",$e->getMessage());
                }
         }

  }

public function handleException($e) 
  {
        $res_array = array();
        if ($e instanceof WSFault) {
            $res_array[self::SOAP_FAULT] = TRUE;
            $res_array[self::SOAP_FAULT_REASON] = $e->Reason;;
        }
        else {
            $res_array[self::ERROR] = TRUE;
            $res_array[self::ERROR_MSG] = $e->getMessage();
        }
        return $res_array;
  }
   
}

class Event 
{
    /* @variable name event name
     * (maps to the xs:string XML schema type )
     */
    public $name;

    /* @variable date_name the starting time of the event
     * (maps to the xs:string XML schema type )
     */
    public $start_date_time;

    public $end_date_time;

    public $description;

     function __construct($name,$start_date_time,$end_date_time,$description) {
        $this->name = $name;
        $this->start_date_time = $start_date_time;
        $this->end_date_time= $end_date_time;
        $this->description=$description;
    }
}

?>
