<?php
$imageID = "1.jpg";
function submit($recvMsg) {
    global $imageID;
    $simplexml = new SimpleXMLElement($recvMsg->str);
    foreach ($simplexml->children("http://www.wso2.net/wsf/prototype") as $tag => $childNode) {
        foreach ($childNode->children("http://www.wso2.net/wsf/prototype") as $tag2 => $childNode2) {
            foreach ($childNode2->children("http://www.wso2.net/wsf/prototype") as $tag3 => $childNode3) {
                if (strcmp($tag3, "strElement") == 0){
                    $imageID = $childNode3;
                }
            }
        }
    }

    $resPayloadString = <<<XML
    <ns1:submitResponse xmlns:ns1="http://www.wso2.net/wsf">
    <pro:testDocOut xmlns:pro="http://www.wso2.net/wsf/prototype">
            <pro:intStrElement>
                    <pro:intElement>12</pro:intElement>
                    <pro:strElement>$imageID</pro:strElement>
            </pro:intStrElement>
            <pro:binaryElement>
            <xop:Include xmlns:xop="http://www.w3.org/2004/08/xop/include" href="cid:a"></xop:Include>
	    </pro:binaryElement>	
            <pro:anyElement>
                    <test123>1 2 3 4 5 6</test123>
            </pro:anyElement>
    </pro:testDocOut>
    </ns1:submitResponse>
XML;
      
  $f = file_get_contents("./service_resources/".$imageID); 	
  return new WSMessage($resPayloadString , 
		array(
			"attachments"=>array("a"=>$f),
                  "defaultAttachmentContentType"=>"image/jpeg"
		     ));
} 
$actions = array("http://www.wso2.net/products/wsf_php/demo/submit"=>"submit");
$ops = array("submit"=>"submit");
$service = new WSService(array("operations"=>$ops,
                               "actions"=>$actions,
                               "useMTOM"=>TRUE));
$service->reply();

?>






