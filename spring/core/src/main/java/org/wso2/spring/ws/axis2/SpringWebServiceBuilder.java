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

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.Map;

import javax.xml.namespace.QName;

import org.apache.axis2.AxisFault;
import org.apache.axis2.Constants;
import org.apache.axis2.context.ConfigurationContext;
import org.apache.axis2.deployment.DeploymentErrorMsgs;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.deployment.util.Utils;
import org.apache.axis2.description.AxisMessage;
import org.apache.axis2.description.AxisOperation;
import org.apache.axis2.description.AxisOperationFactory;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.description.InOutAxisOperation;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.description.ParameterInclude;
import org.apache.axis2.description.WSDL2Constants;
import org.apache.axis2.description.java2wsdl.AnnotationConstants;
import org.apache.axis2.description.java2wsdl.DefaultSchemaGenerator;
import org.apache.axis2.description.java2wsdl.DocLitBareSchemaGenerator;
import org.apache.axis2.description.java2wsdl.Java2WSDLConstants;
import org.apache.axis2.description.java2wsdl.SchemaGenerator;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.engine.MessageReceiver;
import org.apache.axis2.engine.ObjectSupplier;
import org.apache.axis2.i18n.Messages;
import org.apache.axis2.util.Loader;
import org.apache.axis2.wsdl.WSDLConstants;
import org.apache.neethi.Policy;
import org.apache.neethi.PolicyEngine;
import org.apache.ws.commons.schema.utils.NamespaceMap;
import org.wso2.spring.ws.SpringWebService;
import org.wso2.spring.ws.beans.MessageReceiverBean;
import org.wso2.spring.ws.beans.OperationBean;

/**
 * Spring Web Service Builder populates the Axis Service with data from the
 * Spring Web Service, generates WSDL, etc.
 */

public class SpringWebServiceBuilder {

	private AxisService service;
	private ConfigurationContext configCtx;
	private AxisConfiguration axisConfig;

	public SpringWebServiceBuilder(AxisConfiguration axisConfig,
			AxisService service) {
		this.service = service;
		this.axisConfig = axisConfig;
	}

	public SpringWebServiceBuilder(ConfigurationContext configCtx,
			AxisService service) {
		this.service = service;
		this.configCtx = configCtx;
		this.axisConfig = this.configCtx.getAxisConfiguration();
	}

	/**
	 * Populates the Axis Service with data from the Spring Web Service
	 * 
	 * @param springService
	 * @return AxisService
	 * @throws DeploymentException
	 */
	public AxisService populateService(SpringWebService springService)
			throws DeploymentException {
		try {
			// process name
			// Processing service level parameters
			String beanName = springService.getServiceName();

			if (!"".equals(beanName.trim())) {
				service.setName(beanName);
				// To be on the safe side
				if (service.getDocumentation() == null) {
					service.setDocumentation(beanName);
				}
			}

			// Process parameters
			Map parameterMap = springService.getParameters();

			if (parameterMap != null) {
				processParameters(parameterMap, service, service.getParent());
			}

			// process service description

			String description = springService.getServiceDescription();
			if (description == null) {
				description = new String("No service description set");
			}
			service.setDocumentation(description);

			// Setting service target namespace if any

			String targetNameSpace = springService.getTargetNameSpace();

			if (targetNameSpace != null && !"".equals(targetNameSpace)) {
				service.setTargetNamespace(targetNameSpace);
			} else {
				if (service.getTargetNamespace() == null
						|| "".equals(service.getTargetNamespace())) {
					service
							.setTargetNamespace(Java2WSDLConstants.DEFAULT_TARGET_NAMESPACE);
				}
			}

			// processing Default Message receivers

			ArrayList<MessageReceiverBean> receiverList = springService
					.getMessageReceivers();

			if (receiverList != null) {
				Iterator itr = receiverList.iterator();

				while (itr.hasNext()) {
					MessageReceiverBean receiverBean = (MessageReceiverBean) itr
							.next();
					processMessageReceivers(service.getClassLoader(),
							receiverBean);
				}
			}

			// processing service scope
			String sessionScope = springService.getSessionScope();
			if (sessionScope != null) {
				service.setScope(sessionScope);
			}

			// Load object supplier
			String objectSupplierValue = (String) service
					.getParameterValue(SpringAxisConstants.TAG_OBJECT_SUPPLIER);
			if (objectSupplierValue != null) {
				loadObjectSupplierClass(objectSupplierValue);
			}

			ArrayList<OperationBean> operations = springService.getOperations();
			ArrayList<AxisOperation> axisOperations = new ArrayList<AxisOperation>();

			if (operations != null && !operations.isEmpty()) {
				for (int i = 0; i < operations.size(); i++) {
					OperationBean operationBean = operations.get(i);
					String name = operationBean.getName();
					String namespace = operationBean.getNamespace();
					AxisOperation axisOperation;
					if (namespace != null) {
						axisOperation = service.getOperation(new QName(namespace,
								name));
					} else {
						axisOperation = service.getOperation(new QName(name));
						if (axisOperation == null) {
							axisOperation = service.getOperation(new QName(service
									.getTargetNamespace(), name));
						}
					}

					if (axisOperation == null) {
						String mep = operationBean.getMep();
						if (mep == null) {
							// assumed MEP is in-out
							axisOperation = new InOutAxisOperation();
							axisOperation.setParent(service);

						} else {
							axisOperation = AxisOperationFactory
									.getOperationDescription(mep);
						}
						axisOperation.setName(new QName(name));
						String MEP = axisOperation.getMessageExchangePattern();
						if (WSDL2Constants.MEP_URI_IN_ONLY.equals(MEP)
								|| WSDL2Constants.MEP_URI_IN_OPTIONAL_OUT
										.equals(MEP)
								|| WSDL2Constants.MEP_URI_OUT_OPTIONAL_IN
										.equals(MEP)
								|| WSDL2Constants.MEP_URI_ROBUST_OUT_ONLY
										.equals(MEP)
								|| WSDL2Constants.MEP_URI_ROBUST_IN_ONLY
										.equals(MEP)
								|| WSDL2Constants.MEP_URI_IN_OUT.equals(MEP)) {
							AxisMessage inaxisMessage = axisOperation
									.getMessage(WSDLConstants.MESSAGE_LABEL_IN_VALUE);
							if (inaxisMessage != null) {
								inaxisMessage.setName(name
										+ Java2WSDLConstants.MESSAGE_SUFFIX);
							}
						}

						if (WSDL2Constants.MEP_URI_OUT_ONLY.equals(MEP)
								|| WSDL2Constants.MEP_URI_OUT_OPTIONAL_IN
										.equals(MEP)
								|| WSDL2Constants.MEP_URI_IN_OPTIONAL_OUT
										.equals(MEP)
								|| WSDL2Constants.MEP_URI_ROBUST_OUT_ONLY
										.equals(MEP)
								|| WSDL2Constants.MEP_URI_IN_OUT.equals(MEP)) {
							AxisMessage outAxisMessage = axisOperation
									.getMessage(WSDLConstants.MESSAGE_LABEL_OUT_VALUE);
							if (outAxisMessage != null) {
								outAxisMessage.setName(name
										+ Java2WSDLConstants.RESPONSE);
							}
						}
					}

					if (axisOperation == null) {
						throw new DeploymentException("Invalid operation name");
					}
					axisOperations.add(axisOperation);

					String actionMapping = operationBean.getActionMapping();
					if (actionMapping != null) {
						ArrayList<String> actionMappings = new ArrayList<String>();
						actionMappings.add(actionMapping);
						axisOperation.setWsamappingList(actionMappings);
					}

					String outputActionMapping = operationBean
							.getOutputActionMapping();
					if (outputActionMapping != null) {
						axisOperation.setOutputAction(outputActionMapping);
					}
				}
			}

			if (axisOperations != null && !axisOperations.isEmpty()) {
				for (int i = 0; i < axisOperations.size(); i++) {
					AxisOperation axisOperation = axisOperations.get(i);
					service.addOperation(axisOperation);
					
					ArrayList wsamappings = axisOperation.getWSAMappingList();
					if (wsamappings == null) {
						continue;
					}

					for (int j = 0; j < wsamappings.size(); j++) {
						String mapping = (String) wsamappings.get(j);
						if (mapping.length() > 0) {
							service
									.mapActionToOperation(mapping,
											axisOperation);
						}
					}
				}
			}

			// Removing exclude operations
			ArrayList excludeops = new ArrayList();
			ArrayList<OperationBean> excludeOpBeans = springService
					.getExcludeOperations();
			if (excludeOpBeans != null && excludeOpBeans.size() > 0) {
				for (int i = 0; i < excludeOpBeans.size(); i++) {
					OperationBean operationBean = excludeOpBeans.get(i);
					excludeops.add(operationBean.getName());
				}
			}

			ArrayList<String> policies = springService.getPolicies();
			if (policies != null && policies.size() > 0) {
				for (int i = 0; i < policies.size(); i++) {
					String value = policies.get(i);
					ByteArrayInputStream bais = new ByteArrayInputStream(value
							.getBytes());
					Policy policy = PolicyEngine.getPolicy(bais);
					service.getPolicySubject().attachPolicy(policy);
				}
			}
			
			ArrayList<String> policyFiles = springService.getPolicyFiles();
			if (policyFiles != null && policyFiles.size() > 0) {
				for (int i = 0; i < policyFiles.size(); i++) {
					String policyFile = policyFiles.get(i);
					ClassLoader classloader = Thread.currentThread()
							.getContextClassLoader();
					InputStream is = classloader
							.getResourceAsStream(policyFile);
					Policy policy = PolicyEngine.getPolicy(is);
					service.getPolicySubject().attachPolicy(policy);
				}
			}

			// generate schema

			if (!service.isUseUserWSDL()) {
				// Generating schema for the service if the impl class is Java
				if (!service.isWsdlFound()) {
					// trying to generate WSDL for the service using JAM and
					// Java reflection
					try {
						if (generateWsdl(service)) {
							Utils.fillAxisService(service, axisConfig,
									excludeops, null);
						} else {
							ArrayList nonRpcOperations = getNonRPCMethods(service);
							Utils.fillAxisService(service, axisConfig,
									excludeops, nonRpcOperations);
						}
					} catch (Exception e) {
						throw new DeploymentException(Messages.getMessage(
								"errorinschemagen", e.getMessage()), e);
					}
				}
			}

			// processing service-wide modules which required to engage globally
			ArrayList moduleRefs = springService.getModules();
			if (moduleRefs != null) {
				processModuleRefs(moduleRefs);
			}

		} catch (AxisFault axisFault) {
			// TODO Auto-generated catch block
			throw new DeploymentException(axisFault);
		}
		return service;
	}

	private void processModuleRefs(ArrayList moduleRefs)
			throws DeploymentException {
		try {

			Iterator moduleIt = moduleRefs.iterator();
			while (moduleIt.hasNext()) {

				String moduleRefName = (String) moduleIt.next();

				if (moduleRefName != null) {
					if (axisConfig.getModule(moduleRefName) == null) {
						throw new DeploymentException(Messages.getMessage(
								DeploymentErrorMsgs.MODULE_NOT_FOUND,
								moduleRefName));
					} else {
						service.addModuleref(moduleRefName);
					}
				}
			}
		} catch (AxisFault axisFault) {
			throw new DeploymentException(axisFault);
		}
	}

	private void loadObjectSupplierClass(String objectSupplierValue)
			throws AxisFault {
		try {
			ClassLoader loader = service.getClassLoader();
			Class objectSupplierImpl = Loader.loadClass(loader,
					objectSupplierValue.trim());
			ObjectSupplier objectSupplier = (ObjectSupplier) objectSupplierImpl
					.newInstance();
			service.setObjectSupplier(objectSupplier);
		} catch (Exception e) {
			throw AxisFault.makeFault(e);
		}
	}

	private boolean generateWsdl(AxisService axisService) {
		Iterator operatins = axisService.getOperations();
		if (operatins.hasNext()) {
			while (operatins.hasNext()) {
				AxisOperation axisOperation = (AxisOperation) operatins.next();

				if (axisOperation.isControlOperation()) {
					continue;
				}

				if (axisOperation.getMessageReceiver() == null) {
					continue;
				}
				String messageReceiverClass = axisOperation
						.getMessageReceiver().getClass().getName();
				if (!("org.apache.axis2.rpc.receivers.RPCMessageReceiver"
						.equals(messageReceiverClass)
						|| "org.apache.axis2.rpc.receivers.RPCInOnlyMessageReceiver"
								.equals(messageReceiverClass)
						|| "org.apache.axis2.rpc.receivers.RPCInOutAsyncMessageReceiver"
								.equals(messageReceiverClass) || "org.apache.axis2.jaxws.server.JAXWSMessageReceiver"
						.equals(messageReceiverClass))) {
					return false;
				}
			}
		}
		return true;
	}

	private ArrayList getNonRPCMethods(AxisService axisService) {
		ArrayList excludeOperations = new ArrayList();
		Iterator operatins = axisService.getOperations();
		if (operatins.hasNext()) {
			while (operatins.hasNext()) {
				AxisOperation axisOperation = (AxisOperation) operatins.next();
				if (axisOperation.getMessageReceiver() == null) {
					continue;
				}
				String messageReceiverClass = axisOperation
						.getMessageReceiver().getClass().getName();
				if (!("org.apache.axis2.rpc.receivers.RPCMessageReceiver"
						.equals(messageReceiverClass)
						|| "org.apache.axis2.rpc.receivers.RPCInOnlyMessageReceiver"
								.equals(messageReceiverClass)
						|| "org.apache.axis2.rpc.receivers.RPCInOutAsyncMessageReceiver"
								.equals(messageReceiverClass) || "org.apache.axis2.jaxws.server.JAXWSMessageReceiver"
						.equals(messageReceiverClass))) {
					excludeOperations.add(axisOperation.getName()
							.getLocalPart());
				}
			}
		}
		return excludeOperations;
	}

	private void processMessageReceivers(ClassLoader loader,
			MessageReceiverBean receiverBean) throws DeploymentException {

		MessageReceiver receiver = loadMessageReceiver(loader, receiverBean);
		service.addMessageReceiver(receiverBean.getMep(), receiver);

	}

	private MessageReceiver loadMessageReceiver(ClassLoader loader,
			MessageReceiverBean receiverBean) throws DeploymentException {

		String className = receiverBean.getClazz();
		MessageReceiver receiver = null;

		try {
			Class messageReceiver;

			if ((className != null) && !"".equals(className)) {
				messageReceiver = Loader.loadClass(loader, className);
				receiver = (MessageReceiver) messageReceiver.newInstance();
			}
		} catch (ClassNotFoundException e) {
			throw new DeploymentException(Messages.getMessage(
					DeploymentErrorMsgs.ERROR_IN_LOADING_MESSAGE_RECEIVER,
					"ClassNotFoundException", className), e);
		} catch (IllegalAccessException e) {
			throw new DeploymentException(Messages.getMessage(
					DeploymentErrorMsgs.ERROR_IN_LOADING_MESSAGE_RECEIVER,
					"IllegalAccessException", className), e);
		} catch (InstantiationException e) {
			throw new DeploymentException(Messages.getMessage(
					DeploymentErrorMsgs.ERROR_IN_LOADING_MESSAGE_RECEIVER,
					"InstantiationException", className), e);
		}

		return receiver;
	}

	private void processParameters(Map parameterMap, ParameterInclude service,
			ParameterInclude parent) throws DeploymentException {
		Iterator it = parameterMap.keySet().iterator();

		while (it.hasNext()) {
			Parameter parameter = new Parameter();
			// TODO set OMelement to parameter Element
			String paramName = (String) it.next();
			parameter.setName(paramName);

			Object paramValue = parameterMap.get(paramName);

			if (paramValue instanceof String) {
				parameter.setParameterType(Parameter.TEXT_PARAMETER);
				parameter.setValue((String) paramValue);
			} else {
				parameter.setValue(paramValue);
			}

			Parameter parentParam = null;
			if (parent != null) {
				parentParam = parent.getParameter(parameter.getName());
			}

			// TODO set the locked property of a parameter;

			try {
				if (parent != null) {
					if ((parentParam == null)
							|| !parent.isParameterLocked(parameter.getName())) {
						this.service.addParameter(parameter);
					}
				} else {
					this.service.addParameter(parameter);
				}
			} catch (AxisFault axisFault) {
				throw new DeploymentException(axisFault);
			}
		}

	}

	private static void fillAxisService(AxisService axisService,
			AxisConfiguration axisConfig, ArrayList excludeOperations,
			ArrayList nonRpcMethods) throws Exception {
		String serviceClass;
		Parameter implInfoParam = axisService
				.getParameter(Constants.SERVICE_CLASS);
		ClassLoader serviceClassLoader = axisService.getClassLoader();

		if (implInfoParam != null) {
			serviceClass = (String) implInfoParam.getValue();
		} else {
			// if Service_Class is null, every AbstractMR will look for
			// ServiceObjectSupplier. This is user specific and may contain
			// other looks.
			implInfoParam = axisService
					.getParameter(Constants.SERVICE_OBJECT_SUPPLIER);
			if (implInfoParam != null) {
				String className = ((String) implInfoParam.getValue()).trim();
				Class serviceObjectMaker = Loader.loadClass(serviceClassLoader,
						className);
				if (serviceObjectMaker.getModifiers() != Modifier.PUBLIC) {
					throw new AxisFault("Service class " + className
							+ " must have public as access Modifier");
				}

				// Find static getServiceObject() method, call it if there
				Method method = serviceObjectMaker.getMethod(
						"getServiceObject", new Class[] { AxisService.class });
				Object obj = null;
				if (method != null) {
					obj = method.invoke(serviceObjectMaker.newInstance(),
							new Object[] { axisService });
				}
				if (obj == null) {
					// log.warn("ServiceObjectSupplier implmentation Object
					// could not be found");
					throw new DeploymentException(
							"ServiceClass or ServiceObjectSupplier implmentation Object could not be found");
				}
				serviceClass = obj.getClass().getName();
			} else {
				return;
			}
		}
		// adding name spaces

		NamespaceMap map = new NamespaceMap();
		map.put(Java2WSDLConstants.AXIS2_NAMESPACE_PREFIX,
				Java2WSDLConstants.AXIS2_XSD);
		map.put(Java2WSDLConstants.DEFAULT_SCHEMA_NAMESPACE_PREFIX,
				Java2WSDLConstants.URI_2001_SCHEMA_XSD);
		axisService.setNameSpacesMap(map);
		SchemaGenerator schemaGenerator;
		Parameter generateBare = axisService
				.getParameter(Java2WSDLConstants.DOC_LIT_BARE_PARAMETER);
		if (generateBare != null && "true".equals(generateBare.getValue())) {
			schemaGenerator = new DocLitBareSchemaGenerator(serviceClassLoader,
					serviceClass.trim(),
					axisService.getSchematargetNamespace(), axisService
							.getSchemaTargetNamespacePrefix(), axisService);
		} else {
			schemaGenerator = new DefaultSchemaGenerator(serviceClassLoader,
					serviceClass.trim(),
					axisService.getSchematargetNamespace(), axisService
							.getSchemaTargetNamespacePrefix(), axisService);
		}
		schemaGenerator.setExcludeMethods(excludeOperations);
		schemaGenerator.setNonRpcMethods(nonRpcMethods);
		if (!axisService.isElementFormDefault()) {
			schemaGenerator
					.setElementFormDefault(Java2WSDLConstants.FORM_DEFAULT_UNQUALIFIED);
		}
		// package to namespace map
		schemaGenerator.setPkg2nsmap(axisService.getP2nMap());
		Collection schemas = schemaGenerator.generateSchema();
		axisService.addSchema(schemas);
		axisService.setSchemaTargetNamespace(schemaGenerator
				.getSchemaTargetNameSpace());
		axisService.setTypeTable(schemaGenerator.getTypeTable());
		if (Java2WSDLConstants.DEFAULT_TARGET_NAMESPACE.equals(axisService
				.getTargetNamespace())) {
			axisService
					.setTargetNamespace(schemaGenerator.getTargetNamespace());
		}

		// JMethod[] method = schemaGenerator.getMethods();
		// PhasesInfo pinfo = axisConfig.getPhasesInfo();
		//
		// for (int i = 0; i < method.length; i++) {
		// JMethod jmethod = method[i];
		// String opName = getSimpleName(jmethod);
		// AxisOperation operation = axisService
		// .getOperation(new QName(opName));
		// // if the operation there in services.xml then try to set it schema
		// // element name
		// if (operation == null) {
		// operation = axisService.getOperation(new QName(
		// getSimpleName(jmethod)));
		// }
		// MessageReceiver mr = axisService.getMessageReceiver(operation
		// .getMessageExchangePattern());
		// if (mr != null) {
		// } else {
		// mr = axisConfig.getMessageReceiver(operation
		// .getMessageExchangePattern());
		// }
		// if (operation.getMessageReceiver() == null) {
		// operation.setMessageReceiver(mr);
		// }
		// pinfo.setOperationPhases(operation);
		// axisService.addOperation(operation);
		// if (operation.getSoapAction() == null) {
		// operation.setSoapAction("urn:" + opName);
		// }
		// }
	}
	
}
