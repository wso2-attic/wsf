--TEST--
Test for ws_policy_construct_invalid_param sample
--FILE--
<?php

$reqPayloadString = <<<XML
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
XML;

try {
    $my_cert = ws_get_cert_from_file("C:/Apache2.2/htdocs/samples/security/keys/alice_cert.cert");
    $my_key = ws_get_key_from_file("C:/Apache2.2/htdocs/samples/security/keys/alice_key.pem");
    $rec_cert = ws_get_cert_from_file("C:/Apache2.2/htdocs/samples/security/keys/bob_cert.cert");
    
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
Response = <ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>


