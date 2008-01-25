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

package org.wso2.spring.ws.axis2;

import org.apache.axis2.AxisFault;
import org.apache.axis2.ServiceObjectSupplier;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.description.Parameter;

public class SpringObjectSupplier implements ServiceObjectSupplier {
	
	public static final String SERVICE_SPRING_BEANNAME = "SpringBeanName";
	public static final String SPRING_POJO = "SpringPOJO";
	
	
	
	public Object getServiceObject(AxisService axisService) throws AxisFault {
		// TODO Auto-generated method stub
		
        Parameter springPOJOParam = axisService.getParameter(SPRING_POJO);
        Object springPOJO = springPOJOParam.getValue();
        
		if (springPOJO == null) {
			throw new AxisFault("Spring Bean does not exist");
		}
        return springPOJOParam.getValue();
	

	}
}
