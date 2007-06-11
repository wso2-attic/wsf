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

import java.io.File;
import java.lang.reflect.AccessibleObject;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.wso2.wsf.wtp.server.bean.WSASConfigurationBean;
import org.wso2.wsf.wtp.server.constant.WSASConfigurationConstant;
import org.wso2.wsf.wtp.server.util.WSASClassLoadingUtil;
import org.wso2.wsf.wtp.server.util.WSASPropertiesUtil;

public class WSASStartCommand {
	
    private static Class wsasMainClazz;
    private static IStatus status;

	public static IStatus run() throws InvocationTargetException {
		status = Status.OK_STATUS;

		if (WSASConfigurationBean.isWsasStartStatus()) {
			status = new Status( IStatus.ERROR,"id",11,"WSAS Already Running !!",null);
			WSASConfigurationBean.setWSASAlreadyRunning(true);
		}else{
			//Init the Configuration Bean
			WSASConfigurationBean.Init();
			//Set WSAS system properties
			WSASPropertiesUtil.setWSASProperties();
			WSASClassLoadingUtil.init(WSASConfigurationBean.getWsasInstallationPath());
			wsasMainClazz = WSASClassLoadingUtil
							.loadClassFromClassLoader(WSASConfigurationConstant.WSAS_MAIN_CLASS);

			Method[] methods = wsasMainClazz.getMethods();
			Method mainMethod = null;
			for (int i = 0; i < methods.length; i++) {
				if (methods[i].getName().equals("main")) {
					mainMethod = methods[i];
					break;
				}
			}
			Class serviceConfic = WSASClassLoadingUtil
					.loadClassFromClassLoader(WSASConfigurationConstant.WSAS_SERVER_CONFIG_CLASS);
			Field[] fields = serviceConfic.getDeclaredFields();
			AccessibleObject.setAccessible(fields, true);
			try{
				for (int i = 0; i < fields.length; i++) {
					Field f = fields[i];
					if (f.getName().equals("configurationXMLLocation")) {
						f.set(serviceConfic, WSASConfigurationBean.getWsasInstallationPath()
								+ File.separator + "conf" + File
								.separator + "server.xml");
						break;
					}
				}

				mainMethod.invoke(null, new Object[]{new String[]{"RUN"}});
				WSASConfigurationBean.setWSASAlreadyRunning(false);
				
			}catch(IllegalArgumentException e){
				status = new Status( IStatus.ERROR,"id",0,e.getMessage(),null);
			}catch(IllegalAccessException e){
				status = new Status( IStatus.ERROR,"id",0,e.getMessage(),null);
			}
		}
		return status;
	}
	
    public static Class getWSASMainClass(){
        return wsasMainClazz;
    }

}
