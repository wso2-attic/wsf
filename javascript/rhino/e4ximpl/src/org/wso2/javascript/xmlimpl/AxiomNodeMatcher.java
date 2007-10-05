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

public interface AxiomNodeMatcher {

    public final static int ATTRIBUTES = 0;
    public final static int CHILDREN = 1;

    //match any localName and any namespaceURI
    public XMLList matchAnyQName(AxiomNode axiomNode, XMLList xmlList, int type);

    //match any localName with a given namespaceURI
    public XMLList matchAnyLocalName(AxiomNode axiomNode, XMLList xmlList, int type,
                                     String namespaceURI);

    //match any namespace with a given localName
    public XMLList matchAnyNamespace(AxiomNode axiomNode, XMLList xmlList, int type,
                                     String LocalName, String namespaceURI);

    //match given QName;
    public XMLList matchQName(AxiomNode axiomNode, XMLList xmlList, int type,
                              javax.xml.namespace.QName qname);
}
