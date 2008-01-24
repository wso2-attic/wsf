package org.wso2.spring.ws.beans;

import org.apache.axis2.AxisFault;
import org.apache.axis2.deployment.DeploymentErrorMsgs;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.description.AxisDescription;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.i18n.Messages;

// Replaces the Parameter property of the configuration .xml files

public class ParameterBean implements Axis2Bean {

//	private Map parameters = new HashMap();
//	
//	public Map getParameters() {
//		return parameters;
//	}
//
//	public void setParameters(Map parameters) throws AxisFault {
//		this.parameters = parameters;
//	}
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
	@Override
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
