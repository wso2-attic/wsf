<?php
/*
 * Copyright 2005,2008 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

class YahooClient extends WSClient
{
    const SOAP_FAULT = "soap-fault";
    const SOAP_FAULT_REASON = "soap-fault-reason";
    const ERROR = "error";
    const ERROR_MSG = "error-msg";
    const RESPONSE_XML = "str";
    const RESPONSE_DOM = "dom";
    const RESULTS = "results";
 
    /** functions */
    const WEB_SEARCH_METHOD = "webSearch";
    const IMAGE_SEARCH_METHOD = "imageSearch";
    const NEWS_SEARCH_METHOD = "newsSearch";
    const LOCAL_SEARCH_METHOD = "localSearch";

    /** endpoints */
    const WEB_SEARCH_ENDPOINT = "http://api.search.yahoo.com/WebSearchService/V1/webSearch";
    const IMAGE_SEARCH_ENDPOINT = "http://api.search.yahoo.com/ImageSearchService/V1/imageSearch";
    const NEWS_SEARCH_ENDPOINT = "http://api.search.yahoo.com//NewsSearchService/V1/newsSearch";
    const LOCAL_SEARCH_ENDPOINT = "http://api.local.yahoo.com/LocalSearchService/V1/localSearch";

    /** 
     * Your Yahoo Application key
     * @var string
     */
    public $app_id;

    /**
     * Construct the YahooClient
     * @param $app_id Yahoo App Key
     */
    public function __construct($app_id)
    {
	parent::__construct(array("HTTPMethod" => "GET", "useSOAP" => FALSE));
        $this->app_id = $app_id;
    }

  
    /**
     * Search Web
     * @param $query query string
     * @param $options associate array consist of other options to search
     * @return associate array consist of the response parameters
     */  
    public function webSearch($query, array $options = array())
    {
        $options["query"] = $query;

        $options = $this->prepareRequestOptions($options);

        $req_payload = $this->buildRequestPayload(self::WEB_SEARCH_METHOD, $options);

        $req_msg = new WSMessage($req_payload, array("to"=> self::WEB_SEARCH_ENDPOINT));

        try {
            $res = $this->request($req_msg);
        }
        catch(Exception $e)
        {
            return $this->handleException($e);
        }

        $ret = $this->extractResponse($res->str);
        return $ret;
    }

    /**
     * Search News
     * @param $query query string
     * @param $options associate array consist of other options to search
     * @return associate array consist of the response parameters
     */  
    public function newsSearch($query, array $options = array())
    {
        $options["query"] = $query;
        
        $options = $this->prepareRequestOptions($options);

        $req_payload = $this->buildRequestPayload(self::NEWS_SEARCH_METHOD, $options);
        $req_msg = new WSMessage($req_payload, array("to"=> self::NEWS_SEARCH_ENDPOINT));

        try {
            $res = $this->request($req_msg);
        }
        catch(Exception $e)
        {
            return $this->handleException($e);
        }

        $ret = $this->extractResponse($res->str);

        return $ret;

    }

    /**
     * Search Images
     * @param $query query string
     * @param $options associate array consist of other options to search
     * @return associate array consist of the response parameters
     */  
    public function imageSearch($query, array $options = array())
    {
        $options["query"] = $query;
        
        $options = $this->prepareRequestOptions($options);

        $req_payload = $this->buildRequestPayload(self::IMAGE_SEARCH_METHOD, $options);
        $req_msg = new WSMessage($req_payload, array("to"=> self::IMAGE_SEARCH_ENDPOINT));

        try {
            $res = $this->request($req_msg);
        }
        catch(Exception $e)
        {
            return $this->handleException($e);
        }

        $ret = $this->extractResponse($res->str);

        return $ret;
    }

    /**
     * Search Locations
     * @param $query query string
     * @param $options associate array consist of other options to search
     * @return associate array consist of the response parameters
     */  
    public function localSearch($query, array $options = array())
    {
        $options["query"] = $query;
        
        $options = $this->prepareRequestOptions($options);

        $req_payload = $this->buildRequestPayload(self::LOCAL_SEARCH_METHOD, $options);
        $req_msg = new WSMessage($req_payload, array("to"=> self::LOCAL_SEARCH_ENDPOINT));

        try {
            $res = $this->request($req_msg);
        }
        catch(Exception $e)
        {
            return $this->handleException($e);
        }

        $ret = $this->extractResponse($res->str);

        return $ret;
    }

    /**
     * Call xml web service in general
     * @param $method_name method name
     * @param $options associate array consist of options
     * @param $endpoint endpoint url
     * @return associate array consist of the response parameters
     */
    public function call_ws($query, $method_name, array $options, $endpoint)
    {
        $xml = "";

        $options["query"] = $query;
        $options["appid"] = $this->app_id;

        $keys = array_keys($options);
        foreach($keys as $key)
        {
             if(empty($key))
             {
                 continue;
             }
             $value = $options[$key];
             $xml .= "<${key}>${value}</${key}>";
        }
        $xml = "<${method_name}>".$xml."</${method_name}>";
        $yahoo_client = new WSClient(
            array("to"=>$endpoint,
                  "HTTPMethod"=>GET,
                  "useSOAP"=>FALSE));

        $res = array();
        try
        {
            $res_msg = $yahoo_client->request($xml);
            $res[self::RESPONSE_XML] = $res_msg->str;
            $res = $this->extractResponse($res); 
        }
        catch(Exception $e)
        {
            if ($e instanceof WSFault)
            {
                $res[self::SOAP_FAULT] = TRUE;
                $res[self::SOAP_FAULT_REASON] = $e->Reason;;
            }
            else
            {
                $res[self::ERROR] = TRUE;
                $res[self::ERROR_MSG] = $e->getMessage();
            }
        }
        return $res;
    }

    private function prepareRequestOptions($options)
    {
	
        $ret_options = array();
	if(isset($options["appid"]))
		$ret_options["appid"] = $options["appid"];
	if(isset($options["query"]))
                $ret_options["query"] = $options["query"];
        /* copying request options, just to make sure they
           are in the correct order */

        if(isset($options["resuts"]))
            $ret_options["resuts"] = $options["results"];

        if(isset($options["start"]))
            $ret_options["start"] = $options["start"];

        return $ret_options;
    }
    
    private function extractResponse($res_xml)
    {
        $res = array();
        if($res_xml === NULL)
        {
            return $res; // in a case of a fault or an error
        }
        $res_dom = new DOMDocument();
        $res_dom->loadXML($res_xml);
        $res[self::RESPONSE_XML] = $res_xml;
        $res[self::RESPONSE_DOM] = $res_dom;


        $results= array();
        $index = 0;

        if($res_dom !== NULL)
        {
            $root = $res_dom->documentElement;
            
            $res["total"] = $root->getAttribute("totalResultsAvailable");
            $res["start"] = $root->getAttribute("firstResultPosition");
            $res["perpage"] = $root->getAttribute("totalResultsReturned");
            
            if($root !== NULL && $root->hasChildNodes())
            {
                foreach($root->childNodes as $result_dom)
                {
                    if($result_dom->nodeType != XML_ELEMENT_NODE)
                    {
                        continue; 
                    }
                    
                    $results[$index++] = $this->decodeXML($result_dom);
                }
            }
        }
        $res[self::RESULTS] = $results;
        return $res;
    }
   
    private function decodeXML($node)
    {
        $result = array();
        foreach($node->childNodes as $child)
        {
             if($child->nodeType == XML_TEXT_NODE)
             {
                 if($child == $node->firstChild && $child == $node->lastChild)
                 {
                     return $child->nodeValue;
                 }
                 else
                 {
                     //garbage
                     continue;
                 }
             } 
             else if($child->nodeType == XML_ELEMENT_NODE)
             {
                 $tag_name = $child->tagName;
                 $result[$tag_name] = $this->decodeXML($child); 
             } 
        }
        return $result;
    }

    private function buildRequestPayload($method_name, $options) {
        $xml = "";

        $options["appid"] = $this->app_id;

        foreach($options as $key=> $value)
        {
             if(empty($key))
             {
                 continue;
             }
             $xml .= "<${key}>${value}</${key}>";
        }
        $xml = "<${method_name}>".$xml."</${method_name}>";

        return $xml;
    }


    private function handleException($e) {
        $res_array = array();
        if ($e instanceof WSFault) {
            $res_array[self::SOAP_FAULT] = TRUE;
            $res_array[self::SOAP_FAULT_REASON] = $e->Reason;;
        }
        else {
            $res_array[self::ERROR] = TRUE;
            $res_array[self::ERROR_MSG] = $e->getMessage();
        }
        return $res_array;
    }


}
?>
