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


$reqPayloadString = <<<XML
<ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
<text>Hello World!</text>
</ns1:echoString>
XML;


$key = ws_get_cert_from_file("b_cert.cert");

$sec_arry1 = array("includeTimeStamp" => TRUE );

$sec_arry2 = array("encrypt" => TRUE,
                   "algorithmSuite" => "Basic256Rsa15");

$policy_obj = array("inpolicy"=>$sec_arry1,
                    "outpolicy"=>$sec_arry2);

$policy = new WSPolicy(array("security"=>$policy_obj));

$sec_token = new WSSecurityToken(array("ttl" => 300,
                                       "receiverCertificate" => $key));

try {
    $client = new WSClient(array("to"=>"http://localhost/samples/security/encrypt_only/encrypt_service.php",
                                 "policy"=>$policy,
                                 "securityToken" => $sec_token));

    $response = $client->request($reqPayloadString);
    echo $response->str;
} catch (Exception $e) {
    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->code);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }

}



?>