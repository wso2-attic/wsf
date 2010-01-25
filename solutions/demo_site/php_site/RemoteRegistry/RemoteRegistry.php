<?php
/*
 * Copyright (c) 2005-2008 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

require_once "RESTClient.php";
require_once "Resource.php";
require_once "Comment.php";

/**
 * RemoteRegistry, facilitate access to the Registry interface
 *
 */
class RemoteRegistry
{
	private $authorization_str = NULL;
	private $rest_client = NULL;
	private $registry_url = NULL;
	private $last_feed_xml;
	
	const COMMENT_PARAMTER = "comments";
	const RATING_PARAMTER = "ratings";
	const TAG_PARAMTER = "tags";
	const TAGPATHS_PARAMTER = "tagpaths";
	const ADDUSER_PARAMETER = "adduser";
	const ATOM_NS = "http://www.w3.org/2005/Atom";
	const WSO2_TAG_NS = "tag:wso2.org,2008:foo";
	const REGISTRY_NS = "http://wso2.org/registry";
	
	/**
	 * Construct the RemoteRegistry
	 *
	 * @param string $registry_url url of the registry instance
	 * @param string $username username of the registry account, default to NULL
	 * @param string $password password of the registry accound, default to NULL
	 */
	public function __construct($registry_url, $username = NULL, $password = NULL)
	{
		if(substr($registry_url, -1) == '/')
		{
			$registry_url = substr($registry_url, 0, strlen($registry_url)-1);
		}
		
		$this->rest_client = new RESTClient($username, $password);
		$this->registry_url = $registry_url;		
	}
	
	/**
	 * Get resources of an perticular registry path
	 *
	 * @param string $path
	 * @param array $params
	 * @return string retrieved resource
	 */
	public function get($path, array $params = array())
	{
		$response =  $this->rest_client->get($this->registry_url.$path, $params);
	
        $resource = NULL;
		if($this->rest_client->getLastResponseStatus() == "200")
		{
			$resource = $this->createResourceFromFeed($response);
		}
		
		return $resource;
	}
	
	/**
	 * Delete resource
	 *
	 * @param string $path
	 * @return 0 on success, -1 otherwise
	 */
	public function delete($path)
	{
		$this->rest_client->delete($this->registry_url.$path);
		if($this->rest_client->getLastResponseStatus() == "204")
		{
			return 0;
		}
		return -1;
	}
	
	/**
	 * Put resource in to a perticular path
	 *
	 * @param string $path
	 * @param string $resource
	 * @return void
	 */
	public function put($path, $resource) 
	{
		$dom = new DOMDocument();
		$root = $dom->createElementNS(RemoteRegistry::ATOM_NS, "entry");
		$dom->appendChild($root);
		if($resource->description !== NULL)
		{
			$summery = $dom->createElementNS(RemoteRegistry::ATOM_NS, "summery", $resource->description);
			$summery->setAttribute("type", "text");
			$root->appendChild($summery);
		}
		if($resource->author_username !== NULL)
		{
			$author = $dom->createElementNS(RemoteRegistry::ATOM_NS, "author");
			$name = $dom->createElementNS(RemoteRegistry::ATOM_NS, "name", $resource->author_username);
			$author->appendChild($name);
			$root->appendChild($author);
		}
		
		$properties = $dom->createElementNS(RemoteRegistry::WSO2_TAG_NS, "properties");
		if($resource->properties !== NULL && is_array($resource->properties))
		{
			foreach($resource->properties as $key => $value)
			{
				$property = $dom->createElementNS(RemoteRegistry::WSO2_TAG_NS, "property");
				
				$name = $dom->createElementNS(RemoteRegistry::WSO2_TAG_NS, "name", $key);
				$property->appendChild($name);
				$value_ele = $dom->createElementNS(RemoteRegistry::WSO2_TAG_NS, "value", $value);
				$property->appendChild($value_ele);
				
				$properties->appendChild($property);
			}		
		}
		$root->appendChild($properties);
		
		if($resource->content != NULL)
		{
			$content = $dom->createElementNS(RemoteRegistry::ATOM_NS, "content", $resource->content);
			$content->setAttribute("type", $resource->media_type);
			$root->appendChild($content);
		}
		
		if($resource->is_directory)
		{
			$dir = $dom->createElementNS("", "directory", "true");
		}
		else
		{
			$dir = $dom->createElementNS("", "directory", "false");
		}
		$root->appendChild($dir);
		
		if($resource->content_modified)
		{
			$modified = $dom->createElementNS("", "contentModified", "true");
		}
		else
		{
			$modified = $dom->createElementNS("", "contentModified", "false");
		}
		
		$root->appendChild($modified);
		
		$data = $dom->saveXML($dom->documentElement);	
		$response =  $this->rest_client->post($this->registry_url.$path, $data);
		
		return $response;
	}
	
	/**
	 * addComment to a perticular resource
	 *
	 * @param string $path
	 * @param Comment $comment
	 * @return void
	 */
	public function addComment($path, $comment)
	{
		$dom = new DOMDocument();
		$root = $dom->createElementNS(RemoteRegistry::ATOM_NS, "entry");
		$dom->appendChild($root);
		if($comment->user !== NULL)
		{
			$author = $dom->createElementNS(RemoteRegistry::ATOM_NS, "author");
			$name = $dom->createElementNS(RemoteRegistry::ATOM_NS, "name", $comment->user);
			$author->appendChild($name);
			$root->appendChild($author);
		}
		
		if($comment->text !== NULL)
		{
			$content = $dom->createElementNS(RemoteRegistry::ATOM_NS, "content", $comment->text);
			$content->setAttribute("type", "text");
			$root->appendChild($content);
		}
		
		$data = $dom->saveXML($dom->documentElement);
		
		$response =  $this->rest_client->post($this->registry_url.$path.";".RemoteRegistry::COMMENT_PARAMTER, $data);
		
		return $response;
	}
	
	/**
	 * retrieve comments for a perticulr resource
	 *
	 * @param string $path
	 * @return array of Comment comments
	 */
	public function getComments($path)
	{
		$response =  $this->rest_client->get($this->registry_url.$path.";".
						RemoteRegistry::COMMENT_PARAMTER);
						
		$comments = array();
		
		if($this->rest_client->getLastResponseStatus() == "200")
		{
			$resource = $this->createResourceFromFeed($response);
			$feed_xml = $this->last_feed_xml;
			if($feed_xml->entry !== NULL)
			{
				foreach($feed_xml->entry as $entry)
				{
					$comment = new Comment();
					if($entry->updated !== NULL)
					{
						$comment->date_time = $entry->updated."";
					}
					
					if($entry->authour !== NULL && $entry->author->name !== NULL)
					{
						$comment->user = $entry->author->name."";
					}
					
					if($entry->content !== NULL)
					{
						$comment->text = $entry->content."";
					}
					$comments[count($comments)] = $comment;
				}
			}
		}
		
		return $comments;		
	}
	
	/**
	 * rate a resource
	 *
	 * @param string $path resource path
	 * @param int $rateValue
	 * @return void
	 */
	public function rateResource($path, $rateValue)
	{
		$dom = new DOMDocument();
		$root = $dom->createElementNS(RemoteRegistry::ATOM_NS, "entry");
		$dom->appendChild($root);
		
		$content = $dom->createElementNS(RemoteRegistry::ATOM_NS, "content", $rateValue);
		$content->setAttribute("type", "text");
		$root->appendChild($content);
		
		$summery = $dom->createElementNS(RemoteRegistry::ATOM_NS, "summery", RemoteRegistry::RATING_PARAMTER);
		$summery->setAttribute("type", "text");
		$root->appendChild($summery);
		
		$data = $dom->saveXML($dom->documentElement);
		
		$response =  $this->rest_client->post($this->registry_url.$path.";".RemoteRegistry::RATING_PARAMTER, $data);
		
		return $this->rest_client->getLastResponseStatus();
	}
	
	/**
	 * Get Average Rating of a resource
	 *
	 * @param string $path
	 * @return int the avarage rating
	 */
	public function getAverageRating($path)
	{
		$response =  $this->rest_client->get($this->registry_url.$path.";".RemoteRegistry::RATING_PARAMTER);
		
		if($this->rest_client->getLastResponseStatus() == "200")
		{
			$resource = $this->createResourceFromFeed($response);
			$feed_xml = $this->last_feed_xml;
			$wso2_ns = $feed_xml->children("http://wso2.org/registry");
			if($wso2_ns->AverageRating !== NULL)
			{
				return (float)($wso2_ns->AverageRating."");
			}
		}
		
		return 0;
	}

	/**
	 * Get user rating
	 *
	 * @param string $path
	 * @param string $username
	 * @return int
	 */
	public function getUserRating($path, $username)
	{
		$response =  $this->rest_client->get($this->registry_url.$path.";".
						RemoteRegistry::RATING_PARAMTER.":".
						$username);
		
		if($this->rest_client->getLastResponseStatus() == "200")
		{
			$resource = $this->createResourceFromFeed($response);
			$feed_xml = $this->last_feed_xml;
			if($feed_xml->entry !== NULL && $feed_xml->entry->content !== NULL)
			{
				return (int)($feed_xml->entry->content);
			}
		}
		
		return 0;
	}
	
	/**
	 * apply a tag
	 *
	 * @param string $path
	 * @param string $tag
	 * @return void
	 */
	public function applyTag($path, $tag)
	{
		$dom = new DOMDocument();
		$root = $dom->createElementNS(RemoteRegistry::ATOM_NS, "entry");
		$dom->appendChild($root);
		
		
		$content = $dom->createElementNS(RemoteRegistry::ATOM_NS, "content", $tag);
		$content->setAttribute("type", "text");
		$root->appendChild($content);
		
		$data = $dom->saveXML($dom->documentElement);
		
		$response =  $this->rest_client->post($this->registry_url.$path.";".RemoteRegistry::TAG_PARAMTER, $data);
		
		return $response;
	}
	
	/**
	 * get tags
	 *
	 * @param string $path
	 * @return array of string
	 */
	public function getTags($path)
	{
		$response =  $this->rest_client->get($this->registry_url.$path.";".
						RemoteRegistry::TAG_PARAMTER);
						
		$tags = array();
		
		if($this->rest_client->getLastResponseStatus() == "200")
		{
			$resource = $this->createResourceFromFeed($response);
			$feed_xml = $this->last_feed_xml;
			if($feed_xml->entry !== NULL)
			{
				foreach($feed_xml->entry as $entry)
				{
					$taggings = $entry->taggings."";
					if($taggings == "1")
					{
						$tag = $entry->title."";
						$tags[count($tags)] = $tag;
					}
				}
			}
		}
		
		return $tags;		
	}
	
	/**
	 * get resource paths for a given tag
	 *
	 * @param string $tag
	 * @return Resource which contains 
	 */
	public function getResourcePathsWithTag($tag)
	{

		$response =  $this->rest_client->get($this->registry_url."/". ";".
						RemoteRegistry::TAGPATHS_PARAMTER.":".$tag);

		$resource = NULL;
		if($this->rest_client->getLastResponseStatus() == "200")
		{
			$resource = $this->createResourceFromFeed($response, TRUE);
		}
		
		return $resource;		
	}
	
	
	/**
	 * get versions
	 *
	 * @param string $path
	 */
	public function getVersions($path)
	{
		// TODO:
	}
	
	/**
	 * restore versions
	 *
	 * @param string $version_path
	 */
	public function restoreVersion($version_path)
	{
		// TODO:
	}
	
	private function createResourceFromFeed($feed, $no_content = FALSE)
	{
		$index = strpos($feed, "?>");
		if($index === false)
		{
			$xml_str = $feed;
		}
		else
		{
			$xml_str = substr($feed, $index+2);
		}
		$feed_xml = new SimpleXMLElement($xml_str);
		$this->last_feed_xml = $feed_xml;
		
		$resource = new Resource();
		
		/* assign author */
		if($feed_xml->author !== NULL)
		{
			$resource->author_username = $feed_xml->author->name."";
		}
		
		/* assign properties */
		$foo_ns = $feed_xml->children(RemoteRegistry::WSO2_TAG_NS);
		if($foo_ns->properties !== NULL && $foo_ns->properties->property !== NULL)
		{
			$i = 0;
			foreach($foo_ns->properties->property as $property)
			{
				$name = $property->name."";
				$value = $property->value."";
				
				
				$resource->properties[$name] = $value;
				
			}
		}
		
		
		$resource->id = $feed_xml->id."";
		$resource->subtitle = $feed_xml->subtitle."";
		$resource->title = $feed_xml->title."";
		$resource->updated = $feed_xml->updated."";
		
		
		$empty_ns = $feed_xml->children("");
		
		$resource->media_type = $empty_ns->mediaType."";
		$resource->parent_path = $empty_ns->parentPath."";
		$resource->last_updated_username = $empty_ns->lastUpdatedUser."";
		$resource->directory = $empty_ns->directory."";
		$resource->created_time = $empty_ns->createdTime."";
		
		$i = 0;
		if($feed_xml->entry !== NULL)
		{
			foreach($feed_xml->entry as $entry)
			{
				$title = $entry->title."";
				$href = "";
				foreach($entry->link as $link)
				{
					$href = $link["href"]."";
				}
				$resource->entries[$title] = $href;
			}
		}
		
		if($resource->directory !== NULL && $resource->directory."" == "true")
		{
			
		}
		else
		{
			//echo "href". $href."\n";
			if($no_content == FALSE)
			{
				$resource->content = $this->rest_client->get($href, array());
			}
		}
		
		return $resource;
	}

	/**
	 * Enter description here...
	 *
	 * @param string $name
	 * @param string $password
	 * @param string $role
	 * @param string $friendly_name
	 */
	public function addUser($name, $password, $confirm_password, $role, $friendly_name)
	{
		$dom = new DOMDocument();
		$root = $dom->createElementNS(RemoteRegistry::ATOM_NS, "entry");
		$dom->appendChild($root);
		
		$username = $dom->createElementNS(RemoteRegistry::REGISTRY_NS, "username", $name);
		$root->appendChild($username);
		
		$password_node = $dom->createElementNS(RemoteRegistry::REGISTRY_NS, "password", $password);
		$root->appendChild($password_node);
		
		$confirm_password = $dom->createElementNS(RemoteRegistry::REGISTRY_NS, "confirmpassword", $confirm_password);
		$root->appendChild($confirm_password);
		
		$role = $dom->createElementNS(RemoteRegistry::REGISTRY_NS, "rolename", $role);
		$root->appendChild($role);
		
		$friendly_name = $dom->createElementNS(RemoteRegistry::REGISTRY_NS, "friendlyName", $friendly_name);
		$root->appendChild($friendly_name);
		
		$data = $dom->saveXML($dom->documentElement);
		
		$response =  $this->rest_client->post($this->registry_url.$path.";".RemoteRegistry::ADDUSER_PARAMETER, $data);
		
		return $this->rest_client->getLastResponseStatus();
	}
}
?>
