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
package org.wso2.wsf.ide.wtp.ext.server.util;

import java.io.File;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.InetAddress;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.UnknownHostException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.wso2.wsf.ide.core.context.PersistentWSASEmitterContext;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.wtp.ext.server.constant.WSASConfigurationConstant;
import org.xml.sax.SAXException;

public class WSASUtils {
	
	public static String getHostName() {
		String hostName = null;
		try {
			InetAddress addr = InetAddress.getLocalHost();
			hostName = addr.getHostName();
		} catch (UnknownHostException e) {
			e.printStackTrace();
		}
		return hostName;
	}
	
	public static String getIpAddress() {
		String hostAddress = null;
		try {
			InetAddress addr = InetAddress.getLocalHost();
			hostAddress = addr.getHostAddress();
		} catch (UnknownHostException e) {
			e.printStackTrace();
		}
		return hostAddress;
	}
	
	
	public static String getWSASHTTPSAddtess() {
		String  wsasHTTPSAddress = null;
		wsasHTTPSAddress = WSASConfigurationConstant.HTTPS_PREFIX + 
							getIpAddress()+":"+
							WSASConfigurationConstant.WSO2WSAS_HTTPS_PORT;
		return wsasHTTPSAddress;
	}
	
	public static String getWSASHTTPAddtess() {
		String  wsasHTTPAddress = null;
		wsasHTTPAddress = WSASConfigurationConstant.HTTP_PREFIX + 
							getIpAddress()+":"+
							WSASConfigurationConstant.WSO2WSAS_HTTP_PORT;
		return wsasHTTPAddress;
	}
	
	public static String getWSASVersionServiceHTTPAddress() {
		String  wsasHTTPAddress = null;
		wsasHTTPAddress = WSASConfigurationConstant.HTTP_PREFIX + 
							getIpAddress()+":"+
							getTransportHttpPort()+
							WSASConfigurationConstant.WSO2WSAS_VERSION_SUFFIX;
		return wsasHTTPAddress;
	}
	
	public static void setTrustStoreDetails(){
		System.setProperty("javax.net.ssl.trustStore", PersistentWSASEmitterContext.getInstance().getWSASRuntimeLocation()+File.separator+"conf"+File.separator+"wso2wsas.jks");
        System.setProperty("javax.net.ssl.trustStorePassword", "wso2carbon");
        System.setProperty("javax.net.ssl.trustStoreType","wso2wsas");
	}
	
	
	static String getTransportHttpPort(){
		String port="9762";
		String confFolder=FileUtils.addAnotherNodeToPath(PersistentWSASEmitterContext.getInstance().getWSASRuntimeLocation(),WSASConfigurationConstant.CONF_FOLDER);
		String transportXml = FileUtils.addAnotherNodeToPath(confFolder,WSASConfigurationConstant.WSO2WSAS_TRANSPORT_XML);
		Document xmlDocument = getXmlDocument(transportXml);
		if (xmlDocument!=null){
			if (xmlDocument.getDocumentElement().getNodeName().equalsIgnoreCase("transports")){
				NodeList childNodes = xmlDocument.getDocumentElement().getChildNodes();
				for (int i = 0; i < childNodes.getLength(); i++) {
					Node item = childNodes.item(i);
					if (item.getNodeName().equalsIgnoreCase("transport")){
						Node namedItem = item.getAttributes().getNamedItem("name");
						String nodeValue = namedItem.getNodeValue();
						if (nodeValue.equalsIgnoreCase("http")){
							NodeList childNodes2 = item.getChildNodes();
							for (int j = 0; j < childNodes2.getLength(); j++) {
								Node item2 = childNodes2.item(j);
								if (item2.getNodeName().equalsIgnoreCase("parameter")){
									Node namedItem2 = item2.getAttributes().getNamedItem("name");
									String nodeValue2 = namedItem2.getNodeValue();
									if (nodeValue2.equalsIgnoreCase("port")){
										return item2.getTextContent();
									}
								}
								
							}
						}
					}
					
				}
			}
		}
		return port;
	}
	
	private static Document getXmlDocument(String filename){
		DocumentBuilderFactory docBuilderFactory = DocumentBuilderFactory.newInstance();
		DocumentBuilder docBuilder;
		try {
			docBuilder = docBuilderFactory.newDocumentBuilder();
			Document doc = docBuilder.parse (new File(filename));
			return doc;
		} catch (ParserConfigurationException e) {
			return null;
		} catch (SAXException e) {
			return null;
		} catch (IOException e) {
			return null;
		}
	}
}
