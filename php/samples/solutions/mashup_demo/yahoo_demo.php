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
    if(isset($_GET["yahoo_query"]))
    	$yahoo_query = $_GET["yahoo_query"];
    if(isset($_GET["yahoo_method"]))
    	$yahoo_method = $_GET["yahoo_method"];
    if(isset($_GET["page"]))
	$page = $_GET["page"];

    define("RESULTS_PER_PAGE" , 10);

    /* Set the starting entry and number of entries  to return */
    $start = RESULTS_PER_PAGE * ($page-1) + 1;
    $results = RESULTS_PER_PAGE;

    /* Call service only if the query is set, ignore otherwise */
    if (isset($yahoo_query) && !empty($yahoo_query)) {

        /* Include the required class */
        require_once("wso2/yahoo/YahooClient.php");
        $yahoo_client = new YahooClient(
                "rQ8qSMLV34EQyEvRO.y7G91WlgvVIcbrfUliUtQi6AvVnX72hfd6bskjpU6rrw4l");

        /* Switch between the search type */
        switch ($yahoo_method) {
            case "news":   
                $res = $yahoo_client->newsSearch($yahoo_query, array(
                                    "start" => $start,
                                    "results" => $results));
                break;
            case "image":   
                $res = $yahoo_client->imageSearch($yahoo_query, array(
                                    "start" => $start,
                                    "results" => $results));
                break;
            default: 
                $res = $yahoo_client->webSearch($yahoo_query, array(
                                    "start" => $start,
                                    "results" => $results));
        }
        /* Check for the soap - fault */
        if (isset($res["soap-fault"])) {
            $soap_reason = $res["soap-fault-reason"];
            printf("SOAP fault : ${soap_reason}\n");
        }
        /* Check for the error */
        elseif (isset($res["error"])) {
            $error_message = $res["error-msg"];
            printf("Error Message: ${error_message}\n");
        }
        /* Render the response if no errors occured */
        elseif ($res["results"] != NULL) {
            /* yahoo returns results by entry not by pages*/
            $total = $res["total"];
            $start = $res["start"];

            /* convert to pages */
            $page = ceil($start/ RESULTS_PER_PAGE);
            $pages =ceil($total/ RESULTS_PER_PAGE);

            /* Render number bar, to enables access pages by numbers */
            $next_exist = true;
            $prev_exist = true;

            $end_list = 10;
            if ($pages - $page <= $end_list) {
                $end_list = $pages -$page;
                $next_exist = true;
            }
            if ($page == 1) {
                $prev_exist = false;
            }

            $number_bar = "";

            $number_bar .= "<div style='padding:20px'>";

            if ($prev_exist) {
                $prev_page = $page -1;
                $number_bar .= "<a href='javascript:yahooRequest(\"${yahoo_method}\", ${prev_page})'>&lt;&lt;</a> ";
            }

            for ($i = 0; $i < $end_list; $i ++) {
                $page_no = $page + $i;
                $number_bar .= "<a href='javascript:yahooRequest(\"${yahoo_method}\", ${page_no})'>${page_no}</a> ";
            }
           
            if ($next_exist) {
                $next_page = $page +11;
                $number_bar .= "<a href='javascript:yahooRequest(\"${yahoo_method}\", ${next_page})'>&gt;&gt;</a> ";
            }
            $number_bar .= "</div>";

            echo $number_bar;

            echo "<ol start=\"1\">";

            /* Extract information of each result */
            foreach ($res["results"] as $result) {

                echo "<li>";
                switch ($yahoo_method) {
                    case "news":
                        $title = $result["Title"];
                        $summary = $result["Summary"];
                        $url = $result["Url"];
                        $click_url = $result["ClickUrl"];
                        $news_source = $result["NewsSource"];
                        $news_source_url = $result["NewsSourceUrl"];

                        $language = $result["Language"];
                        $published = date("F j, Y, g:i:s a", $result["PublishDate"]);
                        $modified = date("F j, Y, g:i:s a", $result["ModificationDate"]);

                        echo "<div style=\"text-align:left; padding-bottom:15px\">";
                        echo "<h3><a href=\"${click_url}\">${title}</a></h3>";
                        echo "<p>${summary}</p>";
                        echo "<font color=\"blue\"> News Source : <a href=\"${news_source_url}\">${news_source}</a></font></br>";
                        echo "<font color=\"blue\">Published Date: ${published} - Last Modified Date: ${modified}</font>";
                        echo "</div>";

                        break;
                    case "image":
                        $title = $result["Title"];
                        $summary = $result["Summary"];
                        $url = $result["Url"];
                        $click_url = $result["ClickUrl"];
                        $file_size = $result["FileSize"];

                        $height = $result["Height"];
                        $width = $result["Width"];
                        $thumbnail_url = $result["Thumbnail"]["Url"];


                        echo "<div style=\"text-align:left; padding-bottom:15px\">";
                        echo "<img style=\"cursor:pointer\" src='${thumbnail_url}' onclick=\"window.location.href='${click_url}'\"></img>";
                        echo "<h3><a href=\"${click_url}\">${title}</a></h3>";
                        echo "<p>${summary}</p>";
                        echo "<font color=\"blue\"> - Size: ${width} x ${height}</font>";
                        echo "</div>";
                        break;
                    default:
                        $title = $result["Title"];
                        $summary = $result["Summary"];
                        $url = $result["Url"];
                        $click_url = $result["ClickUrl"];
                        $display_url = $result["DisplayUrl"];
                        $cache_size = $result["Cache"]["Size"];
                        $cache_url = $result["Cache"]["Url"];

                        echo "<div style=\"text-align:left; padding-bottom:15px\">";
                        echo "<h3><a href=\"${click_url}\">${title}</a></h3>";
                        echo "<p>${summary}</p>";
                        echo "<font color=\"blue\"> - ${cache_size}k - <a href=\"${cache_url}\">Cached</a></font>";
                        echo "</div>";
                }
                echo "<div class=\"clear\">&nbsp;</div>";
                echo "</li>";
            
            }
            echo "</ol>";
            
            echo $number_bar;
        }
        else
        {
            echo "Empty <br/>";
        }
    }
?>

