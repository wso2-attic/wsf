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

import org.apache.axis2.description.AxisService;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.description.AxisOperation;
import org.apache.axis2.description.InOutAxisOperation;
import org.apache.axis2.AxisFault;
import org.apache.axis2.Constants;
import org.apache.axis2.wsdl.WSDLConstants;
import org.apache.axis2.engine.MessageReceiver;

import javax.xml.namespace.QName;

public class Utils {
      public static AxisService createSimpleJSService(
            QName serviceName, String jsName, QName opName) throws AxisFault {

        MessageReceiver jsReceiver = new JavaScriptReceiver();
        AxisService service = new AxisService(serviceName.getLocalPart());

        service.setClassLoader(Thread.currentThread().getContextClassLoader());


        service.addParameter(new Parameter("ServiceJS", jsName));

        AxisOperation axisOp = new InOutAxisOperation(opName);

        axisOp.setMessageReceiver(jsReceiver);
        axisOp.setStyle(WSDLConstants.STYLE_DOC);
        service.addOperation(axisOp);
        service.mapActionToOperation(Constants.AXIS2_NAMESPACE_URI + "/" + opName.getLocalPart(), axisOp);

        return service;

    }
}
