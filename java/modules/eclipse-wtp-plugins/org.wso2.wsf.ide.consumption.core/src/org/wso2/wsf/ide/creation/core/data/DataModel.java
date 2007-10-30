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
package org.wso2.wsf.ide.creation.core.data;

import org.wso2.wsf.ide.consumption.core.data.Model;

public class DataModel extends Model{
	
	//Client Side
	private String serviceClass;
	private boolean generateServicesXML;
	private boolean servicesXML;
	private boolean generateAAR;
	private String  pathToServicesXML;
	private String  pathToWebServicesTempDir;
	
	//Server Side 
	private boolean generateServerSideInterface;
    private boolean serverXMLCheck;
	private boolean generateAllCheck;
	private boolean testCaseCheck;
	private String databindingType;
	private String namespaseToPackageMapping;
	private String[] externalLibFileSet;
	private boolean includeExtLibs;


	public boolean isGenerateServicesXML(){
		return generateServicesXML;
	}

	public void setGenerateServicesXML(boolean generateServicesXML){
		this.generateServicesXML = generateServicesXML;
	}

	public String getPathToServicesXML(){
		return pathToServicesXML;
	}

	public void setPathToServicesXML(String pathToServicesXML){
		this.pathToServicesXML = pathToServicesXML;
	}

	public boolean isGenerateAAR() {
		return generateAAR;
	}

	public void setGenerateAAR(boolean generateAAR) {
		this.generateAAR = generateAAR;
	}

	public boolean isServicesXML() {
		return servicesXML;
	}

	public void setServicesXML(boolean servicesXML) {
		this.servicesXML = servicesXML;
	}

	public String getPathToWebServicesTempDir() {
		return pathToWebServicesTempDir;
	}

	public void setPathToWebServicesTempDir(String pathToWebServicesTempDir) {
		this.pathToWebServicesTempDir = pathToWebServicesTempDir;
	}

	public String getWsdlURI() {
		return super.getWsdlURI();
	}

	public void setWsdlURI(String wsdlURI) {
		super.setWsdlURI(wsdlURI);
	}

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

	public boolean isGenerateServerSideInterface() {
		return generateServerSideInterface;
	}

	public void setGenerateServerSideInterface(boolean generateServerSideInterface) {
		this.generateServerSideInterface = generateServerSideInterface;
	}

	public String getPortName() {
		return super.getPortName();
	}

	public void setPortName(String portName) {
		super.setPortName(portName);
	}

	public boolean isServerXMLCheck() {
		return serverXMLCheck;
	}

	public void setServerXMLCheck(boolean serverXMLCheck) {
		this.serverXMLCheck = serverXMLCheck;
	}

	public String getServiceName() {
		return super.getServiceName();
	}

	public void setServiceName(String serviceName) {
		super.setServiceName(serviceName);
	}

	public boolean isTestCaseCheck() {
		return testCaseCheck;
	}

	public void setTestCaseCheck(boolean testCaseCheck) {
		this.testCaseCheck = testCaseCheck;
	}

	public String getPackageText() {
		return super.getPackageText();
	}

	public void setPackageText(String packageText) {
		super.setPackageText(packageText);
	}

	public String getServiceClass() {
		return serviceClass;
	}

	public void setServiceClass(String serviceClass) {
		this.serviceClass = serviceClass;
	}

	public String getNamespaseToPackageMapping() {
		return namespaseToPackageMapping;
	}

	public void setNamespaseToPackageMapping(String namespaseToPackageMapping) {
		this.namespaseToPackageMapping = namespaseToPackageMapping;
	}

	public String[] getExternalLibFileSet() {
		return externalLibFileSet;
	}

	public void setExternalLibFileSet(String[] externalLibFileSet) {
		this.externalLibFileSet = externalLibFileSet;
	}

	public boolean isIncludeExtLibs() {
		return includeExtLibs;
	}

	public void setIncludeExtLibs(boolean includeExtLibs) {
		this.includeExtLibs = includeExtLibs;
	}

}
