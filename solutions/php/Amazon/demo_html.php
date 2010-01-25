<?php
/**
 * Sample application using PHP Class Library to consume Amazon Web Services
 */

require_once("AmazonClient.php");

$operation = $_POST["operation"];
$asin = $_POST["asin"];
$query = "";
$catagory_arr = array();

session_start();

/* Please replace this with your own amazon key
  You can retrieve this from http://aws.amazon.com */
if(!isset($_SESSION["key"]))
{
    $key = "Your_Amazon_Key";
}
else
{
    $key = $_SESSION["key"];
}

$searched_items = NULL;
$item_lookups = NULL;

/* The first time the key is set
   we will crete the AmazonClient */

if(isset($_POST["amazon_key"]))
{
    $_SESSION['key'] = $_POST["amazon_key"];
}

if(isset($_POST["clearcart"]) && $_POST["clearcart"] == "true")
{
    $_SESSION["cart"] = NULL;
    unset($_SESSION["cart"]);
}

$error_message = "";

/* After the search operation invoked */
if($operation == "search" && empty($asin))
{
    // retrive the user parameters 
    $query = $_POST["query"];
    $key = $_SESSION["key"];
    $catagory = $_POST["catagory"];
    $page = isset($_POST["page"])?$_POST["page"]: "1";
    $catagory_arr[$catagory] = "selected=\"true\"";

    // and then call the service 
    
    $amazon_client = new AmazonClient($key, "SOAP");

    $searched_items = $amazon_client->ItemSearch($query, $catagory, $page);

    if($searched_items->OperationRequest != NULL && $searched_items->OperationRequest->Errors != NULL && 
                    $searched_items->OperationRequest->Errors->Error != NULL)
    {
        $error_message = trim($searched_items->OperationRequest->Errors->Error->Message."");
    }
    else if($searched_items->Items != NULL && $searched_items->Items->Request != NULL &&
                    $searched_items->Items->Request->Errors != NULL && 
                    $searched_items->Items->Request->Errors->Error != NULL)
    {
        $error_message = trim($searched_items->Items->Request->Errors->Error->Message."");
    }
    else
    {
        $searched_items = $searched_items->Items;
    }
}

/* After an item is selected to add */
if(!empty($asin) && $operation != "add")
{
    $key = $_SESSION["key"];
    $amazon_client = new AmazonClient($key, "SOAP");

    $item_lookups = $amazon_client->ItemLookup($asin);

    if($item_lookups->Request != NULL && $item_lookups->Request->Errors != NULL && 
                    $item_lookups->Request->Errors->Error != NULL)
    {
        $error_message = trim($item_lookups->Request->Errors->Error->Message."");
    }
    else
    {
        $item_lookups = $item_lookups->Items;
    }
}

/* When the adding is really happening */
$cart = $_SESSION["cart"];
$is_add_valid = "True";
if($operation == "add")
{   
    $number = $_POST["number"];
    $key = $_SESSION["key"];

    if(!isset($cart) || empty($cart))
    {
        /* we have to create a cart */
        $amazon_client = new AmazonClient($key, "SOAP");
        $cart_results = $amazon_client->CartCreate(array($asin=>$number));

        $is_add_valid = $cart_results->Request->IsValid;

        if($cart_results->Request != NULL && $cart_results->Request->Errors != NULL && 
                        $cart_results->Request->Errors->Error != NULL)
        {
            $error_message = trim($cart_results->Request->Errors->Error[0]->Message."");
            $is_add_valid = "False";
        }
        else if($is_add_valid == "False")
        {
            $error_message = "The Item is not available to add to the cart";
        }

        if($is_add_valid == "True")
        {
            $cart = array();
            $cart["id"] = trim($cart_results->CartId[0]);
            $cart["HMAC"] = trim($cart_results->HMAC[0]);
            $cart["price"] = trim($cart_results->CartItems->SubTotal->FormattedPrice[0]);
            $cart["purchaseUrl"] = trim($cart_results->PurchaseURL[0]);
            $cart["items"] = array();
        }
    }
    else
    {
        // we already have the cart, so modify it
        $amazon_client = new AmazonClient($key, "SOAP");
        $cart_results = $amazon_client->CartAdd($cart["id"], $cart["HMAC"], array($asin=>$number));
        
        $is_add_valid = $cart_results->Request->IsValid;

        if($cart_results->Request != NULL && $cart_results->Request->Errors != NULL && 
                        $cart_results->Request->Errors->Error != NULL)
        {
            $error_message = trim($cart_results->Request->Errors->Error[0]->Message."");
            $is_add_valid = "False";
        }
        else if($is_add_valid == "False")
        {
            $error_message = "The Item is not available to add to the cart";
        }

        if($is_add_valid == "True")
        {
            $cart["HMAC"] = trim($cart_results->HMAC[0]);
            $cart["price"] = trim($cart_results->CartItems->SubTotal->FormattedPrice[0]);
        }
        else if($is_add_valid == "False")
        {
            $error_message = "Your Request is not valid";
        }
    }


    if($is_add_valid == "True")
    {
        /* keep the items in the session */
        $item = array();
        $item["cartItemId"] = trim($cart_results ->CartItems->CartItem->CartItemId[0]);
        $item["ASIN"] = $asin;
        $item["title"] = trim($cart_results ->CartItems->CartItem->Title);
        $item["quantity"] = trim($cart_results ->CartItems->CartItem->Quantity);

        $cart["items"][count($cart["items"])] = $item;
        
        $_SESSION["cart"] = $cart;
    }
}

?>

<html>
<head>
<title> Amazon Shopping Cart </title>
</head>
<style>

form {
    text-align: center;
    font-family: Verdana, Tahoma;
    font-size: 12px;
}

h1 {
    text-align: center;
    font-family: Verdana, Tahoma;
    font-size: 19px;
    padding: 18px;
}

.seperator
{
    padding:10px;
}

#red
{
    width: 600px;
    margin:0 auto;
    border:2px solid #ef3333;
    background: #ffdddd;
    padding: 15px
}

#search
{
    border:2px solid #3333ef;
    background: #ddddff;
    padding: 15px;
    width: 600px;
    margin:0 auto;
}

#in_search_box
{
    border:5px;
}

</style>

<body>
    <h1> Amazon Web Service with Web Service Framework DEMO</h1>
        <form name="mainform" id="mainform" method="post" action="demo_html.php">
        <?php
            /* Here we are generating a panel to insert the amazon key */
            if(!isset($_SESSION["key"]))
            {
        ?>
                <p>
                    <div id="red" style="">
                        Your Amazon Key 
                        <input name="amazon_key" type="text" value="<?php echo $key?>"/>
                    </div>
                </p>
                <p>
                    <div class="seperator">&nbsp;</div>
                </p>
        <?php
            }
        ?>


        <?php
            /* Here we are generating a panel to enter a query a catagory to search */
            if((!isset($operation) || $operation == "start" || $operation == "search") && empty($asin))
            {
        ?>
                    <div id="search">
                        Query to search
                        <input name="query" type="text" value="<?php echo $query?>"/>
                        <div class="seperator">&nbsp;</div>
                        Catagory to search
                        <select name="catagory">
                            <option value="Apparel" <?php echo $catagory_arr["Apparel"]?>>Apparel</option>
                            <option value="Baby" <?php echo $catagory_arr["Baby"]?>>Baby</option>
                            <option value="Beauty" <?php echo $catagory_arr["Beauty"]?>>Beauty</option>
                            <option value="Blended" <?php echo $catagory_arr["Blended"]?>>Blended</option>
                            <option value="Books" <?php echo $catagory_arr["Books"]?>>Books</option>
                            <option value="Classical" <?php echo $catagory_arr["Classical"]?>>Classical</option>
                            <option value="DVD" <?php echo $catagory_arr["DVD"]?>>DVD</option>
                            <option value="DigitalMusic" <?php echo $catagory_arr["DigitalMusic"]?>>Digital Music</option>
                            <option value="Electronics" <?php echo $catagory_arr["Electronics"]?>>Electronics</option>
                            <option value="GourmetFood" <?php echo $catagory_arr["GourmetFood"]?>>Gourmet Food</option>
                            <option value="HealthPersonalCare" <?php echo $catagory_arr["HealthPersonalCare"]?>>Health Personal Care</option>
                            <option value="Jewelry" <?php echo $catagory_arr["Jewelry"]?>>Jewelry</option>
                            <option value="Kitchen" <?php echo $catagory_arr["Kitchen"]?>>Kitchen</option>
                            <option value="Magazines" <?php echo $catagory_arr["Magazines"]?>>Magazines</option>
                            <option value="Merchants" <?php echo $catagory_arr["Merchants"]?>>Merchants</option>
                            <option value="Miscellaneous" <?php echo $catagory_arr["Miscellaneous"]?>>Miscellaneous</option>
                            <option value="Music" <?php echo $catagory_arr["Music"]?>>Music</option>
                            <option value="MusicTracks" <?php echo $catagory_arr["MusicTracks"]?>>Music Tracks</option>
                            <option value="MusicalInstruments" <?php echo $catagory_arr["MusicalInstruments"]?>>Musical Instruments</option>
                            <option value="OfficeProducts" <?php echo $catagory_arr["OfficeProducts"]?>>Office Products</option>
                            <option value="OutdoorLiving" <?php echo $catagory_arr["OutdoorLiving"]?>>Outdoor Living</option>
                            <option value="PCHardware" <?php echo $catagory_arr["PCHardware"]?>>PC Hardware</option>
                            <option value="PetSupplies" <?php echo $catagory_arr["PetSupplies"]?>>Pet Supplies</option>
                            <option value="Photo" <?php echo $catagory_arr["Photo"]?>>Photo</option>
                            <option value="Restaurants" <?php echo $catagory_arr["Restaurants"]?>>Restaurants</option>
                            <option value="Software" <?php echo $catagory_arr["Software"]?>>Software</option>
                            <option value="SportingGoods" <?php echo $catagory_arr["SportingGoods"]?>>Sporting Goods</option>
                            <option value="Tools" <?php echo $catagory_arr["Tools"]?>>Tools</option>
                            <option value="Toys" <?php echo $catagory_arr["Toys"]?>>Toys</option>
                            <option value="VHS" <?php echo $catagory_arr["VHS"]?>>VHS</option>
                            <option value="Video" <?php echo $catagory_arr["Video"]?>>Video</option>
                            <option value="VideoGames" <?php echo $catagory_arr["VideoGames"]?>>Video Games</option>
                            <option value="Wireless" <?php echo $catagory_arr["Wireless"]?>>Wireless</option>
                            <option value="WirelessAccessories" <?php echo $catagory_arr["WirelessAccessories"]?>>Wireless Accessories</option>
                        </select>
                        <div class="seperator">&nbsp;</div>
                        <?php
                        if(isset($searched_items) && $searched_items != NULL && $searched_items-> TotalPages > 1)
                        {
                            echo "Page <select name=\"page\">";
                            
                            for($i = 1; $i <= $searched_items-> TotalPages; $i ++)
                            {
                                echo "<option value=\"$i\" ".($page == $i?"selected=\"true\"":"").">$i</option>";
                            }

                            echo "</select>";
                        
                            echo "<div class=\"seperator\">&nbsp;</div>";
                        }
                        ?>

                        <input type="submit" value="search"/>
                   </div>
                  <input name="operation" type="hidden" value="search"/>
                  <div class="seperator">&nbsp;</div>
        <?php
            }
        ?>
        <?php
            /* Here we are generating a panel to show the searched results */
            if(isset($operation) && $operation == "search" && $searched_items != NULL && count($searched_items->Item))
            {
                echo "<div id=\"search\">";

                foreach($searched_items->Item as $item) 
                {
                    $detail_page_url = $item->DetailPageURL;
                    $asin = $item->ASIN;
                    $author = $item->ItemAttributes->Author;
                    $creator = $item->ItemAttributes->creator;
                    $manufacturer = $item->ItemAttributes->Manufacturer;
                    $product_group = $item->ItemAttributes->ProductGroup;
                    $title = $item->ItemAttributes->Title;

                    $list_price = $item->ItemAttributes->ListPrice->FormattedPrice;
                    $small_img_url = $item->SmallImage->URL;
                    $medium_img_url = $item->MediumImage->URL;

                    $total_reviews = $item->CustomerReviews->TotalReviews;

                    echo "<a href=\"${detail_page_url}\"><h3>${title}</h3></a>";
                    if(isset($medium_img_url) && !empty($medium_img_url))
                    {
                        echo "<a href=\"${detail_page_url}\"><img src=\"${medium_img_url}\"></a>";
                    }
                    echo "<ul>";
                    if (isset($author) && !empty($author)) {
                        echo "<li>Author: ${author}</li>";
                    }
                    if (isset($creator) && !empty($creator)) {
                        echo "<li>Creator: ${creator}</li>";
                    }
                    if (isset($manufacturer) && !empty($manufacturer)) {
                        echo "<li>Manufactor: ${manufacturer}</li>";
                    }
                    if (isset($total_reviews) && !empty($total_reviews)) {
                        echo "<li>Reviews : ${total_reviews}</li>";
                    }
                    if (isset($list_price) && !empty($list_price)) {
                        echo "<li>Price: ${list_price}</li>";
                    }
                    echo "<li><a href=\"${detail_page_url}\">More Detail</a></li>";
                
                    echo "</ul>";
                    
                    echo "<b><a href=\"javascript:document.getElementById('asin').value='{$asin}'; document.mainform.submit()\">Add ^ to Cart</a></b>";

                    echo "<div class=\"seperator\">&nbsp;</div>";
            
                }
                echo "</div>";
                echo "<input id=\"asin\" name=\"asin\" type=\"hidden\" value=\"\"/>";
                echo "<div class=\"seperator\">&nbsp;</div>";
            }

            /* Here we are generating a panel to show the item you going to add to the cart */
            else if(!empty($asin) && $operation != "add")
            {
                echo "<div id=\"search\">";

                $detail_page_url = $item_lookups->Item->DetailPageURL;
                $asin = $item_lookups->Item->ASIN;
                $author = $item_lookups->Item->ItemAttributes->Author;
                $creator = $item_lookups->Item->ItemAttributes->creator;
                $manufacturer = $item_lookups->Item->ItemAttributes->Manufacturer;
                $product_group = $item_lookups->Item->ItemAttributes->ProductGroup;
                $title = $item_lookups->Item->ItemAttributes->Title;

                $list_price = $item_lookups->Item->ItemAttributes->ListPrice->FormattedPrice;
                $small_img_url = $item_lookups->Item->SmallImage->URL;
                $medium_img_url = $item_lookups->Item->MediumImage->URL;

                $total_reviews = $item_lookups->Item->CustomerReviews->TotalReviews;

                echo "<a href=\"${detail_page_url}\"><h3>${title}</h3></a>";
                if(isset($medium_img_url) && !empty($medium_img_url))
                {
                    echo "<a href=\"${detail_page_url}\"><img src=\"${medium_img_url}\"></a>";
                }
                echo "<ul>";
                if (isset($author) && !empty($author)) {
                    echo "<li>Author: ${author}</li>";
                }
                if (isset($creator) && !empty($creator)) {
                    echo "<li>Creator: ${creator}</li>";
                }
                if (isset($manufacturer) && !empty($manufacturer)) {
                    echo "<li>Manufactor: ${manufacturer}</li>";
                }
                if (isset($total_reviews) && !empty($total_reviews)) {
                    echo "<li>Reviews : ${total_reviews}</li>";
                }
                if (isset($list_price) && !empty($list_price)) {
                    echo "<li>Price: ${list_price}</li>";
                }
                echo "<li><a href=\"${detail_page_url}\">More Detail</a></li>";
            
                echo "</ul>";
                
                echo "Number of Items <input name=\"number\" type=\"text\" value=\"1\"/> ";

                echo "<input type=\"submit\" value=\"Add\"/> ";
                echo "<input id=\"operation\" name=\"operation\" type=\"hidden\" value=\"add\"/> ";
                
                echo "<b><a href=\"javascript:document.getElementById('operation').value='start';document.getElementById('asin').value='';  document.mainform.submit()\">Back to Search</a></b>";

                echo "<div class=\"seperator\">&nbsp;</div>";
            
                echo "</div>";
                
                echo "<input id=\"asin\" name=\"asin\" type=\"hidden\" value=\"{$asin}\"/>";
                
                echo "<div class=\"seperator\">&nbsp;</div>";
            }

            if(isset($error_message) && !empty($error_message))
            {
                echo "<div id=\"red\">";
                echo "<p>{$error_message}</p>";
                echo "<b><a href=\"javascript:document.mainform.submit()\">Back to Search</a></b>";
                echo "</div>";
                echo "<div class=\"seperator\">&nbsp;</div>";
            }

            /* Here we are generating a panel that shows the status of the cart */
            if(isset($cart) && !empty($cart))
            {
                echo "<div id=\"red\">";

                echo "<h3>Your Cart <a href=\"javascript:document.getElementById('clearcart').value='true';document.mainform.submit()\"><i>Clear</i></a></h3>";
                echo "<p>";
                echo "Your total price for the Cart is {$cart["price"]}";
                echo "</p>";
                echo "<p>";
                echo "Your can pay for the Cart from <a href=\"{$cart["purchaseUrl"]}\">here</a>";
                echo "</p>";
                echo "<p>";
                echo "Your Items";
                echo "</p>";
                echo "<ul>";
                foreach($cart["items"] as $item)
                {
                    echo "<li>{$item["title"]} - {$item["quantity"]}</li>";                        
                }
                echo "</ul>";
                
                echo "<b><a href=\"javascript:document.mainform.submit()\">Back to Search</a></b>";
                
                echo "</div>";
                echo "<input id=\"clearcart\" name=\"clearcart\" type=\"hidden\" value=\"false\"/>";
                echo "<div class=\"seperator\">&nbsp;</div>";
            }

        ?>

        <?php
            /* Here we are generating a panel to insert the amazon key */
            if(isset($_SESSION["key"]))
            {
        ?>
                <p>
                    <div id="red" style="">
                        Change Your Amazon Key 
                        <input name="amazon_key" type="text" value="<?php echo $key?>"/>
                    </div>
                </p>
                <p>
                    <div class="seperator">&nbsp;</div>
                </p>
        <?php
            }
        ?>

        </form>
</body>


</html>
