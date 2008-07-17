<?php

require_once("wso2/DataServices/DSConstants.php");
/**
 * keeps the utilities used in DSProcessor
 */
class DSUtils {
    public static function error_log($file, $line, $message) {
        error_log(DS_LOG_PREFIX. " {$file}:{$line} : {$message}");
    }
}

?>
