/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Rhino code, released
 * May 6, 1999.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1997-2000
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Igor Bukanov
 *   Ethan Hugg
 *   Terry Lucas
 *   Milen Nankov
 *
 * Alternatively, the contents of this file may be used under the terms of
 * the GNU General Public License Version 2 or later (the "GPL"), in which
 * case the provisions of the GPL are applicable instead of those above. If
 * you wish to allow use of your version of this file only under the terms of
 * the GPL and not to allow others to use your version of this file under the
 * MPL, indicate your decision by deleting the provisions above and replacing
 * them with the notice and other provisions required by the GPL. If you do
 * not delete the provisions above, a recipient may use your version of this
 * file under either the MPL or the GPL.
 *
 * ***** END LICENSE BLOCK ***** */

package org.wso2.javascript.xmlimpl;

import org.mozilla.javascript.Context;
import org.mozilla.javascript.IdFunctionObject;
import org.mozilla.javascript.Kit;
import org.mozilla.javascript.NativeWith;
import org.mozilla.javascript.Node;
import org.mozilla.javascript.Ref;
import org.mozilla.javascript.ScriptRuntime;
import org.mozilla.javascript.Scriptable;
import org.mozilla.javascript.Undefined;
import org.mozilla.javascript.xml.XMLObject;

/**
 * This abstract class describes what all XML objects (XML, XMLList) should have in common.
 *
 * @see org.mozilla.javascript.xmlimpl.XML
 */
abstract class XMLObjectImpl extends XMLObject {
    private static final Object XMLOBJECT_TAG = new Object();
    public int f = 1;
    protected final XMLLibImpl lib;
    protected boolean prototypeFlag;

    private final static int
            Id_constructor = 1,
            Id_addNamespace = 2,
            Id_appendChild = 3,
            Id_attribute = 4,
            Id_attributes = 5,
            Id_child = 6,
            Id_childIndex = 7,
            Id_children = 8,
            Id_comments = 9,
            Id_contains = 10,
            Id_copy = 11,
            Id_descendants = 12,
            Id_elements = 13,
            Id_inScopeNamespaces = 14,
            Id_insertChildAfter = 15,
            Id_insertChildBefore = 16,
            Id_hasOwnProperty = 17,
            Id_hasComplexContent = 18,
            Id_hasSimpleContent = 19,
            Id_length = 20,
            Id_localName = 21,
            Id_name = 22,
            Id_namespace = 23,
            Id_namespaceDeclarations = 24,
            Id_nodeKind = 25,
            Id_normalize = 26,
            Id_parent = 27,
            Id_prependChild = 28,
            Id_processingInstructions = 29,
            Id_propertyIsEnumerable = 30,
            Id_removeNamespace = 31,
            Id_replace = 32,
            Id_setChildren = 33,
            Id_setLocalName = 34,
            Id_setName = 35,
            Id_setNamespace = 36,
            Id_text = 37,
            Id_toString = 38,
            Id_toSource = 39,
            Id_toXMLString = 40,
            Id_valueOf = 41,
            Id_getXmlObject = 42,
            MAX_PROTOTYPE_ID = 42;

    protected XMLObjectImpl(XMLLibImpl lib, XMLObject prototype) {
        super(lib.globalScope(), prototype);
        this.lib = lib;
    }

    final void exportAsJSClass(boolean sealed) {
        prototypeFlag = true;
        exportAsJSClass(MAX_PROTOTYPE_ID, lib.globalScope(), sealed);
    }

    //Overriden methods
    protected void initPrototypeId(int id) {
        String s;
        int arity;
        switch (id) {
            case Id_constructor: {
                IdFunctionObject ctor;
                if (this instanceof XML) {
                    ctor = new XMLCtor((XML) this, XMLOBJECT_TAG, id, 1);
                } else {
                    ctor = new IdFunctionObject(this, XMLOBJECT_TAG, id, 1);
                }
                initPrototypeConstructor(ctor);
                return;
            }

            case Id_addNamespace:
                arity = 1;
                s = "addNamespace";
                break;
            case Id_appendChild:
                arity = 1;
                s = "appendChild";
                break;
            case Id_attribute:
                arity = 1;
                s = "attribute";
                break;
            case Id_attributes:
                arity = 0;
                s = "attributes";
                break;
            case Id_child:
                arity = 1;
                s = "child";
                break;
            case Id_childIndex:
                arity = 0;
                s = "childIndex";
                break;
            case Id_children:
                arity = 0;
                s = "children";
                break;
            case Id_comments:
                arity = 0;
                s = "comments";
                break;
            case Id_contains:
                arity = 1;
                s = "contains";
                break;
            case Id_copy:
                arity = 0;
                s = "copy";
                break;
            case Id_descendants:
                arity = 1;
                s = "descendants";
                break;
            case Id_elements:
                arity = 2;
                s = "elements";
                break;
            case Id_hasComplexContent:
                arity = 0;
                s = "hasComplexContent";
                break;
            case Id_hasOwnProperty:
                arity = 1;
                s = "hasOwnProperty";
                break;
            case Id_hasSimpleContent:
                arity = 0;
                s = "hasSimpleContent";
                break;
            case Id_inScopeNamespaces:
                arity = 0;
                s = "inScopeNamespaces";
                break;
            case Id_insertChildAfter:
                arity = 2;
                s = "insertChildAfter";
                break;
            case Id_insertChildBefore:
                arity = 2;
                s = "insertChildBefore";
                break;
            case Id_length:
                arity = 0;
                s = "length";
                break;
            case Id_localName:
                arity = 0;
                s = "localName";
                break;
            case Id_name:
                arity = 0;
                s = "name";
                break;
            case Id_namespace:
                arity = 1;
                s = "namespace";
                break;
            case Id_namespaceDeclarations:
                arity = 0;
                s = "namespaceDeclarations";
                break;
            case Id_nodeKind:
                arity = 0;
                s = "nodeKind";
                break;
            case Id_normalize:
                arity = 0;
                s = "normalize";
                break;
            case Id_parent:
                arity = 0;
                s = "parent";
                break;
            case Id_prependChild:
                arity = 1;
                s = "prependChild";
                break;
            case Id_processingInstructions:
                arity = 1;
                s = "processingInstructions";
                break;
            case Id_propertyIsEnumerable:
                arity = 1;
                s = "propertyIsEnumerable";
                break;
            case Id_removeNamespace:
                arity = 1;
                s = "removeNamespace";
                break;
            case Id_replace:
                arity = 2;
                s = "replace";
                break;
            case Id_setChildren:
                arity = 1;
                s = "setChildren";
                break;
            case Id_setLocalName:
                arity = 1;
                s = "setLocalName";
                break;
            case Id_setName:
                arity = 1;
                s = "setName";
                break;
            case Id_setNamespace:
                arity = 1;
                s = "setNamespace";
                break;
            case Id_text:
                arity = 0;
                s = "text";
                break;
            case Id_toString:
                arity = 0;
                s = "toString";
                break;
            case Id_toSource:
                arity = 1;
                s = "toSource";
                break;
            case Id_toXMLString:
                arity = 1;
                s = "toXMLString";
                break;
            case Id_valueOf:
                arity = 0;
                s = "valueOf";
                break;

            case Id_getXmlObject:
                arity = 0;
                s = "getXmlObject";
                break;
            default:
                throw new IllegalArgumentException(String.valueOf(id));
        }
        initPrototypeMethod(XMLOBJECT_TAG, id, s, arity);
    }

    protected int findPrototypeId(String s) {
        int id = 0;
        String X = null;
        int c;
        L:
        switch (s.length()) {
            case 4:
                c = s.charAt(0);
                if (c == 'c') {
                    X = "copy";
                    id = Id_copy;
                } else if (c == 'n') {
                    X = "name";
                    id = Id_name;
                } else if (c == 't') {
                    X = "text";
                    id = Id_text;
                }
                break L;
            case 5:
                X = "child";
                id = Id_child;
                break L;
            case 6:
                c = s.charAt(0);
                if (c == 'l') {
                    X = "length";
                    id = Id_length;
                } else if (c == 'p') {
                    X = "parent";
                    id = Id_parent;
                }
                break L;
            case 7:
                c = s.charAt(0);
                if (c == 'r') {
                    X = "replace";
                    id = Id_replace;
                } else if (c == 's') {
                    X = "setName";
                    id = Id_setName;
                } else if (c == 'v') {
                    X = "valueOf";
                    id = Id_valueOf;
                }
                break L;
            case 8:
                switch (s.charAt(4)) {
                    case 'K':
                        X = "nodeKind";
                        id = Id_nodeKind;
                        break L;
                    case 'a':
                        X = "contains";
                        id = Id_contains;
                        break L;
                    case 'd':
                        X = "children";
                        id = Id_children;
                        break L;

                    case 'r':
                        X = "toString";
                        id = Id_toString;
                        break L;
                    case 'u':
                        X = "toSource";
                        id = Id_toSource;
                        break L;
                    case 'e': {
                        switch (s.charAt(0)) {
                            case 'c':
                                X = "comments";
                                id = Id_comments;
                                break L;
                            case 'e':
                                X = "elements";
                                id = Id_elements;
                                break L;
                        }
                    }
                }
                break L;
            case 9:
                switch (s.charAt(2)) {
                    case 'c':
                        X = "localName";
                        id = Id_localName;
                        break L;
                    case 'm':
                        X = "namespace";
                        id = Id_namespace;
                        break L;
                    case 'r':
                        X = "normalize";
                        id = Id_normalize;
                        break L;
                    case 't':
                        X = "attribute";
                        id = Id_attribute;
                        break L;
                }
                break L;
            case 10:
                c = s.charAt(0);
                if (c == 'a') {
                    X = "attributes";
                    id = Id_attributes;
                } else if (c == 'c') {
                    X = "childIndex";
                    id = Id_childIndex;
                }
                break L;
            case 11:
                switch (s.charAt(0)) {
                    case 'a':
                        X = "appendChild";
                        id = Id_appendChild;
                        break L;
                    case 'c':
                        X = "constructor";
                        id = Id_constructor;
                        break L;
                    case 'd':
                        X = "descendants";
                        id = Id_descendants;
                        break L;
                    case 's':
                        X = "setChildren";
                        id = Id_setChildren;
                        break L;
                    case 't':
                        X = "toXMLString";
                        id = Id_toXMLString;
                        break L;
                }
                break L;
            case 12:
                switch (s.charAt(0)) {
                    case 'a':
                        X = "addNamespace";
                        id = Id_addNamespace;
                        break L;
                    case 'g':
                        X = "getXmlObject";
                        id = Id_getXmlObject;
                        break L;
                    case 'p':
                        X = "prependChild";
                        id = Id_prependChild;
                        break L;
                    case 's':
                        c = s.charAt(3);
                        if (c == 'L') {
                            X = "setLocalName";
                            id = Id_setLocalName;
                        } else if (c == 'N') {
                            X = "setNamespace";
                            id = Id_setNamespace;
                        }
                        break L;
                }
                break L;
            case 14:
                X = "hasOwnProperty";
                id = Id_hasOwnProperty;

                break L;
            case 15:
                X = "removeNamespace";
                id = Id_removeNamespace;
                break L;
            case 16:
                c = s.charAt(0);
                if (c == 'h') {
                    X = "hasSimpleContent";
                    id = Id_hasSimpleContent;
                } else if (c == 'i') {
                    X = "insertChildAfter";
                    id = Id_insertChildAfter;
                }
                break L;
            case 17:
                c = s.charAt(3);
                if (c == 'C') {
                    X = "hasComplexContent";
                    id = Id_hasComplexContent;
                } else if (c == 'c') {
                    X = "inScopeNamespaces";
                    id = Id_inScopeNamespaces;
                } else if (c == 'e') {
                    X = "insertChildBefore";
                    id = Id_insertChildBefore;
                }
                break L;
            case 20:
                X = "propertyIsEnumerable";
                id = Id_propertyIsEnumerable;
                break L;
            case 21:
                X = "namespaceDeclarations";
                id = Id_namespaceDeclarations;
                break L;
            case 22:
                X = "processingInstructions";
                id = Id_processingInstructions;
                break L;
        }
        if (X != null && X != s && !X.equals(s)) id = 0;
        return id;
    }

    public Object execIdCall(IdFunctionObject f, Context cx, Scriptable scope,
                             Scriptable thisObj, Object[] args) {

        if (!f.hasTag(XMLOBJECT_TAG)) {
            return super.execIdCall(f, cx, scope, thisObj, args);
        }

        int id = f.methodId();

        if (id == Id_constructor) {
            return jsConstructor(cx, thisObj == null, args);
        }

        // All (XML|XMLList).prototype methods require thisObj to be XML
        if (!(thisObj instanceof XMLObjectImpl))
            throw incompatibleCallError(f);
        XMLObjectImpl xmlObject = (XMLObjectImpl) thisObj;

        switch (id) {
            case Id_appendChild:
                return xmlObject.appendChild(arg(args, 0));
            case Id_addNamespace: {
                Namespace ns = lib.castToNamespace(cx, arg(args, 0));
                return xmlObject.addNamespace(ns);
            }
            case Id_attribute: {
                XMLName xmlName = lib.toAttributeName(cx, arg(args, 0));
                return xmlObject.attribute(xmlName);
            }
            case Id_attributes:
                return xmlObject.attributes();
            case Id_child: {
                XMLName xmlName = lib.toXMLNameOrIndex(cx, arg(args, 0));
                if (xmlName == null) {
                    long index = ScriptRuntime.lastUint32Result(cx);
                    return xmlObject.child(index);
                } else {
                    return xmlObject.child(xmlName);
                }
            }
            case Id_childIndex:
                return ScriptRuntime.wrapInt(xmlObject.childIndex());
            case Id_children:
                return xmlObject.children();
            case Id_descendants: {
                XMLName xmlName = (args.length == 0)
                        ? XMLName.formStar()
                        : lib.toXMLName(cx, args[0]);
                return xmlObject.descendants(xmlName);
            }
            case Id_elements: {
                XMLName xmlName = (args.length == 0)
                        ? XMLName.formStar()
                        : lib.toXMLName(cx, args[0]);
                return xmlObject.elements(xmlName);
            }
            case Id_hasComplexContent:
                return ScriptRuntime.wrapBoolean(xmlObject.hasComplexContent());
            case Id_hasSimpleContent:
                return ScriptRuntime.wrapBoolean(xmlObject.hasSimpleContent());
            case Id_inScopeNamespaces: {
                Object[] array = xmlObject.inScopeNamespaces();
                return cx.newArray(scope, array);
            }
            case Id_insertChildAfter:
                return xmlObject.insertChildAfter(arg(args, 0), arg(args, 1));
            case Id_insertChildBefore:
                return xmlObject.insertChildBefore(arg(args, 0), arg(args, 1));
            case Id_length:
                return ScriptRuntime.wrapInt(xmlObject.length());
            case Id_localName:
                return xmlObject.localName();
            case Id_name:
                return xmlObject.name();
            case Id_namespace: {
                String prefix = (args.length > 0)
                        ? ScriptRuntime.toString(args[0]) : null;
                return xmlObject.namespace(prefix);
            }
            case Id_namespaceDeclarations: {
                Object[] array = xmlObject.namespaceDeclarations();
                return cx.newArray(scope, array);
            }
            case Id_nodeKind:
                return xmlObject.nodeKind();
            case Id_parent:
                return xmlObject.parent();
            case Id_prependChild:
                return xmlObject.prependChild(arg(args, 0));
            case Id_propertyIsEnumerable: {
                return ScriptRuntime.wrapBoolean(
                        xmlObject.propertyIsEnumerable(arg(args, 0)));
            }

            case Id_removeNamespace: {
                Namespace ns = lib.castToNamespace(cx, arg(args, 0));
                return xmlObject.removeNamespace(ns);
            }
            case Id_replace: {
                XMLName xmlName = lib.toXMLNameOrIndex(cx, arg(args, 0));
                Object arg1 = arg(args, 1);
                if (xmlName == null) {
                    long index = ScriptRuntime.lastUint32Result(cx);
                    return xmlObject.replace(index, arg1);
                } else {
                    return xmlObject.replace(xmlName, arg1);
                }
            }
            case Id_setLocalName: {
                String localName;
                Object arg = arg(args, 0);
                if (arg instanceof QName) {
                    localName = ((QName) arg).localName();
                } else {
                    localName = ScriptRuntime.toString(arg);
                }
                xmlObject.setLocalName(localName);
                return Undefined.instance;
            }
            case Id_setChildren:
                return xmlObject.setChildren(arg(args, 0));
            case Id_setName: {
                Object arg = (args.length != 0) ? args[0] : Undefined.instance;
                QName qname;
                if (arg instanceof QName) {
                    qname = (QName) arg;
                    if (qname.uri() == null) {
                        qname = lib.constructQNameFromString(cx, qname.localName());
                    } else {
                        // E4X 13.4.4.35 requires to always construct QName
                        qname = lib.constructQName(cx, qname);
                    }
                } else {
                    qname = lib.constructQName(cx, arg);
                }
                xmlObject.setName(qname);
                return Undefined.instance;
            }
            case Id_setNamespace: {
                Namespace ns = lib.castToNamespace(cx, arg(args, 0));
                xmlObject.setNamespace(ns);
                return Undefined.instance;
            }
            case Id_text:
                return xmlObject.text();
            case Id_toString:
                return xmlObject.toString();
            case Id_toXMLString: {
                int indent = ScriptRuntime.toInt32(args, 0);
                //return xmlObject.toXMLString(indent);
                return xmlObject.toXMLString(indent);
            }
            case Id_getXmlObject: {
                //int indent = ScriptRuntime.toInt32(args, 0);
                //return xmlObject.toXMLString(indent);
                return xmlObject.getXmlObject();
            }
        }
        return null;
/*




case Id_comments:
return xmlObject.comments();

case Id_contains:
return ScriptRuntime.wrapBoolean(
     xmlObject.contains(arg(args, 0)));

case Id_copy:
return xmlObject.copy();

case Id_hasOwnProperty: {
XMLName xmlName = lib.toXMLName(cx, arg(args, 0));
return ScriptRuntime.wrapBoolean(
     xmlObject.hasOwnProperty(xmlName));
}

case Id_normalize:
xmlObject.normalize();
return Undefined.instance;

case Id_processingInstructions: {
XMLName xmlName = (args.length > 0)
            ? lib.toXMLName(cx, args[0])
            : XMLName.formStar();
return xmlObject.processingInstructions(xmlName);
}

case Id_propertyIsEnumerable: {
return ScriptRuntime.wrapBoolean(
     xmlObject.propertyIsEnumerable(arg(args, 0)));
}

case Id_toSource: {
int indent = ScriptRuntime.toInt32(args, 0);
return xmlObject.toSource(indent);
}

case Id_getAxiomObject: {
org.apache.xmlbeans.XmlObject xmlObject = xmlObject.getXmlObject();
return Context.javaToJS(xmlObject, scope);
}       */
    }

    public void delete(String name) {
        throw new IllegalArgumentException("String: [" + name + "]");
    }

    public final Object addValues(Context cx, boolean thisIsLeft,
                                  Object value) {
        if (value instanceof XMLObject) {
            XMLObject v1, v2;
            if (thisIsLeft) {
                v1 = this;
                v2 = (XMLObject) value;
            } else {
                v1 = (XMLObject) value;
                v2 = this;
            }
            return lib.addXMLObjects(cx, v1, v2);
        }
        if (value == Undefined.instance) {
            // both "xml + undefined" and "undefined + xml" gives String(xml)
            return ScriptRuntime.toString(this);
        }

        return super.addValues(cx, thisIsLeft, value);
    }

    public final Object getDefaultValue(Class hint) {
        return toString();
    }

    protected final Object equivalentValues(Object value) {
        boolean result = equivalentXml(value);
        return result ? Boolean.TRUE : Boolean.FALSE;
    }


    /**
     * Implementation of ECMAScript [[Delete]].
     */
    public final boolean ecmaDelete(Context cx, Object id) {
        if (cx == null) cx = Context.getCurrentContext();
        XMLName xmlName = lib.toXMLNameOrIndex(cx, id);
        if (xmlName == null) {
            long index = ScriptRuntime.lastUint32Result(cx);
            // XXX Fix this
            delete((int) index);
            return true;
        }
        ecmaDeleteImpl(xmlName);
        return true;
    }

    /**
     * Implementation of ECMAScript [[Has]].
     */
    public final boolean ecmaHas(Context cx, Object id) {
        if (cx == null) cx = Context.getCurrentContext();
        XMLName xmlName = lib.toXMLNameOrIndex(cx, id);
        if (xmlName == null) {
            long index = ScriptRuntime.lastUint32Result(cx);
            // XXX Fix this cast
            return has((int) index, this);
        }
        return ecmaHasImpl(xmlName);
    }

    /**
     * Implementation of ECMAScript [[Get]]
     */
    public final Object ecmaGet(Context cx, Object id) {
        if (cx == null)
            cx = Context.getCurrentContext();

        XMLName xmlName = lib.toXMLNameOrIndex(cx, id);

        if (xmlName == null) {
            long index = ScriptRuntime.lastUint32Result(cx);
            // XXX Fix this cast
            Object result = get((int) index, this);
            if (result == Scriptable.NOT_FOUND) {
                result = Undefined.instance;
            }
            return result;
        }

        if (prototypeFlag) {
            String name = xmlName.localName();
            return getMethod(name);
        } else {
            return ecmaGetImpl(xmlName);
        }
    }

    /**
     * Implementation of ECMAScript [[Put]].
     */
    public final void ecmaPut(Context cx, Object id, Object value) {
        if (cx == null) cx = Context.getCurrentContext();
        XMLName xmlName = lib.toXMLNameOrIndex(cx, id);
        if (xmlName == null) {
            long index = ScriptRuntime.lastUint32Result(cx);
            // XXX Fix this cast
            put((int) index, this, value);
            return;
        }
        ecmaPutImpl(xmlName, value);
    }

    public NativeWith enterWith(Scriptable scope) {
        return new XMLWithScope(lib, scope, this);
    }

    public NativeWith enterDotQuery(Scriptable scope) {
        XMLWithScope xws = new XMLWithScope(lib, scope, this);
        xws.initAsDotQuery();
        return xws;
    }


    public Ref memberRef(Context cx, Object elem, int memberTypeFlags) {
        XMLName xmlName;
        if ((memberTypeFlags & Node.ATTRIBUTE_FLAG) != 0) {
            xmlName = lib.toAttributeName(cx, elem);
        } else {
            if ((memberTypeFlags & Node.DESCENDANTS_FLAG) == 0) {
                // Code generation would use ecma(Get|Has|Delete|Set) for
                // normal name idenrifiers so one ATTRIBUTE_FLAG
                // or DESCENDANTS_FLAG has to be set
                throw Kit.codeBug();
            }
            xmlName = lib.toXMLName(cx, elem);
        }
        if ((memberTypeFlags & Node.DESCENDANTS_FLAG) != 0) {
            xmlName.setIsDescendants();
        }
        xmlName.initXMLObject(this);
        return xmlName;
    }

    public Ref memberRef(Context cx, Object namespace, Object elem, int memberTypeFlags) {
        XMLName xmlName = lib.toQualifiedName(cx, namespace, elem);
        if ((memberTypeFlags & Node.ATTRIBUTE_FLAG) != 0) {
            if (!xmlName.isAttributeName()) {
                xmlName.setAttributeName();
            }
        }
        if ((memberTypeFlags & Node.DESCENDANTS_FLAG) != 0) {
            xmlName.setIsDescendants();
        }
        xmlName.initXMLObject(this);
        return xmlName;
    }

    final Object getMethod(String id) {
        return super.get(id, this);
    }

    private static Object arg(Object[] args, int i) {
        return (i < args.length) ? args[i] : Undefined.instance;
    }


    /**
     * ecmaHas(cx, id) calls this after resolving when id to XMLName
     * and checking it is not Uint32 index.
     */
    abstract boolean ecmaHasImpl(XMLName name);

    /**
     * ecmaGet(cx, id) calls this after resolving when id to XMLName
     * and checking it is not Uint32 index.
     */
    abstract Object ecmaGetImpl(XMLName name);

    /**
     * ecmaPut(cx, id, value) calls this after resolving when id to XMLName
     * and checking it is not Uint32 index.
     */
    abstract void ecmaPutImpl(XMLName name, Object value);

    /**
     * ecmaDelete(cx, id) calls this after resolving when id to XMLName
     * and checking it is not Uint32 index.
     */
    abstract void ecmaDeleteImpl(XMLName name);

    /**
     * Test XML equality with target the target.
     */
    abstract boolean equivalentXml(Object target);


    protected abstract Object jsConstructor(Context cx, boolean inNewExpr, Object[] args);

    // Methods from section 12.4.4 in the spec
    abstract XML addNamespace(Namespace ns);

    abstract XML appendChild(Object value);

    abstract XMLList attribute(XMLName xmlName);

    abstract XMLList attributes();

    abstract XMLList child(long index);

    abstract XMLList child(XMLName xmlName);

    abstract int childIndex();

    abstract XMLList children();

    abstract XMLList descendants(XMLName xmlName);

    abstract XMLList elements(XMLName xmlName);

    abstract boolean hasComplexContent();

    abstract boolean hasSimpleContent();

    abstract Object[] inScopeNamespaces();

    abstract XML insertChildAfter(Object child, Object value);

    abstract XML insertChildBefore(Object child, Object value);

    abstract int length();

    abstract String localName();

    abstract QName name();

    abstract Object namespace(String prefix);

    abstract Object[] namespaceDeclarations();

    abstract String nodeKind();

    abstract Object parent();

    abstract XML prependChild(Object value);

    abstract boolean propertyIsEnumerable(Object member);

    abstract XML removeNamespace(Namespace ns);

    abstract XML replace(long index, Object value);

    abstract XML replace(XMLName name, Object value);

    abstract XML setChildren(Object xml);

    abstract void setLocalName(String localName);

    abstract void setName(QName qname);

    abstract void setNamespace(Namespace ns);

    abstract XMLList text();

    public abstract String toString();

    abstract String toXMLString(int indent);

    abstract Object valueOf();

    abstract Object getXmlObject();

}

