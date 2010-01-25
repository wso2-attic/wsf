<?php
/**
 * PHP Class Library to consume Amazon Web Services
 */
class AmazonClient extends WSClient
{

    /** endpoints */
    const AMAZON_SOAP_ENDPOINT = "http://soap.amazon.com:80/onca/soap?Service=AWSECommerceService";
    const AMAZON_REST_ENDPOINT = "http://webservices.amazon.com/onca/xml";

    /** 
     * Your Amazon Application key
     * @var string
     */
    private $amazon_key;
    private $is_soap;

    /**
     * Construct the AmazonClient
     * @param $amazon_key Amazon App Key
     */
    public function __construct($amazon_key, $method)
    {
        if($method == "SOAP" || $method == "soap")
        {
            parent::__construct(array(
                              "to"=>self::AMAZON_SOAP_ENDPOINT,
                              "useSOAP" => "1.1",
                              "action" => "http://soap.amazon.com"));
            $this->is_soap = TRUE;
        }
        else
        {
            parent::__construct(array(
                              "to"=>self::AMAZON_REST_ENDPOINT,
                              "HTTPMethod"=>"GET",
                              "useSOAP" => FALSE));
            $this->is_soap = FALSE;
        }
        $this->amazon_key = $amazon_key;
    }

  
    /**
     * Search Web
     * @param $query query string
     * @param $catagory catagory to search
     * @param $catagory page to search
     * @return associate array consist of the response parameters
     */  
    public function ItemSearch($query, $catagory, $page = 1)
    {
        if($this->is_soap)
        {
            $req_payload = <<<XML
                <ItemSearch xmlns="http://webservices.amazon.com/AWSECommerceService/2007-10-29">
                    <SubscriptionId>{$this->amazon_key}</SubscriptionId>
                    <ResponseGroup>Medium</ResponseGroup>
                    <Request>
                        <ItemPage>{$page}</ItemPage>
                        <Keywords>{$query}</Keywords>
                        <SearchIndex>{$catagory}</SearchIndex>
                    </Request>
                </ItemSearch>
XML;
        }
        else
        {
            $req_payload = <<<XML
                <ItemSearch>
                    <SubscriptionId>{$this->amazon_key}</SubscriptionId>
                    <Service>AWSECommerceService</Service>
                    <ResponseGroup>Medium</ResponseGroup>
                    <Operation>ItemSearch</Operation>
                    <ItemPage>{$page}</ItemPage>
                    <Keywords>{$query}</Keywords>
                    <SearchIndex>{$catagory}</SearchIndex>
                </ItemSearch>
XML;
        }

        $ret_message = $this->request($req_payload);
        $simplexml = new SimpleXMLElement($ret_message->str);

        $res = $simplexml;

        return $res;
    }

    /**
     * ItemLookup
     * @param $ASIN Amaxon Item Id
     * @return associate array consist of the response parameters
     */  
    public function ItemLookup($ASIN)
    {

        if($this->is_soap)
        {
             $req_payload = <<<XML
                <ItemLookup xmlns="http://webservices.amazon.com/AWSECommerceService/2007-10-29">
                    <SubscriptionId>{$this->amazon_key}</SubscriptionId>
                    <ResponseGroup>Medium</ResponseGroup>
                    <Request>
                        <ItemId>{$ASIN}</ItemId>
                        <ReviewPage>1</ReviewPage>
                    </Request>
                </ItemLookup>
XML;
        }
        else
        {
             $req_payload = <<<XML
                <ItemLookup xmlns="http://webservices.amazon.com/AWSECommerceService/2007-10-29">
                    <SubscriptionId>{$this->amazon_key}</SubscriptionId>
                    <Service>AWSECommerceService</Service>
                    <ResponseGroup>Large</ResponseGroup>
                    <Operation>ItemLookup</Operation>
                    <ItemId>{$ASIN}</ItemId>
                    <ReviewPage>1</ReviewPage>
                </ItemLookup>
XML;
        }

        $ret_message = $this->request($req_payload);

        $simplexml = new SimpleXMLElement($ret_message->str);
   
        $res = $simplexml;

        return $res;
    }

    /**
     * CartCreate
     * @param $items array of items you wish to add to the new cart
     *          sould be a hash of  "product ASIN"=> "Quantity"
     * @return associate array consist of the response parameters
     */  
    public function CartCreate(Array $items)
    {
        $i = 0;
        $items_xml = "";
        $req_payload = "";
        foreach ($items as $asin => $quantity)
        {
            $i ++;
            if($this->is_soap)
            {
                $items_xml .= <<<XML
                    <Item>
                        <ASIN>{$asin}</ASIN>
                        <Quantity>{$quantity}</Quantity>
                    </Item>
XML;
            }
            else
            {
                $items_xml .= <<<XML
                    <Item.$i.ASIN>{$asin}</Item.$i.ASIN>
                    <Item.$i.Quantity>{$quantity}</Item.$i.Quantity>
XML;
            }
        }

        if($this->is_soap)
        {
             $req_payload = <<<XML
                <CartCreate xmlns="http://webservices.amazon.com/AWSECommerceService/2007-10-29">
                    <SubscriptionId>{$this->amazon_key}</SubscriptionId>
                    <Request>
                        <Items>
                            $items_xml
                        </Items>
                    </Request>
                </CartCreate>
XML;
        }
        else
        {
             $req_payload = <<<XML
                <CartCreate>
                    <Service>AWSECommerceService</Service>
                    <Operation>CartCreate</Operation>
                    <SubscriptionId>{$this->amazon_key}</SubscriptionId>
                    $items_xml
                </CartCreate>
XML;
        }

        $ret_message = $this->request($req_payload);

        $simplexml = new SimpleXMLElement($ret_message->str);
    
        $res = $simplexml-> Cart;

        return $res;
    }

    /**
     * CartAdd
     * @param $items array of items you wish to add to an existing cart
     *          sould be a hash of  "product ASIN"=> "Quantity"
     * @return associate array consist of the response parameters
     */  
    public function CartAdd($cart_id, $HMAC, Array $items)
    {
        $i = 0;
        $items_xml = "";
        foreach ($items as $asin => $quantity)
        {
            $i ++;
            if($this->is_soap)
            {
                $items_xml .= <<<XML
                    <Item>
                        <ASIN>{$asin}</ASIN>
                        <Quantity>{$quantity}</Quantity>
                    </Item>
XML;
            }
            else
            {
                $items_xml .= <<<XML
                    <Item.$i.ASIN>{$asin}</Item.$i.ASIN>
                    <Item.$i.Quantity>{$quantity}</Item.$i.Quantity>
XML;
            }
        }

        if($this->is_soap)
        {
             $req_payload = <<<XML
                <CartAdd xmlns="http://webservices.amazon.com/AWSECommerceService/2007-10-29">
                    <SubscriptionId>{$this->amazon_key}</SubscriptionId>
                    <Request>
                        <CartId>$cart_id</CartId>
                        <HMAC>$HMAC</HMAC>
                        <Items>
                            $items_xml
                        </Items>
                    </Request>
                </CartAdd>
XML;
        }
        else
        {
             $req_payload = <<<XML
                <CartAdd>
                    <CartId>$cart_id</CartId>
                    <HMAC>$HMAC</HMAC>
                    <Service>AWSECommerceService</Service>
                    <Operation>CartAdd</Operation>
                    <SubscriptionId>{$this->amazon_key}</SubscriptionId>
                    $items_xml
                </CartAdd>
XML;
        }


        $ret_message = $this->request($req_payload);
        $simplexml = new SimpleXMLElement($ret_message->str);
    
        $res = $simplexml-> Cart;

        return $res;
    }
    /**
     * CartModify
     * @param $cart_id id of the cart to modify..
     * @param $HMAC security token for authentication..
     * @param $items array of items you wish to change
     *          sould be a hash of  "Cart Item Id"=> "Quantity"
     * @return associate array consist of the response parameters
     */  
    public function CartModify($cart_id, $HMAC, Array $items)
    {
        $i = 0;
        $items_xml = "";
        foreach ($items as $cart_item_id => $quantity)
        {
            $i ++;
            if($this->is_soap)
            {
                $items_xml .= <<<XML
                        <Item>
                            <CartItemId>{$cart_item_id}</CartItemId>
                            <Quantity>{$quantity}</Quantity>
                        </Item>
XML;
            }
            else
            {
                $items_xml .= <<<XML
                        <Item.$i.CartItemId>{$cart_item_id}</Item.$i.CartItemId>
                        <Item.$i.Quantity>{$quantity}</Item.$i.Quantity>
XML;
            }
        }

        if($this->is_soap)
        {
             $req_payload = <<<XML
                <CartModify xmlns="http://webservices.amazon.com/AWSECommerceService/2007-10-29">
                    <SubscriptionId>{$this->amazon_key}</SubscriptionId>
                    <Request>
                        <CartId>$cart_id</CartId>
                        <HMAC>$HMAC</HMAC>
                        <Items>
                            $items_xml
                        </Items>
                    </Request>
                </CartModify>
XML;
        }
        else
        {
             $req_payload = <<<XML
                <CartModify>
                    <SubscriptionId>{$this->amazon_key}</SubscriptionId>
                    <CartId>$cart_id</CartId>
                    <HMAC>$HMAC</HMAC>
                    <Service>AWSECommerceService</Service>
                    <Operation>CartModify</Operation>
                    $items_xml
                </CartModify>
XML;
            
        }

        $ret_message = $this->request($req_payload);

        $simplexml = new SimpleXMLElement($ret_message->str);
    
        $res = $simplexml-> Cart;

        return $res;
    }

    /**
     * CartClear
     * @param $cart_id id of the cart to modify..
     * @param $HMAC security token for authentication..
     * @return associate array consist of the response parameters
     */  
    public function CartClear($cart_id, $HMAC)
    {
        
        if($this->is_soap)
        {
             $req_payload = <<<XML
                <CartClear xmlns="http://webservices.amazon.com/AWSECommerceService/2007-10-29">
                    <SubscriptionId>{$this->amazon_key}</SubscriptionId>
                    <Request>
                        <CartId>$cart_id</CartId>
                        <HMAC>$HMAC</HMAC>
                    </Request>
                </CartClear>
XML;
        }
        else
        {
             $req_payload = <<<XML
                <CartClear>
                    <Service>AWSECommerceService</Service>
                    <Operation>CartClear</Operation>
                    <SubscriptionId>{$this->amazon_key}</SubscriptionId>
                    <CartId>$cart_id</CartId>
                    <HMAC>$HMAC</HMAC>
                </CartClear>
XML;
        }

        $ret_message = $this->request($req_payload);
        $simplexml = new SimpleXMLElement($ret_message->str);
    
        $res = $simplexml;

        return $res;
    }
} 
?>
