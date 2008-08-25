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

package org.wso2.spring.ws;

import java.util.ArrayList;
import java.util.Map;

import org.wso2.spring.ws.beans.MessageReceiverBean;
import org.wso2.spring.ws.beans.OperationBean;


/**
 * Spring Web Service is a bean to hold information
 *  in place of the services.xml of an Axis 2 service
 *
 */
public class SpringWebService {
	
	// variables to represent options available to a Axis 2 Web Service
	private Object serviceBean;
	private String serviceName;
	private Map parameters;
	private ArrayList<MessageReceiverBean> messageReceivers;
	private String serviceDescription;
	private String targetNameSpace;
	private String sessionScope;
	private ArrayList<String> modules;
	private ArrayList<OperationBean> operations;
    private ArrayList<OperationBean> excludeOperations;
    private ArrayList<String>policies;
    private ArrayList<String>policyFiles;


    public ArrayList<MessageReceiverBean> getMessageReceivers() {
		return messageReceivers;
	}
	public void setMessageReceivers(ArrayList<MessageReceiverBean> messageReceivers) {
		this.messageReceivers = messageReceivers;
	}
	public String getServiceDescription() {
		return serviceDescription;
	}
	public void setServiceDescription(String serviceDescription) {
		this.serviceDescription = serviceDescription;
	}
	public String getTargetNameSpace() {
		return targetNameSpace;
	}
	public void setTargetNameSpace(String targetNameSpace) {
		this.targetNameSpace = targetNameSpace;
	}
	public String getSessionScope() {
		return sessionScope;
	}
	public void setSessionScope(String sessionScope) {
		this.sessionScope = sessionScope;
	}
	public ArrayList<String> getModules() {
		return modules;
	}
	public void setModules(ArrayList<String> modules) {
		this.modules = modules;
	}
	public Map getParameters() {
		return parameters;
	}
	public void setParameters(Map parameters) {
		this.parameters = parameters;
	}
	public String getServiceName() {
		return serviceName;
	}
	public void setServiceName(String serviceName) {
		this.serviceName = serviceName;
	}
	public Object getServiceBean() {
		return serviceBean;
	}
	public void setServiceBean(Object serviceBean) {
		this.serviceBean = serviceBean;
	}
	public ArrayList<OperationBean> getOperations() {
		return operations;
	}
	public void setOperations(ArrayList<OperationBean> operations) {
		this.operations = operations;
	}
	public ArrayList<OperationBean> getExcludeOperations() {
		return excludeOperations;
	}
	public void setExcludeOperations(ArrayList<OperationBean> excludeOperations) {
		this.excludeOperations = excludeOperations;
	}
	public ArrayList<String> getPolicies() {
		return policies;
	}
	public void setPolicies(ArrayList<String> policies) {
		this.policies = policies;
	}
	public ArrayList<String> getPolicyFiles() {
		return policyFiles;
	}
	public void setPolicyFiles(ArrayList<String> policyFiles) {
		this.policyFiles = policyFiles;
	}
	
}
