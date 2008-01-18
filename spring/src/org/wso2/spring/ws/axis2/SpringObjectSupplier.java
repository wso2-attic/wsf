package org.wso2.spring.ws.axis2;

import org.apache.axis2.AxisFault;
import org.apache.axis2.ServiceObjectSupplier;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.description.Parameter;

public class SpringObjectSupplier implements ServiceObjectSupplier {
	
	public static final String SERVICE_SPRING_BEANNAME = "SpringBeanName";
	public static final String SPRING_POJO = "SpringPOJO";
	
	
	@Override
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
