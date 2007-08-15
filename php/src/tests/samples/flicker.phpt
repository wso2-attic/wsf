--TEST--
Test for flicker sample
--FILE--
<?php


$reqPayloadString = <<<XML
<x:FlickrRequest xmlns:x="urn:flickr">
<method>flickr.test.echo</method>
<api_key>76c683a00259619d3d6d98834b8c3271</api_key>
<name>cars</name>
</x:FlickrRequest>
XML;

try {

    $flicker_client = new WSClient(
        array("to"=>"http://api.flickr.com/services/soap/"));

				
    $resMessage = $flicker_client->request($reqPayloadString);
    
    printf("Response = %s <br>", htmlspecialchars($resMessage->str));

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Reason);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>

--EXPECT--
Response = &lt;x:FlickrResponse xmlns:x=&quot;urn:flickr&quot;&gt;
&amp;lt;method&amp;gt;flickr.test.echo&amp;lt;/method&amp;gt;
&amp;lt;api_key&amp;gt;76c683a00259619d3d6d98834b8c3271&amp;lt;/api_key&amp;gt;
&amp;lt;name&amp;gt;cars&amp;lt;/name&amp;gt;
		&lt;/x:FlickrResponse&gt; <br>