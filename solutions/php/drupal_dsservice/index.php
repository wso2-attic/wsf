<html>
<head>
<?php
$SERVICE_URL = "http://localhost/solutions/druapl_dsservice/dsservice_drupal.php";
?>
<title>
DRUPAL Data Service Client
</title>

<script lanaguge="javascript">
// some functions to update the value with the user clicks
function update_getNodeById() {
    var name = document.getElementById('select_getNodeById').value;

    var link = document.getElementById("get_node_by_id_link");
    link.innerHTML = "<?php echo $SERVICE_URL ?>/nodes/" + name;
    link.setAttribute("href", "<?php echo $SERVICE_URL ?>/nodes/" + name);
}

function update_getNodesByDuration(){
    var start_year = document.getElementById('select_getNodesByDurationYear').value;
    var start_month = document.getElementById('select_getNodesByDurationMonth').value;
    var start_day = document.getElementById('select_getNodesByDurationDay').value;

    var end_year = document.getElementById('select_getNodesByDurationEndYear').value;
    var end_month = document.getElementById('select_getNodesByDurationEndMonth').value;
    var end_day = document.getElementById('select_getNodesByDurationEndDay').value;

    var link = document.getElementById("get_nodes_by_duration_link");
	var link_value = "<?php echo $SERVICE_URL ?>/nodesByDuration/" +
				 start_year + "-" + start_month + "-" + start_day + "/to/" + 
				 end_year + "-" + end_month + "-" + end_day;
    link.innerHTML = link_value;
    link.setAttribute("href", link_value);
}


function update_getNodesCountByDuration(){
    var start_year = document.getElementById('select_getNodesCountByDurationYear').value;
    var start_month = document.getElementById('select_getNodesCountByDurationMonth').value;
    var start_day = document.getElementById('select_getNodesCountByDurationDay').value;

    var end_year = document.getElementById('select_getNodesCountByDurationEndYear').value;
    var end_month = document.getElementById('select_getNodesCountByDurationEndMonth').value;
    var end_day = document.getElementById('select_getNodesCountByDurationEndDay').value;

    var link = document.getElementById("get_nodes_count_by_duration_link");
	var link_value = "<?php echo $SERVICE_URL ?>/nodesCountByDuration/" +
				 start_year + "-" + start_month + "-" + start_day + "/to/" + 
				 end_year + "-" + end_month + "-" + end_day;
    link.innerHTML = link_value;
    link.setAttribute("href", link_value);
}

// the same set of functions for comment

function update_getCommentById() {
    var name = document.getElementById('select_getCommentById').value;

    var link = document.getElementById("get_comment_by_id_link");
    link.innerHTML = "<?php echo $SERVICE_URL ?>/comments/" + name;
    link.setAttribute("href", "<?php echo $SERVICE_URL ?>/comments/" + name);
}

function update_getCommentsByDuration(){
    var start_year = document.getElementById('select_getCommentsByDurationYear').value;
    var start_month = document.getElementById('select_getCommentsByDurationMonth').value;
    var start_day = document.getElementById('select_getCommentsByDurationDay').value;

    var end_year = document.getElementById('select_getCommentsByDurationEndYear').value;
    var end_month = document.getElementById('select_getCommentsByDurationEndMonth').value;
    var end_day = document.getElementById('select_getCommentsByDurationEndDay').value;

    var link = document.getElementById("get_comments_by_duration_link");
	var link_value = "<?php echo $SERVICE_URL ?>/commentsByDuration/" +
				 start_year + "-" + start_month + "-" + start_day + "/to/" + 
				 end_year + "-" + end_month + "-" + end_day;
    link.innerHTML = link_value;
    link.setAttribute("href", link_value);
}


function update_getCommentsCountByDuration(){
    var start_year = document.getElementById('select_getCommentsCountByDurationYear').value;
    var start_month = document.getElementById('select_getCommentsCountByDurationMonth').value;
    var start_day = document.getElementById('select_getCommentsCountByDurationDay').value;

    var end_year = document.getElementById('select_getCommentsCountByDurationEndYear').value;
    var end_month = document.getElementById('select_getCommentsCountByDurationEndMonth').value;
    var end_day = document.getElementById('select_getCommentsCountByDurationEndDay').value;

    var link = document.getElementById("get_comments_count_by_duration_link");
	var link_value = "<?php echo $SERVICE_URL ?>/commentsCountByDuration/" +
				 start_year + "-" + start_month + "-" + start_day + "/to/" + 
				 end_year + "-" + end_month + "-" + end_day;
    link.innerHTML = link_value;
    link.setAttribute("href", link_value);
}

</script>

<link href="style.css" rel="stylesheet" type="text/css"/>

</head>
<body>
<h1>
DRUPAL Data Service Client
</h1>

<p>
Click the URLs to see how each URL maps to different data pieces.
</p>

<p>
<ul>
<!-- rendering of the table -->
<table border="1px">
<tr id="title">
<td width="150px">
Operation
</td>
<td width="250px">
Parameters
</td>
<td width="450px">
Url
</td>
</tr>

<!--get all nodes -->
<tr>
<td>
Get All Nodes 
</td>
<td>
No Parameters
</td>
<td>
<a target="_blank" href="<?php echo $SERVICE_URL ?>/nodes"><?php echo $SERVICE_URL ?>/nodes</a>
</td>

<!--get node by id-->
<!-- first we retireve the information from the get all node operation  -->
<?php
$dom = new DOMDocument();
$dom->load("{$SERVICE_URL}/nodes");
$node_id_elements = $dom->getElementsByTagName("nid");

$i = 0;
$node_first_id = "";
$node_options = "";
foreach($node_id_elements as $node_element){
    $node_id = $node_element->nodeValue;
    $selected = "";
    if($i == 0) {
        $node_first_id = $node_id;
        $selected = " selected=\"true\"";
		$i ++;
    }
    $node_options .=  "<option $selected value=\"$node_id\">$node_id</option>";
}

?>
<tr>
<td>
Get Node By Id
</td>
<td>
Name:

<select id="select_getNodeById" onchange="javascript:update_getNodeById()">
<?php echo $node_options;?>
</select>
</td>
<td>
<a target="_blank" id="get_node_by_id_link" href="<?php echo $SERVICE_URL ?>/nodes/<?php echo $node_first_id ?>"><?php echo $SERVICE_URL ?>/nodes/<?php echo $node_first_id ?></a>
</td>

<!--get all nodes by duration -->
<tr>
<td>
Get Nodes By Duration
</td>
<td>
<div>
<?php 
$default_start_date = time() - (7 * 24 * 60 * 60); // a week ago
$default_start_date_arr = getdate($default_start_date);

$default_end_date = time(); // now
$default_end_date_arr = getdate($default_end_date);

?>
Start Date:

<select id="select_getNodesByDurationYear" onchange="javascript:update_getNodesByDuration()">
<?php
for($year = 2000; $year < 2050; $year++ ) {
	$selected = "";
	if($year == $default_start_date_arr["year"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$year\">$year</option>";
}
?>
</select>
<select id="select_getNodesByDurationMonth" onchange="javascript:update_getNodesByDuration()">
<?php
for($month = 1; $month <= 12; $month ++ ) {
	$selected = "";
	if($month == $default_start_date_arr["mon"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$month\">$month</option>";
}
?>
</select>
<select id="select_getNodesByDurationDay" onchange="javascript:update_getNodesByDuration()">
<?php
for($day = 1; $day <= 31; $day ++ ) {
	$selected = "";
	if($day == $default_start_date_arr["mday"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$day\">$day</option>";
}
?>
</select>
</div>
<!-- end date -->
<div>
End Date:

<select id="select_getNodesByDurationEndYear" onchange="javascript:update_getNodesByDuration()">
<?php
for($year = 2000; $year < 2050; $year++ ) {
	$selected = "";
	if($year == $default_end_date_arr["year"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$year\">$year</option>";
}
?>
</select>
<select id="select_getNodesByDurationEndMonth" onchange="javascript:update_getNodesByDuration()">
<?php
for($month = 1; $month <= 12; $month ++ ) {
	$selected = "";
	if($month == $default_end_date_arr["mon"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$month\">$month</option>";
}
?>
</select>
<select id="select_getNodesByDurationEndDay" onchange="javascript:update_getNodesByDuration()">
<?php
for($day = 1; $day <= 31; $day ++ ) {
	$selected = "";
	if($day == $default_end_date_arr["mday"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$day\">$day</option>";
}
?>
</select>
</div>
</td>
<td>
<a target="_blank" id="get_nodes_by_duration_link" href="<?php echo $SERVICE_URL ?>/nodesByDuration/xxx/to/yyy"><?php echo $SERVICE_URL ?>/nodesByDuration/xxx/to/yyy</a>
</td>

</tr>

<!--get nodes count by duration -->
<tr>
<td>
Get Nodes Count By Duration
</td>
<td>
<div>
<?php 
$default_start_date = time() - (7 * 24 * 60 * 60); // a week ago
$default_start_date_arr = getdate($default_start_date);

$default_end_date = time(); // now
$default_end_date_arr = getdate($default_end_date);

?>
Start Date:

<select id="select_getNodesCountByDurationYear" onchange="javascript:update_getNodesCountByDuration()">
<?php
for($year = 2000; $year < 2050; $year++ ) {
	$selected = "";
	if($year == $default_start_date_arr["year"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$year\">$year</option>";
}
?>
</select>
<select id="select_getNodesCountByDurationMonth" onchange="javascript:update_getNodesCountByDuration()">
<?php
for($month = 1; $month <= 12; $month ++ ) {
	$selected = "";
	if($month == $default_start_date_arr["mon"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$month\">$month</option>";
}
?>
</select>
<select id="select_getNodesCountByDurationDay" onchange="javascript:update_getNodesCountByDuration()">
<?php
for($day = 1; $day <= 31; $day ++ ) {
	$selected = "";
	if($day == $default_start_date_arr["mday"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$day\">$day</option>";
}
?>
</select>
</div>
<!-- end date -->
<div>
End Date:

<select id="select_getNodesCountByDurationEndYear" onchange="javascript:update_getNodesCountByDuration()">
<?php
for($year = 2000; $year < 2050; $year++ ) {
	$selected = "";
	if($year == $default_end_date_arr["year"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$year\">$year</option>";
}
?>
</select>
<select id="select_getNodesCountByDurationEndMonth" onchange="javascript:update_getNodesCountByDuration()">
<?php
for($month = 1; $month <= 12; $month ++ ) {
	$selected = "";
	if($month == $default_end_date_arr["mon"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$month\">$month</option>";
}
?>
</select>
<select id="select_getNodesCountByDurationEndDay" onchange="javascript:update_getNodesCountByDuration()">
<?php
for($day = 1; $day <= 31; $day ++ ) {
	$selected = "";
	if($day == $default_end_date_arr["mday"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$day\">$day</option>";
}
?>
</select>
</div>
</td>
<td>
<a target="_blank" id="get_nodes_count_by_duration_link" href="<?php echo $SERVICE_URL ?>/nodesCountByDuration/xxx/to/yyy"><?php echo $SERVICE_URL ?>/nodesCountByDuration/xxx/to/yyy</a>
</td>

</tr>


<!-- the same set of operations for comments ->
</tr>

<!--get all comments -->
<tr>
<td>
Get All Comments 
</td>
<td>
No Parameters
</td>
<td>
<a target="_blank" href="<?php echo $SERVICE_URL ?>/comments"><?php echo $SERVICE_URL ?>/comments</a>
</td>

<!--get comment by id-->
<!-- first we retireve the information from the get all comment operation  -->
<?php
$dom = new DOMDocument();
$dom->load("{$SERVICE_URL}/comments");
$comment_id_elements = $dom->getElementsByTagName("cid");

$i = 0;
$comment_first_id = "";
$comment_options = "";
foreach($comment_id_elements as $comment_element){
    $comment_id = $comment_element->nodeValue;
    $selected = "";
    if($i == 0) {
        $comment_first_id = $comment_id;
        $selected = " selected=\"true\"";
		$i ++;
    }
    $comment_options .=  "<option $selected value=\"$comment_id\">$comment_id</option>";
}

?>
<tr>
<td>
Get Comment By Id
</td>
<td>
Name:

<select id="select_getCommentById" onchange="javascript:update_getCommentById()">
<?php echo $comment_options;?>
</select>
</td>
<td>
<a target="_blank" id="get_comment_by_id_link" href="<?php echo $SERVICE_URL ?>/comments/<?php echo $comment_first_id ?>"><?php echo $SERVICE_URL ?>/comments/<?php echo $comment_first_id ?></a>
</td>

<!--get all comments by duration -->
<tr>
<td>
Get Comments By Duration
</td>
<td>
<div>
<?php 
$default_start_date = time() - (7 * 24 * 60 * 60); // a week ago
$default_start_date_arr = getdate($default_start_date);

$default_end_date = time(); // now
$default_end_date_arr = getdate($default_end_date);

?>
Start Date:

<select id="select_getCommentsByDurationYear" onchange="javascript:update_getCommentsByDuration()">
<?php
for($year = 2000; $year < 2050; $year++ ) {
	$selected = "";
	if($year == $default_start_date_arr["year"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$year\">$year</option>";
}
?>
</select>
<select id="select_getCommentsByDurationMonth" onchange="javascript:update_getCommentsByDuration()">
<?php
for($month = 1; $month <= 12; $month ++ ) {
	$selected = "";
	if($month == $default_start_date_arr["mon"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$month\">$month</option>";
}
?>
</select>
<select id="select_getCommentsByDurationDay" onchange="javascript:update_getCommentsByDuration()">
<?php
for($day = 1; $day <= 31; $day ++ ) {
	$selected = "";
	if($day == $default_start_date_arr["mday"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$day\">$day</option>";
}
?>
</select>
</div>
<!-- end date -->
<div>
End Date:

<select id="select_getCommentsByDurationEndYear" onchange="javascript:update_getCommentsByDuration()">
<?php
for($year = 2000; $year < 2050; $year++ ) {
	$selected = "";
	if($year == $default_end_date_arr["year"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$year\">$year</option>";
}
?>
</select>
<select id="select_getCommentsByDurationEndMonth" onchange="javascript:update_getCommentsByDuration()">
<?php
for($month = 1; $month <= 12; $month ++ ) {
	$selected = "";
	if($month == $default_end_date_arr["mon"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$month\">$month</option>";
}
?>
</select>
<select id="select_getCommentsByDurationEndDay" onchange="javascript:update_getCommentsByDuration()">
<?php
for($day = 1; $day <= 31; $day ++ ) {
	$selected = "";
	if($day == $default_end_date_arr["mday"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$day\">$day</option>";
}
?>
</select>
</div>
</td>
<td>
<a target="_blank" id="get_comments_by_duration_link" href="<?php echo $SERVICE_URL ?>/commentsByDuration/xxx/to/yyy"><?php echo $SERVICE_URL ?>/commentsByDuration/xxx/to/yyy</a>
</td>

</tr>

<!--get comments count by duration -->
<tr>
<td>
Get Comments Count By Duration
</td>
<td>
<div>
<?php 
$default_start_date = time() - (7 * 24 * 60 * 60); // a week ago
$default_start_date_arr = getdate($default_start_date);

$default_end_date = time(); // now
$default_end_date_arr = getdate($default_end_date);

?>
Start Date:

<select id="select_getCommentsCountByDurationYear" onchange="javascript:update_getCommentsCountByDuration()">
<?php
for($year = 2000; $year < 2050; $year++ ) {
	$selected = "";
	if($year == $default_start_date_arr["year"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$year\">$year</option>";
}
?>
</select>
<select id="select_getCommentsCountByDurationMonth" onchange="javascript:update_getCommentsCountByDuration()">
<?php
for($month = 1; $month <= 12; $month ++ ) {
	$selected = "";
	if($month == $default_start_date_arr["mon"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$month\">$month</option>";
}
?>
</select>
<select id="select_getCommentsCountByDurationDay" onchange="javascript:update_getCommentsCountByDuration()">
<?php
for($day = 1; $day <= 31; $day ++ ) {
	$selected = "";
	if($day == $default_start_date_arr["mday"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$day\">$day</option>";
}
?>
</select>
</div>
<!-- end date -->
<div>
End Date:

<select id="select_getCommentsCountByDurationEndYear" onchange="javascript:update_getCommentsCountByDuration()">
<?php
for($year = 2000; $year < 2050; $year++ ) {
	$selected = "";
	if($year == $default_end_date_arr["year"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$year\">$year</option>";
}
?>
</select>
<select id="select_getCommentsCountByDurationEndMonth" onchange="javascript:update_getCommentsCountByDuration()">
<?php
for($month = 1; $month <= 12; $month ++ ) {
	$selected = "";
	if($month == $default_end_date_arr["mon"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$month\">$month</option>";
}
?>
</select>
<select id="select_getCommentsCountByDurationEndDay" onchange="javascript:update_getCommentsCountByDuration()">
<?php
for($day = 1; $day <= 31; $day ++ ) {
	$selected = "";
	if($day == $default_end_date_arr["mday"]) {
        $selected = " selected=\"true\"";
	}
	echo "<option $selected value=\"$day\">$day</option>";
}
?>
</select>
</div>
</td>
<td>
<a target="_blank" id="get_comments_count_by_duration_link" href="<?php echo $SERVICE_URL ?>/commentsCountByDuration/xxx/to/yyy"><?php echo $SERVICE_URL ?>/commentsCountByDuration/xxx/to/yyy</a>
</td>

</tr>
</table>
</p>
<script>

update_getNodeById();
update_getNodesByDuration();
update_getNodesCountByDuration();

update_getCommentById();
update_getCommentsByDuration();
update_getCommentsCountByDuration();
</script>
</body>
</html>
