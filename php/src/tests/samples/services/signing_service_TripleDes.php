<?php


function echoFunction($inMessage) {

    $returnMessage = new WSMessage($inMessage->str);

    return $returnMessage;
}

$cert = ws_get_cert_from_file("keys/bob_cert.cert");
$pvt_key = ws_get_key_from_file("keys/bob_key.pem");

$operations = array("echoString" => "echoFunction");

$sec_array = array("sign" => TRUE,
                    "algorithmSuite" => "TripleDes",
                    "securityTokenReference" => "KeyIdentifier");

$policy = new WSPolicy(array("security"=>$sec_array));

$sec_token = new WSSecurityToken(array("privateKey" => $pvt_key,
                                       "certificate" => $cert));

$actions = array("http://php.axis2.org/samples/echoString" => "echoString");

$svr = new WSService(array("operations" => $operations,
                           "actions" => $actions,
                           "policy" => $policy,
                           "securityToken" => $sec_token));
        
$svr->reply();

?>
