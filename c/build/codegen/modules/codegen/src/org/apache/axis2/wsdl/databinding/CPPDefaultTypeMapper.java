package org.apache.axis2.wsdl.databinding;

import javax.xml.namespace.QName;

/**
 * Created by IntelliJ IDEA.
 * User: NandikaJayawardana
 * Date: Mar 11, 2009
 * Time: 10:55:43 AM
 * To change this template use File | Settings | File Templates.
 */
public class CPPDefaultTypeMapper  extends TypeMappingAdapter {
    private String CPPClassName = "wso2wsf::OMElement*";

    public CPPDefaultTypeMapper() {
    }

    /**
     * Gets the type mapping name. always returns the default mapping
     *
     * @see TypeMapper#getTypeMappingName(javax.xml.namespace.QName)
     */
    public String getTypeMappingName(QName qname) {

        if ((qname != null)) {
            return CPPClassName;
        } else {
            return null;
        }

    }
}
