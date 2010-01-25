<?php

require_once("wso2/DataServices/DataService.php");
require_once("constants.php");

// Database structure

// Application:
// ------------------------------------------------
// |  applicationID  |  applicationName  | applicationTeacher | 
// ------------------------------------------------


// Students
// ---------------------------------------------------------------
// |  studentID  |  studentName  | studentAge |  studentAddress  |
// ---------------------------------------------------------------

// Marks
// --------------------------------------
// |  applicationID  |  studentID  | Marks  | 
// --------------------------------------


// database configurations
$config = array(
      "db" => "mysql",
      "username" => DB_USERNAME,
      "password" => DB_PASSWORD,
      "dbname" => "RESTfulSchool",
      "dbhost" => "localhost");

// ============= READ - Get applications by id operation ========================

$output_format = array(
                    "resultElement" => "applications",
                    "rowElement" => "application",
                    "elements" => array(
                            "id" => "id",
                            "name" => "name",
                            "email" => "email",
			    "address" => "address"));

$input_format = array("id" => "INTEGER");

$sql = "SELECT id, name, email, address FROM Applications where id = ?";

$get_applications_by_id_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_applications_by_id_url = array("HTTPMethod" => "GET", "RESTLocation" => "applications/{id}");

// ==============================================================================

// ============= READ - Get applications operation ==============================

$output_format = array(
                    "resultElement" => "applications",
                    "rowElement" => "application",
                    "elements" => array(
                            "id" => "id",
                            "name" => "name",
                            "email" => "email",
                            "address" => "address"));

$sql = "SELECT id, name, email, address FROM Applications";

$get_applications_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_applications_url = array("HTTPMethod" => "GET", "RESTLocation" => "applications");


// ============= WRITE - Set applications operation ========================

$output_format = array(
                    "resultElement" => "setApplicationResponse",
                    "rowElement" => "status"); //for fail the engine will return false

$sql = "INSERT INTO Applications VALUES(?, ?, ?, ?);";

$input_format = array("id" => "INTEGER", "name" => "STRING", "email" => "STRING", "address" => "STRING");

$set_applications_by_id_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$set_applications_by_id_url = array("HTTPMethod" => "POST", "RESTLocation" => "applications/{id}");

// ==============================================================================


// ============= DELETE - Delete applications operation ========================

$output_format = array(
                    "resultElement" => "deleteApplicationResponse",
                    "rowElement" => "status"); //for fail the engine will return false

$sql = "DELETE FROM Applications WHERE id = ? and not(id=1 or id=2 or id=3)"; //last condition is to keep id 1,2,3 
 

$input_format = array("id" => "INTEGER");

$delete_applications_by_id_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$delete_applications_by_id_url = array("HTTPMethod" => "DELETE", "RESTLocation" => "applications/{id}");

// ==============================================================================

// ============= UPDATE  - Update applications operation ========================

$output_format = array(
                    "resultElement" => "updateApplicationResponse",
                    "rowElement" => "status"); //for fail the engine will return false


$sql = "UPDATE Applications SET name = ?, email = ?, address = ? WHERE id =?  and not(id=1 or id=2 or id=3)"; //last condition is to keep id 1,2,3 
 

$input_format = array("name" => "STRING", "email" => "STRING", "address" => "STRING", "id" => "INTEGER");

$put_applications_by_id_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$put_applications_by_id_url = array("HTTPMethod" => "PUT", "RESTLocation" => "applications/{id}");

// ==============================================================================



// list of operations
$operations = array(
                "getApplications" => $get_applications_op,
                "getApplicationsById" => $get_applications_by_id_op,
                "setApplicationsById" => $set_applications_by_id_op,
                "deleteApplicationsById" => $delete_applications_by_id_op,
                "putApplicationsById" => $put_applications_by_id_op,
                );

// list of rest url mappping (operation => url)
$restmap = array(
                "getApplications" => $get_applications_url,
                "getApplicationsById" => $get_applications_by_id_url,
                "setApplicationsById" => $set_applications_by_id_url,
                "deleteApplicationsById" => $delete_applications_by_id_url,
                "putApplicationsById" => $put_applications_by_id_url,
                );

// creating DSService and reply
$service = new DataService(array("config" => $config, "operations" => $operations, "RESTMapping"=>$restmap));
$service->reply();

?>

