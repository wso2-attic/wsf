package org.wso2.springwebservices.beans;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import org.apache.axis2.AxisFault;
import org.apache.axis2.engine.AxisConfiguration;

// implements common parameters both to the transport receiver and the transport sender

public abstract class AbstractTransportBean implements Axis2Bean {
	
	private Map parameters = new HashMap();
	private String name = null;
	private String clazz = null;

	public Map getParameters() {
		return parameters;
	}
	
	public void setParameters(Map parameters) throws AxisFault {
		this.parameters = parameters;
	}
	
		
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getClazz() {
		return clazz;
	}
	public void setClazz(String clazz) {
		this.clazz = clazz;
	}
}
