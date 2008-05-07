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
    $amazon_query = $_GET["amazon_query"];
    $amazon_index = $_GET["amazon_index"];
    $amazon_key   = $_GET["amazon_key"];

    $page = $_GET["page"];

    /* Call service only if the query is set, ignore otherwise */
    if (isset($amazon_query) && !empty($amazon_query) && isset($amazon_key)) {

        require_once("wso2/amazon/AmazonClient.php");
        $amazon_client = new AmazonClient($amazon_key);

        $res = $amazon_client->itemSearch($amazon_query, $amazon_index, $page);

        /* Check for the soap - fault */
        if ($res["soap-fault"]) {
            $soap_reason = $res["soap-fault-reason"];
            printf("SOAP fault : ${soap_reason}\n");
        }

        /* Check for the error */
        elseif ($res["error"]) {
            $error_message = $res["error-msg"];
            printf("Error Message: ${error_message}\n");
        }

        /* Render the response if no errors occured */
        elseif ($res["results"] != NULL) {
            $pages = $res["pages"];

            /* Render the numbers to display, This allows access by page number */
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
                $number_bar .= "<a href='javascript:amazonRequest(${prev_page})'>&lt;&lt;</a> ";
            }

            for ($i = 0; $i < $end_list; $i ++) {
                $page_no = $page + $i;
                $number_bar .= "<a href='javascript:amazonRequest(${page_no})'>${page_no}</a> ";
            }

            if ($next_exist) {
                $next_page = $page +11;
                $number_bar .= "<a href='javascript:amazonRequest(${next_page})'>&gt;&gt;</a> ";
            }
            $number_bar .= "</div>";

            echo $number_bar;
            
            echo "<ol start=\"1\">";

            $start = 0;

            foreach ($res["results"] as $result) {
                echo "<li>";

                $detail_page_url=$result["DetailPageURL"];
                $asin = $result["ASIN"];
                $author = $result["ItemAttributes"]["Author"];
                $creator = $result["ItemAttributes"]["Creator"];
                $manufacturer = $result["ItemAttributes"]["Manufacturer"];
                $product_group = $result["ItemAttributes"]["ProductGroup"];
                $title = $result["ItemAttributes"]["Title"];

                $list_price = $result["ItemAttributes"]["ListPrice"]["FormattedPrice"];
                $small_img_url = $result["SmallImage"]["URL"];
                $medium_img_url = $result["MediumImage"]["URL"];

                $total_reviews = $result["CustomerReviews"]["TotalReviews"];

                echo "<div>";
                echo "<a href=\"${detail_page_url}\"><h3>${title}</h3></a>";
                if(isset($medium_img_url) && !empty($medium_img_url))
                {
                    echo "<a href=\"${detail_page_url}\"><img src=\"${medium_img_url}\"></a>";
                }
                echo "<ul>";
                if (isset($author)) {
                    echo "<li>Author: ${author}</li>";
                }
                if (isset($creator)) {
                    echo "<li>Creator: ${creator}</li>";
                }
                if (isset($manufacturer)) {
                    echo "<li>Manufactor: ${manufacturer}</li>";
                }

                if (isset($total_reviews)) {
                    echo "<li>Reviews : ${total_reviews}</li>";
                }
                if (isset($list_price)) {
                    echo "<li>Price: ${list_price}</li>";
                }
                echo "<li><a href=\"${detail_page_url}\">More Detail</a><li>";


                echo "</ul>";

                echo "</div>";
                echo "<div style=\"padding:5px\" id=\"${id_asin}\">";
                echo "</div>";
                echo "<div style=\"height:10px\">&nbsp;</div>";
                echo "</li>";

                $start ++;
            }

            echo "</ol>";

            echo $number_bar;
        }
        else {
            echo "Empty <br/>";
        }
    }
?>
