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


public class PluginLocationFinderUtil {
//	/**
//	 *  
//	 * @return returns a Vector containing PluginData objects.
//	 * Each PluginData object represents a Plugin found under any of the following 
//	 * plugin directories
//	 * a. the targetPlatformLocation\eclipse\plugins directory, 
//	 * b. other plugin directories as specified by *.link files under 
//	 *    targetPlatform\eclipse\links directory 
//	 **/ 
//	public static Vector getPluginsInTargetPlatform(){
//		/**
//		//step1: Get path of target platform.
//		//step2: Prepare path of links folder.
//		//step3: Get list of files in links folder.
//		//step4: Parse each link file and get the path of linked Eclipse folder.
//		//step5: Prepare a list of all plugin root folders 
//		//       (Eclipse plugins and linked Eclipse plugins).
//		//step6: 6a. For each plugin root folder, 
//		//       6b. go to each plugin directory and get path of plugin.xml.
//		//step7: Parse the plugin.xml file to get plugin id, plugin version, 
//		//       and store in vectors, lists, etc.
//		//step8: Go back to step 6 to continue with next plugin directory.
//		**/
//
//		//step1: Get path of target platform. 
//		//Fall back to Eclipse install location if targetplatform in not set.
//		URL platFormURL = Platform.getInstallLocation().getURL();
//		Location location = Platform.getInstallLocation();
//		IPath eclipsePath = null ;		
//
//		//Get path of target platform against which the users of this tool 
//		//will compile their code.	
////		IPath targetPlatFormLocation = new Path(getTargetPlatformPath(true));
////		IPath targetPlatFormLocation = new Path(System.getProperty("user.dir"));
//
////		if(_useTargetPlatform == false)
//			eclipsePath = new Path(platFormURL.getPath());
////		else
////			eclipsePath = targetPlatFormLocation;
//		
////		showMessage("Considering target platform to be: " + 
////					eclipsePath.toString());
//		
//		//step2: Prepare path of links folder.
//		//step3: Get list of files in links folder.		
//		//step4: Parse each link file and get the path of linked Eclipse folder.
//		IPath linksPath = new Path( eclipsePath.toString() ).append("/links");
//		String linkedPaths[] = getLinkedPaths(linksPath.toString());
//		int linkedPathLength = 0;
//		if(null != linkedPaths){
//			linkedPathLength = linkedPaths.length;
//		}
//		
//		//step5: Prepare a list of all plugin root folders 
//		//       (Eclipse plugins and linked Eclipse plugins).
//		IPath eclipsePluginRootFolders[] = new IPath[linkedPathLength + 1];
//		eclipsePluginRootFolders[0] = 
//			new Path( eclipsePath.toString() ).append("/plugins");
//		if(null != linkedPaths){
//			for(int i=0; i<linkedPaths.length; i++){
//				eclipsePluginRootFolders[i+1] = 
//				new Path(linkedPaths[i]).append("/eclipse/plugins");
//			}
//		}
//
//		//step6: 6a. For each plugin root folder, 
//		//       6b. go to each plugin directory and get path of plugin.xml.
//		//step7: Parse the plugin.xml file to get plugin id, plugin version, 
//		//       and store in vectors, lists, etc.
//		Vector vectorsInThisVector = new Vector();
//		for(int i=0; i<eclipsePluginRootFolders.length; i++){
//			System.out.println("\n========plugin IDs and Versions in " + 
//			eclipsePluginRootFolders[i] + "========");
//			Vector pluginDataObjs  = 
//			getPluginDataForAllPlugins(
//				eclipsePluginRootFolders[i].toString());
//			vectorsInThisVector.add(pluginDataObjs);
//			System.out.println(pluginDataObjs);
//			System.out.println("\n===========|||=== end ===|||===========");
//		}
//		
//		Vector pluginData = new Vector();
//		Iterator outerIterator = vectorsInThisVector.iterator();
//		while(outerIterator.hasNext()){
//			Vector pluginDataObjs = (Vector)outerIterator.next();
//			Iterator innerIterator = pluginDataObjs.iterator();
//			while(innerIterator.hasNext()){
//				PluginData pd = (PluginData)innerIterator.next();
//				String pluginIdKey = pd.getPluginID();
//				String versionValue = pd.getPluginVersion();
//				String pluginPath = pd.getPluginLocation();
//				pluginData.add(pd);
//			}
//		}
//		
//		int breakpoint=0;
//
//		return pluginData;
//	}
//
//
}
