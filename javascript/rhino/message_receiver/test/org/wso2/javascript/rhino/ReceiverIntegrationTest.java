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

import junit.framework.TestCase;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.impl.builder.StAXOMBuilder;
import org.apache.axis2.client.Options;
import org.apache.axis2.client.ServiceClient;
import org.apache.axis2.context.ConfigurationContext;
import org.apache.axis2.context.ConfigurationContextFactory;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.transport.http.SimpleHTTPServer;

import javax.xml.stream.XMLStreamException;
import java.io.ByteArrayInputStream;

/**
 * Class ReceiverIntegrationTest tests the Javascript message receiver
 */
public class ReceiverIntegrationTest extends TestCase implements ReceiverTestConstants {

    private SimpleHTTPServer server;

    private ConfigurationContext configurationContext;

    private AxisService service;

    public ReceiverIntegrationTest() {
    }

    protected void setUp() throws Exception {
        configurationContext = ConfigurationContextFactory.createConfigurationContextFromFileSystem(
                null, axis2xml);
        server = new SimpleHTTPServer(configurationContext, TESTING_PORT);
        server.start();

        service = JSUtils.createSimpleJSService(serviceName, serviceJS);
        server.getConfigurationContext().getAxisConfiguration().addService(
                service);

    }

    protected void tearDown() throws Exception {
        server.stop();
    }

    private OMElement buildOMElement(String str) throws XMLStreamException {
        StAXOMBuilder staxOMBuilder = new StAXOMBuilder(
                new ByteArrayInputStream(str.getBytes()));
        return staxOMBuilder.getDocumentElement();
    }

    private OMElement getJSONEchoOMElement() throws XMLStreamException {
        String str = "<echoJSON><echoString>JSON echo string</echoString></echoJSON>";
        return buildOMElement(str);
    }

    private OMElement getEchoOMElement() throws XMLStreamException {
        String str = "<echo><echoString>XML echo string</echoString></echo>";
        return buildOMElement(str);
    }

    /**
     * Tests the message receiver for its ability to support JSON.
     * The following JSON string is sent to the service and is echoed
     * by the service.
     * <p/>
     * {"echoJSON":{"echoString":"JSON echo string"}}
     *
     * @throws Exception
     */
//    public void testEchoJSON() throws Exception {
//        JSUtils.addInOutOperation(service, echoJSONOp);
//        OMElement payload = getJSONEchoOMElement();
//        Options options = new Options();
//        options.setTo(serviceEPR);
//        options.setProperty(Constants.Configuration.MESSAGE_TYPE, "application/json");
//        ServiceClient sender = new ServiceClient(configurationContext, null);
//        sender.setOptions(options);
//        OMElement result = sender.sendReceive(payload);
//        TestCase.assertEquals("JSON echo string",
//                result.getFirstElement().getText());
//    }

    /**
     * Tests the message receiver for its ability to support E4X.
     * The following XML string is sent to the service and is echoed
     * by the service.
     * <p/>
     * &lt;echo&gt;&lt;echoString&gt;XML echo string&lt;/echoString&gt;&lt;/echo&gt;
     *
     * @throws Exception
     */
    public void testEcho() throws Exception {
        JSUtils.addInOutOperation(service, echoOp);
        OMElement payload = getEchoOMElement();
        Options options = new Options();
        options.setTo(serviceEPR);
        ServiceClient sender = new ServiceClient(configurationContext, null);
        sender.setOptions(options);
        OMElement result = sender.sendReceive(payload);
        TestCase.assertEquals("XML echo string",
                              result.getFirstElement().getText());
    }
}
