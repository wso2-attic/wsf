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

import org.apache.axis2.deployment.DeploymentErrorMsgs;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.i18n.Messages;
import org.apache.axis2.transport.MessageFormatter;
import org.apache.axis2.util.Loader;

/**
 * The Message Formatter Bean replaces the message 
 * formatter property of the configuration .xml files
 */
public class MessageFormatterBean implements Axis2Bean{
	
	private String contentType;
	private String clazz;
	
	// populate the axis configuration with the set properties
	
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
