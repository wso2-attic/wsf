<?php

// PHP classes corresponding to the data types in defined in WSDL

class postStory {

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

}

class postStoryResponse {

    /**
     * @var int
     */
    public $return;

}

class User {

    /**
     * @var int
     */
    public $id;

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

}

class getComments {

}

class getCommentsResponse {

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

}

class getNodesResponse {

    /**
     * @var array[0, unbounded] of (object)Node
     */
    public $return;

}

// define the class map
$class_map = array(
    "postStory" => "postStory",
    "Node" => "Node",
    "postStoryResponse" => "postStoryResponse",
    "User" => "User",
    "getCommentsForNode" => "getCommentsForNode",
    "getCommentsForNodeResponse" => "getCommentsForNodeResponse",
    "Comment" => "Comment",
    "getComments" => "getComments",
    "getCommentsResponse" => "getCommentsResponse",
    "postComment" => "postComment",
    "postCommentResponse" => "postCommentResponse",
    "getNodes" => "getNodes",
    "getNodesResponse" => "getNodesResponse");

try {
	
	$security_token = new WSSecurityToken(array("user" => "dimuthu",
				"password" => "8a14b53d6283a11a87b735ca2ee0c79f",
				"passwordType" => "plain"));
	
    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"DrupalAPI.wsdl",
		"securityToken" => $security_token,
        "classmap" => $class_map));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

/*
    // create input object and set values
    $input = new postStory();
    //TODO: fill in the class fields of $input to match your business logic
	
*/
	
	$post = new Node();
	
	$post->title = "test";
	$post->content = "test";
	$post->time = time();
	
	$input->post = $post;
	
	/*
    // call the operation
    $response = $proxy->postStory($input);
    //TODO: Implement business logic to consume $response, which is of type postStoryResponse
	
	print_r($response);

    $input = new registerUser();
    //TODO: fill in the class fields of $input to match your business logic
	$input->user = "TEST";
	$input->id = "3";
	$input->name = "test";
	$input->password = "test123";
	$input->email = "test@test.ooo";

    // call the operation
    $response = $proxy->registerUser($input);
    //TODO: Implement business logic to consume $response, which is of type registerUserResponse
	
	print_r($response);

    $input = new getCommentsForNode();
    //TODO: fill in the class fields of $input to match your business logic
	$input->nodeId = 2;

    // call the operation
    $response = $proxy->getCommentsForNode($input);
    //TODO: Implement business logic to consume $response, which is of type getCommentsForNodeResponse
	print_r($response);

    $input = new getUsers();
    //TODO: fill in the class fields of $input to match your business logic

    // call the operation
    $response = $proxy->getUsers($input);
    //TODO: Implement business logic to consume $response, which is of type getUsersResponse
	print_r($response);

    $input = new getComments();
    //TODO: fill in the class fields of $input to match your business logic

    // call the operation
    $response = $proxy->getComments($input);
    //TODO: Implement business logic to consume $response, which is of type getCommentsResponse
	print_r($response);

    $input = new postComment();
    //TODO: fill in the class fields of $input to match your business logic
	$comment = new Comment();
	
	$comment->id = 3;
	$comment->title = "test";
	$comment->content = "test";
	$comment->time = "2008-08-09";
	$comment->userId = 3;
	$comment->nodeId = 5;
	
	$input->comment = $comment;
	
    // call the operation
    $response = $proxy->postComment($input);
    //TODO: Implement business logic to consume $response, which is of type postCommentResponse
	print_r($response);


    $input = new getNodes();
    //TODO: fill in the class fields of $input to match your business logic

    // call the operation
    $response = $proxy->getNodes($input);
    //TODO: Implement business logic to consume $response, which is of type getNodesResponse
	print_r($response);
*/

} catch (Exception $e) {
    // in case of an error, process the fault
    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n", $e->getMessage());
    }
}
?>
