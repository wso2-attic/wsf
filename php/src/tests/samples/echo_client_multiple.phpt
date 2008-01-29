--TEST--
Test for echo_client multiple invocation
--FILE--
<?php

$reqPayloadStrings = array();

for ($i = 0 ; $i < 10; $i++) {
$tmp = "Hello World "."$i";
$reqPayloadString = <<<XML
<ns1:echoString xmlns:ns1="http://ws.apache.org/axis2/c/samples">
   <text>$tmp</text>
</ns1:echoString>
XML;
array_push($reqPayloadStrings,$reqPayloadString);
}

try
{
    $serviceClient = new WSClient();

    for($i = 0 ; $i < 10; $i++) {
        $msg = new WSMessage($reqPayloadStrings[$i],
                                      array("to"=>"http://localhost/samples/echo_service.php"));
        $resPayload = $serviceClient->request($msg);
        printf("Round %s<br>",$i);
        printf("--------<br>");
        
        printf("Response = %s <br><br>", htmlspecialchars($resPayload->str));
        printf("Last Request = %s<br><br>",htmlspecialchars($serviceClient->getLastRequest()));
        printf("Last Response = %s<br><br>",htmlspecialchars($serviceClient->getLastResponse()));
        //printf("Last Response Headers = %s<br><br>",$serviceClient->getLastResponseHeaders());
    
    }

} catch (Exception $e) {
   if ($e instanceof WSFault) {
       printf("Soap Fault : %s<br>", $e->getSoapFaultText());
   } else {
       printf("Fault Message = %s<br>",$e->getMessage());
   }
}
?>
--EXPECT--
Round 0<br>--------<br>Response = &lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 0&lt;/text&gt;
&lt;/ns1:echoString&gt; <br><br>Last Request = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 0&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Last Response = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 0&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Round 1<br>--------<br>Response = &lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 1&lt;/text&gt;
&lt;/ns1:echoString&gt; <br><br>Last Request = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 1&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Last Response = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 1&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Round 2<br>--------<br>Response = &lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 2&lt;/text&gt;
&lt;/ns1:echoString&gt; <br><br>Last Request = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 2&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Last Response = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 2&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Round 3<br>--------<br>Response = &lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 3&lt;/text&gt;
&lt;/ns1:echoString&gt; <br><br>Last Request = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 3&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Last Response = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 3&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Round 4<br>--------<br>Response = &lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 4&lt;/text&gt;
&lt;/ns1:echoString&gt; <br><br>Last Request = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 4&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Last Response = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 4&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Round 5<br>--------<br>Response = &lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 5&lt;/text&gt;
&lt;/ns1:echoString&gt; <br><br>Last Request = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 5&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Last Response = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 5&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Round 6<br>--------<br>Response = &lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 6&lt;/text&gt;
&lt;/ns1:echoString&gt; <br><br>Last Request = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 6&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Last Response = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 6&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Round 7<br>--------<br>Response = &lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 7&lt;/text&gt;
&lt;/ns1:echoString&gt; <br><br>Last Request = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 7&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Last Response = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 7&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Round 8<br>--------<br>Response = &lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 8&lt;/text&gt;
&lt;/ns1:echoString&gt; <br><br>Last Request = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 8&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Last Response = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 8&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Round 9<br>--------<br>Response = &lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 9&lt;/text&gt;
&lt;/ns1:echoString&gt; <br><br>Last Request = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 9&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>Last Response = &lt;soapenv:Envelope xmlns:soapenv=&quot;http://www.w3.org/2003/05/soap-envelope&quot;&gt;&lt;soapenv:Header/&gt;&lt;soapenv:Body&gt;&lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World 9&lt;/text&gt;
&lt;/ns1:echoString&gt;&lt;/soapenv:Body&gt;&lt;/soapenv:Envelope&gt;<br><br>