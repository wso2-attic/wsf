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

package org.apache.axis2.schema.rampart;

import junit.framework.TestCase;
import org.apache.axiom.attachments.ByteArrayDataSource;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.apache.axis2.databinding.ADBException;
import org.w3.www._2005._05.xmlmime.Base64Binary;
import org.w3.www._2005._05.xmlmime.ContentType_type0;
import org.w3.www._2005._05.xmlmime.TestExtension;

import javax.activation.DataHandler;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;


public class RampartTest extends TestCase {

    public void testExtension(){
        TestExtension testExtension = new TestExtension();

        Base64Binary base64Binary = new Base64Binary();
        testExtension.setTestExtension(base64Binary);

        String testString = "test base 64 eleemnt";
        DataHandler dataHandler = new DataHandler(new ByteArrayDataSource(testString.getBytes()));
        base64Binary.setBase64Binary(dataHandler);

        ContentType_type0 contentType_type0 = new ContentType_type0();
        contentType_type0.setContentType_type0("test string");
        base64Binary.setContentType(contentType_type0);

        try {
            OMElement omElement = testExtension.getOMElement(TestExtension.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestExtension result = TestExtension.Factory.parse(xmlReader);
            
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }
}
