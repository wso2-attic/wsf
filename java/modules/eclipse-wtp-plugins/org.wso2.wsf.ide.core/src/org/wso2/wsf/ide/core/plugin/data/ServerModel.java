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
package org.wso2.wsf.ide.core.plugin.data;

import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;

public class ServerModel {
	
	//WSAS Runtime
	private static String wsasServerPath;
	
	//WSAS Preferences
	//Service Codegen Options
	private static String serviceDatabinding = WSASCoreUIMessages.ADB;
	private static boolean serviceTestcase = false;
	private static boolean serviceInterfaceSkeleton = false;
	private static boolean serviceGenerateAll = false;
	
	//Client Codegen Options
	private static boolean sync = false;
	private static boolean async = false;
	private static String cleintDatabinding = WSASCoreUIMessages.ADB;
	private static boolean clientTestcase = false;
	private static boolean clientGenerateAll = false;
	
	//Service Archive Options
	private static String aarExtention = WSASCoreUIMessages.AAR;

	public static String getWsasServerPath() {
		return wsasServerPath;
	}

	public static void setWsasServerPath(String wsasServerPathParam) {
		wsasServerPath = wsasServerPathParam;
	}

	public static String getAarExtention() {
		return aarExtention;
	}

	public static void setAarExtention(String aarExtention) {
		ServerModel.aarExtention = aarExtention;
	}

	public static boolean isAsync() {
		return async;
	}

	public static void setAsync(boolean async) {
		ServerModel.async = async;
	}

	public static String getCleintDatabinding() {
		return cleintDatabinding;
	}

	public static void setCleintDatabinding(String cleintDatabinding) {
		ServerModel.cleintDatabinding = cleintDatabinding;
	}

	public static boolean isClientGenerateAll() {
		return clientGenerateAll;
	}

	public static void setClientGenerateAll(boolean clientGenerateAll) {
		ServerModel.clientGenerateAll = clientGenerateAll;
	}

	public static boolean isClientTestcase() {
		return clientTestcase;
	}

	public static void setClientTestcase(boolean clientTestcase) {
		ServerModel.clientTestcase = clientTestcase;
	}

	public static String getServiceDatabinding() {
		return serviceDatabinding;
	}

	public static void setServiceDatabinding(String serviceDatabinding) {
		ServerModel.serviceDatabinding = serviceDatabinding;
	}

	public static boolean isServiceGenerateAll() {
		return serviceGenerateAll;
	}

	public static void setServiceGenerateAll(boolean serviceGenerateAll) {
		ServerModel.serviceGenerateAll = serviceGenerateAll;
	}

	public static boolean isServiceInterfaceSkeleton() {
		return serviceInterfaceSkeleton;
	}

	public static void setServiceInterfaceSkeleton(boolean serviceInterfaceSkeleton) {
		ServerModel.serviceInterfaceSkeleton = serviceInterfaceSkeleton;
	}

	public static boolean isServiceTestcase() {
		return serviceTestcase;
	}

	public static void setServiceTestcase(boolean serviceTestcase) {
		ServerModel.serviceTestcase = serviceTestcase;
	}

	public static boolean isSync() {
		return sync;
	}

	public static void setSync(boolean sync) {
		ServerModel.sync = sync;
	}

}
