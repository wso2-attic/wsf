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

import org.eclipse.core.resources.ResourcesPlugin;
//import org.eclipse.jst.ws.internal.common.ServerUtils;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.WSASCoreUtils;

public class FacetContainerUtils {

	public static String  pathToWebProjectContainer(String project) {

		String workspaceDirectory = ResourcesPlugin.getWorkspace().getRoot()
												   .getLocation().toOSString();
		String projectString = replaceEscapecharactors(project.toString());

		String currentDynamicWebProjectDir = WSASCoreUtils.addAnotherNodeToPath(
															workspaceDirectory, 
															getProjectNameFromFramewokNameString(projectString)
															); 

		//TODO The Web content directory can be different. cater that also
		String webContainerDirString = WSASCoreUtils.addAnotherNodeToPath(
														currentDynamicWebProjectDir,
														WSASCoreUIMessages.DIR_WEBCONTENT);
		
		return webContainerDirString;
	}
	
	
	public static String pathToWebProjectContainerLib(String project){

		String webContainerWEBINFString = WSASCoreUtils.addAnotherNodeToPath(
															pathToWebProjectContainer(project),
															WSASCoreUIMessages.DIR_WEB_INF);

		return  WSASCoreUtils.addAnotherNodeToPath(
								webContainerWEBINFString,
								WSASCoreUIMessages.DIR_LIB);
	}
	
	
	
	//Fix for the windows build not working
	private static String replaceEscapecharactors(String vulnarableString){
		if (vulnarableString.indexOf("/")!=-1){
			vulnarableString = vulnarableString.replace('/', File.separator.charAt(0));
		}
		return vulnarableString;
	}
	
	
	private static String getProjectNameFromFramewokNameString(String frameworkProjectString){
		if (frameworkProjectString.indexOf(getSplitCharactor())== -1){
			return frameworkProjectString;
		}else{
			return frameworkProjectString.split(getSplitCharactors())[1];
		}
		
	}
	
	
	private static String getSplitCharactor(){
		//Windows check (because from inside wtp in return I received a hard coded path)
		if (File.separatorChar == '\\'){
			return "\\" ;
		}else{
			return File.separator;
		}
	}
	
	private static String getSplitCharactors(){
		//Windows check (because from inside wtp in return I received a hard coded path)
		if (File.separatorChar == '\\'){
			return "\\" + File.separator;
		}else{
			return File.separator;
		}
	}
	
	
	public static String getDeployedWSDLURL(String projectName, String serviceName){
		//TODO get the hostname and port from eclispe runtime  
		String[] deployedWSDLURLParts = {WSASCoreUIMessages.SERVICES,
										 serviceName
										 };
		//Get the Project URL from this excluding the hard coded URL for the server path.
		//String projectURL = ServerUtils.getEncodedWebComponentURL(projectName, 
		//											serviceServerTypeID_, 
		//											serviceExistingServer);

		
		return FileUtils.addNodesToURL(WSASCoreUIMessages.LOCAL_SERVER_PORT, 
										deployedWSDLURLParts)+"?wsdl";
	}
}
