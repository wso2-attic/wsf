package org.wso2.spring.ws.axis2;

import java.io.File;
import java.util.Iterator;
import java.util.Map;

import javax.servlet.ServletConfig;

import org.apache.axis2.AxisFault;
import org.apache.axis2.Constants;
import org.apache.axis2.builder.ApplicationXMLBuilder;
import org.apache.axis2.builder.MIMEBuilder;
import org.apache.axis2.builder.MTOMBuilder;
import org.apache.axis2.builder.SOAPBuilder;
import org.apache.axis2.builder.XFormURLEncodedBuilder;
import org.apache.axis2.context.ConfigurationContext;
import org.apache.axis2.deployment.DeploymentConstants;
import org.apache.axis2.deployment.DeploymentEngine;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.deployment.ModuleDeployer;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.engine.AxisConfigurator;
import org.apache.axis2.transport.http.HTTPConstants;
import org.springframework.beans.factory.config.ConfigurableListableBeanFactory;
import org.wso2.spring.ws.SpringAxisConfiguration;
import org.wso2.spring.ws.beans.Axis2Bean;

public class SpringBeanSystemConfigurator extends DeploymentEngine implements
		AxisConfigurator {
	
	private SpringAxisConfiguration springConfig = null;
	private String repoLocation = null;
	private ServletConfig config;
	
	public SpringBeanSystemConfigurator(SpringAxisConfiguration springConfig, ServletConfig config) throws DeploymentException{
		// TODO Auto-generated constructor stub
		
		this.springConfig = springConfig;
		this.axisConfig = new AxisConfiguration();
		this.config = config;

		
		Parameter param = new Parameter();
        param.setName(Constants.Configuration.ARTIFACTS_TEMP_DIR);
        param.setValue(config.getServletContext().getAttribute("javax.servlet.context.tempdir"));
        try {
            axisConfig.addParameter(param);
        } catch (AxisFault axisFault) {
            axisFault.printStackTrace(System.out);
        }
	}
	
	
	public void engageGlobalModules() throws AxisFault {
		// TODO Auto-generated method stub
		engageModules();
	}

	
	public AxisConfiguration getAxisConfiguration() throws AxisFault {
		// TODO Auto-generated method stub
		
		SpringAxisConfigBuilder builder = new SpringAxisConfigBuilder(springConfig);
		// populate Axis Configuration with default values
		populateDefaultValues(axisConfig);
		
		// populate the Axis Configuration with values from the Spring Axis Configuration bean
		builder.populateConfig(axisConfig);

		// load modules present in the classpath, sinc eno repo exists as in the normal axis scenario
		moduleDeployer = new ModuleDeployer(axisConfig);
		loadFromClassPath();

		axisConfig.setConfigurator(this);
        return axisConfig;
		
	}
	
	public void populateDefaultValues(AxisConfiguration axisConfig) {
		axisConfig.addMessageBuilder("multipart/related", new MIMEBuilder());
        axisConfig.addMessageBuilder("application/soap+xml", new SOAPBuilder());
        axisConfig.addMessageBuilder("text/xml", new SOAPBuilder());
        axisConfig.addMessageBuilder("application/xop+xml", new MTOMBuilder());
        axisConfig.addMessageBuilder("application/xml", new ApplicationXMLBuilder());
        axisConfig.addMessageBuilder("application/x-www-form-urlencoded",
                                     new XFormURLEncodedBuilder());
	}
	
	@Override
	public void loadServices() {
        if (!(repoLocation == null || "".equals(repoLocation))) {
            super.loadServices();
        }
    }
	
	public void setConfigContext(ConfigurationContext configContext) {
        super.setConfigContext(configContext);

        // setting ServletContext into configctx
        configContext.setProperty(HTTPConstants.MC_HTTP_SERVLETCONTEXT,
                                  config.getServletContext());
        // setting ServletContext into configctx
        configContext.setProperty(HTTPConstants.MC_HTTP_SERVLETCONTEXT,
                                  config.getServletContext());
        Parameter servletConfigParam = new Parameter();
        servletConfigParam.setName(HTTPConstants.HTTP_SERVLETCONFIG);
        servletConfigParam.setValue(config);
        try {
            configContext.getAxisConfiguration().addParameter(servletConfigParam);
        } catch (AxisFault axisFault) {
            System.out.println(axisFault.getMessage());
        	//log.error(axisFault.getMessage(), axisFault);
        }
    }

}
