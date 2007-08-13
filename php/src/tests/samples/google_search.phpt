--TEST--
Check for google sample
--FILE--
<?php
$reqPayloadString = <<<XML
<ns1:doGoogleSearch x:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/" xmlns:ns1="urn:GoogleSearch" xmlns:x="http://schemas.xmlsoap.org/soap/envelope/" xmlns:xsi="http://www.w3.org/1999/XMLSchema-instance" xmlns:xsd="http://www.w3.org/1999/XMLSchema">
	<key xsi:type="xsd:string">wCumFQpQFHL7+coIxlNKUGtyVsgrVAnb</key>
	<q xsi:type="xsd:string">temperature</q>
	<start xsi:type="xsd:int">0</start>
	<maxResults xsi:type="xsd:int">10</maxResults>
	<filter xsi:type="xsd:boolean">true</filter>
	<restrict xsi:type="xsd:string"></restrict>
	<safeSearch xsi:type="xsd:boolean">false</safeSearch>
	<lr xsi:type="xsd:string"></lr>
	<ie xsi:type="xsd:string">latin1</ie>
	<oe xsi:type="xsd:string">latin1</oe>
</ns1:doGoogleSearch>
XML;

try {
	$client = new WSClient(array("to" => "http://api.google.com/search/beta2",
		"useSOAP"=>"1.1")); 

	$resPayload = $client->request($reqPayloadString);
	printf("Response = %s <br/>\n", htmlspecialchars($resPayload->str));
} catch (Exception $e) {
	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
	
}


?>

--EXPECT--
Response = &lt;ns1:doGoogleSearchResponse SOAP-ENV:encodingStyle=&quot;http://schemas.xmlsoap.org/soap/encoding/&quot; xmlns:ns1=&quot;urn:GoogleSearch&quot;&gt;
&lt;return xsi:type=&quot;ns1:GoogleSearchResult&quot;&gt;
&lt;directoryCategories xsi:type=&quot;ns2:Array&quot; ns2:arrayType=&quot;ns1:DirectoryCategory[0]&quot; xmlns:ns2=&quot;http://schemas.xmlsoap.org/soap/encoding/&quot;&gt;
&lt;/directoryCategories&gt;
&lt;documentFiltering xsi:type=&quot;xsd:boolean&quot;&gt;false&lt;/documentFiltering&gt;
&lt;endIndex xsi:type=&quot;xsd:int&quot;&gt;10&lt;/endIndex&gt;
&lt;estimateIsExact xsi:type=&quot;xsd:boolean&quot;&gt;false&lt;/estimateIsExact&gt;
&lt;estimatedTotalResultsCount xsi:type=&quot;xsd:int&quot;&gt;236000000&lt;/estimatedTotalResultsCount&gt;
&lt;resultElements xsi:type=&quot;ns3:Array&quot; ns3:arrayType=&quot;ns1:ResultElement[10]&quot; xmlns:ns3=&quot;http://schemas.xmlsoap.org/soap/encoding/&quot;&gt;
&lt;item xsi:type=&quot;ns1:ResultElement&quot;&gt;
&lt;URL xsi:type=&quot;xsd:string&quot;&gt;http://www.onlineconversion.com/temperature.htm&lt;/URL&gt;
&lt;cachedSize xsi:type=&quot;xsd:string&quot;&gt;12k&lt;/cachedSize&gt;
&lt;directoryCategory xsi:type=&quot;ns1:DirectoryCategory&quot;&gt;
&lt;fullViewableName xsi:type=&quot;xsd:string&quot;&gt;&lt;/fullViewableName&gt;
&lt;specialEncoding xsi:type=&quot;xsd:string&quot;&gt;&lt;/specialEncoding&gt;
&lt;/directoryCategory&gt;
&lt;directoryTitle xsi:type=&quot;xsd:string&quot;&gt;&lt;/directoryTitle&gt;
&lt;hostName xsi:type=&quot;xsd:string&quot;&gt;&lt;/hostName&gt;
&lt;relatedInformationPresent xsi:type=&quot;xsd:boolean&quot;&gt;true&lt;/relatedInformationPresent&gt;
&lt;snippet xsi:type=&quot;xsd:string&quot;&gt;Convert &amp;lt;b&amp;gt;temperatures&amp;lt;/b&amp;gt; to and from celsius, fahrenheit, and kelvin.&lt;/snippet&gt;
&lt;summary xsi:type=&quot;xsd:string&quot;&gt;&lt;/summary&gt;
&lt;title xsi:type=&quot;xsd:string&quot;&gt;Online Conversion - &amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; Conversion&lt;/title&gt;
&lt;/item&gt;
&lt;item xsi:type=&quot;ns1:ResultElement&quot;&gt;
&lt;URL xsi:type=&quot;xsd:string&quot;&gt;http://en.wikipedia.org/wiki/Temperature&lt;/URL&gt;
&lt;cachedSize xsi:type=&quot;xsd:string&quot;&gt;77k&lt;/cachedSize&gt;
&lt;directoryCategory xsi:type=&quot;ns1:DirectoryCategory&quot;&gt;
&lt;fullViewableName xsi:type=&quot;xsd:string&quot;&gt;&lt;/fullViewableName&gt;
&lt;specialEncoding xsi:type=&quot;xsd:string&quot;&gt;&lt;/specialEncoding&gt;
&lt;/directoryCategory&gt;
&lt;directoryTitle xsi:type=&quot;xsd:string&quot;&gt;&lt;/directoryTitle&gt;
&lt;hostName xsi:type=&quot;xsd:string&quot;&gt;&lt;/hostName&gt;
&lt;relatedInformationPresent xsi:type=&quot;xsd:boolean&quot;&gt;true&lt;/relatedInformationPresent&gt;
&lt;snippet xsi:type=&quot;xsd:string&quot;&gt;1 The &amp;lt;b&amp;gt;temperature&amp;lt;/b&amp;gt; of an ideal monatomic gas is a measure of the average kinetic &amp;lt;br&amp;gt;  energy of its atoms as they move. In this animation, the size of helium &amp;lt;b&amp;gt;...&amp;lt;/b&amp;gt;&lt;/snippet&gt;
&lt;summary xsi:type=&quot;xsd:string&quot;&gt;&lt;/summary&gt;
&lt;title xsi:type=&quot;xsd:string&quot;&gt;&amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; - Wikipedia, the free encyclopedia&lt;/title&gt;
&lt;/item&gt;
&lt;item xsi:type=&quot;ns1:ResultElement&quot;&gt;
&lt;URL xsi:type=&quot;xsd:string&quot;&gt;http://www.eo.ucar.edu/skymath/tmp2.html&lt;/URL&gt;
&lt;cachedSize xsi:type=&quot;xsd:string&quot;&gt;38k&lt;/cachedSize&gt;
&lt;directoryCategory xsi:type=&quot;ns1:DirectoryCategory&quot;&gt;
&lt;fullViewableName xsi:type=&quot;xsd:string&quot;&gt;&lt;/fullViewableName&gt;
&lt;specialEncoding xsi:type=&quot;xsd:string&quot;&gt;&lt;/specialEncoding&gt;
&lt;/directoryCategory&gt;
&lt;directoryTitle xsi:type=&quot;xsd:string&quot;&gt;&lt;/directoryTitle&gt;
&lt;hostName xsi:type=&quot;xsd:string&quot;&gt;&lt;/hostName&gt;
&lt;relatedInformationPresent xsi:type=&quot;xsd:boolean&quot;&gt;true&lt;/relatedInformationPresent&gt;
&lt;snippet xsi:type=&quot;xsd:string&quot;&gt;A good general discussion of the physics and concept of &amp;amp;quot;&amp;lt;b&amp;gt;temperature&amp;lt;/b&amp;gt;.&amp;amp;quot;&lt;/snippet&gt;
&lt;summary xsi:type=&quot;xsd:string&quot;&gt;&lt;/summary&gt;
&lt;title xsi:type=&quot;xsd:string&quot;&gt;About &amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt;&lt;/title&gt;
&lt;/item&gt;
&lt;item xsi:type=&quot;ns1:ResultElement&quot;&gt;
&lt;URL xsi:type=&quot;xsd:string&quot;&gt;http://www.temperatureworld.com/&lt;/URL&gt;
&lt;cachedSize xsi:type=&quot;xsd:string&quot;&gt;33k&lt;/cachedSize&gt;
&lt;directoryCategory xsi:type=&quot;ns1:DirectoryCategory&quot;&gt;
&lt;fullViewableName xsi:type=&quot;xsd:string&quot;&gt;&lt;/fullViewableName&gt;
&lt;specialEncoding xsi:type=&quot;xsd:string&quot;&gt;&lt;/specialEncoding&gt;
&lt;/directoryCategory&gt;
&lt;directoryTitle xsi:type=&quot;xsd:string&quot;&gt;&lt;/directoryTitle&gt;
&lt;hostName xsi:type=&quot;xsd:string&quot;&gt;&lt;/hostName&gt;
&lt;relatedInformationPresent xsi:type=&quot;xsd:boolean&quot;&gt;true&lt;/relatedInformationPresent&gt;
&lt;snippet xsi:type=&quot;xsd:string&quot;&gt;&amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; news, &amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; information and &amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; related resources.&lt;/snippet&gt;
&lt;summary xsi:type=&quot;xsd:string&quot;&gt;&lt;/summary&gt;
&lt;title xsi:type=&quot;xsd:string&quot;&gt;&amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; World&lt;/title&gt;
&lt;/item&gt;
&lt;item xsi:type=&quot;ns1:ResultElement&quot;&gt;
&lt;URL xsi:type=&quot;xsd:string&quot;&gt;http://www.wunderground.com/US/Region/US/Temperature.html&lt;/URL&gt;
&lt;cachedSize xsi:type=&quot;xsd:string&quot;&gt;71k&lt;/cachedSize&gt;
&lt;directoryCategory xsi:type=&quot;ns1:DirectoryCategory&quot;&gt;
&lt;fullViewableName xsi:type=&quot;xsd:string&quot;&gt;&lt;/fullViewableName&gt;
&lt;specialEncoding xsi:type=&quot;xsd:string&quot;&gt;&lt;/specialEncoding&gt;
&lt;/directoryCategory&gt;
&lt;directoryTitle xsi:type=&quot;xsd:string&quot;&gt;&lt;/directoryTitle&gt;
&lt;hostName xsi:type=&quot;xsd:string&quot;&gt;&lt;/hostName&gt;
&lt;relatedInformationPresent xsi:type=&quot;xsd:boolean&quot;&gt;true&lt;/relatedInformationPresent&gt;
&lt;snippet xsi:type=&quot;xsd:string&quot;&gt;A giant ridge of high pressure will keep &amp;lt;b&amp;gt;temperatures&amp;lt;/b&amp;gt; very warm in the Southwest, &amp;lt;br&amp;gt;  &amp;lt;b&amp;gt;...&amp;lt;/b&amp;gt; &amp;lt;b&amp;gt;Temperatures&amp;lt;/b&amp;gt; in the Lower 48 states Sunday ranged from a low of 38 &amp;lt;b&amp;gt;...&amp;lt;/b&amp;gt;&lt;/snippet&gt;
&lt;summary xsi:type=&quot;xsd:string&quot;&gt;&lt;/summary&gt;
&lt;title xsi:type=&quot;xsd:string&quot;&gt;Regional Map : Weather Underground&lt;/title&gt;
&lt;/item&gt;
&lt;item xsi:type=&quot;ns1:ResultElement&quot;&gt;
&lt;URL xsi:type=&quot;xsd:string&quot;&gt;http://www.convert-me.com/en/convert/temperature&lt;/URL&gt;
&lt;cachedSize xsi:type=&quot;xsd:string&quot;&gt;21k&lt;/cachedSize&gt;
&lt;directoryCategory xsi:type=&quot;ns1:DirectoryCategory&quot;&gt;
&lt;fullViewableName xsi:type=&quot;xsd:string&quot;&gt;&lt;/fullViewableName&gt;
&lt;specialEncoding xsi:type=&quot;xsd:string&quot;&gt;&lt;/specialEncoding&gt;
&lt;/directoryCategory&gt;
&lt;directoryTitle xsi:type=&quot;xsd:string&quot;&gt;&lt;/directoryTitle&gt;
&lt;hostName xsi:type=&quot;xsd:string&quot;&gt;&lt;/hostName&gt;
&lt;relatedInformationPresent xsi:type=&quot;xsd:boolean&quot;&gt;true&lt;/relatedInformationPresent&gt;
&lt;snippet xsi:type=&quot;xsd:string&quot;&gt;&amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; conversion online. Instant online units and measurements conversion: &amp;lt;br&amp;gt;  for metric conversion and other systems. Many units supported from common &amp;lt;b&amp;gt;...&amp;lt;/b&amp;gt;&lt;/snippet&gt;
&lt;summary xsi:type=&quot;xsd:string&quot;&gt;&lt;/summary&gt;
&lt;title xsi:type=&quot;xsd:string&quot;&gt;&amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; conversion online.&lt;/title&gt;
&lt;/item&gt;
&lt;item xsi:type=&quot;ns1:ResultElement&quot;&gt;
&lt;URL xsi:type=&quot;xsd:string&quot;&gt;http://weather.unisys.com/surface/sfc_con_temp.html&lt;/URL&gt;
&lt;cachedSize xsi:type=&quot;xsd:string&quot;&gt;8k&lt;/cachedSize&gt;
&lt;directoryCategory xsi:type=&quot;ns1:DirectoryCategory&quot;&gt;
&lt;fullViewableName xsi:type=&quot;xsd:string&quot;&gt;&lt;/fullViewableName&gt;
&lt;specialEncoding xsi:type=&quot;xsd:string&quot;&gt;&lt;/specialEncoding&gt;
&lt;/directoryCategory&gt;
&lt;directoryTitle xsi:type=&quot;xsd:string&quot;&gt;&lt;/directoryTitle&gt;
&lt;hostName xsi:type=&quot;xsd:string&quot;&gt;&lt;/hostName&gt;
&lt;relatedInformationPresent xsi:type=&quot;xsd:boolean&quot;&gt;true&lt;/relatedInformationPresent&gt;
&lt;snippet xsi:type=&quot;xsd:string&quot;&gt;Current &amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; Contour Plot. PLOT, Temp, NA-Temp &amp;amp;middot; 24-Temp &amp;amp;middot; WChill &amp;amp;middot; Heat &amp;amp;middot; &amp;lt;br&amp;gt;  Pres &amp;amp;middot; 3-Pres &amp;lt;b&amp;gt;...&amp;lt;/b&amp;gt; Current &amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; Contour Plot.    Unisys Corp. 2001 &amp;lt;b&amp;gt;...&amp;lt;/b&amp;gt;&lt;/snippet&gt;
&lt;summary xsi:type=&quot;xsd:string&quot;&gt;&lt;/summary&gt;
&lt;title xsi:type=&quot;xsd:string&quot;&gt;Unisys Weather: Current &amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; Contour Plot&lt;/title&gt;
&lt;/item&gt;
&lt;item xsi:type=&quot;ns1:ResultElement&quot;&gt;
&lt;URL xsi:type=&quot;xsd:string&quot;&gt;http://hyperphysics.phy-astr.gsu.edu/hbase/thermo/temper.html&lt;/URL&gt;
&lt;cachedSize xsi:type=&quot;xsd:string&quot;&gt;7k&lt;/cachedSize&gt;
&lt;directoryCategory xsi:type=&quot;ns1:DirectoryCategory&quot;&gt;
&lt;fullViewableName xsi:type=&quot;xsd:string&quot;&gt;&lt;/fullViewableName&gt;
&lt;specialEncoding xsi:type=&quot;xsd:string&quot;&gt;&lt;/specialEncoding&gt;
&lt;/directoryCategory&gt;
&lt;directoryTitle xsi:type=&quot;xsd:string&quot;&gt;&lt;/directoryTitle&gt;
&lt;hostName xsi:type=&quot;xsd:string&quot;&gt;&lt;/hostName&gt;
&lt;relatedInformationPresent xsi:type=&quot;xsd:boolean&quot;&gt;true&lt;/relatedInformationPresent&gt;
&lt;snippet xsi:type=&quot;xsd:string&quot;&gt;A convenient operational definition of &amp;lt;b&amp;gt;temperature&amp;lt;/b&amp;gt; is that it is a measure of &amp;lt;br&amp;gt;  the average translational kinetic energy associated with the disordered &amp;lt;b&amp;gt;...&amp;lt;/b&amp;gt;&lt;/snippet&gt;
&lt;summary xsi:type=&quot;xsd:string&quot;&gt;&lt;/summary&gt;
&lt;title xsi:type=&quot;xsd:string&quot;&gt;&amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt;&lt;/title&gt;
&lt;/item&gt;
&lt;item xsi:type=&quot;ns1:ResultElement&quot;&gt;
&lt;URL xsi:type=&quot;xsd:string&quot;&gt;http://www.weatherwizkids.com/temperature.htm&lt;/URL&gt;
&lt;cachedSize xsi:type=&quot;xsd:string&quot;&gt;40k&lt;/cachedSize&gt;
&lt;directoryCategory xsi:type=&quot;ns1:DirectoryCategory&quot;&gt;
&lt;fullViewableName xsi:type=&quot;xsd:string&quot;&gt;&lt;/fullViewableName&gt;
&lt;specialEncoding xsi:type=&quot;xsd:string&quot;&gt;&lt;/specialEncoding&gt;
&lt;/directoryCategory&gt;
&lt;directoryTitle xsi:type=&quot;xsd:string&quot;&gt;&lt;/directoryTitle&gt;
&lt;hostName xsi:type=&quot;xsd:string&quot;&gt;&lt;/hostName&gt;
&lt;relatedInformationPresent xsi:type=&quot;xsd:boolean&quot;&gt;true&lt;/relatedInformationPresent&gt;
&lt;snippet xsi:type=&quot;xsd:string&quot;&gt;&amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; is a degree of hotness or coldness the can be measured using a &amp;lt;br&amp;gt;  thermometer. It&amp;amp;#39;s also a measure of how fast the atoms and molecules of a &amp;lt;b&amp;gt;...&amp;lt;/b&amp;gt;&lt;/snippet&gt;
&lt;summary xsi:type=&quot;xsd:string&quot;&gt;&lt;/summary&gt;
&lt;title xsi:type=&quot;xsd:string&quot;&gt;&amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt;&lt;/title&gt;
&lt;/item&gt;
&lt;item xsi:type=&quot;ns1:ResultElement&quot;&gt;
&lt;URL xsi:type=&quot;xsd:string&quot;&gt;http://www.temperatures.com/&lt;/URL&gt;
&lt;cachedSize xsi:type=&quot;xsd:string&quot;&gt;29k&lt;/cachedSize&gt;
&lt;directoryCategory xsi:type=&quot;ns1:DirectoryCategory&quot;&gt;
&lt;fullViewableName xsi:type=&quot;xsd:string&quot;&gt;&lt;/fullViewableName&gt;
&lt;specialEncoding xsi:type=&quot;xsd:string&quot;&gt;&lt;/specialEncoding&gt;
&lt;/directoryCategory&gt;
&lt;directoryTitle xsi:type=&quot;xsd:string&quot;&gt;&lt;/directoryTitle&gt;
&lt;hostName xsi:type=&quot;xsd:string&quot;&gt;&lt;/hostName&gt;
&lt;relatedInformationPresent xsi:type=&quot;xsd:boolean&quot;&gt;true&lt;/relatedInformationPresent&gt;
&lt;snippet xsi:type=&quot;xsd:string&quot;&gt;An information resource on a wide range of devices that measure &amp;lt;b&amp;gt;temperature&amp;lt;/b&amp;gt;.&lt;/snippet&gt;
&lt;summary xsi:type=&quot;xsd:string&quot;&gt;&lt;/summary&gt;
&lt;title xsi:type=&quot;xsd:string&quot;&gt;About &amp;lt;b&amp;gt;Temperature&amp;lt;/b&amp;gt; Sensors or &amp;lt;b&amp;gt;temperature&amp;lt;/b&amp;gt; measurement devices and &amp;lt;b&amp;gt;...&amp;lt;/b&amp;gt;&lt;/title&gt;
&lt;/item&gt;
&lt;/resultElements&gt;
&lt;searchComments xsi:type=&quot;xsd:string&quot;&gt;&lt;/searchComments&gt;
&lt;searchQuery xsi:type=&quot;xsd:string&quot;&gt;temperature&lt;/searchQuery&gt;
&lt;searchTime xsi:type=&quot;xsd:double&quot;&gt;0.126511&lt;/searchTime&gt;
&lt;searchTips xsi:type=&quot;xsd:string&quot;&gt;&lt;/searchTips&gt;
&lt;startIndex xsi:type=&quot;xsd:int&quot;&gt;1&lt;/startIndex&gt;
&lt;/return&gt;
&lt;/ns1:doGoogleSearchResponse&gt; <br/>