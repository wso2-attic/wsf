package org.apache.axis2.wsdl.databinding;

import org.apache.axis2.namespace.Constants;
import org.apache.axis2.wsdl.i18n.CodegenMessages;

import javax.xml.namespace.QName;

/**
 * Created by IntelliJ IDEA.
 * User: NandikaJayawardana
 * Date: Mar 11, 2009
 * Time: 10:57:12 AM
 * To change this template use File | Settings | File Templates.
 */
public class CPPTypeMapper extends TypeMappingAdapter {

    private String defaultClassName = "wso2wsf::OMElement*";

    public CPPTypeMapper() {
    }

    public String getTypeMappingName(QName qname) {

        if ((qname != null)) {
            Object o = qName2NameMap.get(qname);
            if (o != null) {
                return (String)o;
            } else if (Constants.XSD_ANYTYPE.equals(qname) ||
                    Constants.XSD_ANY.equals(qname)) {
                return defaultClassName;
            } else {
                throw new UnmatchedTypeException(
                        CodegenMessages.getMessage("databinding.typemapper.typeunmatched",
                                                   qname.getLocalPart(),
                                                   qname.getNamespaceURI())
                );
            }
        } else {
            return null;
        }
    }

    public String getDefaultMappingName() {
        return defaultClassName;
    }

    public void setDefaultMappingName(String defaultMapping) {
        this.defaultClassName = defaultMapping;
    }

}

