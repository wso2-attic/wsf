--TEST--
Test for ws_client_getProxy_withService_port sample
--FILE--
<?php

try {

    $client = new WSClient(array("wsdl"=>"misc_files/sample.wsdl"));

    $proxy = $client->getProxy("SampleEchoService","SampleEchoServicePort");	

    $val =  $proxy->echoString("Hello");    
    echo $val."\n";

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>
--EXPECT--
Response = &lt;ns1:echoString xmlns:ns1=&quot;http://php.axis2.org/samples&quot;&gt;
        &lt;text&gt;Hello World!&lt;/text&gt;
    &lt;/ns1:echoString&gt; <br>
