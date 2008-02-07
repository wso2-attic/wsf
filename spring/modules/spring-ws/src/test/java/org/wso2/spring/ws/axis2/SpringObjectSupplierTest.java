package org.wso2.spring.ws.axis2;
import org.apache.axis2.AxisFault;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.description.Parameter;

import junit.framework.TestCase;


public class SpringObjectSupplierTest extends TestCase {
	
	public static final String SERVICE_SPRING_BEANNAME = "SpringBeanName";
	public static final String SPRING_POJO = "SpringPOJO";
	
	public void testGetServiceObject() {
		SpringObjectSupplier supplier = new SpringObjectSupplier();
		AxisService service = new AxisService();
		Object testObj = new Object();
		Object retrievedObj = null;
		try {
			service.addParameter(new Parameter(SERVICE_SPRING_BEANNAME, "testName" ));
			service.addParameter(SPRING_POJO, testObj);
			retrievedObj = supplier.getServiceObject(service);
		} catch (AxisFault e) {
			// TODO Auto-generated catch block
			fail("Axis Fault received while retrieveing POJO object");
		}
		assertEquals(testObj, retrievedObj);
		
	}
}
