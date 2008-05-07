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
$getResult = $_POST["getResult"];
$symbol = $_POST["symbol"];
$amount = $_POST["amount"];
		    
?>

<html>
<head>
<title> Trader Service </title>
</head>
<body>
<form method="post" action="<?php echo $PHP_SELF;?>">
<table cols="2" border="1" cellpadding="10" cellspacing="0" align="center" width="100%" bgcolor="#eeeeee">
<tr>
<td>
<h4>Create portFolio</h4>

<br/>

<h4>Parameters</h4>
Symbol:<input type="text" size="6" maxlength="15" name="symbol" value="" color="red">
Amount in millions:<input type="text" size="6" maxlength="15" name="amount" value=""><br/>
<br/>

<input type="submit" value="Create" name="getResult">
<input type="submit" value="Reset" name="reset">


</td>
</tr>
</table>

</form>
<?php
if (isset($_POST['getResult']))
{
      if (isset($_GET['symbol']) && isset($_GET['amount']))
      {
	
	$symbol = $_GET['symbol'];
	$amount = $_GET['amount'];
	
      }
    
     
if (isset($symbol) &&  isset($amount))
{
  $fp;
  if (stristr(PHP_OS, 'WIN')) {
	$fp = @fopen('portfolio.xml','r+');
 }else{
 	$fp = @fopen('/tmp/portfolio.xml','r+');
 }
 
 if(!$fp) {
   

 
  $items = array();
  $items [] = array(
  'Symbol' => $symbol,
  'Amount' => $amount,
  );

  $doc = new DOMDocument("1.0");
  $doc->formatOutput = true;
  $r = $doc->createElement( "items" );
  $doc->appendChild( $r );


foreach( $items as $item )
  {
  $b = $doc->createElement( "item" );
  
  $Symbol = $doc->createElement( "Symbol" );
  $Symbol->appendChild(
  $doc->createTextNode( $item['Symbol'] )
  );
  $b->appendChild( $Symbol );
  
  $Amount = $doc->createElement( "Amount" );
  $Amount->appendChild(
  $doc->createTextNode( $item['Amount'] )
  );
  $b->appendChild( $Amount );
  
  $r->appendChild( $b );

  }
 if (stristr(PHP_OS, 'WIN')) {
 	print $doc->save("portfolio.xml");
 }else{
 	print $doc->save("/tmp/portfolio.xml");
 }
    echo "created";

 }
 else
{
  $items = array();
  $items [] = array(
  'Symbol' => $symbol,
  'Amount' => $amount,
  );
  
 if (stristr(PHP_OS, 'WIN')) {
	 $doc =DOMDocument::load("portfolio.xml");
 }else{
  $doc =DOMDocument::load("/tmp/portfolio.xml");
 }
 $doc->formatOutput = true;
 $r = $doc->firstChild;

 
  foreach( $items as $item )
  {
  $b = $doc->createElement( "item" );
  
  $Symbol = $doc->createElement( "Symbol" );
  $Symbol->appendChild(
  $doc->createTextNode( $item['Symbol'] )
  );
  $b->appendChild( $Symbol );
  
  $Amount = $doc->createElement( "Amount" );
  $Amount->appendChild(
  $doc->createTextNode( $item['Amount'] )
  );
  $b->appendChild( $Amount );
  
  $r->appendChild( $b );

  }
  fwrite($fp,$doc->savexml());
  fclose($fp);
  echo "created";
 }
}
}

?>




</body>
</html>
