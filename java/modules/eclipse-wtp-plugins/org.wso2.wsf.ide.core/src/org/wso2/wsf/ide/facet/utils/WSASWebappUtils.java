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
package org.wso2.wsf.ide.facet.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

import org.eclipse.core.runtime.IProgressMonitor;
import org.wso2.wsf.ide.core.plugin.data.ServerModel;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.core.utils.WSASCoreUtils;
import org.wso2.wsf.ide.facet.messages.WSASFacetUIMessages;

public class WSASWebappUtils {

	private static String tempWarLocation = null;
	private static boolean alreadyWarExist = false;
	private static String previousProject;

	public static String  copyWSASWar(IProgressMonitor monitor, String wsasHome, String project)
										throws FileNotFoundException, IOException{
		if(!alreadyWarExist || !project.equals(previousProject)){
			previousProject = project;
			File tempWSASDirectory = new File (WSASCoreUtils.tempWSASDirectory());
			if(!tempWSASDirectory.exists()){
				tempWSASDirectory.mkdirs();
			}
			if (tempWSASDirectory.isDirectory()) {
				tempWarLocation = WSASCoreUtils.addAnotherNodeToPath(
						WSASCoreUtils.tempWSASDirectory(),
						WSASCoreUIMessages.DIR_EXPLOADED_TEMPWAR);
				File tempWarLocationFile= new File(tempWarLocation);
				if (tempWarLocationFile.exists()) {
					FileUtils.deleteDirectories(tempWarLocationFile);
				}
				tempWarLocationFile.mkdirs();
				Properties properties = new Properties();
				properties.load(new FileInputStream(WSASCoreUtils.tempWSASWebappFileLocation()));
				if (properties.containsKey(WSASCoreUIMessages.PROPERTY_KEY_PATH)){
					String wsasHomeLocation = (ServerModel.getWsasServerPath()!=null)
									?ServerModel.getWsasServerPath()
									:properties.getProperty(WSASCoreUIMessages.PROPERTY_KEY_PATH);
					String wsasLibFile = WSASCoreUtils.addAnotherNodeToPath(
							wsasHomeLocation,
					"lib");
					String wsasConfFile = WSASCoreUtils.addAnotherNodeToPath(
							wsasHomeLocation,
					"conf");
					String wsasRepositoryFile = WSASCoreUtils.addAnotherNodeToPath(
							wsasHomeLocation,
					"repository");
					String wsasTempWebInf = WSASCoreUtils.addAnotherNodeToPath(
							tempWarLocation,
					"WEB-INF");
					String wsasTempWebInfLib = WSASCoreUtils.addAnotherNodeToPath(
							wsasTempWebInf,
					"lib");
					
					File wsasTempWebInfLibFile = new File(wsasTempWebInfLib);
					if (wsasTempWebInfLibFile.exists()){
						wsasTempWebInfLibFile.mkdirs();
					}
					
					String wsasTempWebInfConf = WSASCoreUtils.addAnotherNodeToPath(
							wsasTempWebInf,
					"conf");
					
					File wsasTempWebInfConfFile = new File(wsasTempWebInfConf);
					if (wsasTempWebInfConfFile.exists()){
						wsasTempWebInfConfFile.mkdirs();
					}
					

					//Copy the webapp content 
					FileUtils.copyDirectory(new File(wsasLibFile),
											wsasTempWebInfLibFile);
					//Delete the unwanted tomcat directory in the lib
					FileUtils.deleteDirectories(FileUtils.addAnotherNodeToPath(wsasTempWebInfLib, "tomcat"));

					//copy conf directory
					FileUtils.copyDirectory(new File(wsasConfFile), 
											wsasTempWebInfConfFile);
					
					//Copy modules and services 					
					FileUtils.copyDirectory(new File(wsasRepositoryFile), 
											new File(wsasTempWebInf));
					//Filter out the servletapi jars
					FileUtils.filterOutRestrictedFiles(wsasTempWebInfLibFile.getAbsolutePath(),
							                           WSASFacetUIMessages.FILE_SERVLET_API,"jar");

					alreadyWarExist= true;
				}

			} else {
				alreadyWarExist = false;
				//Throws an error message
			}
		}	
		return tempWarLocation;
	}

}
