<?php
/*
 * Copyright 2005,2006 WSO2, Inc. http://wso2.com
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
connect to the calender database and select the appropiate table
*/

function connect_db()
{
  $dbhost = "localhost";
  $dbname = "calender";
  $dbuname = "root";
  $dbpass = "";
  $link=mysql_connect($dbhost,  $dbuname,  $dbpass);
  mysql_select_db($dbname, $link);
}



function register($inMessage)
{

   $simplexml = new SimpleXMLElement($inMessage->str);
   $userID=trim($simplexml->userID);
   $uname=trim($simplexml->uname);
   $mypassword =trim($simplexml->password);
   $firstName=trim($simplexml->firstName);
   $lastName=trim($simplexml->lastName);
   $email =trim($simplexml->email);
   $address=trim($simplexml->address);
   $country =trim($simplexml->country);
   $code=trim($simplexml->code);


   $password=md5($mypassword);
 
   $dbhost = "localhost";
   $dbname = "calender";
   $dbuname = "root";
   $dbpass = "";
   $link=mysql_connect($dbhost,  $dbuname,  $dbpass);
   mysql_select_db($dbname, $link);

   
   $query = "INSERT INTO `customer_details` (`user_id`, `User_name`, `Password`, `First_name`, `Last_name`, `Email`, `Address`, `Country`, `Postel_code`) VALUES ('".$userID."','".$uname."', '".$password."', '".$firstName."', '".$lastName."', '".$email."', '".$address."', '".$country."', '".$code."')";
                
     $res=mysql_query($query,$link);

        if($res) 
            { 
         $resPayload = <<<XML
         <ns1:result xmlns:ns1="http://php.axis2.org/samples">
         <text>success</text>
         </ns1:result>
XML;


        $returnMessage = new WSMessage($resPayload);
        return $returnMessage;

 
            }
}


/*
login function use to log in to the calendar system. 
*/

function login($inMessage) 
{
  //read incoming soap and get the values
  $simplexml = new SimpleXMLElement($inMessage->str);
  $myuserID=trim($simplexml->param1);
  $password =trim($simplexml->param2);
  

  // username and password sent from signup form
  $mypassword=md5($password);

  $dbhost = "localhost";
  $dbname = "calender";
  $dbuname = "root";
  $dbpass = "";
  $link=mysql_connect($dbhost,  $dbuname,  $dbpass);
  mysql_select_db($dbname, $link);

  $sql="SELECT Password FROM `customer_details` WHERE `user_id` = '$myuserID'";
  $result=mysql_query($sql,$link);

     if(!$result || (mysql_numrows($result) < 1))
    {
     $resPayload = <<<XML
     <ns1:result xmlns:ns1="http://php.axis2.org/samples">
     <text>invalid password</text>
     </ns1:result>
XML;

     $returnMessage = new WSMessage($resPayload);
     return $returnMessage;
    }

// Mysql_num_row is counting table row
     $dbarray = mysql_fetch_array($result);

// If result matched $myusername and $mypassword, table row must be 1 row

     if($mypassword == $dbarray[0])
     {

      $resPayload = <<<XML
      <ns1:result xmlns:ns1="http://php.axis2.org/samples">
      <text>success</text>
      </ns1:result>
XML;

      $returnMessage = new WSMessage($resPayload);
      return $returnMessage;
      }  


}


function readTimeValues($inMessage)
{
   $simplexml = new SimpleXMLElement($inMessage->str);
   $user_id=trim($simplexml->userId);
   $week=trim($simplexml->week);
   $year=trim($simplexml->year);

   connect_db();
   $time=array();

   $query1="SELECT time FROM `create_events` WHERE `user_id`='".$user_id."' AND `week`='".$week."' AND `year`='".$year."'";
   $row1=mysql_query($query1);

   $resPayload = <<<XML
   <ns1:result xmlns:ns1="http://php.axis2.org/samples">
XML;


   while($values=mysql_fetch_array($row1, MYSQL_NUM)){
   $resPayload .= <<<XML
    <time>$values[0]</time>         
XML;
}

   $resPayload .= <<<XML
    </ns1:result>
XML;

$returnMessage = new WSMessage($resPayload);
return $returnMessage;

}


function readEventValues($inMessage)
{
   $simplexml = new SimpleXMLElement($inMessage->str);
   $user_id=trim($simplexml->userId);
   $week=trim($simplexml->week);
   $year=trim($simplexml->year);

   connect_db();

   $event=array();

   $query="SELECT event FROM `create_events` WHERE `user_id`='".$user_id."' AND `week`='".$week."' AND `year`='".$year."'";
   $row=mysql_query($query);

   $resPayload = <<<XML
   <ns1:result xmlns:ns1="http://php.axis2.org/samples">
XML;


   while($values=mysql_fetch_array($row, MYSQL_NUM)){
   $resPayload .= <<<XML
   <event>$values[0]</event>
XML;
}
   $resPayload .= <<<XML
   </ns1:result>
XML;

   $returnMessage = new WSMessage($resPayload);
   return $returnMessage;

}


function readDayValues($inMessage)
{

   $simplexml = new SimpleXMLElement($inMessage->str);
   $user_id=trim($simplexml->userId);
   $week=trim($simplexml->week);
   $year=trim($simplexml->year);

   connect_db();

   $event=array();

   $query="SELECT date FROM `create_events` WHERE `user_id`='".$user_id."' AND `week`='".$week."' AND `year`='".$year."'";
   $row=mysql_query($query);

   $resPayload = <<<XML
      <ns1:result xmlns:ns1="http://php.axis2.org/samples">
XML;


   while($values=mysql_fetch_array($row, MYSQL_NUM)){
   $resPayload .= <<<XML
   <day>$values[0]</day>
XML;
}
   $resPayload .= <<<XML
   </ns1:result>
XML;

   $returnMessage = new WSMessage($resPayload);
   return $returnMessage;

}



/*
addEvent function is to add a new event to the calender. Basically what it does is reading data
from the incoming soap message and store it in the database.If the event is stored successfully 
then service will send a success message as a respond and if it fails then send a message as 'Event
is not added'
*/

function addEvent($inMessage) 
{

  //read incoming soap and get the values
  $simplexml = new SimpleXMLElement($inMessage->str);

 // $userId =trim($simplexml->param1);
  $time = trim($simplexml->param1);
  $event =trim($simplexml->param2);
  $date=trim($simplexml->param3);
  $user_id=trim($simplexml->param4);
  $week=trim($simplexml->param5);
  $year=trim($simplexml->param6);

  connect_db();
  
  //add data to the database
  $query = "INSERT INTO `create_events` (`user_id`, `year`,`week`,`time`,`event`,`date`) VALUES ('".$user_id."','".$year."','".$week."','".$time."','".$event."','".$date."')";
  $res = mysql_query($query);

  if(!$res) { 
      $resPayload = <<<XML
      <ns1:result xmlns:ns1="http://php.axis2.org/samples">
      <text>Event is not added</text>
      </ns1:result>
XML;
    }
  else {
    $resPayload = <<<XML
      <ns1:result xmlns:ns1="http://php.axis2.org/samples">
      <text>Event is successfully added</text>
      </ns1:result>
XML;
  } 
  $returnMessage = new WSMessage($resPayload);
  return $returnMessage;
}



/*
updateEvent function is to update a event which is already stored.
*/

function updateEvent($inMessage)
{
  //read the incoming soap message and get the values
  $simplexml = new SimpleXMLElement($inMessage->str);
  $time = trim($simplexml->param1);
  $event =trim($simplexml->param2);
  $date=trim($simplexml->param3);
  $user_id=trim($simplexml->param4);
  $week=trim($simplexml->param5);
  $year=trim($simplexml->param6);

  connect_db();

  //update values
  $query="UPDATE `create_events` SET `event`='".$event."' WHERE `user_id`='".$user_id."' AND `time`='".$time."' AND `date`='".$date."' AND `week`='".$week."' AND `year`='".$year."'";
  $res=mysql_query($query);
  if($res) {
    $resPayload = <<<XML
      <ns1:result xmlns:ns1="http://php.axis2.org/samples">
      <text>Event is successfully updated</text>
      </ns1:result>
XML;
     }

  $returnMessage = new WSMessage($resPayload);
  return $returnMessage;
}



/*
deleteEvent function is to delete a already stored event.
*/

function deleteEvent($inMessage)
{
  //read the incoming soap message and get the values
   $simplexml = new SimpleXMLElement($inMessage->str);
   $time = trim($simplexml->param1);
   $date=trim($simplexml->param2);
   $user_id=trim($simplexml->param3);
   $week=trim($simplexml->param4);
   $year=trim($simplexml->param5);

   connect_db();

  //Delete event
   $query="DELETE FROM `create_events` WHERE `user_id`='".$user_id."' AND `time`='".$time."' AND `date`='".$date."' AND `week`='".$week."' AND `year`='".$year."'";
   $res=mysql_query($query);
 
   if($res) {
    $resPayload = <<<XML
      <ns1:result xmlns:ns1="http://php.axis2.org/samples">
      <text>Event is successfully removed</text>
      </ns1:result>
XML;
  }

   $returnMessage = new WSMessage($resPayload);
   return $returnMessage;
}



   $operations = array("register"=>"register",
                     "login"=> "login",
                     "add" => "addEvent",
                     "update"=>"updateEvent",
                     "delete"=>"deleteEvent",
                     "readtime"=>"readTimeValues",
                     "readevent"=>"readEventValues",
                     "readday"=>"readDayValues");

   $svr = new WSService(array("operations" => $operations));
   $svr->reply();
?>
