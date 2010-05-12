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

package org.apache.axis2.schema.base64binary;

import junit.framework.TestCase;
import org.apache.axiom.attachments.ByteArrayDataSource;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.apache.axis2.databinding.ADBException;
import org.apache.axis2.databinding.types.HexBinary;
import org.w3.www._2005._05.xmlmime.*;

import javax.activation.DataHandler;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;


public class Base64BinaryTest extends TestCase {

    public void testBase64Binary(){
        TestBase64Binary testBase64Binary = new TestBase64Binary();
        Base64Binary base64Binary = new Base64Binary();
        testBase64Binary.setTestBase64Binary(base64Binary);

        String testString = "new test string";

        DataHandler dataHandler = new DataHandler(new ByteArrayDataSource(testString.getBytes()));
        base64Binary.setBase64Binary(dataHandler);
        ContentType_type0 contentType_type0 = new ContentType_type0();
        contentType_type0.setContentType_type0("test content type");
        base64Binary.setContentType(contentType_type0);


        try {
            OMElement omElement = testBase64Binary.getOMElement(TestBase64Binary.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestBase64Binary result = TestBase64Binary.Factory.parse(xmlReader);
            DataHandler resultDataHandler = result.getTestBase64Binary().getBase64Binary();
            byte[] bytes = new byte[128];
            int length = resultDataHandler.getInputStream().read(bytes);
            String resultString = new String(bytes,0,length);
            assertEquals(resultString,testString);
            assertEquals(result.getTestBase64Binary().getContentType().getContentType_type0(),"test content type");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testHexBinary(){
        TestHexBinary testHexBinary = new TestHexBinary();
        org.w3.www._2005._05.xmlmime.HexBinary hexBinary = new org.w3.www._2005._05.xmlmime.HexBinary();
        testHexBinary.setTestHexBinary(hexBinary);

        String testString = "ab";

        org.apache.axis2.databinding.types.HexBinary adbHexBinary =
                new  org.apache.axis2.databinding.types.HexBinary(testString);

        hexBinary.setHexBinary(adbHexBinary);
        ContentType_type0 contentType_type0 = new ContentType_type0();
        contentType_type0.setContentType_type0("test content type");
        hexBinary.setContentType(contentType_type0);


        try {
            OMElement omElement = testHexBinary.getOMElement(TestBase64Binary.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestHexBinary result = TestHexBinary.Factory.parse(xmlReader);
            assertEquals(result.getTestHexBinary().getHexBinary().toString(),testString);
            assertEquals(result.getTestHexBinary().getContentType().getContentType_type0(),"test content type");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testBase64MultiElement(){

        TestBase64MultiElement testBase64MultiElement = new TestBase64MultiElement();
        String testString = "testing base 64 elements";
        DataHandler dataHandler = new DataHandler(new ByteArrayDataSource(testString.getBytes()));
        testBase64MultiElement.setParam1(dataHandler);
        testBase64MultiElement.setParam2("test string");
        testBase64MultiElement.setParam3(5);

        try {
            OMElement omElement = testBase64MultiElement.getOMElement(TestBase64MultiElement.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestBase64MultiElement result = TestBase64MultiElement.Factory.parse(xmlReader);
            DataHandler resultDataHandler = result.getParam1();
            byte[] buffer = new byte[128];
            int length = resultDataHandler.getInputStream().read(buffer);
            String resultString = new String(buffer,0,length);
            assertEquals(testString,resultString);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }


}
