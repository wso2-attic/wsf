package org.wso2.wsas.wtp.facet.utils;

import java.io.File;

import org.eclipse.core.resources.ResourcesPlugin;
import org.wso2.wsf.wtp.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.wtp.core.utils.WSASCoreUtils;

public class FacetContainerUtils {

	public static String  pathToWebProjectContainer(String project) {

		String workspaceDirectory = ResourcesPlugin.getWorkspace().getRoot()
												   .getLocation().toOSString();
		String projectString = replaceEscapecharactors(project.toString());

		String currentDynamicWebProjectDir = WSASCoreUtils.addAnotherNodeToPath(
															workspaceDirectory, 
															projectString.split(getSplitCharactors())[1]
															); 

		//TODO The Web content directory can be different. cater that also
		String webContainerDirString = WSASCoreUtils.addAnotherNodeToPath(
														currentDynamicWebProjectDir,
														WSASCoreUIMessages.DIR_WEBCONTENT);
		
		return webContainerDirString;
	}
	
	//Fix for the windows build not working
	public static String replaceEscapecharactors(String vulnarableString){
		if (vulnarableString.indexOf("/")!=-1){
			vulnarableString = vulnarableString.replace('/', File.separator.charAt(0));
		}
		return vulnarableString;
	}
	
	public static String getSplitCharactors(){
		if (File.separatorChar == '\\'){
			return "\\" + File.separator;
		}else{
			return File.separator;
		}
	}
}
