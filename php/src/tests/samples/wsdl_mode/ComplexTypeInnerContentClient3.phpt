--TEST--
ComplexType Inner Content 3
--FILE--
<?php
require_once("samples/wsdl_mode/lib/request.php");

$url = "http://localhost/services/wsdl_mode/ComplexTypeInnerContentService.php";
$msg = <<<END
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope">
   <soapenv:Body>
      <ns1:myDemo xmlns:ns1="http://wso2.org/dyn/codegen/demo">
         <ns1:demo2>Hi string</ns1:demo2>
         <ns1:demo4>test123</ns1:demo4>
         <ns1:demo3>6</ns1:demo3>
         <ns1:demo5>test456</ns1:demo5>
      </ns1:myDemo>
   </soapenv:Body>
</soapenv:Envelope>
END;

soap_post($url, $msg, "urn:myDemo");
?>
--EXPECT--
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope"><soapenv:Body><ns1:myDemoResponse xmlns:ns1="http://wso2.org/dyn/codegen/demo">myDemo Object
(
    [demo1] =&gt; 
    [demo2] =&gt; Hi string
    [demo3] =&gt; 6
    [demo4] =&gt; test123
    [demo5] =&gt; 
)
</ns1:myDemoResponse></soapenv:Body></soapenv:Envelope>
