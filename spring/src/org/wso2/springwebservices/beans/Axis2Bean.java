package org.wso2.springwebservices.beans;

import org.apache.axis2.AxisFault;
import org.apache.axis2.engine.AxisConfiguration;

public interface Axis2Bean {
	
	public void populateConfig(AxisConfiguration axisConfig) throws AxisFault;
}
