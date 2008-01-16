package org.wso2.springwebservices.util;

import java.util.Iterator;
import java.util.Map;

import javax.servlet.ServletException;

import org.springframework.context.ApplicationContext;
import org.wso2.springwebservices.SpringAxisConfiguration;
import org.wso2.springwebservices.WebServices;

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
