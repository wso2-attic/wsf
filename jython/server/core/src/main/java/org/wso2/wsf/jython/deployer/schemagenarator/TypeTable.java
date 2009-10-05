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

import javax.xml.namespace.QName;
import java.util.HashMap;

public abstract class
        TypeTable {

    protected HashMap simpleTypetoxsd;
    protected HashMap complexTypeMap;

    public TypeTable() {
        simpleTypetoxsd = new HashMap();
        complexTypeMap = new HashMap();
        populateSimpleTypes();
    }

    protected abstract void populateSimpleTypes();

    /**
     * Retuns the QNAme of the simple type given its name
     *
     * @param typeName - The type given in the annotation
     * @return -QName Representing the annotation type as a xs Type
     */
    public QName getSimpleSchemaTypeName(String typeName) {
        return (QName) simpleTypetoxsd.get(typeName);
    }

    /**
     * Adds a complex type to the complexTypeMap
     *
     * @param name       - The name of the complex type
     * @param schemaType - The schema Type of the complexType
     */
    public void addComplexSchema(String name, QName schemaType) {
        complexTypeMap.put(name, schemaType);
    }

    /**
     * Retuns the QNAme of the complex type given its name
     *
     * @param name - The name of the complexType
     * @return - The QName of the cmplexType
     */
    public QName getComplexSchemaType(String name) {
        return (QName) complexTypeMap.get(name);
    }

    /**
     * Given an annotation type returns the corresponding xs type
     *
     * @param typeName - The type given in the annotation
     * @return -QName Representing the annotation type as a xs Type
     */
    public QName getQNamefortheType(String typeName) {
        QName type = getSimpleSchemaTypeName(typeName);
        if (type == null) {
            type = getComplexSchemaType(typeName);
        }
        return type;
    }
}