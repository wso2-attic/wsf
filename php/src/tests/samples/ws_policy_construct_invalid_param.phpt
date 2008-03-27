--TEST--
Test for ws_policy_construct_invalid_param sample
--FILE--
<?php

$reqPayloadString = <<<XML
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
XML;

try {
    $my_cert = ws_get_cert_from_file("keys/alice_cert.cert");
    $my_key = ws_get_key_from_file("keys/alice_key.pem");
    $rec_cert = ws_get_cert_from_file("keys/bob_cert.cert");
    
    $reqMessage = new WSMessage($reqPayloadString,
                                array("to"=>"http://localhost/samples/security/signing/signing_service_Basic128.php",
                                      "action" => "http://php.axis2.org/samples/echoString"));
    
    $sec_array = array("sign"=>TRUE,
                       "algorithmSuite" => "Basic128",
                       "securityTokenRefernce" => "Direct");
    
    $policy = new WSPolicy();
    $sec_token = new WSSecurityToken(array("privateKey" => $my_key,
                                           "certificate" => $my_cert,
                                           "receiverCertificate" => $rec_cert));
    
    $client = new WSClient(array("useWSA" => TRUE,
                                 "policy" => $policy,
                                 "securityToken" => $sec_token));
				
    $resMessage = $client->request($reqMessage);
    
    printf("Response = %s \n", $resMessage->str);

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>

--EXPECT--
Warning: WSPolicy::__construct() expects at least 1 parameter, 0 given in E:\wsfphp\src\tests\samples\ws_policy_construct_invalid_param.php on line 20

Fatal error: WSPolicy::__construct(): Invalid parameters in E:\wsfphp\src\tests\samples\ws_policy_construct_invalid_param.php on line 20

