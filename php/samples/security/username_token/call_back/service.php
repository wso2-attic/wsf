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

// Username Password mapping table
$user_pass_mapping = array(
			"Raigama" => "RaigamaPW",
			"Alice" => "abcd!123",
			"Bob" => "wxyz!123");

function echoFunction($inMessage) {

	$returnMessage = new WSMessage($inMessage->str);

	return $returnMessage;
}

function get_my_password_function($username)
{
	//logic to get password from any source (ex: using mysql database
	// etc)
	global $user_pass_mapping;
	if(isset($user_pass_mapping[$username])){
		$password = $user_pass_mapping[$username];
		return $password;
	}
	else
	 return NULL;

}

$operations = array("echoString" => "echoFunction");
$actions = array("http://php.axis2.org/samples/echoString" => "echoString");
$policy_file = file_get_contents("policy.xml");

$policy = new WSPolicy($policy_file);
$sec_token = new WSSecurityToken(array("passwordCallback" => "get_my_password_function",
                                       "passwordType" => "Digest"));

$svr = new WSService(array("operations" => $operations,
                           "actions" => $actions,
                           "policy" => $policy,
                           "securityToken" => $sec_token));

$svr->reply();

?>
