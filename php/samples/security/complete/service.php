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
$pub_key = ws_get_cert_from_file("../keys/alice_cert.cert");

$operations = array("echoString" => "echoFunction");

$policy_xml = file_get_contents("policy.xml");
$policy = new WSPolicy($policy_xml);

$sec_token = new WSSecurityToken(array("privateKey" => $pvt_key,
                                       "certificate" => $cert,
                                       "receiverCertificate" => $pub_key));

$actions = array("http://wso2.org/wsfphp/samples/echoString" => "echoString");

$svr = new WSService(array("operations" => $operations,
                           "actions" => $actions,
                           "policy" => $policy,
                           "securityToken" => $sec_token));
        
$svr->reply();

?>
