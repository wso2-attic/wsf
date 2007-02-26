package org.wso2.wsf.wtp.core.utils;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import org.eclipse.core.resources.ResourcesPlugin;
import org.wso2.wsf.wtp.core.plugin.messages.WSASCoreUIMessages;

public class WSASCoreUtils {
	
	public static String tempWSASDirectory() {
		String projectDirDotMetadata = addAnotherNodeToPath(ResourcesPlugin.getWorkspace().getRoot().getLocation().toOSString(), 
				 WSASCoreUIMessages.DIR_DOT_METADATA);
		String projectDirDotPlugins= addAnotherNodeToPath(projectDirDotMetadata,
												WSASCoreUIMessages.DIR_DOT_PLUGINS);
		String tempWSASDir =addAnotherNodeToPath(projectDirDotPlugins, 
							 WSASCoreUIMessages.TEMP_WSAS_FACET_DIR);
		return tempWSASDir;
	}
	
	public static String tempWSASWebappFileLocation() {
		return
		addAnotherNodeToPath(tempWSASDirectory(),
							 WSASCoreUIMessages.WEBAPP_EXPLODED_SERVER_LOCATION_FILE);
	}
	
	
	public static String tempRuntimeStatusFileLocation() {
		return
		addAnotherNodeToPath(tempWSASDirectory(),
							 WSASCoreUIMessages.SERVER_STATUS_LOCATION_FILE);
	}
	
	public static String addAnotherNodeToPath(String currentPath, String newNode) {
		return currentPath + File.separator + newNode;
	}
	
	public static void  writePropertyToFile(File file,String key, String value) throws IOException {
	       BufferedWriter out = new BufferedWriter(new FileWriter(file));
	       out.write(key+"="+value+"\n");
	       out.close();
	}

}
