<?php

function soap_post($url, $data, $action) {
    $content_type = "application/soap+xml;charset=UTF-8;action=\"{$action}\"";
    $opts = array(
      'http'=>array(
        'method'=>"POST",
        'header'=>"User-Agent: wsf/php test case\r\n".
                  "Content-Type: ".$content_type."\r\n".
                  "Content-length: " . strlen($data)."\r\n",
         'content' => $data
      )
    );
    
    $context = stream_context_create($opts);
    
    $fp = fopen($url, 'r', false, $context);
    $result = fpassthru($fp);
    fclose($fp);

    return $result;
}

?>
