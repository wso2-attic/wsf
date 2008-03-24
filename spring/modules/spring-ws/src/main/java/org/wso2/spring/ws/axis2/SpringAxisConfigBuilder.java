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

package org.wso2.spring.ws.axis2;

import java.util.ArrayList;
import java.util.Iterator;

import org.apache.axis2.AxisFault;
import org.apache.axis2.engine.AxisConfiguration;
import org.wso2.spring.ws.SpringAxisConfiguration;
import org.wso2.spring.ws.beans.Axis2Bean;

/**
 * Ths SpringAxisConfigBuilder populates 
 * the axis configuration with bean properties
 */

public class SpringAxisConfigBuilder {
	
	private SpringAxisConfiguration springConfig = null;
	
	
	public SpringAxisConfigBuilder(SpringAxisConfiguration springConfig) {
		this.springConfig = springConfig;
	}
	
	
	/**
	 * Populates configuration with parameters, receivers, formatters, etc
	 * @param axisConfig
	 * @throws AxisFault
	 */
	public void populateConfig(AxisConfiguration axisConfig) throws AxisFault {
		
		populateConfigWithLists(springConfig.getParameters(), axisConfig);
		populateConfigWithLists(springConfig.getMessageReceivers(), axisConfig);
		populateConfigWithLists(springConfig.getMessageFormatters(), axisConfig);
		populateConfigWithLists(springConfig.getMessageBuilders(), axisConfig);
		populateConfigWithLists(springConfig.getTransportReceivers(), axisConfig);
		populateConfigWithLists(springConfig.getTransportSenders(), axisConfig);
		populateConfigWithLists(springConfig.getPhaseOrders(), axisConfig);
		
		// processing modules
		if (springConfig.getModules() != null) {
			Iterator moduleIt = springConfig.getModules().iterator();
			while (moduleIt.hasNext()) {
				String refName = (String) moduleIt.next();
				axisConfig.addGlobalModuleRef(refName);
			}
		}
	}
	
	
	/**
	 * Populates axis configuration with values from various property lists
	 * @param list
	 * @param axisConfig
	 * @throws AxisFault
	 */
	private void populateConfigWithLists(ArrayList list, AxisConfiguration axisConfig) throws AxisFault{
		Iterator it = list.iterator();
		
		while (it.hasNext()) {
			Axis2Bean bean = (Axis2Bean) it.next();
			bean.populateConfig(axisConfig);
		}
	}
	
	
}
