/*
* Copyright 2005,2006 WSO2, Inc. http://wso2.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/
package org.wso2.javascript.xmlimpl;

import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMAttribute;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.OMException;
import org.apache.axiom.om.OMFactory;
import org.apache.axiom.om.OMNamespace;
import org.apache.axiom.om.OMNode;
import org.apache.axiom.om.OMText;
import org.apache.axiom.om.impl.builder.StAXOMBuilder;
import org.mozilla.javascript.Context;
import org.mozilla.javascript.ScriptRuntime;
import org.mozilla.javascript.Scriptable;
import org.mozilla.javascript.Undefined;
import org.mozilla.javascript.Wrapper;

import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.Iterator;

public class XML extends XMLObjectImpl {

    private AxiomNode axiomNode;

    XML(XMLLibImpl lib, AxiomNode axiomNode) {
        super(lib, lib.xmlPrototype);
        this.axiomNode = axiomNode;
        this.axiomNode.xmlObject = this;
    }

    protected Object jsConstructor(Context cx, boolean inNewExpr, Object[] args) {
        XML xml;
        if (args.length == 0) {
            xml = toXML(lib, "");

        } else {
            if (!inNewExpr && args[0] instanceof XML) {
                //XML returns the same object.
                xml = (XML) args[0];
            }
            xml = toXML(lib, args[0]);
        }
        return xml;
    }

    public Scriptable getExtraMethodSource(Context cx) {
        if (hasSimpleContent()) {
            String src = toString();
            return ScriptRuntime.toObjectOrNull(cx, src);
        }
        return null;
    }

    public String getClassName() {
        return "XML";
    }

    boolean ecmaHasImpl(XMLName xmlName) {
        boolean result = false;

        if (prototypeFlag) {
            String name = xmlName.localName();

            if (getMethod(name) != NOT_FOUND) {
                result = true;
            }
        } else {
            String name = xmlName.localName();
            if ((((XMLList) ecmaGetImpl(xmlName)).length() > 0) ||
                    (getMethod(name) != NOT_FOUND)) {
                result = true;
            }
        }
        return result;
    }

    Object ecmaGetImpl(XMLName xmlName) {
        XMLList xmlList = new XMLList(lib);

        //Implements x..@y, x..@ns::y etc.
        if (xmlName.isDescendants() && xmlName.isAttributeName()) {
            axiomNode.setNodeMatcher(AxiomNode.DESCENDEN_ATTRIBUTE_MATCHER);
            axiomNode.matchNodes(xmlName, xmlList, AxiomNodeMatcher.ATTRIBUTES);

            //Implements x..y, x..ns::y etc,
        } else if (xmlName.isDescendants() && !xmlName.isAttributeName()) {
            axiomNode.setNodeMatcher(AxiomNode.DESCENDENT_CHILDREN_MATCHER);
            axiomNode.matchNodes(xmlName, xmlList, AxiomNodeMatcher.CHILDREN);

            //Implements x.@, x.@ns::y etc,
        } else if (xmlName.isAttributeName()) {
            axiomNode.setNodeMatcher(AxiomNode.NODE_MATCHER);
            axiomNode.matchNodes(xmlName, xmlList, AxiomNodeMatcher.ATTRIBUTES);

            //Implements x.y, x.ns::y etc,
        } else {
            javax.xml.namespace.QName qname =
                    new javax.xml.namespace.QName(xmlName.uri(), xmlName.localName());
            xmlList.setTargets(this, qname);
            axiomNode.setNodeMatcher(AxiomNode.NODE_MATCHER);
            axiomNode.matchNodes(xmlName, xmlList, AxiomNodeMatcher.CHILDREN);
        }
        return xmlList;
    }

    void ecmaPutImpl(XMLName xmlName, Object value) {
        //Log("put property: " + name + " value: " + value.getClass());
        if (prototypeFlag) {

        } else {
            // Special-case checks for undefined and null
            if (value == null || value instanceof Undefined) {
                throw ScriptRuntime.typeError("value is null or undefined..");
            }

            if (xmlName.isAttributeName()) {
                axiomNode.insertAttribute(xmlName, value);

            } else if (xmlName.uri() == null && xmlName.localName().equals("*")) {
                setChildren(value);

            } else {
                // Convert text into XML if needed.
                XMLObjectImpl xmlValue;
                // Check for attribute type and convert to textNode
                if (value instanceof XML) {
                    xmlValue = (XML) value;

                    if (((XML) xmlValue).getAxiomNode().isAttribute()) {
                        xmlValue = axiomNode.getElemetFromText(lib, xmlName, xmlValue.toString());
                    }

                } else if (value instanceof XMLList) {
                    xmlValue = (XMLList) value;

                    for (int i = 0; i < xmlValue.length(); i++) {
                        XML xml = ((XMLList) xmlValue).getFromAxiomNodeList(i);

                        if (xml.axiomNode.isAttribute())
                            ((XMLList) xmlValue).replace(i, axiomNode.getElemetFromText(lib,
                                                                                        xmlName,
                                                                                        xmlValue.toString()));
                    }

                } else {
                    xmlValue = axiomNode
                            .getElemetFromText(lib, xmlName, ScriptRuntime.toString(value));
                }

                XMLList matches = (XMLList) ecmaGetImpl(xmlName);

                if (matches.length() == 0) {
                    appendChild(xmlValue);

                } else {
                    // Remove all other matches
                    for (int i = 1; i < matches.length(); i++) {
                        removeChild(matches.getFromAxiomNodeList(i).axiomNode);
                    }

                    // Replace first match with new value.
                    XML xmlToAdd;
                    for (int i = 0; i < xmlValue.length(); i++) {

                        if (xmlValue instanceof XMLList) {
                            xmlToAdd = ((XMLList) xmlValue).getFromAxiomNodeList(i);

                        } else {
                            xmlToAdd = (XML) xmlValue;
                        }

                        // If it's an attribute or text node, make text node.
                        if (xmlToAdd.getAxiomNode().isAttribute() ||
                                xmlToAdd.getAxiomNode().isText())
                            xmlToAdd =
                                    axiomNode.getElemetFromText(lib, xmlName, xmlToAdd.toString());

                        if (i == 0) {
                            // 1st assignment is replaceChild all others are appendChild
                            replaceChild(matches.getFromAxiomNodeList(0).getAxiomNode(),
                                         xmlToAdd.getAxiomNode());

                        } else {
                            XMLList tmpMatches = (XMLList) ecmaGetImpl(xmlName);
                            insertChild(tmpMatches.getFromAxiomNodeList(i - 1).getAxiomNode(),
                                        xmlToAdd, AxiomNode.APPEND_CHILD);
                            //appendChild(xmlToAdd);
                        }
                    }
                }
            }
        }
    }

    void ecmaDeleteImpl(XMLName name) {
        if (axiomNode.isElement()) {
            XMLList matches = (XMLList) ecmaGetImpl(name);
            matches.remove();
        }
    }

    boolean equivalentXml(Object target) {
        boolean result = false;

        if (target instanceof XML) {
            AxiomNode refNode = this.getAxiomNode();
            AxiomNode targetNode = ((XML) target).getAxiomNode();

            if (refNode.isAttribute() || refNode.isText() || targetNode.isAttribute() ||
                    targetNode.isText()) {
                result = toString().equals(target.toString());

            } else {
                result = AxiomNode.equivalentAxiomNode(refNode, targetNode);
            }

        } else if (target instanceof XMLList) {
            XMLList otherList = (XMLList) target;

            if (otherList.length() == 1)
                result = equivalentXml(otherList.getFromAxiomNodeList(0));

        } else if (hasSimpleContent()) {
            String otherStr = ScriptRuntime.toString(target);
            result = toString().equals(otherStr);
        }
        return result;
    }

    public Object get(int index, Scriptable start) {
        //Log("get index: " + index);
        if (index == 0) {
            return this;
        } else {
            return Scriptable.NOT_FOUND;
        }
    }

    public boolean has(int index, Scriptable start) {
        return (index == 0);
    }

    public void put(int index, Scriptable start, Object value) {
        // Spec says assignment to indexed XML object should return type error
        throw ScriptRuntime.typeError("Assignment to indexed XML is not allowed");
    }

    public void delete(int index) {
        if (index == 0) {
            remove();
        }
    }


    /**
     * The addNamespace method adds a namespace declaration to the in scope namespaces for this
     * XML object and returns this XML object. If the in scope namespaces for the XML object
     * already contains a namespace with a prefix matching that of the given parameter,
     * the prefix of the existing namespace is set to undefined.
     *
     * @param ns - Namespace object to be added
     * @return XML
     */
    XML addNamespace(Namespace ns) {
        axiomNode.addInScopeNamespace(ns);
        return this;
    }

    /**
     * The appendChild method appends the given child to the end of this XML object’s
     * properties and returns this XMLobject. For example,
     * <p/>
     * var e = <employees>
     * <employee id="0" ><name>Jim</name><age>25</age></employee>
     * <employee id="1" ><name>Joe</name><age>20</age></employee>
     * </employees>;
     * // Add a new child element to the end of Jim's employee element
     * e.employee.(name == "Jim").appendChild(<hobby>snorkeling</hobby>);
     * </p>
     *
     * @param value - Child object to be appended
     * @return XML
     */
    XML appendChild(Object value) {
        return insertChild(null, value, AxiomNode.APPEND_CHILD);
    }

    /**
     * The attribute method returns an XMLList containing zero or one XML attributes associated
     * with this XML object that have the given attributeName. For example,
     * <p/>
     * // get the id of the employee named Jim
     * e.employee.(name == "Jim").attribute("id");
     *
     * @param xmlName
     * @return XMLList of attributes
     */
    XMLList attribute(XMLName xmlName) {
        return (XMLList) ecmaGetImpl(xmlName);
    }

    /**
     * The attributes method returns an XMLList containing the XML attributes
     * of this object. For example,
     * // print the attributes of an XML object
     * function printAttributes(x) {
     * for each (var a in x.attributes()) {
     * print("The attribute named " + a.name() + " has the value " + a);
     * }
     * }
     *
     * @return XMLList
     */
    XMLList attributes() {
        XMLName xmlName = XMLName.formStar();
        xmlName.setAttributeName();
        return (XMLList) ecmaGetImpl(xmlName);
    }

    /**
     * The child method returns the list of children in this XML object matching the
     * given numeric property name. The child method returns
     * a list containing the child at the ordinal position identified by propertyName. For example,
     * <p/>
     * var secondChild = customer.child(1);     // equivalent to: var secondChild = customer.*[1]
     *
     * @param index
     * @return XMLList
     */
    XMLList child(long index) {
        XMLList xmlList = new XMLList(lib);
        xmlList.addAxiomNode(axiomNode.childAt((int) index));
        return xmlList;
    }

    /**
     * The child method returns the list of children in this XML object matching the
     * given propertyName.
     * <p/>
     * var name = customer.child("name");       // equivalent to: var name = customer.name;
     *
     * @param xmlName - name of the property name wrapped in a XMLName
     * @return XMLList
     */
    XMLList child(XMLName xmlName) {
        return (XMLList) ecmaGetImpl(xmlName);
    }

    /**
     * Returns a Number representing the ordinal position of this XML object within the context of
     * its parent. For example,
     * <p/>
     * // Get the ordinal index of the employee named Joe.
     * var joeindex = e.employee.(name == "Joe").childIndex();
     *
     * @return position of the child within the context of its parent
     */
    int childIndex() {
        return axiomNode.getChildIndex();
    }

    /**
     * The children method returns an XMLList containing all the properties of this XML object
     * in order. For example,
     * <p/>
     * // Get child elements of first employee: returns an XMLList containing:
     * // <name>Jim</name>, <age>25</age> and <hobby>Snorkeling</hobby>
     * var emps = e.employee[0].children();
     *
     * @return XMLList
     */
    XMLList children() {
        return (XMLList) ecmaGetImpl(XMLName.formStar());
    }

    /**
     * The descendants method returns all the XML valued descendants (children, grandchildren,
     * great-grandchildren,etc.) of this XML object with the given name. If the name parameter is
     * omitted, it returns all descendants of thisXML object.
     *
     * @param xmlName
     * @return XMLList
     */
    XMLList descendants(XMLName xmlName) {
        if (!xmlName.isDescendants())
            xmlName.setIsDescendants();
        return (XMLList) ecmaGetImpl(xmlName);
    }

    /**
     * When the elements method is called with one parameter name, it returns an XMLList
     * containing all the children ofthis XML object that are XML elements with the given name.
     * When the elements method is called with noparameters, it returns an XMLList containing
     * all the children of this XML object that are XML elements regardless of their name.
     *
     * @param xmlName
     * @return XMLList
     */
    XMLList elements(XMLName xmlName) {
        if (xmlName.isDescendants() || xmlName.isAttributeName())
            throw ScriptRuntime.typeError("Argument is not a valid argument");

        XMLList xmlList = new XMLList(lib);
        return axiomNode.getChildElements(xmlName, xmlList);
    }

    /**
     * The hasComplexContent method returns a Boolean value indicating whether this XML object
     * contains complex content. An XML object is considered to contain complex content if it
     * represents an XML element that has child elements. XML objects representing attributes,
     * comments, processing instructions and text nodes do not have complex content.
     * The existence of attributes, comments, processing instructions and text nodes within an
     * XML object is not significant in determining if it has complex content.
     *
     * @return boolean
     */
    boolean hasComplexContent() {
        if (axiomNode.isElement()) {
            if (axiomNode.getOMElement().getFirstElement() != null)
                return true;
        } else {
            return false;
        }
        return false;
    }

    /**
     * The hasSimpleContent method returns a Boolean value indicating whether this XML object
     * contains simple content. An XML object is considered to contain simple content if it
     * represents a text node, represents an attribute node or if it represents an XML element
     * that has no child elements. XML objects representing comments and
     * processing instructions do not have simple content. The existence of attributes,
     * comments, processing instructions and text nodes within an XML object is not significant
     * in determining if it has simple content.
     *
     * @return boolean
     */
    boolean hasSimpleContent() {
        if (axiomNode.isComment() || axiomNode.isProcessingInstruction())
            return false;

        if (axiomNode.isElement()) {
            if (axiomNode.getOMElement().getFirstElement() != null)
                return false;
        }
        return true;
    }

    Object[] inScopeNamespaces() {
        return axiomNode.getInScopeNamespace(lib);
    }

    XML insertChildAfter(Object child, Object value) {
        if (child == null) {
            // Spec says inserting after nothing is the same as appending
            appendChild(value);

        } else if (child instanceof XML) {
            XML childXML = (XML) child;
            if (childXML.getAxiomNode().getOMNode() != null)
                insertChild(childXML.getAxiomNode(), value, AxiomNode.APPEND_CHILD);

        } else if (child instanceof XMLList) {
            XML childXML = ((XMLList) child).getFromAxiomNodeList(0);
            if (childXML.getAxiomNode().getOMNode() != null)
                insertChild(childXML.getAxiomNode(), value, AxiomNode.APPEND_CHILD);
        }
        return this;
    }

    XML insertChildBefore(Object child, Object value) {

        if (child == null) {
            // Spec says inserting after nothing is the same as prepending
            prependChild(value);

        } else if (child instanceof XML) {
            XML childXML = (XML) child;
            if (childXML.getAxiomNode().getOMNode() != null)
                insertChild(childXML.getAxiomNode(), value, AxiomNode.PREPEND_CHILD);

        } else if (child instanceof XMLList) {
            XML childXML = ((XMLList) child).getFromAxiomNodeList(0);
            if (childXML.getAxiomNode().getOMNode() != null)
                insertChild(childXML.getAxiomNode(), value, AxiomNode.PREPEND_CHILD);
        }
        return this;
    }

    int length() {
        return 1;
    }

    String localName() {
        QName name = name();
        if (name == null) {
            return null;
        }
        return name.localName();
    }

    /**
     * name method returns QName object containing a legal XML element name, attribute
     * name, or PI name or null.
     * this method  null if and only if the XML object represents an XML comment or text node
     *
     * @return QName representing the name of element, attribute or PI or null
     */
    QName name() {
        /*QName qname = null;
        if (axiomNode.isText() || axiomNode.isComment()) {
            return null;

        } else if (axiomNode.isElement()) {
            OMElement omElement = (OMElement) axiomNode.getNode();
            qname = new QName(lib, omElement.getQName().getNamespaceURI(),
                    omElement.getQName().getLocalPart(), "");

        } else if (axiomNode.isAttribute()) {
            OMAttribute omAttribute = (OMAttribute) axiomNode.getNode();
            qname = new QName(lib, omAttribute.getQName().getNamespaceURI(),
                    omAttribute.getQName().getLocalPart(), "");

        } else if (axiomNode.isProcessingInstruction()) {
            //TODO handle PI in the name method
            //OMProcessingInstruction omPI = (OMProcessingInstruction) axiomNode.getNode();
            //qname = new QName(lib, omPI.getQName().getNamespaceURI(),
            // omPI.getQName().getLocalPart(), "");
            qname = null;
        }*/
        javax.xml.namespace.QName qname = axiomNode.getQName();
        QName resultQName = new QName(lib, qname.getNamespaceURI(),
                                      qname.getLocalPart(), qname.getPrefix());
        return resultQName;
    }

    Object namespace(String prefix) {
        Object namespace = Undefined.instance;

        if (!axiomNode.isElement()) {
            return namespace;
        }

        OMElement omElement = axiomNode.getOMElement();

        if (prefix == null) {
            javax.xml.namespace.QName qname = omElement.getQName();

            if (qname.getNamespaceURI() != "")
                namespace = new Namespace(lib, qname.getPrefix(), qname.getNamespaceURI());


        } else {
            OMNamespace ns = omElement.findNamespaceURI(prefix);

            if (ns != null)
                namespace = new Namespace(lib, ns.getPrefix(), ns.getNamespaceURI());

        }
        return namespace;
    }

    Object[] namespaceDeclarations() {
        OMNamespace ns;
        Object[] list;
        ArrayList nsList = new ArrayList();
        if (axiomNode.isElement()) {
            OMElement element = axiomNode.getOMElement();
            Iterator iterator = element.getAllDeclaredNamespaces();
            while (iterator.hasNext()) {
                ns = (OMNamespace) iterator.next();
                Namespace namespace = new Namespace(lib, ns.getPrefix(), ns.getNamespaceURI());
                nsList.add(namespace);
            }
        }
        list = new Object[nsList.size()];
        for (int i = 0; i < nsList.size(); i++) {
            Namespace namespace = (Namespace) nsList.get(i);
            list[i] = namespace;

        }
        return list;
    }

    String nodeKind() {
        String nodeKind;
        if (axiomNode.isAttribute()) {
            nodeKind = "attribute";
        } else if (axiomNode.isText()) {
            nodeKind = "text";
        } else if (axiomNode.isComment()) {
            nodeKind = "comment";
        } else if (axiomNode.isProcessingInstruction()) {
            nodeKind = "processing-instruction";
        } else if (axiomNode.isElement()) {
            nodeKind = "element";
        } else {
            // A non-existant node has the nodeKind() of text
            nodeKind = "text";
        }
        return nodeKind;
    }

    /**
     * parent() method returns the parent XML object  of a xml element.
     *
     * @return XML Object
     */
    Object parent() {
        AxiomNode parentNode = axiomNode.getParentNode();
        if (parentNode != null) {
            return parentNode.getXMLObject(lib);
        }
        return null;
    }

    XML prependChild(Object value) {
        insertChild(null, value, AxiomNode.PREPEND_CHILD);
        return this;

    }

    boolean propertyIsEnumerable(Object member) {
        boolean result;
        if (member instanceof Integer) {
            result = (((Integer) member).intValue() == 0);
        } else if (member instanceof Number) {
            double x = ((Number) member).doubleValue();
            // Check that number is posotive 0
            result = (x == 0.0 && 1.0 / x > 0);
        } else {
            result = ScriptRuntime.toString(member).equals("0");
        }
        return result;
    }

    XML removeNamespace(Namespace ns) {
        //TODO Axiom does not support removing namespaces.
        throw ScriptRuntime.typeError("Unsupported operation");
    }

    XML replace(long index, Object value) {
        AxiomNode nodeToRemove = axiomNode.childAt((int) index);
        if (nodeToRemove != null)
            replaceChild(nodeToRemove, value);
        return this;
    }

    XML replace(XMLName name, Object value) {
        if (axiomNode.isElement()) {
            XMLList xmlList = (XMLList) ecmaGetImpl(name);

            if (xmlList.length() > 0)
                ecmaPutImpl(name, value);
        }
        return this;
    }

    /**
     * The setChildren method replaces the XML properties of this XML object with a new set of XML
     * properties from value. value may be a single XML object or an XMLList.
     * setChildren returns this XML object. For example,
     * <p/>
     * // Replace the entire contents of Jim's employee element
     * e.employee.(name == "Jim").setChildren(<name>John</name> + <age>35</age>);
     *
     * @param xml
     * @return this XML Object
     */
    XML setChildren(Object xml) {
        // remove all children
        XMLName xmlName = XMLName.formStar();
        XMLList matches = (XMLList) ecmaGetImpl(xmlName);
        matches.remove();

        // append new children
        appendChild(xml);
        return this;
    }

    void setLocalName(String localName) {
        //TODO handle PI
        if (axiomNode.isAttribute()) {
            axiomNode.getOMAttribute().setLocalName(localName);

        } else if (axiomNode.isElement()) {
            axiomNode.getOMElement().setLocalName(localName);

        }
    }

    void setName(QName qname) {
        if (lib.isXMLName(Context.getCurrentContext(), qname.localName())) {
            OMNamespace omNS;

            if (axiomNode.isElement()) {
                OMElement omElement = axiomNode.getOMElement();
                omNS = axiomNode.getOMFactory().createOMNamespace(qname.uri(), qname.prefix());
                omElement.setLocalName(qname.localName());
                omElement.setNamespace(omNS);

            } else if (axiomNode.isAttribute()) {
                OMAttribute omAttr = axiomNode.getOMAttribute();
                omNS = axiomNode.getOMFactory().createOMNamespace(qname.uri(), qname.prefix());
                omAttr.setLocalName(qname.localName());
                omAttr.setOMNamespace(omNS);

            } else if (axiomNode.isProcessingInstruction()) {
                //TODO Handle pI
            }

        } else {
            throw ScriptRuntime.typeError("QName is not valid");
        }
    }

    void setNamespace(Namespace ns) {
        OMNamespace omNamespace;

        if (axiomNode.isAttribute()) {
            OMAttribute omAttr = axiomNode.getOMAttribute();
            omNamespace = axiomNode.getOMFactory().createOMNamespace(ns.uri(), ns.prefix());
            omAttr.setOMNamespace(omNamespace);

        } else if (axiomNode.isElement()) {
            OMElement omEle = axiomNode.getOMElement();
            omNamespace = axiomNode.getOMFactory().createOMNamespace(ns.uri(), ns.prefix());
            omEle.setNamespace(omNamespace);
        }
    }

    XMLList text() {
        XMLList xmlList = new XMLList(lib);
        Iterator iterator;
        OMNode tmpNode;

        if (axiomNode.isElement()) {
            iterator = axiomNode.getOMElement().getChildren();

            while (iterator.hasNext()) {
                tmpNode = (OMNode) iterator.next();

                if (tmpNode.getType() == OMNode.TEXT_NODE) {
                    xmlList.addAxiomNode(AxiomNode.buildAxiomNode(tmpNode, axiomNode));
                }
            }
        }
        return xmlList;
    }

    public String toString() {
        try {
            if (axiomNode.isAttribute()) {
                return axiomNode.getOMAttribute().getAttributeValue();

            } else if (axiomNode.isText()) {
                return axiomNode.getOMText().getText();

            } else if (hasSimpleContent()) {
                Object obj;
                StringBuffer stringBuffer = new StringBuffer();
                if (axiomNode.getOMNode() != null) {
                    Iterator iterator = axiomNode.getOMElement().getChildren();

                    while (iterator.hasNext()) {
                        if ((obj = iterator.next()) instanceof OMText) {
                            stringBuffer.append(((OMText) obj).getText());
                        }
                    }
                }
                return stringBuffer.toString();

            } else {
                return toXMLString(0);

            }
        } catch (OMException e) {
            throw ScriptRuntime.typeError(e.getMessage());

        } catch (Throwable e) {
            throw ScriptRuntime.typeError(e.getMessage());
        }
    }

    String toXMLString(int indent) {
        //TODO handle indentation later
        try {
            String str = "";

            if (axiomNode.isElement()) {
                str = axiomNode.getOMNode().toString();

            } else if (axiomNode.isAttribute()) {
                str = axiomNode.getOMAttribute().getAttributeValue();

            } else if (axiomNode.isText()) {
                str = axiomNode.getOMText().getText();

            } else if (axiomNode.isComment()) {
                //TODO handle comment serialization
                str = axiomNode.getOMComment().getValue();
                return "comment is not handled " + str;

            } else if (axiomNode.isProcessingInstruction()) {
                str = axiomNode.getOMProcessingInstruction().getTarget();
                return "PI is not handled " + str;
                //TODO handle PI serialization
            }

            return str;

        } catch (OMException e) {
            throw ScriptRuntime.typeError(e.getMessage());

        } catch (Throwable e) {
            throw ScriptRuntime.typeError(e.getMessage());
        }
    }

    Object valueOf() {
        return this;
    }

    Object getXmlObject() {
        if (axiomNode.isOMNode()) {
            return axiomNode.getOMNode();
        } else if (axiomNode.isAttribute()) {
            return axiomNode.getOMAttribute();
        }
        return null;
    }


    protected void removeChild(AxiomNode axiomNode) {
        this.axiomNode.removeChild(axiomNode);
    }

    void remove() {
        axiomNode.detach();
    }

    //Static Methods
    static XML getFromAxiomNode(XMLLibImpl lib, AxiomNode axiomNode) {
        if (axiomNode.xmlObject == null) {
            axiomNode.xmlObject = new XML(lib, axiomNode);
        }
        return axiomNode.xmlObject;
    }

    static XML toXML(XMLLibImpl lib, Object value) {

        String xmlString;
        AxiomNode axiomNode = null;

        if (value == null || value == Undefined.instance) {
            throw ScriptRuntime.typeError("value == null || value == undefined.instance");

        } else if (value instanceof XMLObjectImpl) {
            if (value instanceof XML) {
                xmlString = ((XML) value).toXMLString(0);

            } else {
                throw ScriptRuntime.typeError("Invalid argument ");
            }

        } else if (value instanceof String || value instanceof Number || value instanceof Boolean) {
            xmlString = ScriptRuntime.toString(value);

        } else {
            if (value instanceof OMNode) {
                axiomNode = AxiomNode.buildAxiomNode(value, null);
                return new XML(lib, axiomNode);

            } else if (value instanceof Wrapper) {
                Object wrapped = ((Wrapper) value).unwrap();
                if (wrapped instanceof OMNode) {
                    axiomNode = AxiomNode.buildAxiomNode(wrapped, null);
                    return new XML(lib, axiomNode);
                }
            }
            xmlString = ScriptRuntime.toString(value);
        }

        if (xmlString.trim().startsWith("<>")) {
            throw ScriptRuntime.typeError("Invalid use of XML object anonymous tags <></>.");
        }

        //apply default namespace
        Context cx = Context.getCurrentContext();
        Namespace defaultNamespace;

        if (cx == null) {
            defaultNamespace = lib.namespacePrototype;

        } else {
            defaultNamespace = lib.getDefaultNamespace(cx);

        }

        xmlString = "<parent xmlns=\"" + defaultNamespace.uri() + "\" >" + xmlString.trim() +
                "</parent>";

        try {
            XMLStreamReader parser2 = XMLInputFactory.newInstance()
                    .createXMLStreamReader(new StringReader(xmlString));
            StAXOMBuilder builder2 = new StAXOMBuilder(parser2);
            OMNode omNode = builder2.getDocumentElement().getFirstOMChild();
            if (omNode == null) {
                OMFactory omFactory = OMAbstractFactory.getOMFactory();
                omNode = omFactory.createOMText("");
            }
            //TODO need to deel with removing comments,PIs whithe spaces if those are not necessary
            axiomNode = AxiomNode.buildAxiomNode(omNode, null);

        } catch (XMLStreamException e) {
            throw ScriptRuntime.typeError(e.getMessage());

        } catch (OMException e) {
            throw ScriptRuntime.typeError(e.getMessage());

        } catch (Throwable e) {
            throw ScriptRuntime.typeError(e.getMessage());
        }

        return new XML(lib, axiomNode);
    }

    public OMNode getAxiomFromXML() {
        Object object = getXmlObject();
        // If its an OMAttribute we take its value and create an OMText from it as we have to be
        // returning an OMNode.
        if (object instanceof OMAttribute) {
            OMAttribute omAttribute = (OMAttribute) object;
            return axiomNode.getOMFactory().createOMText(omAttribute.getAttributeValue());
        }
        return (OMNode) object;
    }

    AxiomNode getAxiomNode() {
        return axiomNode;
    }

    void setAxiomNode(AxiomNode axiomNode) {
        this.axiomNode = axiomNode;
    }

    /**
     * Insert the value according to the refNode and mode
     * If refNode is null then append or prepend the value based on the mode
     * If refNode is not null then insert value after or before the refNode based on the mode
     *
     * @param refNode
     * @param value
     * @param mode    represent APPEND or PREPEND
     * @return XML
     */
    public XML insertChild(AxiomNode refNode, Object value, int mode) {

        if (value instanceof Undefined) {
            // Do nothing
        } else if (value instanceof XML) {
            XML xmlValue = (XML) value;
            axiomNode.insertChild(refNode, xmlValue.getAxiomNode(), mode);

        } else if (value instanceof XMLList) {
            XMLList list = (XMLList) value;
            XML xmlValue;
            for (int i = 0; i < list.length(); i++) {
                xmlValue = list.getFromAxiomNodeList(i);
                insertChild(refNode, xmlValue, mode);
            }
        } else {
            // Convert to string and make XML out of it
            String xmlStr = ScriptRuntime.toString(value);
            XML xmlValue = toXML(lib, xmlStr);
            insertChild(refNode, xmlValue, mode);
        }
        return this;
    }

    /**
     * Replace value with give nodeToReplace
     * First, value is inserted before the nodeToReplace then nodeTo Replace is detached.
     * Value can be a XML/XMLList/String,
     * therefore insertChild method is called to resolve the value
     *
     * @param nodeToReplace
     * @param value
     */
    private void replaceChild(AxiomNode nodeToReplace, Object value) {
        if (nodeToReplace.getOMNode() != null) {
            insertChild(nodeToReplace, value, AxiomNode.PREPEND_CHILD);
            nodeToReplace.detach();
        }
    }

    private void replaceChild(AxiomNode nodeToReplace, AxiomNode nodeToAdd) {
        if (nodeToReplace.getOMNode() != null) {
            axiomNode.insertChild(nodeToReplace, nodeToAdd, AxiomNode.PREPEND_CHILD);
            nodeToReplace.detach();
        }
    }

    public void replaceAll(XML targetXML) {
        AxiomNode targetNode = AxiomNode
                .buildAxiomNode(targetXML.getAxiomNode().cloneOMNode(), axiomNode.getParentNode());

        if (axiomNode.getOMNode() != null) {
            axiomNode.insertChild(axiomNode, targetNode, AxiomNode.PREPEND_CHILD);
            axiomNode.detach();
            this.axiomNode = targetNode;
        }
    }
}

