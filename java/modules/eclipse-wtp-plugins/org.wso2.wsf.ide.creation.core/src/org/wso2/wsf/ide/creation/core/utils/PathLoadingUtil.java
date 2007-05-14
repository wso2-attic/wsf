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
package org.wso2.wsf.ide.creation.core.utils;

import org.eclipse.core.resources.ResourcesPlugin;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.creation.core.data.DataModel;
import org.wso2.wsf.ide.creation.core.messages.WSASCreationUIMessages;

public class PathLoadingUtil {
	
	//Model
	private static  DataModel model = null;

	//Paths
	private static String tempCodegenOutputLocation = null;
	private static String currentDynamicWebProjectDir = null;
	private static String workspaceDirectory = null;
	private static String currentProjectWebProjectName = null;
	
	//Already Computed
	private static boolean alreadyInit = false;
	private static boolean alreadyComputeTempCodegenOutputLocation = false;
	private static boolean alreadyComputeCurrentDynamicWebProjectDir = false;
	private static boolean alreadyComputeWorkspaceDirectory = false;
	private static boolean requireToupdateModel = false;
	
	public static void init(DataModel inputModel){
		requireToupdateModel = !alreadyInit || 
		!currentProjectWebProjectName.equals(inputModel.getWebProjectName());
		if(requireToupdateModel){
		model = inputModel;
		currentProjectWebProjectName = inputModel.getWebProjectName();
		}
		}

	public	static String getWorkspaceDirectory() {
		if (!alreadyComputeWorkspaceDirectory){
			workspaceDirectory = ResourcesPlugin.getWorkspace().getRoot()
			.getLocation().toOSString();
			alreadyComputeWorkspaceDirectory = true;
		}
		return workspaceDirectory;
	}
	
	public static String getCurrentDynamicWebProjectDir(){
		if (!alreadyComputeCurrentDynamicWebProjectDir || requireToupdateModel){
			currentDynamicWebProjectDir = FileUtils.addAnotherNodeToPath(
			getWorkspaceDirectory(), model.getWebProjectName());
			alreadyComputeCurrentDynamicWebProjectDir = true;
		}
		return currentDynamicWebProjectDir;
	}
	
	
	public static String getTempCodegenOutputLocation() {
		if (!alreadyComputeTempCodegenOutputLocation){
			String[] nodes = {	WSASCreationUIMessages.DIR_DOT_METADATA,
								WSASCreationUIMessages.DIR_DOT_PLUGINS,
								WSASCreationUIMessages.WSAS_PROJECT,
								WSASCreationUIMessages.CODEGEN_RESULTS};
			tempCodegenOutputLocation = FileUtils.addNodesToPath(getWorkspaceDirectory(), nodes);
			alreadyComputeTempCodegenOutputLocation = true;
		}
		return tempCodegenOutputLocation;
	}

}
