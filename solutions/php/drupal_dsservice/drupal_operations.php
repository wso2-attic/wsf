<?php


// ============= CURD operations for node table ==========================
// =======================================================================


// ============= READ - Get nodes by duration operation ========================

$output_format = array(
		"resultElement" => "nodes",
		"rowElement" => "node",
		"elements" => array(
			"nid" => "nid",
			"type" => "type",
			"body" => "body",
			"title" => "title"));

$input_format = array("startTime" => "STRING", "endTime" => "STRING" );

$sql = "SELECT n.nid, n.type, n.title, SUBSTRING(nr.body, 1, 200) as body FROM {$db_prefix}node n, {$db_prefix}node_revisions nr where n.nid = nr.nid".
		" and n.created > UNIX_TIMESTAMP(?) and n.created < UNIX_TIMESTAMP(?)";


$get_nodes_by_duration_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_nodes_by_duration_url = array("HTTPMethod" => "GET", "RESTLocation" => "nodesByDuration/{startTime}/to/{endTime}");

// ==============================================================================

// ============= READ - Get nodes count by duration operation ========================

$output_format = array(
		"resultElement" => "nodes",
		"rowElement" => "count",
		"texts" => array("count(*)"));

$input_format = array("startTime" => "STRING", "endTime" => "STRING" );

$sql = "SELECT count(*) FROM {$db_prefix}node n, {$db_prefix}node_revisions nr where n.nid = nr.nid".
	" and n.created > UNIX_TIMESTAMP(?) and n.created < UNIX_TIMESTAMP(?)";

$get_nodes_count_by_duration_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_nodes_count_by_duration_url = array("HTTPMethod" => "GET", "RESTLocation" => "nodesCountByDuration/{startTime}/to/{endTime}");

// ==============================================================================


// ============= READ - Get nodes by id operation ========================

$output_format = array(
		"resultElement" => "nodes",
		"rowElement" => "node",
		"elements" => array(
			"nid" => "nid",
			"type" => "type",
			"body" => "body",
			"title" => "title"));

$input_format = array("nid" => "INTEGER");

$sql = "SELECT n.nid, n.type, n.title, SUBSTRING(nr.body, 1, 200) as body FROM {$db_prefix}node n, {$db_prefix}node_revisions nr where n.nid = nr.nid and n.nid = ?";

$get_node_by_id_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_node_by_id_url = array("HTTPMethod" => "GET", "RESTLocation" => "nodes/{nid}");

// ==============================================================================

// ============= READ - Get nodes operation ==============================

$output_format = array(
		"resultElement" => "nodes",
		"rowElement" => "node",
		"elements" => array(
			"nid" => "nid",
			"type" => "type",
			"body" => "body",
			"title" => "title"));

$sql = "SELECT n.nid, n.type, n.title, SUBSTRING(nr.body, 1, 200) as body FROM {$db_prefix}node n, ".
	"{$db_prefix}node_revisions nr ".
	"where n.nid = nr.nid ".
	"ORDER BY n.created DESC LIMIT 0, 5";

$get_nodes_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_nodes_url = array("HTTPMethod" => "GET", "RESTLocation" => "nodes");


// ==============================================================================

// ============= READ - Get comments operation ==============================

$output_format = array(
		"resultElement" => "comments",
		"rowElement" => "comment",
		"elements" => array(
			"cid" => "cid",
			"subject" => "subject",
			"comment" => "comment",
			"name" => "name"));

$sql = "SELECT c.cid, c.subject, SUBSTRING(c.comment, 1, 200) as comment, c.name FROM {$db_prefix}comments c ".
	"ORDER BY c.timestamp DESC LIMIT 0, 5";

$get_comments_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_comments_url = array("HTTPMethod" => "GET", "RESTLocation" => "comments");


// ==============================================================================


// ============= READ - Get comments by node id operation ========================

$output_format = array(
		"resultElement" => "comments",
		"rowElement" => "comment",
		"elements" => array(
			"cid" => "cid",
			"subject" => "subject",
			"comment" => "comment",
			"name" => "name"));

$input_format = array("nid" => "INTEGER", "cid" => "INTEGER");

$sql = "SELECT c.cid, c.subject, SUBSTRING(c.comment, 1, 200) as comment, c.name FROM {$db_prefix}comments c where c.nid = ? and c.cid = ?";

$get_comments_by_node_id_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_comments_by_node_id_url = array("HTTPMethod" => "GET", "RESTLocation" => "nodes/{nid}/comments/{cid}");

// ==============================================================================


// ============= READ - Get comments by comment id operation ========================

$output_format = array(
		"resultElement" => "comments",
		"rowElement" => "comment",
		"elements" => array(
			"cid" => "cid",
			"subject" => "subject",
			"comment" => "comment",
			"name" => "name"));

$input_format = array("cid" => "INTEGER");

$sql = "SELECT c.cid, c.subject, SUBSTRING(c.comment, 1, 200) as comment, c.name FROM {$db_prefix}comments c where c.cid = ?";

$get_comment_by_comment_id_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_comment_by_comment_id_url = array("HTTPMethod" => "GET", "RESTLocation" => "comments/{cid}");

// ==============================================================================


// ============= READ - Get comments by duration operation ========================

$output_format = array(
		"resultElement" => "comments",
		"rowElement" => "comment",
		"elements" => array(
			"cid" => "cid",
			"subject" => "subject",
			"comment" => "comment",
			"name" => "name"));

$input_format = array("startTime" => "STRING", "endTime" => "STRING" );

$sql = "SELECT c.cid, c.subject, SUBSTRING(c.comment, 1, 200) as comment, c.name FROM {$db_prefix}comments c WHERE ".
	" c.timestamp > UNIX_TIMESTAMP(?) and c.timestamp < UNIX_TIMESTAMP(?)";

$get_comments_by_duration_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_comments_by_duration_url = array("HTTPMethod" => "GET", "RESTLocation" => "commentsByDuration/{startTime}/to/{endTime}");

// ==============================================================================



// ============= READ - Get comments Count by duration operation ========================


$output_format = array(
		"resultElement" => "comments",
		"rowElement" => "count",
		"texts" => array("count(*)"));

$input_format = array("startTime" => "STRING", "endTime" => "STRING" );

$sql = "SELECT count(*) FROM {$db_prefix}comments c WHERE ".
	" c.timestamp > UNIX_TIMESTAMP(?) and c.timestamp < UNIX_TIMESTAMP(?)";

$get_comments_count_by_duration_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_comments_count_by_duration_url = array("HTTPMethod" => "GET", "RESTLocation" => "commentsCountByDuration/{startTime}/to/{endTime}");

// ==============================================================================



// ============= READ - Get nodes count per Day for 24 Hours operation ========================

$output_format = array(
		"resultElement" => "nodes",
		"rowElement" => "stat",
		"elements" => array(
			"count" => "count(*)",
			"priorHour" => "priorHour",
			"date" => "created"));


$sql = "SELECT ROUND((UNIX_TIMESTAMP(NOW()) - created)/(60*60)) as priorHour, created, count(*) FROM {$db_prefix}node ".
	"WHERE ((UNIX_TIMESTAMP(NOW()) - created)/(60*60)) < 24 GROUP BY priorHour";

$get_nodes_count_per_hour_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_nodes_count_per_hour_url = array("HTTPMethod" => "GET", "RESTLocation" => "nodesCountPerHour");

// ==============================================================================



// ============= READ - Get nodes count per Day for 30 Days operation ========================

$output_format = array(
		"resultElement" => "nodes",
		"rowElement" => "stat",
		"elements" => array(
			"count" => "count(*)",
			"priorDate" => "priorDate",
			"date" => "created"));


$sql = "SELECT ROUND((UNIX_TIMESTAMP(NOW()) - created)/(24*60*60)) as priorDate, created, count(*) FROM {$db_prefix}node ".
	"WHERE ((UNIX_TIMESTAMP(NOW()) - created)/(24*60*60)) < 30 GROUP BY priorDate";

$get_nodes_count_per_day_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_nodes_count_per_day_url = array("HTTPMethod" => "GET", "RESTLocation" => "nodesCountPerDay");

// ==============================================================================



// ============= READ - Get nodes count per month for 12 month operation ========================

$output_format = array(
		"resultElement" => "nodes",
		"rowElement" => "stat",
		"elements" => array(
			"count" => "count(*)",
			"priorMonth" => "priorMonth",
			"date" => "created"));


$sql = "SELECT ROUND((UNIX_TIMESTAMP(NOW()) - created)/(24*60*60*30)) as priorMonth, created, count(*) FROM {$db_prefix}node ".
	"WHERE ((UNIX_TIMESTAMP(NOW()) - created)/(24*60*60*30)) < 12 GROUP BY priorMonth";

$get_nodes_count_per_month_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_nodes_count_per_month_url = array("HTTPMethod" => "GET", "RESTLocation" => "nodesCountPerMonth");

// ==============================================================================



// ============= READ - Get nodes count per year for 5 year operation ========================

$output_format = array(
		"resultElement" => "nodes",
		"rowElement" => "stat",
		"elements" => array(
			"count" => "count(*)",
			"priorYear" => "priorYear",
			"date" => "created"));


$sql = "SELECT ROUND((UNIX_TIMESTAMP(NOW()) - created)/(24*60*60*365)) as priorYear, created, count(*) FROM {$db_prefix}node ".
	"WHERE ((UNIX_TIMESTAMP(NOW()) - created)/(24*60*60*365)) < 5 GROUP BY priorYear";

$get_nodes_count_per_year_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_nodes_count_per_year_url = array("HTTPMethod" => "GET", "RESTLocation" => "nodesCountPerYear");

// ==============================================================================




// ============= READ - Get comments count per Hour for 24 Hours operation ========================

$output_format = array(
		"resultElement" => "comments",
		"rowElement" => "stat",
		"elements" => array(
			"count" => "count(*)",
			"priorHour" => "priorHour",
			"date" => "timestamp"));


$sql = "SELECT ROUND((UNIX_TIMESTAMP(NOW()) - timestamp)/(60*60)) as priorHour, timestamp, count(*) FROM {$db_prefix}comments ".
	"WHERE ((UNIX_TIMESTAMP(NOW()) - timestamp)/(60*60)) < 24 GROUP BY priorHour";

$get_comments_count_per_hour_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_comments_count_per_hour_url = array("HTTPMethod" => "GET", "RESTLocation" => "commentsCountPerHour");





// ============= READ - Get comments count per Day for 30 Days operation ========================

$output_format = array(
		"resultElement" => "comments",
		"rowElement" => "stat",
		"elements" => array(
			"count" => "count(*)",
			"priorDate" => "priorDate",
			"date" => "timestamp"));


$sql = "SELECT ROUND((UNIX_TIMESTAMP(NOW()) - timestamp)/(24*60*60)) as priorDate, timestamp, count(*) FROM {$db_prefix}comments ".
	"WHERE ((UNIX_TIMESTAMP(NOW()) - timestamp)/(24*60*60)) < 30 GROUP BY priorDate";

$get_comments_count_per_day_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_comments_count_per_day_url = array("HTTPMethod" => "GET", "RESTLocation" => "commentsCountPerDay");

// ==============================================================================



// ============= READ - Get comments count per month for 12 month operation ========================

$output_format = array(
		"resultElement" => "comments",
		"rowElement" => "stat",
		"elements" => array(
			"count" => "count(*)",
			"priorMonth" => "priorMonth",
			"date" => "timestamp"));


$sql = "SELECT ROUND((UNIX_TIMESTAMP(NOW()) - timestamp)/(24*60*60*30)) as priorMonth, timestamp, count(*) FROM {$db_prefix}comments ".
	"WHERE ((UNIX_TIMESTAMP(NOW()) - timestamp)/(24*60*60*30)) < 12 GROUP BY priorMonth";

$get_comments_count_per_month_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_comments_count_per_month_url = array("HTTPMethod" => "GET", "RESTLocation" => "commentsCountPerMonth");

// ==============================================================================



// ============= READ - Get comments count per year for 5 year operation ========================

$output_format = array(
		"resultElement" => "comments",
		"rowElement" => "stat",
		"elements" => array(
			"count" => "count(*)",
			"priorYear" => "priorYear",
			"date" => "timestamp"));


$sql = "SELECT ROUND((UNIX_TIMESTAMP(NOW()) - timestamp)/(24*60*60*365)) as priorYear, timestamp, count(*) FROM {$db_prefix}comments ".
	"WHERE ((UNIX_TIMESTAMP(NOW()) - timestamp)/(24*60*60*365)) < 5 GROUP BY priorYear";

$get_comments_count_per_year_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_comments_count_per_year_url = array("HTTPMethod" => "GET", "RESTLocation" => "commentsCountPerYear");

// ==============================================================================




// ============= READ - Get users posted a node for the given duration ========================

$output_format = array(
		"resultElement" => "users",
		"rowElement" => "user",
		"elements" => array(
			"name" => "name",
			"email" => "mail"));

$input_format = array("startTime" => "STRING", "endTime" => "STRING");

$sql = "SELECT u.name, u.mail FROM {$db_prefix}node n, {$db_prefix}users u WHERE n.uid = u.uid".
	" and n.created > UNIX_TIMESTAMP(?) and n.created < UNIX_TIMESTAMP(?) GROUP BY u.name";

$get_users_posted_duration_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_users_posted_duration_url = array("HTTPMethod" => "GET", "RESTLocation" => "usersPosted/{startTime}/to/{endTime}");

// ==============================================================================


// ============= READ - Get the count of the users posted a node for the given duration ========================

$output_format = array(
		"resultElement" => "users",
		"rowElement" => "count",
		"texts" => array("count(*)"));

$input_format = array("startTime" => "STRING", "endTime" => "STRING");

$sql = "SELECT count(*) FROM {$db_prefix}node n, {$db_prefix}users u WHERE n.uid = u.uid".
	" and n.created > UNIX_TIMESTAMP(?) and n.created < UNIX_TIMESTAMP(?) GROUP BY u.name";

$get_users_posted_count_duration_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_users_posted_count_duration_url = array("HTTPMethod" => "GET", "RESTLocation" => "usersPostedCount/{startTime}/to/{endTime}");

// ==============================================================================



// ============= READ - Get the nodes posted by a user for the given duration ========================
$output_format = array(
		"resultElement" => "nodes",
		"rowElement" => "node",
		"elements" => array(
			"nid" => "nid",
			"type" => "type",
			"body" => "body",
			"title" => "title"));

$input_format = array( "user" => "INT", "startTime" => "STRING", "endTime" => "STRING");

$sql = "SELECT n.nid, n.type, n.title, SUBSTRING(nr.body, 1, 200) as body FROM {$db_prefix}node n, {$db_prefix}node_revisions nr where n.nid = nr.nid".
	"  AND n.uid = ? AND n.created > UNIX_TIMESTAMP(?) AND n.created < UNIX_TIMESTAMP(?)";

$get_nodes_posted_by_user_per_duration_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_nodes_posted_by_user_per_duration_url = array("HTTPMethod" => "GET", "RESTLocation" => "usersPosts/{user}/{startTime}/to/{endTime}");

// ==============================================================================




// ============= READ - Get users posted a comment for the given duration ========================

$output_format = array(
		"resultElement" => "users",
		"rowElement" => "user",
		"elements" => array(
			"name" => "name",
			"email" => "mail"));

$input_format = array("startTime" => "STRING", "endTime" => "STRING");

$sql = "SELECT u.name, u.mail FROM {$db_prefix}comments c, {$db_prefix}users u WHERE u.uid = c.uid".
	" AND c.timestamp > UNIX_TIMESTAMP(?) AND c.timestamp < UNIX_TIMESTAMP(?) GROUP BY u.name";
	

$get_users_commented_duration_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_users_commented_duration_url = array("HTTPMethod" => "GET", "RESTLocation" => "usersCommented/{startTime}/to/{endTime}");

// ==============================================================================


// ============= READ - Get the count of users posted a comment for the given duration ========================

$output_format = array(
		"resultElement" => "users",
		"rowElement" => "count",
		"texts" => array("count(*)"));

$input_format = array("startTime" => "STRING", "endTime" => "STRING");

$sql = "SELECT count(*) FROM {$db_prefix}comments c, {$db_prefix}users u WHERE u.uid = c.uid".
	" AND c.timestamp > UNIX_TIMESTAMP(?) AND c.timestamp < UNIX_TIMESTAMP(?) GROUP BY u.name";
	

$get_users_commented_count_duration_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_users_commented_count_duration_url = array("HTTPMethod" => "GET", "RESTLocation" => "usersCommentedCount/{startTime}/to/{endTime}");

// ==============================================================================




// ============= READ - Get the comments posted by a user for the given duration ========================
$output_format = array(
		"resultElement" => "comments",
		"rowElement" => "comment",
		"elements" => array(
			"cid" => "cid",
			"subject" => "subject",
			"comment" => "comment",
			"name" => "name"));

$input_format = array("user" => "INT", "startTime" => "STRING", "endTime" => "STRING" );

$sql = "SELECT c.cid, c.subject, SUBSTRING(c.comment, 1, 200) as comment, c.name FROM {$db_prefix}comments c WHERE ".
	" c.uid = ? AND c.timestamp > UNIX_TIMESTAMP(?) and c.timestamp < UNIX_TIMESTAMP(?)";

$get_comments_posted_by_user_per_duration_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_comments_posted_by_user_per_duration_url = array("HTTPMethod" => "GET", "RESTLocation" => "usersComments/{user}/{startTime}/to/{endTime}");

// ==============================================================================




// list of operations
$nodes_operations = array(
		"getNodes" => $get_nodes_op,
		"getComments" => $get_comments_op,
		"getCommentsByNodeId" => $get_comments_by_node_id_op,
		"getNodeById" => $get_node_by_id_op,
		"getNodesByDuration" => $get_nodes_by_duration_op,
		"getNodesCountByDuration" => $get_nodes_count_by_duration_op,
		"getCommentByCommentId" => $get_comment_by_comment_id_op,
		"getCommentsByDuration" => $get_comments_by_duration_op,
		"getCommentsCountByDuration" => $get_comments_count_by_duration_op,
		
		"getNodesCountPerHour" => $get_nodes_count_per_hour_op,
		"getNodesCountPerDay" => $get_nodes_count_per_day_op,
		"getNodesCountPerMonth" => $get_nodes_count_per_month_op,
		"getNodesCountPerYear" => $get_nodes_count_per_year_op,
		
		"getCommentsCountPerHour" => $get_comments_count_per_hour_op,
		"getCommentsCountPerDay" => $get_comments_count_per_day_op,
		"getCommentsCountPerMonth" => $get_comments_count_per_month_op,
		"getCommentsCountPerYear" => $get_comments_count_per_year_op,
		
		"getUsersPostedByDuration" => $get_users_posted_duration_op,
		"getUsersPostedCountByDuration" => $get_users_posted_count_duration_op,
		"getNodesPostedByUserByDuration" => $get_nodes_posted_by_user_per_duration_op,
		"getUsersCommentedByDuration" => $get_users_commented_duration_op,
		"getUsersCommentedCountByDuration" => $get_users_commented_count_duration_op,
		"getCommentsPostedByUserByDuration" => $get_comments_posted_by_user_per_duration_op,
		);

// list of rest url mappping (operation => url)
$nodes_restmap = array(
		"getNodes" => $get_nodes_url,
		"getComments" => $get_comments_url,
		"getCommentsByNodeId" => $get_comments_by_node_id_url,
		"getNodeById" => $get_node_by_id_url,
		"getNodesByDuration" => $get_nodes_by_duration_url,
		"getNodesCountByDuration" => $get_nodes_count_by_duration_url,
		"getCommentByCommentId" => $get_comment_by_comment_id_url,
		"getCommentsByDuration" => $get_comments_by_duration_url,
		"getCommentsCountByDuration" => $get_comments_count_by_duration_url,
		
		"getNodesCountPerHour" => $get_nodes_count_per_hour_url,
		"getNodesCountPerDay" => $get_nodes_count_per_day_url,
		"getNodesCountPerMonth" => $get_nodes_count_per_month_url,
		"getNodesCountPerYear" => $get_nodes_count_per_year_url,
		
		"getCommentsCountPerHour" => $get_comments_count_per_hour_url,
		"getCommentsCountPerDay" => $get_comments_count_per_day_url,
		"getCommentsCountPerMonth" => $get_comments_count_per_month_url,
		"getCommentsCountPerYear" => $get_comments_count_per_year_url,
		
		"getUsersPostedByDuration" => $get_users_posted_duration_url,
		"getUsersPostedCountByDuration" => $get_users_posted_count_duration_url,
		"getNodesPostedByUserByDuration" => $get_nodes_posted_by_user_per_duration_url,
		"getUsersCommentedByDuration" => $get_users_commented_duration_url,
		"getUsersCommentedCountByDuration" => $get_users_commented_count_duration_url,
		"getCommentsPostedByUserByDuration" => $get_comments_posted_by_user_per_duration_url,
		);


?>
