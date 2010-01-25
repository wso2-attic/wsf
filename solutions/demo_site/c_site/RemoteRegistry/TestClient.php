<?php
require "RemoteRegistry.php";

$rr = new RemoteRegistry("http://localhost:9090/wso2registry/atom/", "admin", "admin");


//$response = $rr-> get("/test/test");

//$response = $rr->delete("/test/test/notes2");

//print_r($response);

//$response = $rr->get("/test/test/good_morning");

//print_r($response);

//$comment = new Comment();
//$comment->text = "comment from php";
//$comment->user = "admin";
//
//$response = $rr->addComment("/test/test/mytest_file", $comment);

//$comments = $rr->getComments("/test/test/mytest_file");
//
//
//foreach($comments as $comment)
//{
//	echo "comment\n";
//	echo "user: ".$comment->user."\n";
//	echo "text: ".$comment->text."\n";
//}

//$response = $rr->getAverageRating("/test/test/mytest_file");
//
//echo $response;

//$response = $rr->getUserRating("/test/test/mytest_file", "dimuthu");
//
//echo $response;

//$response = $rr->applyTag("/test/test/mytest_file", "php1, php2, php3");

//$tags = $rr->getTags("/test/test/mytest_file");
//
//foreach($tags as $tag)
//{
//	echo $tag."\n";
//}

//$res = $rr->rateResource("/test", 5);

//$res = $rr->getResourcePathsWithTag("amazon");

//print_r($res);


/*
$r1 = new Resource();
$r1->author_username = "dimuthu";
$r1->description = "This is a test";
$r1->content = "Again some test";
$r1->media_type = "text";

$res = $rr->put("/wso2registry/atom/test/test2", $r1); */

$res = $rr->addUser("dc", "dc", "user", "dc_");

print_r($res);


?>