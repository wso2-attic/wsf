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

class FlickrClient extends WSClient
{
    const ENDPOINT = "http://api.flickr.com/services/soap/";
    
    const RESPONSE_XML = "response-xml";
    const RESPONSE_DOM = "response-dom";
    const SOAP_FAULT = "soap-fault";
    const SOAP_FAULT_REASON = "soap-fault";
    const ERROR = "error";
    const ERROR_MSG = "error-msg";

    //constants on retrieving information about photos 
    const PHOTO_TITLE = "title";
    const MEDIUM_SIZE_PHOTO_URL = "medium_size_url";
    const SMALL_SIZE_PHOTO_URL = "small_size_url";
    const THUMBNAIL_SIZE_PHOTO_URL = "thumbnail_size_url";
    const BIG_SIZE_PHOTO_URL = "big_size_url";
    const ORIGINAL_JPG_PHOTO_URL = "original_size_jpg";
    const ORIGINAL_GIF_PHOTO_URL = "original_size_gif";
    const ORIGINAL_PNG_PHOTO_URL = "original_size_png";

    //list of functions
    const PHOTO_SEARCH_FUNC = "flickr.photos.search";

    const PHOTOS = "photos";

    /** 
     * Your Flickr API key
     * @var string
     */
    public $api_key;

    /**
     * Construct the FlickrClient
     * @param $api_key Flickr API Key
     */
    public function __construct($api_key)
    {
        parent::__construct(array(
                             "to"=> self::ENDPOINT));
        $this->api_key = $api_key;
    }


    /**
     * Search photos based on the text
     * @param $text Text to search among photo texts
     * @param $options associate array consist of other options to search
     * @return associate array consist of the response parameters
     */
    public function photosTextSearch($text, array $options = array())
    {
        $req_options = array();
        /* query should be the first argument */
        $req_options["text"] = $text;

        $this->prepareRequestOptions($options, $req_options);

        return $this->photosSearch($req_options);
    }
 
    /**
     * Search photos based on the tags
     * @param $tag Tag to search among photo tags
     * @param $options associate array consist of other options to search
     * @return associate array consist of the response parameters
     */
    public function photosTagSearch($tags, array $options = array())
    {
        $req_options = array();
        $req_options["tags"] = $tags;

        $this->prepareRequestOptions($options, $req_options);

        return $this->photosSearch($req_options);
    }

    private function prepareRequestOptions($options, &$req_options)
    {
        /* copying request options, just to make sure they
           are in the correct order */
        if(isset($options["min_upload_date"]))
            $req_options["min_upload_date"] = $options["min_upload_date"];
        if(isset($options["max_upload_date"]))
            $req_options["max_upload_date"] = $options["max_upload_date"];
        if(isset($options["min_taken_date"]))
            $req_options["min_taken_date"] = $options["min_taken_date"];
        if(isset($options["max_taken_date"]))
            $req_options["max_taken_date"] = $options["max_taken_date"];
        if(isset($options["page"]))
            $req_options["page"] = $options["page"];
    }
  
    /**
     * Search photos in general
     * @param $options associate array consist of other options to search
     * @return associate array consist of the response parameters
     */  
    public function photosSearch(array $options = array())
    {
        $req = $this->buildRequestPayload(self::PHOTO_SEARCH_FUNC, $options);
        try {
            $res = $this->request($req);
        }
        catch(Exception $e)
        {
            return $this->handleException($e);
        }
        
        $ret = $this->extractPhotoResponse($res->str);

        return $ret;
    }

    
    private function extractPhotoResponse($res_xml)
    {
        if($res_xml === NULL)
        {
            return NULL; // in a case of a fault or an error
        }
        $res_dom = new DomDocument();
       
        $res_xml = htmlspecialchars_decode($res_xml);

        $res_dom->loadXML($res_xml);

        $photos = array();
        $index = 0;

        $ret = array();

        if($res_dom !== NULL)
        {
            $root = $res_dom->documentElement;
            $params = $root->firstChild;
            
            while($params->nodeType == XML_TEXT_NODE)
            {
                $params = $params->nextSibling;
            }

            $ret["page"] = $params->getAttribute("page");
            $ret["total"] = $params->getAttribute("total");
            $ret["pages"] = $params->getAttribute("pages");
            $ret["perpage"] = $params->getAttribute("perpage");


            if($params !== NULL && $params ->hasChildNodes())
            {
                foreach($params->childNodes as $param_dom)
                {
                    if($param_dom->nodeType != XML_ELEMENT_NODE)
                    {
                        continue; 
                    }
    
                    $id = $param_dom->getAttribute("id");
                    $title = $param_dom->getAttribute("title");
                    $farm_id = $param_dom->getAttribute("farm");
                    $server_id = $param_dom->getAttribute("server");
                    $secret = $param_dom->getAttribute("secret");
    
                    $photo_url_m= "http://farm${farm_id}.static.flickr.com/${server_id}/${id}_${secret}_m.jpg";
                    $photo_url_s= "http://farm${farm_id}.static.flickr.com/${server_id}/${id}_${secret}_s.jpg";
                    $photo_url_t= "http://farm${farm_id}.static.flickr.com/${server_id}/${id}_${secret}_t.jpg";
                    $photo_url_b= "http://farm${farm_id}.static.flickr.com/${server_id}/${id}_${secret}_b.jpg";
                    $photo_url_o_jpg= "http://farm${farm_id}.static.flickr.com/${server_id}/${id}_${secret}_o.jpg";
                    $photo_url_o_gif= "http://farm${farm_id}.static.flickr.com/${server_id}/${id}_${secret}_o.jif";
                    $photo_url_o_png= "http://farm${farm_id}.static.flickr.com/${server_id}/${id}_${secret}_o.png";
    
                    $photos[$index] = array();
                    $photos[$index][self::PHOTO_TITLE] = $title; 
                    $photos[$index][self::MEDIUM_SIZE_PHOTO_URL] = $photo_url_m; 
                    $photos[$index][self::SMALL_SIZE_PHOTO_URL] = $photo_url_s; 
                    $photos[$index][self::THUMBNAIL_SIZE_PHOTO_URL] = $photo_url_t; 
                    $photos[$index][self::BIG_SIZE_PHOTO_URL] = $photo_url_b; 
                    $photos[$index][self::ORIGINAL_JPG_PHOTO_URL] = $photo_url_o_jpg; 
                    $photos[$index][self::ORIGINAL_GIF_PHOTO_URL] = $photo_url_o_gif; 
                    $photos[$index][self::ORIGINAL_PNG_PHOTO_URL] = $photo_url_o_png; 
                  
                    $index ++; 
                }
            }
        }
       
        $ret[self::PHOTOS] = $photos;
        return $ret;
    }

    private function buildRequestPayload($method_name, $options)
    {
        $xml = "<method>${method_name}</method>";
        $xml .= "<api_key>{$this->api_key}</api_key>";

        foreach($options as $key=> $value)
        {
             if(empty($key))
             {
                 continue;
             }
             $xml .= "<${key}>${value}</${key}>";
        }
        $xml = "<x:FlickrRequest xmlns:x=\"urn:flickr\">${xml}</x:FlickrRequest>";

        return $xml;
    }

    private function handleException($e) {
        $res_array = array();
        if ($e instanceof WSFault) {
            $res_array[self::SOAP_FAULT] = TRUE;
            $res_array[self::SOAP_FAULT_REASON] = $e->Reason;;
            /*echo "SOAP FAULT: ".$e->Reason."\n";*/
        }
        else {
            $res_array[self::ERROR] = TRUE;
            $res_array[self::ERROR_MSG] = $e->getMessage();
            /*echo "ERROR_MSG: ".$e->getMessage()."\n";*/
        }
        return $res_array;
    }
}
?>
