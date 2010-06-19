<?php
/*
 * Copyright 2005,2008 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

if(isset($_POST["scenario"]))
	$scenario = $_POST["scenario"];
if(isset($_POST["epr"]))
	$epr = $_POST["epr"];
$imageID = 1;
if(isset($_POST["qosAddr"]))
	$qosAddr = $_POST["qosAddr"];
$qosMTOM;
$qosRM;
$qosAddr =FALSE;
$recvMsg="";
$sentMsg="";
session_start();
$message = "";
if (!isset($_SESSION['message'])) {
		    $_SESSION['message'] = "";
} else {
    if (isset($_POST['submit']) || !isset($_GET['imageID'])) {
       	$_SESSION['message'] = "";
    }
    $message = $_SESSION['message'];
}
?>

<html>
	<head>
		<title>WSF/PHP MTOM ADDRESSING</title>
	</head>
	<body>
	<form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
	<table cols="2" border="1" cellpadding="10" cellspacing="0" align="center" width="100%">
	<tr>
	    <td>
	<h4>Request Reply Senario</h4>

<h4>Target Endpoint</h4>
Endpoint:<input type="text" size="60" maxlength="60" name="epr" value="http://localhost/samples/sudoku/sudoku_service.php"><br />
<h4>WS-*</h4>
Addressing : <input type="checkbox" value="Addressing" name="qosAddr"><br/>
XOP/MTOM : <input type="checkbox" checked="true" disabled value="MTOM" name="qosMTOM"><br/>
<!--Reliable Messaging : <input type="checkbox" value="RM" name="qosRM"><br /-->
<br />
<br />
<input type="submit" value="submit" name="submit">
</form>
<br/>
<br/>
<?php
echo "<form method=\"post\" action=\"http://".$_SERVER['SERVER_NAME'].":".$_SERVER["SERVER_PORT"]."/samples/sudoku/sudoku_client.php?act=delete\">";
echo "<input type=\"submit\" value=\"Reset \" name=\"reset\">";
echo "</form>";
echo "</td>";
?>

<?php

if (isset($_POST['submit']) || isset($_GET['imageID'])) {
if (isset($_GET['imageID'])){
    $imageID = $_GET['imageID'];
    $epr = $_GET['epr'];
    $qosAddr = $_GET['qosAddr'];
}


echo "<td>";

echo "<h2> Here are the Results</h2> <br/><br/>";

$reqPayloadString = <<<XML
<ns1:submit xmlns:ns1="http://www.wso2.net/wsf">
<pro:testDocIn xmlns:pro="http://www.wso2.net/wsf/prototype">
        <pro:intStrElement>
                <pro:intElement>12</pro:intElement>
                <pro:strElement>$imageID.jpg</pro:strElement>
        </pro:intStrElement>
        <pro:binaryElement/>
        <pro:anyElement>
                <test123>1 2 3 4 5 6</test123>
        </pro:anyElement>
</pro:testDocIn>
</ns1:submit>
XML;


try {
    $msg = new WSMessage($reqPayloadString,
			array("to"=>$epr,
			"action"=>"http://www.wso2.net/products/wsf_php/demo/submit"));
    
    $client_options = array();
    $client_options["useMTOM"] = TRUE;
    $client_options["responseXOP"] = TRUE;
    if($qosAddr){
    	$client_options["useWSA"] = TRUE;
    }

    $client = new WSClient($client_options);

    $message = $message.">>> Sending SOAP request to ".$epr." requesting for image ".$imageID.".jpg<br/>";
    $resMsg = $client->request($msg);
   
    $cid2str = $resMsg->attachments;
    $cid2cnt = $resMsg->cid2contentType;	    
    if($cid2str){
    foreach($cid2str as $i=>$value){
	    $f = $cid2str[$i];
		file_put_contents("./client_resources/".$imageID.".jpg", $f);
    }
    }   
    
    $message = $message."<<< Saved image ".$imageID.".jpg received<br/>";
    $sentMsg = $client->getLastRequest();
    $recvMsg = $client->getLastResponse();
    echo "<strong>Showing solution blocks ".$imageID." out of 9</strong>";
    echo "<table><tr>";
    for ($counter = 1; $counter <= $imageID; $counter++) {
        	echo "<td><img src='./client_resources/".$counter.".jpg'/></td>";
        if (($counter % 3) == 0 ) {
            echo "</tr><tr>";
        }
    }
    echo "</tr></table>";

    if ($imageID < 9) {
        $imageID += 1;
        echo "<script type='text/javascript'>";
        echo "function reload() {";
        echo "window.location=";
        echo "'http://".$_SERVER['SERVER_NAME'].":".$_SERVER["SERVER_PORT"]."/samples/sudoku/sudoku_client.php";
        echo "?imageID=".$imageID."&epr=".$epr."&qosAddr=".$qosAddr."';}";
        echo "setTimeout('reload()',1000)";
        echo "</script>";
    }
  
} catch (Exception $e) {
    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }

}
    
echo "</td>";
}
else {
echo "<td>.";
echo "</td>";
}
?>
</tr>
</table>
<?php
echo $message."<br/>";
echo "<strong>Showing Sent/Received Message </strong>";
echo "<table><tr>";
echo "<td><textarea type=\"text\" rows=\"15\" cols=\"60\">";
echo $sentMsg."";
echo "</textarea></td>";
if($recvMsg)
{
echo "<td><textarea type=\"text\" rows=\"15\" cols=\"60\">";
echo $recvMsg."";
echo "</textarea></td>";	 
}
echo "</tr></table>";
$_SESSION['message'] = $message;
?>
</body>
</html>














