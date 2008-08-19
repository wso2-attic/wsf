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

package org.wso2.spring.ws.beans;

import java.util.HashMap;
import java.util.Map;

import org.apache.axis2.AxisFault;

/**
 * The AbstractTransportBean implements parameters common to both
 * the transport receiver and the transport sender
 */

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
