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

import org.apache.axis2.addressing.EndpointReference;

import javax.xml.namespace.QName;

public interface ReceiverTestConstants {
        public static int TESTING_PORT = 5555;

    public static final EndpointReference targetEPR = new EndpointReference(
            "http://127.0.0.1:" + (TESTING_PORT)
                    + "/axis2/services/EchoJSService");

    public static final QName serviceName = new QName("EchoJSService");

    public static final QName operationName = new QName("echo");
}
