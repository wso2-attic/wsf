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

import java.util.ArrayList;

public class ComplexType extends Type{

    private ArrayList<Type> members = new ArrayList<Type>();

    public ArrayList<Type> getMembers() {
        return members;
    }

    public void addMember(Type type) {
        members.add(type);
    }
}
