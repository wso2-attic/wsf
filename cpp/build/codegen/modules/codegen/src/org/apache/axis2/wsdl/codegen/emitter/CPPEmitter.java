/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

package org.apache.axis2.wsdl.codegen.emitter;

import org.apache.axis2.util.JavaUtils;
import org.apache.axis2.util.PolicyUtil;
import org.apache.axis2.util.Utils;
import org.apache.axis2.wsdl.WSDLConstants;
import org.apache.axis2.wsdl.WSDLUtil;
import org.apache.axis2.description.*;
import org.apache.axis2.wsdl.SOAPHeaderMessage;
import org.apache.axis2.wsdl.codegen.CodeGenConfiguration;
import org.apache.axis2.wsdl.codegen.CodeGenerationException;
import org.apache.axis2.wsdl.codegen.writer.*;
import org.apache.axis2.wsdl.databinding.CUtils;
import org.apache.axis2.wsdl.databinding.TypeMapper;
import org.apache.axis2.wsdl.databinding.CPPTypeMapper;
import org.apache.neethi.Policy;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

import javax.xml.namespace.QName;
import java.io.File;
import java.util.*;

import com.ibm.wsdl.util.xml.DOM2Writer;

//import com.ibm.wsdl.util.xml.DOM2Writer;

public class CPPEmitter extends AxisServiceBasedMultiLanguageEmitter {
    protected static final String CPP_STUB_PREFIX = "";
    protected static final String CPP_SKEL_PREFIX = "";
     protected static final String CPP_CALLBACK_PREFIX = "I";
    protected static final String CPP_CALLBACK_SUFFIX = "Callback";
    protected static final String CPP_SVC_SKEL_PREFIX = "";
    protected static final String CPP_STUB_SUFFIX = "Stub";
    protected static final String CPP_SKEL_SUFFIX = "Skeleton";
    protected static final String CPP_SVC_SKEL_SUFFIX = "";

    protected static final String JAVA_DEFAULT_TYPE = "org.apache.axiom.om.OMElement";
    protected static final String CPP_DEFAULT_TYPE = "wso2wsf::OMElement*";

    protected static final String CPP_OUR_TYPE_PREFIX = "";
    protected static final String CPP_OUR_TYPE_SUFFIX = "";


    public CPPEmitter() {
        super();
    }

    /** @param configuration  */
    public CPPEmitter(CodeGenConfiguration configuration) {
        super();
        this.codeGenConfiguration = configuration;
        this.mapper = new CPPTypeMapper();


    }

    /**
     * @param configuration
     * @param mapper
     */
    public CPPEmitter(CodeGenConfiguration configuration, TypeMapper mapper) {
        super();
        this.codeGenConfiguration = configuration;
        this.mapper = mapper;


    }

    /**
     * Emit the stub
     *
     * @throws org.apache.axis2.wsdl.codegen.CodeGenerationException
     */
    public void emitStub() throws CodeGenerationException {

        try {
            Map originalTypeMap = getNewCopy(mapper.getAllMappedNames());
            for (Iterator axisServicesIter = this.axisServices.iterator();
                 axisServicesIter.hasNext();) {
                this.axisService = (AxisService) axisServicesIter.next();
                //we have to generate the code for each bininding
                //for the moment lets genrate the stub name with the service name and end point name
                this.axisBinding = axisService.getEndpoint(axisService.getEndpointName()).getBinding();

                Map endpoints = this.axisService.getEndpoints();
                for (Iterator endPointsIter = endpoints.values().iterator();
                     endPointsIter.hasNext();) {
                    // set the end point details.
                    this.axisEndpoint = (AxisEndpoint) endPointsIter.next();
                    this.axisBinding = this.axisEndpoint.getBinding();
                    axisService.setEndpointName(this.axisEndpoint.getName());
                    axisService.setBindingName(
                            this.axisEndpoint.getBinding().getName().getLocalPart());

                    // see the comment at updateMapperClassnames for details and reasons for
                    // calling this method
                    if (mapper.isObjectMappingPresent()) {
                        // initialize the map to original one
                        copyMap(originalTypeMap, mapper.getAllMappedNames());
                        updateMapperForStub();
                    } else {
                        copyToFaultMap();
                    }

                    //generate and populate the fault names before hand. We need that for
                    //the smooth opration of the thing
                    //first reset the fault names and recreate it
                    resetFaultNames();
                    generateAndPopulateFaultNames();
                    updateFaultPackageForStub();

                   /** Generate Code for CPP Stubs */
                   writeCPPStub();
                   writeCallback();
                   emitBuildScript();
                   writeVCProjectFile();
                }

            }

        } catch (Exception e) {
            //log the error here
            e.printStackTrace();
        }
    }



    /**
     * Emit the skeltons
     *
     * @throws org.apache.axis2.wsdl.codegen.CodeGenerationException
     */
    public void emitSkeleton() throws CodeGenerationException {
        try {
            // write skeleton
            writeCPPSkel();

            // write a Service Skeleton for this particular service.
            writeCPPServiceSkeleton();
            //create the build script
            emitBuildScript();

            writeServiceXml();
            writeVCProjectFile();

        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
    /**
     * Emit the build script
     *
     * @throws org.apache.axis2.wsdl.codegen.CodeGenerationException
     */
    public void emitBuildScript() throws CodeGenerationException {
        try {
        	writeBuildScript();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }


    /**
     * Writes the Stub.
     *
     * @throws Exception
     */
    protected void writeCPPStub() throws Exception {

        // first check for the policies in this service and write them
        Document interfaceImplModel = createDOMDocumentForInterfaceImplementation();

        CPPStubHeaderWriter writerHStub =
                new CPPStubHeaderWriter(getOutputDirectory(codeGenConfiguration.getOutputLocation(),
                                                         codeGenConfiguration.getSourceLocation()),
                                      codeGenConfiguration.getOutputLanguage());


        writeFile(interfaceImplModel, writerHStub);


        CPPStubSourceWriter writerCStub =
                new CPPStubSourceWriter(getOutputDirectory(codeGenConfiguration.getOutputLocation(),
                                                         codeGenConfiguration.getSourceLocation()),
                                      codeGenConfiguration.getOutputLanguage());

        writeFile(interfaceImplModel, writerCStub);

    }
    /**
     * Writes the Skel.
     *
     * @throws Exception
     */
    protected void writeCPPSkel() throws Exception {

        Document skeletonModel =
                createDOMDocumentForSkeleton(codeGenConfiguration.isServerSideInterface());


        CPPSkelHeaderWriter skeletonWriter = new CPPSkelHeaderWriter(
                getOutputDirectory(this.codeGenConfiguration.getOutputLocation(),
                                   codeGenConfiguration.getSourceLocation()),
                this.codeGenConfiguration.getOutputLanguage());

        writeFile(skeletonModel, skeletonWriter);

        CPPSkelSourceWriter skeletonWriterStub = new CPPSkelSourceWriter(
                getOutputDirectory(this.codeGenConfiguration.getOutputLocation(),
                                   codeGenConfiguration.getSourceLocation()),
                this.codeGenConfiguration.getOutputLanguage());

        writeFile(skeletonModel, skeletonWriterStub);
    }

    /** @throws Exception  */
    protected void writeCPPServiceSkeleton() throws Exception {

        Document skeletonModel = createDOMDocumentForServiceSkeletonXML();
        CPPSvcSkeletonHeaderWriter hwriter = new CPPSvcSkeletonHeaderWriter(
                getOutputDirectory(codeGenConfiguration.getOutputLocation(),
                                   codeGenConfiguration.getSourceLocation()),
                                   codeGenConfiguration.getOutputLanguage());
        writeFile(skeletonModel, hwriter);


        CPPSvcSkeletonWriter writer =
                new CPPSvcSkeletonWriter(getOutputDirectory(codeGenConfiguration.getOutputLocation(),
                                                          codeGenConfiguration.getSourceLocation()),
                                       codeGenConfiguration.getOutputLanguage());

        writeFile(skeletonModel, writer);

        CPPExtensionMacroWriter macroWriter = new CPPExtensionMacroWriter((getOutputDirectory(codeGenConfiguration.getOutputLocation(),
                                             codeGenConfiguration.getSourceLocation())),
                                             codeGenConfiguration.getOutputLanguage(),axisService.getName());

        writeFile(skeletonModel, macroWriter);
    }

    /**
     * Write the Bu.lsild Script
     *
     * @throws Exception
     */
    protected void writeBuildScript() throws Exception {
        if (this.codeGenConfiguration.isGenerateDeployementDescriptor()) {

            // Write the service xml in a folder with the
            Document buildXMLModel = createDOMDocumentForBuildScript(this.codeGenConfiguration);
            FileWriter buildXmlWriter =
                    new CPPBuildScriptWriter(
                            getOutputDirectory(this.codeGenConfiguration.getOutputLocation(),
                                               codeGenConfiguration.getSourceLocation()),
                            this.codeGenConfiguration.getOutputLanguage());

            writeFile(buildXMLModel, buildXmlWriter);
        }
    }

    protected void writeVCProjectFile() throws Exception{
        Document doc =  createDOMDocumentForInterfaceImplementation();
        CodeGenConfiguration codegen = this.codeGenConfiguration;
        Element rootElement = doc.getDocumentElement();
        String outputLocation = codegen.getOutputLocation().getPath();
        String  targetsourceLocation = codegen.getSourceLocation();
        addAttribute(doc,"targetsourcelocation",targetsourceLocation,rootElement);

       if(codegen.isSetoutputSourceLocation() && !outputLocation.equals(".") && !outputLocation.equals("")){
           if(!codegen.isFlattenFiles()){
                addAttribute(doc,"option","1",rootElement);
             }else{
                addAttribute(doc,"option","0",rootElement);
             }
             addAttribute(doc,"outputlocation",outputLocation,rootElement);
        }
        else
        {
            addAttribute(doc,"option","0",rootElement);
        }

        //if(codeGenConfiguration.getUri2PackageNameMap())
        addAttribute(doc, "isServer",codeGenConfiguration.isServerSide()? "1" : "0", rootElement);
        //System.out.println(DOM2Writer.nodeToString(doc));
        CPPVCProjectWriter vcProjectWriter = new CPPVCProjectWriter(
                getOutputDirectory(this.codeGenConfiguration.getOutputLocation(),
                                this.codeGenConfiguration.getSourceLocation()),
                this.codeGenConfiguration.getOutputLanguage(),axisService.getName(),this.codeGenConfiguration.isServerSide());
        writeFile(doc, vcProjectWriter);
    }

    protected void writeServiceXml() throws Exception {
        if (this.codeGenConfiguration.isGenerateDeployementDescriptor()) {

            // Write the service xml in a folder with the
            Document serviceXMLModel = createDOMDocumentForServiceXML();
            FileWriter serviceXmlWriter =
                    new CPPServiceXMLWriter(
                            getOutputDirectory(this.codeGenConfiguration.getOutputLocation(),
                                               codeGenConfiguration.getResourceLocation()),
                            this.codeGenConfiguration.getOutputLanguage());

            writeFile(serviceXMLModel, serviceXmlWriter);
//            System.out.println("Service XML Model String"+DOM2Writer.nodeToString(serviceXMLModel));
        }
    }

     protected void writeCallback() throws Exception {
         Document callbackModel = createDOMDocumentForCallback();
        CPPCallbackHeaderWriter writerCallback =
                new CPPCallbackHeaderWriter((getOutputDirectory(codeGenConfiguration.getOutputLocation(),
                                             codeGenConfiguration.getSourceLocation())),
                                             codeGenConfiguration.getOutputLanguage());

        writeFile(callbackModel, writerCallback);
//         System.out.print(DOM2Writer.nodeToString(callbackModel));
       /*
        CPPStubSourceWriter writerCStub =
                new CPPStubSourceWriter(getOutputDirectory(codeGenConfiguration.getOutputLocation(),
                                                         codeGenConfiguration.getSourceLocation()),
                                      codeGenConfiguration.getOutputLanguage());

        writeFile(interfaceImplModel, writerCStub);
        */
    }

    protected Document createDOMDocumentForCallback() {
    Document doc = getEmptyDocument();
    Element rootElement = doc.createElement("callback");

    addAttribute(doc, "cppNamespace", CUtils.makeCPPNamespace(codeGenConfiguration.getPackageName()), rootElement);
    String name ="";
    String serviceName ="";
    if(this.axisService.getEndpoints().size() > 1) {
        name  =  makeCClassName(CPP_CALLBACK_PREFIX +axisService.getName() + axisService.getEndpointName())
                + CPP_CALLBACK_SUFFIX;
        serviceName = this.axisService.getName() + this.axisService.getEndpointName();

    } else {
        name = makeCClassName(CPP_CALLBACK_PREFIX+ axisService.getName()) + CPP_CALLBACK_SUFFIX;
        serviceName = this.axisService.getName();
    }

    addAttribute(doc, "name", name, rootElement);
    addAttribute(doc, "servicename",serviceName, rootElement);
    addAttribute(doc, "caps-name",name.toUpperCase(),rootElement);

      if(codeGenConfiguration.getUri2PackageNameMap() != null)
            addAttribute(doc, "enableNS2P","yes", rootElement);
    //TODO JAXRPC mapping support should be considered here ??
    this.loadOperations(doc, rootElement, null);

    doc.appendChild(rootElement);
    return doc;
}

    /** Creates the DOM tree for implementations. */
    protected Document createDOMDocumentForInterfaceImplementation() throws Exception {

        String serviceName = axisService.getName();
        String serviceTns = axisService.getTargetNamespace();
        String serviceCName = makeCClassName(axisService.getName());

        String callbackName ="";

        if (this.axisService.getEndpoints().size() > 1) {
            callbackName  =     makeCClassName(CPP_CALLBACK_PREFIX +axisService.getName() + axisService.getEndpointName())
                        + CPP_CALLBACK_SUFFIX;
             serviceCName = makeCClassName(this.axisService.getName() + this.axisService.getEndpointName());
        } else {
            callbackName = makeCClassName(CPP_CALLBACK_PREFIX+ axisService.getName()) + CPP_CALLBACK_SUFFIX;
        }
       
        String stubName = serviceCName + CPP_STUB_SUFFIX;

        Document doc = getEmptyDocument();
        Element rootElement = doc.createElement("class");

        addAttribute(doc, "name", stubName, rootElement);
        /** Not required */
        addAttribute(doc, "caps-name", stubName.toUpperCase(), rootElement);
        addAttribute(doc, "prefix", stubName, rootElement); //prefix to be used by the functions
        addAttribute(doc, "qname", serviceName + "|" + serviceTns, rootElement);


        addAttribute(doc, "servicename", serviceCName, rootElement);
        addAttribute(doc, "cppNamespace", CUtils.makeCPPNamespace(codeGenConfiguration.getPackageName()), rootElement);

        addAttribute(doc, "namespace", serviceTns, rootElement);
        addAttribute(doc, "interfaceName", serviceCName, rootElement);
        addAttribute(doc, "callbackName", callbackName, rootElement);
        if(codeGenConfiguration.getUri2PackageNameMap() != null)
                addAttribute(doc, "enableNS2P","yes", rootElement);

        /* The following block of code is same as for the
         * AxisServiceBasedMultiLanguageEmitter createDOMDocumentForInterfaceImplementation()
         */
        // add the wrap classes flag
        if (codeGenConfiguration.isPackClasses()) {
            addAttribute(doc, "wrapped", "yes", rootElement);
        }

        // add SOAP version
        addSoapVersion(doc, rootElement);

        // add the end point
        addEndpoint(doc, rootElement);

        // set the sync/async attributes
        fillSyncAttributes(doc, rootElement);

        // ###########################################################################################
        // this block of code specifically applies to the integration of databinding code into the
        // generated classes tightly (probably as inner classes)
        // ###########################################################################################
        // check for the special models in the mapper and if they are present process them
        if (mapper.isObjectMappingPresent()) {

            // add an attribute to the root element showing that the writing has been skipped
            addAttribute(doc, "skip-write", "yes", rootElement);

            // process the mapper objects
            processModelObjects(mapper.getAllMappedObjects(), rootElement, doc);
        }

        // #############################################################################################

        // load the operations
        loadOperations(doc, rootElement, null);

        // add the databind supporters. Now the databind supporters are completly contained inside
        // the stubs implementation and not visible outside
        rootElement.appendChild(createDOMElementforDatabinders(doc, false));

        Object stubMethods;

        //if some extension has added the stub methods property, add them to the
        //main document
        if ((stubMethods = codeGenConfiguration.getProperty("stubMethods")) != null) {
            rootElement.appendChild(doc.importNode((Element)stubMethods, true));
        }

        //add another element to have the unique list of faults
        rootElement.appendChild(getUniqueListofFaults(doc));

        /////////////////////////////////////////////////////
//        System.out.print("Interface implementation document");
//         System.out.println(DOM2Writer.nodeToString(rootElement));
        /////////////////////////////////////////////////////


        doc.appendChild(rootElement);
        return doc;
    }

    protected Document createDOMDocumentForSkeleton(boolean isSkeletonInterface) {
        Document doc = getEmptyDocument();
        Element rootElement = doc.createElement("interface");

        String serviceCName = makeCClassName(axisService.getName());
        String skelName = CPP_SKEL_PREFIX + serviceCName + CPP_SKEL_SUFFIX;

        // only the name is used
        addAttribute(doc, "name", skelName, rootElement);
        addAttribute(doc, "caps-name", skelName.toUpperCase(), rootElement);
        addAttribute(doc, "cppNamespace", CUtils.makeCPPNamespace(codeGenConfiguration.getPackageName()), rootElement);
        String serviceName = axisService.getName();
        String serviceTns = axisService.getTargetNamespace();
        addAttribute(doc, "prefix", skelName, rootElement); //prefix to be used by the functions
        addAttribute(doc, "qname", serviceName + "|" + serviceTns, rootElement);

        if(codeGenConfiguration.getUri2PackageNameMap() != null)
                addAttribute(doc, "enableNS2P","yes", rootElement);
        fillSyncAttributes(doc, rootElement);
        loadOperations(doc, rootElement, null);

        //attach a list of faults
        rootElement.appendChild(getUniqueListofFaults(doc));

        doc.appendChild(rootElement);


        /////////////////////////////////////////////////////
//         System.out.println(DOM2Writer.nodeToString(rootElement));
        /////////////////////////////////////////////////////

        return doc;

    }

    protected Document createDOMDocumentForServiceSkeletonXML() {
        Document doc = getEmptyDocument();
        Element rootElement = doc.createElement("interface");

        String localPart = makeCClassName(axisService.getName());
        String svcSkelName = CPP_SVC_SKEL_PREFIX + localPart + CPP_SVC_SKEL_SUFFIX;
        String skelName = CPP_SKEL_PREFIX + localPart + CPP_SKEL_SUFFIX;

        // only the name is used
        addAttribute(doc, "name", svcSkelName, rootElement);
        addAttribute(doc, "caps-svc-name", skelName.toUpperCase(), rootElement);
        addAttribute(doc, "prefix", svcSkelName, rootElement); //prefix to be used by the functions
        String serviceName = axisService.getName();
        String serviceTns = axisService.getTargetNamespace();
        addAttribute(doc, "qname", serviceName + "|" + serviceTns, rootElement);

        addAttribute(doc, "svcname", skelName, rootElement);
        addAttribute(doc, "caps-svcname",svcSkelName.toUpperCase(), rootElement);
        addAttribute(doc, "svcop_prefix", skelName, rootElement);
        addAttribute(doc, "cppNamespace", CUtils.makeCPPNamespace(codeGenConfiguration.getPackageName()), rootElement);

        fillSyncAttributes(doc, rootElement);
        loadOperations(doc, rootElement, null);

        // add SOAP version
        addSoapVersion(doc, rootElement);

        //attach a list of faults
        rootElement.appendChild(getUniqueListofFaults(doc));
        if(codeGenConfiguration.getUri2PackageNameMap() != null)
                addAttribute(doc, "enableNS2P","yes", rootElement);
        doc.appendChild(rootElement);
        return doc;

    }

    protected Document createDOMDocumentForBuildScript(CodeGenConfiguration codegen) {
    	 Document doc = getEmptyDocument();
         Element rootElement = doc.createElement("interface");

         String serviceCName = makeCClassName(axisService.getName());
         addAttribute(doc,"isServerSide",codegen.isServerSide()?"1":"0", rootElement);
        // String skelName = C_SKEL_PREFIX + serviceCName + C_SKEL_SUFFIX;
         addAttribute(doc,"servicename",serviceCName,rootElement);
         String outputLocation = codegen.getOutputLocation().getPath();
         String  targetsourceLocation = codegen.getSourceLocation();
        addAttribute(doc,"targetsourcelocation",targetsourceLocation,rootElement);
        //if user specify a location for the source

         if(codegen.isSetoutputSourceLocation() && !outputLocation.equals(".") && !outputLocation.equals("")){
             if(!codegen.isFlattenFiles()){
                addAttribute(doc,"option","1",rootElement);
             }else{
                addAttribute(doc,"option","0",rootElement);                 
             }
             addAttribute(doc,"outputlocation",outputLocation,rootElement);
         }
        else
         {
            addAttribute(doc,"option","0",rootElement);
         }
         fillSyncAttributes(doc, rootElement);
         loadOperations(doc, rootElement, null);
         // add SOAP version
         addSoapVersion(doc, rootElement);

         //attach a list of faults
         rootElement.appendChild(getUniqueListofFaults(doc));
         if(codeGenConfiguration.getUri2PackageNameMap() != null)
                addAttribute(doc, "enableNS2P","yes", rootElement);
         doc.appendChild(rootElement);
         return doc;

    }

    /**
     * @param word
     * @return Returns character removed string.
     */
    protected String makeCClassName(String word) {
        //currently avoid only java key words and service names with '.' characters

        if (CUtils.isCKeyword(word)) {
            return CUtils.makeNonCKeyword(word);
        }
        String outWord = word.replace('.', '_');
        return outWord.replace('-', '_');
    }


    /**
     * Loads the operations
     *
     * @param doc
     * @param rootElement
     * @param mep
     * @return operations found
     */
    protected boolean loadOperations(Document doc, Element rootElement, String mep) {
        Element methodElement;
        String portTypeName = makeCClassName(axisService.getName());

        Iterator bindingOperations = this.axisBinding.getChildren();
        boolean opsFound = false;
        AxisOperation axisOperation = null;
        AxisBindingOperation axisBindingOperation = null;

        while (bindingOperations.hasNext()) {

            axisBindingOperation = (AxisBindingOperation) bindingOperations.next();
            axisOperation = axisBindingOperation.getAxisOperation();

            // populate info holder with mep information. This will used in determining which
            // message receiver to use, etc.,

            String messageExchangePattern = axisOperation.getMessageExchangePattern();
            if (infoHolder.get(messageExchangePattern) == null) {
                infoHolder.put(messageExchangePattern, Boolean.TRUE);
            }

            if (mep == null) {

                opsFound = true;

                List soapHeaderInputParameterList = new ArrayList();
                List soapHeaderOutputParameterList = new ArrayList();

                methodElement = doc.createElement("method");

                String localPart = axisOperation.getName().getLocalPart();
                String opCName = makeCClassName(localPart);
                String opNS = axisOperation.getName().getNamespaceURI();

                addAttribute(doc, "name", opCName, methodElement);
                addAttribute(doc, "caps-name", opCName.toUpperCase(), methodElement);
                addAttribute(doc, "localpart", localPart, methodElement);
                addAttribute(doc, "qname", localPart + "|" + opNS, methodElement);

                addAttribute(doc, "namespace", opNS, methodElement);
                String style = axisOperation.getStyle();
                addAttribute(doc, "style", style, methodElement);
                addAttribute(doc, "dbsupportname",
                             portTypeName + localPart + DATABINDING_SUPPORTER_NAME_SUFFIX,
                             methodElement);


                addAttribute(doc, "mep", Utils.getAxisSpecifMEPConstant(
                        axisOperation.getMessageExchangePattern()) + "", methodElement);
                addAttribute(doc, "mepURI", axisOperation.getMessageExchangePattern(),
                             methodElement);


                addSOAPAction(doc, methodElement, axisBindingOperation.getName());
                //add header ops for input
                addHeaderOperations(soapHeaderInputParameterList, axisBindingOperation, true);
                //add header ops for output
                addHeaderOperations(soapHeaderOutputParameterList, axisBindingOperation, false);

                PolicyInclude policyInclude = axisOperation.getPolicyInclude();
                Policy policy = policyInclude.getPolicy();
                if (policy != null) {
                    try {
                        addAttribute(doc, "policy", PolicyUtil.policyComponentToString(policy),
                                     methodElement);
                    } catch (Exception ex) {
                        throw new RuntimeException("can't serialize the policy to a String ", ex);
                    }
                }

                methodElement.appendChild(
                        getInputElement(doc, axisBindingOperation, soapHeaderInputParameterList));
                methodElement.appendChild(
                        getOutputElement(doc, axisBindingOperation, soapHeaderOutputParameterList));
                methodElement.appendChild(getFaultElement(doc, axisOperation));

                rootElement.appendChild(methodElement);
            } else {
                //mep is present - we move ahead only if the given mep matches the mep of this operation

                if (mep.equals(axisOperation.getMessageExchangePattern())) {
                    //at this point we know it's true
                    opsFound = true;
                    List soapHeaderInputParameterList = new ArrayList();
                    List soapHeaderOutputParameterList = new ArrayList();
                    List soapHeaderFaultParameterList = new ArrayList();
                    methodElement = doc.createElement("method");
                    String localPart = axisOperation.getName().getLocalPart();
                    String opCName = makeCClassName(localPart);
                    String opNS = axisOperation.getName().getNamespaceURI();

                    addAttribute(doc, "name", opCName, methodElement);
                    addAttribute(doc, "caps-name", opCName.toUpperCase(), methodElement);
                    addAttribute(doc, "localpart", localPart, methodElement);
                    addAttribute(doc, "qname", localPart + "|" + opNS, methodElement);

                    addAttribute(doc, "namespace", axisOperation.getName().getNamespaceURI(),
                                 methodElement);
                    addAttribute(doc, "style", axisOperation.getStyle(), methodElement);
                    addAttribute(doc, "dbsupportname",
                                 portTypeName + localPart + DATABINDING_SUPPORTER_NAME_SUFFIX,
                                 methodElement);

                    addAttribute(doc, "mep", Utils.getAxisSpecifMEPConstant(
                            axisOperation.getMessageExchangePattern()) + "", methodElement);
                    addAttribute(doc, "mepURI", axisOperation.getMessageExchangePattern(),
                                 methodElement);


                    addSOAPAction(doc, methodElement, axisBindingOperation.getName());
                    addHeaderOperations(soapHeaderInputParameterList, axisBindingOperation, true);
                    addHeaderOperations(soapHeaderOutputParameterList, axisBindingOperation, false);

                    /*
                     * Setting the policy of the operation
                     */

                    Policy policy = axisOperation.getPolicyInclude().getPolicy();
                    if (policy != null) {
                        try {
                            addAttribute(doc, "policy",
                                         PolicyUtil.policyComponentToString(policy),
                                         methodElement);
                        } catch (Exception ex) {
                            throw new RuntimeException("can't serialize the policy to a String",
                                                       ex);
                        }
                    }


                    methodElement.appendChild(getInputElement(doc,
                                                              axisBindingOperation,
                                                              soapHeaderInputParameterList));
                    methodElement.appendChild(getOutputElement(doc,
                                                               axisBindingOperation,
                                                               soapHeaderOutputParameterList));
                    methodElement.appendChild(getFaultElement(doc,
                                                              axisOperation));
                    rootElement.appendChild(methodElement);

                }

            }

        }

        return opsFound;
    }


    /**
     * A convenient method for the generating the parameter element
     *
     * @param doc
     * @param paramName
     * @param paramType
     * @param opName
     * @param paramName
     */
    protected Element generateParamComponent(Document doc,
                                             String paramName,
                                             String paramType,
                                             QName opName,
                                             QName paramQName,
                                             String partName,
                                             boolean isPrimitive,
                                             boolean isArray) {

        Element paramElement = doc.createElement("param");
        //return paramElement;/*
        addAttribute(doc, "name",
                     paramName, paramElement);

        String typeMappingStr = (paramType == null)
                ? ""
                : paramType;


        if (JAVA_DEFAULT_TYPE.equals(typeMappingStr)) {
            typeMappingStr = CPP_DEFAULT_TYPE;
        }

        String filename = typeMappingStr.replace( "::", "_" );


        addAttribute(doc, "filename", filename, paramElement);


        addAttribute(doc, "type", typeMappingStr, paramElement);
        //adds the short type
        addShortType(paramElement, (paramQName == null) ? null : paramQName.getLocalPart());

        addAttribute(doc, "caps-type", typeMappingStr.toUpperCase(), paramElement);

        // add an extra attribute to say whether the type mapping is the default
        if (mapper.getDefaultMappingName().equals(paramType)) {
            addAttribute(doc, "default", "yes", paramElement);
        }
        addAttribute(doc, "value", getParamInitializer(paramType), paramElement);
        // add this as a body parameter
        addAttribute(doc, "location", "body", paramElement);

        //if the opName and partName are present , add them
        if (opName != null) {
            addAttribute(doc, "opname", opName.getLocalPart(), paramElement);

        }

        if (paramQName != null) {
            Element qNameElement = doc.createElement("qname");
            addAttribute(doc, "nsuri", paramQName.getNamespaceURI(), qNameElement);
            addAttribute(doc, "localname", paramQName.getLocalPart(), qNameElement);
            paramElement.appendChild(qNameElement);
        }

        if (partName != null) {
            addAttribute(doc, "partname",
                         JavaUtils.capitalizeFirstChar(partName),
                         paramElement);
        }

        if (isPrimitive) {
            addAttribute(doc, "primitive", "yes", paramElement);
        }

        if (isArray) {
            addAttribute(doc, "array", "yes", paramElement);
        }

        // the new trick to identify adb types
        boolean isOurs = true;

        if (typeMappingStr.length() != 0 && !typeMappingStr.equals("void") &&
                !typeMappingStr.equals(CPP_DEFAULT_TYPE) && typeMappingStr.contains("::") && !typeMappingStr.contains("std::string")) {
            addAttribute(doc, "ours", "yes", paramElement);


            isOurs = true;
        } else {
            isOurs = false;
        }

        if (isOurs) {
            typeMappingStr = CPP_OUR_TYPE_PREFIX + typeMappingStr + CPP_OUR_TYPE_SUFFIX;
        }

        addAttribute(doc, "axis2-type", typeMappingStr, paramElement);
        addAttribute(doc, "axis2-caps-type", typeMappingStr.toUpperCase(), paramElement);

        return paramElement;  //*/
    }

    /**
     * @param doc
     * @param operation
     * @param param
     */
    protected void addCSpecifcAttributes(Document doc, AxisOperation operation, Element param,
                                         String messageType) {
        String typeMappingStr;
        AxisMessage message;

        if (messageType.equals(WSDLConstants.MESSAGE_LABEL_IN_VALUE))
            message = operation.getMessage(WSDLConstants.MESSAGE_LABEL_IN_VALUE);
        else
            message = operation.getMessage(WSDLConstants.MESSAGE_LABEL_OUT_VALUE);

        QName typeMapping = message.getElementQName();

        String paramType = this.mapper.getTypeMappingName(message.getElementQName());
        if (doc == null || paramType == null || param == null) {
            return;
        }

        if (message != null) {
            String type = this.mapper.getTypeMappingName(message.getElementQName());
            typeMappingStr = (type == null)
                    ? ""
                    : type;
        } else {
            typeMappingStr = "";
        }


        addAttribute(doc, "caps-type", paramType.toUpperCase(), param);
        addAttribute(doc, "type", paramType, param);


String filename = paramType.replace( "::", "_" );


        addAttribute(doc, "filename", filename, param);




        if (!paramType.equals("") && !paramType.equals("void") &&
                !typeMappingStr.equals(CPP_DEFAULT_TYPE) && typeMappingStr.contains("::") && !typeMappingStr.contains("std::string") ) {
            addAttribute(doc, "ours", "yes", param);
        }

    }

    /**
     * @param doc
     * @param operation
     * @return Returns the parameter element.
     */
    protected Element[] getInputParamElement(Document doc, AxisOperation operation) {
        Element[] param = super.getInputParamElement(doc, operation);
        for (int i = 0; i < param.length; i++) {
            addCSpecifcAttributes(doc, operation, param[i], WSDLConstants.MESSAGE_LABEL_IN_VALUE);
        }

        return param;
    }

    /**
     * @param doc
     * @param operation
     * @return Returns Element.
     */
    protected Element getOutputParamElement(Document doc, AxisOperation operation) {
        Element param = super.getOutputParamElement(doc, operation);
        addCSpecifcAttributes(doc, operation, param, WSDLConstants.MESSAGE_LABEL_OUT_VALUE);

        return param;
    }

    /**
     * Gets the output directory for source files.
     *
     * @param outputDir
     * @return Returns File.
     */
    protected File getOutputDirectory(File outputDir, String dir2) {
        if (dir2 != null && !"".equals(dir2)) {
            if (outputDir.getName().equals(".")) {
                outputDir = new File(outputDir, dir2);
            }
        }

        if (!outputDir.exists()) {
            outputDir.mkdirs();
        }

        return outputDir;
    }

    /**
     * @param doc
     * @param parameters
     * @param location
     */
    protected List getParameterElementList(Document doc, List parameters, String location) {
        List parameterElementList = new ArrayList();

        if ((parameters != null) && !parameters.isEmpty()) {
            int count = parameters.size();

            for (int i = 0; i < count; i++) {
                Element param = doc.createElement("param");
                SOAPHeaderMessage header = (SOAPHeaderMessage) parameters.get(i);
                QName name = header.getElement();

                addAttribute(doc, "name", this.mapper.getParameterName(name), param);

                String typeMapping = this.mapper.getTypeMappingName(name);
                String typeMappingStr = (typeMapping == null)
                        ? ""
                        : typeMapping;

                addAttribute(doc, "type", typeMappingStr, param);
                
String filename = typeMappingStr.replace( "::", "_" );


        addAttribute(doc, "filename", filename, param);
                
                
                
                addAttribute(doc, "location", location, param);
                if (header.isMustUnderstand()) {
                    addAttribute(doc, "mustUnderstand", "true", param);
                }

                if (name != null) {
                    Element qNameElement = doc.createElement("qname");
                    addAttribute(doc, "nsuri", name.getNamespaceURI(), qNameElement);
                    addAttribute(doc, "localname", name.getLocalPart(), qNameElement);
                    param.appendChild(qNameElement);
                }
                parameterElementList.add(param);

                // the new trick to identify adb types
                boolean isOurs = true;

                if (typeMappingStr.length() != 0 && !typeMappingStr.equals("void") &&
                        !typeMappingStr.equals(CPP_DEFAULT_TYPE) && typeMappingStr.contains("::") && !typeMappingStr.contains("std::string")) {
                    addAttribute(doc, "ours", "yes", param);
                    isOurs = true;
                } else {
                    isOurs = false;
                }

                if (isOurs) {
                    typeMappingStr = CPP_OUR_TYPE_PREFIX + typeMappingStr + CPP_OUR_TYPE_SUFFIX;
                }

                addAttribute(doc, "axis2-type", typeMappingStr, param);

            }
        }
        return parameterElementList;
    }

    /**
     * A util method that returns a unique list of faults for a given mep
     *
     * @param doc
     * @return DOM element
     */
    protected Element getUniqueListofFaultsofMep(Document doc, String mep) {

        //  list to keep fault message qnames for this mep
        Set faultListForMep = new HashSet();

        Iterator iter = this.axisService.getOperations();
        AxisOperation axisOperation;

        for (; iter.hasNext();) {
            axisOperation = (AxisOperation) iter.next();
            if (mep == null) {
                // add the fault messages
                addFaultMessages(axisOperation.getFaultMessages(), faultListForMep);
            } else {
                if (mep.equals(axisOperation.getMessageExchangePattern())) {
                    // add the fault messages
                    addFaultMessages(axisOperation.getFaultMessages(), faultListForMep);
                }
            }
        }

        Element rootElement = doc.createElement("fault-list");
        Element faultElement;
        String key;
        Iterator iterator = faultListForMep.iterator();
        while (iterator.hasNext()) {
            faultElement = doc.createElement("fault");
            key = (String) iterator.next();

            //as for the name of a fault, we generate an exception
            addAttribute(doc, "name",
                    (String) fullyQualifiedFaultClassNameMap.get(key),
                    faultElement);
            addAttribute(doc, "shortName",
                    (String) faultClassNameMap.get(key),
                    faultElement);

            //the type represents the type that will be wrapped by this
            //name
            String typeMapping =
                    this.mapper.getTypeMappingName((QName) faultElementQNameMap.get(key));
            addAttribute(doc, "type", (typeMapping == null)
                    ? ""
                    : typeMapping, faultElement);
            String attribValue = (String) instantiatableMessageClassNames.
                    get(key);

            addAttribute(doc, "instantiatableType",
                    attribValue == null ? "" : attribValue,
                    faultElement);

            String exceptionName = ((QName) faultElementQNameMap.get(key)).getLocalPart();
            addAttribute(doc, "localname",
                    exceptionName == null ? "" : exceptionName,
                    faultElement);

            addAttribute(doc, "caps-localname",
                    exceptionName == null ? "" : exceptionName.toUpperCase(),
                    faultElement);

            // add an extra attribute to say whether the type mapping is
            // the default
            if (mapper.getDefaultMappingName().equals(typeMapping)) {
                addAttribute(doc, "default", "yes", faultElement);
            }
            addAttribute(doc, "value", getParamInitializer(typeMapping),
                    faultElement);

            rootElement.appendChild(faultElement);
        }
        return rootElement;
    }


    /**
     * @param doc
     * @param operation
     * @return Returns the parameter element.
     */
    protected Element[] getFaultParamElements(Document doc, AxisOperation operation) {
        ArrayList params = new ArrayList();
        ArrayList faultMessages = operation.getFaultMessages();

        if (faultMessages != null && !faultMessages.isEmpty()) {
            Element paramElement;
            AxisMessage msg;
            for (int i = 0; i < faultMessages.size(); i++) {
                paramElement = doc.createElement("param");
                msg = (AxisMessage) faultMessages.get(i);

                if (msg.getElementQName() == null) {
                    throw new RuntimeException("Element QName is null for " + msg.getName() + "!");
                }

                //as for the name of a fault, we generate an exception
                String faultComment = "";
                if (msg.getDocumentation() != null){
                    faultComment = msg.getDocumentation().trim();
                }
                addAttribute(doc, "comment", faultComment, paramElement);
                addAttribute(doc, "name",
                        (String) fullyQualifiedFaultClassNameMap.get(msg.getName()),
                        paramElement);
                addAttribute(doc, "shortName",
                        (String) faultClassNameMap.get(msg.getName()),
                        paramElement);

                // attach the namespace and the localName
                addAttribute(doc, "namespace",
                        msg.getElementQName().getNamespaceURI(),
                        paramElement);
                addAttribute(doc, "localname",
                        msg.getElementQName().getLocalPart(),
                        paramElement);
                addAttribute(doc, "caps-localname",
                        msg.getElementQName().getLocalPart().toUpperCase(),
                        paramElement);

                if (msg.getElementQName() != null) {
                    Element qNameElement = doc.createElement("qname");
                    addAttribute(doc, "nsuri", msg.getElementQName().getNamespaceURI(), qNameElement);
                    addAttribute(doc, "localname", msg.getElementQName().getLocalPart(), qNameElement);
                    paramElement.appendChild(qNameElement);
                }
                //the type represents the type that will be wrapped by this
                //name
                String typeMapping =
                        this.mapper.getTypeMappingName(msg.getElementQName());
                addAttribute(doc, "type", (typeMapping == null)
                        ? ""
                        : typeMapping, paramElement);
String filename = typeMapping.replace( "::", "_" );


        addAttribute(doc, "filename", filename, paramElement);



                //add the short name
                addShortType(paramElement, (msg.getElementQName() == null) ? null :
                        msg.getElementQName().getLocalPart());

                String attribValue = (String) instantiatableMessageClassNames.
                        get(msg.getElementQName());
                addAttribute(doc, "instantiatableType",
                        attribValue == null ? "" : attribValue,
                        paramElement);

                // add an extra attribute to say whether the type mapping is
                // the default
                if (mapper.getDefaultMappingName().equals(typeMapping)) {
                    addAttribute(doc, "default", "yes", paramElement);
                }
                addAttribute(doc, "value", getParamInitializer(typeMapping),
                        paramElement);

                Iterator iter = msg.getExtensibilityAttributes().iterator();
                while (iter.hasNext()) {
                    // process extensibility attributes
                }
                params.add(paramElement);
            }

            return (Element[]) params.toArray(new Element[params.size()]);
        } else {
            return new Element[]{};//return empty array
        }


    }

    /**
     * Finds the output element.
     *
     * @param doc
     * @param bindingOperation
     * @param headerParameterQNameList
     */
    protected Element getOutputElement(Document doc,
                                       AxisBindingOperation bindingOperation,
                                       List headerParameterQNameList) {
        AxisOperation operation = bindingOperation.getAxisOperation();
        Element outputElt = doc.createElement("output");
        String mep = operation.getMessageExchangePattern();


        if (WSDLUtil.isOutputPresentForMEP(mep)) {

            Element param = getOutputParamElement(doc, operation);

            if (param != null) {
                outputElt.appendChild(param);
            }

            List outputElementList = getParameterElementList(doc, headerParameterQNameList,
                    WSDLConstants.SOAP_HEADER);
            outputElementList.addAll(getParameterElementListForHttpHeader(doc,
                    (ArrayList) getBindingPropertyFromMessage(
                            WSDL2Constants.ATTR_WHTTP_HEADER,
                            operation.getName(),
                            WSDLConstants.WSDL_MESSAGE_DIRECTION_OUT),
                    WSDLConstants.HTTP_HEADER));

            for (int i = 0; i < outputElementList.size(); i++) {
                outputElt.appendChild((Element) outputElementList.get(i));
            }

            /*
            * Setting the effective policy for the output message.
            */
            Policy policy = getBindingPolicyFromMessage(bindingOperation,
                    WSDLConstants.WSDL_MESSAGE_DIRECTION_OUT);

            if (policy != null) {
                try {
                    addAttribute(doc, "policy",
                            PolicyUtil.getSafeString(PolicyUtil.policyComponentToString(policy)),
                            outputElt);
                } catch (Exception ex) {
                    throw new RuntimeException("can't serialize the policy ..");
                }
            }
        }
        return outputElt;
    }

    /**
     * Get the input element
     *
     * @param doc
     * @param bindingOperation
     * @param headerParameterQNameList
     * @return DOM element
     */
    protected Element getInputElement(Document doc,
                                      AxisBindingOperation bindingOperation,
                                      List headerParameterQNameList) {
        AxisOperation operation = bindingOperation.getAxisOperation();
        Element inputElt = doc.createElement("input");
        String mep = operation.getMessageExchangePattern();

        if (WSDLUtil.isInputPresentForMEP(mep)) {

            Element[] param = getInputParamElement(doc, operation);
            for (int i = 0; i < param.length; i++) {
                inputElt.appendChild(param[i]);
            }

            List parameterElementList = getParameterElementList(doc, headerParameterQNameList,
                    WSDLConstants.SOAP_HEADER);
            parameterElementList.addAll(getParameterElementListForHttpHeader(doc,
                    (ArrayList) getBindingPropertyFromMessage(
                            WSDL2Constants.ATTR_WHTTP_HEADER,
                            operation.getName(),
                            WSDLConstants.WSDL_MESSAGE_DIRECTION_IN),
                    WSDLConstants.HTTP_HEADER));
            parameterElementList.addAll(getParameterElementListForSOAPModules(doc,
                    (ArrayList) getBindingPropertyFromMessage(
                            WSDL2Constants.ATTR_WSOAP_MODULE,
                            operation.getName(),
                            WSDLConstants.WSDL_MESSAGE_DIRECTION_IN)));

            for (int i = 0; i < parameterElementList.size(); i++) {
                inputElt.appendChild((Element) parameterElementList.get(i));
            }

            /*
            * Setting the effective policy of input message
            */
            Policy policy = getBindingPolicyFromMessage(bindingOperation,
                    WSDLConstants.WSDL_MESSAGE_DIRECTION_IN);

            if (policy != null) {
                try {
                    addAttribute(doc, "policy",
                            PolicyUtil.getSafeString(PolicyUtil.policyComponentToString(policy)),
                            inputElt);
                } catch (Exception ex) {
                    throw new RuntimeException("can't serialize the policy ..");
                }
            }

        }
        //System.out.println(DOM2Writer.nodeToString(inputElt));
        return inputElt;
    }

}
