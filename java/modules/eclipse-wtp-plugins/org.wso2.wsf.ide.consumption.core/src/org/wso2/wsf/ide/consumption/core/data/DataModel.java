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

public class DataModel extends Model{
	
	//Consumption DataModel Parameters
	
	private String 	serviceClass;
	private String 	databindingType;
	private String 	namespaseToPackageMapping;
	//Default setting is to generate both sync and async
	private boolean	Sync = false; 
	private boolean	ASync = false;
	private boolean generateAllCheck = false;
	private boolean testCaseCheck = false;
	private boolean unpackClasses = false;

	
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
	
	public boolean isASync() {
		return ASync;
	}
	public void setASync(boolean async) {
		ASync = async;
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
	public boolean isUnpackClasses() {
		return unpackClasses;
	}
	public void setUnpackClasses(boolean unpackClasses) {
		this.unpackClasses = unpackClasses;
	}

}
