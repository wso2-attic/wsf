<?php
class FlickrClient extends WSClient
{
    const ENDPOINT = "http://api.flickr.com/services/soap/";
    
    const RESPONSE_XML = "response-xml";
    const RESPONSE_DOM = "response-dom";
    const SOAP_FAULT = "soap-fault";
    const SOAP_FAULT_REASON = "soap-fault";
    const ERROR = "error";
    const ERROR_MSG = "error-msg";


    //list of functions
    const PHOTO_SEARCH_FUNC = "flickr.photos.search";
    const PHOTO_SEARCH_TAGS = "flickr.photos.addTags";   
    const PHOTO_GET_INFO = "flickr.photos.getInfo";
    const PHOTO_GET_FAVORITE = "flickr.photos.getFavorites";    
    const PHOTO_GET_RECENT = "flickr.photos.getRecent";    
    const PHOTO_GET_PERMS = "flickr.photos.getPerms";
    const PHOTO_GET_SIZES = "flickr.photos.getSizes";
    const PHOTO_GET_FROB = "flickr.auth.getFrob";
    const FlickrAuthGetToken = "flickr.auth.getToken"; 
    
    const FlickrPhotoAddComments ="flickr.photos.comments.addComment";
    const PHOTOS = "photos";

    /** 
     * Your Flickr API key
     */
    public $api_key;

    /**
     * Construct the FlickrClient
     */
    public function __construct($api_key)
    {
        parent::__construct(array(
                             "to"=> self::ENDPOINT));
        $this->api_key = $api_key;
    }



   public function GetPhotoInfo(array $options = array())
  {
    $req = $this->buildRequestPayload(self::PHOTO_GET_INFO,$options);
        try {
            $res = $this->request($req);
        }
        catch(Exception $e)
        {
            return $this->handleException($e);
        }

        $ret = $res->str;

        return $ret;
 
   } 
 
   public function FlickrAuthGetFrob()
  {
      $api_key=$this->api_key;
      $shared="539f7b71f6f65c55";
      $perms="write";
      $method="flickr.auth.getFrob";
      $signature=md5($shared.'api_key'.$api_key.'method'.$method);
  
   $req=<<<XML
        <x:FlickrRequest xmlns:x="urn:flickr">
        <method>flickr.auth.getFrob</method>
        <api_key>$api_key</api_key>
        <api_sig>$signature</api_sig>
        </x:FlickrRequest>

XML;

 try {
     $res = $this->request($req);
     }
 catch(Exception $e)
     {
       return $this->handleException($e);
     }

   $ret = $res->str;

   return $ret;

 }


 public function FlickrAuthGetToken($frob)
 {
      $api_key=$this->api_key;
      $shared="539f7b71f6f65c55";
      $method="flickr.auth.getToken";
      $signature=md5($shared.'api_key'.$api_key.'frob'.$frob.'method'.$method);
      file_put_contents("/tmp/sig.txt",$signature);
      file_put_contents("/tmp/frob.txt",$frob);

 
      $req=<<<XML
        <x:FlickrRequest xmlns:x="urn:flickr">
        <method>flickr.auth.getToken</method>
        <api_key>$api_key</api_key>
        <frob>$frob</frob>
        <api_sig>$signature</api_sig>
        </x:FlickrRequest>
XML;

 try {
     $res = $this->request($req);
     }
 catch(Exception $e)
     {
       return $this->handleException($e);
     }

 $ret = $res->str;
 return $ret;

 }


 public function FlickrPhotoAddComments($photo_id,$comment,$token,$shared)
 {
      $api_key=$this->api_key;
      $method="flickr.photos.comments.addComment";
      $signature=md5($shared.'api_key'.$api_key.'auth_token'.$token.'comment_text'.$comment.'method'.$method.'photo_id'.$photo_id);
      $sig=$shared.'api_key'.$api_key.'auth_token'.$token.'comment_text'.$comment.'method'.$method.'photo_id'.$photo_id;    
      file_put_contents("/tmp/sig1.txt",$sig);
      file_put_contents("/tmp/toc1.txt",$token);
      file_put_contents("/tmp/mdsig.txt",$signature);

 $req=<<<XML
        <x:FlickrRequest xmlns:x="urn:flickr">
        <method>flickr.photos.comments.addComment</method>
        <api_key>$api_key</api_key>
        <auth_token>$token</auth_token>
        <api_sig>$signature</api_sig>
        <photo_id>$photo_id</photo_id>
        <comment_text>$comment</comment_text>
        </x:FlickrRequest>
XML;

 try {
     $res = $this->request($req);
     }
 catch(Exception $e)
     {
       return $this->handleException($e);
     }

 $ret = $res->str;
 return $ret;

 }


 public function GetPhotoFevorite(array $options = array())
  {
    $req = $this->buildRequestPayload(self::PHOTO_GET_FAVORITE,$options);
        try {
            $res = $this->request($req);
        }
        catch(Exception $e)
        {
            return $this->handleException($e);
        }

        $ret = $res->str;

        return $ret;

   }

  public function GetPhotoPerms(array $options = array())
  {
    $req = $this->buildRequestPayload(self::PHOTO_GET_PERMS,$options);
        try {
            $res = $this->request($req);
        }
        catch(Exception $e)
        {
            return $this->handleException($e);
        }

        $ret = $res->str;

        return $ret;

   }


  public function GetPhotoSizes(array $options = array())
  {
    $req = $this->buildRequestPayload(self::PHOTO_GET_SIZES,$options);
        try {
            $res = $this->request($req);
        }
        catch(Exception $e)
        {
            return $this->handleException($e);
        }

        $ret = $res->str;

        return $ret;

   }


  public function GetPhotoRecent()
  {

   $api_key=$this->api_key;

   $req=<<<XML
        <x:FlickrRequest xmlns:x="urn:flickr">
        <method>flickr.photos.getRecent</method>
        <api_key>$api_key</api_key>
        </x:FlickrRequest>     

XML;


 try {
     $res = $this->request($req);
     }
 catch(Exception $e)
     {
       return $this->handleException($e);
     }

   $ret = $res->str;

   return $ret;

}


  public function PhotoSearch($text)
  {

   $api_key=$this->api_key;

   $req=<<<XML
        <x:FlickrRequest xmlns:x="urn:flickr">
        <method>flickr.photos.search</method>
        <api_key>$api_key</api_key>
        <text>$text</text>
        </x:FlickrRequest>

XML;


 try {
     $res = $this->request($req);
     }
 catch(Exception $e)
     {
       return $this->handleException($e);
     }

   $ret = $res->str;

   return $ret;

}



  private function buildRequestPayload($method_name, $options)
    {
        $xml = "<method>${method_name}</method>";
        $xml .= "<api_key>{$this->api_key}</api_key>";

        foreach($options as $key=> $value)
        {
             if(empty($key))
             {
                 continue;
             }
             $xml .= "<${key}>${value}</${key}>";
        }
        $xml = "<x:FlickrRequest xmlns:x=\"urn:flickr\">${xml}</x:FlickrRequest>";

        return $xml;
    }

  private function handleException($e) {
        $res_array = array();
        if ($e instanceof WSFault) {
            $res_array[self::SOAP_FAULT] = TRUE;
            $res_array[self::SOAP_FAULT_REASON] = $e->Reason;;
            /*echo "SOAP FAULT: ".$e->Reason."\n";*/
        }
        else {
            $res_array[self::ERROR] = TRUE;
            $res_array[self::ERROR_MSG] = $e->getMessage();
            /*echo "ERROR_MSG: ".$e->getMessage()."\n";*/
        }
        return $res_array;
    }
}
?>
