<?php
/*
 * Copyright (c) 2005-2010 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * This class includes the Attribute names, attribute values and
 * the namespaces used in wsdl generation scripts
 */

class WS_WSDL_Const
{

    const WS_DOM_DOCUMENT_VERSION_NO = '1.0';
    const WS_DOM_DOCUMENT_ENCODING = 'UTF-8';

    const WS_WSDL_DEFAULT_SCHEMA_ATTR_NAME = 'tnx';
    const WS_WSDL_TNS_ATTR_NAME = 'tns';

    const WS_WSDL_DEFINITION = 'definitions';
    const WS_WSDL_DEF_XSD_QN = 'xmlns:xsd';
    const WS_WSDL_DEF_TNS_QN = 'xmlns:tns';
    const WS_WSDL_DEF_SOAP_ENV_QN = 'xmlns:soap';
    const WS_WSDL_DEF_WSDL_QN = 'xmlns:wsdl';
    const WS_WSDL_DEF_SOAP_ENC_QN = 'xmlns:soapenc';
    const WS_WSDL_DEF_TARGET_NS = 'targetNamespace';
    const WS_WSDL_DEF_HTTP_QN = 'xmlns:http';
    const WS_WSDL_DEF_ELEMENT_PREFIX = 'xmlns:tnx';
    
    const WS_WSDL_DEF_ELEMENT_NS_POSTFIX = '/xsd';


    const WS_WSDL2_DESCRIPTION = "description";
    const WS_WSDL2_WSOAP_ATTR_NAME = "xmlns:wsoap";
    const WS_WSDL2_WSDLX_ATTR_NAME = "xmlns:wsdlx";
    const WS_WSDL2_WHTTP_ATTR_NAME = "xmlns:whttp";
    const WS_WSDL2_DOCUMENTATION = "documentation";


    const WS_WSDL2_NAMESPACE = "http://www.w3.org/2006/01/wsdl";
    const WS_WSDL2_WSOAP_ATTR_VAL = "http://www.w3.org/2006/01/wsdl/soap";
    const WS_WSDL2_WSDLX_ATTR_VAL = "http://www.w3.org/2006/01/wsdl-extension";
    const WS_WSDL2_WHTTP_ATTR_VAL = "http://www.w3.org/2006/01/wsdl/http";
    const WS_WSDL2_SOAP_ATTR_VAL = "http://www.w3.org/2003/05/soap-envelope";
    const WS_WSDL2_BINDING_ATTR_VAL = "http://www.w3.org/2003/05/soap/bindings/HTTP";
    const WS_WSDL2_PATTERN_ATTR_VAL ="http://www.w3.org/2006/01/wsdl/in-out";

    const WS_SOAP_XML_SCHEMA_NAMESPACE = 'http://www.w3.org/2001/XMLSchema';
    const WS_SOAP_SCHEMA_INSTANCE_NAMESPACE = 'http://www.w3.org/2001/XMLSchema-instance';
    const WS_SOAP_SCHEMA_ENCODING_NAMESPACE = 'http://schemas.xmlsoap.org/soap/encoding/';
    const WS_SOAP_ENVELOP_NAMESPACE = 'http://schemas.xmlsoap.org/soap/envelope/';
    const WS_SCHEMA_SOAP_HTTP_NAMESPACE = 'http://schemas.xmlsoap.org/soap/http';
    const WS_SCHEMA_SOAP_NAMESPACE = 'http://schemas.xmlsoap.org/wsdl/soap/';
    const WS_SCHEMA_WSDL_NAMESPACE = 'http://schemas.xmlsoap.org/wsdl/';
    
    const WS_WSDL_HTTP12_NAMESPACE  = 'http://www.w3.org/2003/05/soap/bindings/HTTP/';

    const WS_WSDL_DEF_SCHEMA_URI = 'http://www.w3.org/2000/xmlns/';

    const WS_WSDL_WSAW_NAMESPACE = "http://www.w3.org/2006/05/addressing/wsdl";
    const WS_WSDL_WSAW_PREFIX = "wsaw";

    const WS_WSDL_OPERTION_INPUT_TAG = '';
    const WS_WSDL_OPERTION_OUTPUT_TAG = 'response';


    const WS_WSDL_ACTION = "Action";
    const WS_WSDL_SERVICE_ATTR_NAME = "service";
    const WS_WSDL_NAME_ATTR_NAME = "name";
    const WS_WSDL_PORT_ATTR_NAME = "port";
    const WS_WSDL_BINDING_ATTR_NAME ="binding";
    const WS_WSDL_LOCATION_ATTR_NAME ="location";
    const WS_WSDL_ADDRESS_ATTR_NAME ="address";
    const WS_WSDL_INTERFACE_ATTR_NAME = "interface";
    const WS_WSDL_ENDPOINT_ATTR_NAME = "endpoint";

    const WS_WSDL_INPUT_ATTR_NAME = 'input';
    const WS_WSDL_OUTPUT_ATTR_NAME = 'output';
    const WS_WSDL_TYPE_ATTR_NAME = 'type';
    const WS_WSDL_RETURN_ATTR_NAME = 'return';

    const WS_WSDL_MESSAGE_ATTR_NAME = 'message';
    const WS_WSDL_PART_ATTR_NAME = 'part';
    const WS_WSDL_TAG_ATTR_NAME = 'tag';
    const WS_WSDL_ELEMENT_ATTR_NAME = 'element';
    const WS_WSDL_ATTRIBUTE_ATTR_NAME = 'attribute';

    const WS_WSDL_STYLE_ATTR_NAME = 'style';
    const WS_WSDL_RPC_ATTR_NAME = 'rpc';
    const WS_WSDL_DOCUMENT_ATTR_NAME = 'document';
    const WS_WSDL_TRANSPORT_ATTR_NAME = 'transport';
    const WS_WSDL_OPERATION_ATTR_NAME = 'operation';
    const WS_WSDL_BODY_ATTR_NAME = 'body';
    const WS_WSDL_USE_ATTR_NAME = 'use';
    const WS_WSDL_ENCODED_ATTR_NAME = 'encoded';
    const WS_WSDL_LITERAL_ATTR_NAME = 'literal';
    const WS_WSDL_ENCOD_STYLE_ATTR_NAME= 'encodingStyle';
    const WS_WSDL_RPC_NAMESPACE= 'namespace';
    const WS_WSDL_RPC_NAMESPACE_VALUE= 'http://www.wso2.org/php';
    const WS_WSDL_SOAP_ACTION_ATTR_NAME = 'soapAction';

    const WS_WSDL_PROTOCAL_ATTR_NAME = "protocol";
    const WS_WSDL_VERSION_ATTR_NAME = "version";
    //const WS_WSDL_BINDING_VERSION_ATTR_VAL = "1.2";
    const WS_WSDL_SOAP_ATTR_NAME = "soap";

    const WS_WSDL_HTTP_ATTR_NAME = "http://";
    const WS_WSDL_HTTPS_ATTR_NAME = "https://";
    const WS_WSDL_PORTTYPE_ATTR_NAME ='portType';

    const WS_WSDL_PATTERN_ATTR_NAME = "pattern";
    const WS_WSDL_PARAMETERS_ATTR_NAME = "parameters";

    const WS_WSDL_NAMESPACE_ATTR_NAME = 'ns';
    const WS_WSDL_WSDLTYPE_ATTR_NAME = 'wsdlType';
    const WS_WSDL_TYPES_ATTR_NAME ='types';
    const WS_WSDL_SCHEMA_ATTR_NAME = 'schema';
    const WS_WSDL_COMPLXTYPE_ATTR_NAME = 'complexType';
    const WS_WSDL_COMPLXCONTENT_ATTR_NAME = 'compleContent';
    const WS_WSDL_RESTRICTION_ATTR_NAME = 'restriction';
    const WS_WSDL_BASE_ATTR_NAME = 'base';
    const WS_WSDL_REF_ATTR_NAME = 'ref';
    const WS_WSDL_SOAPENCARRAY_ATTR_NAME = 'soapenc:array';
    const WS_WSDL_SOAPENCARRAYTYPE_ATTR_NAME = 'soapenc:arrayType';
    const WS_WSDL_ARRAYTYPE_ATTR_NAME = 'arrayType';
    const WS_WSDL_TNSMIXED_ATTR_NAME = 'tns:mixed[]';
    const WS_WSDL_ALL_ATTR_NAME = 'all';
    const WS_WSDL_SEQUENCE_ATTR_NAME = 'sequence';
    const WS_WSDL_XSD_ATTR_NAME = 'xsd:';
    const WS_WSDL_RESPONSE_ATTR_NAME = 'Response';
    const WS_WSDL_IN_ATTR_NAME = 'In';
    const WS_WSDL_OUT_ATTR_NAME = 'Out';
    const WS_WSDL_ELEMENTFORMDEFAULT_ATTR_NAME = 'elementFormDefault';
    const WS_WSDL_QUALIFIED_ATTR_NAME = 'qualified';
    
    const WS_WSDL_INPUT = 'input';
    const WS_WSDL_OUTPUT = 'output';

    const WS_WSDL_ATTR_MAX_OCCURS = "maxOccurs";
    const WS_WSDL_ATTR_MIN_OCCURS = "minOccurs";
    const WS_WSDL_ATTR_VALUE_UNBOUNDED = "unbounded";

    const WS_WSDL_SCHEMA_TYPE_DEFAULT_NS = "http://www.wso2.org/php/xsd";
    const WS_WSDL_DEFAULT_NS = "http://www.wso2.org/php";

    const WSF_WSDL_VERSION2_0 = "wsdl2.0";
    const WSF_WSDL_VERSION1_1 = "wsdl1.1";

    const WSF_WSDL_WSDL11_2_2_CONVERTORS = "dynamic_invocation/xslt/wsdl11to20.xsl10.xsl";

    const WSF_WSDL_RPC_ENCODED = "rpc-enc";
    const WSF_WSDL_RPC = "rpc";
    const WSF_WSDL_DOCLIT = "doclit";
    const WSF_WSDL_IMPORT = "import";
    const WSF_WSDL_NAMESPACE = "namespace";

    static public $defaultTypes = array(
                                      'string'    => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                           'name' => 'string'),
                                      'boolean'  => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          'name' => 'boolean'),
                                      'double' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                        'name' =>'double'),
                                      'float'   => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                         'name' =>'float'),
                                      'int'    => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                        'name' => 'int'),
                                      'integer'  => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          'name' => 'integer'),
                                      'byte' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      'name' =>'byte'),
                                      'decimal'   => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                           'name' =>'decimal'),
                                      'base64Binary' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                              'name' => 'base64Binary'),
                                      'hexBinary' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                           'name' => 'hexBinary'),
                                      'anyType' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                         'name' =>'anyType'),
                                      'any' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                     'name' =>'any'),
                                      'QName'    => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          'name' => 'QName'),
                                      'dateTime'  => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                           'name' => 'dateTime'),
                                      'date' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      'name' =>'date'),
                                      'time'   => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                        'name' =>'time'),
                                      'unsignedLong'   => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                                'name' =>'unsignedLong'),
                                      'unsignedInt'    => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                                'name' => 'unsignedInt'),
                                      'unsignedShort'  => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                                'name' => 'unsignedShort'),
                                      'unsignedByte' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                              'name' =>'unsignedByte'),
                                      'positiveInteger'   => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                                   'name' =>'positiveInteger'),
                                      'negativeInteger'    => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                                    'name' => 'negativeInteger'),
                                      'nonNegativeInteger'  => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                                     'name' => 'nonnegativeInteger'),
                                      'nonPositiveInteger' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                                    'name' =>'nonPositiveInteger'),
                                      'gYearMonth'   => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                              'name' =>'gYearMonth'),
                                      'gMonthDay' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                           'name' => 'gMonthDay'),
                                      'gYear' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                       'name' => 'gYear'),
                                      'gDay' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      'name' => 'gDay'),
                                      'duration' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          'name' =>'duration'),
                                      'Name' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      'name' =>'Name'),
                                      'NCName'    => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                           'name' => 'NCName'),
                                      'NMTOKENS'  => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                           'name' => 'NMTOKENS'),
                                      'NOTATION' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          'name' =>'NOTATION'),
                                      'NMTOKEN'   => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                           'name' =>'NMTOKEN'),
                                      'ENTITY'   => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          'name' =>'ENTITY'),
                                      'ENTITIES' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          'name' => 'ENTITIES'),
                                      'IDREF' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                       'name' =>'IDREF'),
                                      'IDREFS' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                        'name' =>'IDREFS'),
                                      'anyURI'    => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                           'name' => 'anyURI'),
                                      'language'  => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                           'name' => 'language'),
                                      'ID' => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                    'name' =>'ID'),
                                      'normalizedString'   => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                                    'name' =>'normalizedString'),
                                      'token'   => array('ns'   => self::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                         'name' =>'token'));
}

?>
