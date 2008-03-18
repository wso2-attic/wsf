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
 
 function echo_function($inMessage){
    $response_value = "";
    $dom = new DOMDocument();
    $dom->loadXML($inMessage->str);
    $child_node = $dom->firstChild;
    if(!is_null($child_node)){
    	if($child_node->localName == 'echoIn'){
		$response_value = $child_node->nodeValue;
		
    	}
    }
   	if(!is_null($response_value)){
		$doc = new DOMDocument("");
		$root = $doc->createElementNS("http://example.org/echo","ns1:echoOut", $response_value);
		$doc->appendChild($root);
		$str = $doc->saveXML();
		$responseMessage = new WSMessage($str, array( "action" =>"http://example.org/action/echoOut"));  
		return $responseMessage;    		
	}
 }
 
 function notify_function($inMessage){
	return;
 }
 
 function op1_function($inMessage){
	$response_value = "";
    $dom = new DOMDocument();
    $dom->loadXML($inMessage->str);
    $child_node = $dom->firstChild;
    if(!is_null($child_node)){
    	if($child_node->localName == 'dispatchIn'){
    		$response_value = $child_node->nodeValue;
    	}
    }
   	if(!is_null($response_value)){
		$doc = new DOMDocument("");
		$root = $doc->createElementNS('http://example.org/dispatch','ns1:dispatchOut', $response_value);
		$doc->appendChild($root);
		$str = $doc->saveXML();
		$responseMessage = new WSMessage($str, array( "action" =>"http://example.org/action/Op1Reply"));  
		return $responseMessage;    		
	}
 }
 
 function op2_function($inMessage){
	$response_value = "";
    $dom = new DOMDocument();
    $dom->loadXML($inMessage->str);
    $child_node = $dom->firstChild;
    if(!is_null($child_node)){
    	if($child_node->localName == 'dispatchIn'){
    		$response_value = $child_node->nodeValue;
    	}
    }
   	if(!is_null($response_value)){
		$doc = new DOMDocument("");
		$root = $doc->createElementNS('http://example.org/dispatch','ns1:dispatchOut', $response_value);
		$doc->appendChild($root);
		$str = $doc->saveXML();
		$responseMessage = new WSMessage($str, array( "action" =>"http://example.org/action/Op2Reply"));  
		return $responseMessage;    		
	}
 }
 
 function op3_function($inMessage){
  	$response_value = "";
    $dom = new DOMDocument();
    $dom->loadXML($inMessage->str);
    $child_node = $dom->firstChild;
    if(!is_null($child_node)){
    	if($child_node->localName == 'dispatchIn'){
    		$response_value = $child_node->nodeValue;
    	}
    }
   	if(!is_null($response_value)){
		$doc = new DOMDocument("");
		$root = $doc->createElementNS('http://example.org/dispatch','ns1:dispatchOut', $response_value);
		$doc->appendChild($root);
		$str = $doc->saveXML();
		$responseMessage = new WSMessage($str, array( "action" =>"http://example.org/action/Op3Reply"));  
		return $responseMessage;    		
	}
 }
 
 function op4_function($inMessage){
 	$response_value = "";
    $dom = new DOMDocument();
    $dom->loadXML($inMessage->str);
    $child_node = $dom->firstChild;
    if(!is_null($child_node)){
    	if($child_node->localName == 'dispatchIn'){
    		$response_value = $child_node->nodeValue;
    	}
    }
   	if(!is_null($response_value)){
		$doc = new DOMDocument("");
		$root = $doc->createElementNS('http://example.org/dispatch','ns1:dispatchOut', $response_value);
		$doc->appendChild($root);
		$str = $doc->saveXML();
		$responseMessage = new WSMessage($str, array( "action" =>"http://example.org/action/Op4Reply"));  
		return $responseMessage;    		
	}
 }
 
 $operations = array("Echo"=>"echo_function",
 					 "Notify"=>"notify_function",
 					 "Op1"=>"op1_function",
 					 "Op2"=>"op2_function",
 					 "Op3"=>"op3_function",
 					 "Op4"=>"op4_function");
 
 $actions = array("http://example.org/action/echoIn"=>"Echo",
 				  "http://example.org/action/notify"=>"Notify",
				  "http://example.org/action/Op1"=>"Op1",
 				  "http://example.org/action/Op2"=>"Op2",
 				  "http://example.org/action/Op3"=>"Op3",
 				  "http://example.org/action/Op4"=>"Op4");

$service_options = array();
$service_options["operations"] = $operations;
$service_options["actions"] = $actions;
$service_options["serviceName"] ="WSAddressingCR";
//$service_options["wsdl"]="http://131.107.72.15/WSAddressingCR_Service_WCF/WSAddressing10.svc?wsdl=wsdl1";		  
 				  
$service = new WSService($service_options); 	
$service->reply();			  
?>
