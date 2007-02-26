package org.wso2.wsf.wtp.core.plugin.messages;

import org.eclipse.osgi.util.NLS;

public final class WSASCoreUIMessages extends NLS {

	private static final String BUNDLE_NAME = "org.wso2.wsf.wtp.core.plugin.messages.WSASCoreUI";//$NON-NLS-1$

	private WSASCoreUIMessages() {
		// Do not instantiate
	}

	public static String LABEL_BROUSE;
	public static String LABEL_WEB_SERVICE_CODEGEN;
	public static String LABEL_WEB_SERVICE_CLIENT_CODEGEN;
	public static String LABEL_DATABINDING;
	public static String LABEL_WSAS_RUNTIME_LOAD;
	public static String LABEL_WSAS_RUNTIME_LOAD_ERROR;
	
	public static String DIR_WEBCONTENT;
	public static String DIR_TEMPWAR;
	public static String DIR_DIST;
	public static String DIR_DOT_METADATA;
	public static String DIR_DOT_PLUGINS;

	public static String FILE_WSAS_WAR;
	
	public static String WSAS_LOCATION;
	public static String TEMP_WSAS_FACET_DIR;
	public static String WEBAPP_EXPLODED_SERVER_LOCATION_FILE;
	public static String SERVER_STATUS_LOCATION_FILE;
	public static String LABEL_WEBAPP_LOCATION;
	public static String NULL;
	public static String ADB;
	public static String PROPERTY_KEY_PATH;
	public static String PROPERTY_KEY_STATUS;

	public static String SERVER_STATUS;
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
