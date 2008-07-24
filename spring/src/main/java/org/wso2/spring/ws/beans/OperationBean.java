/*
 * Copyright 2005-2008 WSO2, Inc. (http://wso2.com)
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

package org.wso2.spring.ws.beans;

/**
 * The operation bean replaces the operations property
 * in the .xml configuration files. 
 */
public class OperationBean {
    private String name;
    private String namespace;
    private String mep;
    private String actionMapping;
    private String outputActionMapping;
    //TODO: Implement other attributes

    public void setName(String name) {
        this.name = name;
    }
    
	public String getName() {
		return name;
	}
	
	public String getNamespace() {
		return namespace;
	}

	public void setNamespace(String namespace) {
		this.namespace = namespace;
	}

	public String getActionMapping() {
		return actionMapping;
	}

	public void setActionMapping(String actionMapping) {
		this.actionMapping = actionMapping;
	}

	public String getOutputActionMapping() {
		return outputActionMapping;
	}

	public void setOutputActionMapping(String outputActionMapping) {
		this.outputActionMapping = outputActionMapping;
	}

	public String getMep() {
		return mep;
	}

	public void setMep(String mep) {
		this.mep = mep;
	}
}
