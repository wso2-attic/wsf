/*******************************************************************************
 * Copyright (c) 2007 WSO2 Inc. and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 * WSO2 Inc. - initial API and implementation
 * yyyymmdd bug      Email and other contact information
 * -------- -------- -----------------------------------------------------------
 * 20070213   168762 sandakith@wso2.com - Lahiru Sandakith, Initial code to introduse the Axis2 
 * 										  runtime to the framework for 168762
 *******************************************************************************/
package org.wso2.wsf.wtp.ws.creation.core.data;

public class Model {
	
	private boolean serverStatus;
	private String  wsdlURI;
	private String portName;
	private String serviceName;
	private String packageText;
	
	public String getPackageText() {
		return packageText;
	}
	public void setPackageText(String packageText) {
		this.packageText = packageText;
	}
	public String getPortName() {
		return portName;
	}
	public void setPortName(String portName) {
		this.portName = portName;
	}
	public String getServiceName() {
		return serviceName;
	}
	public void setServiceName(String serviceName) {
		this.serviceName = serviceName;
	}
	public String getWsdlURI() {
		return wsdlURI;
	}
	public void setWsdlURI(String wsdlURI) {
		this.wsdlURI = wsdlURI;
	}
	public boolean getServerStatus() {
		return serverStatus;
	}
	public void setServerStatus(boolean b) {
		this.serverStatus = b;
	}

}
