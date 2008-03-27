--TEST--
Test for mtom download client sample
--FILE--
<?php

$requestPayloadString = <<<XML
<download xmlns="http://test.org"></download>
XML;

try {

    $client = new WSClient(
        array( "to" => "http://localhost/samples/mtom/mtom_download_service.php",
               "useMTOM" => TRUE,
               "responseXOP" => TRUE));

    $requestMessage = new WSMessage($requestPayloadString);                    
    $responseMessage = $client->request($requestMessage);
    
    $cid2stringMap = $responseMessage->attachments;
    $cid2contentMap = $responseMessage->cid2contentType;
    $imageName;
    if($cid2stringMap && $cid2contentMap){
        foreach($cid2stringMap as $i=>$value){
            $f = $cid2stringMap[$i];
            $contentType = $cid2contentMap[$i];
            if(strcmp($contentType,"image/jpeg") ==0){
                $imageName = $i."."."jpg";
                if(stristr(PHP_OS, 'WIN')) {
                    file_put_contents($imageName, $f);
                    printf("Image Saved");
                }else{
                    file_put_contents("/tmp/".$imageName, $f);
                    printf("Image Saved");
                }
            }
        }
    }else{
        printf("attachments not received ");
    }
    
} catch (Exception $e) {

    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
}
?>
--EXPECT--
Image Saved
