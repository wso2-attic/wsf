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

class AmazonClient extends WSClient
{
    const SOAP_FAULT = "soap-fault";
    const SOAP_FAULT_REASON = "soap-fault-reason";
    const ERROR = "error";
    const ERROR_MSG = "error-msg";
    const RESPONSE_XML = "str";
    const RESPONSE_DOM = "dom";
    const RESULTS = "results";
 
    /** functions */
    const ITEM_SEARCH_METHOD = "ItemSearch";
    const ITEM_LOOKUP_METHOD = "ItemLookup";

    /** endpoints */
    const AMAZON_ENDPOINT = "http://webservices.amazon.com/onca/xml";
    //const AMAZON_ENDPOINT = "http://localhost:8080/onca/xml";

    /** 
     * Your Amazon Application key
     * @var string
     */
    public $amazon_key;

    /**
     * Construct the AmazonClient
     * @param $amazon_key Amazon App Key
     */
    public function __construct($amazon_key)
    {
        parent::__construct(array(
                              "to"=>self::AMAZON_ENDPOINT,
                              "HTTPMethod"=>GET,
                              "useSOAP"=>FALSE));
        $this->amazon_key = $amazon_key;
    }

  
    /**
     * Search Web
     * @param $query query string
     * @param $catagory catagory to search
     * @param $page page number to return
     * @param $options associate array consist of other options to search
     * @return associate array consist of the response parameters
     */  
    public function itemSearch($query, $catagory, 
                    $page, array $options = array())
    {
        $req_options = array(
                "Service" => AWSECommerceService,
                "AWSAccessKeyId" => $this->amazon_key,
                "Operation" => "ItemSearch",
                "Keywords" => $query,
                "ResponseGroup" => "Medium",
                "SearchIndex" => $catagory,
                "ItemPage" => $page,
                );

        $req_payload = $this->buildRequestPayload(self::ITEM_SEARCH_METHOD, $req_options);

        try {
            $res = $this->request($req_payload);

        }
        catch(Exception $e) {
            return $this->handleException($e);
        }

        $ret = $this->extractResponse($res->str);
        return $ret;
    }

    /**
     * Spell itemLookup
     * @param $item_id Item_id
     * @param @search_index SearchIndex
     * @title 
     * @return associate array consist of the response parameters
     */  
    public function itemLookup($item_id, $search_index)
    {
        $options = array(
                "Service" => AWSECommerceService,
                "IdType" => "ASIN",
                "SearchIndex" => $search_index,
                "AWSAccessKeyId" => $this->amazon_key,
                "Operation" => "ItemSearch",
                "ItemId" => $item_id);

        $req_payload = $this->buildRequestPayload(self::ITEM_LOOKUP_METHOD, $options);

        try {
            $res = $this->request($req_payload);
        }
        catch(Exception $e) {
            return $this->handleException($e);
        }

        $ret = $this->extractResponse($res->str);

        return $ret;

    }

    
    private function extractResponse($res_xml)
    {
        $res = array();
        if ($res_xml === NULL) {
            return $res; // in a case of a fault or an error
        }
        $res_dom = new DomDocument();

        $res_dom->loadXML($res_xml);
        $res[self::RESPONSE_XML] = $res_xml;
        $res[self::RESPONSE_DOM] = $res_dom;

        $results= array();
        $index = 0;

        if ($res_dom !== NULL) {
            $root = $res_dom->documentElement;
            
            if ($root !== NULL && $root->hasChildNodes()) {
                foreach ($root->childNodes as $childs_dom) {
                    if ($childs_dom->nodeType != XML_ELEMENT_NODE) {
                        continue; 
                    }


                    if ($childs_dom->tagName == "Items") {
                        foreach ($childs_dom->childNodes as $item) {
                            if ($item-> nodeType == XML_ELEMENT_NODE &&
                                    $item->tagName == "Item") {
                                $results[$index++] = $this->decodeXML($item);
                            }

                            if ($item->nodeType == XML_ELEMENT_NODE &&
                                    $item->tagName == "TotalPages" ) {
                                $res["pages"] = $item->firstChild->nodeValue;
                            }
                        }
                    }
                }
            }
        }
        $res[self::RESULTS] = $results;
        return $res;
    }
   
    private function decodeXML($node)
    {
        $result = array();
        foreach ($node->childNodes as $child) {
             if ($child->nodeType == XML_TEXT_NODE) {
                 if ($child == $node->firstChild && $child == $node->lastChild) {
                     return $child->nodeValue;
                 }
                 else {
                     //garbage
                     continue;
                 }
             }
             else if ($child->nodeType == XML_ELEMENT_NODE) {
                 $tag_name = $child->tagName;
                 $result[$tag_name] = $this->decodeXML($child); 
             }
        }
        return $result;
    }

    private function buildRequestPayload($method_name, $options) {
        $xml = "";

        foreach ($options as $key=> $value) {
             if (empty($key)) {
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
