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

importClass(Packages.org.apache.axiom.om.impl.builder.StAXOMBuilder);
importClass(Packages.org.apache.axiom.om.impl.dom.jaxp.DocumentBuilderFactoryImpl);
importClass(Packages.org.apache.axiom.om.OMAbstractFactory);
importClass(Packages.org.apache.axiom.om.OMElement);
importClass(Packages.org.apache.axiom.om.OMFactory);
importClass(Packages.org.apache.axiom.om.OMNamespace);
importClass(Packages.org.apache.axiom.soap.SOAP11Constants);
importClass(Packages.org.apache.axiom.soap.SOAP12Constants);
importClass(Packages.org.apache.axis2.addressing.AddressingConstants);
importClass(Packages.org.apache.axis2.addressing.EndpointReference);
importClass(Packages.org.apache.axis2.AxisFault);
importClass(Packages.org.apache.axis2.client.Options);
importClass(Packages.org.apache.axis2.client.ServiceClient);
importClass(Packages.org.apache.axis2.client.async.AsyncResult);
importClass(Packages.org.apache.axis2.client.async.Callback);
importClass(Packages.org.apache.axis2.Constants);
importClass(Packages.org.apache.axis2.transport.http.HttpTransportProperties);
importClass(Packages.org.apache.axis2.transport.http.HTTPConstants);
importClass(Packages.javax.xml.stream.XMLStreamReader);
importClass(Packages.javax.xml.stream.XMLInputFactory);
importClass(Packages.javax.xml.parsers.DocumentBuilderFactory);
importClass(java.io.StringReader);
importClass(java.io.ByteArrayInputStream);


function WSRequest() {

    // public variable onreadystatechange
    this.onreadystatechange = null;
    // public variable responseText
    this.responseText = null;
    // public variable responseXML
    this.responseXML = null;
    // public variable readyState
    this.readyState = 0;

    // other private variables
    var async = true;
    var sender = null;
    var optionArr = null;
    var httpMethod = null;
    var url = null;
    var username = null;
    var passwd = null;

    /* private function _reset()
    *  resets private variables
    *  invoked by the privileged method open() when readyState equals 4
    */
    function _reset() {
        async = true;
        sender = null;
        optionArr = null
        httpMethod = null
        url = null;
        username = null;
        passwd = null;
        this.readyState = 0;
    }

    // privileged method open()
    this.open = function open() {
        if (this.readyState > 0 && this.readyState < 4) { // readyState can either be 1, 2 or 4
            throw new Error("INVALID_STATE_EXCEPTION");
        } else if (this.readyState == 4) { // reset private variables if readyState equals 4
            _reset();
        }

        if (arguments.length < 2) { // a minimum of 2 arguments are needed for open() method
            throw new Error("INVALID_SYNTAX_EXCEPTION");
        } else {
            if (typeof(arguments[0]) == "object") {
                optionArr = arguments[0];
            } else if (typeof(arguments[0]) == "string") {
                httpMethod = arguments[0];
            } else {
                throw new Error("INVALID_SYNTAX_EXCEPTION");
            }

            if (typeof(arguments[1]) == "string") {
                url = arguments[1];
            } else {
                throw new Error("INVALID_SYNTAX_EXCEPTION");
            }

            if (typeof(arguments[2]) == "boolean") {
                async = arguments[2];
                if (typeof(arguments[3]) == "string") {
                    username = arguments[3];
                    if (typeof(arguments[4]) == "string" && arguments[5] == undefined) {
                        passwd = arguments[4];
                    } else if (arguments[4] == undefined) {
                        passwd = null;
                    } else {
                        throw new Error("INVALID_SYNTAX_EXCEPTION");
                    }
                } else if (arguments[3] == undefined) {
                    username = null;
                    passwd = null;
                } else {
                    throw new Error("INVALID_SYNTAX_EXCEPTION");
                }
            } else if (typeof(arguments[2]) == "string") {
                username = arguments[2];
                if (typeof(arguments[3]) == "string" && arguments[4] == undefined) {
                    passwd = arguments[3];
                } else if (arguments[3] == undefined) {
                    passwd = null;
                } else {
                    throw new Error("INVALID_SYNTAX_EXCEPTION");
                }
            } else if (arguments[2] != undefined) {
                throw new Error("INVALID_SYNTAX_EXCEPTION");
            }
        }

        if (!_handleOpen()) {
            throw new Error("INVALID_SYNTAX_EXCEPTION");
        }

        this.responseText = null;
        this.responseXML = null;

        this.readyState = 1;
        this.onreadystatechange();
    }

    // private method _handleOpen()
    function _handleOpen() {
        var options = new Options();
        sender = new ServiceClient();
        sender.setOptions(options);

        options.setProperty(HTTPConstants.CHUNKED, Boolean.FALSE);
        
        var targetEPR = new EndpointReference(url);
        options.setTo(targetEPR);

        // handle basic authentication
        if (username != null) { // set username if not null
            var authenticator = new HttpTransportProperties.Authenticator();
            authenticator.setUsername(username);
            if (passwd != null) { // set password if present
                authenticator.setPassword(passwd);
            }
            authenticator.setPreemptiveAuthentication(true);
            options.setProperty(HTTPConstants.AUTHENTICATE,
                    authenticator);
        }


        if (httpMethod != null) { // handle open() method defined as in 2.2.4 in the API
            if (httpMethod.equalsIgnoreCase("get")) {
                options.setProperty(Constants.Configuration.HTTP_METHOD,
                        Constants.Configuration.HTTP_METHOD_GET);
                options.setProperty(Constants.Configuration.ENABLE_REST, Constants.VALUE_TRUE);
            } else if (httpMethod.equalsIgnoreCase("post")) {
                options.setProperty(Constants.Configuration.HTTP_METHOD,
                        Constants.Configuration.HTTP_METHOD_POST);
            } else {
                return false;
            }
        } else if (optionArr != null) { // handle open() method defined as in 2.2.3 in the API
            // set true by default to useSOAP
            var useSOAP = (optionArr["useSOAP"] == undefined) ? true : optionArr["useSOAP"];
            // set HTTP_POST by default for httpMethod
            httpMethod = (optionArr["HTTPMethod"] == undefined) ? "post" : optionArr["HTTPMethod"];

            // avoid using SOAP for HTTP_GET
            if (useSOAP != false && httpMethod.equalsIgnoreCase("get")) {
                return false;
            }

            if (httpMethod.equalsIgnoreCase("get")) {
                options.setProperty(Constants.Configuration.HTTP_METHOD,
                        Constants.Configuration.HTTP_METHOD_GET);
            } else if (httpMethod.equalsIgnoreCase("post")) {
                options.setProperty(Constants.Configuration.HTTP_METHOD,
                        Constants.Configuration.HTTP_METHOD_POST);
            } else {
                return false;
            }

            // handle useSOAP option
            if (useSOAP == 1.1 || useSOAP == "1.1") {
                options.setSoapVersionURI(SOAP11Constants.SOAP_ENVELOPE_NAMESPACE_URI);
            } else if (useSOAP == 1.2 || useSOAP == "1.2" || useSOAP == true) {
                options.setSoapVersionURI(SOAP12Constants.SOAP_ENVELOPE_NAMESPACE_URI);
            } else if (useSOAP == false) {
                options.setProperty(Constants.Configuration.ENABLE_REST, Constants.VALUE_TRUE);
            } else {
                return false;
            }


            var useWSA = optionArr["useWSA"];
            if (useWSA == 1.0 || useWSA == "1.0" || useWSA == true || useWSA == "submission") {
                if (useWSA == "submission") { // set addressing to WSA submission version
                    options.setProperty(AddressingConstants.WS_ADDRESSING_VERSION,
                    AddressingConstants.Submission.WSA_NAMESPACE);
                } else { // set addressing to WSA 1.0 version
                    options.setProperty(AddressingConstants.WS_ADDRESSING_VERSION,
                    AddressingConstants.Final.WSA_NAMESPACE);
                }
                if (typeof(optionArr["action"]) == "string") { // action is necessary if WSA is to be used
                    sender.engageModule(new Packages.javax.xml.namespace.QName(Constants.MODULE_ADDRESSING));
                    options.setAction(optionArr["action"]);
                    if (typeof(optionArr["from"]) == "string") {
                        options.setFrom(new EndpointReference(optionArr["from"]));
                    } else if (optionArr["from"] != undefined) {
                        return false;
                    }

                    if (typeof(optionArr["replyTo"]) == "string") {
                        options.setReplyTo(new EndpointReference(optionArr["replyTo"]));
                    } else if (optionArr["replyTo"] != undefined) {
                        return false;
                    }

                    if (typeof(optionArr["faultTo"]) == "string") {
                        options.setFaultTo(new EndpointReference(optionArr["faultTo"]));
                    } else if (optionArr["faultTo"] != undefined) {
                        return false;
                    }
                } else {
                    return false;
                }
            } else if (useWSA == undefined || useWSA == false) {
                sender.disengageModule(new Packages.javax.xml.namespace.QName(Constants.MODULE_ADDRESSING));
            } else {
                return false;
            }

        } else {
            // both httpMethod and optionArr is null
            return false;
        }
        return true;
    }

    // privileged method send(payload)
    this.send = function send(payload) {
        //send() should be invoked only after invoking open()
        if (this.readyState != 1) throw new Error("INVALID_STATE_EXCEPTION");
        if (typeof(payload) == "string") {
            try {
                var parser = XMLInputFactory.newInstance().createXMLStreamReader(
                        new StringReader(payload));
                var builder = new StAXOMBuilder(parser);
                payload = builder.getDocumentElement();
            } catch(xmlError) {
                throw new Error("INVALID_INPUT_EXCEPTION");
            }
        } else if (typeof(payload) == "object") {
            // set DOOMRequired to true
            DocumentBuilderFactoryImpl.setDOOMRequired(true);
            try {
                payload = payload.getFirstChild();
            } catch(domError) {
                throw new Error("INVALID_INPUT_EXCEPTION");
            }
        } else if (payload == undefined) {
            payload = null;
        }else {
            throw new Error("INVALID_SYNTAX_EXCEPTION");
        }

        try {
            if (async) { // asynchronous call to send()
                var callback = new JavaAdapter(Callback, new createCallback(this));
                sender.sendReceiveNonBlocking(payload, callback);
                this.readyState = 2;
            } else { // synchronous call to send()
                this.readyState = 2;
                var response = sender.sendReceive(payload);
                this.responseXML = new XML(response);
                this.responseText = response.toString();
                this.readyState = 4;
            }
            this.onreadystatechange();
        } catch(e) {
            throw new Error(e);
        }
    }


    function createCallback(wsrequest) {
        this.wsrequest = wsrequest;
        this.onComplete = onComplete;
        this.onError = onError;
    }

    function onComplete(result) {
        // get content in SOAP body as a string
        var response = result.getResponseEnvelope().getBody().getFirstElement();
        this.wsrequest.responseText = response.toString();
        this.wsrequest.responseXML = new XML(response);
        this.wsrequest.readyState = 4;
        this.wsrequest.onreadystatechange();
    }

    function onError(e) {
        e.printStackTrace();
    }
}






