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
import org.mozilla.javascript.IdScriptableObject;
import org.mozilla.javascript.ScriptRuntime;
import org.mozilla.javascript.Scriptable;
import org.mozilla.javascript.Undefined;

public class Namespace extends IdScriptableObject {

    private XMLLibImpl lib;
    private String prefixValue;
    private String uriValue;

    private static final Object NAMESPACE_TAG = new Object();

    private static final int
            Id_constructor = 1,
            Id_toString = 2,
            Id_toSource = 3,
            Id_prefix = 1,
            Id_uri = 2,
            MAX_PROTOTYPE_ID = 3,
            MAX_INSTANCE_ID = 2;

    public Namespace(XMLLibImpl lib, String uriValue) {
        super(lib.globalScope(), lib.namespacePrototype);
        this.lib = lib;

        if (uriValue == null)
            throw new IllegalArgumentException();

        this.lib = lib;
        this.prefixValue = (uriValue.length() == 0) ? "" : null;
        this.uriValue = uriValue;
    }

    public Namespace(XMLLibImpl lib, String prefixValue, String uriValue) {
        super(lib.globalScope(), lib.namespacePrototype);

        if (uriValue == null)
            throw new IllegalArgumentException();
        if (uriValue.length() == 0) {
            // prefix should be "" for empty uri
            if (prefixValue == null)
                throw new IllegalArgumentException();
            if (prefixValue.length() != 0)
                throw new IllegalArgumentException();
        }

        this.lib = lib;
        this.prefixValue = prefixValue;
        this.uriValue = uriValue;
    }

    public void exportAsJSClass(boolean sealed) {
        exportAsJSClass(MAX_PROTOTYPE_ID, lib.globalScope(), sealed);
    }


    protected int getMaxInstanceId() {
        return super.getMaxInstanceId() + MAX_INSTANCE_ID;
    }

    protected int findInstanceIdInfo(String s) {
        int id = 0;
        String x = null;
        int length = s.length();

        if (length == 3) {
            x = "uri";
            id = Id_uri;
        } else if (length == 6) {
            x = "prefix";
            id = Id_prefix;
        }

        if (x != null && x != s && !x.equals(s)) id = 0;

        if (id == 0) return super.findInstanceIdInfo(s);

        int attr;
        switch (id) {
            case Id_prefix:
            case Id_uri:
                attr = PERMANENT | READONLY;
                break;
            default:
                throw new IllegalStateException();
        }
        return instanceIdInfo(attr, super.getMaxInstanceId() + id);
    }

    protected String getInstanceIdName(int id) {
        switch (id - super.getMaxInstanceId()) {
            case Id_prefix:
                return "prefix";
            case Id_uri:
                return "uri";
        }
        return super.getInstanceIdName(id);
    }

    protected Object getInstanceIdValue(int id) {
        switch (id - super.getMaxInstanceId()) {
            case Id_prefix:
                if (prefix() == null) return Undefined.instance;
                return prefix();
            case Id_uri:
                return uri();
        }
        return super.getInstanceIdValue(id);
    }

    protected Object equivalentValues(Object value) {
        if (!(value instanceof Namespace)) return Scriptable.NOT_FOUND;
        boolean result = equals((Namespace) value);
        return result ? Boolean.TRUE : Boolean.FALSE;
    }

    public boolean equals(Object obj) {
        if (!(obj instanceof Namespace)) return false;
        return equals((Namespace) obj);
    }

    private boolean equals(Namespace n) {
        return uri().equals(n.uri());
    }

    private Namespace realThis(Scriptable thisObj, IdFunctionObject f) {
        if (!(thisObj instanceof Namespace))
            throw incompatibleCallError(f);
        return (Namespace) thisObj;
    }

    protected int findPrototypeId(String s) {
        int id = 0;

        String x = null;
        int c;
        int length = s.length();
        if (length == 8) {
            c = s.charAt(3);
            if (c == 'o') {
                x = "toSource";
                id = Id_toSource;
            } else if (c == 't') {
                x = "toString";
                id = Id_toString;
            }
        } else if (length == 11) {
            x = "constructor";
            id = Id_constructor;
        }
        if (x != null && x != s && !x.equals(s)) id = 0;

        return id;
    }

    protected void initPrototypeId(int id) {
        String s;
        int arity;
        switch (id) {
            case Id_constructor:
                arity = 2;
                s = "constructor";
                break;
            case Id_toString:
                arity = 0;
                s = "toString";
                break;
            case Id_toSource:
                arity = 0;
                s = "toSource";
                break;
            default:
                throw new IllegalArgumentException(String.valueOf(id));
        }
        initPrototypeMethod(NAMESPACE_TAG, id, s, arity);
    }

    public Object execIdCall(IdFunctionObject f, Context cx, Scriptable scope, Scriptable thisObj,
                             Object[] args) {
        if (!f.hasTag(NAMESPACE_TAG)) {
            return super.execIdCall(f, cx, scope, thisObj, args);
        }
        int id = f.methodId();
        switch (id) {
            case Id_constructor:
                return namespaceConstructor(cx, (thisObj == null), args);
            case Id_toString:
                return realThis(thisObj, f).toString();
                //case Id_toSource:
                //  return realThis(thisObj, f).js_toSource();
        }
        throw new IllegalArgumentException(String.valueOf(id));
    }

    public String toString() {
        return uriValue;
    }

    public String getClassName() {
        return "Namespace";
    }

    private Object namespaceConstructor(Context cx, boolean inNewExpr, Object[] args) {
        Namespace namespace;

        if (!inNewExpr && args.length == 1 && args[0] instanceof Namespace) {
            namespace = lib.castToNamespace(cx, args[0]);
        }

        if (args.length == 0) {        //prefixValue is not specified and uriValue is not specified
            namespace = lib.constructNamespace(cx);

        } else if (args.length == 1) {           //prefixValue is not specified
            namespace = lib.constructNamespace(cx, args[0]);

        } else if (args.length == 2) {
            namespace = lib.constructNamespace(cx, args[0], args[1]);
        } else {
            throw ScriptRuntime.typeError(
                    "Cannot find a matching constructor. ");
        }

        return namespace;
    }

    public String uri() {
        return uriValue;
    }

    public String prefix() {
        return prefixValue;
    }
}
