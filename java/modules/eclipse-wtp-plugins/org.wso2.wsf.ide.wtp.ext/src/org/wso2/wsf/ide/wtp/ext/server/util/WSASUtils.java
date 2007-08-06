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

import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.InetAddress;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.UnknownHostException;

import org.wso2.wsf.ide.wtp.ext.server.constant.WSASConfigurationConstant;

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
							WSASConfigurationConstant.WSO2WSAS_VERSION_SUFFIX;
		return wsasHTTPAddress;
	}
	
}
