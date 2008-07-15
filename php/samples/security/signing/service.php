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

$cert = ws_get_cert_from_file("../keys/bob_cert.cert");
$pvt_key = ws_get_key_from_file("../keys/bob_key.pem");

$operations = array("echoString" => "echoFunction");

$sec_array = array("sign" => TRUE,
                    "algorithmSuite" => "Basic256Rsa15",
                    "securityTokenReference" => "KeyIdentifier");

$policy = new WSPolicy(array("security"=>$sec_array));

$sec_token = new WSSecurityToken(array("privateKey" => $pvt_key,
                                       "certificate" => $cert));

$actions = array("http://wso2.org/wsfphp/samples/echoString" => "echoString");

$svr = new WSService(array("operations" => $operations,
                           "actions" => $actions,
                           "policy" => $policy,
                           "securityToken" => $sec_token));
        
$svr->reply();

?>
