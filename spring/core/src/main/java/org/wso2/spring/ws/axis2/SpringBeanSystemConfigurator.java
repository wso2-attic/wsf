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

import javax.servlet.ServletConfig;

import org.apache.axis2.AxisFault;
import org.apache.axis2.Constants;
import org.apache.axis2.builder.ApplicationXMLBuilder;
import org.apache.axis2.builder.MIMEBuilder;
import org.apache.axis2.builder.MTOMBuilder;
import org.apache.axis2.builder.SOAPBuilder;
import org.apache.axis2.builder.XFormURLEncodedBuilder;
import org.apache.axis2.context.ConfigurationContext;
import org.apache.axis2.deployment.DeploymentEngine;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.deployment.ModuleDeployer;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.engine.AxisConfigurator;
import org.apache.axis2.transport.http.HTTPConstants;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.wso2.spring.ws.SpringAxisConfiguration;

/**
 * Axis Configurator for WSF/Spring
 */
public class SpringBeanSystemConfigurator extends DeploymentEngine implements
		AxisConfigurator {
	
	private static final Log log = LogFactory.getLog(SpringBeanSystemConfigurator.class);
	
	private SpringAxisConfiguration springConfig = null;
	private String repoLocation = null;
	private ServletConfig config;
	
	public SpringBeanSystemConfigurator(SpringAxisConfiguration springConfig, ServletConfig config) throws DeploymentException{
		
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
	
	
	/* (non-Javadoc)
	 * @see org.apache.axis2.engine.AxisConfigurator#engageGlobalModules()
	 */
	public void engageGlobalModules() throws AxisFault {
		// TODO Auto-generated method stub
		engageModules();
	}

	
	/* (non-Javadoc)
	 * @see org.apache.axis2.engine.AxisConfigurator#getAxisConfiguration()
	 */
	public AxisConfiguration getAxisConfiguration() throws AxisFault {
		
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
	
	/**
	 * @param axisConfig
	 */
	public void populateDefaultValues(AxisConfiguration axisConfig) {
		axisConfig.addMessageBuilder("multipart/related", new MIMEBuilder());
        axisConfig.addMessageBuilder("application/soap+xml", new SOAPBuilder());
        axisConfig.addMessageBuilder("text/xml", new SOAPBuilder());
        axisConfig.addMessageBuilder("application/xop+xml", new MTOMBuilder());
        axisConfig.addMessageBuilder("application/xml", new ApplicationXMLBuilder());
        axisConfig.addMessageBuilder("application/x-www-form-urlencoded",
                                     new XFormURLEncodedBuilder());
	}
	
	/* (non-Javadoc)
	 * @see org.apache.axis2.deployment.DeploymentEngine#loadServices()
	 */
	@Override
	public void loadServices() {
        if (!(repoLocation == null || "".equals(repoLocation))) {
            super.loadServices();
        }
    }
	
	/* (non-Javadoc)
	 * @see org.apache.axis2.deployment.DeploymentEngine#setConfigContext(org.apache.axis2.context.ConfigurationContext)
	 */
	public void setConfigContext(ConfigurationContext configContext) {
        super.setConfigContext(configContext);

        // setting ServletContext into configctx
        configContext.setProperty(HTTPConstants.MC_HTTP_SERVLETCONTEXT,
                                  config.getServletContext());
        Parameter servletConfigParam = new Parameter();
        servletConfigParam.setName(HTTPConstants.HTTP_SERVLETCONFIG);
        servletConfigParam.setValue(config);
        try {
            configContext.getAxisConfiguration().addParameter(servletConfigParam);
        } catch (AxisFault axisFault) {
        	log.error(axisFault.getMessage(), axisFault);
        }
    }

}
