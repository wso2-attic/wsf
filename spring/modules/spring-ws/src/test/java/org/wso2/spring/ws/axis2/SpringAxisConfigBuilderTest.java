package org.wso2.spring.ws.axis2;

import java.io.File;

import javax.servlet.ServletException;

import junit.framework.TestCase;

import org.apache.axis2.AxisFault;
import org.apache.axis2.engine.AxisConfiguration;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;
import org.wso2.spring.ws.SpringAxisConfiguration;
import org.wso2.spring.ws.util.Utils;

public class SpringAxisConfigBuilderTest extends TestCase {
	@Override
	protected void setUp() throws Exception {
		// TODO Auto-generated method stub
		super.setUp();
		
		
	}
	
	public void testBuildConfig() {
		
		ApplicationContext applicationContext =
            new FileSystemXmlApplicationContext("src" + File.separator + "test" + File.separator + "resources" + File.separator + "axis2Config.xml");
		
		try {
			SpringAxisConfigBuilder configBuilder = new SpringAxisConfigBuilder(Utils.getAxisConfigfromAppContext(applicationContext));
			AxisConfiguration axisConfig = new AxisConfiguration();
			configBuilder.populateConfig(axisConfig);
		} catch (AxisFault e) {
			// TODO Auto-generated catch block
			fail("Cannot populate Axis Configuration");
		} catch (ServletException e) {
			// TODO Auto-generated catch block
			fail("Error resolving axis2Config.xml");
		}
	}
}
