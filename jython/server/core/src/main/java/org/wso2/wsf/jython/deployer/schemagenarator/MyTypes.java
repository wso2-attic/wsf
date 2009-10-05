/*
 * Copyright 2008 WSO2, Inc. http://www.wso2.org
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

package org.wso2.wsf.jython.deployer.schemagenarator;

import org.apache.ws.commons.schema.constants.Constants;

public class MyTypes extends TypeTable{
    protected void populateSimpleTypes() {
        simpleTypetoxsd.put("xs:string", Constants.XSD_STRING);
        simpleTypetoxsd.put("xs:normalizedString", Constants.XSD_NORMALIZEDSTRING);
        simpleTypetoxsd.put("xs:token", Constants.XSD_TOKEN);
        simpleTypetoxsd.put("xs:language", Constants.XSD_LANGUAGE);
        simpleTypetoxsd.put("xs:Name", Constants.XSD_NAME);
        simpleTypetoxsd.put("xs:NCName", Constants.XSD_NCNAME);
        simpleTypetoxsd.put("xs:NOTATION", Constants.XSD_NOTATION);
        simpleTypetoxsd.put("xs:anyURI", Constants.XSD_ANYURI);
        simpleTypetoxsd.put("xs:float", Constants.XSD_FLOAT);
        simpleTypetoxsd.put("xs:double", Constants.XSD_DOUBLE);
        simpleTypetoxsd.put("xs:duration", Constants.XSD_DURATION);
        simpleTypetoxsd.put("xs:integer", Constants.XSD_INTEGER);
        simpleTypetoxsd.put("xs:nonPositiveInteger", Constants.XSD_NONPOSITIVEINTEGER);
        simpleTypetoxsd.put("xs:negativeInteger", Constants.XSD_NEGATIVEINTEGER);
        simpleTypetoxsd.put("xs:long", Constants.XSD_LONG);
        simpleTypetoxsd.put("xs:int", Constants.XSD_INT);
        simpleTypetoxsd.put("xs:short", Constants.XSD_SHORT);
        simpleTypetoxsd.put("xs:byte", Constants.XSD_BYTE);
        simpleTypetoxsd.put("xs:nonNegativeInteger", Constants.XSD_NONNEGATIVEINTEGER);
        simpleTypetoxsd.put("xs:unsignedLong", Constants.XSD_UNSIGNEDLONG);
        simpleTypetoxsd.put("xs:unsignedInt", Constants.XSD_UNSIGNEDINT);
        simpleTypetoxsd.put("xs:unsignedShort", Constants.XSD_UNSIGNEDSHORT);
        simpleTypetoxsd.put("xs:unsignedByte", Constants.XSD_UNSIGNEDBYTE);
        simpleTypetoxsd.put("xs:positiveInteger", Constants.XSD_POSITIVEINTEGER);
        simpleTypetoxsd.put("xs:decimal", Constants.XSD_DECIMAL);
        simpleTypetoxsd.put("xs:boolean", Constants.XSD_BOOLEAN);
        simpleTypetoxsd.put("xs:dateTime", Constants.XSD_DATETIME);
        simpleTypetoxsd.put("xs:date", Constants.XSD_DATE);
        simpleTypetoxsd.put("xs:time", Constants.XSD_TIME);
        simpleTypetoxsd.put("xs:gYearMonth", Constants.XSD_YEARMONTH);
        simpleTypetoxsd.put("xs:gMonthDay", Constants.XSD_MONTHDAY);
        simpleTypetoxsd.put("xs:gYear", Constants.XSD_YEAR);
        simpleTypetoxsd.put("xs:gDay", Constants.XSD_DAY);
        simpleTypetoxsd.put("xs:gMonth", Constants.XSD_MONTH);
        simpleTypetoxsd.put("xs:QName", Constants.XSD_QNAME);
        simpleTypetoxsd.put("xs:hexBinary", Constants.XSD_HEXBIN);
        simpleTypetoxsd.put("xs:base64Binary", Constants.XSD_BASE64);
        simpleTypetoxsd.put("xs:anyType", Constants.XSD_ANYTYPE);

        // Support for python data types
        simpleTypetoxsd.put("int", Constants.XSD_INT);
        simpleTypetoxsd.put("integer", Constants.XSD_INT);
        simpleTypetoxsd.put("Integer", Constants.XSD_INT);
        simpleTypetoxsd.put("long", Constants.XSD_LONG);
        simpleTypetoxsd.put("Long", Constants.XSD_LONG);        
        simpleTypetoxsd.put("double", Constants.XSD_DOUBLE);
        simpleTypetoxsd.put("Double", Constants.XSD_DOUBLE);
        simpleTypetoxsd.put("complex", Constants.XSD_ANYTYPE);
        simpleTypetoxsd.put("Complex", Constants.XSD_ANYTYPE);
        simpleTypetoxsd.put("string", Constants.XSD_STRING);
        simpleTypetoxsd.put("String", Constants.XSD_STRING);
        simpleTypetoxsd.put("dictionary", Constants.XSD_ANYTYPE);
        simpleTypetoxsd.put("dict", Constants.XSD_ANYTYPE);
        simpleTypetoxsd.put("Dictionary", Constants.XSD_ANYTYPE);
        simpleTypetoxsd.put("Dict", Constants.XSD_ANYTYPE);
        simpleTypetoxsd.put("tuple", Constants.XSD_ANYTYPE);
        simpleTypetoxsd.put("Tuple", Constants.XSD_ANYTYPE);
        simpleTypetoxsd.put("list", Constants.XSD_ANYTYPE);
        simpleTypetoxsd.put("List", Constants.XSD_ANYTYPE);
        simpleTypetoxsd.put("array", Constants.XSD_ANYTYPE);
        simpleTypetoxsd.put("Array", Constants.XSD_ANYTYPE);

    }
}
