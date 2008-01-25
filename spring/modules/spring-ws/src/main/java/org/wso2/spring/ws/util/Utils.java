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

package org.wso2.spring.ws.util;

import java.util.Iterator;
import java.util.Map;

import javax.servlet.ServletException;

import org.springframework.context.ApplicationContext;
import org.wso2.spring.ws.SpringAxisConfiguration;
import org.wso2.spring.ws.WebServices;

public class Utils {
	
	// returns Spring axis configuration bean from an application context
	
	public static SpringAxisConfiguration getAxisConfigfromAppContext(ApplicationContext appCtx) throws ServletException{
		return (SpringAxisConfiguration) getBeanfromAppContext(appCtx, SpringAxisConfiguration.class);
	}
	
	// returns Spring services bean from an application context
	
	public static WebServices getServicesfromAppContext(ApplicationContext appCtx) throws ServletException{
		return (WebServices) getBeanfromAppContext(appCtx, WebServices.class);
	}

	
	// returns required bean from an application context
	
	protected static Object getBeanfromAppContext(ApplicationContext appCtx, Class clazz) throws ServletException{
		
		Map configMap = appCtx.getBeansOfType(clazz);
		if (configMap.size() > 1) {
			throw new ServletException("More than one "+ clazz.getCanonicalName() +" beans present");
		}
		Iterator it = configMap.values().iterator();
		Object obj =  it.next();
		return obj;
	}
	
	// returns bean id from an object
	
	
}
