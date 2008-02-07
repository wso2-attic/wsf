package org.wso2.spring.ws.axis2;

import org.apache.axis2.AxisFault;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.engine.AxisConfiguration;
import org.wso2.spring.ws.SpringWebService;

import junit.framework.TestCase;

public class SpringWebServiceBuilderTest extends TestCase {
	public void testPopulateService() {
		SpringWebService sampleService = new SpringWebService();
		Object samplePOJO = new Object();
		sampleService.setServiceBean(samplePOJO);
		sampleService.setServiceName("TestWebService");
		sampleService.setServiceDescription("This is a test webservice for Spring/Axis2 Integration");
		sampleService.setSessionScope("request");
		
		AxisService service = new AxisService();
				
		SpringWebServiceBuilder servicebuilder = new SpringWebServiceBuilder(new AxisConfiguration(), service);
		try {
			service = servicebuilder.populateService(sampleService);
		} catch (DeploymentException e) {
			// TODO Auto-generated catch block
			fail("Coud not populate service");
		}
		
		
	}
}
