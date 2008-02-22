<?
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
