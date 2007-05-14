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
package org.wso2.wsf.ide.core.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;

public class RuntimePropertyUtils {
	private static File PropertiesFileDir,serverPropertiesFile,statusPropertyFile,warPropertyFile;
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
	
	private static void warPropertiesFileInit() throws IOException{
		warPropertyFile = new File(WSASCoreUtils.tempWarStatusFileLocation());
		if (!warPropertyFile.exists()){
			warPropertyFile.createNewFile();
		}
		properties.load(new FileInputStream(warPropertyFile));
	}
	
	
	
	public static IStatus writeServerPathToPropertiesFile(String wsasPath) {
		//Fix for properties file skipping the File seperator charactor 
		// on windows when loading again
		String wsasPathNew = null;
		if ((wsasPath.indexOf("\\")) != -1) {
			wsasPathNew = wsasPath.replace(File.separator, File.separator+File.separator);;
		}else{
			wsasPathNew=wsasPath;
		}
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
												   wsasPathNew);
		} catch (FileNotFoundException e) {
			updateStatusError();
		} catch (IOException e) {
			updateStatusError();
		}
		
		return status;
	}
	
	public static String getServerPathFromPropertiesFile(){
		init();
		String serverPath = null;
		serverPropertiesFile = new File(WSASCoreUtils.tempWSASWebappFileLocation());
		if (!serverPropertiesFile.exists()){
			updateStatusError();			
		}
		try {
			properties.load(new FileInputStream(serverPropertiesFile));
			if(properties.containsKey(WSASCoreUIMessages.PROPERTY_KEY_PATH)){
				serverPath = properties.getProperty(WSASCoreUIMessages.PROPERTY_KEY_PATH);
			}
		} catch (FileNotFoundException e) {
			updateStatusError();
		} catch (IOException e) {
			updateStatusError();
		}
		return serverPath;
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
			updateStatusError(); 
		} catch (IOException e) {
			updateStatusError();
		}
		
		return status;
	}
	
	public static IStatus writeWarStausToPropertiesFile(boolean warStatus) {
		try {
			init();
			warPropertiesFileInit();
			if(! (properties.size()== 0)){
				if(properties.containsKey(WSASCoreUIMessages.PROPERTY_KEY_STATUS)){
					properties.remove(WSASCoreUIMessages.PROPERTY_KEY_STATUS);
				}
			}
			WSASCoreUtils.writePropertyToFile(warPropertyFile, 
											   WSASCoreUIMessages.PROPERTY_KEY_STATUS, 
											   String.valueOf(warStatus));
		} catch (FileNotFoundException e) {
			updateStatusError(); 
		} catch (IOException e) {
			updateStatusError();
		}
		
		return status;
	}
	
	public static boolean getWarStatusFromPropertiesFile(){
		init();
		boolean warStatus = false;
		warPropertyFile = new File(WSASCoreUtils.tempWarStatusFileLocation());
		if (!warPropertyFile.exists()){
			updateStatusError();			
		}
		try {
			properties.load(new FileInputStream(warPropertyFile));
			if(properties.containsKey(WSASCoreUIMessages.PROPERTY_KEY_STATUS)){
				warStatus = Boolean.parseBoolean(
						properties.getProperty(WSASCoreUIMessages.PROPERTY_KEY_STATUS));
			}
		} catch (FileNotFoundException e) {
			updateStatusError();
		} catch (IOException e) {
			updateStatusError();
		}
		return warStatus;
	}

	private static void updateStatusError(){
			status = new Status( IStatus.ERROR, 
					"id", 
					0, 
					WSASCoreUIMessages.ERROR_INVALID_WSAS_SERVER_LOCATION, 
					null ); 
		}
		
	}
