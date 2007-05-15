<?php

$reqPayloadString = <<<XML
<ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
<text>Hello World!</text>
</ns1:echoString>
XML;


$key = ws_get_key_from_file("b_cert.cert");

$in_policy_xml = file_get_contents("client-incoming-secpolicy.xml");
$out_policy_xml = file_get_contents("client-outgoing-secpolicy.xml");

$policy_obj = array("inpolicy"=>$in_policy_xml,
                    "outpolicy"=>$out_policy_xml);

$policy = new WSPolicy(array("security"=>$policy_obj));

$sec_token = new WSSecurityToken(array("user" => "Raigama",
                                       "ttl" => 300,
                                       "password" => "RaigamaPW",
                                       "passwordType" => "Digest",
                                       "receiverCertificate" => $key));

try {
    $client = new WSClient(array("to"=>"http://localhost:9090/secpolicy/scenario4/sec_service_scenario4_file.php",
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