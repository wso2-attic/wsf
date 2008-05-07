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


require_once("CalendarClient.php");

$client = new CalendarClient("Amal","aaa");

//Registration
/*
$return_val = CalendarClient::register("Malki", "hhh",  "D",  "G",  "dilum@gmail.com",  "test",  "test",  "777" );
print_r($return_val);
*/

//Add a new event
//uncommnet this to add a event
/*
$obj=new Event("friends b day","2008-02-07","2008-02-07","ddd");
$returnMessage=$client->addEvent($obj);
print_r($returnMessage);
*/

//Get events
//uncommnet this to get events
/*
$returnMessage=$client->getEvents("2002-02-01T00:00:00Z","2002-09-30T00:00:00Z");
print_r($returnMessage);
*/
  
//Delete events
//uncommnet this to get events
/*
$return_val=$client->deleteEvents("2008-02-08 10:59:59","2008-02-08 11:30:00");
print_r($return_val);
*/

?>
