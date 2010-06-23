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

function echoFunction($inMessage) {

    $returnMessage = new WSMessage($inMessage->str);

    return $returnMessage;
}

function sct_delete_callback($sct_id,$sct_id_type)
{

}

function sct_store_callback($sct_str, $global_id,$local_id) {
	
	if (stristr(PHP_OS, 'WIN')) {
		$store_file = "sct.content";
	}else{
		$store_file = "/tmp/sct.content";
	}
	
	$fp_store_file_w = fopen($store_file, "a");
	if(flock($fp_store_file_w, LOCK_EX)) {
		if(!is_null($global_id)){
			fwrite($fp_store_file_w, $global_id.'|'.$sct_str.'!');
        }
        if(!is_null($local_id)){
			fwrite($fp_store_file_w,$local_id.'|'.$sct_str.'!');
        }
		flock($fp_store_file_w, LOCK_UN);
	} else {
		echo "Couldn't lock the ".$store_file." for writing!";
	}
	fclose($fp_store_file_w);
	return TRUE;
}

function sct_get_callback($sct_id,$sct_id_type, $is_encryption)
{
	if (stristr(PHP_OS, 'WIN')) {
		$sct_file = "sct.content";
	}else{
		$sct_file = "/tmp/sct.content";
	}
	$sct_array = array();	
	$sct_id_array = array();	
	
	clearstatcache();

	if(file_exists($sct_file))
	{
		$length = filesize($sct_file);
		$fp_rf = fopen($sct_file, "r");
		if(flock($fp_rf, LOCK_SH)) {
			$content = fread($fp_rf, $length);
			flock($fp_rf, LOCK_UN);
			$tok_rec = strtok($content, '!');
			$i = 0;
			while($tok_rec) {
				$msg_id_sct_str = $tok_rec;
				$sct_array[$i] = $msg_id_sct_str;
				$tok_rec = strtok('!');
				$i++;
			}
		} else {
			echo "Couldn't lock the ".$sct_file." for reading!";
		}
		fclose($fp_rf);
	}
	foreach($sct_array as $sctidvalue)
	{
		$tok1 = strtok($sctidvalue,'|');
		$tok2 = strtok('|');
		$sct_id_array[$tok1] = $tok2;
	}

	if(array_key_exists($sct_id, $sct_id_array))
	{
		return $sct_id_array[$sct_id];
	}
	return NULL;
}

$operations = array("echoString" => "echoFunction","SecConv10Issue"=>"echoFunction");
$actions = array("http://wso2.org/wsfphp/samples/echoString" => "echoString",
				"http://schemas.xmlsoap.org/ws/2005/02/trust/RST/SCT" => "SecConv10Issue");
$policy_xml = file_get_contents("policy.xml");
$policy = new WSPolicy($policy_xml);

$policy_xml = file_get_contents("sts_policy.xml");
$sts_policy = new WSPolicy($policy_xml);

$pub_key = ws_get_cert_from_file("../../keys/bob_cert.cert");
$rec_cert = ws_get_cert_from_file("../../keys/alice_cert.cert");
$pvt_key = ws_get_key_from_file("../../keys/bob_key.pem");

$security_token = new WSSecurityToken(array("user" => "Raigama",
                                            "password" => "RaigamaPW",
                                            "passwordType" => "Digest",
					    "storeSCTCallback" => "sct_store_callback",
					    "getSCTCallback" => "sct_get_callback",
					    "privateKey" => $pvt_key, 
					    "certificate"=> $pub_key,
					    "receiverCertificate" => $rec_cert,
				    	    "deleteSCTCallback"=>"sct_delete_callback"));


$svr = new WSService(array("operations" => $operations,
                           "actions" => $actions,
			   "opPolicies"=>array("echoString"=>$policy, "SecConv10Issue"=>$sts_policy),
			   "useOwnSTS"=>true,
                           "securityToken" => $security_token));
        
$svr->reply();

?>


