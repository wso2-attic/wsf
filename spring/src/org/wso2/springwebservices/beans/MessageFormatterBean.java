package org.wso2.springwebservices.beans;

import org.apache.axis2.deployment.DeploymentErrorMsgs;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.i18n.Messages;
import org.apache.axis2.transport.MessageFormatter;
import org.apache.axis2.util.Loader;

// Replaces the message formatter property of the configuration .xml files


public class MessageFormatterBean implements Axis2Bean{
	
	private String contentType;
	private String clazz;
	
	// populate the axis configuration with the set properties
	@Override
	public void populateConfig(AxisConfiguration axisConfig) throws DeploymentException {
		// TODO Auto-generated method stub
		MessageFormatter formatterObject = null;
        Class formatterClass = null;
        String className = getClazz();
            
        try {
        	formatterClass = Loader.loadClass(getClazz());
        	formatterObject = (MessageFormatter) formatterClass.newInstance();
        }catch (ClassNotFoundException e) {
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

        axisConfig.addMessageFormatter(getContentType(), formatterObject);
	}
	
	public String getContentType() {
		return contentType;
	}
	public void setContentType(String contentType) {
		this.contentType = contentType;
	}
	public String getClazz() {
		return clazz;
	}
	public void setClazz(String clazz) {
		this.clazz = clazz;
	}
}
