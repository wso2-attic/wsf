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
	public static final String PREFERENCE_WSAS_RUNTIME_SET = "wsasRuntimeLocationSet";
	//WSAS Preferences
	//Debug Options
	public static final String PREFERENCE_DEBUG_HOST = "debugHost"; 
	public static final String PREFERENCE_DEBUG_PORT = "debuPort"; 
	
	//Service Code generation Options
	public static final String PREFERENCE_SERVICE_DATABINDING = "serviceDatabinding"; 
	public static final String PREFERENCE_SERVICE_INTERFACE_SKELETON = "serviceInterfaceSkeleton"; 
	public static final String PREFERENCE_SERVICE_GENERATE_ALL = "serviceGenerateAll"; 

	//Client Code generation Options
	public static final String PREFERENCE_CLIENT_SYNC = "sync"; 
	public static final String PREFERENCE_CLIENT_ASYNC = "async";
	public static final String PREFERENCE_CLIENT_DATABINDING = "cleintDatabinding";
	public static final String PREFERENCE_CLIENT_TESTCASE = "clientTestcase"; 
	public static final String PREFERENCE_CLIENT_GENERATE_ALL = "clientGenerateAll"; 
	public static final String PREFERENCE_CLIENT_UNPACK_CLASSES = "clientUnpackClasses"; 
	
	//Service Archive Options
	public static final String PREFERENCE_AAR_EXTENTION  = "aarExtention";

	/**
	 * @param selection set the WSAS runtime location.
	 */
	public void setWSASRuntimeLocation(String runtimeLocation);

	/**
	 * @param returns the WSAS runtime location.
	 */
	public String getWSASRuntimeLocation();

	public void setCorrectWSASPathSet(boolean runtimeLocationSet);

	public boolean isCorrectWSASPathSet();
	
	//Debug Options
	public void setDebugHost(String debugHost);

	public String getDebugHost();
	
	public void setDebuPort(String debuPort);

	public String getDebuPort();
	
	//Service Code generation Options
	public void setServiceDatabinding(String serviceDatabinding);

	public String getServiceDatabinding();
	
	public void setServiceInterfaceSkeleton(boolean serviceInterfaceSkeleton);

	public boolean isServiceInterfaceSkeleton();

	public void setServiceGenerateAll(boolean serviceGenerateAll);

	public boolean isServiceGenerateAll();
	
	//Client Code generation Options
	public void setSync(boolean clientSync);

	public boolean isSync();

	public void setAsync(boolean clientAsync);

	public boolean isAsync();

	public void setClientDatabinding(String clientDatabinding);

	public String getClientDatabinding();

	public void setClientTestCase(boolean clientTestCase);

	public boolean isClientTestCase();

	public void setClientGenerateAll(boolean clientGenerateAll);

	public boolean isClientGenerateAll();
	
	public void setClientUnpackClasses(boolean clientUnpackClasses);

	public boolean isClientUnpackClasses();

	//AAR Options
	public void setAarExtention(String aarExtention);

	public String getAarExtention();
}
