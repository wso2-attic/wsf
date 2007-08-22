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
	public static final boolean PREFERENCE_WSAS_RUNTIME_SET_DEFAULT = false;
	public static final String PREFERENCE_WSAS_DEBUG_PORT_DEFAULT = "8088";
	
	//Axis2 Preferences
	//Service Code generation Options
	public static final String PREFERENCE_SERVICE_DATABINDING_DEFAULT = WSASCoreUIMessages.ADB;
	public static final boolean PREFERENCE_SERVICE_INTERFACE_SKELETON_DEFAULT = false;
	public static final boolean PREFERENCE_SERVICE_GENERATE_ALL_DEFAULT = false;

	//Client Code generation Options
	public static final boolean PREFERENCE_CLIENT_SYNC_DEFAULT =  false;
	public static final boolean PREFERENCE_CLIENT_ASYNC_DEFAULT =  false;
	public static final String PREFERENCE_CLIENT_DATABINDING_DEFAULT  = WSASCoreUIMessages.ADB;
	public static final boolean PREFERENCE_CLIENT_TESTCASE_DEFAULT = false;
	public static final boolean PREFERENCE_CLIENT_GENERATE_ALL_DEFAULT = false;
	public static final boolean PREFERENCE_CLIENT_UNPACK_CLASSES_DEFAULT = false;
	
	//Service Archive Options
	private static String PREFERENCE_AAR_EXTENTION_DEFAULT  = WSASCoreUIMessages.AAR;	//aarExtention

	/**
	 * @return returns the default setting for runtime location.
	 */
	public static String getWSASRuntimeLocation() {
		return PREFERENCE_WSAS_RUNTIME_LOCATION_DEFAULT;
	}
	
	public static boolean getWSASRuntimeLocationSet() {
		return PREFERENCE_WSAS_RUNTIME_SET_DEFAULT;
	}
	
	//Service Code generation Options

	public static String getServiceDatabinding(){
		return PREFERENCE_SERVICE_DATABINDING_DEFAULT;
	}

	public static boolean isServiceInterfaceSkeleton(){
		return PREFERENCE_SERVICE_INTERFACE_SKELETON_DEFAULT;
	}

	public static boolean isServiceGenerateAll(){
		return PREFERENCE_SERVICE_GENERATE_ALL_DEFAULT;
	}
	
	//Client Codegen Oprions
	public static boolean isClientSync(){
		return PREFERENCE_CLIENT_SYNC_DEFAULT;
	}

	public static boolean isClientAsync(){
		return PREFERENCE_CLIENT_ASYNC_DEFAULT;
	}

	public static String getClientDatabinding(){
		return PREFERENCE_CLIENT_DATABINDING_DEFAULT;
	}

	public static boolean isClientTestCase(){
		return PREFERENCE_CLIENT_TESTCASE_DEFAULT;
	}

	public static boolean isClientGenerateAll(){
		return PREFERENCE_CLIENT_GENERATE_ALL_DEFAULT;
	}
	
	public static boolean isClientUnpackClasses(){
		return PREFERENCE_CLIENT_UNPACK_CLASSES_DEFAULT;
	}

	//Service AAR Options
	public static String getAarExtention(){
		return PREFERENCE_AAR_EXTENTION_DEFAULT;
	}

	public static String getDebugPort() {
		return PREFERENCE_WSAS_DEBUG_PORT_DEFAULT;
	}


}
