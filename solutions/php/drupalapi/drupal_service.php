<?php
//define("DRUPAL_INST", "drupal_inst_dir");
define("DRUPAL_INST", "C:\wamp\www\drupal6");

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
	
/* some global variables to be used for keep the user authentication*/
$current_username = "";
$current_userid = 0;
	
// PHP classes corresponding to the data types in defined in WSDL

class postStory {

    /**
     * @var (object)Node
     */
    public $post;

}
class postPage {
	
	/**
	 * @var (object)Node
	 */
	public $post;
	
}

class Node {

    /**
     * @var int
     */
    public $id;

    /**
     * @var string
     */
    public $title;

    /**
     * @var string
     */
    public $content;

    /**
     * @var dateTime
     */
	public $time;
	
	/**
	 * @var int
	 */
	public $userId;
	
	/**
	 * @var int
	 */
	public $promote;
	
	/**
	 * @var int
	 */
	public $moderate;
	
	/**
	 * @var int
	 */
	public $commentAccess;
	
	/**
	 * @var string
	 */
	public $type;

}

class postStoryResponse {

    /**
     * @var int
     */
    public $return;

}

class postPageResponse {
	
	/**
	 * @var int
	 */
	public $return;
	
}

class login {
	
}

class loginResponse {
	
	/**
	 * @var int
	 */
	public $return;
	
}


class User {

    /**
     * @var string
     */
    public $name;

    /**
     * @var string
     */
    public $password;

    /**
     * @var string
     */
    public $email;

}

class getCommentsForNode {

    /**
     * @var int
     */
    public $nodeId;

}

class getCommentsForNodeResponse {

    /**
     * @var array[0, unbounded] of (object)Comment
     */
    public $return;

}

class Comment {

    /**
     * @var int
     */
    public $id;

    /**
     * @var string
     */
    public $title;

    /**
     * @var string
     */
    public $content;

    /**
     * @var dateTime
     */
    public $time;

    /**
     * @var int
     */
	public $nodeId;
	
	/**
	 * @var int
	 */
	public $userId;
	
	/**
	 * @var string
	 */
	public $userName;

}

class getComments {
	
	/**
	 * @var int
	 */
	public $limit;
}

class getCommentsResponse {

    /**
     * @var array[0, unbounded] of (object)Comment
     */
    public $return;

}


class getCommentsByDuration {
	
	/**
	 * @var dateTime
	 */
	public $startTime;
	
	/**
	 * @var dateTime
	 */
	public $endTime;
}

class getCommentsByDurationResponse {
	
	/**
	 * @var array[0, unbounded] of (object)Comment
	 */
	public $return;
	
}


class postComment {

    /**
     * @var (object)Comment
     */
    public $comment;

}

class postCommentResponse {

    /**
     * @var int
     */
    public $return;

}

class getNodes {
	/**
	 * @var int
	 */
	public $limit;

}

class getNodesResponse {

    /**
     * @var array[0, unbounded] of (object)Node
     */
    public $return;

}

class getNodeById {
	/**
	 * @var int
	 */
	public $id;
	
}

class getNodeByIdResponse {
	
	/**
	 * @var (object)Node
	 */
	public $return;
	
}

class getNodesByDuration {
	
	/**
	 * @var dateTime
	 */
	public $startTime;
	
	/**
	 * @var dateTime
	 */
	public $endTime;
}

class getNodesByDurationResponse {
	
	/**
	 * @var array[0, unbounded] of (object)Node
	 */
	public $return;
	
}

// define the class map
$class_map = array(
		"postStory" => "postStory",
		"postPage" => "postPage",
		"Node" => "Node",
		"postStoryResponse" => "postStoryResponse",
		"postPageResponse" => "postPageResponse",
		"User" => "User",
		"getCommentsForNode" => "getCommentsForNode",
		"getCommentsForNodeResponse" => "getCommentsForNodeResponse",
		"Comment" => "Comment",
		"getComments" => "getComments",
		"getCommentsResponse" => "getCommentsResponse",
		"getCommentsByDuration" => "getCommentsByDuration",
		"getCommentsByDurationResponse" => "getCommentsByDurationResponse",
		"postComment" => "postComment",
		"postCommentResponse" => "postCommentResponse",
		"getNodes" => "getNodes",
		"getNodesResponse" => "getNodesResponse",
		"getNodesByDuration" => "getNodesByDuration",
		"getNodesByDurationResponse" => "getNodesByDurationResponse");

// define PHP functions that maps to WSDL operations 
/**
 * Service function postStory
 * @param object of postStory $input 
 * @return object of postStoryResponse 
 */
function postStory($input) {
    // NOTE: $input is of type postStory
    // NOTE: should return an object of type postStoryResponse
	
	$node_id = post_node($input, "story");
	
	$response = new postStoryResponse();
	$response->return = $node_id;
	
	return $response;
}

// define PHP functions that maps to WSDL operations 
/**
 * Service function postStory
 * @param object of postStory $input 
 * @return object of postStoryResponse 
 */
function postPage($input) {
	// NOTE: $input is of type postPage
	// NOTE: should return an object of type postPageResponse
	
	
	$node_id = post_node($input, "page");
	
	$response = new postPageResponse();
	$response->return = $node_id;
	
	return $response;
}

/**
 * post the node and retrieve the nodeId - this is not a service operation
 * @param $input the input containing the node type
 * @param $node_type node_type can have values "story", "page"
 * @return $node_id
 */

function post_node($input, $node_type)
{
	global $db_config;
	global $current_userid;
	
	// extracting out the db config
	$dbhost = $db_config["dbhost"];
	$dbname = $db_config["dbname"];
	$db_username = $db_config["username"];
	$db_password = $db_config["password"];
	
	
	// create the sql link
	$link=mysql_connect($dbhost,  $db_username,  $db_password);
	mysql_select_db($dbname, $link);
	
	// extracting out the input parameters
	$node = $input->post;
	$content = $node->content;
	$teaser = substr($content, 0, 600);
	$node_id = $node->id;
	$node_title = $node->title;
	$promote = $node->promote;
	$moderate = $node->moderate;
	$comment_access = $node->commentAccess;
	
	
	$node_time = $node->time;
	if($node_time == null) {
		$node_time = time(); // save as the current time
	}
	
	// users id is taken from the username token
	$node_user_id = $current_userid;
	
	// prepearing additional fields for insert depends on the avaiability.
	
	$additional_field_names = "";
	$additional_field_values = "";
	
	if(!is_null($promote)) {
		$additional_field_names .= ", promote";
		$additional_field_values .= ", '$promote'";
	}
	if(!is_null($moderate)) {
		$additional_field_names .= ", moderate";
		$additional_field_values .= ", '$moderate'";
	}
	if(!is_null($comment_access)) {
		$additional_field_names .= ", comment";
		$additional_field_values .= ", '$comment_access'";
	}
	
	// weather it is a new record or an existng record..
	$new_record = false;
	if($node_id == null) {
		// if the node_id is not given we assume it is a new entry..
		$new_record = true;
		
		// no node id version of inserting..
		$node_insert_sql = "INSERT INTO node (title, uid, type, created, changed $additional_field_names) ".
			"VALUES('$node_title', '$current_userid', '$node_type', '$node_time', '$node_time' $additional_field_values)";
	}
	else {
		// should check wether the nid exist
		$select_nodeid_sql = "SELECT nid, uid FROM node WHERE nid='$node_id'";
		$result = mysql_query($select_nodeid_sql);
		
		// no existing record, so create a new one, this time with nid
		if(mysql_num_rows($result) == 0) {
			$new_record = true;
			
			$node_insert_sql = "INSERT INTO node (nid, title, uid, type, created, changed $additional_field_names) ".
				"VALUES('$node_id', '$node_title', '$current_userid', '$node_type', ".
				"'$node_time', '$node_time' $additional_field_values)";
		}
		else {
			// this is the path updating the node
			// this only allow to be done if the uid of the originial auther is same as this one..
			$node_row = mysql_fetch_row($result);
			$node_uid = $node_row[1];
			
			if($current_userid != $node_uid) {
				// this is not allowed and should be thrown soap fault..
				throw new WSFault("Sender", "The original author of the node is different ".
						" from the current user");
			}
		}
	}
	
	if($new_record) {
		// first insert the node and retrieve the node id
		mysql_query($node_insert_sql);
		$node_id = mysql_insert_id();
		
		
		// then update the revision..
		$sql = "INSERT INTO node_revisions (nid, uid, title, body, teaser, log, timestamp) ".
			"VALUES('$node_id', '$current_userid', '$node_title', '$content', '$teaser', ".
			"'Inserted from wsf/php service', '$node_time')";
		
		
		mysql_query($sql);
		// get the version id
		$version_id = mysql_insert_id();
		
		// update the vid field of the node..
		
		mysql_query("UPDATE node SET ".
				" vid = '$version_id' WHERE nid = '$node_id'");
		
		// there is a node comment statistic table corrosponding to each node
		
		$insert_node_comment_stats = "INSERT INTO node_comment_statistics (nid, last_comment_timestamp, last_comment_uid, ".
			"comment_count) VALUES ('$node_id', '$node_time', '$current_userid', '0')";
		
		mysql_query($insert_node_comment_stats);
	}
	else {
		// first update the revision..
		
		$sql = "INSERT INTO node_revisions (nid, uid, title, body, teaser, log, timestamp) ".
			"VALUES ('$node_id', '$current_userid', '$node_title', '$content', '$teaser', 'Inserted from wsf/php service', '$node_time')";
		
		mysql_query($sql);
		// get the version id
		$version_id = mysql_insert_id();
		
		// update the node..
		$update_key_value_pairs = "";
		if(!is_null($node_title)) {
			$update_key_value_pairs .= " title = '$node_title', ";
		}
		if(!is_null($moderate)) {
			$update_key_value_pairs .= " moderate = '$moderate', ";
		}
		if(!is_null($promote)) {
			$update_key_value_pairs .= " promote = '$promote', ";
		}
		
		mysql_query("UPDATE node SET $update_key_value_pairs uid = '$current_userid', changed = '$node_time', ".
				" vid= '$version_id' WHERE nid = '$node_id'");
				
				
	}
	
	return $node_id;
}


/**
 * Service function getCommentsForNode
 * @param object of getCommentsForNode $input 
 * @return object of getCommentsForNodeResponse 
 */
function getCommentsForNode($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type getCommentsForNode
    // NOTE: should return an object of type getCommentsForNodeResponse
	
	$node_id = $input->nodeId;
	
	global $db_config;
	
	$dbhost = $db_config["dbhost"];
	$dbname = $db_config["dbname"];
	$db_username = $db_config["username"];
	$db_password = $db_config["password"];
	
	
	$link=mysql_connect($dbhost,  $db_username,  $db_password);
	mysql_select_db($dbname, $link);
	
	$sql="SELECT c.cid, c.subject, c.comment, c.nid, c.timestamp, c.uid, c.name FROM comments c, node n ".
			"WHERE c.nid = $node_id and c.nid = n.nid and n.comment > 0";
	$result=mysql_query($sql);
	
	$comments = array();
	
	while ($row = mysql_fetch_array($result, MYSQL_NUM)) {
		
		$comment = new Comment();
		$comment->id = $row[0];
		$comment->title = $row[1];
		$comment->content = $row[2];
		$comment->nodeId = $row[3];
		$comment->time =  (int)$row[4];
		$comment->userId = $row[5];
		$comment->userName = $row[6];
		
		$comments []= $comment; 
	}
	
	$response = new getCommentsForNode();
	$response->return = $comments;
	
	return $response;
}


/**
 * Service function getCommentsByDuration
 * @param object of getCommentsByDuration $input 
 * @return object of getCommentsByDurationResponse 
 */
function getCommentsByDuration($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type getCommentsByDuration
    // NOTE: should return an object of type getCommentsByDurationResponse
	
	global $db_config;
	
	$dbhost = $db_config["dbhost"];
	$dbname = $db_config["dbname"];
	$db_username = $db_config["username"];
	$db_password = $db_config["password"];
	
	
	$link=mysql_connect($dbhost,  $db_username,  $db_password);
	mysql_select_db($dbname, $link);
	
	// extracting out the input
	
	$start_time = $input->startTime;
	$end_time  = $input->endTime;
	
	// the sql to execute
	
	// query only the accessible commments..
	$sql="SELECT c.cid, c.subject, c.comment, c.nid, c.timestamp, c.uid, c.name FROM comments c, ".
		"node n WHERE c.nid = n.nid and n.comment > 0 ".
		" and c.timestamp > '$start_time' and c.timestamp < '$end_time'";
		
	$result=mysql_query($sql);
	
	$comments = array();
	
	while ($row = mysql_fetch_array($result, MYSQL_NUM)) {
		
		$comment = new Comment();
		$comment->id = $row[0];
		$comment->title = $row[1];
		$comment->content = $row[2];
		$comment->nodeId = $row[3];
		$comment->time = (int)$row[4];
		$comment->userId = $row[5];
		$comment->userName = $row[6];
		
		$comments []= $comment; 
	}
	
	$response = new getCommentsResponse();
	$response->return = $comments;
	
	return $response;
}


/**
 * Service function getComments
 * @param object of getComments $input 
 * @return object of getCommentsResponse 
 */
function getComments($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type getComments
    // NOTE: should return an object of type getCommentsResponse
	
	global $db_config;
	
	$dbhost = $db_config["dbhost"];
	$dbname = $db_config["dbname"];
	$db_username = $db_config["username"];
	$db_password = $db_config["password"];
	
	// extracting out the limit value
	$limit = (int)$input->limit;
	if($limit <= 0 ) {
		return new WSFault("Sender", "Limit value should be > 0 ");
	}
	
	
	$link=mysql_connect($dbhost,  $db_username,  $db_password);
	mysql_select_db($dbname, $link);
	
	// query only the accessible commments..
	$sql="SELECT c.cid, c.subject, c.comment, c.nid, c.timestamp, c.uid, c.name FROM comments c, ".
		"node n WHERE c.nid = n.nid and n.comment > 0 ".
		"ORDER BY c.timestamp DESC LIMIT 0, $limit";
	$result=mysql_query($sql);
	
	$comments = array();
	
	while ($row = mysql_fetch_array($result, MYSQL_NUM)) {
		
		$comment = new Comment();
		$comment->id = $row[0];
		$comment->title = $row[1];
		$comment->content = $row[2];
		$comment->nodeId = $row[3];
		$comment->time = (int)$row[4];
		$comment->userId = $row[5];
		$comment->userName = $row[6];
		
		$comments []= $comment; 
	}
	
	$response = new getCommentsResponse();
	$response->return = $comments;
	
	return $response;
}


/**
 * Service function postComment
 * @param object of postComment $input 
 * @return object of postCommentResponse 
 */
function postComment($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type postComment
    // NOTE: should return an object of type postCommentResponse
	
	global $db_config;
	global $current_userid;
	global $current_username;
	
	// extracting out the db config
	$dbhost = $db_config["dbhost"];
	$dbname = $db_config["dbname"];
	$db_username = $db_config["username"];
	$db_password = $db_config["password"];
	
	
	// create the sql link
	$link=mysql_connect($dbhost,  $db_username,  $db_password);
	mysql_select_db($dbname, $link);
	
	// extracting out the input parameters

	$comment = $input->comment;

	$content = $comment->content;
	$comment_id = $comment->id;
	$node_id = $comment->nodeId;
	$comment_time = time();
	$title = $comment->title;
	

	// users id is taken from the username token
	$comment_user_id = $current_userid;
	$comment_user_name = $current_username;
	
	
	
	// check whether the node accesses allow commenting..
	if($node_id) {
		$is_allow_comment_sql = "SELECT comment FROM node where nid='$node_id'";
		$is_allow_comment_result = mysql_query($is_allow_comment_sql);
		
		if(mysql_num_rows($is_allow_comment_result) == 0) {
			throw new WSFault("Sender", "The node with node_id = $node_id doesn't exists ".
				"Please specify a valid node id for the comment");
		}
		
		$is_allow_comment_row = mysql_fetch_row($is_allow_comment_result);
		$is_allow_comment = $is_allow_comment_row[0];
		
		if($is_allow_comment < 2) {
			// not allowed to put comments..
			throw new WSFault("Sender", "Comments are not allowed for the node id = $node_id");
		}
	}
	
	if($title === null) {
		$title = substr($content, 0, 50);
	}
	
	$comment_inserting_updating_sql = "";
	if($comment_id != null) {
		
		if($node_id != null) {
			// if the commend id and node id both given, should check whether such thing exist..
			$is_comment_id_exist_sql = "SELECT cid FROM `comments` where `cid`='$comment_id' and `nid`='$node_id'";
			$is_comment_id_exist_result = mysql_query($is_comment_id_exist_sql);
			if(mysql_num_rows($is_comment_id_exist_result) == 0) {
				throw new WSFault("Sender", "Comment ID doesn't exist for the given node_id");
			}
			
		}
		else {
			
			$is_comment_id_exist_sql = "SELECT cid FROM `comments` where `cid`='$comment_id'";
			$is_comment_id_exist_result = mysql_query($is_comment_id_exist_sql);
			if(mysql_num_rows($is_comment_id_exist_result) == 0) {
				
				throw new WSFault("Sender", "The comment with the given id doesn't exists, ".
						"Creating a new comment requires a node id associated with it");
			}
		}
		
		// else we update the comment id
		$comment_updating_sql = "UPDATE `comments` SET `comment`='$content', `subject`='$title', ".
			"`timestamp` = '$comment_time' WHERE cid = '$comment_id'";
		mysql_query($comment_updating_sql);
		
		// updating the comment statistics
		
		$comment_inc_sql = "UPDATE `node_comment_statistics` SET `last_comment_timestamp` = '$comment_time', ".
			"`last_comment_uid` = '$comment_user_id' WHERE nid = '$node_id'";
		mysql_query($comment_inc_sql);
	}
	else {
		
		// the node id is necessory..
		if($node_id === null) {
			throw new WSFault("Sender", "Either nodeId or commentId should be not NULL");
		}
		
		// otherwise insert the values.
		
		// else we update the comment id
		$comment_inserting_sql = "INSERT INTO `comments` (`nid`, `uid`, `comment`, `subject`, `timestamp`, `name`) ".
					" VALUES ('$node_id', '$comment_user_id', '$content', '$title', '$comment_time', '$comment_user_name')";
		mysql_query($comment_inserting_sql);
		
		
		$comment_id = mysql_insert_id();
		
		// and we increment the number of comment for the node in node_comment_statistics..
		$comment_count_sql = "SELECT `comment_count` FROM `node_comment_statistics` WHERE `nid`='$node_id'";
		
		$comment_count_result = mysql_query($comment_count_sql);
		
		$comment_count_row = mysql_fetch_row($comment_count_result);
		$comment_count = $comment_count_row[0];
		
		$comment_count = (int)$comment_count + 1;
		
		$comment_inc_sql = "UPDATE node_comment_statistics SET `last_comment_timestamp` = '$comment_time', ".
			"`last_comment_uid` = '$comment_user_id', `comment_count` = '$comment_count' ".
				"WHERE `nid` = '$node_id'";
				
		mysql_query($comment_inc_sql);
	}
	
	$response = new postCommentResponse();
	
	$response->return = $comment_id;
	return $response;
}


/**
 * Service function getNodes
 * @param object of getNodes $input 
 * @return object of getNodesResponse 
 */
function getNodes($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type getNodes
    // NOTE: should return an object of type getNodesResponse
	
	global $db_config;
	
	$dbhost = $db_config["dbhost"];
	$dbname = $db_config["dbname"];
	$db_username = $db_config["username"];
	$db_password = $db_config["password"];
	
	// extracting out the limit value
	$limit = (int)$input->limit;
	
	
	if($limit <= 0 ) {
		return new WSFault("Sender", "Limit value should be > 0 ");
	}
	
	$link=mysql_connect($dbhost,  $db_username,  $db_password);
	mysql_select_db($dbname, $link);
	
	$sql="SELECT n.nid, n.title, nr.body, n.uid, n.created, n.promote, n.moderate, ".
		"n.comment, n.type ".
		"FROM node n, node_revisions nr where n.nid = nr.nid AND n.vid = nr.vid ".
		"ORDER BY n.created DESC LIMIT 0, $limit";
		
	$result=mysql_query($sql);
	
	$nodes = array();
	
	while ($row = mysql_fetch_array($result, MYSQL_NUM)) {
		
		$node = new Node();
		$node->id = $row[0];
		$node->title = $row[1];
		$node->content = $row[2];
		$node->userId = $row[3];
		$node->time = (int)$row[4];
		$node->promote = $row[5];
		$node->moderate = $row[6];
		$node->commentAccess = $row[7];
		$node->type = $row[8];
		
		$nodes []= $node; 
	}
	
	$response = new getNodesResponse();
	$response->return = $nodes;
	
	return $response;
}


/**
 * Service function getNodeById
 * @param object of getNodeById $input 
 * @return object of getNodeByIdResponse 
 */
function getNodeById($input) {
	// TODO: fill in the business logic
	// NOTE: $input is of type getNodeById
	// NOTE: should return an object of type getNodeByIdResponse
	
	global $db_config;
	
	$dbhost = $db_config["dbhost"];
	$dbname = $db_config["dbname"];
	$db_username = $db_config["username"];
	$db_password = $db_config["password"];
	
	// extracting out the id value
	$id = $input->id;
	
	
	if($id <= 0 ) {
		return new WSFault("Sender", "node id value should be > 0 ");
	}
	
	$link=mysql_connect($dbhost,  $db_username,  $db_password);
	mysql_select_db($dbname, $link);
	
	$sql="SELECT n.nid, n.title, nr.body, n.uid, n.created, n.promote, n.moderate, ".
		"n.comment, n.type ".
		"FROM node n, node_revisions nr where n.nid = nr.nid AND n.vid = nr.vid AND n.nid = '$id'";
	
	$result=mysql_query($sql);
	
	$node = new Node();
	if ($row = mysql_fetch_array($result, MYSQL_NUM)) {
		$node->id = $row[0];
		$node->title = $row[1];
		$node->content = $row[2];
		$node->userId = $row[3];
		$node->time = (int)$row[4];
		$node->promote = $row[5];
		$node->moderate = $row[6];
		$node->commentAccess = $row[7];
		$node->type = $row[8];
	}
	
	$response = new getNodeByIdResponse();
	$response->return = $node;
	
	return $response;
}


/**
 * Service function getNodesByDuration
 * @param object of getNodes $input 
 * @return object of getNodesByDurationResponse 
 */
function getNodesByDuration($input) {
	// TODO: fill in the business logic
	// NOTE: $input is of type getNodesByDuration
	// NOTE: should return an object of type getNodesByDurationResponse
	
	global $db_config;
	
	$dbhost = $db_config["dbhost"];
	$dbname = $db_config["dbname"];
	$db_username = $db_config["username"];
	$db_password = $db_config["password"];
	
	
	$link=mysql_connect($dbhost,  $db_username,  $db_password);
	mysql_select_db($dbname, $link);
	
	// extracting out the input
	
	$start_time = $input->startTime;
	$end_time  = $input->endTime;
	
	// the sql to executes
	$sql="SELECT n.nid, n.title, nr.body, n.uid, n.created, n.promote, n.moderate, ".
		"n.comment, n.type ".
		" FROM node n, node_revisions nr where n.nid = nr.nid AND n.vid = nr.vid ".
		" and n.created > '$start_time' and n.created < '$end_time'";
		
		
	$result=mysql_query($sql);
	
	$nodes = array();
	
	while ($row = mysql_fetch_array($result, MYSQL_NUM)) {
		
		$node = new Node();
		$node->id = $row[0];
		$node->title = $row[1];
		$node->content = $row[2];
		$node->userId = $row[3];
		$node->time = (int)$row[4];
		$node->promote = $row[5];
		$node->moderate = $row[6];
		$node->commentAccess = $row[7];
		$node->type = $row[8];
		
		$nodes []= $node; 
	}
	
	$response = new getNodesByDurationResponse();
	$response->return = $nodes;
	
	return $response;
}


/**
 * Service function login
 * @param object of login $input 
 * @return object of loginResponse 
 */
function login($input) {
	// if the function is called, 
	// the username token should be already validated
	$response = new loginResponse();
	$response->return = 1;
	return $response;
}

/**
 * call back function.
 * verify the validity of user enterd password with
 * the actual password which is kept in the database.
 */
function get_password($username)
{
	global $current_username;
	global $current_userid;
	global $db_config;
	
	$dbhost = $db_config["dbhost"];
	$dbname = $db_config["dbname"];
	$db_username = $db_config["username"];
	$db_password = $db_config["password"];
	
	
	$link=mysql_connect($dbhost,  $db_username,  $db_password);
	mysql_select_db($dbname, $link);
	
	$sql="SELECT uid, pass FROM `users` WHERE `name` = '".$username."'";
	$result=mysql_query($sql);
	
	list($userid, $password)=mysql_fetch_row($result);
	
	if($password) {
		$current_username = $username;
		$current_userid = $userid;
		return $password;
	}
	else {
		$current_username = "";
		$current_userid = 0;
		return NULL;
	}
}

$sec_token = new WSSecurityToken(array(
			"passwordCallback" => "get_password",
			"passwordType" => "plain"));

// define the operations map
$operations = array(
    "postStory" => "postStory",
    "postPage" => "postPage",
    "getCommentsForNode" => "getCommentsForNode",
    "getComments" => "getComments",
    "getCommentsByDuration" => "getCommentsByDuration",
    "postComment" => "postComment",
    "getNodes" => "getNodes",
    "login" => "login",
    "getNodeById" => "getNodeById",
    "getNodesByDuration" => "getNodesByDuration");

// define the actions => operations map
$actions = array(
    "urn:postStory" => "postStory",
    "urn:postPage" => "postPage",
    "urn:getCommentsForNode" => "getCommentsForNode",
    "urn:getComments" => "getComments",
    "urn:getCommentsByDuration" => "getCommentsByDuration",
    "urn:postComment" => "postComment",
    "urn:getNodes" => "getNodes",
    "urn:login" => "login",
    "urn:getNodeById" => "getNodeById",
    "urn:getNodesByDuration" => "getNodesByDuration");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"DrupalAPI.wsdl",
		"actions" => $actions,
		"securityToken" => $sec_token,
        "classmap" => $class_map,
        "operations" => $operations));

// process client requests and reply 
$service->reply();

?>
