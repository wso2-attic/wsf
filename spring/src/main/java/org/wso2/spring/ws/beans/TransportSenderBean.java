package org.wso2.spring.ws.beans;

import java.util.Iterator;
import java.util.Set;

import org.apache.axis2.AxisFault;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.description.TransportOutDescription;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.transport.TransportSender;
import org.apache.axis2.util.Loader;

//Replaces the Transport Sender property of the configuration .xml files

public class TransportSenderBean extends AbstractTransportBean {
	@Override
	public void populateConfig(AxisConfiguration axisConfig) throws AxisFault {
		// TODO Auto-generated method stub
		
		// initialize transport out description
		
		TransportOutDescription tod = new TransportOutDescription(getName());
		
		TransportSender transportSender = null;
		
		// Load the transport sender class
		
		try {
			Class sender = Loader.loadClass(getClazz());
			transportSender = (TransportSender) sender.newInstance();
			tod.setSender(transportSender);
		} catch (ClassNotFoundException e) {
            throw new DeploymentException(e);
        } catch (IllegalAccessException e) {
            throw new DeploymentException(e);
        } catch (InstantiationException e) {
            throw new DeploymentException(e);
        }
        
     // add parameters of the transport sender to the transport out description
        
        Set paramKeys = getParameters().keySet();
		
		Iterator it = paramKeys.iterator();
		
		while (it.hasNext()) {
			String paramName = (String) it.next();
			
			org.apache.axis2.description.Parameter param = new org.apache.axis2.description.Parameter();
			param.setName(paramName);
			param.setValue(getParameters().get(paramName));
			tod.addParameter(param);
			it.remove();
			
		}
		
		// add transport out description to the Axis configuration
		axisConfig.addTransportOut(tod);
        
	}
}
