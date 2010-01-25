<?php
include_once("drupalapi_client.php");

$action = $_GET["action"];

if(!isset($action) || $action == "") {
	$get_nodes_link = "class=\"selected\"";
}
if($action == "node_by_id") {
	$get_node_by_id_link = "class=\"selected\"";
}
else if($action == "comments") {
	$get_comments_link = "class=\"selected\"";
}
else if($action == "comments_by_node") {
	$get_comments_node_link = "class=\"selected\"";
}
else if($action == "login" || $action == "logout") {
	$login_link = "class=\"selected\"";
}
else if($action == "submit_story") {
	$submit_story_link = "class=\"selected\"";
}
else if($action == "submit_page") {
	$submit_page_link = "class=\"selected\"";
}
else if($action == "submit_comment") {
	$submit_comment_link = "class=\"selected\"";
}

// login link
session_start();

// login and logout operations are done at the start
if($action == "login") {
	$username_submitted = $_POST["username"];
	$login_failed = false;
	if(isset($username_submitted)) {
		//user is submitted the form so handle it.
		$password = $_POST["password"];
		
		$_SESSION["username"] = $username_submitted;
		$_SESSION["password"] = $password;
		try {
			// create the DrupalAPIClient
			$client = new DrupalAPIClient($username_submitted, $password);
			
			$input =  new login();
			$response = $client->login($input);
			
			$success_code = $response->return;
			
			if($success_code) {
				$login_content = "<div class=\"message\">Login Successful, Now you can POST stories, pages and comments</div>";
				
			}
			else {
				$login_content = "<div class=\"red\">Login Failed! Please Retry.</div>";
				$login_failed = true;
			}
			
		}
		catch (Exception $e) {
			$login_content = "<div class=\"red\">Login Failed! Please Retry.</div>";
			$login_failed = true;
		}
	}
}
else if($action == "logout") {
	
	session_destroy();
	$logout_content = "<div class=\"message\">You are successfully Logout</div>";
}

$login_username = $_SESSION["username"];
$login_password = $_SESSION["password"];

if(!isset($login_username)) {
	$login_link_html = "<a $login_link href=\"index.php?action=login\">Login</a>";
}
else {
	$login_link_html = "<a $login_link href=\"index.php?action=logout\">Logout</a>";
}
?>
<html>
<head>
<title>Drupal Web Service Client Using WSF/PHP</title>
<link rel='stylesheet' href='style.css' type='text/css' media='all' />

</head>
<body>
<div id="wrapper">
<h1>DRUPAL Web Service API - DEMO Client</h1>
<ul class="topicmenu">
	<li>
		<a <?php echo $get_nodes_link ?> href="index.php">Get All Nodes</a>
	</li>
	<li>
		<a <?php echo $get_node_by_id_link ?> href="index.php?action=node_by_id">Get Node By Id</a>
	</li>
	<li>
		<a <?php echo $get_comments_link ?> href="index.php?action=comments">Get All Comments</a>
	</li>
</ul>
<ul class="topicmenu">
	<li>
		<a <?php echo $get_comments_node_link ?> href="index.php?action=comments_by_node">Get Comments Per Node</a>
	</li>
	<li>
		<?php echo $login_link_html ?>
	</li>
	<li>
		<a <?php echo $submit_story_link ?> href="index.php?action=submit_story">Submit Story</a>
	</li>
</ul>
<ul class="topicmenu">
	<li>
		<a <?php echo $submit_page_link ?> href="index.php?action=submit_page">Submit Page</a>
	</li>
	<li>
		<a <?php echo $submit_comment_link ?> href="index.php?action=submit_comment">Submit Comment</a>
	</li>
</ul>

<div id="content">
<?php

// operation for retrieve all nodes
if(!isset($action) || $action == "") {
	
	$getNodes = new getNodes();
	$getNodes->limit = 5;
	
	$response = DrupalAPIClient::getNodes($getNodes);
	
	$returns = $response->return;
	
	if(is_array($returns)) {
		foreach ($returns as $node) {
			$node_id = $node->id;
			$title = $node->title;
			$content = $node->content;
			$comment_access = $node->commentAccess;
			$type = $node->type;
			
			html_for_view_node($node_id, $title, $content, $comment_access, $type);
		}

	}
	else {
		echo "<div id=\"message\">There are no Items Here</div>";
	}
}
// show the page for retrieve node by id
else if($action == "node_by_id") {
	$nid = $_GET["nid"];
	
	// if the nid null ask for the nid
	if(!isset($nid) || $nid == "") {
?>

<div id="content">
<ul>
<li>
<form method="GET" action="index.php?action=node_by_id">
Please Enter an ID of the node you want to view: 
<input type="text" style="width:65px" name="nid"/>
<input type="submit" value="Go"/>
</form>
</li>

<li>
Or Select a Node from the "Get All Nodes" Tab
</li>
</ul>
</div>

<?php
	}
	else {
		// nid is found just show the node..
		$getNodes = new getNodeById();
		$getNodes->id = $nid;
		
		$response = DrupalAPIClient::getNodeById($getNodes);
		
		$node = $response->return;
	
		$node_id = $node->id;
		$title = $node->title;
		$content = $node->content;
		$comment_access = $node->commentAccess;
		$type = $node->type;
		
		html_for_view_node($node_id, $title, $content, $comment_access, $type);
		
	}
}
else if($action == "comments") {
	
	$getComments = new getComments();
	$getComments->limit = 5;
	
	$response = DrupalAPIClient::getComments($getComments);
	
	$returns = $response->return;
	
	if(is_array($returns)) {
		foreach ($returns as $comment) {
			$comment_id = $comment->id;
			$title = $comment->title;
			$content = $comment->content;
			$userName = $comment->userName;
			$node_id = $comment->nodeId;
			
			html_for_view_comment($comment_id, $title, $content, $userName, $node_id);
			
		}
	}
	else {
		echo "<div id=\"message\">There are no Items Here</div>";
	}
}
// show the page for retrieve comments by node
else if($action == "comments_by_node") {
	$nid = $_GET["nid"];
	
	// if the nid null ask for the nid
	if(!isset($nid) || $nid == "") {
?>

<div id="content">
<ul>
<li>
<form method="GET" action="index.php?action=comments_by_node">
Please Enter an ID of the node you want to view: 
<input type="text" style="width:65px" name="nid"/>
<input type="submit" value="Go"/>
</form>
</li>

<li>
Or Select a Node from the "Get All Nodes" Tab
</li>
</ul>
</div>

		<?php
	}
	else {
		// nid is found just show the node..
		$getComments = new getCommentsForNode();
		$getComments->nodeId = $nid;
		
		$response = DrupalAPIClient::getCommentsForNode($getComments);
		
		$returns = $response->return;
		
		if(is_array($returns)) {
			foreach ($returns as $comment) {
				$comment_id = $comment->id;
				$title = $comment->title;
				$content = $comment->content;
				$userName = $comment->userName;
				$node_id = $comment->nodeId;
				
				html_for_view_comment($comment_id, $title, $content, $userName, $node_id);
			}
			
		}
		else {
			echo "<div id=\"message\">There are no Items Here</div>";
		}
		
	}
}
// show the page for login
else if($action == "login") {
	echo $login_content;
	if(!isset($username_submitted) || $login_failed) {
?>
<div id="login">
<form method="post" action="index.php?action=login">
<h2>
Enter Username and Password for login
</h2>
<p>
Username <input type="text" name="username"/>
</p>
<p>
Password <input type="password" name="password"/>
</p>
<p>
<input type="submit" value="submit"/>
</p>
</form>
</div>
<?php
	}
}
// logout html code
else if($action == "logout") {
	echo $logout_content;
}
// show the page for to submit story
else if($action == "submit_story") {
	$show_submit_story_page = false;
	if(!isset($login_username)) {
		echo "<div class=\"message\">Please login to post a story</div>";
	}
	else if($_POST["submit"]){
		$title = $_POST["title"];
		$content = $_POST["story"];
		
		if($title == "") {
			echo "<div class=\"red\">Please type a title</div>";
			$show_submit_story_page = true;
		}
		
		else {
			$post = new Node();
			
			$post->title = $title;
			$post->content = $content;
			$post->time = time();
			$post->type = "story";
			$post->commentAccess = 2; // by default read/write comments
			$post->moderate = 0;
			$post->promote =1;
			
			$postStory = new postStory();
			$postStory->post = $post;
			
			// create the DrupalAPIClient
			$client = new DrupalAPIClient($login_username, $login_password);
			
			$response =  $client->postStory($postStory);
			
			$node_id = $response->return;
			
			if($node_id > 0 ) {
				echo "<div class=\"message\">Story Submission Successful!</div>";
				echo "<p>Visit <a href=\"index.php?action=node_by_id&nid={$node_id}\">here</a> for visit the Story</p>";
			}
			else {
				echo "<div class=\"red\">Submission the Story Failed!, Please Retry</div>";
				$show_submit_story_page = true;
			}
		}
		
	}
	else {
		$show_submit_story_page = true;
	}
	
	if($show_submit_story_page) {
?>
	<div id="content">
	<h2>Submit Your Story Here</h2>
	<form method="POST" action="index.php?action=submit_story">
	<p>
	Title
	<input name="title" style="width:450px;  font-size: 25px;" type="text"/>
	</p>
	<p>
	<textarea cols="58" rows="20" name="story"></textarea>
	</p>
	<p>
	<input name="submit" type="submit" value="Submit Story"/>
	</p>
	</form>
	</div>
<?php
	}
}
// show the page for to submit page
else if($action == "submit_page") {
	$show_submit_story_page = false;
	if(!isset($login_username)) {
		echo "<div class=\"message\">Please login to post a Page</div>";
	}
	else if($_POST["submit"]){
		$title = $_POST["title"];
		$content = $_POST["page"];
		
		if($title == "") {
			echo "<div class=\"red\">Please type a title</div>";
			$show_submit_story_page = true;
		}
		else {
			$post = new Node();
			
			$post->title = $title;
			$post->content = $content;
			$post->time = time();
			$post->type = "page";
			$post->commentAccess = 2; // by default read/write comments
			$post->moderate = 0;
			$post->promote =1;
			
			$postPage = new postPage();
			$postPage->post = $post;
			
			// create the DrupalAPIClient
			$client = new DrupalAPIClient($login_username, $login_password);
			
			$response =  $client->postPage($postPage);
			
			$node_id = $response->return;
			
			if($node_id > 0 ) {
				echo "<div class=\"message\">Page Submission Successful!</div>";
				echo "<p>Visit <a href=\"index.php?action=node_by_id&nid={$node_id}\">here</a> for visit the Page</p>";
			}
			else {
				echo "<div class=\"red\">Submission the Page Failed!, Please Retry</div>";
				$show_submit_story_page = true;
			}
		}
	}
	else {
		$show_submit_story_page = true;
	}
	
	if($show_submit_story_page) {
?>
	<div id="content">
	<h2>Submit Your Page Here</h2>
	<form method="POST" action="index.php?action=submit_page">
	<p>
	Title
	<input name="title" style="width:450px;  font-size: 25px;" type="text"/>
	</p>
	<p>
	<textarea cols="58" rows="20" name="page"></textarea>
	</p>
	<p>
	<input name="submit" type="submit" value="Submit Page"/>
	</p>
	</form>
	</div>
<?php
	}
}
// show the page for to submit comment
else if($action == "submit_comment") {
	$nid = $_GET["nid"];
	
	$show_submit_comment_page = false;
	if(!isset($login_username)) {
		echo "<div class=\"message\">Please login to post a Comment</div>";
	}
	// if the nid null ask for the nid
	if(!isset($nid) || $nid == "") {
?>

<div id="content">
<ul>
<li>
<form method="GET" action="index.php?action=submit_comment">
Please Enter an ID of the node you want to Comment for: 
<input type="text" style="width:65px" name="nid"/>
<input type="submit" value="Go"/>
</form>
</li>

<li>
Or Select "Submit Comment" from the "Get All Nodes" Tab
</li>
</ul>
</div>

<?php
	}
	else if($_POST["submit"]){
		$title = $_POST["title"];
		$content = $_POST["comment"];
		
				if($content == "") {
			echo "<div class=\"red\">Please type the comment</div>";
					$show_submit_comment_page = true;
		}
		elseif ($title == "") {
			echo "<div class=\"red\">Please type the title for the comment</div>";
			$show_submit_comment_page = true;
		}
		else {
			
			$comment = new Comment();
			
			$comment->title = $title;
			$comment->content = $content;
			$comment->time = time();
			$comment->nodeId = $nid;
			
			$postComment = new postComment();
			$postComment->comment = $comment;
			
			// create the DrupalAPIClient
			$client = new DrupalAPIClient($login_username, $login_password);
			
			$response =  $client->postComment($postComment);
			
			$comment_id = $response->return;
			
			if($comment_id > 0 ) {
				echo "<div class=\"message\">Comment Submission Successful!</div>";
				echo "<p>Visit <a href=\"index.php?action=comments_by_node&nid={$nid}\">here</a> for visit the Comments for the node</p>";
			}
			else {
				echo "<div class=\"red\">Submission the Comment Failed!, Please Retry</div>";
				$show_submit_comment_page = true;
			}
		}
	}
	else {
		$show_submit_comment_page = true;
	}
	
	if($show_submit_comment_page) {
?>
	<div id="content">
	<h2>Submit Your Comment Here</h2>
	<form method="POST" action="index.php?action=submit_comment&nid=<?php echo $nid?>">
	<p>
	Title
	<input name="title" style="width:450px;  font-size: 25px;" type="text"/>
	</p>
	<p>
	<textarea cols="58" rows="15" name="comment"></textarea>
	</p>
	<p>
	<input name="submit" type="submit" value="Submit Comment"/>
	</p>
	</form>
	</div>
<?php
	}
}
?>
</div>
</div>
</body>
</html>

<?php
function html_for_view_node($node_id, $title, $content, $comment_access, $type)
{
	if($node_id == null) {
		return;
	}
	// prepare the comment html string
	if($comment_access == 1) { // that is read only
		$comment_html_string = "<a href=\"index.php?action=comments_by_node&nid={$node_id}\">Show Comments</a>";
	}
	else if($comment_access == 2) { // that is read and write
		$comment_html_string = "<a href=\"index.php?action=comments_by_node&nid={$node_id}\">Show Comments</a>".
				" | <a href=\"index.php?action=submit_comment&nid={$node_id}\">Add New Comment</a>";
	}
	else {
		$comment_html_string = "<i>Comments are protected</i>";
	}
	
	?>
	<div class="node">
	
	<h2><a <?php echo "href=\"index.php?action=node_by_id&nid={$node_id}\"" ?>><?php echo $title;?></a></h2>
	<div class="node_content">
	<?php echo $content; ?>
	</div>
	<div class="node_comment_links">
	<?php echo $comment_html_string; ?>
	</div>
	</div>
	
	<?php	
}


function html_for_view_comment($comment_id, $title, $content, $userName, $node_id)
{
	if($comment_id == null) {
		return;
	}
	
	?>
	<div class="node">
	
	<h2><a <?php echo "href=\"index.php?action=comments_by_node&nid={$node_id}\"" ?>><?php echo $title;?></a>
	</h2>
	<div class="node_content">
	<?php echo $content; ?>
	</div>
	<div class="node_comment_links">
	- By <?php echo $userName ?>
	</div>
	</div>
	
	<?php	
}
?>