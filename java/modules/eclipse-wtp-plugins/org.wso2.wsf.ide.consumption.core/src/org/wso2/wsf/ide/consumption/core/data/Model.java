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
package org.wso2.wsf.ide.consumption.core.data;

public class Model {
	
	private String  webProjectName;
	
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
	
	public String getWebProjectName() {
		return webProjectName;
	}
	public void setWebProjectName(String webProjectName) {
		this.webProjectName = webProjectName;
	}

}
