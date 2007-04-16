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
package org.wso2.wsf.wtp.consumption.core.data;

public class DataModel extends Model{
	
	//Consumption DataModel Parameters
	private String  webProjectName;
	private String 	serviceClass;
	private String 	databindingType;
	private String 	namespaseToPackageMapping;
	private boolean	Sync;
	private boolean	ASync;
	private boolean generateAllCheck;
	private boolean testCaseCheck;

	
	public String getDatabindingType() {
		return databindingType;
	}
	public void setDatabindingType(String databindingType) {
		this.databindingType = databindingType;
	}
	public boolean isGenerateAllCheck() {
		return generateAllCheck;
	}
	public void setGenerateAllCheck(boolean generateAllCheck) {
		this.generateAllCheck = generateAllCheck;
	}
	public String getNamespaseToPackageMapping() {
		return namespaseToPackageMapping;
	}
	public void setNamespaseToPackageMapping(String namespaseToPackageMapping) {
		this.namespaseToPackageMapping = namespaseToPackageMapping;
	}

	public String getPackageText() {
		return super.getPackageText();
	}

	public void setPackageText(String packageText) {
		super.setPackageText(packageText);
	}
	
	public String getPortName() {
		return super.getPortName();
	}

	public void setPortName(String portName) {
		super.setPortName(portName);
	}
	
	public String getServiceClass() {
		return serviceClass;
	}
	public void setServiceClass(String serviceClass) {
		this.serviceClass = serviceClass;
	}

	public String getServiceName() {
		return super.getServiceName();
	}

	public void setServiceName(String serviceName) {
		super.setServiceName(serviceName);
	}
	
	public String getWsdlURI() {
		return super.getWsdlURI();
	}

	public void setWsdlURI(String wsdlURI) {
		super.setWsdlURI(wsdlURI);
	}
	
	public String getWebProjectName() {
		return webProjectName;
	}
	public void setWebProjectName(String webProjectName) {
		this.webProjectName = webProjectName;
	}
	public boolean isASync() {
		return ASync;
	}
	public void setASync(boolean sync) {
		ASync = sync;
	}
	public boolean isSync() {
		return Sync;
	}
	public void setSync(boolean sync) {
		Sync = sync;
	}
	public boolean isTestCaseCheck() {
		return testCaseCheck;
	}
	public void setTestCaseCheck(boolean testCaseCheck) {
		this.testCaseCheck = testCaseCheck;
	}

}