package org.wso2.wsf.wtp.core.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.wso2.wsf.wtp.core.plugin.messages.WSASCoreUIMessages;

public class RuntimePropertyUtils {
	private static File PropertiesFileDir,serverPropertiesFile,statusPropertyFile;
	private static IStatus status;
	private static Properties properties;
	
	private static void init(){
		PropertiesFileDir = new File(WSASCoreUtils.tempWSASDirectory());
		if (!PropertiesFileDir.exists()){
			PropertiesFileDir.mkdirs();
		}
		properties = new Properties();
	}
	
	private static void serverPropertiesFileInit() throws IOException{
		serverPropertiesFile = new File(WSASCoreUtils.tempWSASWebappFileLocation());
		if (!serverPropertiesFile.exists()){
			serverPropertiesFile.createNewFile();
		}
		properties.load(new FileInputStream(serverPropertiesFile));
	}
	
	private static void statusPropertiesFileInit() throws IOException{
		statusPropertyFile = new File(WSASCoreUtils.tempRuntimeStatusFileLocation());
		if (!statusPropertyFile.exists()){
			statusPropertyFile.createNewFile();
		}
		properties.load(new FileInputStream(statusPropertyFile));
	}
	
	public static IStatus writeServerPathToPropertiesFile(String wsasPath) {
		try {
			init();
			serverPropertiesFileInit();
			if(! (properties.size()== 0)){
				if(properties.containsKey(WSASCoreUIMessages.PROPERTY_KEY_PATH)){
					properties.remove(WSASCoreUIMessages.PROPERTY_KEY_PATH);
				}
			}
				WSASCoreUtils.writePropertyToFile(serverPropertiesFile, 
												   WSASCoreUIMessages.PROPERTY_KEY_PATH,
												   wsasPath);
		} catch (FileNotFoundException e) {
			status = new Status( IStatus.ERROR, 
					"id", 
					0, 
					WSASCoreUIMessages.ERROR_INVALID_WSAS_SERVER_LOCATION, 
					null ); 
		} catch (IOException e) {
			status = new Status( IStatus.ERROR, 
					"id", 
					0, 
					WSASCoreUIMessages.ERROR_INVALID_WSAS_SERVER_LOCATION, 
					null ); 
		}
		
		return status;
	}
	
	
	public static IStatus writeServerStausToPropertiesFile(String runtimeStatus) {
		try {
			init();
			statusPropertiesFileInit();
			if(! (properties.size()== 0)){
				if(properties.containsKey(WSASCoreUIMessages.PROPERTY_KEY_STATUS)){
					properties.remove(WSASCoreUIMessages.PROPERTY_KEY_STATUS);
				}
			}
			WSASCoreUtils.writePropertyToFile(statusPropertyFile, 
											   WSASCoreUIMessages.PROPERTY_KEY_STATUS, 
											   runtimeStatus);
		} catch (FileNotFoundException e) {
			status = new Status( IStatus.ERROR, 
					"id", 
					0, 
					WSASCoreUIMessages.ERROR_INVALID_WSAS_SERVER_LOCATION, 
					null ); 
		} catch (IOException e) {
			status = new Status( IStatus.ERROR, 
					"id", 
					0, 
					WSASCoreUIMessages.ERROR_INVALID_WSAS_SERVER_LOCATION, 
					null ); 
		}
		
		return status;
	}

}
