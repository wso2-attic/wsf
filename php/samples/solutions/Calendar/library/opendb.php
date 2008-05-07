<?
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

function dbconnect() 
{ 
    global $dbhost,  $dbuname,  $dbpass,  $dbname; 
   $link= mysql_connect($dbhost,  $dbuname,  $dbpass); 
    mysql_select_db($dbname,$link) or die ("<p>Unable to select database !</p>"); 
} 

function query_db($query) 
{ 
    dbconnect(); 
    return mysql_query($query); 
} 
?>
