<?php
session_start();

require_once("defines.php");

/* retrieve the show nodes and show comments values */
$request_url = $_SERVER["REQUEST_URI"];
if(isset($_POST["show_choosed"])) {
	$show_nodes = isset($_POST["show_nodes"]);
	$show_comments = isset($_POST["show_comments"]);
}
else if(isset($_SESSION["show_nodes"]) || isset($_SESSION["show_comments"])){
	$show_comments = $_SESSION["show_nodes"];
	$show_nodes = $_SESSION["show_comments"];
}
else {
	$show_comments = 0;
	$show_nodes = 1;
}

$_SESSION["show_nodes"] = $show_comments;
$_SESSION["show_comments"] = $show_nodes;

/* retrive the duration value */

if(isset($_POST["duration"])) {
	$duration = $_POST["duration"];
}
else if(isset($_SESSION["duration"])) {
	$duration = $_SESSION["duration"];
}
else {
	$duration = "lastDay";
}
$_SESSION["duration"] = $duration;

$action = $_GET["action"];

?>
<html>
<head>
<title>Drupal Web Service Client - Admin Panel</title>
<link rel='stylesheet' href='style.css' type='text/css' media='all' />

</head>
<body>
<div id="wrapper">
<h1>Drupal Web Service Client - Admin Panel</h1>
<ul class="topicmenu">
	<li>
		<a <?php echo $get_nodes_link ?> href="index.php">Recent Updates</a>
	</li>
	<li>
		<a <?php echo $get_comments_link ?> href="index.php?action=users">Recent Users</a>
	</li>
	<li>
		<a <?php echo $get_comments_link ?> href="index.php?action=grpahs">Summery Graphs</a>
	</li>
</ul>
<div>
<form action="<?php $request_url ?>" method="POST">
	<ul class="node_comment_checks">
		<li>
			<input type="checkbox" onclick="form.submit()" name="show_nodes" value="1" <?php echo $show_nodes?"checked=1":"" ?>/> Nodes
		</li>
		<li>
			<input type="checkbox" onclick="form.submit()" name="show_comments" value="1" <?php echo $show_comments?"checked=1":"" ?> /> Comments
		</li>
		<li>
			<select name="duration" onchange="form.submit()">
				<option <?php echo $duration == "lastDay"?"selected":"" ?> value="lastDay">Last Day</option>
				<option <?php echo $duration == "lastMonth"?"selected":"" ?> value="lastMonth">Last Month</option>
				<option <?php echo $duration == "lastYear"?"selected":"" ?> value="lastYear">Last Year</option>
				<option <?php echo $duration == "last5Years"?"selected":"" ?> value="last5Years">Last 5 Years</option>
			</select>
		</li>
	</ul>
	<input type="hidden" name="show_choosed" value="1"/>
</form>
</div>
<?php

$end_time = date("Y-m-d H:i:s"); /* end time is always this moment */
if($duration == "lastDay") {
	$start_time = date("Y-m-d H:i:s", time() - 24*60*60);
}
else if($duration == "lastMonth") {
	$start_time = date("Y-m-d H:i:s", time() - 30*24*60*60);
}
else if($duration == "lastYear") {
	$start_time = date("Y-m-d H:i:s", time() - 365*24*60*60);
}
else if($duration == "last5Years") {
	$start_time = date("Y-m-d H:i:s", time() - 5*365*24*60*60);
}

if(!$show_comments && !$show_nodes) {
?>
	<div class="node">
	
	Please select either Node or Comment from the checke boxes
	</div>
<?php
}
else if(!isset($action) || $action == "") {
	/* This is to show comments and the the nodes */
	
	
	if($show_nodes) {
		$request_xml = <<<XML
			<getNodesByDuration>
				<startTime>$start_time</startTime>
				<endTime>$end_time</endTime>
			</getNodesByDuration>
XML;
		$client = new WSClient(array("to" => SERVICE_ENDPOINT));
		
		$response_xml = $client->request($request_xml);
		
		$doc = new DOMDocument();
		$doc->loadXML($response_xml->str);
		
		$nids = $doc->getElementsByTagName("nid");
		$types = $doc->getElementsByTagName("type");
		$contents = $doc->getElementsByTagName("body");
		$titles = $doc->getElementsByTagName("title");
		
		$nodes = array();
		for($i = $nids->length -1 ; $i >= 0; $i--) {
			$nid = $nids->item($i)->nodeValue;
			$type = $types->item($i)->nodeValue;
			$title = $titles->item($i)->nodeValue;
			$content = $contents->item($i)->nodeValue;
			
			?>
			<div class="node">
			
			<h2><?php echo $title;?></h2>
			<div class="node_content">
			<?php echo $content; ?>
			</div>
			<div class="node_footer">
			<?php echo $type; ?> - <?php echo $nid ?>
			</div>
			</div>
			<?php
		}
		
	}
	
	if($show_comments) {
		$request_xml = <<<XML
			<getCommentsByDuration>
				<startTime>$start_time</startTime>
				<endTime>$end_time</endTime>
			</getCommentsByDuration>
XML;
		$client = new WSClient(array("to" => SERVICE_ENDPOINT));
		
		$response_xml = $client->request($request_xml);
		
		$doc = new DOMDocument();
		$doc->loadXML($response_xml->str);
		
		$cids = $doc->getElementsByTagName("cid");
		$names = $doc->getElementsByTagName("name");
		$contents = $doc->getElementsByTagName("comment");
		$titles = $doc->getElementsByTagName("subject");
		
		$comments = array();
		for($i = $cids->length -1 ; $i >= 0; $i--) {
			$comments[$i] = array();
			$cid = $cids->item($i)->nodeValue;
			$username = $names->item($i)->nodeValue;
			$title = $titles->item($i)->nodeValue;
			$content = $contents->item($i)->nodeValue;
			
			?>
			<div class="node">
			
			<h2><?php echo $title;?></h2>
			<div class="node_content">
			<?php echo $content; ?>
			</div>
			<div class="node_footer">
			<?php echo $username; ?> - <?php echo $cid ?>
			</div>
			</div>
			<?php
			
		}
	}
}
else if($action == "users") {
	/* This is to show users commented and updated nodes */


	if($show_nodes) {
		$request_xml = <<<XML
			<getUsersPostedByDuration>
				<startTime>$start_time</startTime>
				<endTime>$end_time</endTime>
			</getUsersPostedByDuration>
XML;
		$client = new WSClient(array("to" => SERVICE_ENDPOINT));
		
		$response_xml = $client->request($request_xml);
		
		$doc = new DOMDocument();
		$doc->loadXML($response_xml->str);
		
		$names = $doc->getElementsByTagName("name");
		$emails = $doc->getElementsByTagName("email");
		
		$nodes = array();
		for($i = $names->length -1 ; $i >= 0; $i--) {
			$name = $names->item($i)->nodeValue;
			$email = $emails->item($i)->nodeValue;
			
			if($name == "") {
				continue;
			}
			
			?>
			<div class="node">
			<div class="node_content">
			<?php echo "$name - <a href=\"mailto:$email\">$email</a>"; ?>
			</div>
			</div>
			<?php
		}
		
	}
	
	if($show_comments) {
		$request_xml = <<<XML
			<getUsersCommentedByDuration>
				<startTime>$start_time</startTime>
				<endTime>$end_time</endTime>
			</getUsersCommentedByDuration>
XML;
		$client = new WSClient(array("to" => SERVICE_ENDPOINT));
		
		$response_xml = $client->request($request_xml);
		
		$doc = new DOMDocument();
		$doc->loadXML($response_xml->str);
		
		
		$doc = new DOMDocument();
		$doc->loadXML($response_xml->str);
		
		$names = $doc->getElementsByTagName("name");
		$emails = $doc->getElementsByTagName("email");
		
		$nodes = array();
		for($i = $names->length -1 ; $i >= 0; $i--) {
			$name = $names->item($i)->nodeValue;
			$email = $emails->item($i)->nodeValue;
			
			if($name == "") {
				continue;
			}
			
			?>
			<div class="node">
			<div class="node_content">
			<?php echo "$name - <a href=\"mailto:$email\">$email</a>"; ?>
			</div>
			</div>
			<?php
		}
	}	
}
else if($action == "grpahs")
{
?>

<img src="image.php?duration=<?php echo $duration?><?php echo $show_comments?"&show_comments=1":""?><?php echo $show_nodes?"&show_nodes=1":""?>"/>
<?php	
}

?>

</body>
</html>
