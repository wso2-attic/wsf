<!--
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
 -->

<DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en-US" lang="en-US">
<head>
<title>WSO2 Calendar</title>
<meta http-equiv="content-type" content="text/html; charset=iso-8859-1">
<link rel="stylesheet" type="text/css" href="./assets/style/initial.css" media="screen, projection" />
<link rel="stylesheet" type="text/css" href="./assets/style/wso2cal.css" media="screen, projection" />
<link href="./assets/style/style3.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="./assets/scripts/basic_cal.js"></script>
</head>
<body>
<div id="container">
  <div id="header">
    <h1><img src="./assets/images/wso2.png" alt="wso2" /></h1><p>Keep track your fact</p>
        <hr class="hidden clear" />
  </div>
  <div id="wrapper">
    <div id="content">
                <div id="cal_menu">
                        <?php
                           if($_SESSION["member_id"]){
                           $user_id=$_SESSION["member_id"];
                           echo"welcome &nbsp<b>$user_id<b>";
                          }
                         ?>
                        <a href="logout.php"><b><i>logout</i></b></a>
<?php               //  <ul><li><a href="add_event_client.php">Create Event</a></li><li><a href="update_event_client.php">Update Event</a></li><li><a href="delete_event_client.php">Delete Event</a></li></ul>//?>
                </div>
                <div id="main">

