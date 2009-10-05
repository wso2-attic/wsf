/*
 * Copyright 2008 WSO2, Inc. http://www.wso2.org
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

package org.wso2.wsf.jython.deployer;

import org.apache.axis2.deployment.*;
import org.apache.axis2.deployment.repository.util.DeploymentFileData;
import org.apache.axis2.context.ConfigurationContext;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.description.*;
import org.apache.axis2.description.java2wsdl.Java2WSDLConstants;
import org.apache.axis2.AxisFault;
import org.apache.axis2.i18n.Messages;
import org.apache.axis2.wsdl.WSDLConstants;
import org.apache.ws.commons.schema.utils.NamespaceMap;
import org.apache.ws.commons.schema.XmlSchema;
import org.apache.ws.commons.schema.XmlSchemaElement;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.python.core.PySystemState;
import org.python.core.PyObject;
import org.python.util.PythonInterpreter;

import javax.xml.namespace.QName;
import java.util.*;
import java.io.*;

import org.wso2.wsf.jython.messagereceiver.PythonScriptReceiver;
import org.wso2.wsf.jython.deployer.schemagenarator.*;

public class PythonDeployer implements Deployer {
    private static final Log log = LogFactory.getLog(PythonDeployer.class);

    private AxisConfiguration axisConfig;

    protected Map schemaMap = new Hashtable();

    private ConfigurationContext configCtx;


    public void init(ConfigurationContext configCtx) {
        this.configCtx = configCtx;
        this.axisConfig = this.configCtx.getAxisConfiguration();
    }


    public void deploy(DeploymentFileData deploymentFileData) {
        StringWriter errorWriter = new StringWriter();
        String serviceStatus = "";
        try {
            String repoPath = deploymentFileData.getFile().getParentFile().getAbsolutePath();
            deploymentFileData.setClassLoader(axisConfig.getServiceClassLoader());
            AxisServiceGroup serviceGroup = new AxisServiceGroup(axisConfig);
            serviceGroup.setServiceGroupClassLoader(deploymentFileData.getClassLoader());
            ArrayList serviceList = processService(deploymentFileData, serviceGroup,
                    configCtx, repoPath);
            if (serviceList != null) {
                DeploymentEngine.addServiceGroup(serviceGroup, serviceList, deploymentFileData
                        .getFile().toURL(), deploymentFileData, axisConfig);
                log.info(Messages.getMessage(DeploymentErrorMsgs.DEPLOYING_WS, deploymentFileData
                        .getName()));
            }
        } catch (DeploymentException de) {
            de.printStackTrace();
            log.error(Messages.getMessage(DeploymentErrorMsgs.INVALID_SERVICE, deploymentFileData
                    .getName(), de.getMessage()), de);
            PrintWriter error_ptintWriter = new PrintWriter(errorWriter);
            de.printStackTrace(error_ptintWriter);
            serviceStatus = "Error:\n" + errorWriter.toString();
        } catch (AxisFault axisFault) {
            log.error(Messages.getMessage(DeploymentErrorMsgs.INVALID_SERVICE, deploymentFileData
                    .getName(), axisFault.getMessage()), axisFault);
            PrintWriter error_ptintWriter = new PrintWriter(errorWriter);
            axisFault.printStackTrace(error_ptintWriter);
            serviceStatus = "Error:\n" + errorWriter.toString();
        } catch (Exception e) {
            e.printStackTrace();
            if (log.isInfoEnabled()) {
                StringWriter sw = new StringWriter();
                PrintWriter pw = new PrintWriter(sw);
                e.printStackTrace(pw);
                log.info(Messages.getMessage(DeploymentErrorMsgs.INVALID_SERVICE,
                        deploymentFileData.getName(), sw.getBuffer().toString()));
            }
            PrintWriter error_ptintWriter = new PrintWriter(errorWriter);
            e.printStackTrace(error_ptintWriter);
            serviceStatus = "Error:\n" + errorWriter.toString();
        } catch (Throwable t) {
            t.printStackTrace();
            if (log.isInfoEnabled()) {
                StringWriter sw = new StringWriter();
                PrintWriter pw = new PrintWriter(sw);
                t.printStackTrace(pw);
                log.info(Messages.getMessage(DeploymentErrorMsgs.INVALID_SERVICE,
                        deploymentFileData.getName(), sw.getBuffer().toString()));
            }
            PrintWriter error_ptintWriter = new PrintWriter(errorWriter);
            t.printStackTrace(error_ptintWriter);
            serviceStatus = "Error:\n" + errorWriter.toString();
        } finally {
            if (serviceStatus.startsWith("Error:")) {
                axisConfig.getFaultyServices().put(deploymentFileData.getFile().getAbsolutePath(),
                        serviceStatus);
            }
        }
    }

    public ArrayList processService(DeploymentFileData currentFile,
                                    AxisServiceGroup axisServiceGroup, ConfigurationContext configCtx, String repoPath)
            throws AxisFault {
        try {
            String shortFileName = DescriptionBuilder.getShortFileName(currentFile.getName());
            String serviceName = shortFileName;
            axisServiceGroup.setServiceGroupName(currentFile.getName());
            AxisService axisService = null;
            if (log.isDebugEnabled()) {
                System.out.println(" Script Repo Path : " + repoPath);
                log.debug(shortFileName + " python script is being processed !");
                log.debug("shortFileName                :" + shortFileName);
                log.debug("currentFileName AbsolutePath :" + currentFile.getAbsolutePath());
                log.debug("currnetFileName              :" + currentFile.getName());
            }
            axisService = new AxisService();
            Parameter servicePythonParameter = new Parameter("PythonScript", currentFile.getFile());
            axisService.addParameter(servicePythonParameter);
            String targetNamespace = "http://services.mashup.wso2.org/" + serviceName;
            axisService.setParent(axisServiceGroup);
            axisService.setClassLoader(currentFile.getClassLoader());
            axisService.setName(serviceName);
            axisService.setTargetNamespace(targetNamespace);

            // adding namespaces
            NamespaceMap map2 = new NamespaceMap();
            map2.put(Java2WSDLConstants.AXIS2_NAMESPACE_PREFIX, Java2WSDLConstants.AXIS2_XSD);
            map2.put(Java2WSDLConstants.DEFAULT_SCHEMA_NAMESPACE_PREFIX,
                    Java2WSDLConstants.URI_2001_SCHEMA_XSD);
            axisService.setNameSpacesMap(map2);

            String schemaTargetNamespace = "http://services.mashup.wso2.org/" + serviceName + "?xsd";

            // setting up the schema
            MyTypes types = new MyTypes();
            SchemaGenerator schemaGenerator = new SchemaGenerator("http://foo.com", types);
            XmlSchema schema = schemaGenerator.getSchema();
            axisService.addSchema(schema);

            QName paramElementQname = new QName(schemaTargetNamespace, "PythonParameter");

            // setting the python.path variable progarmmatically
            Properties props = new Properties();
            String path = ":" + repoPath;
            props.setProperty("python.path", path);
            PythonInterpreter.initialize(System.getProperties(), props,
                    new String[]{""});
            PySystemState.initialize();
            PythonInterpreter interp = new PythonInterpreter();
            interp.exec("import sys");
            interp.exec("print sys.path");

            InputStream inpStream = Thread.currentThread().getContextClassLoader().getResourceAsStream("Processor.py");
            interp.execfile(inpStream);

            String scriptName = "import " + shortFileName;
            interp.exec(scriptName);
            //interp.exec("import Processor");
            String stt = "getDictionary(" + shortFileName + ")";
            PyObject ob1 = interp.eval(stt);

            String st2 = "dictToJavaMap(" + ob1 + ")";
            PyObject ob2 = interp.eval(st2);
            HashMap map = (HashMap) ob2.__tojava__(HashMap.class);

            annotationsToSchema(map, axisService, schemaGenerator);
            ArrayList serviceList = new ArrayList();
            serviceList.add(axisService);
            return serviceList;
        } catch (Exception e) {
            throw new DeploymentException(e);
        }
    }

    /**
     * Reads the annotations in the python script and maps the annotations to schema. Generates the xml schema for the
     * python service
     *
     * @param map             - The HashMap which contains the annotations of the python service
     * @param axisService     - The axis service
     * @param schemaGenerator - The schema generator
     */
    private void annotationsToSchema(HashMap map, AxisService axisService, SchemaGenerator schemaGenerator) {
        //HashMap map = (HashMap) obj2.__tojava__(HashMap.class);
        Iterator k = map.keySet().iterator();
        while (k.hasNext()) {
            //['returns:double', 'operationName:double', 'double', ' MyClass.multiply', ' var1:integer', ' var2:integer']
            //{'operationName': 'add','returns': 'int','var1': 'integer','var2': 'integer'}
            String key = (String) k.next();
            if (log.isDebugEnabled()) {
                log.debug("\nKey " + key + " === Value " + map.get(key));
            }

            String str = String.valueOf(map.get(key));
            str = str.substring(1, str.length() - 1);
            //create the schema for the deployed script
            HashMap hmap = new HashMap();
            String st[], stTemp[];
            st = str.split(",");
            if (log.isDebugEnabled()) {
                log.debug("\n The methods in the python script is :");
            }

            for (int i = 0; i < st.length - 1; i++) {
                if (log.isDebugEnabled()) {
                    log.debug("value " + i + " is " + st[i]);
                }
                stTemp = st[i].split("-");
                stTemp[0] = stTemp[0].replaceAll("\"", "");
                stTemp[1] = stTemp[1].replaceAll("\"", "");
                hmap.put(stTemp[0].substring(2, stTemp[0].length()), stTemp[1].substring(0, stTemp[1].length() - 1));
            }
            ComplexType inComplexType = new ComplexType();
            ComplexType outComplexType = new ComplexType();
            ComplexType innerInComplexType = new ComplexType();

            String opName = "";
            Iterator k3 = hmap.keySet().iterator();
            while (k3.hasNext()) {
                String key2 = (String) k3.next();
                if (key2.equals("operationName")) {
                    opName = (String) hmap.get(key2);
                    inComplexType.setName((String) hmap.get(key2));
                    if (log.isDebugEnabled()) {
                        log.debug("\noperation name found = = = " + opName);
                    }
                }
            }

            Iterator k2 = hmap.keySet().iterator();
            while (k2.hasNext()) {
                String key2 = (String) k2.next();
                String value2 = (String) hmap.get(key2);
                if (log.isDebugEnabled()) {
                    log.debug("\nKey2 " + key2 + " === Value " + value2);
                }

                String strTemp2[];
                boolean isInnerComplex = false;

                //Setting complex types within complex types
                if (value2.contains("~")) {
                    if (log.isDebugEnabled()) {
                        log.debug("\n\n---------Start:  an inner complex type --------------");
                        log.debug(" Inner complex type name is  ---  " + key2);
                    }
                    isInnerComplex = true;
                    innerInComplexType.setName(key2);
                    /*innerInComplexType*/
                    //Key2 var3 === Value (a=string~b=integer)~
                    // Here key2 should be the name of the complex schema type element name
                    value2 = value2.replace("(", "");
                    value2 = value2.replace(")", "");
                    strTemp2 = value2.split("~");
                    for (int i = 0; i < strTemp2.length; i++) {
                        String complexItems[] = strTemp2[i].split("=");
                        // o contains the key
                        // 1 contains the value
                        SimpleType simpleType3 = new SimpleType();
                        simpleType3.setName(complexItems[0]);
                        simpleType3.setType(complexItems[1]);
                        if (log.isDebugEnabled()) {
                            log.debug(complexItems[0] + "  ---  " + complexItems[1]);
                        }
                        innerInComplexType.addMember(simpleType3);
                    }

                    inComplexType.addMember(innerInComplexType);
                    if (log.isDebugEnabled()) {
                        log.debug("---------End : an inner complex type --------------\n\n");
                    }
                    continue;
                }

                if (key2.equals("operationName")) {
                    // there is a problem when we do like this should do another iterator to do so -- problem solved
                } else if (key2.equals("eturns")) {
                    outComplexType.setName(opName + " response ");
                    SimpleType simpleType = new SimpleType();    // return name == method response
                    simpleType.setName("returns");
                    simpleType.setType(value2);

                    outComplexType.addMember(simpleType);
                    //outComplexType.setName((String)hmap.get(key2));
                } else {
                    SimpleType simpleType2 = new SimpleType();
                    simpleType2.setName(key2);
                    simpleType2.setType(value2);

                    inComplexType.addMember(simpleType2);
                }
            }

            XmlSchemaElement inSchemaElement = null;
            XmlSchemaElement outSchemaElement = null;
            try {
                inSchemaElement = schemaGenerator.createInputElement(inComplexType, opName);
                outSchemaElement = schemaGenerator.createOutputElement(outComplexType, opName);
            } catch (Exception e) {
                e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
            }
            QName inParamElementQname = inSchemaElement.getQName(); // set this to the QName of the in message
            QName outParamElementQname = outSchemaElement.getQName();

            try {
                processOperation(axisService, inParamElementQname, outParamElementQname, opName);
            } catch (AxisFault axisFault) {
                //throw new AxisFault(axisFault.getMessage());
                axisFault.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
            }
        }
    }


    private void processOperation(AxisService axisService, QName inParamElementQname, QName outParamElementQname, String method) throws AxisFault {
        AxisOperation axisOp = new InOutAxisOperation(new QName(method));
        axisOp.setMessageReceiver(new PythonScriptReceiver());
        axisOp.setStyle(WSDLConstants.STYLE_DOC);
        Parameter parameter = new Parameter();
        parameter.setName("OPERATION_NAME");
        parameter.setValue(method);
        axisOp.addParameter(parameter);
        axisService.addOperation(axisOp);

        AxisMessage inMessage = axisOp
                .getMessage(WSDLConstants.MESSAGE_LABEL_IN_VALUE);
        if (inMessage != null) {
            // create the complex type & create a QName out of it and set it to the setElementQName of in message
            inMessage.setName(method + Java2WSDLConstants.MESSAGE_SUFFIX);
            inMessage.setElementQName(inParamElementQname);
        }
        AxisMessage outMessage = axisOp
                .getMessage(WSDLConstants.MESSAGE_LABEL_OUT_VALUE);

        if (outMessage != null) {
            outMessage.setName(method + Java2WSDLConstants.MESSAGE_SUFFIX);
            outMessage.setElementQName(outParamElementQname);
        }
        if (axisOp.getInputAction() == null) {
            axisOp.setSoapAction("urn:" + method);
        }
        axisConfig.getPhasesInfo().setOperationPhases(axisOp);
    }

    public void unDeploy(String fileName) {
        try {
            axisConfig.removeServiceGroup(fileName);
            log.info(Messages.getMessage(DeploymentErrorMsgs.SERVICE_REMOVED, fileName));
        } catch (AxisFault axisFault) {
            // May be a faulty service
            axisConfig.removeFaultyService(fileName);
        }
    }

    public void setDirectory(String s) {

    }

    public void setExtension(String s) {

    }


}
