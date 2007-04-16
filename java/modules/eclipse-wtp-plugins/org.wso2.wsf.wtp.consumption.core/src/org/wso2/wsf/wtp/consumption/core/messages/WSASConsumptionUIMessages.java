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
package org.wso2.wsf.wtp.consumption.core.messages;

import org.eclipse.osgi.util.NLS;

public final class WSASConsumptionUIMessages extends NLS {

	private static final String BUNDLE_NAME = "org.wso2.wsf.wtp.consumption.core.messages.WSASConsumptionUI";//$NON-NLS-1$

	private WSASConsumptionUIMessages() {
		// Do not instantiate
	}

	public static String LABEL_SERVICE_NAME_CAPTION;
	public static String LABEL_GENERATE_TESTCASE_CAPTION;
	public static String LABEL_DATABINDING_CAPTION;
	public static String LABEL_PORTNAME;
	public static String LABEL_GENERATE_ALL;
	public static String LABEL_PACKEGE_NAME;
	public static String LABEL_NAMESPACE;
	public static String LABEL_PACKAGE;
	public static String LABEL_NAMESPACE_TO_PACKAGE;
	public static String LABEL_CLIENT_SIDE;
	public static String LABEL_SYNC_AND_ASYNC;
	public static String LABEL_SYNC;
	public static String LABEL_ASYNC;
	public static String LABEL_DATA_MODEL;
	
	public static String MSG_ERROR_DEFAULT;

	public static String PAGE_TITLE_WS_AXIS2_PROXY;
	public static String PAGE_DESC_WS_AXIS2_PROXY;
	


	public static String TOOLTIP_PPAE_PAGE;
	public static String BUTTON_ALL_WANTED;
	
	public static String DIR_DYNAMIC_PROJECT_WEBSERVICES;
	public static String DIR_BUILD;
	public static String DIR_SRC;
	public static String DIR_CLASSES;
	public static String DIR_RESOURCES;
	public static String DIR_AAR;
	public static String DIR_META_INF;
	public static String DIR_WEB_INF;
	public static String DIR_SERVICES;
	public static String DIR_WEBSERVICES;
	public static String DIR_WEBCONTENT;
	public static String DIR_WORKSPACE;
	public static String DIR_AXIS2;
	public static String DIR_PLUGINS;
	public static String DIR_DOT_METADATA;
	public static String DIR_DOT_PLUGINS;
	public static String DIR_LIB;
	
	public static String ERROR_INVALID_FILE_READ_WRITEL;
	public static String ERROR_INVALID_WSDL_FILE_READ_WRITEL;
	public static String ERROR_CODEGEN_EXCEPTION;
	
	public static String AXIS2_RUNTIME;
	public static String AXIS2_PROJECT;
	public static String PATH_TO_AXIS2_LIBS;
	public static String USER_WORK_DIRECTORY;
	public static String SPLIT_WORKSPACE;
	public static String WEB_INF_LIB;
	public static String CODEGEN_RESULTS;
	
	public static String DATA_BINDING_ADB;
	public static String DATA_BINDING_NONE;
	
	public static String AXIS2_PLUGIN;
	
	static {
		NLS.initializeMessages(BUNDLE_NAME, WSASConsumptionUIMessages.class);
	}
}
