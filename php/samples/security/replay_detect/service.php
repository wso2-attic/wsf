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

function array_contains($array_of_string, $str) {
	foreach ($array_of_string as $value) {
		if(strcmp($value, $str) == 0) {
			return TRUE;			
		}
	}
	return FALSE;
}

function replay_detect_callback($msg_id, $time_created) {
	
	$max_duration = 5;
	if (stristr(PHP_OS, 'WIN')) {
		$replay_file = "replay.content";
	}else{
		$replay_file = "/tmp/replay.content";
	}
	$list_of_records = array();	
	clearstatcache();	
	if(file_exists($replay_file))
	{
		$length = filesize($replay_file);
		$fp_rf = fopen($replay_file, "r");
		if(flock($fp_rf, LOCK_SH)) {
			$content = fread($fp_rf, $length);
			flock($fp_rf, LOCK_UN);
			$tok_rec = strtok($content, '@');
			while($tok_rec) {
				$list_of_records[] = $tok_rec;
				$tok_rec = strtok('@');
			}
		} else {
			echo "Couldn't lock the ".$replay_file." for reading!";
		}
		fclose($fp_rf);
	}else {
		$fp_rf_w = fopen($replay_file, "w");
		if(flock($fp_rf_w, LOCK_EX)) {
			fwrite($fp_rf_w, $msg_id.$time_created.'@');
			flock($fp_rf_w, LOCK_UN);
		} else {
			echo "Couldn't lock the ".$replay_file." for writing!";
		}
		fclose($fp_rf_w);
		return TRUE;
	}

	if(array_contains($list_of_records, $msg_id.$time_created)) {
		return FALSE;
	} else {
		$elements = count($list_of_records);
		if($elements == $max_duration) {
			$new_rcd_list = array_splice($list_of_records, 1);
			$new_rcd_list[] = $msg_id.$time_created;
			$fp_rf_w = fopen($replay_file, "w");
			if(flock($fp_rf_w, LOCK_EX)) {
				foreach($new_rcd_list as $value) {
					fwrite($fp_rf_w, $value.'@');
				}
				flock($fp_rf_w, LOCK_UN);
			} else {
				echo "Couldn't lock the file for writing!";
			}
			fclose($fp_rf_w);
		} else {
			$list_of_records[] = $msg_id.$time_created;
			$fp_rf_w = fopen($replay_file, "w");
			if(flock($fp_rf_w, LOCK_EX)) {
				foreach($list_of_records as $value) {
					fwrite($fp_rf_w, $value.'@');
				}
				flock($fp_rf_w, LOCK_UN);
			} else {
				echo "Couldn't lock the file for writing!";
			}

			fclose($fp_rf_w);
		}
	}

	return TRUE;
}

$operations = array("echoString" => "echoFunction");
$actions = array("http://wso2.org/wsfphp/samples/echoString" => "echoString");

$policy_file = file_get_contents("policy.xml");
$policy = new WSPolicy($policy_file);
$security_token = new WSSecurityToken(array("user" => "Raigama",
                                            "password" => "RaigamaPW",
                                            "passwordType" => "Digest",
					    "replayDetectionCallback" => "replay_detect_callback",
					    "enableReplayDetect" => TRUE));


$svr = new WSService(array("operations" => $operations,
                           "actions" => $actions,
                           "policy" => $policy,
                           "securityToken" => $security_token));
        
$svr->reply();

?>


