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

package org.apache.axis2.schema.defaultnamespaces;

import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.util.StAXUtils;
import org.apache.axis2.databinding.utils.writer.MTOMAwareXMLSerializer;
import org.apache.axis2.databinding.utils.writer.MTOMAwareXMLStreamWriter;
import org.tempuri.defaultnamepaces.TestChildType;
import org.tempuri.defaultnamepaces.TestElement1;
import org.tempuri.defaultnamepaces.TestSimpleUnion;

import javax.xml.namespace.QName;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import javax.xml.stream.XMLStreamWriter;
import java.io.ByteArrayInputStream;
import java.io.StringWriter;

public class DefaultNamespacesTest extends TestCase {

    public void testTestElement1() {

        TestElement1 testElement1 = new TestElement1();

        TestChildType testChildType = new TestChildType();
        testChildType.setParam1(new QName("http://tempuri.org/defaultnamepaces", "param1"));
        testChildType.setParam2("Param2");
        testChildType.setParam3(new QName("http://tempuri.org/defaultnamepaces", "param3"));
        testChildType.setParam4("Param4");

        TestSimpleUnion testSimpleUnion1 = new TestSimpleUnion();
        testSimpleUnion1.setObject(new QName("http://tempuri.org/defaultnamepaces", "param5"));

        testChildType.setParam5(testSimpleUnion1);

        testChildType.setAttribute1("attribute1");
        testChildType.setAttribute2(new QName("http://tempuri.org/defaultnamepaces", "attribute2"));

        TestSimpleUnion testSimpleUnion2 = new TestSimpleUnion();
        testSimpleUnion2.setObject(new QName("http://tempuri.org/defaultnamepaces", "attribute3"));


        testElement1.setTestElement1(testChildType);
        StringWriter stringWriter = new StringWriter();

        try {

            XMLStreamWriter xmlStreamWriter = StAXUtils.createXMLStreamWriter(stringWriter);
            MTOMAwareXMLStreamWriter mtomAwareXMLStreamWriter = new MTOMAwareXMLSerializer(xmlStreamWriter);
            testElement1.getTestElement1().serialize(new QName("http://tempuri.org/defaultnamepaces", "TestElement1", "ns1"),
                    OMAbstractFactory.getSOAP11Factory(), mtomAwareXMLStreamWriter);
            xmlStreamWriter.flush();
            xmlStreamWriter.close();
            String omElementString = stringWriter.toString();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestElement1 result = TestElement1.Factory.parse(xmlReader);
            assertTrue(result.getTestElement1() instanceof TestChildType);
            TestChildType resultType = (TestChildType) result.getTestElement1();
            assertEquals(resultType.getParam1(), new QName("http://tempuri.org/defaultnamepaces", "param1"));
            assertEquals(resultType.getParam2(), "Param2");
            assertEquals(resultType.getParam3(), new QName("http://tempuri.org/defaultnamepaces", "param3"));
            assertEquals(resultType.getParam4(), "Param4");
            assertEquals(resultType.getAttribute1(), "attribute1");
            assertEquals(resultType.getAttribute2(), new QName("http://tempuri.org/defaultnamepaces", "attribute2"));
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            e.printStackTrace();
            fail();
        }

    }
}
