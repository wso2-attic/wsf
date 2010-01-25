<?php


//define("DRUPAL_INST", "drupal_inst_dir");
define("DRUPAL_INST", "C:\wamp\www\drupal6");

// this will include the DataService class
require_once("wso2/DataServices/DataService.php");

// this will include the $db_url and $db_prefix variables
require_once(DRUPAL_INST."/sites/default/settings.php");

// $db_url is of form dbtype://username:password@localhost/databasename
// derive the db, usernmae, password, dbname, dbhost from db_url

list($db_type, $db_url_rest) = split("://", $db_url);
list($db_username, $db_url_rest) = split(":", $db_url_rest);
list($db_password, $db_url_rest) = split("@", $db_url_rest);
list($db_host, $db_url_rest) = split("/", $db_url_rest);
$db_name = $db_url_rest;


// database configurations
$db_config = array(
		"db" => $db_type,
		"username" => $db_username,
		"password" => $db_password,
		"dbname" => $db_name,
		"dbhost" => $db_host);


require("drupal_operations.php");

$operations = $nodes_operations;
$restmap = $nodes_restmap;

// creating DSService and reply
$service = new DataService(array("config" => $db_config,
					 "operations" => $operations,
					 "RESTMapping"=>$restmap));
$service->reply();

?>