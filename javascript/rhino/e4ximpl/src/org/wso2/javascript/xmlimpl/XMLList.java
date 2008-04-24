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

import org.apache.axiom.om.OMNode;
import org.apache.axiom.om.OMText;
import org.apache.axiom.om.OMAttribute;
import org.mozilla.javascript.Callable;
import org.mozilla.javascript.Context;
import org.mozilla.javascript.Function;
import org.mozilla.javascript.ScriptRuntime;
import org.mozilla.javascript.Scriptable;
import org.mozilla.javascript.Undefined;
import org.mozilla.javascript.xml.XMLObject;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class XMLList extends XMLObjectImpl implements Function {

    private List _axiomNodeList = null;
    private XMLObjectImpl targetObject = null;
    private javax.xml.namespace.QName targetProperty = null;
    private final static String LIST_WITH_ONE_ITEM = "method works only on " +
            "lists containing one item";

    public XMLList(XMLLibImpl lib) {
        super(lib, lib.xmlListPrototype);
        _axiomNodeList = new ArrayList();
    }

    public XMLList(XMLLibImpl lib, List axiomNodeList) {
        super(lib, lib.xmlListPrototype);
        if (axiomNodeList != null) {
            _axiomNodeList = axiomNodeList;
        } else {
            axiomNodeList = new ArrayList();
        }
    }

    public Scriptable getExtraMethodSource(Context cx) {
        if (length() == 1) {
            return getFromAxiomNodeList(0);
        }
        return null;
    }

    public String getClassName() {
        return "XMLList";
    }

    boolean ecmaHasImpl(XMLName xmlName) {
        boolean result = false;
        //Has now should return true if the property would have results > 0 or f it's a method name
        String name = xmlName.localName();
        if ((((XMLList) ecmaGetImpl(xmlName)).length() > 0) ||
                (getMethod(name) != NOT_FOUND)) {
            result = true;
        }
        return result;
    }

    Object ecmaGetImpl(XMLName name) {
        XMLList xmlList = new XMLList(lib);
        javax.xml.namespace.QName qname = null;

        if (!name.isDescendants() && !name.isAttributeName())
            // Only set the targetProperty if this is a regular child get
            // and not a descendant or attribute get
            qname = new javax.xml.namespace.QName(name.uri(), name.localName(), "");

        xmlList.setTargets(this, qname);
        for (int i = 0; i < length(); i++)
            xmlList.addToList(getFromAxiomNodeList(i).ecmaGetImpl(name));

        return xmlList;
    }

    void ecmaPutImpl(XMLName xmlName, Object value) {
        // Special-case checks for undefined and null
        if (value == null) {
            value = "null";
        } else if (value instanceof Undefined) {
            value = "undefined";
        }

        if (length() > 1) {
            throw ScriptRuntime.typeError(
                    "Assignment to lists with more than one item is not supported");

        } else if (length() == 0) {
            // Secret sauce for super-expandos.
            // We set an element here, and then add ourselves to our target.
            if (targetObject != null &&
                    targetProperty != null &&
                    !targetProperty.getLocalPart().equals("*")) {
                // Add an empty element with our targetProperty xmlName and then set it.
                //TODO Change this imple
                AxiomNode tmpAxiomNode = AxiomNode.buildAxiomNode(null, null);
                XML xmlValue = tmpAxiomNode.getElemetFromText(lib,
                                                              XMLName.formProperty(
                                                                      targetProperty.getNamespaceURI(),
                                                                      targetProperty.getLocalPart()),
                                                              "");
                addToList(xmlValue);

                if (xmlName.isAttributeName()) {
                    insertAttribute(xmlName, value);

                } else {
                    XML xml = getFromAxiomNodeList(0);
                    xml.ecmaPutImpl(xmlName, value);

                    // Update the list with the new item at location 0.
                    replace(0, getFromAxiomNodeList(0));
                }

                // Now add us to our parent
                XMLName name2 = XMLName.formProperty(targetProperty.getNamespaceURI(),
                                                     targetProperty.getLocalPart());
                targetObject.ecmaPutImpl(name2, this);
            } else {
                throw ScriptRuntime.typeError(
                        "Assignment to empty XMLList without targets not supported");
            }

        } else if (xmlName.isAttributeName()) {
            insertAttribute(xmlName, value);

        } else {
            XML xml = getFromAxiomNodeList(0);
            xml.ecmaPutImpl(xmlName, value);

            // Update the list with the new item at location 0.
            replace(0, getFromAxiomNodeList(0));
        }
    }

    void ecmaDeleteImpl(XMLName name) {
        for (int i = 0; i < length(); i++) {
            XML xml = getFromAxiomNodeList(i);

            if (xml.getAxiomNode().isElement()) {
                xml.ecmaDeleteImpl(name);
            }
        }
    }

    boolean equivalentXml(Object target) {
        boolean result = false;

        // Zero length list should equate to undefined
        if (target instanceof Undefined && length() == 0) {
            result = true;

        } else if (length() == 1) {
            result = getFromAxiomNodeList(0).equivalentXml(target);

        } else if (target instanceof XMLList) {
            XMLList otherList = (XMLList) target;

            if (otherList.length() == length()) {
                result = true;

                for (int i = 0; i < length(); i++) {
                    if (!getFromAxiomNodeList(i).equivalentXml(otherList.getFromAxiomNodeList(i))) {
                        result = false;
                        break;
                    }
                }
            }
        }
        return result;
    }

    public void delete(int index) {
        if (index >= 0 && index < length()) {
            XML xml = getFromAxiomNodeList(index);
            xml.remove();
            removeFromList(index);
        }
    }

    public boolean has(int index, Scriptable start) {
        return 0 <= index && index < length();
    }

    public void put(int index, Scriptable start, Object value) {
        //TODO implements the put method
        Object parent = Undefined.instance;
        XMLObject xmlValue;

        // Special-case checks for undefined and null
        if (value == null) {
            value = "null";
        } else if (value instanceof Undefined) {
            value = "undefined";
        }

        if (value instanceof XMLObject) {
            xmlValue = (XMLObject) value;
        } else {
            if (targetProperty == null) {
                xmlValue = XML.toXML(lib, value.toString());
            } else {
                AxiomNode tmpAxiomNode = AxiomNode.buildAxiomNode(null, null);
                xmlValue = tmpAxiomNode.getElemetFromText(lib,
                                                          XMLName.formProperty(
                                                                  targetProperty.getNamespaceURI(),
                                                                  targetProperty.getLocalPart()),
                                                          value.toString());
            }
        }

        // Find the parent
        if (index < length()) {
            parent = getFromAxiomNodeList(index).parent();
        } else {
            // Appending
            parent = parent();
        }

        if (parent instanceof XML) {
            // found parent, alter doc
            XML xmlParent = (XML) parent;

            if (index < length()) {
                // We're replacing the the node.
                XML xmlNode = getFromAxiomNodeList(index);

                if (xmlValue instanceof XML) {
                    xmlNode.replaceAll((XML) xmlValue);
                    //xmlValue should be cast to XML otherwise replace(intdex, object) method will be called
                    replace(index, (XML) xmlValue);
                } else if (xmlValue instanceof XMLList) {
                    // Replace the first one, and add the rest on the list.
                    XMLList list = (XMLList) xmlValue;

                    if (list.length() > 0) {
                        int lastIndexAdded = xmlNode.childIndex();
                        xmlNode.replaceAll(list.getFromAxiomNodeList(0));
                        replace(index, list.getFromAxiomNodeList(0));

                        for (int i = 1; i < list.length(); i++) {
                            xmlParent.insertChildAfter(xmlParent.child(lastIndexAdded),
                                                       list.getFromAxiomNodeList(i));
                            lastIndexAdded++;
                            insert(index + i, list.getFromAxiomNodeList(i));
                        }
                    }
                }
            } else {
                // Appending
                xmlParent.appendChild(xmlValue);
                addToList(xmlParent.child(index));
            }
        } else {
            //TODO
            // Don't all have same parent, no underlying doc to alter
            if (index < length()) {
                XML xmlNode = XML.getFromAxiomNode(lib, AxiomNode.buildAxiomNode(
                        _axiomNodeList.get(index),
                        ((XML) getFromAxiomNodeList(index).parent()).getAxiomNode()));

                if (xmlValue instanceof XML) {
                    xmlNode.replaceAll((XML) xmlValue);
                    replace(index, xmlNode);
                } else if (xmlValue instanceof XMLList) {
                    // Replace the first one, and add the rest on the list.
                    XMLList list = (XMLList) xmlValue;

                    if (list.length() > 0) {
                        xmlNode.replaceAll((XML) list.getFromAxiomNodeList(0));
                        replace(index, (XML) list.getFromAxiomNodeList(0));

                        for (int i = 1; i < list.length(); i++) {
                            insert(index + i, (XML) list.getFromAxiomNodeList(i));
                        }
                    }
                }
            } else {
                addToList(xmlValue);
            }
        }
    }

    public Object get(int index, Scriptable start) {
        //Log("get index: " + index);
        if (index >= 0 && index < length()) {
            return getFromAxiomNodeList(index);
        } else {
            return Scriptable.NOT_FOUND;
        }
    }

    public Object[] getIds() {
        Object enumObjs[];

        if (prototypeFlag) {
            enumObjs = new Object[0];
        } else {
            enumObjs = new Object[length()];

            for (int i = 0; i < enumObjs.length; i++) {
                enumObjs[i] = new Integer(i);
            }
        }
        return enumObjs;
    }

    public Object call(Context cx, Scriptable scope, Scriptable thisObj, Object[] args) {
        // This XMLList is being called as a Function.
        // Let's find the real Function object.
        if (targetProperty == null)
            throw ScriptRuntime.notFunctionError(this);

        String methodName = targetProperty.getLocalPart();

        boolean isApply = methodName.equals("apply");
        if (isApply || methodName.equals("call"))
            return applyOrCall(isApply, cx, scope, thisObj, args);

        Callable method = ScriptRuntime.getElemFunctionAndThis(
                this, methodName, cx);
        // Call lastStoredScriptable to clear stored thisObj
        // but ignore the result as the method should use the supplied
        // thisObj, not one from redirected call
        ScriptRuntime.lastStoredScriptable(cx);
        return method.call(cx, scope, thisObj, args);
    }

    public Scriptable construct(Context cx, Scriptable scope, Object[] args) {
        throw ScriptRuntime.typeError1("msg.not.ctor", "XMLList");
    }

    private Object applyOrCall(boolean isApply,
                               Context cx, Scriptable scope,
                               Scriptable thisObj, Object[] args) {
        String methodName = isApply ? "apply" : "call";
        if (!(thisObj instanceof XMLList) ||
                ((XMLList) thisObj).targetProperty == null)
            throw ScriptRuntime.typeError1("msg.isnt.function",
                                           methodName);

        return ScriptRuntime.applyOrCall(isApply, cx, scope, thisObj, args);
    }

    protected Object jsConstructor(Context cx, boolean inNewExpr, Object[] args) {
        if (args.length == 0) {
            return new XMLList(lib);
        } else {
            if (!inNewExpr && args[0] instanceof XMLList) {
                //XML returns the same object.
                return args[0];
            }

            if (args[0] == null || args[0] == Undefined.instance) {
                return new XMLList(lib);

            } else if (args[0] instanceof XMLList) {
                return args[0];

            } else {
                return toXMLList(lib, args[0]);
            }
        }
    }

    XML addNamespace(Namespace ns) {
        if (length() == 1) {
            return getFromAxiomNodeList(0).addNamespace(ns);
        } else {
            throw ScriptRuntime.typeError("addNamespace" + LIST_WITH_ONE_ITEM);
        }
    }

    XML appendChild(Object value) {
        if (length() == 1) {
            return getFromAxiomNodeList(0).appendChild(value);
        } else {
            throw ScriptRuntime.typeError("appendChild" + LIST_WITH_ONE_ITEM);
        }
    }

    XMLList attribute(XMLName xmlName) {
        XMLList xmlList = new XMLList(lib);
        for (int i = 0; i < length(); i++)
            xmlList.addToList(getFromAxiomNodeList(i).attribute(xmlName));
        return xmlList;
    }

    XMLList attributes() {
        XMLList xmlList = new XMLList(lib);
        for (int i = 0; i < length(); i++)
            xmlList.addToList(getFromAxiomNodeList(i).attributes());
        return xmlList;
    }

    XMLList child(long index) {
        XMLList xmlList = new XMLList(lib);
        for (int i = 0; i < length(); i++)
            xmlList.addToList(getFromAxiomNodeList(i).child(index));
        return xmlList;
    }

    XMLList child(XMLName xmlName) {
        XMLList xmlList = new XMLList(lib);
        for (int i = 0; i < length(); i++)
            xmlList.addToList(getFromAxiomNodeList(i).child(xmlName));
        return xmlList;
    }

    int childIndex() {
        if (length() == 1) {
            return getFromAxiomNodeList(0).childIndex();
        } else {
            throw ScriptRuntime.typeError("childIndex" + LIST_WITH_ONE_ITEM);
        }
    }

    XMLList children() {
        XMLList xmlList = new XMLList(lib);
        for (int i = 0; i < length(); i++)
            xmlList.addToList(getFromAxiomNodeList(i).children());
        return xmlList;
    }

    XMLList descendants(XMLName xmlName) {
        XMLList xmlList = new XMLList(lib);
        for (int i = 0; i < length(); i++)
            xmlList.addToList(getFromAxiomNodeList(i).descendants(xmlName));
        return xmlList;
    }

    XMLList elements(XMLName xmlName) {
        XMLList xmlList = new XMLList(lib);
        for (int i = 0; i < length(); i++)
            xmlList.addToList(getFromAxiomNodeList(i).elements(xmlName));
        return xmlList;
    }

    boolean hasComplexContent() {
        if (length() != 0) {
            if (length() == 0) {
                return getFromAxiomNodeList(0).hasComplexContent();
            } else {
                for (int i = 0; i < length(); i++) {
                    if (!((AxiomNode) _axiomNodeList.get(i)).isElement())
                        return false;
                }
                return true;
            }
        }
        return false;
    }

    boolean hasSimpleContent() {
        if (length() != 0) {
            if (length() == 1) {
                XML xmlobject = getFromAxiomNodeList(0);
                return xmlobject.hasSimpleContent();
            } else {
                for (int i = 0; i < length(); i++)
                    if (((AxiomNode) _axiomNodeList.get(i)).isElement())
                        return false;
            }
        }
        return true;
    }

    Object[] inScopeNamespaces() {
        if (length() == 1) {
            return getFromAxiomNodeList(0).inScopeNamespaces();
        } else {
            throw ScriptRuntime.typeError("inScopeNamespaces" + LIST_WITH_ONE_ITEM);
        }
    }

    XML insertChildAfter(Object child, Object value) {
        if (length() == 1) {
            return getFromAxiomNodeList(0).insertChildAfter(child, value);
        } else {
            throw ScriptRuntime.typeError("insertChildAfter" + LIST_WITH_ONE_ITEM);
        }
    }

    XML insertChildBefore(Object child, Object value) {
        if (length() == 1) {
            return getFromAxiomNodeList(0).insertChildBefore(child, value);
        } else {
            throw ScriptRuntime.typeError("insertChildBefore" + LIST_WITH_ONE_ITEM);
        }
    }

    public int length() {
        return _axiomNodeList.size();
    }

    String localName() {
        if (length() == 1) {
            return name().localName();
        } else {
            throw ScriptRuntime.typeError("localName" + LIST_WITH_ONE_ITEM);
        }
    }

    QName name() {
        if (length() == 1) {
            return getFromAxiomNodeList(0).name();
        } else {
            throw ScriptRuntime.typeError("name" + LIST_WITH_ONE_ITEM);
        }
    }

    Object namespace(String prefix) {
        if (length() == 1) {
            return getFromAxiomNodeList(0).namespace(prefix);
        } else {
            throw ScriptRuntime.typeError("namespace" + LIST_WITH_ONE_ITEM);
        }
    }

    Object[] namespaceDeclarations() {
        if (length() == 1) {
            return getFromAxiomNodeList(0).namespaceDeclarations();
        } else {
            throw ScriptRuntime.typeError("namespaceDeclarations" + LIST_WITH_ONE_ITEM);
        }
    }

    String nodeKind() {
        if (length() > 1) {
            throw ScriptRuntime.typeError("nodeKind" + LIST_WITH_ONE_ITEM);
        } else {
            XML xml = getFromAxiomNodeList(0);
            if (xml != null)
                return xml.nodeKind();
        }
        return null;
    }

    /**
     * If list is empty, return undefined, if elements have different parents return undefined,
     * If they all have the same parent, return that parent.
     *
     * @return
     */
    Object parent() {
        Object sameParent = Undefined.instance;

        if ((length() == 0) && (targetObject != null) && (targetObject instanceof XML)) {
            sameParent = targetObject;
        } else {
            for (int i = 0; i < length(); i++) {
                Object currParent = getFromAxiomNodeList(i).parent();

                if (i == 0) {
                    // Set the first for the rest to compare to.
                    sameParent = currParent;
                } else if (sameParent != currParent) {
                    sameParent = Undefined.instance;
                    break;
                }
            }
        }

        // If everything in the list is the sameParent then return that as the parent.
        return sameParent;
    }

    XML prependChild(Object value) {
        if (length() == 1) {
            return getFromAxiomNodeList(0).prependChild(value);
        } else {
            throw ScriptRuntime.typeError("prependChild" + LIST_WITH_ONE_ITEM);
        }
    }

    boolean propertyIsEnumerable(Object member) {
        long index;
        if (member instanceof Integer) {
            index = ((Integer) member).intValue();
        } else if (member instanceof Number) {
            double x = ((Number) member).doubleValue();
            index = (long) x;
            if ((double) index != x) {
                return false;
            }
            if (index == 0 && 1.0 / x < 0) {
                // Negative 0
                return false;
            }
        } else {
            String s = ScriptRuntime.toString(member);
            index = ScriptRuntime.testUint32String(s);
        }
        return (0 <= index && index < length());
    }

    XML removeNamespace(Namespace ns) {
        if (length() == 1) {
            return getFromAxiomNodeList(0).removeNamespace(ns);
        } else {
            throw ScriptRuntime.typeError("prependChild" + LIST_WITH_ONE_ITEM);
        }
    }

    XML replace(long index, Object xml) {
        if (length() == 1) {
            return getFromAxiomNodeList(0).replace(index, xml);
        } else {
            throw ScriptRuntime.typeError("replace" + LIST_WITH_ONE_ITEM);
        }
    }

    XML replace(XMLName name, Object xml) {
        if (length() == 1) {
            return getFromAxiomNodeList(0).replace(name, xml);
        } else {
            throw ScriptRuntime.typeError("replace" + LIST_WITH_ONE_ITEM);
        }
    }

    XML setChildren(Object xml) {
        if (length() == 1) {
            return getFromAxiomNodeList(0).setChildren(xml);
        } else {
            throw ScriptRuntime.typeError("setChild" + LIST_WITH_ONE_ITEM);
        }
    }

    void setLocalName(String localName) {
        if (length() == 1) {
            getFromAxiomNodeList(0).setLocalName(localName);
        } else {
            throw ScriptRuntime.typeError("setLocalName" + LIST_WITH_ONE_ITEM);
        }
    }

    void setName(QName qname) {
        if (length() == 1) {
            getFromAxiomNodeList(0).setName(qname);
        } else {
            throw ScriptRuntime.typeError("seName" + LIST_WITH_ONE_ITEM);
        }
    }

    void setNamespace(Namespace ns) {
        if (length() == 1) {
            getFromAxiomNodeList(0).setNamespace(ns);
        } else {
            throw ScriptRuntime.typeError("setNamespace" + LIST_WITH_ONE_ITEM);
        }
    }

    XMLList text() {
        XMLList xmlList = new XMLList(lib);
        for (int i = 0; i < length(); i++)
            xmlList.addToList(getFromAxiomNodeList(i).text());
        return xmlList;
    }

    public String toString() {
        if (hasSimpleContent()) {
            StringBuffer stringBuffer = new StringBuffer();

            for (int i = 0; i < length(); i++) {
                XML next = getFromAxiomNodeList(i);
                stringBuffer.append(next.toString());
            }
            return stringBuffer.toString();

        } else {
            return toXMLString(0);

        }
    }

    String toXMLString(int indent) {
        StringBuffer stringBuffer = new StringBuffer();

        for (int i = 0; i < length(); i++) {
            if (i > 0) {
                stringBuffer.append('\n');
            }

            stringBuffer.append(getFromAxiomNodeList(i).toXMLString(indent));
        }
        return stringBuffer.toString();
    }

    Object valueOf() {
        return this;
    }

    Object getXmlObject() {

        int length = length();
        OMNode[] omNodes = new OMNode[length];
        for (int i = 0; i < length; i++) {
            XML xml = getFromAxiomNodeList(i);
            Object object = xml.getXmlObject();
            // If its an OMAttribute we take its value and create an OMText from it as we have to be
            // returning an OMNode.
            if (object instanceof OMAttribute) {
                OMAttribute omAttribute = (OMAttribute) object;
                omNodes[i] = xml.getAxiomNode().getOMFactory()
                        .createOMText(omAttribute.getAttributeValue());
            } else {
                omNodes[i] = (OMNode) object;
            }
        }
        return omNodes;
    }

    public void addAxiomNode(AxiomNode axiomNode) {
        if (axiomNode != null)
            _axiomNodeList.add(axiomNode);
    }

    void addToList(Object toAdd) {
        if (toAdd instanceof Undefined)
            return;

        if (toAdd instanceof XMLList) {
            XMLList xmlListToAdd = (XMLList) toAdd;
            for (int i = 0; i < xmlListToAdd.length(); i++)
                addAxiomNode((AxiomNode) xmlListToAdd._axiomNodeList.get(i));

        } else if (toAdd instanceof XML) {
            addAxiomNode(((XML) toAdd).getAxiomNode());
        }
    }

    void remove() {
        int nLen = length();
        for (int i = nLen - 1; i >= 0; i--) {
            XML xml = getFromAxiomNodeList(i);
            if (xml != null) {
                xml.remove();
                removeFromList(i);
            }
        }
    }

    private void removeFromList(int index) {
        _axiomNodeList.remove(index);
    }

    private void insertAttribute(XMLName xmlName, Object value) {
        for (int i = 0; i < length(); i++) {
            XML xml = getFromAxiomNodeList(i);
            xml.getAxiomNode().insertAttribute(xmlName, value);
        }
    }

    public void setTargets(XMLObjectImpl targetObject, javax.xml.namespace.QName targetProperty) {
        this.targetObject = targetObject;
        this.targetProperty = targetProperty;
    }

    XML getFromAxiomNodeList(int index) {
        XML xmlObject;

        if (index >= 0 && index < length()) {
            AxiomNode axiomNode = (AxiomNode) _axiomNodeList.get(index);
            xmlObject = XML.getFromAxiomNode(lib, axiomNode);
        } else {
            xmlObject = null;
        }

        return xmlObject;
    }

    void replace(int index, XML xml) {
        if (index < length()) {
            ArrayList axiomNodeList = new ArrayList();

            // Copy upto item to replace.
            for (int i = 0; i < index; i++) {
                axiomNodeList.add(_axiomNodeList.get(i));
            }

            axiomNodeList.add(xml.getAxiomNode());

            // Skip over old item we're going to replace we've already add new item on above line.
            for (int i = index + 1; i < length(); i++) {
                axiomNodeList.add(_axiomNodeList.get(i));
            }

            _axiomNodeList = axiomNodeList;
        }
    }

    void insert(int index, XML xml) {
        if (index < length()) {
            ArrayList axiomNodeList = new ArrayList();

            // Copy upto item to replace.
            for (int i = 0; i < index; i++) {
                axiomNodeList.add(_axiomNodeList.get(i));
            }

            axiomNodeList.add(xml.getAxiomNode());

            // Skip over old item we're going to replace we've already add new item on above line.
            for (int i = index; i < length(); i++) {
                axiomNodeList.add(_axiomNodeList.get(i));
            }

            _axiomNodeList = axiomNodeList;
        }
    }

    static XMLList toXMLList(XMLLibImpl lib, Object value) {
        String xmlString;
        List axiomNodeList;
        XMLList xmlList;

        if (value instanceof XML) {
            XML xml = (XML) value;
            axiomNodeList = new ArrayList(1);
            axiomNodeList.add(xml.getAxiomNode());
            xmlList = new XMLList(lib, axiomNodeList);
            xmlList.targetObject = (XMLObjectImpl) xml.parent();
            xmlList.targetProperty = xml.getAxiomNode().getQName();

        } else if (value instanceof String || value instanceof Number || value instanceof Boolean) {
            xmlString = ScriptRuntime.toString(value);
            //Remove anonymous start tag and end tag
            if (xmlString.startsWith("<>") && xmlString.endsWith("</>")) {
                xmlString = xmlString.substring(2, xmlString.length() - 3);

            } else if (xmlString.startsWith("<>") || xmlString.endsWith("</>")) {
                throw ScriptRuntime
                        .typeError("XML with anonymous tag missing, start or end anonymous tag");
            }

            xmlString = "<parent>" + xmlString +
                    "</parent>";  //Avoid having several top level XML elements

            XML xml = XML.toXML(lib, xmlString);
            axiomNodeList = new ArrayList();
            OMNode omNode;
            Iterator iterator = xml.getAxiomNode().getOMElement().getChildren();
            while (iterator.hasNext()) {
                omNode = (OMNode) iterator.next();
                if (!(omNode.getType() == OMNode.TEXT_NODE &&
                        (((OMText) omNode).getTextCharacters())[0] == '\n')) {
                    axiomNodeList.add(AxiomNode.buildAxiomNode(omNode, xml.getAxiomNode()));
                }
            }
            xmlList = new XMLList(lib, axiomNodeList);

        } else if (value instanceof XMLList) {
            //TODO handle cloning of axiomNodes
            xmlList = new XMLList(lib, ((XMLList) value)._axiomNodeList);

        } else {
            throw ScriptRuntime.typeError("Invalid argument");
        }

        return xmlList;
    }

    public OMNode[] getAxiomFromXML() {
        return (OMNode[]) getXmlObject();
    }


}
