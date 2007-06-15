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

import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;

public class WSASEmitterDefaults {

	public static final String PREFERENCE_WSAS_RUNTIME_LOCATION_DEFAULT = "";
	//Axis2 Preferences
	//Service Code generation Options
	public static final String PREFERENCE_SERVICE_DATABINDING_DEFAULT = WSASCoreUIMessages.ADB;

	//Client Code generation Options
	public static final String PREFERENCE_CLIENT_DATABINDING_DEFAULT  = WSASCoreUIMessages.ADB;


	/**
	 * @return returns the default setting for runtime location.
	 */
	public static String getWSASRuntimeLocation() {
		return PREFERENCE_WSAS_RUNTIME_LOCATION_DEFAULT;
	}
	
	//Service Code generation Options

	public static String getServiceDatabinding(){
		return PREFERENCE_SERVICE_DATABINDING_DEFAULT;
	}

	
	public static String getClientDatabinding(){
		return PREFERENCE_CLIENT_DATABINDING_DEFAULT;
	}


}
