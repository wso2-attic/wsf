<?php

global $request_str;
global $response_str;

$request_str = $response_str = "";

if($_GET["requestBags"] == "1")
{
    requestBags();
}

/* temporary function to format xml */
function format_xml($xml)
{
    $xml = str_replace(">", ">\n", $xml);
    $xml = str_replace("</", "\n</", $xml);
    $xml = str_replace(">\n\n</", ">\n</", $xml);
    return $xml;
}

/* the function where actual web service call trigger */
function requestBags()
{

    /* Generate a random number for the purchase order*/
    $randNum = (rand()%99);

    /* Requested date is two weeks from today*/
    $reqDate = mktime(0,0,0,date("m"),date("d")+14,date("Y"));
    $reqDateStr = date("Y/m/d", $reqDate);

    /* The payload string*/
    $requestPayloadString = <<<XML
          <po:Order xmlns:po="http://www.back_packers.com/ws/purchaseorder">
             <po:OrderId>po-$randNum</po:OrderId>
             <po:ReqDate>$reqDateStr</po:ReqDate>
             <po:Design>
                <po:FileName>design.jpg</po:FileName>
                <po:Image><xop:Include xmlns:xop="http://www.w3.org/2004/08/xop/include" href="cid:myid1"></xop:Include></po:Image>
             </po:Design>
          </po:Order>
XML;

    try {
        global $request_str;
        global $response_str;
        /* Load the design*/
        $f = file_get_contents("./design.jpg");
       
        /* Build the message*/
        $requestMessage = new WSMessage($requestPayloadString, 
            array("to" => "http://localhost/solutions/store/manuf_service.php",
                    "action" => "http://www.back_packers.com/purchaseOrder",
                    "attachments" => array("myid1" => $f)));
        
        /* Load certificates and keys*/
        $rec_cert = ws_get_cert_from_file("keys/bob_cert.cert");
        $my_cert = ws_get_cert_from_file("keys/alice_cert.cert");
        $my_key = ws_get_key_from_file("keys/alice_key.pem");

        /* Load policy file*/
        $policy_xml = file_get_contents("policy.xml");
        $policy = new WSPolicy($policy_xml);

        /* Ceate a security token with reqd configurations*/
        $sec_token = new WSSecurityToken(array("user" => "Alice",
                                                "password" => "abcd!1234",
                                                "passwordType" => "Digest",
                                                "privateKey" => $my_key,
                                               "certificate" => $my_cert,
                                               "receiverCertificate" => $rec_cert));

        /* Create a new client*/
        $client = new WSClient(array("useWSA" => TRUE,
                                     "useMTOM" => FALSE,
                                     "policy" => $policy,
                                     "securityToken" => $sec_token));

        /* Request*/
        $responseMessage = $client->request($requestMessage);

        /* to track the messages */
        $request_str = $client->getLastRequest();
        $response_str = $client->getLastResponse();

        $request_str = format_xml($request_str);
        $response_str = format_xml($response_str);

        
        /* Print the response*/
        print "<div id=\"message\">More Backpacks requested : The purchase order number is {$responseMessage->str}</div>";

    } catch (Exception $e) {
        if ($e instanceof WSFault) {
            printf("Soap Fault: %s\n", $e->Reason);
        } else {
            printf("Message = %s\n",$e->getMessage());
        }
    }

} /*eof function requestBags()*/

?>

<HTML>
<HEAD>
    <TITLE>Store Client</TITLE>

<script type="text/javascript">
var stock_avail = 826;
var x = stock_avail;

function pause(numberMillis) {
        var now = new Date();
        var exitTime = now.getTime() + numberMillis;
        while (true) {
            now = new Date();
            if (now.getTime() > exitTime){
                return;
            }
        }
}


function setStock(){
    document.getElementById('stock').innerHTML = x;
}

function countD(){
    /*
    for(i = 0; i < 5; i++){
        alert("kjkj");
        document.getElementById('stock').innerHTML = i;
        pause(1000);
    }
    */
    x=x-1;
    setStock();

    /*If the stock goes below a predefined level, place the purchase order*/
    if(x < 820){
        /*Req PHP function*/
        location.href="online_client.php?requestBags=1";
    }
}

function resetD(){
    x = stock_avail;
    setStock();
    location.href="online_client.php?requestBags=0";
}
</script>

<style>
.config-textarea {
    text-align: left;
    width: 400px;
    height: 200px;
}

.clear {
    clear: both;
}

.content-left {
    width: 450px;
    float:left;
}

.content-middle {
    float: left;
}

.content-right {
    width: 450px;
    float:right;
}


#content
{
    width: 1000px;
    margin:0 auto;
    border:2px;
    padding: 15px
}

h2
{
    text-align: center;
    font-family: Verdana, Tahoma;
    font-size: 19px;
    padding: 12px;

}

h3
{
    text-align: center;
    font-family: Verdana, Tahoma;
    font-size: 14px;
    padding: 4px;

}

p
{
    font-family: Verdana, Tahoma;
    font-size: 12px;
    padding: 4px;
}

#message
{
    width: 1000px;
    margin:0 auto;
    font-family: Verdana, Tahoma;
    font-size: 15px;
    padding: 4px;
    color: #ff0000;
}

</style>
</HEAD>
<BODY>
<div id="content">
<H2>Backpack manufacs</H2>
<p>
<h3>How to run the demo?</h3>
<p>To reduce the number of bags available, click on the Buy button. If the stock level goes down 820, a purchase order will be placed automatically on the manufacturing service. To start over, click on the Reset
</p>
<form method="post" action="">
        <h3>Messages</h3>
        <div>
            <div class="content-left">
                <p>
                    Request Message
                </p>
                <textarea class="config-textarea" readonly="true"><?php echo $request_str;?></textarea>
            </div>
            <div class="content-middle">
            </div>
            <div class="content-right">
                <p>
                    Output Message
                </p>
                <textarea class="config-textarea" readonly="true"><?php echo $response_str;?></textarea>
            </div>
        </div>
        <div class="clear">
                &nbsp;
        </div>

        <input type='button' onclick='countD()' value='Buy'/>
        <input type='button' onclick='resetD()' value='Reset'/>


        <p>
            Available stock <b id='stock'>---</b> <br />
        </p>
        <p>
            <img src="design.jpg" width=400 />
        </p>

</form>
</div>
</BODY>
</HTML>
