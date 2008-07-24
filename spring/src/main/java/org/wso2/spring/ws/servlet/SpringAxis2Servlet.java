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

package org.wso2.spring.ws.servlet;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.MissingResourceException;

import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.xml.namespace.QName;

import org.apache.axis2.AxisFault;
import org.apache.axis2.Constants;
import org.apache.axis2.context.ConfigurationContext;
import org.apache.axis2.context.ConfigurationContextFactory;
import org.apache.axis2.deployment.DeploymentErrorMsgs;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.description.AxisModule;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.i18n.Messages;
import org.apache.axis2.transport.http.AxisServlet;
import org.springframework.context.ApplicationContext;
import org.springframework.web.context.support.WebApplicationContextUtils;
import org.wso2.spring.ws.SpringWebService;
import org.wso2.spring.ws.WebServices;
import org.wso2.spring.ws.axis2.SpringBeanSystemConfigurator;
import org.wso2.spring.ws.axis2.SpringWebServiceBuilder;
import org.wso2.spring.ws.beans.MessageReceiverBean;
import org.wso2.spring.ws.util.Utils;

/**
 * The Spring Axis2 Servlet integrates Axis2 capabilities into the Spring
 * framework
 */
public class SpringAxis2Servlet extends AxisServlet {

	private AxisService axisService;

	public void init(ServletConfig servletConfig) throws ServletException {
		super.init(servletConfig);
		ServletContext servletContext = servletConfig.getServletContext();

		// Spring application context is retrieved from the servlet context
		ApplicationContext applicationContext = WebApplicationContextUtils
				.getWebApplicationContext(servletContext);

		// Retrieve the services bean and get the service list from the app
		// context
		WebServices servicesBean = Utils
				.getServicesfromAppContext(applicationContext);
		ArrayList<SpringWebService> services = servicesBean.getServices();

		if (!(services == null)) {
			Iterator<SpringWebService> it = services.iterator();

			while (it.hasNext()) {
				SpringWebService springService = (SpringWebService) it.next();

				// Retrieve data required to build service
				String beanName = springService.getServiceName();
				Object springPOJO = springService.getServiceBean();
				String clazz = springPOJO.getClass().getName();

				try {
					// Start building axis service
					axisService = new AxisService(beanName + "SpringService");

					SpringWebServiceBuilder builder = new SpringWebServiceBuilder(
							configContext, axisService);

					// populate Spring bean with common parameters

					springService = populateCommonParameters(springService,
							clazz);

					// populate Axis Service
					axisService = builder.populateService(springService);

					// add service to axis configuration
					this.axisConfiguration.addService(axisService);
					handleModulesRefs();

				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace(System.out);
					throw new ServletException(
							"Could not populate Web Service with required Spring bean");
				}
			}
		}
	}

	// populate Spring Web Service bean with parameters common to POJOs

	private SpringWebService populateCommonParameters(
			SpringWebService springService, String clazz) {
		ArrayList<MessageReceiverBean> msgReceivers = springService
				.getMessageReceivers();

		// populate common message receivers only if no message receivers are
		// specified by the service author
		if (msgReceivers == null || msgReceivers.isEmpty()) {
			// populate common message receivers
			MessageReceiverBean inOnlyReceiver = new MessageReceiverBean();
			inOnlyReceiver.setMep("http://www.w3.org/2004/08/wsdl/in-only");
			inOnlyReceiver
					.setClazz("org.apache.axis2.rpc.receivers.RPCInOnlyMessageReceiver");
			MessageReceiverBean inOutOnlyReceiver = new MessageReceiverBean();
			inOutOnlyReceiver.setMep("http://www.w3.org/2004/08/wsdl/in-out");
			inOutOnlyReceiver
					.setClazz("org.apache.axis2.rpc.receivers.RPCMessageReceiver");
			if (msgReceivers == null) {
				msgReceivers = new ArrayList<MessageReceiverBean>();
			}
			msgReceivers.add(inOnlyReceiver);
			msgReceivers.add(inOutOnlyReceiver);
			springService.setMessageReceivers(msgReceivers);
		}

		// populate common parameters

		Map parameters = springService.getParameters();

		if (parameters == null) {
			parameters = new HashMap();
		}

		parameters.put("ServiceObjectSupplier",
				"org.wso2.spring.ws.axis2.SpringObjectSupplier");
		parameters.put("SpringPOJO", springService.getServiceBean());
		parameters.put("ServiceClass", clazz);

		springService.setParameters(parameters);

		return springService;
	}

	private void handleModulesRefs() throws MissingResourceException, AxisFault {
		ArrayList list = axisService.getModules();
		for (int i = 0; i < list.size(); i++) {
			AxisModule module = axisConfiguration.getModule((String) list
					.get(i));
			if (module == null) {
				throw new DeploymentException(Messages.getMessage(
						DeploymentErrorMsgs.BAD_MODULE_FROM_SERVICE,
						axisService.getName(), ((QName) list.get(i))
								.getLocalPart()));
			}
			axisService.engageModule(module);
		}
	}

	@Override
	protected ConfigurationContext initConfigContext(ServletConfig config)
			throws ServletException {
		// TODO Auto-generated method stub
		ServletContext servletContext = servletConfig.getServletContext();

		// Spring application context is retrieved from the servlet context
		ApplicationContext applicationContext = WebApplicationContextUtils
				.getWebApplicationContext(servletContext);

		try {
			// Spring bean system configurator created from the application
			// context
			SpringBeanSystemConfigurator sbsc = new SpringBeanSystemConfigurator(
					Utils.getAxisConfigfromAppContext(applicationContext),
					config);

			// Configuration context created from configurator
			ConfigurationContext configContext = ConfigurationContextFactory
					.createConfigurationContext(sbsc);
			configContext.setProperty(Constants.CONTAINER_MANAGED,
					Constants.VALUE_TRUE);
			return configContext;
		} catch (Exception e) {
			throw new ServletException(e);
		}
	}
}