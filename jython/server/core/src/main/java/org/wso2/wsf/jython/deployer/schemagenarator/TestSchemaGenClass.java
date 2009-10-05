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

import org.apache.ws.commons.schema.XmlSchema;
import org.apache.ws.commons.schema.XmlSchemaElement;

public class TestSchemaGenClass {

    public static void main(String[] args) throws Exception {
        MyTypes types = new MyTypes();
        SchemaGenerator schemaGenerator = new SchemaGenerator("http://foo.com", types);
        ComplexType complexType= new ComplexType();
        complexType.setName("Test");    // method name
        SimpleType simpleType = new SimpleType();
        simpleType.setName("simple1");
        simpleType.setType("string");
        SimpleType simpleType2 = new SimpleType();
        simpleType2.setName("simple2");
        simpleType2.setType("string");
        SimpleType simpleType3 = new SimpleType();
        simpleType3.setName("simple3");
        simpleType3.setType("string");

        complexType.addMember(simpleType);
        complexType.addMember(simpleType2);
        complexType.addMember(simpleType3);

//        ComplexType complexType2= new ComplexType();
//        complexType2.setName("InnerType");
//        SimpleType simpleType4 = new SimpleType();
//        simpleType4.setName("simple4");
//        simpleType4.setType("string");
//
//        complexType2.addMember(simpleType4);
//        complexType.addMember(complexType2);
//
//        SimpleType simpleType5 = new SimpleType();
//        simpleType5.setName("simple5");
//        simpleType5.setType("string");

//        complexType.addMember(simpleType5);
        XmlSchemaElement schemaElement = schemaGenerator.createInputElement(complexType, "Test");
        schemaElement.getQName(); // set this to the QName of the in message 
        XmlSchema schema = schemaGenerator.getSchema();
        System.out.println("");
    }
}
