--TEST--
ComplexType All 2 
--FILE--
<?php
require_once("samples/wsdl_mode/lib/request.php");

$url = "http://localhost/services/wsdl_mode/ComplexTypeAllService.php";
$msg = <<<END
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope">
   <soapenv:Body>
      <ns1:myDemo xmlns:ns1="http://wso2.org/dyn/codegen/demo">
         <ns1:demo2>test</ns1:demo2>
         <ns1:demo1>3</ns1:demo1>
      </ns1:myDemo>
   </soapenv:Body>
</soapenv:Envelope>
END;

soap_post($url, $msg, "urn:myDemo");
?>
--EXPECT--
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope"><soapenv:Body><ns1:myDemoResponse xmlns:ns1="http://wso2.org/dyn/codegen/demo">myDemo Object
(
    [demo1] =&gt; 3
    [demo2] =&gt; test
)
</ns1:myDemoResponse></soapenv:Body></soapenv:Envelope>
