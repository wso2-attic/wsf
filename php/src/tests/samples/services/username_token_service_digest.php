<?php


function echoFunction($inMessage) {

    $returnMessage = new WSMessage($inMessage->str);

    return $returnMessage;
}

$operations = array("echoString" => "echoFunction");
$actions = array("http://php.axis2.org/samples/echoString" => "echoString");
$sec_array = array("useUsernameToken" => TRUE);

$policy = new WSPolicy(array("security"=>$sec_array));
$sec_token = new WSSecurityToken(array("user" => "Raigama",
                                       "password" => "RaigamaPW",
                                       "passwordType" => "Digest"));

$svr = new WSService(array("operations" => $operations,
                           "actions" => $actions,
                           "policy" => $policy,
                           "securityToken" => $sec_token));
        
$svr->reply();

?>
