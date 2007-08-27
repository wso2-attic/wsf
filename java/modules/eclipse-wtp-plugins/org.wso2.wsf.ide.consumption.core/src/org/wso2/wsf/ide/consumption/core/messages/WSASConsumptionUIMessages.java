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
package org.wso2.wsf.ide.consumption.core.messages;

import org.eclipse.osgi.util.NLS;

public final class WSASConsumptionUIMessages extends NLS {

	private static final String BUNDLE_NAME = 
		"org.wso2.wsf.ide.consumption.core.messages.WSASConsumptionUI";//$NON-NLS-1$

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
	public static String LABEL_CLIENT_SIDE;
	public static String LABEL_SYNC_AND_ASYNC;
	public static String LABEL_SYNC;
	public static String LABEL_ASYNC;
	public static String LABEL_DATA_MODEL;
	
	public static String PAGE_TITLE_WS_WSAS_PROXY;
	public static String PAGE_DESC_WS_WSAS_PROXY;
	
	public static String DIR_DOT_METADATA;
	public static String DIR_DOT_PLUGINS;
	
	public static String ERROR_INVALID_FILE_READ_WRITEL;
	public static String ERROR_INVALID_WSDL_FILE_READ_WRITEL;
	public static String ERROR_CODEGEN_EXCEPTION;
	
	public static String WSAS_PROJECT;
	public static String CODEGEN_RESULTS;
	
	
	static {
		NLS.initializeMessages(BUNDLE_NAME, WSASConsumptionUIMessages.class);
	}
}
