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

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;

import org.eclipse.core.resources.ResourcesPlugin;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;

public class WSASCoreUtils {
	
	private static boolean alreadyComputedTempWSASDirectory = false;
	private static String tempWSASDir = null;
	
	public static String tempWSASDirectory() {
		if (!alreadyComputedTempWSASDirectory){
			String[] nodes = {WSASCoreUIMessages.DIR_DOT_METADATA,
								WSASCoreUIMessages.DIR_DOT_PLUGINS,
								WSASCoreUIMessages.TEMP_WSAS_FACET_DIR};
			tempWSASDir =FileUtils.addNodesToPath(
					ResourcesPlugin.getWorkspace().getRoot().getLocation().toOSString(), nodes); 
			alreadyComputedTempWSASDirectory= true;
		}
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
	
	public static String tempWarStatusFileLocation() {
		return
		addAnotherNodeToPath(tempWSASDirectory(),
							 WSASCoreUIMessages.WAR_STATUS_LOCATION_FILE);
	}
	
	public static String addAnotherNodeToPath(String currentPath, String newNode) {
		return currentPath + File.separator + newNode;
	}
	
	public static void  writePropertyToFile(File file,String key, String value) throws IOException {
		Writer out = new BufferedWriter(new OutputStreamWriter(
						new FileOutputStream(file), "8859_1"));
	       out.write(key+"="+value+"\n");
	       out.close();
	}

}
