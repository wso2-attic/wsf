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


class Bar
{
    private $value = "";

    function Bar($str){
        $this->value = $str;
    }

    function echoValue($inMessage){

$responsePayloadString = <<<XML
<ns1:echoString xmlns:ns1="http://wso2.org/projects/wsf/php">
     <value>$this->value</value></ns1:echoString>
XML;
        return new WSMessage($responsePayloadString);
    }
}


$operations = array("echoString" => "echoValue");

$service = new WSService(array( "classes" => array("Bar" => array("operations" => $operations,
                                                              "args" => array("Hello") ))));
        
$service->reply();

?>
