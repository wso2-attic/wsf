package org.wso2.springwebservices.beans;

import java.util.Iterator;
import java.util.Set;

import org.apache.axis2.AxisFault;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.description.TransportInDescription;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.transport.TransportListener;
import org.apache.axis2.util.Loader;

//Replaces the Transport Receiver property of the configuration .xml files

public class TransportReceiverBean extends AbstractTransportBean {
	
	@Override
	public void populateConfig(AxisConfiguration axisConfig) throws AxisFault {
		// TODO Auto-generated method stub
		
		// initialize transport in description
		
		TransportInDescription tid = new TransportInDescription(getName());
		
		TransportListener receiver = null;
		
		// Load the transport receiver class
		try {
			Class receiverClass = Loader.loadClass(getClazz());

			receiver = (TransportListener) receiverClass.newInstance();
			tid.setReceiver(receiver);
		} catch (ClassNotFoundException e) {
            throw new DeploymentException(e);
        } catch (IllegalAccessException e) {
            throw new DeploymentException(e);
        } catch (InstantiationException e) {
            throw new DeploymentException(e);
        }
        
        // add parameters of the transport receiver to the transport in description
        
		Set paramKeys = getParameters().keySet();
		
		Iterator it = paramKeys.iterator();
		
		while (it.hasNext()) {
			String paramName = (String) it.next();
			
			org.apache.axis2.description.Parameter param = new org.apache.axis2.description.Parameter();
			param.setName(paramName);
			param.setValue(getParameters().get(paramName));
			tid.addParameter(param);
			it.remove();
		}
		
		// add transport in description to the Axis configuration
		axisConfig.addTransportIn(tid);
	}
}
