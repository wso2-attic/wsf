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
package org.wso2.wsf.wtp.server.command;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.wtp.server.bean.WSASConfigurationBean;

public class WSASStopCommand {
	
    private static Class wsasMainClazz;
    private static IStatus status;
	
	public static IStatus run() throws InvocationTargetException {
		status = Status.OK_STATUS;
		
		if (WSASConfigurationBean.isWsasStartStatus()) {
			wsasMainClazz = WSASStartCommand.getWSASMainClass();
			try {
				Method[] methods = wsasMainClazz.getMethods();
				Method shutdownMethod = null;
				for (int i = 0; i < methods.length; i++) {
					if (methods[i].getName().equals("main")) {
						shutdownMethod = methods[i];
						break;
					}
				}

				shutdownMethod.invoke(null, new Object[]{new String[]{"STOP"}});

				//set wsas start status to shutdown
				WSASConfigurationBean.setWsasStartStatus(false);

			}  catch (IllegalAccessException e) {
				status = new Status( IStatus.ERROR,"id",0,e.getMessage(),null );
			}
		}else{
			status = new Status( IStatus.ERROR,"id",12,"WSAS Instance is not active !!",null ); 
		}
		return status;
	}

}
