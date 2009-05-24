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

package org.apache.axis2.schema.extension;

import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.apache.axis2.databinding.types.Language;
import test.axis2.apache.org.BaseType;
import test.axis2.apache.org.FullName;
import test.axis2.apache.org.SimpleType;

import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;

public class SimpleExtensionTest extends TestCase {

    public void testSimpleTypeComplexExtension() {
        FullName fullName = new FullName();
        fullName.setFirst("amila");
        fullName.setMiddle("chinthaka");
        fullName.setLast("suriarachchi");
        fullName.setLanguage(new Language("singhala"));
        fullName.setAttribute1(BaseType.Factory.fromString(BaseType._s1, ""));

        fullName.setAttribute2(SimpleType.Factory.fromString("ATTRIBUTE", ""));

        try {
            OMElement omElement = fullName.getOMElement(FullName.MY_QNAME, OMAbstractFactory.getSOAP11Factory());
            String omElementString;
            XMLStreamReader xmlReader;
            FullName newFullName;

            omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            newFullName = FullName.Factory.parse(xmlReader);
            assertEquals(newFullName.getFirst(), "amila");
            assertEquals(newFullName.getMiddle(), "chinthaka");
            assertEquals(newFullName.getLast(), "suriarachchi");
            assertEquals(newFullName.getLanguage().toString(), "singhala");
            assertEquals(newFullName.getAttribute1().toString(), BaseType._s1);
            assertEquals(newFullName.getAttribute2().toString(), "ATTRIBUTE");

            omElementString = omElement.toString();
            System.out.println("OM String ==> " + omElementString);
            xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            newFullName = FullName.Factory.parse(xmlReader);
            assertEquals(newFullName.getFirst(), "amila");
            assertEquals(newFullName.getMiddle(), "chinthaka");
            assertEquals(newFullName.getLast(), "suriarachchi");
            assertEquals(newFullName.getLanguage().toString(), "singhala");
            assertEquals(newFullName.getAttribute1().toString(), BaseType._s1);
            assertEquals(newFullName.getAttribute2().toString(), "ATTRIBUTE");
        } catch (Exception e) {
            assertFalse(true);
        }
    }


}
