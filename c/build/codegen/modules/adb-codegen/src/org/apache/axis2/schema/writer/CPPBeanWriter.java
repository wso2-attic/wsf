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

package org.apache.axis2.schema.writer;

import org.apache.axis2.schema.BeanWriterMetaInfoHolder;
import org.apache.axis2.schema.CompilerOptions;
import org.apache.axis2.schema.SchemaCompilationException;
import org.apache.axis2.schema.SchemaConstants;
import org.apache.axis2.schema.i18n.SchemaCompilerMessages;
import org.apache.axis2.schema.typemap.JavaTypeMap;
import org.apache.axis2.schema.util.PrimitiveTypeFinder;
import org.apache.axis2.schema.util.SchemaPropertyLoader;
import org.apache.axis2.util.JavaUtils;
import org.apache.axis2.util.XSLTTemplateProcessor;
import org.apache.axis2.util.XSLTUtils;
import org.apache.axis2.util.URLProcessor;
import org.apache.axis2.wsdl.databinding.CUtils;
import org.apache.ws.commons.schema.XmlSchemaElement;
import org.apache.ws.commons.schema.XmlSchemaSimpleType;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

import javax.xml.namespace.QName;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Templates;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.stream.StreamSource;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import com.ibm.wsdl.util.xml.DOM2Writer;

//import com.ibm.wsdl.util.xml.DOM2Writer;

/**
 * Java Bean writer for the schema compiler.
 */
public class CPPBeanWriter implements BeanWriter {

    public static final String WRAPPED_DATABINDING_CLASS_NAME = "WrappedDatabinder";
    public static final String AXIS2_PREFIX = "";
    private String javaBeanTemplateName = null;
    private boolean templateLoaded = false;
    private Templates sourceTemplateCache;
    private Templates headerTemplateCache;

    private List namesList;
    private static int count = 0;
    private boolean wrapClasses = false;
    private boolean writeClasses = false;

    protected File rootDir;

    private Document globalWrappedSourceDocument;
    private Document globalWrappedHeaderDocument;

    private Map modelMap = new HashMap();
    private static final String ADB_CLASS_PREFIX = "";
    private static final String ADB_CLASS_POSTFIX = "";
    private static final String DEFAULT_CPP_CLASS_NAME = "wso2wsf::OMElement*";

    private Map baseTypeMap = new JavaTypeMap().getTypeMap();

    private Map ns2packageNameMap = new HashMap();
    boolean enableNS2P = false;

    private Map cppNamespacesToClassnamesMap = new HashMap();

    private String cppNamespace;

    String packageName;

    // a list of externally identified QNames to be processed. This becomes
    // useful when  only a list of external elements need to be processed

    public static final String DEFAULT_CLASS_NAME = "wso2wsf::OMElement*";
    public static final String DEFAULT_CLASS_ARRAY_NAME = "wso2wsf::OMElement*";

    public static final String DEFAULT_ATTRIB_CLASS_NAME = "wso2wsf::OMAttribute*";
    public static final String DEFAULT_ATTRIB_ARRAY_CLASS_NAME = "wso2wsf::OMAttribute*";

    public static final String DEFAULT_TYPE_NS = "http://www.w3.org/2001/XMLSchema";

    private static final String DEFAULT_CPP_NAMESPACE = "adb";

    /**
     * Default constructor
     */
    public CPPBeanWriter() {
    }

    /**
     * This returns a map of Qnames vs DOMDocument models. One can use this method to
     * obtain the raw DOMmodels used to write the classes.
     * This has no meaning when the classes are supposed to be wrapped  so the
     *
     * @return Returns Map.
     * @see org.apache.axis2.schema.writer.BeanWriter#getModelMap()
     */
    public Map getModelMap() {
        return modelMap;
    }

    public String getDefaultClassName() {
        return DEFAULT_CLASS_NAME;
    }

    public String getDefaultClassArrayName() {
        return DEFAULT_CLASS_ARRAY_NAME;
    }

    public String getDefaultAttribClassName() {
        return DEFAULT_ATTRIB_CLASS_NAME;
    }

    public String getDefaultAttribArrayClassName() {
        return DEFAULT_ATTRIB_ARRAY_CLASS_NAME;
    }
    public void init(CompilerOptions options) throws SchemaCompilationException {
        try {
            initWithFile(options.getOutputLocation());
            packageName = options.getPackageName();
            ns2packageNameMap = options.getNs2PackageMap();
            if(options.getNs2PackageMap() != null)
                enableNS2P = true;

            writeClasses = options.isWriteOutput();
            //packageName = options.getPackageName();
            
            if (!writeClasses) {
                wrapClasses = false;
            } else {
                wrapClasses = options.isWrapClasses();
            }

            //if the wrap mode is set then create a global document to keep the wrapped
            //element models
            if (options.isWrapClasses()) {
                globalWrappedSourceDocument = XSLTUtils.getDocument();
                Element rootElement = XSLTUtils.getElement(globalWrappedSourceDocument, "beans");
                globalWrappedSourceDocument.appendChild(rootElement);
                XSLTUtils.addAttribute(globalWrappedSourceDocument, "name", CPPBeanWriter.WRAPPED_DATABINDING_CLASS_NAME, rootElement);

                globalWrappedHeaderDocument = XSLTUtils.getDocument();
                rootElement = XSLTUtils.getElement(globalWrappedHeaderDocument, "beans");
                globalWrappedHeaderDocument.appendChild(rootElement);
                XSLTUtils.addAttribute(globalWrappedHeaderDocument, "name", CPPBeanWriter.WRAPPED_DATABINDING_CLASS_NAME, rootElement);
//                String tempPackageName;
//
//                if (packageName != null && packageName.endsWith(".")) {
//                    tempPackageName = this.packageName.substring(0,
//                            this.packageName.lastIndexOf("."));
//                } else {
//                    tempPackageName = DEFAULT_CPP_NAMESPACE;
//                }
//
//               XSLTUtils.addAttribute(globalWrappedHeaderDocument, "package", CUtils.makeCPPNamespace(tempPackageName), rootElement);
//               XSLTUtils.addAttribute(globalWrappedSourceDocument,"package", CUtils.makeCPPNamespace(tempPackageName), rootElement);

            }


        } catch (IOException e) {
            throw new SchemaCompilationException(e);
        } catch (ParserConfigurationException e) {
            throw new SchemaCompilationException(e); //todo need to put correct error messages
        }
    }

    /**
     * @param element
     * @param typeMap
     * @param metainf
     * @return Returns String.
     * @throws org.apache.axis2.schema.SchemaCompilationException
     *
     */
    public String write(XmlSchemaElement element,
                        Map typeMap,
                        Map groupTypeMap,
                        BeanWriterMetaInfoHolder metainf) throws SchemaCompilationException {

        try {
            QName qName = element.getQName();

            return process(qName, metainf, typeMap, groupTypeMap, true, false);
        } catch (Exception e) {
            throw new SchemaCompilationException(e);
        }


    }

    /**
     * @param qName
     * @param typeMap
     * @param metainf
     * @param isAbstract
     * @throws org.apache.axis2.schema.SchemaCompilationException
     *
     * @see BeanWriter
     */
    public String write(QName qName,
                        Map typeMap,
                        Map groupTypeMap,
                        BeanWriterMetaInfoHolder metainf,
                        boolean isAbstract)
            throws SchemaCompilationException {

        try {
            //determine the package for this type.
            return process(qName, metainf, typeMap, groupTypeMap, false, isAbstract);

        } catch (SchemaCompilationException e) {
            throw e;
        } catch (Exception e) {
            throw new SchemaCompilationException(e);
        }


    }

    /**
     * @throws org.apache.axis2.schema.SchemaCompilationException
     * @see BeanWriter#writeBatch()
     */
    public void writeBatch() throws SchemaCompilationException {
        try {
            if (wrapClasses) {

                File outSource = createOutFile(CPPBeanWriter.WRAPPED_DATABINDING_CLASS_NAME, ".cpp");
                File outHeader = createOutFile(CPPBeanWriter.WRAPPED_DATABINDING_CLASS_NAME, ".h");
                //parse with the template and create the files
                parseSource(globalWrappedSourceDocument, outSource);
                parseHeader(globalWrappedHeaderDocument, outHeader);
            }
        } catch (Exception e) {
            throw new SchemaCompilationException(e);
        }
    }

    /**
     * @param simpleType
     * @param typeMap
     * @param metainf
     * @return Returns String.
     * @throws org.apache.axis2.schema.SchemaCompilationException
     *
     */
    public String write(XmlSchemaSimpleType simpleType,
                        Map typeMap,
                        Map groupTypeMap,
                        BeanWriterMetaInfoHolder metainf) throws SchemaCompilationException {
        try {
            //determine the package for this type.
            QName qName = simpleType.getQName();
            if (qName == null) {
                qName = (QName) simpleType.getMetaInfoMap().get(SchemaConstants.SchemaCompilerInfoHolder.FAKE_QNAME);
            }
            metainf.addtStatus(qName, SchemaConstants.SIMPLE_TYPE_OR_CONTENT);
            return process(qName, metainf, typeMap, groupTypeMap, true, false);

        } catch (SchemaCompilationException e) {
            throw e;
        } catch (Exception e) {
            throw new SchemaCompilationException(e);
        }
    }

    /**
     * @param rootDir
     * @throws java.io.IOException
     * @see BeanWriter
     */
    private void initWithFile(File rootDir) throws IOException {
        if (rootDir == null) {
            this.rootDir = new File(".");
        } else if (!rootDir.isDirectory()) {
            throw new IOException(SchemaCompilerMessages.getMessage("schema.rootnotfolderexception"));
        } else {
            this.rootDir = rootDir;
        }

        namesList = new ArrayList();
        javaBeanTemplateName = SchemaPropertyLoader.getBeanTemplate();
    }


        private String getPackage(String namespaceURI) {
        String basePackageName;
        if ((ns2packageNameMap != null) && ns2packageNameMap.containsKey(namespaceURI)) {
            basePackageName = (String) ns2packageNameMap.get(namespaceURI);
        } else {
            basePackageName = URLProcessor.makePackageName(namespaceURI);
        }

        return this.packageName == null ? basePackageName
                : this.packageName + basePackageName;
    }

    /**
     * Make the fully qualified class name for an element or named type
     *
     * @param qName the qualified Name for this element or type in the schema
     * @return the appropriate fully qualified class name to use in generated code
     */
    public String makeFullyQualifiedClassName(QName qName) {

        String originalName = qName.getLocalPart();
        String packageName = this.packageName;
        
        if(packageName == null){
            packageName = getPackage(qName.getNamespaceURI());
        }
        
        String cppNamespace = CUtils.makeCPPNamespace(packageName);
        String className = null;
        String fullyQualifiedClassName =null;
        String classPrefix= null;

        if(!wrapClasses){
              className = makeUniqueCPPClassName(this.namesList, originalName);
        }else{
            if (!this.cppNamespacesToClassnamesMap.containsKey(cppNamespace)) {
                    this.cppNamespacesToClassnamesMap.put(cppNamespace, new ArrayList());
            }
            className = makeUniqueCPPClassName((List) this.cppNamespacesToClassnamesMap.get(cppNamespace), originalName);
        }

         if (wrapClasses){
            classPrefix = (cppNamespace == null ? DEFAULT_CPP_NAMESPACE + "::"
                    : cppNamespace)
                    + WRAPPED_DATABINDING_CLASS_NAME;
         }
        else if (writeClasses){
            classPrefix = cppNamespace;
         }

        if (classPrefix != null)
            fullyQualifiedClassName = classPrefix + (classPrefix.endsWith("::") ? "" : "::") + className;
        else
            fullyQualifiedClassName = className;

        return  fullyQualifiedClassName;
    }

    /**
     * A util method that holds common code
     * for the complete schema that the generated XML complies to
     * look under other/beanGenerationSchema.xsd
     *
     * @param qName
     * @param metainf
     * @param typeMap
     * @param isElement
     * @return Returns String.
     * @throws Exception
     */
    private String process(QName qName,
                        BeanWriterMetaInfoHolder metainf,
                        Map typeMap,
                        Map groupTypeMap,
                        boolean isElement,
                        boolean isAbstract)
            throws Exception {
        String fullyQualifiedClassName = metainf.getOwnClassName();
        if (fullyQualifiedClassName == null)
            fullyQualifiedClassName = makeFullyQualifiedClassName(qName);

        String cppNamespace = null;

        String className = fullyQualifiedClassName
                .substring(1 + fullyQualifiedClassName.lastIndexOf(':'));

        if (fullyQualifiedClassName.lastIndexOf(':') == -1) {// no ':' so namespace
            // the package
            // is not there
            cppNamespace = "";
        } else {
            cppNamespace = fullyQualifiedClassName.substring(0,
                    fullyQualifiedClassName.indexOf(':'));
        }

       String originalName = qName == null? "" : qName.getLocalPart();
        ArrayList propertyNames = new ArrayList();

        if (!templateLoaded) {
            loadTemplate();
        }

        //if wrapped then do not write the classes now but add the models to a global document. However in order to write the
        //global class that is generated, one needs to call the writeBatch() method
        if (wrapClasses) {
            globalWrappedSourceDocument.getDocumentElement().appendChild(
                    getBeanElement(globalWrappedSourceDocument, className,
                        originalName, cppNamespace,qName, isElement, isAbstract,
                        metainf, propertyNames, typeMap, groupTypeMap));

            globalWrappedHeaderDocument.getDocumentElement().appendChild(
                    getBeanElement(globalWrappedHeaderDocument, className,
                        originalName, cppNamespace,qName, isElement, isAbstract,
                        metainf, propertyNames, typeMap, groupTypeMap));

        } else {
            //create the model
            Document modelSource = XSLTUtils.getDocument();
            Document modelHeader = XSLTUtils.getDocument();
            //make the XML
            modelSource.appendChild(getBeanElement(modelSource, className, originalName, cppNamespace,
                    qName, isElement, isAbstract, metainf, propertyNames,
                    typeMap, groupTypeMap));
            modelHeader.appendChild(getBeanElement(modelHeader, className, originalName, cppNamespace,
                    qName, isElement, isAbstract, metainf, propertyNames,
                    typeMap, groupTypeMap));

            if (writeClasses) {
                //create the file
                //String fileName = className.substring(0, className.length() -1);
                
                String fileName;
                
                if ( cppNamespace != "" && enableNS2P)
                {
                  fileName = cppNamespace + "_" + className;
                }
                else
                {
                  fileName = className;                
                }

                File outSource = createOutFile(fileName, ".cpp");
                File outHeader = createOutFile(fileName, ".h");
                //parse with the template and create the files
                parseSource(modelSource, outSource);
                parseHeader(modelHeader, outHeader);
            }

            //add the model to the model map
            modelMap.put(
                    new QName(qName.getNamespaceURI(), className)
                    , modelSource);
            modelMap.put(
                    new QName(qName.getNamespaceURI(), className)
                    , modelHeader);

            /////////////////////////////////////////////////////
//             System.out.println(DOM2Writer.nodeToString(modelSource.getFirstChild()));
            ///////////////////////////////////////////////////

        }

        //return the fully qualified class name
        return fullyQualifiedClassName;

    }


    /**
     * @param model
     * @param className
     * @param originalName
     * @param qName
     * @param isElement
     * @param metainf
     * @param propertyNames
     * @param typeMap
     * @return Returns Element.
     * @throws org.apache.axis2.schema.SchemaCompilationException
     *
     */
    private Element getBeanElement(
            Document model,
            String className,
            String originalName,
            String cppNamespace,
            QName qName,
            boolean isElement,
            boolean isAbstract,
            BeanWriterMetaInfoHolder metainf,
            ArrayList propertyNames,
            Map typeMap,
            Map groupTypeMap)
     throws SchemaCompilationException {

        Element rootElt = XSLTUtils.getElement(model, "class");

        //String strippedClassName = className.substring(4, className.length() -3);
//        String strippedClassName = className.substring(4, className.length() -3);

        XSLTUtils.addAttribute(model, "name", className, rootElt);
        XSLTUtils.addAttribute(model, "cppNamespace", cppNamespace,  rootElt);
        //XSLTUtils.addAttribute(model, "name", strippedClassName, rootElt);

        XSLTUtils.addAttribute(model, "originalName", originalName, rootElt);
        XSLTUtils.addAttribute(model, "nsuri", qName.getNamespaceURI(), rootElt);
        XSLTUtils.addAttribute(model, "nsprefix", getPrefixForURI(qName.getNamespaceURI(), qName.getPrefix()), rootElt);

        /* use caps for macros */
        //String capsName = strippedClassName.toUpperCase();
        String capsName = className.toUpperCase();

        XSLTUtils.addAttribute(model, "caps-name", capsName, rootElt);
        if(enableNS2P){
            XSLTUtils.addAttribute(model, "enableNS2P", "yes", rootElt);
        }

        if (!wrapClasses) {
            XSLTUtils.addAttribute(model, "unwrapped", "yes", rootElt);
        }

        if (isAbstract) {
            XSLTUtils.addAttribute(model, "isAbstract", "yes", rootElt);
        }

        if (!writeClasses) {
            XSLTUtils.addAttribute(model, "skip-write", "yes", rootElt);
        }

        if (!isElement) {
            XSLTUtils.addAttribute(model, "type", "yes", rootElt);
        }

        if (metainf.isAnonymous()) {
            XSLTUtils.addAttribute(model, "anon", "yes", rootElt);
        }

        if (metainf.isExtension()) {
            XSLTUtils.addAttribute(model, "extension", metainf.getExtensionClassName(), rootElt);
        }

        if (metainf.isRestriction()) {
            XSLTUtils.addAttribute(model, "restriction", metainf
                    .getRestrictionClassName(), rootElt);
        }


        if (metainf.isChoice()) {
            XSLTUtils.addAttribute(model, "choice", "yes", rootElt);
        }

         if (metainf.isSimple()) {
            XSLTUtils.addAttribute(model, "simple", "yes", rootElt);
        }

        if (metainf.isUnion()) {
            XSLTUtils.addAttribute(model, "union", "yes", rootElt);
        }

        if (metainf.isList()) {
            XSLTUtils.addAttribute(model, "list", "yes", rootElt);
        }

        if (metainf.isOrdered()) {
            XSLTUtils.addAttribute(model, "ordered", "yes", rootElt);
        }

        if (isElement && metainf.isNillable(qName)) {
            XSLTUtils.addAttribute(model, "nillable", "yes", rootElt);
        }

        if (metainf.isParticleClass()) {
            XSLTUtils.addAttribute(model, "particleClass", "yes", rootElt);
        }

        if (metainf.isHasParticleType()){
            XSLTUtils.addAttribute(model, "hasParticleType", "yes", rootElt);
        }

        //populate all the information
        populateInfo(metainf, model, rootElt, propertyNames, typeMap, groupTypeMap, false);

        if (metainf.isSimple() && metainf.isUnion()) {
            populateMemberInfo(metainf, model, rootElt, typeMap);
        }

        if (metainf.isSimple() && metainf.isList()) {
            populateListInfo(metainf, model, rootElt, typeMap, groupTypeMap);
        }

//        System.out.println(DOM2Writer.nodeToString(rootElt));
        return rootElt;
    }

    protected void populateListInfo(BeanWriterMetaInfoHolder metainf,
                                    Document model,
                                    Element rootElement,
                                    Map typeMap,
                                    Map groupTypeMap) {

        String cName = makeUniqueCPPClassName(new ArrayList(), metainf.getItemTypeQName().getLocalPart());
        Element itemType = XSLTUtils.addChildElement(model, "itemtype", rootElement);
        XSLTUtils.addAttribute(model, "type", metainf.getItemTypeClassName(), itemType);
        XSLTUtils.addAttribute(model, "nsuri", metainf.getItemTypeQName().getNamespaceURI(), itemType);
        XSLTUtils.addAttribute(model, "originalName", metainf.getItemTypeQName().getLocalPart(), itemType);
        //XSLTUtils.addAttribute(model, "cname", cName.substring(4, cName.length()-3), itemType);
        XSLTUtils.addAttribute(model,  "cname", cName, itemType);
        if (typeMap.containsKey(metainf.getItemTypeQName()) ||
                groupTypeMap.containsKey(metainf.getItemTypeClassName())) {
            XSLTUtils.addAttribute(model, "ours", "true", itemType);
        }
        if (PrimitiveTypeFinder.isPrimitive(metainf.getItemTypeClassName())) {
            XSLTUtils.addAttribute(model, "primitive", "yes", itemType);
        }

    }

    protected void populateMemberInfo(BeanWriterMetaInfoHolder metainf,
                                      Document model,
                                      Element rootElement,
                                      Map typeMap) {
        Map memberTypes = metainf.getMemberTypes();
        QName memberQName;
        for (Iterator iter = memberTypes.keySet().iterator(); iter.hasNext();) {
            memberQName = (QName) iter.next();
            String memberClass = (String) memberTypes.get(memberQName);


        // add member type element
            Element memberType = XSLTUtils.addChildElement(model, "memberType", rootElement);
            XSLTUtils.addAttribute(model, "type", memberClass, memberType);
            XSLTUtils.addAttribute(model, "nsuri", memberQName.getNamespaceURI(), memberType);
            XSLTUtils.addAttribute(model, "originalName", memberQName.getLocalPart(), memberType);
            XSLTUtils.addAttribute(model, "caps-originalName", memberQName.getLocalPart().toUpperCase(), memberType);
            if (typeMap.containsKey(memberQName)) {
                /** add another attribute to make sure that _t types are handled */
                XSLTUtils.addAttribute(model, "ours", "true", memberType);
            }

        }
    }

    /**
     * @param metainf
     * @param model
     * @param rootElt
     * @param propertyNames
     * @param typeMap
     * @throws org.apache.axis2.schema.SchemaCompilationException
     *
     */
    private void populateInfo(BeanWriterMetaInfoHolder metainf,
                              Document model,
                              Element rootElt,
                              ArrayList propertyNames,
                              Map typeMap,
                              Map groupTypeMap,
                              boolean isInherited) throws SchemaCompilationException {
        if (metainf.getParent() != null && (!metainf.isRestriction() || (metainf.isRestriction() && metainf.isSimple())))
        {
            populateInfo(metainf.getParent(), model, rootElt, propertyNames,
                    typeMap, groupTypeMap, true);
        }
        addPropertyEntries(metainf, model, rootElt, propertyNames, typeMap, groupTypeMap, isInherited);

    }


    private String makeCPPMehtodName(String name){
        if(name !="" && name.length()>0)
        {
            char[] charArr = name.toCharArray();
            if('a' <= charArr[0] && 'z' >= charArr[0] )
            {
                charArr[0] = (char)('A' - 'a' + charArr[0]);
                return new String(charArr);
            }
        }
        return  name;
    }

    /**
     * @param metainf
     * @param model
     * @param rootElt
     * @param propertyNames
     * @param typeMap
     * @throws org.apache.axis2.schema.SchemaCompilationException
-     *
     */
    private void addPropertyEntries(BeanWriterMetaInfoHolder metainf,
                                    Document model, Element rootElt,
                                    ArrayList propertyNames,
                                    Map typeMap,
                                    Map groupTypeMap,
                                    boolean isInherited) throws SchemaCompilationException {
        // go in the loop and add the part elements
        QName[] qName;
        ArrayList missingQNames = new ArrayList();
        ArrayList qNames = new ArrayList();
        BeanWriterMetaInfoHolder parentMetaInf = metainf.getParent();

        if (metainf.isOrdered()) {
            qName = metainf.getOrderedQNameArray();
        } else {
            qName = metainf.getQNameArray();
        }

        for (int i = 0; i < qName.length; i++) {
            qNames.add(qName[i]);
        }
        //adding missing QNames to the end, including elements & attributes.
        // for the simple types we have already add the parent elements
        // it is almost consider as an extension
        if (metainf.isRestriction() && !metainf.isSimple()) {
            addMissingQNames(metainf, qNames, missingQNames);
        }

        QName name;
        for (int i = 0; i < qName.length; i++) {
            Element property = XSLTUtils.addChildElement(model, "property", rootElt);
            name = qName[i];
            String xmlName = makeUniqueCPPClassName(new ArrayList(), name.getLocalPart());

            XSLTUtils.addAttribute(model, "name", name.getLocalPart(), property);
            XSLTUtils.addAttribute(model, "originalName", name.getLocalPart(), property);


            XSLTUtils.addAttribute(model, "nsuri", name.getNamespaceURI(), property);
            XSLTUtils.addAttribute(model, "prefix", name.getPrefix(), property);

           // XSLTUtils.addAttribute(model, "cname", xmlName.substring(4, xmlName.length() -3), property);
            XSLTUtils.addAttribute(model, "cname", makeCPPMehtodName(xmlName), property);


            String CClassNameForElement = metainf.getClassNameForQName(name);

            if (CClassNameForElement == null) {
                CClassNameForElement = CPPBeanWriter.DEFAULT_CPP_CLASS_NAME;
            }
            CClassNameForElement = getShortTypeName(CClassNameForElement);

            String filename = CClassNameForElement.replace( "::", "_" );

            XSLTUtils.addAttribute(model, "filename", filename, property);
            if(enableNS2P)
                XSLTUtils.addAttribute(model, "enableNS2P", "yes", property);

            XSLTUtils.addAttribute(model, "type", CClassNameForElement, property);


            /**
             * Caps for use in C macros
             */
            XSLTUtils.addAttribute(model, "caps-cname", xmlName, property);

            //XSLTUtils.addAttribute(model, "caps-cname", xmlName.substring(4, xmlName.length() -3 ).toUpperCase(), property);

            XSLTUtils.addAttribute(model, "caps-type", CClassNameForElement.toUpperCase(), property);

            if (PrimitiveTypeFinder.isPrimitive(CClassNameForElement)) {
                XSLTUtils.addAttribute(model, "primitive", "yes", property);
            }
            //add an attribute that says the type is default
            if (isDefault(CClassNameForElement)) {
                XSLTUtils.addAttribute(model, "default", "yes", property);
            }

             // add the default value
            if (metainf.isDefaultValueAvailable(name)){
                QName schemaQName = metainf.getSchemaQNameForQName(name);
                if (baseTypeMap.containsKey(schemaQName)){
                    XSLTUtils.addAttribute(model, "defaultValue",
                            metainf.getDefaultValueForQName(name), property);
                }
            }

            if (typeMap.containsKey(metainf.getSchemaQNameForQName(name)) ||
                    (metainf.getSchemaQNameForQName(name) == null ||
                    !metainf.getSchemaQNameForQName(name).getNamespaceURI().equals(DEFAULT_TYPE_NS))
                     && !CClassNameForElement.equals(DEFAULT_CPP_CLASS_NAME)
                     && !CClassNameForElement.equals(DEFAULT_ATTRIB_CLASS_NAME)) {
                XSLTUtils.addAttribute(model, "ours", "yes", property);

            }

            if (metainf.getAttributeStatusForQName(name)) {
                XSLTUtils.addAttribute(model, "attribute", "yes", property);
            }else{
                XSLTUtils.addAttribute(model, "notattribute", "yes", property);
            }

            if (metainf.isNillable(name)) {
                XSLTUtils.addAttribute(model, "nillable", "yes", property);
            }

            String shortTypeName;
            if (metainf.getSchemaQNameForQName(name) != null) {
                //see whether the QName is a basetype
                if (baseTypeMap.containsKey(metainf.getSchemaQNameForQName(name))) {
                    shortTypeName = metainf.getSchemaQNameForQName(name).getLocalPart();
                } else {
                    shortTypeName = getShortTypeName(CClassNameForElement);
                }
            } else {
                shortTypeName = getShortTypeName(CClassNameForElement);
            }
            XSLTUtils.addAttribute(model, "shorttypename", shortTypeName, property);

            if (isInherited) {
                XSLTUtils.addAttribute(model, "inherited", "yes", property);
            }

            if (metainf.getAnyStatusForQName(name)) {
                XSLTUtils.addAttribute(model, "any", "yes", property);
            }

            if (metainf.getBinaryStatusForQName(name)) {
                XSLTUtils.addAttribute(model, "binary", "yes", property);
            }

            if (metainf.getSimpleStatusForQName(name)) {
                XSLTUtils.addAttribute(model, "simple", "yes", property);
            }

            //put the min occurs count irrespective of whether it's an array or not
            long minOccurs = metainf.getMinOccurs(name);
            XSLTUtils.addAttribute(model, "minOccurs", minOccurs + "", property);


            if (metainf.getArrayStatusForQName(name)) {
                String attrName = name.getLocalPart();
                int arrayTokenStart = attrName.indexOf("Array");
                if (arrayTokenStart >= 0) {
                    String arrayEle = attrName.substring(0, arrayTokenStart);
                    XSLTUtils.addAttribute(model, "arrayele", arrayEle, property);
                }
                XSLTUtils.addAttribute(model, "isarray", "yes", property);
                XSLTUtils.addAttribute(
                        model,
                        "arrayBaseType",
                        CClassNameForElement,
                        property);

                long maxOccurs = metainf.getMaxOccurs(name);
                if (maxOccurs == Long.MAX_VALUE) {
                    XSLTUtils.addAttribute(model, "unbound", "yes", property);
                }
                XSLTUtils.addAttribute(model, "maxOccurs", maxOccurs + "", property);

            }

            if ((parentMetaInf != null) && metainf.isRestriction() && missingQNames.contains(name)) {
                // this element details should be there with the parent meta Inf
                addAttributesToProperty(
                        parentMetaInf,
                        name,
                        model,
                        property,
                        typeMap,
                        groupTypeMap,
                        CClassNameForElement);

            } else {
                addAttributesToProperty(
                        metainf,
                        name,
                        model,
                        property,
                        typeMap,
                        groupTypeMap,
                        CClassNameForElement);
            }
        }
    }

    private void addAttributesToProperty(BeanWriterMetaInfoHolder metainf,
                                             QName name,
                                             Document model,
                                             Element property,
                                             Map typeMap,
                                             Map groupTypeMap,
                                             String CClassNameForElement) {
            // add an attribute that says the type is default
            if (metainf.getDefaultStatusForQName(name)) {
                XSLTUtils.addAttribute(model, "default", "yes", property);
            }

            if (typeMap.containsKey(metainf.getSchemaQNameForQName(name)) ||
                    groupTypeMap.containsKey(metainf.getSchemaQNameForQName(name)) ||
                    (metainf.getSchemaQNameForQName(name) == null ||
                    !metainf.getSchemaQNameForQName(name).getNamespaceURI().equals(DEFAULT_TYPE_NS))
                     && !CClassNameForElement.equals(DEFAULT_CPP_CLASS_NAME)
                     && !CClassNameForElement.equals(DEFAULT_ATTRIB_CLASS_NAME)) {
                XSLTUtils.addAttribute(model, "ours", "yes", property);
            }

            if (metainf.getAttributeStatusForQName(name)) {
                XSLTUtils.addAttribute(model, "attribute", "yes", property);
            }

            if (metainf.isNillable(name)) {
                XSLTUtils.addAttribute(model, "nillable", "yes", property);
            }

            if (metainf.getOptionalAttributeStatusForQName(name)) {
                XSLTUtils.addAttribute(model, "optional", "yes", property);
            }

            String shortTypeName;
            if (metainf.getSchemaQNameForQName(name) != null) {
                // see whether the QName is a basetype
                if (baseTypeMap.containsKey(metainf.getSchemaQNameForQName(name))) {
                    shortTypeName = metainf.getSchemaQNameForQName(name).getLocalPart();
                } else {
                    shortTypeName = getShortTypeName(CClassNameForElement);
                }
            } else {
                shortTypeName = getShortTypeName(CClassNameForElement);
            }
            XSLTUtils.addAttribute(model, "shorttypename", shortTypeName, property);


            if (metainf.getAnyStatusForQName(name)) {
                XSLTUtils.addAttribute(model, "any", "yes", property);
            }

            if (metainf.getBinaryStatusForQName(name)) {
                XSLTUtils.addAttribute(model, "binary", "yes", property);
            }

            if (metainf.isSimple() || metainf.getSimpleStatusForQName(name)) {
                XSLTUtils.addAttribute(model, "simple", "yes", property);
            }

            // put the min occurs count irrespective of whether it's an array or
            // not
            long minOccurs = metainf.getMinOccurs(name);
            XSLTUtils.addAttribute(model, "minOccurs", minOccurs + "", property);


            if (metainf.getArrayStatusForQName(name)) {

                XSLTUtils.addAttribute(model, "array", "yes", property);

                int endIndex = CClassNameForElement.indexOf("[");
                if (endIndex >= 0) {
                    XSLTUtils.addAttribute(model, "arrayBaseType",
                            CClassNameForElement.substring(0, endIndex), property);
                } else {
                    XSLTUtils.addAttribute(model, "arrayBaseType",
                            CClassNameForElement, property);
                }

                long maxOccurs = metainf.getMaxOccurs(name);
                if (maxOccurs == Long.MAX_VALUE) {
                    XSLTUtils.addAttribute(model, "unbound", "yes", property);
                } else {
                    XSLTUtils.addAttribute(model, "maxOccurs", maxOccurs + "", property);
                }
            }
            if (metainf.isRestrictionBaseType(name)) {
                XSLTUtils.addAttribute(model, "restrictionBaseType", "yes", property);
            }

            if (metainf.isExtensionBaseType(name)) {
                XSLTUtils.addAttribute(model, "extensionBaseType", "yes", property);
            }

            if (metainf.isRestrictionBaseType(name) && metainf.getLengthFacet() != -1) {
                XSLTUtils.addAttribute(model, "lenFacet", metainf.getLengthFacet() + "", property);
            }

            if (metainf.isRestrictionBaseType(name) && metainf.getMaxLengthFacet() != -1) {
                XSLTUtils.addAttribute(model, "maxLenFacet", metainf.getMaxLengthFacet() + "", property);
            }

            if (metainf.isRestrictionBaseType(name) && metainf.getMinLengthFacet() != -1) {
                XSLTUtils.addAttribute(model, "minLenFacet", metainf.getMinLengthFacet() + "", property);
            }

            if (metainf.isRestrictionBaseType(name) && metainf.getMaxExclusiveFacet() != null) {
                XSLTUtils.addAttribute(model, "maxExFacet", metainf.getMaxExclusiveFacet() + "", property);
            }

            if (metainf.isRestrictionBaseType(name) && metainf.getMinExclusiveFacet() != null) {
                XSLTUtils.addAttribute(model, "minExFacet", metainf.getMinExclusiveFacet() + "", property);
            }

            if (metainf.isRestrictionBaseType(name) && metainf.getMaxInclusiveFacet() != null) {
                XSLTUtils.addAttribute(model, "maxInFacet", metainf.getMaxInclusiveFacet() + "", property);
            }

            if (metainf.isRestrictionBaseType(name) && metainf.getMinInclusiveFacet() != null) {
                XSLTUtils.addAttribute(model, "minInFacet", metainf.getMinInclusiveFacet() + "", property);
            }

            if (!metainf.getEnumFacet().isEmpty()) {
                boolean validJava = true;    // Assume all enum values are valid ids

                Iterator iterator = metainf.getEnumFacet().iterator();
                // Walk the values looking for invalid ids
                while (iterator.hasNext()) {
                    String value = (String) iterator.next();
                    if (!JavaUtils.isJavaId(value)) {
                        validJava = false;
                    }
                }

                int id = 0;
                iterator = metainf.getEnumFacet().iterator();
                while (iterator.hasNext()) {
                    Element enumFacet = XSLTUtils.addChildElement(model, "enumFacet", property);
                    String attribValue = (String) iterator.next();
                    XSLTUtils.addAttribute(model, "value", attribValue, enumFacet);
                    if (validJava) {
                        XSLTUtils.addAttribute(model, "id", attribValue.toUpperCase(), enumFacet);
                    } else {
                        id++;
                        // Replace all invalid characters and append an id to avoid collisions
                        XSLTUtils.addAttribute(model, "id",
                                attribValue.toUpperCase().replaceAll("[^A-Z0-9]", "_") + "_" + id, enumFacet);
                    }
                }
            }

            if (metainf.isRestrictionBaseType(name) && metainf.getPatternFacet() != null) {
                XSLTUtils.addAttribute(model, "patternFacet", metainf.getPatternFacet(), property);
            }
        }



    private void addMissingQNames(BeanWriterMetaInfoHolder metainf, ArrayList qName, ArrayList missingQNames) {

        QName[] qNames = null;
        QName[] pQNames = null;

        BeanWriterMetaInfoHolder parentMetaInf = metainf.getParent();

        if (metainf.isOrdered()) {
            qNames = metainf.getOrderedQNameArray();
        } else {
            qNames = metainf.getQNameArray();
        }

        if (parentMetaInf != null) {
            if (parentMetaInf.isOrdered()) {
                pQNames = parentMetaInf.getOrderedQNameArray();
            } else {
                pQNames = parentMetaInf.getQNameArray();
            }
        }


        for (int i = 0; pQNames != null && i < pQNames.length; i++) {
            if (qNameNotFound(pQNames[i], metainf)) {
                missingQNames.add(pQNames[i]);
            }
        }
        //adding missing QNames to the end of list.
        if (!missingQNames.isEmpty()) {
            for (int i = 0; i < missingQNames.size(); i++) {
                qName.add(missingQNames.get(i));
            }
        }

    }

    private boolean qNameNotFound(QName qname, BeanWriterMetaInfoHolder metainf) {

        boolean found = false;
        QName[] qNames;

        if (metainf.isOrdered()) {
            qNames = metainf.getOrderedQNameArray();
        } else {
            qNames = metainf.getQNameArray();
        }

        for (int j = 0; j < qNames.length; j++) {
            if (qname.getLocalPart().equals(qNames[j].getLocalPart())) {
                found = true;
            }
        }
        return !found;
    }

    /**
     * Test whether the given class name matches the default
     *
     * @param CClassNameForElement
     * @return bool
     */
    private boolean isDefault(String CClassNameForElement) {
        return getDefaultClassName().equals(CClassNameForElement) ||
                getDefaultClassArrayName().equals(CClassNameForElement);
    }


    /**
     * Given the xml name, make a unique class name taking into account that some
     * file systems are case sensitive and some are not.
     * -Consider the Jax-WS spec for this
     *
     * @param listOfNames
     * @param xmlName
     * @return Returns String.
     */
    private String makeUniqueCPPClassName(List listOfNames, String xmlName) {
        String cName="";
        if (CUtils.isCKeyword(xmlName)) {
            cName = CUtils.makeNonCKeyword(xmlName);
        } else {
             cName = xmlName.replace('-','_');
            cName = JavaUtils.capitalizeFirstChar(JavaUtils.xmlNameToJava(cName));
        }

        cName = cName.replace('.','_');
        cName = cName.replace('-','_');

        while (listOfNames.contains(cName.toLowerCase())) {
            if (!listOfNames.contains((cName + "E").toLowerCase())){
                cName = cName + "E";
            } else {
                cName = cName + count++;
            }
            cName = cName + CPPBeanWriter.count++;
        }

        listOfNames.add(cName.toLowerCase());

        //String modifiedCName = ADB_CLASS_PREFIX  + cName + ADB_CLASS_POSTFIX;
        String modifiedCName = ADB_CLASS_PREFIX  + cName + ADB_CLASS_POSTFIX;
                
        return modifiedCName;
    }


    /**
     * A bit of code from the old code generator. We are better off using the template
     * engines and such stuff that's already there. But the class writers are hard to be
     * reused so some code needs to be repeated (atleast a bit)
     */
    private void loadTemplate() throws SchemaCompilationException {

        //first get the language specific property map
        Class clazz = this.getClass();
        InputStream xslStream;
        String templateName = javaBeanTemplateName;
        if (templateName != null) {
            try {
                String sourceTemplateName = templateName + "Source.xsl";
                xslStream = clazz.getResourceAsStream(sourceTemplateName);
                sourceTemplateCache = TransformerFactory.newInstance().newTemplates(new StreamSource(xslStream));

                String headerTemplateName = templateName + "Header.xsl";
                xslStream = clazz.getResourceAsStream(headerTemplateName);
                headerTemplateCache = TransformerFactory.newInstance().newTemplates(new StreamSource(xslStream));

                templateLoaded = true;
            } catch (TransformerConfigurationException e) {
                throw new SchemaCompilationException(SchemaCompilerMessages.getMessage("schema.templateLoadException"), e);
            }
        } else {
            throw new SchemaCompilationException(SchemaCompilerMessages.getMessage("schema.templateNotFoundException"));
        }
    }


    /**
     * Creates the output file
     *
     * @param fileName
     * @param extension
     * @throws Exception
     */
    protected File createOutFile(String fileName, String extension) throws Exception {
        return org.apache.axis2.util.FileWriter.createClassFile(this.rootDir,
                "",
                AXIS2_PREFIX + fileName,
                extension);
    }

    /**
     * Writes the output file
     *
     * @param doc
     * @param outputFile
     * @throws Exception
     */
    private void parseSource(Document doc, File outputFile) throws Exception {
        OutputStream outStream = new FileOutputStream(outputFile);
        XSLTTemplateProcessor.parse(outStream,
                doc,
                this.sourceTemplateCache.newTransformer());
        outStream.write('\n');
        outStream.write('\n');
        outStream.flush();
        outStream.close();

    }

    /**
     * Writes the output file
     *
     * @param doc
     * @param outputFile
     * @throws Exception
     */
    private void parseHeader(Document doc, File outputFile) throws Exception {
        OutputStream outStream = new FileOutputStream(outputFile);
        XSLTTemplateProcessor.parse(outStream,
                doc,
                this.headerTemplateCache.newTransformer());
        outStream.write('\n');
        outStream.write('\n');
        outStream.flush();
        outStream.close();

    }

    /**
     * Get a prefix for a namespace URI.  This method will ALWAYS
     * return a valid prefix - if the given URI is already mapped in this
     * serialization, we return the previous prefix.  If it is not mapped,
     * we will add a new mapping and return a generated prefix of the form
     * "ns<num>".
     *
     * @param uri is the namespace uri
     * @return Returns prefix.
     */
    public String getPrefixForURI(String uri) {
        return getPrefixForURI(uri, null);
    }

    /**
     * Last used index suffix for "ns"
     */
    private int lastPrefixIndex = 1;

    /**
     * Map of namespaces URI to prefix(es)
     */
    HashMap mapURItoPrefix = new HashMap();
    HashMap mapPrefixtoURI = new HashMap();

    /**
     * Get a prefix for the given namespace URI.  If one has already been
     * defined in this serialization, use that.  Otherwise, map the passed
     * default prefix to the URI, and return that.  If a null default prefix
     * is passed, use one of the form "ns<num>"
     */
    public String getPrefixForURI(String uri, String defaultPrefix) {
        if ((uri == null) || (uri.length() == 0))
            return null;
        String prefix = (String) mapURItoPrefix.get(uri);
        if (prefix == null) {
            if (defaultPrefix == null || defaultPrefix.length() == 0) {
                prefix = "ns" + lastPrefixIndex++;
                while (mapPrefixtoURI.get(prefix) != null) {
                    prefix = "ns" + lastPrefixIndex++;
                }
            } else {
                prefix = defaultPrefix;
            }
            mapPrefixtoURI.put(prefix, uri);
            mapURItoPrefix.put(uri, prefix);
        }
        return prefix;
    }

    private String getShortTypeName(String typeClassName) {
        if (typeClassName.endsWith("[]")) {
            typeClassName = typeClassName.substring(0, typeClassName.lastIndexOf("["));
        }
        return typeClassName;

    }

    /**
     * Keep unimplemented
     *
     * @param mapperPackageName
     * @see org.apache.axis2.schema.writer.BeanWriter#registerExtensionMapperPackageName(String)
     */
    public void registerExtensionMapperPackageName(String mapperPackageName) {
        //unimplemented
    }

    /**
     * Keep unimplemented
     *
     * @param metainfArray
     * @see org.apache.axis2.schema.writer.BeanWriter#writeExtensionMapper(org.apache.axis2.schema.BeanWriterMetaInfoHolder[])
     */
    public void writeExtensionMapper(BeanWriterMetaInfoHolder[] metainfArray) throws SchemaCompilationException {
        //unimplemented
    }

    /**
     * Keep unimplemented
     *
     * @see org.apache.axis2.schema.writer.BeanWriter#getExtensionMapperPackageName()
     */
    public String getExtensionMapperPackageName() {
        return null;
    }
}
