--TEST--
Test for reply detect service
--FILE--
<?php
$reqPayloadString = <<<XML
<ns1:echo xmlns:ns1="http://wso2.org/wsfphp/samples"><text>Hello World!</text></ns1:echo>
XML;

try {

    $reqMessage = new WSMessage($reqPayloadString,
                                array("to"=>"http://localhost/samples/security/replay_detect/service.php",
                                      "action" => "http://wso2.org/wsfphp/samples/echoString"));
    
    $security_options = array("useUsernameToken" => TRUE );
    $policy = new WSPolicy(array("security" => $security_options));
    $security_token = new WSSecurityToken(array("user" => "Raigama",
                                                "password" => "RaigamaPW",
                                                "passwordType" => "Digest"));
    
    $client = new WSClient(array("useWSA" => TRUE,
                                "policy" => $policy,
                                "securityToken" => $security_token));
				
    $resMessage = $client->request($reqMessage);
    
    printf("Response = %s \n", $resMessage->str);

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Reason);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>
--EXPECT--
Response = <ns1:echo xmlns:ns1="http://wso2.org/wsfphp/samples"><text>Hello World!</text></ns1:echo>
