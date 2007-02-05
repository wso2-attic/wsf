/*
 * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
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
package org.wso2.javascript.rhino;

import org.apache.axis2.client.Options;
import org.apache.axis2.client.ServiceClient;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.transport.http.SimpleHTTPServer;
import org.apache.axis2.context.ConfigurationContextFactory;
import org.apache.axis2.context.ConfigurationContext;
import org.apache.axis2.AxisFault;
import org.apache.axiom.om.OMFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.impl.builder.StAXOMBuilder;

import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import javax.xml.stream.XMLInputFactory;
import java.io.ByteArrayInputStream;

import junit.framework.TestCase;

public class ReceiverIntegrationTest extends TestCase implements ReceiverTestConstants{
    private String expectedString = "Hello Echo";

        private SimpleHTTPServer server;

        private ConfigurationContext configurationContext;

        public ReceiverIntegrationTest() {
        }

        protected void setUp() throws Exception {

            configurationContext = ConfigurationContextFactory
                    .createConfigurationContextFromFileSystem(null, null);
            server = new SimpleHTTPServer(configurationContext,TESTING_PORT);
            try {
                server.start();
            } catch(AxisFault af) {
                af.printStackTrace();
            }
            AxisService service = Utils.createSimpleJSService(serviceName,
                    ("EchoJS.js"), operationName);
            server.getConfigurationContext().getAxisConfiguration().addService(
                    service);
        }

        protected void tearDown() throws Exception {
            server.stop();
        }

        protected static OMElement getEchoOMElement() throws XMLStreamException {

            String str = "<echoString>Hello Echo</echoString>";

            XMLStreamReader xmlReader = XMLInputFactory.newInstance().createXMLStreamReader(new
                    ByteArrayInputStream(str.getBytes()));
            OMFactory fac = OMAbstractFactory.getOMFactory();

            StAXOMBuilder staxOMBuilder = new
                    StAXOMBuilder(fac, xmlReader);
            return staxOMBuilder.getDocumentElement();

        }

        public void testEcho() throws Exception {
            OMElement payload = getEchoOMElement();
            Options options = new Options();
            options.setTo(targetEPR);
            ServiceClient sender = new ServiceClient(configurationContext, null);
            options.setAction("urn:echo");
            sender.setOptions(options);
            OMElement result = sender.sendReceive(payload);
            TestCase.assertEquals(expectedString, result.getFirstElement().getText());
        }

}
