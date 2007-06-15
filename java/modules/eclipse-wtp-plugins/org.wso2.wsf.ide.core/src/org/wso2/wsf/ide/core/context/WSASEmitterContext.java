/*
 * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
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
package org.wso2.wsf.ide.core.context;

public interface WSASEmitterContext {
	
	/**
	 * This constant string is used to lookup the runtime location general
	 * preference from the plugins local preferences store.
	 */
	public static final String PREFERENCE_WSAS_RUNTIME_LOCATION = "wsasRuntimeLocation";
	//WSAS Preferences
	//Service Code generation Options
	public static final String PREFERENCE_SERVICE_DATABINDING = "serviceDatabinding"; 
	
	//Client Code generation Options
	public static final String PREFERENCE_CLIENT_DATABINDING = "cleintDatabinding"; 
	
	
	/**
	 * @param selection set the WSAS runtime location.
	 */
	public void setWSASRuntimeLocation(String runtimeLocation);

	/**
	 * @param returns the WSAS runtime location.
	 */
	public String getWSASRuntimeLocation();
	
	//Service Code generation Options

	public void setServiceDatabinding(String serviceDatabinding);

	public String getServiceDatabinding();
	
	//Client Code generation Options

	public void setClientDatabinding(String clientDatabinding);

	public String getClientDatabinding();
}
