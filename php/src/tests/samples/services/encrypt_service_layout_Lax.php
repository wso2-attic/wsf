<?php


function echoFunction($inMessage) {

    $returnMessage = new WSMessage($inMessage->str);

    return $returnMessage;
}

$pub_key = ws_get_cert_from_file("keys/alice_cert.cert");
$pvt_key = ws_get_key_from_file("keys/bob_key.pem");

$operations = array("echoString" => "echoFunction");
$sec_array = array("encrypt" => TRUE,
                    "algorithmSuite" => "Basic128Rsa15",
                    "layout" => "Lax",
                    "securityTokenReference" => "EmbeddedToken");

$actions = array("http://php.axis2.org/samples/echoString" => "echoString");

$policy = new WSPolicy(array("security"=>$sec_array));
$sec_token = new WSSecurityToken(array("privateKey" => $pvt_key,
                                       "receiverCertificate" =>$pub_key));

$svr = new WSService(array("actions" => $actions,
                           "operations" => $operations,
                           "policy" => $policy,
                           "securityToken" => $sec_token));
        
$svr->reply();

?>
