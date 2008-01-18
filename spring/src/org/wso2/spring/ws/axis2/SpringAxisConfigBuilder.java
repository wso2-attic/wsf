package org.wso2.spring.ws.axis2;

import java.util.ArrayList;
import java.util.Iterator;

import org.apache.axis2.AxisFault;
import org.apache.axis2.engine.AxisConfiguration;
import org.wso2.spring.ws.SpringAxisConfiguration;
import org.wso2.spring.ws.beans.Axis2Bean;

public class SpringAxisConfigBuilder {
// populate axis configuration with bean properties
	
	private SpringAxisConfiguration springConfig = null;
	
	public SpringAxisConfigBuilder(SpringAxisConfiguration springConfig) {
		// TODO Auto-generated constructor stub
		this.springConfig = springConfig;
	}
	
	
	public void populateConfig(AxisConfiguration axisConfig) throws AxisFault {
		// TODO Auto-generated method stub
		
		// populate configuration with parameters, receivers, formatters, etc
		
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
	
	
	// populate axis configuration with values from various property lists
	
	private void populateConfigWithLists(ArrayList list, AxisConfiguration axisConfig) throws AxisFault{
		Iterator it = list.iterator();
		
		while (it.hasNext()) {
			Axis2Bean bean = (Axis2Bean) it.next();
			bean.populateConfig(axisConfig);
		}
	}
	
	
}
