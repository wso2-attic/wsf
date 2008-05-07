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
    
    /* Extract the arguments from HTTP GET request */
    $flickr_query = $_GET["flickr_query"];
    $flickr_method = $_GET["flickr_method"];        
    $flickr_key = $_GET["flickr_key"];
	
    $taken_start_year= $_GET["taken_start_year"];
    $taken_start_month= $_GET["taken_start_month"];
    $taken_start_day= $_GET["taken_start_day"];
                                      
    $taken_end_year= $_GET["taken_end_year"];
    $taken_end_month= $_GET["taken_end_month"];
    $taken_end_day= $_GET["taken_end_day"];
                                                 
    $uploaded_start_year= $_GET["uploaded_start_year"];
    $uploaded_start_month= $_GET["uploaded_start_month"];
    $uploaded_start_day= $_GET["uploaded_start_day"];
                                             
    $uploaded_end_year= $_GET["uploaded_end_year"];
    $uploaded_end_month= $_GET["uploaded_end_month"];
    $uploaded_end_day= $_GET["uploaded_end_day"];

    $page = $_GET["page"];

    $options = array();

    /* Set the page to return */
    if(isset($page)) {
        $options["page"] = $page;
    }

    /* If uploaded start year is set the options will be
       included to control the inputs */
    if(isset($uploaded_start_year)) {

        $taken_start = mktime(0, 0, 0, $taken_start_month, $taken_start_day, $taken_start_year);
        $taken_end = mktime(23, 59, 59, $taken_end_month, $taken_end_day, $taken_end_year);
    
        $uploaded_start = mktime(0, 0, 0, $uploaded_start_month, $uploaded_start_day, $uploaded_start_year);
        $uploaded_end = mktime(23, 59, 59, $uploaded_end_month, $uploaded_end_day, $uploaded_end_year);

        $options["min_taken_date"] = $taken_start;
        $options["max_taken_date"] = $taken_end;
        $options["min_upload_date"] = $uploaded_start;
        $options["max_upload_date"] = $uploaded_end;
    }

    /* Set the default search to tag search */
    if(!isset($flickr_method) || empty($flickr_method)) {
        $flickr_method = "tags";
    }

    /* Call service only if the query is set, ignore otherwise */
if(isset($flickr_query) && !empty($flickr_query) && isset($flickr_key)) {
        /* Include the required class */
        require_once("wso2/flickr/FlickrClient.php");  
	
	$flickr_client = new FlickrClient($flickr_key);
        if($flickr_method === "text") {
            $res = $flickr_client->photosTextSearch($flickr_query, $options);
        }
        else {
            $res = $flickr_client->photosTagSearch($flickr_query, $options);
        }

        /* Check for the soap - fault */
        if($res["soap-fault"]) {
            $soap_reason = $res["soap-fault-reason"];
            printf("SOAP fault : ${soap_reason}\n");
        }
        /* Check for the error */
        elseif($res["error"]) {
            $error_message = $res["error-msg"];
            printf("Error Message: ${error_message}\n");
        }
        /* Render the response if no errors occured */
        elseif ($res["photos"] != NULL) {

            /* Calculating and Rendering the Number bar to access page by
             number */
            $page = $res["page"];
            $total = $res["total"];
            $pages = $res["pages"];

            $next_exist = true;
            $prev_exist = true;

            $end_list = 10;
            if (($pages - $page) <= $end_list) {
                $end_list = $pages - $page;
                $next_exist = false;
            }
            if ($page == 1) {
                $prev_exist = false;
            }

            $number_bar = "";
            $number_bar .= "<div style='padding:20px'>";

            if ($prev_exist) {
                $prev_page = $page -1;
                $number_bar .= "<a href='javascript:flickrRequest(${prev_page})'>&lt;&lt;</a> ";
            }

            for ($i = 0; $i < $end_list; $i ++) {
                $page_no = $page + $i;
                $number_bar .= "<a href='javascript:flickrRequest(${page_no})'>${page_no}</a> ";
            }
           
            if ($next_exist) {
                $next_page = $page +11;
                $number_bar .= "<a href='javascript:flickrRequest(${next_page})'>&gt;&gt;</a> ";
            }
            $number_bar .= "</div>";

            echo $number_bar;

            /* Extract information of each photos */

            foreach($res["photos"] as $photo) {
                $title = $photo["title"];
                $thumbnail_url = $photo["thumbnail_size_url"];
                $original_url = $photo["original_size_jpg"];
                $big_url = $photo["big_size_url"];

                echo "<div>";
                echo "<a href='${big_url}'><img style=\"cursor:pointer\"".
                    "src='${thumbnail_url}'></img></a><br/>";
                echo "</div>";
                echo "<div style='padding-bottom:20px'>";
                echo "${title} ";
                echo "<a href='${thumbnail_url}'>Thumbnail</a> ";
                echo "<a href='${original_url}'>Original</a>";
                echo "</div>";
            }
            
            echo $number_bar;

        }
        else {
            echo "Empty <br/>";
        }
    }
?>
