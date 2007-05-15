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

function echoFunction($inMessage) {

    $returnMessage = new WSMessage($inMessage->str);

    return $returnMessage;
}

$operations = array("echoString" => "echoFunction");
$pub_key = ws_get_cert_from_file("a_cert.cert");


$in_policy_xml = file_get_contents("service-policy.xml");
$out_policy_xml = file_get_contents("out-service-policy.xml");

$sec_array = array("inpolicy" => $in_policy_xml,
                   "outpolicy" => $out_policy_xml);

$policy = new WSPolicy(array("security" => $sec_array));


$sec_token = new WSSecurityToken(array("ttl" => 100,
                                       "receiverCertificate" => $pub_key));

$svr = new WSService(array("operations" => $operations,
                           "policy" => $policy,
                           "securityToken" => $sec_token));
        
$svr->reply();

?>









