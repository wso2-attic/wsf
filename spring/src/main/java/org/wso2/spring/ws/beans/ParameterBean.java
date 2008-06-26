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

import org.apache.axis2.AxisFault;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.engine.AxisConfiguration;

/**
 * The Parameter bean replaces the Parameter 
 * property of the configuration .xml files
 */
public class ParameterBean implements Axis2Bean {

	private boolean locked;
	private String name;
	private String value;
	
	
	public boolean getLocked() {
		return locked;
	}
	
	public void setLocked(boolean locked) {
		this.locked = locked;
	}
	
	public boolean isLocked() {
		if (getLocked()) return true;
		else return false;
		
	}	
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getValue() {
		return value;
	}
	
	public void setValue(String value) {
		this.value = value;
	}
	
	private org.apache.axis2.description.Parameter populate() throws DeploymentException {
		ParameterBean springParam = this;
		org.apache.axis2.description.Parameter param = null;
		// Set parameter bean values to the parameter property of the Axis Configuration
		try {
			param = new org.apache.axis2.description.Parameter();

			param.setName(springParam.getName());
			param.setValue(springParam.getValue());
			param.setParameterType(Parameter.TEXT_PARAMETER);
			//Set Locked


			if (springParam.isLocked()) {
				param.setLocked(true);
			} else {
				param.setLocked(false);
			}

		} catch (Exception e) {
			throw new DeploymentException(e);
		}
		return param;
	
	}
	
	// populate the Axis Configuration with parameters
	
	public void populateConfig(AxisConfiguration axisConfig) throws AxisFault {
		// TODO Auto-generated method stub

		try {
			axisConfig.addParameter(populate());
		} catch (Exception e) {
			throw new DeploymentException(e);
		}
		
	}
	
	public void populateService(AxisService axisService) throws AxisFault {
		// TODO Auto-generated method stub

		try {
			axisService.addParameter(populate());
		} catch (Exception e) {
			throw new DeploymentException(e);
		}
		
	}

	
		
}
