--TEST--
Check for Yahoo sample
--FILE--
<?php
$reqPayloadString = <<<XML
<webSearch><appid>ApacheRestDemo</appid><query>SriLanka</query><form/></webSearch>
XML;

try {

    $client = new WSClient(
        array("to"=>"http://search.yahooapis.com/WebSearchService/V1/webSearch",
	      "HTTPMethod"=>GET,
	      "useSOAP"=>FALSE));
				
    $resMessage = $client->request($reqPayloadString);
    
    printf("Response = %s <br>", htmlspecialchars($resMessage->str));

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}

?>

--EXPECT--
Notice: Use of undefined constant GET - assumed 'GET' in C:\WSO2-Projects\WSF_PHP\wso2-wsf-php-1.0.0beta\src\tests\samples\yahoo_search.php on line 10
Response = &lt;ResultSet type=&quot;web&quot; xsi:schemaLocation=&quot;urn:yahoo:srch http://api.search.yahoo.com/WebSearchService/V1/WebSearchResponse.xsd&quot; totalResultsAvailable=&quot;97600000&quot; moreSearch=&quot;/WebSearchService/V1/webSearch?query=SriLanka&amp;amp;appid=ApacheRestDemo&amp;amp;region=us&quot; firstResultPosition=&quot;1&quot; totalResultsReturned=&quot;10&quot; xmlns=&quot;urn:yahoo:srch&quot; xmlns:xsi=&quot;http://www.w3.org/2001/XMLSchema-instance&quot;&gt;
&lt;Result&gt;&lt;Title&gt;Welcome to the Official Website of Sri Lanka Tourist Board&lt;/Title&gt;&lt;Summary&gt;... available, and a discussion forum for questions on traveling to Sri Lanka. ... August) is the seasons of festivals in Sri Lanka and the full moon day of Esala ...&lt;/Summary&gt;&lt;Url&gt;http://www.srilankatourism.org/&lt;/Url&gt;&lt;ClickUrl&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBOTvdmMwF;_ylu=X3oDMTB2cXVjNTM5BGNvbG8DdwRsA1dTMQRwb3MDMQRzZWMDc3IEdnRpZAM-/SIG=11jujc55e/EXP=1184842990/**http%3A//www.srilankatourism.org/&lt;/ClickUrl&gt;&lt;DisplayUrl&gt;www.srilankatourism.org/&lt;/DisplayUrl&gt;&lt;ModificationDate&gt;1184655600&lt;/ModificationDate&gt;&lt;MimeType&gt;text/html&lt;/MimeType&gt;
&lt;Cache&gt;&lt;Url&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBOjvdmMwF;_ylu=X3oDMTBwOHA5a2tvBGNvbG8DdwRwb3MDMQRzZWMDc3IEdnRpZAM-/SIG=16dlg6frh/EXP=1184842990/**http%3A//66.218.69.11/search/cache%3Fei=UTF-8%26appid=ApacheRestDemo%26query=SriLanka%26u=www.srilankatourism.org/%26w=srilanka%2B%2522sri%2Blanka%2522%26d=W_0axOrnPIZg%26icp=1%26.intl=us&lt;/Url&gt;&lt;Size&gt;26201&lt;/Size&gt;&lt;/Cache&gt;
&lt;/Result&gt;

&lt;Result&gt;&lt;Title&gt;Hotel Reservations. Sri Lanka &amp;amp;amp; Maldives&lt;/Title&gt;&lt;Summary&gt;Business and travel directory offering news, mail, and classifieds.&lt;/Summary&gt;&lt;Url&gt;http://www.srilanka.com/&lt;/Url&gt;&lt;ClickUrl&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBPDvdmMwF;_ylu=X3oDMTB2ZjQ4dDExBGNvbG8DdwRsA1dTMQRwb3MDMgRzZWMDc3IEdnRpZAM-/SIG=11cha1378/EXP=1184842990/**http%3A//www.srilanka.com/&lt;/ClickUrl&gt;&lt;DisplayUrl&gt;www.srilanka.com/&lt;/DisplayUrl&gt;&lt;ModificationDate&gt;1184655600&lt;/ModificationDate&gt;&lt;MimeType&gt;text/html&lt;/MimeType&gt;
&lt;Cache&gt;&lt;Url&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBPTvdmMwF;_ylu=X3oDMTBwZG5hOWwzBGNvbG8DdwRwb3MDMgRzZWMDc3IEdnRpZAM-/SIG=16683klk8/EXP=1184842990/**http%3A//66.218.69.11/search/cache%3Fei=UTF-8%26appid=ApacheRestDemo%26query=SriLanka%26u=www.srilanka.com/%26w=srilanka%2B%2522sri%2Blanka%2522%26d=YR2gqOrnPIZ6%26icp=1%26.intl=us&lt;/Url&gt;&lt;Size&gt;34914&lt;/Size&gt;&lt;/Cache&gt;
&lt;/Result&gt;

&lt;Result&gt;&lt;Title&gt;Sri Lanka - Wikipedia, the free encyclopedia&lt;/Title&gt;&lt;Summary&gt;Hyperlinked, in-depth article on the Republic of Sri Lanka. Includes notes on history, politics, and geography, as well as links.&lt;/Summary&gt;&lt;Url&gt;http://en.wikipedia.org/wiki/Sri_Lanka&lt;/Url&gt;&lt;ClickUrl&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBPzvdmMwF;_ylu=X3oDMTB2M3MzdmZoBGNvbG8DdwRsA1dTMQRwb3MDMwRzZWMDc3IEdnRpZAM-/SIG=11qn4q0bt/EXP=1184842990/**http%3A//en.wikipedia.org/wiki/Sri_Lanka&lt;/ClickUrl&gt;&lt;DisplayUrl&gt;en.wikipedia.org/wiki/Sri_Lanka&lt;/DisplayUrl&gt;&lt;ModificationDate&gt;1184482800&lt;/ModificationDate&gt;&lt;MimeType&gt;text/html&lt;/MimeType&gt;
&lt;Cache&gt;&lt;Url&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBQDvdmMwF;_ylu=X3oDMTBwZ2dpZ2ZkBGNvbG8DdwRwb3MDMwRzZWMDc3IEdnRpZAM-/SIG=16kubt6mm/EXP=1184842990/**http%3A//66.218.69.11/search/cache%3Fei=UTF-8%26appid=ApacheRestDemo%26query=SriLanka%26u=en.wikipedia.org/wiki/Sri_Lanka%26w=srilanka%2B%2522sri%2Blanka%2522%26d=WBPMu-rnPIUw%26icp=1%26.intl=us&lt;/Url&gt;&lt;Size&gt;198540&lt;/Size&gt;&lt;/Cache&gt;
&lt;/Result&gt;

&lt;Result&gt;&lt;Title&gt;Sri Lanka Web Server&lt;/Title&gt;&lt;Summary&gt;Includes general information, news, travel, and business information. Also hosts a chat room.&lt;/Summary&gt;&lt;Url&gt;http://www.lanka.net/&lt;/Url&gt;&lt;ClickUrl&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBQjvdmMwF;_ylu=X3oDMTB2OWM1MXQ5BGNvbG8DdwRsA1dTMQRwb3MDNARzZWMDc3IEdnRpZAM-/SIG=119oknnil/EXP=1184842990/**http%3A//www.lanka.net/&lt;/ClickUrl&gt;&lt;DisplayUrl&gt;www.lanka.net/&lt;/DisplayUrl&gt;&lt;ModificationDate&gt;1184655600&lt;/ModificationDate&gt;&lt;MimeType&gt;text/html&lt;/MimeType&gt;
&lt;Cache&gt;&lt;Url&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBQzvdmMwF;_ylu=X3oDMTBwYzFnNmkxBGNvbG8DdwRwb3MDNARzZWMDc3IEdnRpZAM-/SIG=163dm572m/EXP=1184842990/**http%3A//66.218.69.11/search/cache%3Fei=UTF-8%26appid=ApacheRestDemo%26query=SriLanka%26u=www.lanka.net/%26w=srilanka%2B%2522sri%2Blanka%2522%26d=NxVRp-rnPIdr%26icp=1%26.intl=us&lt;/Url&gt;&lt;Size&gt;26616&lt;/Size&gt;&lt;/Cache&gt;
&lt;/Result&gt;

&lt;Result&gt;&lt;Title&gt;Sri Lanka - Permanent Mission to the United Nations&lt;/Title&gt;&lt;Summary&gt;Permanent Mission of the Democratic Socialist Republic of Sri Lanka to the United Nations in New York, which also acts as a consulate.&lt;/Summary&gt;&lt;Url&gt;http://srilanka.un.int/&lt;/Url&gt;&lt;ClickUrl&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBRTvdmMwF;_ylu=X3oDMTB2NW50aG1hBGNvbG8DdwRsA1dTMQRwb3MDNQRzZWMDc3IEdnRpZAM-/SIG=11botnn12/EXP=1184842990/**http%3A//srilanka.un.int/&lt;/ClickUrl&gt;&lt;DisplayUrl&gt;srilanka.un.int/&lt;/DisplayUrl&gt;&lt;ModificationDate&gt;1183964400&lt;/ModificationDate&gt;&lt;MimeType&gt;text/html&lt;/MimeType&gt;
&lt;Cache&gt;&lt;Url&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBRjvdmMwF;_ylu=X3oDMTBwdDJ0dDBoBGNvbG8DdwRwb3MDNQRzZWMDc3IEdnRpZAM-/SIG=165e968l2/EXP=1184842990/**http%3A//66.218.69.11/search/cache%3Fei=UTF-8%26appid=ApacheRestDemo%26query=SriLanka%26u=srilanka.un.int/%26w=srilanka%2B%2522sri%2Blanka%2522%26d=FU8JVOrnPFzb%26icp=1%26.intl=us&lt;/Url&gt;&lt;Size&gt;94847&lt;/Size&gt;&lt;/Cache&gt;
&lt;/Result&gt;

&lt;Result&gt;&lt;Title&gt;Sri Lanka (SRI) - ADB.org&lt;/Title&gt;&lt;Summary&gt;Sri Lanka has been a member of ADB since 1966. ... Initiative for Asia-Pacific Welcomes Sri Lanka and Macao, China as 26th and 27th Full Members ...&lt;/Summary&gt;&lt;Url&gt;http://www.adb.org/SriLanka/default.asp&lt;/Url&gt;&lt;ClickUrl&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBSDvdmMwF;_ylu=X3oDMTB2azJrdmpwBGNvbG8DdwRsA1dTMQRwb3MDNgRzZWMDc3IEdnRpZAM-/SIG=11r98s6kh/EXP=1184842990/**http%3A//www.adb.org/SriLanka/default.asp&lt;/ClickUrl&gt;&lt;DisplayUrl&gt;www.adb.org/SriLanka/default.asp&lt;/DisplayUrl&gt;&lt;ModificationDate&gt;1183359600&lt;/ModificationDate&gt;&lt;MimeType&gt;text/html&lt;/MimeType&gt;
&lt;Cache&gt;&lt;Url&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBSTvdmMwF;_ylu=X3oDMTBwYmwxdWo4BGNvbG8DdwRwb3MDNgRzZWMDc3IEdnRpZAM-/SIG=16lk3c5ic/EXP=1184842990/**http%3A//66.218.69.11/search/cache%3Fei=UTF-8%26appid=ApacheRestDemo%26query=SriLanka%26u=www.adb.org/SriLanka/default.asp%26w=srilanka%2B%2522sri%2Blanka%2522%26d=WJHSdurnPDT-%26icp=1%26.intl=us&lt;/Url&gt;&lt;Size&gt;18026&lt;/Size&gt;&lt;/Cache&gt;
&lt;/Result&gt;

&lt;Result&gt;&lt;Title&gt;Sri Lanka national football team - Wikipedia, the free encyclopedia&lt;/Title&gt;&lt;Summary&gt;This Wikipedia encyclopaedia entry describes the national team. ... sub-continent, top-level football in Sri Lanka stands somewhat in the shadow of ...&lt;/Summary&gt;&lt;Url&gt;http://en.wikipedia.org/wiki/Sri_Lanka_national_football_team&lt;/Url&gt;&lt;ClickUrl&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBSzvdmMwF;_ylu=X3oDMTB2bDEyNXM5BGNvbG8DdwRsA1dTMQRwb3MDNwRzZWMDc3IEdnRpZAM-/SIG=12hg5prkh/EXP=1184842990/**http%3A//en.wikipedia.org/wiki/Sri_Lanka_national_football_team&lt;/ClickUrl&gt;&lt;DisplayUrl&gt;en.wikipedia.org/wiki/Sri_Lanka_national_football_team&lt;/DisplayUrl&gt;&lt;ModificationDate&gt;1183359600&lt;/ModificationDate&gt;&lt;MimeType&gt;text/html&lt;/MimeType&gt;
&lt;Cache&gt;&lt;Url&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBTDvdmMwF;_ylu=X3oDMTBwMTB0ZWFoBGNvbG8DdwRwb3MDNwRzZWMDc3IEdnRpZAM-/SIG=17b6j4g8p/EXP=1184842990/**http%3A//66.218.69.11/search/cache%3Fei=UTF-8%26appid=ApacheRestDemo%26query=SriLanka%26u=en.wikipedia.org/wiki/Sri_Lanka_national_football_team%26w=srilanka%2B%2522sri%2Blanka%2522%26d=XCXouOrnPFMm%26icp=1%26.intl=us&lt;/Url&gt;&lt;Size&gt;48302&lt;/Size&gt;&lt;/Cache&gt;
&lt;/Result&gt;

&lt;Result&gt;&lt;Title&gt;Sri Lanka Travel Information | Lonely Planet Destination Guide&lt;/Title&gt;&lt;Summary&gt;Information on events, attractions, activities, and transportation for the independent traveler.&lt;/Summary&gt;&lt;Url&gt;http://www.lonelyplanet.com/worldguide/destinations/asia/sri-lanka&lt;/Url&gt;&lt;ClickUrl&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBTjvdmMwF;_ylu=X3oDMTB2bTU4Zm85BGNvbG8DdwRsA1dTMQRwb3MDOARzZWMDc3IEdnRpZAM-/SIG=12md5edd2/EXP=1184842990/**http%3A//www.lonelyplanet.com/worldguide/destinations/asia/sri-lanka&lt;/ClickUrl&gt;&lt;DisplayUrl&gt;www.lonelyplanet.com/worldguide/destinations/asia/sri-lanka&lt;/DisplayUrl&gt;&lt;ModificationDate&gt;1184655600&lt;/ModificationDate&gt;&lt;MimeType&gt;text/html&lt;/MimeType&gt;
&lt;Cache&gt;&lt;Url&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBTzvdmMwF;_ylu=X3oDMTBwYTZ1aGtmBGNvbG8DdwRwb3MDOARzZWMDc3IEdnRpZAM-/SIG=17gae2mnn/EXP=1184842990/**http%3A//66.218.69.11/search/cache%3Fei=UTF-8%26appid=ApacheRestDemo%26query=SriLanka%26u=www.lonelyplanet.com/worldguide/destinations/asia/sri-lanka%26w=srilanka%2B%2522sri%2Blanka%2522%26d=RAS9xurnPIgu%26icp=1%26.intl=us&lt;/Url&gt;&lt;Size&gt;53299&lt;/Size&gt;&lt;/Cache&gt;
&lt;/Result&gt;

&lt;Result&gt;&lt;Title&gt;Sri Lanka Vacations, Tourism &amp;amp;amp; Attractions - Yahoo! Travel&lt;/Title&gt;&lt;Summary&gt;Sri Lanka vacations: Find the best Sri Lanka hotels, attractions, maps, pictures, weather, airport information, travel advice and more on Yahoo! Travel.&lt;/Summary&gt;&lt;Url&gt;http://travel.yahoo.com/p-travelguide-191501663-sri_lanka_vacations-i&lt;/Url&gt;&lt;ClickUrl&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBUTvdmMwF;_ylu=X3oDMTB2dW8yNmN0BGNvbG8DdwRsA1dTMQRwb3MDOQRzZWMDc3IEdnRpZAM-/SIG=1cq92s7lh/EXP=1184842990/**http%3A//rdrw1.yahoo.com/click%3Fu=http%3A//travel.yahoo.com/p-travelguide-191501663-sri_lanka_vacations-i%253B_ylc%253DX3oDMTFka28zOGNuBF9TAzI3NjY2NzkEX3MDOTY5NTUzMjUEc2VjA3NzcC1kZXN0BHNsawN0aXRsZQ--%26y=04F520AE16975DD405%26i=482%26c=9126%26q=02%255ESSHPM%255BL7LmvS~qt~6%26e=utf-8%26r=8%26d=wow~WBSV-en-us%26n=LPPKK1M6QMEKD8JJ%26s=1%26t=%26m=469DF36E%26x=052399538A3F4B471886C1B55988C0A969&lt;/ClickUrl&gt;&lt;DisplayUrl&gt;travel.yahoo.com/p-travelguide-191501663-sri_lanka_vacations-i&lt;/DisplayUrl&gt;&lt;ModificationDate&gt;1179558000&lt;/ModificationDate&gt;&lt;MimeType&gt;text/html&lt;/MimeType&gt;&lt;/Result&gt;

&lt;Result&gt;&lt;Title&gt;WTO | Sri Lanka - Member information&lt;/Title&gt;&lt;Summary&gt;Sri Lanka has been a WTO member since 1 January 1995. ... Reviews of Sri Lanka back to ... The Impact of GATS on Telecommunications Competition in Sri Lanka ...&lt;/Summary&gt;&lt;Url&gt;http://www.wto.org/english/thewto_e/countries_e/sri_lanka_e.htm&lt;/Url&gt;&lt;ClickUrl&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBUzvdmMwF;_ylu=X3oDMTEwc3RuNTk4BGNvbG8DdwRsA1dTMQRwb3MDMTAEc2VjA3NyBHZ0aWQD/SIG=12jkah701/EXP=1184842990/**http%3A//www.wto.org/english/thewto_e/countries_e/sri_lanka_e.htm&lt;/ClickUrl&gt;&lt;DisplayUrl&gt;www.wto.org/english/thewto_e/countries_e/sri_lanka_e.htm&lt;/DisplayUrl&gt;&lt;ModificationDate&gt;1182150000&lt;/ModificationDate&gt;&lt;MimeType&gt;text/html&lt;/MimeType&gt;
&lt;Cache&gt;&lt;Url&gt;http://uk.wrs.yahoo.com/_ylt=A0Je5apu851GhkYBVDvdmMwF;_ylu=X3oDMTBxNTUzbTg4BGNvbG8DdwRwb3MDMTAEc2VjA3NyBHZ0aWQD/SIG=17dgnkjsm/EXP=1184842990/**http%3A//66.218.69.11/search/cache%3Fei=UTF-8%26appid=ApacheRestDemo%26query=SriLanka%26u=www.wto.org/english/thewto_e/countries_e/sri_lanka_e.htm%26w=srilanka%2B%2522sri%2Blanka%2522%26d=A0z1j-rnPFuR%26icp=1%26.intl=us&lt;/Url&gt;&lt;Size&gt;25818&lt;/Size&gt;&lt;/Cache&gt;
&lt;/Result&gt;
&lt;/ResultSet&gt; <br>