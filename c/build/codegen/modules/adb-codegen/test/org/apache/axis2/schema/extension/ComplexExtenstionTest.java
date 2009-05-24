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
import test.axis2.apache.org.BaseType;
import test.axis2.apache.org.ExtendedComplexType;
import test.axis2.apache.org.FullName;
import test.axis2.apache.org.TestComplexElement;

import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;

public class ComplexExtenstionTest extends TestCase {

    public void testComplexExtension() {

        TestComplexElement testComplexElement = new TestComplexElement();
        ExtendedComplexType extendedComplexType = new ExtendedComplexType();
        testComplexElement.setTestComplexElement(extendedComplexType);
        extendedComplexType.setFirst("Amila");
        extendedComplexType.setMiddle("Chinthaka");
        extendedComplexType.setLast("Suriarachchi");
        extendedComplexType.setParentElement1("test1");
        extendedComplexType.setParentElement2("test2");

        try {
            OMElement omElement = testComplexElement.getOMElement(TestComplexElement.MY_QNAME, OMAbstractFactory.getSOAP11Factory());
            String omElementString;
            XMLStreamReader xmlReader;
            TestComplexElement result;

            omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            result = TestComplexElement.Factory.parse(xmlReader);
            assertEquals(result.getTestComplexElement().getFirst(),"Amila");
            assertEquals(result.getTestComplexElement().getMiddle(),"Chinthaka");
            assertEquals(result.getTestComplexElement().getLast(),"Suriarachchi");
            assertEquals(result.getTestComplexElement().getParentElement1(),"test1");
            assertEquals(result.getTestComplexElement().getParentElement2(),"test2");

            omElementString = omElement.toString();
            System.out.println("OM String ==> " + omElementString);
            xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            result = TestComplexElement.Factory.parse(xmlReader);
            assertEquals(result.getTestComplexElement().getFirst(),"Amila");
            assertEquals(result.getTestComplexElement().getMiddle(),"Chinthaka");
            assertEquals(result.getTestComplexElement().getLast(),"Suriarachchi");
            assertEquals(result.getTestComplexElement().getParentElement1(),"test1");
            assertEquals(result.getTestComplexElement().getParentElement2(),"test2");

        } catch (Exception e) {
            assertFalse(true);
        }

    }
}
