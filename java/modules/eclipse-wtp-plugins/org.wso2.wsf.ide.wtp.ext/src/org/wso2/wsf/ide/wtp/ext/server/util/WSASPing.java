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
import java.net.URL;

import org.wso2.wsf.ide.wtp.ext.server.bean.WSASConfigurationBean;

public class WSASPing {
	
	/**
	 * Ping the WSAS service that represent the given URL. 
	 * @param serviceURL
	 * @return result of the ping
	 */
	public boolean pingWSASService(String serviceURL){
		try {
			URL url = new URL(serviceURL);
			HttpURLConnection httpCon;
			httpCon = (HttpURLConnection) url.openConnection();
			httpCon.setDoOutput(true);
			httpCon.setDoInput(true);
			httpCon.setUseCaches(false);
			httpCon.setRequestMethod("GET");
			HttpURLConnection.setFollowRedirects(true);
			httpCon.connect();
			httpCon.disconnect();
			WSASConfigurationBean.setWsasStartStatus(true);
		} catch (IOException e) {
			WSASConfigurationBean.setWsasStartStatus(false);
			return false;
		}
		return true;
	}

}
