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

import org.eclipse.wst.command.internal.env.context.PersistentContext;
import org.wso2.wsf.ide.core.plugin.WebServiceWSASCorePlugin;

public class PersistentWSASEmitterContext extends PersistentContext implements
		WSASEmitterContext {

	private static PersistentWSASEmitterContext context_ = null;

	public static PersistentWSASEmitterContext getInstance() 
	{
		if (context_ == null) {
			context_ = new PersistentWSASEmitterContext();
			context_.load();
		}
		return context_;
	}
	
	public void load(){
		setDefault(PREFERENCE_WSAS_RUNTIME_LOCATION, WSASEmitterDefaults.getWSASRuntimeLocation());
		setDefault(PREFERENCE_WSAS_RUNTIME_SET, WSASEmitterDefaults.getWSASRuntimeLocationSet());
		setDefault(PREFERENCE_DEBUG_PORT, WSASEmitterDefaults.getDebugPort());
		
		setDefault(PREFERENCE_SERVICE_DATABINDING, WSASEmitterDefaults.getServiceDatabinding());
		setDefault(PREFERENCE_SERVICE_INTERFACE_SKELETON, WSASEmitterDefaults.isServiceInterfaceSkeleton());
		setDefault(PREFERENCE_SERVICE_GENERATE_ALL, WSASEmitterDefaults.isServiceGenerateAll());
		//client defaults
		setDefault(PREFERENCE_CLIENT_SYNC, WSASEmitterDefaults.isClientSync());
		setDefault(PREFERENCE_CLIENT_ASYNC, WSASEmitterDefaults.isClientAsync());
		setDefault(PREFERENCE_CLIENT_DATABINDING, WSASEmitterDefaults.getClientDatabinding());
		setDefault(PREFERENCE_CLIENT_TESTCASE, WSASEmitterDefaults.isClientTestCase());
		setDefault(PREFERENCE_CLIENT_GENERATE_ALL, WSASEmitterDefaults.isClientGenerateAll());
		setDefault(PREFERENCE_CLIENT_UNPACK_CLASSES, WSASEmitterDefaults.isClientUnpackClasses());
		//AAR Defaults
		setDefault(PREFERENCE_AAR_EXTENTION, WSASEmitterDefaults.getAarExtention());

		
	}
	
	private PersistentWSASEmitterContext() 	{
		super(WebServiceWSASCorePlugin.getDefault());
	}

	public String getWSASRuntimeLocation() {
		return getValueAsString(PREFERENCE_WSAS_RUNTIME_LOCATION);
	}

	public void setWSASRuntimeLocation(String runtimeLocation) {
		setValue(PREFERENCE_WSAS_RUNTIME_LOCATION, runtimeLocation);
	}
	
	public boolean isCorrectWSASPathSet() {
		return getValueAsBoolean(PREFERENCE_WSAS_RUNTIME_SET);
	}

	public void setCorrectWSASPathSet(boolean runtimeLocationSet) {
		setValue(PREFERENCE_WSAS_RUNTIME_SET, runtimeLocationSet);
	}
	
	//Service 
	
	public String getServiceDatabinding() {
		return getValueAsString(PREFERENCE_SERVICE_DATABINDING);
	}
	
	public void setServiceDatabinding(String serviceDatabinding) {
		setValue(PREFERENCE_SERVICE_DATABINDING, serviceDatabinding);
	}
	
	public boolean isServiceInterfaceSkeleton() {
		return getValueAsBoolean(PREFERENCE_SERVICE_INTERFACE_SKELETON);
	}
	
	public void setServiceInterfaceSkeleton(boolean serviceInterfaceSkeleton) {
		setValue(PREFERENCE_SERVICE_INTERFACE_SKELETON, serviceInterfaceSkeleton);	
	}	
		
	public boolean isServiceGenerateAll() {
		return getValueAsBoolean(PREFERENCE_SERVICE_GENERATE_ALL);
	}
	
	public void setServiceGenerateAll(boolean serviceGenerateAll) {
		setValue(PREFERENCE_SERVICE_GENERATE_ALL, serviceGenerateAll);
	}
	
	
	//Client
	
	public boolean isSync() {
		return getValueAsBoolean(PREFERENCE_CLIENT_SYNC);
	}
	
	public void setSync(boolean clientSync) {
		setValue(PREFERENCE_CLIENT_SYNC, clientSync);
	}

	public boolean isAsync() {
		return getValueAsBoolean(PREFERENCE_CLIENT_ASYNC);
	}
	
	public void setAsync(boolean clientAsync) {
		setValue(PREFERENCE_CLIENT_ASYNC, clientAsync);
	}
	
	public String getClientDatabinding() {
		return getValueAsString(PREFERENCE_CLIENT_DATABINDING);
	}
	
	public void setClientDatabinding(String clientDatabinding) {
		setValue(PREFERENCE_CLIENT_DATABINDING, clientDatabinding);
	}
	
	public boolean isClientTestCase() {
		return getValueAsBoolean(PREFERENCE_CLIENT_TESTCASE);
	}
	
	public void setClientTestCase(boolean clientTestCase) {
		setValue(PREFERENCE_CLIENT_TESTCASE, clientTestCase);
	}

	public boolean isClientGenerateAll() {
		return getValueAsBoolean(PREFERENCE_CLIENT_GENERATE_ALL);
	}

	public void setClientGenerateAll(boolean clientGenrateAll) {
		setValue(PREFERENCE_CLIENT_GENERATE_ALL, clientGenrateAll);
	}
	
	public boolean isClientUnpackClasses() {
		return getValueAsBoolean(PREFERENCE_CLIENT_UNPACK_CLASSES);
	}

	public void setClientUnpackClasses(boolean clientUnpackClasses) {
		setValue(PREFERENCE_CLIENT_UNPACK_CLASSES, clientUnpackClasses);
	}
	
	//AAR Options
	
	public String getAarExtention(){
		return getValueAsString(PREFERENCE_AAR_EXTENTION);
	}
	
	public void setAarExtention(String aarExtention){
		setValue(PREFERENCE_AAR_EXTENTION, aarExtention);
	}

	//Debug Options 
	public String getDebuPort() {
		return getValueAsString(PREFERENCE_DEBUG_PORT);
	}

	public String getDebugHost() {
		return getValueAsString(PREFERENCE_DEBUG_HOST);
	}

	public void setDebuPort(String debuPort) {
		setValue(PREFERENCE_DEBUG_PORT, debuPort);
		
	}

	public void setDebugHost(String debugHost) {
		setValue(PREFERENCE_DEBUG_HOST, debugHost);
	}

}
