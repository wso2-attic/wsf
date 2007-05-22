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
package org.wso2.wsf.wtp.server.monitor;

import java.net.URL;
import java.net.URLConnection;

import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.ui.PlatformUI;
import org.wso2.wsf.wtp.server.bean.WSASConfigurationBean;
import org.wso2.wsf.wtp.server.util.WSASUtils;

public class WSASUpMonitorThread extends Thread {
	private final long wsasStartTime = 10000;
	private final long inactiveSleepTime = 1000;
	MessageBox box = new MessageBox(PlatformUI.getWorkbench().getActiveWorkbenchWindow().getShell());
	private static boolean alive = true;
	
    public void run() {
        try {
        	URLConnection conn = null;
        	
        	while(conn == null){
        		WSASUpMonitorThread.sleep(wsasStartTime);
	            // Create a URLConnection object for a URL
	            URL url = new URL(WSASUtils.getWSASHTTPAddtess());
	            conn = url.openConnection();
	            if(conn != null){
					//set wsas start status to pass
					WSASConfigurationBean.setWsasStartStatus(true);
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
