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

package org.wso2.wsf.jython.deployer.schemagenarator;


import org.apache.ws.commons.schema.XmlSchema;
import org.apache.ws.commons.schema.XmlSchemaCollection;
import org.apache.ws.commons.schema.XmlSchemaComplexType;
import org.apache.ws.commons.schema.XmlSchemaElement;
import org.apache.ws.commons.schema.XmlSchemaEnumerationFacet;
import org.apache.ws.commons.schema.XmlSchemaForm;
import org.apache.ws.commons.schema.XmlSchemaSequence;
import org.apache.ws.commons.schema.XmlSchemaSimpleType;
import org.apache.ws.commons.schema.XmlSchemaSimpleTypeRestriction;
import org.apache.ws.commons.schema.constants.Constants;
import org.apache.ws.commons.schema.utils.NamespaceMap;

import javax.xml.namespace.QName;

/**
 * Schema generation class.
 */
public class SchemaGenerator {

    private String schemaTargetNamespace;

    private String prefix = "ws";

    private XmlSchema xmlSchema;

    private String TYPE = "Type";

    private TypeTable typeTable;

    private String RESPONSE = "Response";

    public NamespaceMap getNamespaceMap() {
        return nameSpacesMap;
    }

    private NamespaceMap nameSpacesMap = new NamespaceMap();

    public SchemaGenerator(String schemaTargetNamespace, TypeTable typeTable) {
        this.schemaTargetNamespace = schemaTargetNamespace;
        this.typeTable = typeTable;
        XmlSchemaCollection xmlSchemaCollection = new XmlSchemaCollection();
        xmlSchema = new XmlSchema(this.schemaTargetNamespace, xmlSchemaCollection);
        xmlSchema.setAttributeFormDefault(new XmlSchemaForm(XmlSchemaForm.UNQUALIFIED));
        xmlSchema.setElementFormDefault(new XmlSchemaForm(XmlSchemaForm.UNQUALIFIED));

        String URI_2001_SCHEMA_XSD = "http://www.w3.org/2001/XMLSchema";
        String DEFAULT_SCHEMA_NAMESPACE_PREFIX = "xs";
        nameSpacesMap.put(DEFAULT_SCHEMA_NAMESPACE_PREFIX, URI_2001_SCHEMA_XSD);
        nameSpacesMap.put(prefix, this.schemaTargetNamespace);
        xmlSchema.setNamespaceContext(nameSpacesMap);
    }

    public XmlSchema getSchema() {
        return xmlSchema;
    }

    public XmlSchemaElement createInputElement(Type input, String functionName) throws Exception {
        return createElement(input, functionName);
    }

    public XmlSchemaElement createOutputElement(Type output, String functionName) throws Exception {
        return createElement(output, functionName + RESPONSE);
    }

    private XmlSchemaElement handleComplexType(ComplexType complexType, String functionName)
            throws Exception {
        XmlSchemaElement xmlSchemaElement;
        XmlSchemaComplexType xmlSchemaComplexType =
                createComplexType(complexType, functionName + TYPE);
        if (complexType == null) {
            return null;
        }
        xmlSchemaElement = createXMLSchemaElement(functionName, functionName + TYPE);
        xmlSchemaElement.setSchemaType(xmlSchemaComplexType);
        xmlSchemaElement.setQName(new QName(schemaTargetNamespace, functionName));
        return xmlSchemaElement;
    }

    private XmlSchemaElement createElement(Type param, String functionName) throws Exception {
        XmlSchemaElement xmlSchemaElement = null;
        if (param instanceof ComplexType) {
            ComplexType complexType = (ComplexType) param;
            xmlSchemaElement =
                    handleComplexType(complexType, functionName);
        } else if (param instanceof SimpleType) {
            ComplexType complexType = new ComplexType();
            complexType.addMember(param);
            complexType.setName(functionName);
            xmlSchemaElement =
                    handleComplexType(complexType, functionName);
        }
        if (xmlSchemaElement == null) {
            return null;
        }
        QName element =
                new QName(this.schemaTargetNamespace, functionName, this.prefix);
        xmlSchema.getItems().add(xmlSchemaElement);
        xmlSchema.getElements().add(element, xmlSchemaElement);
        return xmlSchemaElement;
    }

    private XmlSchemaComplexType createComplexType(ComplexType complexType, String elementName)
            throws Exception {
        QName element =
                new QName(this.schemaTargetNamespace, elementName, this.prefix);
        XmlSchemaComplexType xmlSchemaComplexType = new XmlSchemaComplexType(xmlSchema);
        xmlSchemaComplexType.setName(elementName);
        xmlSchema.getItems().add(xmlSchemaComplexType);

        XmlSchemaSequence xmlSchemaSequence = new XmlSchemaSequence();
        for (Type type : complexType.getMembers()) {
            XmlSchemaElement xmlSchemaElement;
            if (type instanceof SimpleType) {
                SimpleType simpleType = (SimpleType) type;
                if ((xmlSchemaElement = createXMLSchemaElement(simpleType.getName(), simpleType.getType())) != null) {
                    xmlSchemaSequence.getItems().add(xmlSchemaElement);
                }
            } else if (type instanceof ComplexType) {
                ComplexType complexTypeParam = (ComplexType) type;
                if ((xmlSchemaElement = handleComplexType(complexTypeParam, elementName +
                        complexTypeParam.getName() + TYPE)) != null) {
                    xmlSchemaElement.setName(complexTypeParam.getName());
                    xmlSchemaSequence.getItems().add(xmlSchemaElement);
                }
            }
        }
        xmlSchemaComplexType.setParticle(xmlSchemaSequence);
        typeTable.addComplexSchema(elementName, element);
        return xmlSchemaComplexType;
    }

    private XmlSchemaElement createXMLSchemaElement(String name, String paramType) throws
            Exception {
        XmlSchemaElement xmlSchemaElement = new XmlSchemaElement();
        xmlSchemaElement.setName(name);
            QName qName = typeTable.getQNamefortheType(paramType);
            if (qName == null) {
                throw new Exception(
                        "No matching schematype could be found for the type : " + paramType);
            }
            xmlSchemaElement.setSchemaTypeName(qName);
            return xmlSchemaElement;
    }

    public String getSchemaTargetNamespace() {
        return schemaTargetNamespace;
    }

    /**
     * If the inputType annotations match the pattern of enumeration create the appropriate schema element to handle
     * that.
     *
     * @param name  - The name of the parameter
     * @param enums - Array of enumeration values
     * @return XmlSchemaSimpleType - An XmlSchemaSimpleType which has a restriction and the enumaration.
     */
    private XmlSchemaSimpleType handleEnumeration(String name, String[] enums) {
        XmlSchemaSimpleTypeRestriction simpleTypeRestriction = new XmlSchemaSimpleTypeRestriction();
        // Set the base type to string. 95% of the time enumerations are strings so use it.
        simpleTypeRestriction.setBaseTypeName(Constants.XSD_STRING);
        XmlSchemaSimpleType simpleType = new XmlSchemaSimpleType(xmlSchema);
        simpleType.setName(name);
        simpleType.setContent(simpleTypeRestriction);

        // Create enumeration facets for each value
        for (String anEnum : enums) {
            String enumeration = anEnum.trim();
            XmlSchemaEnumerationFacet enumerationFacet = new XmlSchemaEnumerationFacet();
            enumerationFacet.setValue(enumeration);
            simpleTypeRestriction.getFacets().add(enumerationFacet);
        }

        return simpleType;
    }
}
