/*
 * Copyright 2005-2008 WSO2, Inc. (http://wso2.com)
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

package org.wso2.spring.ws.beans;

import java.util.Iterator;
import java.util.Set;

import org.apache.axis2.AxisFault;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.description.TransportOutDescription;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.transport.TransportSender;
import org.apache.axis2.util.Loader;

/**
 * The Transport Sender Bean replaces the Transport 
 * Sender property of the configuration .xml files 
 */

public class TransportSenderBean extends AbstractTransportBean {
	
	public void populateConfig(AxisConfiguration axisConfig) throws AxisFault {
		// TODO Auto-generated method stub
		
		// initialize transport out description
		
		TransportOutDescription tod = new TransportOutDescription(getName());
		
		TransportSender transportSender = null;
		
		// Load the transport sender class
		
		try {
			Class sender = Loader.loadClass(getClazz());
			transportSender = (TransportSender) sender.newInstance();
			tod.setSender(transportSender);
		} catch (ClassNotFoundException e) {
            throw new DeploymentException(e);
        } catch (IllegalAccessException e) {
            throw new DeploymentException(e);
        } catch (InstantiationException e) {
            throw new DeploymentException(e);
        }
        
     // add parameters of the transport sender to the transport out description
        
        Set paramKeys = getParameters().keySet();
		
		Iterator it = paramKeys.iterator();
		
		while (it.hasNext()) {
			String paramName = (String) it.next();
			
			org.apache.axis2.description.Parameter param = new org.apache.axis2.description.Parameter();
			param.setName(paramName);
			param.setValue(getParameters().get(paramName));
			tod.addParameter(param);
			it.remove();
			
		}
		
		// add transport out description to the Axis configuration
		axisConfig.addTransportOut(tod);
        
	}
}
