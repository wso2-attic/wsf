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
package org.wso2.wsf.ide.creation.core.messages;

import org.eclipse.osgi.util.NLS;

public class WSASCreationUIMessages extends NLS {

	//get the lables from this massages to the properties file
	private static final String BUNDLE_NAME = 
			"org.wso2.wsf.ide.creation.core.messages.WSASCreationUI";//$NON-NLS-1$

	private WSASCreationUIMessages() {
		// Do not instantiate
	}
	//labels
	public static String LABEL_HAVE_SERVICES_XML_FILE;
	public static String LABEL_DEFAULT_SERVICES_XML_FILE;
	public static String LABEL_WSAS_PREFERENCE_PAGE;
	public static String LABEL_WSAS_PREFERENCE_PAGE_HEADING;
	public static String LABEL_WSAS_PREFERENCE_PAGE_SUB_HEADING;
	public static String LABEL_BROWSE;
	public static String LABEL_DATA_MODEL;
	public static String LABEL_JAVA_2_WSDL_PAGE_HEADING;
	public static String LABEL_JAVA_2_WSDL_PAGE_SUB_HEADING;
	public static String LABEL_SERVICE_NAME_CAPTION;
	public static String LABEL_GENERATE_TESTCASE_CAPTION;
	public static String LABEL_DATABINDING_CAPTION;
	public static String LABEL_PORTNAME;
	public static String LABEL_GENERATE_ALL;
	public static String LABEL_GENERATE_SERVERSIDE_INTERFACE;
	public static String LABEL_PACKEGE_NAME;
	public static String LABEL_NAMESPACE;
	public static String LABEL_PACKAGE;
	public static String LABEL_NAMESPACE_TO_PACKAGE;
	
	//files
	public static String FILE_SERVICES_XML;
	public static String FILE_XML;
	//folders
	public static String DIR_BUILD;
	public static String DIR_SRC;
	public static String DIR_CLASSES;
	public static String DIR_RESOURCES;
	public static String DIR_META_INF;
	public static String DIR_WEB_INF;
	public static String DIR_SERVICES;
	public static String DIR_WEBSERVICES;
	public static String DIR_WEBCONTENT;
	public static String DIR_DOT_METADATA;
	public static String DIR_DOT_PLUGINS;
	//error
	public static String ERROR_INVALID_SERVICES_XML;
	public static String ERROR_INVALID_FILE_READ_WRITEL;
	public static String ERROR_INVALID_WSDL_FILE_READ_WRITEL;
	public static String ERROR_INVALID_SERVICE_CREATION;
	public static String ERROR_CODEGEN_EXCEPTION;
	//other
	public static String JAR_TASK;
	public static String WSAS_PROJECT;
	public static String CODEGEN_RESULTS;
	public static String SKELETON_SUFFIX;

	static {
		NLS.initializeMessages(BUNDLE_NAME, WSASCreationUIMessages.class);
	}

}
