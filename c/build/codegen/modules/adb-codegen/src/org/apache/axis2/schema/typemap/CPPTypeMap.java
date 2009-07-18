/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

package org.apache.axis2.schema.typemap;

import org.apache.axis2.schema.SchemaConstants;

import javax.xml.namespace.QName;
import java.util.HashMap;
import java.util.Map;

/**
 * The CPP type map. uses a static map for caching
 */
public class CPPTypeMap implements TypeMap{

    private static Map typeMap = new HashMap();

    // Type map for the standard schema types
    public Map getTypeMap(){
         return typeMap;
    }

    static {
        // If SOAP 1.1 over the wire, map wrapper classes to XSD primitives.
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_STRING,
                                 "std::string");

        // The XSD Primitives are mapped to axis2/c primitives.
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_BOOLEAN, "bool");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_DOUBLE, "double");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_FLOAT, "float");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_INT, "int");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_INTEGER,
                                 "int");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_LONG, "int64_t");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_SHORT, "short");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_BYTE, "axis2_byte_t");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_ANY, "wso2wsf::OMElement*");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_DECIMAL, "double");

        CPPTypeMap.addTypemapping(SchemaConstants.XSD_ANYTYPE,
                                 "wso2wsf::OMElement*");
                          // wrap axutil_qname to c++
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_QNAME,
                                 "axutil_qname_t*");

                        // wrap to c++
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_DATE,
                                 "axutil_date_time_t*");

        CPPTypeMap.addTypemapping(SchemaConstants.XSD_TIME,
                                 "axutil_date_time_t*");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_DATETIME,
                                 "axutil_date_time_t*");
                // wrap for c++
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_BASE64,
                                 "axutil_base64_binary_t*");

        CPPTypeMap.addTypemapping(SchemaConstants.XSD_HEXBIN,
                                 "wso2wsf::OMElement*");

        // These are the g* types (gYearMonth, etc) which map to Axis types
        // These types are mapped to an integer
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_YEARMONTH,
                                 "axutil_date_time_t*");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_YEAR,
                                 "int");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_MONTH,
                                 "int");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_DAY,
                                 "int");
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_MONTHDAY,
                                 "axutil_date_time_t*");

        // xsd:token
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_TOKEN, "std::string");

        // a xsd:normalizedString
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_NORMALIZEDSTRING,
                                 "std::string");

        // a xsd:unsignedLong
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_UNSIGNEDLONG,
                                 "uint64_t");

        // a xsd:unsignedInt
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_UNSIGNEDINT,
                                 "unsigned int");

        // a xsd:unsignedShort
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_UNSIGNEDSHORT,
                                 "unsigned short");

        // a xsd:unsignedByte
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_UNSIGNEDBYTE,
                                 "axis2_unsigned_byte_t");

        // a xsd:nonNegativeInteger
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_NONNEGATIVEINTEGER,
                                 "unsigned int");

        // a xsd:negativeInteger
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_NEGATIVEINTEGER,
                                 "int");

        // a xsd:positiveInteger
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_POSITIVEINTEGER,
                                 "unsigned int");

        // a xsd:nonPositiveInteger
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_NONPOSITIVEINTEGER,
                                 "unsigned int");

        // a xsd:Name
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_NAME, "std::string");

        // a xsd:NCName
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_NCNAME, "std::string");

        // a xsd:ID
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_ID, "std::string");

        // a xsd:language
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_LANGUAGE, "std::string");

        // a xsd:NmToken
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_NMTOKEN, "std::string");

        // a xsd:NmTokens
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_NMTOKENS, "std::string");

        // a xsd:NOTATION
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_NOTATION, "OMElement*");

        // a xsd:XSD_ENTITY
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_ENTITY, "std::string");

        // a xsd:XSD_ENTITIES
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_ENTITIES, "std::string");

        // a xsd:XSD_IDREF
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_IDREF, "std::string");

        // a xsd:XSD_XSD_IDREFS
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_IDREFS, "std::string");

        // a xsd:Duration
        // wrap for c++
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_DURATION, "axutil_duration_t*");

        // a xsd:anyURI
        // wrap for c++
        CPPTypeMap.addTypemapping(SchemaConstants.XSD_ANYURI,
                                 "axutil_uri_t*");
    }

    private static void addTypemapping(QName name, String str) {
        CPPTypeMap.typeMap.put(name, str);
    }

    // Type map for the soap encoding types
    public Map getSoapEncodingTypesMap() {
        return soapEncodingTypeMap;
    }

    private static Map soapEncodingTypeMap = new HashMap();

    static {
        // populate the soapEncodingTypeMap
        // std::list
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_ARRAY,
                "std::vector<void*>*");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_STRUCT,
                "wso2wsf::OMElement*");
        // wrap for C++
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_BASE64,
                "axutil_base64_binary_t*");
        // warp for c++
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_DURATION,
                "axutil_duration_t*");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_DATETIME,
                "axutil_date_time_t*");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_NOTATION,
                "wso2wsf::OMElement*");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_TIME,
                "axutil_date_time_t*");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_DATE,
                "axutil_date_time_t*");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_GYEARMONTH,
                "axutil_date_time_t*");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_GYEAR,
                "int");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_GMONTHDAY,
                "axutil_date_time_t*");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_GDAY,
                "int");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_GMONTH,
                "int");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_BOOLEAN,
                "bool");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_BASE64BINARY,
                "axutil_base64_binary_t*");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_HEXBINARY,
                "wso2wsf::OMElement*");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_FLOAT,
                "float");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_DOUBLE,
                "double");
        // wrap
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_ANYURI,
                "axutil_uri_t*");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_QNAME,
                "axutil_qname_t*");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_STRING,
                "std::string");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_NORMALIZEDSTRING,
                "std::string");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_TOKEN,
                "std::string");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_LANGUAGE,
                "std::string");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_NAME,
                "std::string");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_NMTOKEN,
                "std::string");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_NCNAME,
                "std::string");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_ID,
                "std::string");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_IDREF,
                "std::string");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_ENTITY,
                "std::string");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_IDREFS,
                "std::string");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_ENTITIES,
                "std::string");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_DECIMAL,
                "double");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_INTEGER,
                "int");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_NONPOSITIVEINTEGER,
                "int");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_NEGATIVEINTEGER,
                "int");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_LONG,
                "int64_t");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_INT,
                "int");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_SHORT,
                "short");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_BYTE,
                "byte");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_NONNEGATIVEINTEGER,
                "unsigned int");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_UNSIGNEDLONG,
                "uint64_t");
        addSoapEncodingTypeMapping(SchemaConstants.SOAP_ENCODING_UNSIGNEDINT,
                "unsigned int");
    }

    private static void addSoapEncodingTypeMapping(QName name, String className) {
        soapEncodingTypeMap.put(name, className);
    }
}
