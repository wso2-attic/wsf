<?php

/**
 * Simple demonstration using PHP Class Library to consume Amazon Web Services
 */



/* Please replace this with your own amazon key
  You can retrieve this from http://aws.amazon.com */
$key = "your_amazon_key";

/* creating the AmazonClient object */
require_once("AmazonClient.php");
$amazon_client = new AmazonClient($key, "SOAP");

/************************************************************************/

/* Invoking the ItemSearch operation */

$items = $amazon_client->ItemSearch("Web Services Sanjiva", "Books");

foreach($items->Item as $item)
{
    echo $item->ASIN.". ";
    echo $item->ItemAttributes->Title. " - ";
    #echo $item->DetailPageURL. " - ";
    echo $item->ItemAttributes->Author. "\n";
}

/************************************************************************/

/* Invoking the ItemLookup operation */

$lookups = $amazon_client->ItemLookup("0131488740");

echo $lookups->Item->ASIN.". ";
echo $lookups->Item->ItemAttributes->Title. " - ";
echo $lookups->Item->ItemAttributes->Author. "\n";


/************************************************************************/


/* Invoking the CartCreate operation */

$cart = $amazon_client->CartCreate(array("0131488740" => 5));

echo $cart->CartId. " - ";
echo $cart->CartItems->SubTotal->FormattedPrice."\n";
echo "HMAC: ".$cart->HMAC."\n";
foreach($cart->CartItems->CartItem as $item)
{
    echo "Item: {$item->CartItemId} - {$item->Title}.\n";
}
echo $cart->PurchaseURL."\n";

/************************************************************************/


/* Invoking the CartModify operation */

$cart = $amazon_client->CartModify("102-0208736-3675339", "lXOKkAyAVl6+/+D+KA3GvJRF4P0=", array("U181IPR3ATNL7R" => 3));
echo $cart->CartId. " - ";
echo $cart->CartItems->SubTotal->FormattedPrice."\n";
echo $cart->PurchaseURL."\n";

/************************************************************************/


/* Invoking the CartClear operation */

$result = $amazon_client->CartClear("102-0208736-3675339", "lXOKkAyAVl6+/+D+KA3GvJRF4P0=");


/************************************************************************/

?>
