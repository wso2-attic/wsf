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

/**
 * RestClient interface for PHP
 *
 */
class RESTClient
{
	private $with_curl;
	
	const USER_AGENT = 'RESTClient PHP Library Class';
	
	private $username;
	private $password;
	
	private $status;

    /**
     * Constructor of the RESTClient
     */
	public function __construct($username = NULL, $passoword = NULL)
	{
		if(function_exists("curl_init"))
		{
			$this->with_curl = TRUE;
		}
		else
		{
			$this->with_curl = FALSE;
		}
		$this->username = $username;
		$this->password = $passoword;
		
	}

    /**
     * Call the HTTP 'GET' method
     * @param string $url URL of the service..
     * @param array $params request parameters, hash of (key,value) pairs
     * @return response string
     */
	public function get($url, $params = NULL)
	{
		if($params !== NULL)
		{
			$params_str = "?";
			if(is_array($params))
			{
				foreach($params as $key=> $value)
				{
					$params_str .= urlencode($key)."=".urlencode($value)."&";
				}
			}
			else
			{
				$params_str .= $params;
			}
		
			$url .= $params_str;
		}
		
		$result = "";
		
		if($this->with_curl)
		{
  			$curl = curl_init();
  			
      		curl_setopt($curl, CURLOPT_URL, $url);
      		curl_setopt($curl, CURLOPT_HTTPGET, TRUE);
      		curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
      		curl_setopt($curl, CURLOPT_USERAGENT, RESTClient::USER_AGENT);
      		if($this->username !== NULL)
      		{
				curl_setopt($curl, CURLOPT_USERPWD, "{$this->username}:{$this->password}");
      		}
      		$result = curl_exec($curl);
      		
      		$this->status = curl_getinfo($curl,CURLINFO_HTTP_CODE);
      		
      		curl_close($curl);
		}
		else
		{
			$username_str = "{$this->username}:{$this->password}";
			$auth_string = "Basic " + base64_encode($username_str);
			
			$opts = array(
			  'http'=>array(
			    'method'=>"GET",
			    'header'=>"User-Agent: ".RESTClient::USER_AGENT."\r\n".
						  "Authorization: ".$auth_string."\r\n"
			  )
			);
			
			$context = stream_context_create($opts);
			
			$fp = fopen($url, 'r', false, $context);
			$result = fpassthru($fp);
			fclose($fp);
		}
		return $result;
	}
	
    /**
     * Call the HTTP 'POST' method
     * @param string $url URL of the service..
     * @param string $data request data
     * @param array $content_type the http content type
     * @return response string
     */
	public function post($url, $data, $content_type = "application/atom+xml;type=entr")
	{		
		$result = "";
		
		if($this->with_curl)
		{
  			$curl = curl_init();
  			curl_setopt($curl, CURLOPT_HTTPHEADER, Array("Content-Type: ".$content_type));
      		curl_setopt($curl, CURLOPT_URL, $url);
      		curl_setopt($curl, CURLOPT_POST, TRUE);
      		curl_setopt($curl, CURLOPT_POSTFIELDS, $data);
      		if($this->username !== NULL)
      		{
				curl_setopt($curl, CURLOPT_USERPWD, "{$this->username}:{$this->password}");
      		}
      		curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
      		curl_setopt($curl, CURLOPT_USERAGENT, RESTClient::USER_AGENT);
      		$result = curl_exec($curl);
      		$this->status = curl_getinfo($curl,CURLINFO_HTTP_CODE);
      		curl_close($curl);
		}
		else
		{
			$username_str = "{$this->username}:{$this->password}";
			$auth_string = "Basic " + base64_encode($username_str);
			
			$opts = array(
			  'http'=>array(
			    'method'=>"POST",
			    'header'=>"User-Agent: ".RESTClient::USER_AGENT."\r\n".
						  "Authorization: ".$auth_string."\r\n".
						  "Content-Type: ".$content_type."\r\n".
						  "Content-length: " . strlen($data)."\r\n",
			     'content' => $data
			  )
			);
			
			$context = stream_context_create($opts);
			
			$fp = fopen($url, 'r', false, $context);
			$result = fpassthru($fp);
			fclose($fp);
		}
		
		return $result;
	}
	
    /**
     * Call the HTTP 'PUT' method
     * @param string $url URL of the service..
     * @param string $data request data
     * @return response string
     */
	public function put($url, $data)
	{
		$result = "";
		
		if($this->with_curl)
		{
    		
    		$fh = fopen('php://memory', 'rw');
  			fwrite($fh, $data);
  			rewind($fh);
    		
  			$curl = curl_init();
      		
  			
      		if($this->username !== NULL)
      		{
				curl_setopt($curl, CURLOPT_USERPWD, "{$this->username}:{$this->password}");
      		}
      		curl_setopt($curl, CURLOPT_USERAGENT, RESTClient::USER_AGENT);      		
      		curl_setopt($curl, CURLOPT_INFILE, $fh);
      		curl_setopt($curl, CURLOPT_INFILESIZE, strlen($data));
      		curl_setopt($curl, CURLOPT_TIMEOUT, 10);
      		curl_setopt($curl, CURLOPT_PUT, 1);
      		curl_setopt($curl, CURLOPT_URL, $url);
      		curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
      		//curl_setopt($curl, CURLOPT_HTTPHEADER, array("Expect: "));
      		$result = curl_exec($curl);
      		
      		$this->status = curl_getinfo($curl,CURLINFO_HTTP_CODE);
      		curl_close($curl);
      		
      		fclose($fh);
		} 
		else 
		{
			/* This executes when only curl is not installed,
			   This was not working with 'PUT' */
			
			$username_str = "{$this->username}:{$this->password}";
			$auth_string = "Basic " + base64_encode($username_str);
			
			$opts = array(
			  'http'=>array(
			    'header'=>"User-Agent: ".RESTClient::USER_AGENT."\r\n".
						  "Authorization: ".$auth_string."\r\n"
			  )
			);
			
			$context = stream_context_create($opts);
			
			$fp = fopen($url, 'w', false, $context);
			$result = fwrite($fp, $data);
			fclose($fp);
		}
		
		return $result;
	}
	
    /**
     * Call the HTTP 'DELETE' method
     * @param string $url URL of the service..
     * @param array $params request parameters, hash of (key,value) pairs
     */
	public function delete($url, $params = NULL)
	{
		if($params !== NULL)
		{
			$params_str = "?";
			if(is_array($params))
			{
				foreach($params as $key=> $value)
				{
					$params_str .= urlencode($key)."=".urlencode($value)."&";
				}
			}
			else
			{
				$params_str .= $params;
			}
			
			$url .= $params_str;
		}
		
		$result = "";
		
		if($this->with_curl)
		{
  			$curl = curl_init();
      		if($this->username !== NULL)
      		{
				curl_setopt($curl, CURLOPT_USERPWD, "{$this->username}:{$this->password}");
      		}
      		curl_setopt($curl, CURLOPT_URL, $url);
      		curl_setopt($curl, CURLOPT_CUSTOMREQUEST, "DELETE");
      		curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
      		curl_setopt($curl, CURLOPT_USERAGENT, RESTClient::USER_AGENT);
      		$result = curl_exec($curl);
      		
      		$this->status = curl_getinfo($curl,CURLINFO_HTTP_CODE);
      		curl_close($curl);
		}
		else
		{
			/* This executes when only curl is not installed,
			   This was not working with 'DELETE' */
			$username_str = "{$this->username}:{$this->password}";
			$auth_string = "Basic " + base64_encode($username_str);
			
			$opts = array(
			  'http'=>array(
			    'header'=>"User-Agent: ".RESTClient::USER_AGENT."\r\n".
						  "Authorization: ".$auth_string."\r\n"
			  )
			);
			
			$context = stream_context_create($opts);
			
			unlink($url, $context);
		}
		
	}
	
	public function getLastResponseStatus()
	{
		return $this->status;
	}
	
}
?>
