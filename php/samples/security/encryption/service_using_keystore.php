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

function echoFunction($inMessage) {

    $returnMessage = new WSMessage($inMessage->str);

    return $returnMessage;
}

$keystore = file_get_contents("../keys/bob_kstore.p12");

$operations = array("echoString" => "echoFunction");
$sec_array = array("encrypt" => TRUE,
                   "algorithmSuite" => "Basic256Rsa15",
                   "securityTokenReference" => "IssuerSerial");

$actions = array("http://wso2.org/wsfphp/samples/echoString" => "echoString");
 
$policy = new WSPolicy(array("security"=> $sec_array));

$sec_token = new WSSecurityToken(array("PKCS12KeyStore" => $keystore,
				       "user"=>"b",
                                       "password"=>"b12345"));

$svr = new WSService(array("actions" => $actions,
                           "operations" => $operations,
                           "policy" => $policy,
                           "securityToken" => $sec_token));
        
$svr->reply();

?>
