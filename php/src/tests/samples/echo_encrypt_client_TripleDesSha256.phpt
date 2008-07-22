--TEST--
Test for echo_encrypt_client_Basic128Rsa15 sample
--FILE--
<?php


$reqPayloadString = <<<XML
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
XML;

try {
    $rec_cert = ws_get_cert_from_file("keys/bob_cert.cert");
    $pvt_key = ws_get_key_from_file("keys/alice_key.pem");
    
    $reqMessage = new WSMessage($reqPayloadString,
                                array("to"=>"http://localhost/services/encrypt_service_TripleDesSha256.php",
                                      "action" => "http://php.axis2.org/samples/echoString"));
    
    $sec_array = array("encrypt"=>TRUE,
                       "algorithmSuite" => "TripleDesSha256",
                       "securityTokenReference" => "IssuerSerial");
    
    $policy = new WSPolicy(array("security"=>$sec_array));
    $sec_token = new WSSecurityToken(array("privateKey" => $pvt_key,
                                           "receiverCertificate" => $rec_cert));
    
    $client = new WSClient(array("useWSA" => TRUE,
                                 "policy" => $policy,
                                 "securityToken" => $sec_token));
				
    $resMessage = $client->request($reqMessage);
    
    printf("Response = %s \n", $resMessage->str);

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>
--EXPECT--
Response = <ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>


