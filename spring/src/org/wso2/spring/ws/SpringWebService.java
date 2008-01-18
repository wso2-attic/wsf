package org.wso2.spring.ws;

import java.util.ArrayList;
import java.util.Map;

import org.wso2.spring.ws.beans.MessageReceiverBean;


// Spring Web Service is a bean to hold information in place of the services.xml of an Axis 2 service


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
	
	
}
