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
package org.wso2.wsf.ide.wtp.ext.server.monitor;

import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URL;

import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.ui.PlatformUI;
import org.wso2.wsf.ide.wtp.ext.server.bean.WSASConfigurationBean;
import org.wso2.wsf.ide.wtp.ext.server.util.WSASUtils;

public class WSASUpMonitorThread extends Thread {
	private final long inactiveSleepTime = 2000;
	MessageBox box = new MessageBox(PlatformUI.getWorkbench().getActiveWorkbenchWindow().getShell());
	private static boolean alive = true;
	
    public void run() {
        try {
        	URL url = new URL(WSASUtils.getWSASVersionServiceHTTPAddress());
        	
            while (true) {
                try {
                    HttpURLConnection httpCon;
                    httpCon = (HttpURLConnection) url.openConnection();
                    httpCon.setDoOutput(true);
                    httpCon.setDoInput(true);
                    httpCon.setUseCaches(false);
                    httpCon.setRequestMethod("GET");
                    HttpURLConnection.setFollowRedirects(true);

                    httpCon.connect();
                    httpCon.disconnect();
                    Thread.sleep(1000);
                    WSASConfigurationBean.setWsasStartStatus(true);
                    break;
                } catch (IOException e) {
                    try {
                    	WSASUpMonitorThread.sleep(inactiveSleepTime);
                    } catch (InterruptedException e1) {
    					WSASConfigurationBean.setWsasStartStatus(false);
                        break;
                    }
                }
            }
        	
     	
        	while(true){
        		if (alive) {
        			WSASUpMonitorThread.sleep(inactiveSleepTime);
				}else{
					return;
				}
        	}
        	
         
        } catch (Exception e) {
        	e.printStackTrace();
        }

    }
    
    public static void setAlive(boolean flag){
    	alive = flag;
    }

}
