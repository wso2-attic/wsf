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

import org.wso2.spring.ws.beans.ParameterBean;
import org.wso2.spring.ws.beans.PhaseOrderBean;



/**
 * Spring Axis configuration replaces the axis2.xml making it 
 * possible to represent the configuration information 
 * with a Spring bean 
 *
 */
public class SpringAxisConfiguration{
	
	// Axis2 options available to be configured
	
	private ArrayList<ParameterBean> parameters;
	
	private ArrayList deployers;
	
	private ArrayList messageReceivers;
	
	private ArrayList messageFormatters;
	
	private ArrayList messageBuilders;
	
	private ArrayList transportReceivers;
	
	private ArrayList transportSenders;
	
	private ArrayList modules;
	
	private ArrayList<PhaseOrderBean> phaseOrders;
	
	
	public ArrayList getDeployers() {
		return deployers;
	}

	public void setDeployers(ArrayList deployers) {
		this.deployers = deployers;
	}

	public ArrayList getMessageReceivers() {
		return messageReceivers;
	}

	public void setMessageReceivers(ArrayList messageReceivers) {
		this.messageReceivers = messageReceivers;
	}

	public ArrayList getMessageFormatters() {
		return messageFormatters;
	}

	public void setMessageFormatters(ArrayList messageFormatters) {
		this.messageFormatters = messageFormatters;
	}

	public ArrayList getMessageBuilders() {
		return messageBuilders;
	}

	public void setMessageBuilders(ArrayList messageBuilders) {
		this.messageBuilders = messageBuilders;
	}

	public ArrayList getTransportSenders() {
		return transportSenders;
	}

	public void setTransportSenders(ArrayList transportSenders) {
		this.transportSenders = transportSenders;
	}

	public ArrayList getModules() {
		return modules;
	}

	public void setModules(ArrayList modules) {
		this.modules = modules;
	}

	public ArrayList getPhaseOrders() {
		return phaseOrders;
	}

	public void setPhaseOrders(ArrayList<PhaseOrderBean> phaseOrders) {
		this.phaseOrders = phaseOrders;
	}

	public ArrayList getTransportReceivers() {
		return transportReceivers;
	}

	public void setTransportReceivers(ArrayList transportReceivers) {
		this.transportReceivers = transportReceivers;
	}


	public ArrayList<ParameterBean> getParameters() {
		return parameters;
	}


	public void setParameters(ArrayList<ParameterBean> parameters) {
		this.parameters = parameters;
	}

	
	
}
