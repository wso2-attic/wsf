<?php

    /**
     * This defines the constants used throught out the library
     */

 	define("DS_INPUT_FORMAT","inputFormat");
 	define("DS_OUTPUT_FORMAT","outputFormat");
 	define("DS_SQL","sql");
 	define("DS_INPUT_MAPPING","inputMapping");
 	define("DS_OPERATIONS","operations");

 	define("DS_CONFIG","config");
    define("DS_DSN", "dsn");
    define("DS_DB_ENGINE", "db");
 	define("DS_USERNAME","username");
 	define("DS_PASSWORD","password");
 	define("DS_DBHOST","dbhost");
 	define("DS_HOST","host");
 	define("DS_DBNAME","dbname");

 	define("DS_SOCKET","socket");
 	define("DS_DBPORT","port");

 	define("DS_ANNOTATIONS","annotations");
    define("DS_LOG_PREFIX", "[DataServices]");
    
    
    define("DS_PROCESSOR_HANDLER", "DSProcessorHandler");
    define("DS_CLASSES", "classes");
    define("DS_ARGS", "args");
    define("DS_QUERY_STRING", "QUERY_STRING");

    // constants related to result element format keys
    define("DS_RESPONSE_NS_DEFAULT_PREFIX", "ds");
    define("DS_RESPONSE_NS_DEFAULT_URI", "http://wso2.org/projects/wsf/php/ds");
    define("DS_REQUEST_NS_DEFAULT_URI", "http://wso2.org/projects/wsf/php/ds");

    define("DS_RESULT_ELEMENT", "resultElement");
    define("DS_DEFAULT_RESULT_ELEMENT", "results");
    define("DS_ROW_ELEMENT", "rowElement");
    define("DS_DEFAULT_ROW_ELEMENT", "row");
    define("DS_USE_NIL", "useNil");
    define("DS_DEFAULT_NAMESPACE", "defaultNamespace");
    define("DS_COLUMN_DEFAULT", "columnDefault");
    define("DS_DEFAULT_COLUMN_DEFAULT", "element");
    define("DS_ELEMENTS", "elements");
    define("DS_ATTRIBUTES", "attributes");
    define("DS_TEXTS", "texts");
    define("DS_QUERIES", "queries");
    define("DS_ELEMENTS_ORDER", "elementsOrder");

    define("DS_COLUMN_NAME", "column");
    define("DS_COLUMN_PARAM", "param");
    define("DS_COLUMN_VALUE", "value");
    define("DS_COLUMN_TYPE", "xsdType");

    define("DS_XSD_ANY", "xsd:any");
    
    define("DS_WSDL_NAME", "name");
    define("DS_WSDL_NAMESPACE", "namespace");
    define("DS_WSDL_TYPE", "type");
    define("DS_WSDL_SEQUENCE", "sequence");
    define("DS_WSDL_ATTRIBUTES", "attributes");
    
    define("DS_WSDL_INPUT", "input");
    define("DS_WSDL_OUTPUT", "output");
    define("DS_WSDL_TYPES", "types");

    define("DS_WSDL_TYPE_POSTFIX", "Type");
    define("DS_WSDL_NILLABLE", "nillable");
    define("DS_WSDL_TRUE", "true");
    define("DS_WSDL_FALSE", "false");
    define("DS_WSDL_MIN_OCCURS", "minOccurs");
    define("DS_WSDL_MAX_OCCURS", "maxOccurs");
    define("DS_WSDL_UNBOUNDED", "unbounded");

    define("DS_DB_NATIVE_TYPE", "native_type");
    define("DS_DB_NAME", "name");
?>
