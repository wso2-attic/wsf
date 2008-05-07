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

/*
call back function.
verify the validity of user enterd password with
the actual password which is kept in the database.
*/

  function get_password($username) 
 {
      global $session;
      $session['name']=$username;
      $mypassword=md5($password);

      $dbhost = "localhost";
      $dbname = "Calendar";
      $dbuname = "root";
      $dbpass = "";
      $link=mysql_connect($dbhost,  $dbuname,  $dbpass);
      mysql_select_db($dbname, $link);

      $sql="SELECT password FROM `customer_details` WHERE `user_name` = '".$username."'";
      $result=mysql_query($sql,$link);
      $password=mysql_fetch_array($result, MYSQL_NUM);

       if($password){
	             
                 return $password[0];
                }
      else {
           return NULL;
           }
 }


/*
Register the user with system.
Enter the user ibformation and the information store in the 
database called 'customer_details'.
*/


function register($username,$password,$first_name,$last_name,$email,$address,$country,$postal_code)
 {

      $dbhost = "localhost";
      $dbname = "Calendar";
      $dbuname = "root";
      $dbpass = "";
      $link=mysql_connect($dbhost,  $dbuname,  $dbpass);
      mysql_select_db($dbname, $link);

      $sql="SELECT `password` FROM `customer_details` WHERE `user_name` = '$username'";
      $result=mysql_query($sql,$link);
      $name=mysql_fetch_array($result, MYSQL_NUM);
     
      if(empty($name))
	 {
 
          $query = "INSERT INTO `customer_details`(`user_name`,`password`,`first_name`, `last_name`, `email`, `address`, `country`, `postel_code`) VALUES ('".$username."', '".$password."', '".$first_name."', '".$last_name."', '".$email."', '".$address."', '".$country."', '".$postal_code."')";

          $res=mysql_query($query,$link);
     
             if($res)  {
                       return array("success" => "registration is successfully finished");
                       }
             else  {
                    return array("success" => "not added");
                   }
      }

      else {
           return array("success" => "User name is already exist...");
           }

 }


/*
The newly created event is added to the database.
If there is any event for the similer time , the old
one will be updated with new event.

*/
function addEvent($inMessage)
 {

      $dbhost = "localhost";
      $dbname = "Calendar";
      $dbuname = "root";
      $dbpass = "";
      $link=mysql_connect($dbhost,  $dbuname,  $dbpass);
      mysql_select_db($dbname, $link);

      $simplexml = new SimpleXMLElement($inMessage->str);
      $username=trim($simplexml->username);
      $name=trim($simplexml->event->name);
      $start_date_time=trim($simplexml->event->start_date_time);
      $end_date_time=trim($simplexml->event->end_date_time);
      $description=trim($simplexml->event->description);
        
    
      $sql="SELECT user_id FROM `customer_details` WHERE `user_name` = '".$username."'";
      $result1=mysql_query($sql,$link);
      $userid=mysql_fetch_array($result1, MYSQL_NUM);
      $user_id=$userid[0];
   
      file_put_contents("/tmp/user.txt",$userid);

      $query2="SELECT name FROM `events` WHERE `user_id`='".$user_id."' AND `start_time`='".$start_date_time."' AND `end_time`='".$end_date_time."'";
      $events=mysql_query($query2,$link);
      $event=mysql_fetch_array($events, MYSQL_NUM);
      file_put_contents("/tmp/event.txt",$event);

   
         if(empty($event))
           {
                $query = "INSERT INTO `events` (`start_time`,`end_time`,`name`, `description`, `user_id`) VALUES ('".$start_date_time."', '".$end_date_time."', '".$name."', '".$description."', '".$user_id."');";
		$res=mysql_query($query,$link);
        	file_put_contents("/tmp/payload.txt", $query);                 
                     if($res){ 
                     $resPayload = <<<XML
                     <ns1:result xmlns:ns1="http://php.axis2.org/samples">
                     <text>new event is added.....</text>
                     </ns1:result>
XML;
                     }          
          }


         else
	    {
                $query= "UPDATE `events` SET `name`= '".$name."', `description`='".$description."' WHERE `user_id`= '".$user_id."' AND `start_time`= '".$start_date_time."' AND `end_time`= '".$end_date_time."'";
                $res=mysql_query($query,$link);
              
               file_put_contents("/tmp/my.txt",$event);
                if($res){
                     $resPayload = <<<XML
                     <ns1:result xmlns:ns1="http://php.axis2.org/samples">
                     <text>event is updated.....</text>
                     </ns1:result>
XML;
              
                   }
            }
 
        $returnMessage = new WSMessage($resPayload);
        return $returnMessage;
 
  
}


/*
Delete events from the database.

*/
  function deleteEvents($user_name,$start_date_time,$end_date_time){

      $dbhost = "localhost";
      $dbname = "Calendar";
      $dbuname = "root";
      $dbpass = "";
      $link=mysql_connect($dbhost,$dbuname,$dbpass);
      mysql_select_db($dbname,$link);
      
      $sql="SELECT user_id FROM `customer_details` WHERE `user_name` = '".$user_name."'";
      $result1=mysql_query($sql,$link);
      $userId=mysql_fetch_array($result1, MYSQL_NUM);
      $user_id=$userId[0];
      file_put_contents("/tmp/name2.txt",$userId);


      $query="DELETE FROM `events` WHERE `user_id`='".$user_id."' AND `start_time`='".$start_date_time."' AND `end_time`='".$end_date_time."'";
      $res=mysql_query($query,$link);
      if($res){
                 return array("success" => "event is removed");
                }
      
     else{
          return array("success" => "not removed...");
        }

 }



/*
Get the events for a specific time duration.
*/


function getEvents($inMessage){

      $dbhost = "localhost";
      $dbname = "Calendar";
      $dbuname = "root";
      $dbpass = "";
      $link=mysql_connect($dbhost,  $dbuname,  $dbpass);
      mysql_select_db($dbname, $link);

      $simplexml = new SimpleXMLElement($inMessage->str);
      $username=trim($simplexml->username);
      $start_date_time=trim($simplexml->start_date_time);
      $end_date_time=trim($simplexml->end_date_time);

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
    

      $sql2="SELECT * FROM `events` WHERE `user_id`='".$user_id."' AND `start_time` > '".$start_date."' AND `end_time` < '".$end_date."'";
      $result2=mysql_query($sql2,$link);

      $resPayload = <<<XML
      <ns1:result xmlns:ns1="http://php.axis2.org/samples">
XML;
 
      while($event=mysql_fetch_array($result2, MYSQL_NUM)){
      $resPayload .= <<<XML
      <event>
      <start_date_time>$event[0]</start_date_time>
      <end_date_time>$event[1]</end_date_time>
      <name>$event[2]</name>
      <description>$event[3]</description>
      </event>
XML;
}

      $resPayload .= <<<XML
      </ns1:result>
XML;

      $returnMessage = new WSMessage($resPayload);
      return $returnMessage;

}




$security_token = new WSSecurityToken(array("passwordCallback" => "get_password",
                                      "passwordType" => "Digest"));

$operations = array("register" => "register",
                    "addEvent"=> "addEvent",
                    "deleteEvents"=>"deleteEvents",
                    "getEvents"=>"getEvents");

$opParams = array("register"=> "MIXED",
                   "addEvent" => "WSMESSAGE",
                   "deleteEvents"=>"MIXED",
                     "getEvents"=>"WSMESSAGE");

$actions = array("urn:register" => "register",
                 "urn:addEvent" => "addEvent",
                 "urn:deleteEvents"=>"deleteEvents",
                 "urn:getEvents"=>"getEvents");

$svr = new WSService(array("wsdl"=>"Calendar.wsdl",
                           "operations" => $operations,
                           "opParams" => $opParams, 
                           "actions" => $actions,
                           "securityToken" => $security_token));

$svr->reply();
?>
