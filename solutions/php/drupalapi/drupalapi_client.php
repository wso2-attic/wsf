<?php

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

class DrupalAPIClient {
	// define the class map
	private static $class_map = array(
		"postBlog" => "postBlog",
		"Blog" => "Blog",
		"postBlogResponse" => "postBlogResponse",
		"User" => "User",
		"getCommentsForNode" => "getCommentsForNode",
		"getCommentsForNodeResponse" => "getCommentsForNodeResponse",
		"Comment" => "Comment",
		"getCommentsResponse" => "getCommentsResponse",
		"getCommentsByDuration" => "getCommentsByDuration",
		"getCommentsByDurationResponse" => "getCommentsByDurationResponse",
		"postComment" => "postComment",
		"postCommentResponse" => "postCommentResponse",
		"getNodesResponse" => "getNodesResponse",
		"getNodes" => "getNodes",
		"getNodeById" => "getNodeById",
		"getNodeByIdResponse" => "getNodeByIdResponse",
		"getNodesByDuration" => "getNodesByDuration",
		"getNodesByDurationResponse" => "getNodesByDurationResponse");
	
	private $proxy = NULL;
		
	public function __construct($usernmae, $password) {
		
		$security_token = new WSSecurityToken(array("user" => $usernmae,
					"password" => md5($password),
					"passwordType" => "plain"));
		
		
		// create client in WSDL mode
		$client = new WSClient(array ("wsdl" =>"DrupalAPI.wsdl",
					"securityToken" => $security_token,
					"classmap" => DrupalAPIClient::$class_map));
		
		// get proxy object reference form client 
		$this->proxy = $client->getProxy();
	}
	
	public function postPage($input) {
		try {
			// create input object and set values
			//$input = new postPage();
			//TODO: fill in the class fields of $input to match your business logic
			
			// call the operation
			$response = $this->proxy->postPage($input);
			//TODO: Implement business logic to consume $response, which is of type postPageResponse
			
			return $response;
			
		} catch (Exception $e) {
			// in case of an error, process the fault
			if ($e instanceof WSFault) {
				printf("Soap Fault: %s\n", $e->Reason);
			} else {
				printf("Message = %s\n", $e->getMessage());
			}
		}
	}
	
	
	public function postStory($input) {
		try {
			// create input object and set values
			//$input = new postStory();
			//TODO: fill in the class fields of $input to match your business logic
			
			// call the operation
			$response = $this->proxy->postStory($input);
			//TODO: Implement business logic to consume $response, which is of type postStoryResponse
			
			return $response;
			
		} catch (Exception $e) {
			// in case of an error, process the fault
			if ($e instanceof WSFault) {
				printf("Soap Fault: %s\n", $e->Reason);
			} else {
				printf("Message = %s\n", $e->getMessage());
			}
		}
	}
	
	
	public static function getCommentsForNode($input) {
		try {
			
			//$input = new getCommentsForNode();
			//TODO: fill in the class fields of $input to match your business logic
			
			// call the operation
			
			// create a private client and proxy in WSDL mode
			$client = new WSClient(array ("wsdl" =>"DrupalAPI.wsdl",
						"classmap" => DrupalAPIClient::$class_map));
			
			$proxy = $client->getProxy();
			$response = $proxy->getCommentsForNode($input);
			//TODO: Implement business logic to consume $response, which is of type getCommentsForNodeResponse
			
			return $response;
		} catch (Exception $e) {
			// in case of an error, process the fault
			if ($e instanceof WSFault) {
				printf("Soap Fault: %s\n", $e->Reason);
			} else {
				printf("Message = %s\n", $e->getMessage());
			}
		}
	}
	
	
	
	
	
	public static function getComments($input) {
		try {
			
			//TODO: fill $input with (data type: anyType) data to match your business logic
			
			// call the operation
			
			// create a private client and proxy in WSDL mode
			$client = new WSClient(array ("wsdl" =>"DrupalAPI.wsdl",
						"classmap" => DrupalAPIClient::$class_map));
						
			$proxy = $client->getProxy();
			
			$response = $proxy->getComments($input);
			//TODO: Implement business logic to consume $response, which is of type getCommentsResponse
			
			return $response;
		} catch (Exception $e) {
			// in case of an error, process the fault
			if ($e instanceof WSFault) {
				printf("Soap Fault: %s\n", $e->Reason);
			} else {
				printf("Message = %s\n", $e->getMessage());
			}
		}
	}
	
	
	
	public static function getCommentsByDuration($input) {
		try {
			
			//TODO: fill $input with (data type: anyType) data to match your business logic
			
			// call the operation
			
			// create a private client and proxy in WSDL mode
			$client = new WSClient(array ("wsdl" =>"DrupalAPI.wsdl",
						"classmap" => DrupalAPIClient::$class_map));
			
			$proxy = $client->getProxy();
			
			$response = $proxy->getCommentsByDuration($input);
			//TODO: Implement business logic to consume $response, which is of type getCommentsResponse
			
			return $response;
		} catch (Exception $e) {
			// in case of an error, process the fault
			if ($e instanceof WSFault) {
				printf("Soap Fault: %s\n", $e->Reason);
			} else {
				printf("Message = %s\n", $e->getMessage());
			}
		}
	}
	
	
	public function postComment($input) {
		try {
			
			//TODO: fill in the class fields of $input to match your business logic
			
			// call the operation
			$response = $this->proxy->postComment($input);
			//TODO: Implement business logic to consume $response, which is of type postCommentResponse
			
			return $response;
		} catch (Exception $e) {
			// in case of an error, process the fault
			if ($e instanceof WSFault) {
				printf("Soap Fault: %s\n", $e->Reason);
			} else {
				printf("Message = %s\n", $e->getMessage());
			}
		}
	}
	
	public function login($input) {
		// if the login fails it would raise a fault..
		//TODO: fill in the class fields of $input to match your business logic
		
		// call the operation
		$response = $this->proxy->login($input);
		//TODO: Implement business logic to consume $response, which is of type loginResponse
		
		return $response;
	}
	
	
	public static function getNodes($input) {
		try {
			
			//TODO: fill $input with (data type: anyType) data to match your business logic
			
			// call the operation
			
			// create a private client and proxy in WSDL mode
			$client = new WSClient(array ("wsdl" =>"DrupalAPI.wsdl",
						"classmap" => DrupalAPIClient::$class_map));
			
			$proxy = $client->getProxy();
			
			$response = $proxy->getNodes($input);
			//TODO: Implement business logic to consume $response, which is of type getNodesResponse
			
			return $response;
		} catch (Exception $e) {
			// in case of an error, process the fault
			if ($e instanceof WSFault) {
				printf("Soap Fault: %s\n", $e->Reason);
			} else {
				printf("Message = %s\n", $e->getMessage());
			}
		}
	}
	
	public static function getNodeById($input) {
		try {
			
			//TODO: fill $input with (data type: getNodeById) data to match your business logic
			
			// call the operation
			
			// create a private client and proxy in WSDL mode
			$client = new WSClient(array ("wsdl" =>"DrupalAPI.wsdl",
						"classmap" => DrupalAPIClient::$class_map));
			
			$proxy = $client->getProxy();
			
			$response = $proxy->getNodeById($input);
			//TODO: Implement business logic to consume $response, which is of type getNodeByIdResponse
			
			return $response;
		} catch (Exception $e) {
			// in case of an error, process the fault
			if ($e instanceof WSFault) {
				printf("Soap Fault: %s\n", $e->Reason);
			} else {
				printf("Message = %s\n", $e->getMessage());
			}
		}
	}
	
	public static function getNodesByDuration($input) {
		try {
			
			//TODO: fill $input with (data type: anyType) data to match your business logic
			
			// call the operation
			
			// create a private client and proxy in WSDL mode
			$client = new WSClient(array ("wsdl" =>"DrupalAPI.wsdl",
						"classmap" => DrupalAPIClient::$class_map));
			
			$proxy = $client->getProxy();
			
			$response = $proxy->getNodesByDuration($input);
			//TODO: Implement business logic to consume $response, which is of type getNodesResponse
			
			return $response;
		} catch (Exception $e) {
			// in case of an error, process the fault
			if ($e instanceof WSFault) {
				printf("Soap Fault: %s\n", $e->Reason);
			} else {
				printf("Message = %s\n", $e->getMessage());
			}
		}
	}
}
?>
