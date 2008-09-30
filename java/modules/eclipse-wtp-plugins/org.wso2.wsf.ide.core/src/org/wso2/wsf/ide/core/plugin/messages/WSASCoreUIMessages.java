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
package org.wso2.wsf.ide.core.plugin.messages;

import org.eclipse.osgi.util.NLS;

public final class WSASCoreUIMessages extends NLS {

	private static final String BUNDLE_NAME = 
			"org.wso2.wsf.ide.core.plugin.messages.WSASCoreUI";		//$NON-NLS-1$
	public static final String DIR_BIN = "bin" ; 					//$NON-NLS-1$
	public static final String WSAS_START_BAT = "startup.bat" ; 	//$NON-NLS-1$
	public static final String WSAS_DEBUG_BAT = "wso2wsas.bat" ; 	//$NON-NLS-1$
	public static final String WSAS_START_SH = "wso2wsas.sh" ;      //$NON-NLS-1$
	public static final String WSAS_START_BAT_NEW = "wso2server.bat" ; 	//$NON-NLS-1$
	public static final String WSAS_DEBUG_BAT_NEW = "wso2server.bat" ; 	//$NON-NLS-1$
	public static final String WSAS_START_SH_NEW = "wso2server.sh" ;      //$NON-NLS-1$
	public static final String WSAS_STOP_BAT = "shutdown.bat" ; 	//$NON-NLS-1$
	public static final String WSAS_STOP_SH = "shutdown.sh" ; 		//$NON-NLS-1$
	
	public static final String SHELL = "sh " ; 						//$NON-NLS-1$
	public static final String XTERM_EXEC = "xterm -e sh " ; 		//$NON-NLS-1$
	public static final String PROPERTIES_OS_NAME = "os.name" ; 	//$NON-NLS-1$
	
	
	public static final String WSAS_ALREADY_RUNNING = "WSAS Already Running !!" ;   //$NON-NLS-1$
	public static final String WSAS_NOT_ACTIVE = "WSAS Instance is not active !!";  //$NON-NLS-1$
	
	
	public static final String OS_WIN_9 = "windows 9" ; 			//$NON-NLS-1$
	public static final String OS_WIN_NT = "nt" ; 					//$NON-NLS-1$
	public static final String OS_WIN_2000 = "windows 2000" ; 		//$NON-NLS-1$
	public static final String OS_WIN_XP = "windows xp" ; 			//$NON-NLS-1$
	public static final String OS_WIN_VISTA	 = "windows vista" ; 	//$NON-NLS-1$

	public static final String WSAS_DEFAULT_DEBUG_HOST = "localhost" ; 		//$NON-NLS-1$
	public static final String WSAS_DEFAULT_DEBUG_PORT = "8088" ; 			//$NON-NLS-1$
	public static final String WSAS_DEFAULT_DEBUG_APPENDER = " --debug " ;	//$NON-NLS-1$
	
	
	
	

	private WSASCoreUIMessages() {
		// Do not instantiate
	}

	public static String LABEL_BROUSE;
	public static String LABEL_WEB_SERVICE_CODEGEN;
	public static String LABEL_WEB_SERVICE_CLIENT_CODEGEN;
	public static String LABEL_WEB_SERVICE_AAR;
	public static String LABEL_AAR_EXTENTION;
	public static String LABEL_DATABINDING;
	public static String LABEL_WSAS_RUNTIME_LOAD;
	public static String LABEL_WSAS_RUNTIME_LOAD_ERROR;
	public static String LABEL_WSAS_RUNTIME_NOT_EXIT;
	public static String LABEL_GENERATE_TESTCASE_CAPTION;
	public static String LABEL_GENERATE_SERVERSIDE_INTERFACE;
	public static String LABEL_GENERATE_ALL;
	public static String LABEL_CLIENT_SIDE;
	public static String LABEL_SYNC_AND_ASYNC;
	public static String LABEL_SYNC;
	public static String LABEL_ASYNC;
	public static String LABEL_UNPACK_CLASSES;
	
	public static String DIR_WEBCONTENT;
	public static String DIR_TEMPWAR;
	public static String DIR_EXPLOADED_TEMPWAR;
	public static String DIR_DOT_METADATA;
	public static String DIR_WEB_INF;
	public static String DIR_LIB;
	public static String DIR_CONF;
	public static String DIR_DOT_PLUGINS;
	public static String DIR_UNZIP;

	public static String FILE_WSAS_WAR;
	
	public static String WSAS_LOCATION;
	public static String WSAS_RUNTIME;
	public static String WSAS_RUNTIME_CONFIGURATION;
	public static String WSAS_DEBUG_HOST;
	public static String WSAS_DEBUG_PORT;
	public static String WSAS_PREFERENCES;
	public static String WSAS_RUNTIME_TOOLTIP;
	public static String WSAS_PREFERENCES_TOOLTIP;
	public static String TEMP_WSAS_FACET_DIR;
	public static String WEBAPP_EXPLODED_SERVER_LOCATION_FILE;
	public static String SERVER_STATUS_LOCATION_FILE;
	public static String WAR_STATUS_LOCATION_FILE;
	public static String NULL;
	public static String ADB;
	public static String AAR;
	public static String PROPERTY_KEY_PATH;
	public static String PROPERTY_KEY_STATUS;
	public static String LOCAL_SERVER_PORT;
	public static String LOCAL_SERVER_PORT_HTTPS;
	public static String SERVICES;
	public static String WSAS_RUNTIME_LOCATION;
	public static String WSAS_RUNTIME_PREFERENCES;
	public static String DATA_BINDING_ADB;
	public static String DATA_BINDING_XMLBEANS;
	public static String DATA_BINDING_JIBX;
	public static String DATA_BINDING_NONE;

	public static String SERVER_STATUS_PASS;
	public static String SERVER_STATUS_FAIL;

	public static String ERROR_INVALID_WSAS_SERVER_LOCATION;
	public static String ERROR_INVALID_FILE_READ_WRITEL;
	public static String ERROR_SERVER_IS_NOT_SET;

	
	public static String PROGRESS_INSTALL_WSAS_RUNTIME;
	public static String PROGRESS_UNINSTALL_WSAS_RUNTIME;
	
	static {
		NLS.initializeMessages(BUNDLE_NAME, WSASCoreUIMessages.class);
	}
}
