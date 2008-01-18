package org.wso2.spring.ws.beans;

import org.apache.axis2.deployment.DeploymentErrorMsgs;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.engine.MessageReceiver;
import org.apache.axis2.i18n.Messages;
import org.apache.axis2.util.Loader;

// Replaces the message receiver property of the configuration .xml files

public class MessageReceiverBean implements Axis2Bean {
	
	private String mep;
	private String clazz;
	
	// populate the axis configuration with the set properties
	@Override
	public void populateConfig(AxisConfiguration axisConfig) throws DeploymentException {
		// TODO Auto-generated method stub
		
        MessageReceiver receiver = null;
        Class messageReceiver = null;
        String className = getClazz();
        
        try {
			messageReceiver = Loader.loadClass(getClazz());
			receiver = (MessageReceiver) messageReceiver.newInstance();
		} catch (ClassNotFoundException e) {
            throw new DeploymentException(Messages.getMessage(
                    DeploymentErrorMsgs.ERROR_IN_LOADING_MESSAGE_RECEIVER,
                    "ClassNotFoundException", className), e);
        } catch (IllegalAccessException e) {
            throw new DeploymentException(Messages.getMessage(
                    DeploymentErrorMsgs.ERROR_IN_LOADING_MESSAGE_RECEIVER,
                    "IllegalAccessException", className), e);
        } catch (InstantiationException e) {
            throw new DeploymentException(Messages.getMessage(
                    DeploymentErrorMsgs.ERROR_IN_LOADING_MESSAGE_RECEIVER,
                    "InstantiationException", className), e);
        }
        
        axisConfig.addMessageReceiver(getMep(), receiver);
	}
	

	public String getMep() {
		return mep;
	}
	public void setMep(String mep) {
		this.mep = mep;
	}
	public String getClazz() {
		return clazz;
	}
	public void setClazz(String clazz) {
		this.clazz = clazz;
	}
}
