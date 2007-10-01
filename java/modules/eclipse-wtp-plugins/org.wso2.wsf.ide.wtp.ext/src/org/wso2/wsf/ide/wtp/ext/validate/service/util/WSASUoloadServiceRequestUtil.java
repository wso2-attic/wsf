/*
 * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
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
package org.wso2.wsf.ide.wtp.ext.validate.service.util;

import java.io.File;
import java.net.URL;
import java.util.Iterator;

import javax.activation.DataHandler;
import javax.activation.FileDataSource;
import javax.xml.namespace.QName;
import javax.xml.soap.AttachmentPart;
import javax.xml.soap.MessageFactory;
import javax.xml.soap.SOAPBody;
import javax.xml.soap.SOAPConnection;
import javax.xml.soap.SOAPConnectionFactory;
import javax.xml.soap.SOAPElement;
import javax.xml.soap.SOAPEnvelope;
import javax.xml.soap.SOAPException;
import javax.xml.soap.SOAPFactory;
import javax.xml.soap.SOAPMessage;
import javax.xml.soap.SOAPPart;

import org.w3c.dom.DOMException;
import org.w3c.dom.Node;
import org.wso2.wsf.ide.wtp.ext.server.command.WTPInternalBrowserCommand;
import org.wso2.wsf.ide.wtp.ext.server.constant.WSASMessageConstant;

public class WSASUoloadServiceRequestUtil {
	
	private static WSASUoloadServiceRequestUtil instance;
	
	private DataHandler dh;
	private SOAPConnection connection;
	private SOAPFactory soapFactory;
	private boolean isXml;
	private boolean isArchive;
	private boolean isService;
	private boolean isModule;
	private boolean isWSDL;
	private boolean alredyInit;
	
	//Private constructor
	private WSASUoloadServiceRequestUtil(){
	}
	
	public static WSASUoloadServiceRequestUtil getInstance(){
		if (instance == null) {
			instance = new WSASUoloadServiceRequestUtil();
		}
		return instance;
	}
	
	private void init(){
		try {
			connection = SOAPConnectionFactory.newInstance().createConnection();
			soapFactory = SOAPFactory.newInstance();
			alredyInit = true;
		} catch (UnsupportedOperationException e) {
			e.printStackTrace();
		} catch (SOAPException e) {
			e.printStackTrace();
		}
	}
	
	public String requestValidate(File resourceFile, String fileType){
		if(!alredyInit)init();
		String returnUUID = null;
		if (isService) {
			if (isXml) {
				returnUUID = sendUploadFileToWSAS(resourceFile,fileType,
						WSASMessageConstant.validateServiceEndpoint,
						WSASMessageConstant.serviceXMLEndOperation);
			}else{
				returnUUID = sendUploadFileToWSAS(resourceFile,fileType,
						WSASMessageConstant.validateServiceEndpoint, 
						WSASMessageConstant.archiveEndOperation);
			}
		}else if (isModule){
			if (isXml) {
				returnUUID = sendUploadFileToWSAS(resourceFile,fileType,
						WSASMessageConstant.validateModuleEndpoint,
						WSASMessageConstant.moduleXMLEndOperation);
			}else{
				returnUUID = sendUploadFileToWSAS(resourceFile,fileType,
						WSASMessageConstant.validateModuleEndpoint, 
						WSASMessageConstant.archiveEndOperation);
			}
		}else if (isWSDL){
			returnUUID = sendUploadFileToWSAS(resourceFile,fileType,
					WSASMessageConstant.wsdlConversionEndpoint, 
					WSASMessageConstant.wsdlConversionEndOperation);
		}
		return returnUUID;
	}
	
	public void popupInternalBrowser(URL url){
		WTPInternalBrowserCommand
			.popUpInrernalBrouwser(url.toString());
	}
	
	private String sendUploadFileToWSAS(File resourceFile, String fileType, 
			String validateServiceEndpoint, String endOperation){		
			try{
				SOAPMessage message = MessageFactory.newInstance().createMessage();

				QName uploadQName = new QName("http://org.apache.axis2/xsd","upload","ns");
				SOAPElement uploadElement = soapFactory.createElement(uploadQName);

				//set the attachement
				dh = new DataHandler(new FileDataSource(resourceFile));
				AttachmentPart attachment = message.createAttachmentPart(dh);
				attachment.setContentId("myAttachment");
				attachment.setContentType("txt/xml");

				QName payloadQName = new QName("payload");
				SOAPElement payloadElement = soapFactory.createElement(payloadQName);

				QName attach = new QName("attachment");
				SOAPElement attachmentElement = soapFactory.createElement(attach);
				attachmentElement.setAttribute("href", "cid:" + attachment.getContentId());

				//Add type element
				QName attachmentId = new QName("type");
				SOAPElement attachmentIdEle = soapFactory.createElement(attachmentId);
				attachmentIdEle.addTextNode(fileType);

				payloadElement.addChildElement(attachmentElement);
				payloadElement.addChildElement(attachmentIdEle);

				uploadElement.addChildElement(payloadElement);

				message.getSOAPBody().addChildElement(uploadElement);
				message.addAttachmentPart(attachment);

				SOAPMessage result = connection.call(message,
						WSASMessageConstant.generalServiceEndPoint);

				SOAPPart part = result.getSOAPPart();
				SOAPEnvelope envelope = part.getEnvelope();
				SOAPBody body = envelope.getBody();

				Node uploadResponse = body.getFirstChild();
				Node returnNode = uploadResponse.getFirstChild();
				String uuid = returnNode.getFirstChild().toString();

				if(!body.hasFault())  {
					Iterator iterator = result.getAttachments();
					if(iterator.hasNext()) {
						dh = ((AttachmentPart)iterator.next()).getDataHandler();
						String fname = dh.getName();
						//if (null != fname) return new File(fname);
					}
				}
				if (isArchive) {
					
				}
				String returnId = sendUUID(uuid,validateServiceEndpoint,endOperation);
				return returnId;
			} catch (UnsupportedOperationException e) {
				e.printStackTrace();
			} catch (Exception e) {
				e.printStackTrace();
			}
		return null;
	}
	
	
	
	   private String sendUUID(String uuid, String endPoint, String endOperation){
			try {

				SOAPMessage message = MessageFactory.newInstance().createMessage();
				
				QName uploadQName = new QName("http://org.wso2.wsf/tools",endOperation,"ns");
				SOAPElement uploadElement = soapFactory.createElement(uploadQName);
		
				//Add type element
				QName qnameEle = new QName("fileId");
				SOAPElement attachmentIdEle = soapFactory.createElement(qnameEle);
				attachmentIdEle.addTextNode(uuid);
				uploadElement.addChildElement(attachmentIdEle);
				
				message.getSOAPBody().addChildElement(uploadElement);
				
				SOAPMessage result = connection.call(message,endPoint);
				
				SOAPPart part = result.getSOAPPart();
				SOAPEnvelope envelope = part.getEnvelope();
				SOAPBody body = envelope.getBody();
				

				if(!body.hasFault())  {
					Iterator iterator = result.getAttachments();
					if(iterator.hasNext()) {
						dh = ((AttachmentPart)iterator.next()).getDataHandler();
						String fname = dh.getName();
					}
				}
				
	   			Node uploadResponse = body.getFirstChild();
				Node returnNode = uploadResponse.getFirstChild();
				String uuid1 = returnNode.getFirstChild().toString();

				return uuid1;
				
			} catch (UnsupportedOperationException e) {
				e.printStackTrace();
			} catch (DOMException e) {
				e.printStackTrace();
			} catch (SOAPException e) {
				e.printStackTrace();
			}
	    	return null;
	    }

	public void setXml(boolean isXml) {
		this.isXml = isXml;
	}

	public void setArchive(boolean isArchive) {
		this.isArchive = isArchive;
	}

	public void setService(boolean isService) {
		this.isService = isService;
	}

	public void setModule(boolean isModule) {
		this.isModule = isModule;
	}
	
	public void reset() {
		this.isModule = false;
		this.isService = false;
		this.isXml = false;
		this.isArchive = false;
		this.isWSDL = false ;
	}

	public void setWSDL(boolean isWSDL) {
		this.isWSDL = isWSDL;
	}

}
