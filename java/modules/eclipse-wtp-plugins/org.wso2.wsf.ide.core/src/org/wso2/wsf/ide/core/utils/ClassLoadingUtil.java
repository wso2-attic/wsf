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
import java.net.MalformedURLException;
import java.net.URL;

import org.apache.tools.ant.AntClassLoader;
import org.apache.tools.ant.Project;
import org.apache.tools.ant.types.Path;

public class ClassLoadingUtil {

	private static String[] wsasClassPath = null;
	private static String[] classLoadPath = null;
	private static int libCount = 0;
	private static AntClassLoader antClassLoader;
	private static boolean libsLoaded = false;
	private static URL[] urls = null;
	private static boolean alreadyInit = false;
	private static boolean initByClient = false;
	
	public static void init(String project) {
		if (!alreadyInit) {

		//Obtain a ant class loader instance
			if(antClassLoader==null){
		antClassLoader =  new AntClassLoader();
			}
		
		// Set the class loader to child first
		antClassLoader.setParentFirst(false);
		
			if (!(wsasClassPath ==null) || !libsLoaded){
				classLoadPath = getWSASLibs(project);
			}
			
			if(urls == null){
				urls= new URL[classLoadPath.length];
			}

		Path classpath = new Path(new Project());
		
		try{
			for (int i = 0; i < classLoadPath.length; i++) {
				//Create a File object on the root of the directory containing the class file
				if(classLoadPath[i]!=null){
					File file = new File(classLoadPath[i]);
					// Convert File to a URL
					URL url = file.toURL();          
					urls[i]= url;
					classpath.setPath(classLoadPath[i]);
				}
			}
			
		}catch(MalformedURLException e){
			e.printStackTrace();
		}
			antClassLoader.setClassPath(classpath);
			alreadyInit = true;
				}
			}

	
	
	public static Class loadClassFromAntClassLoader(String fillyQualifiedClassName){
		
		Class cls = null;
		try{	
			cls = antClassLoader.loadClass(fillyQualifiedClassName);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		return cls;
	}
	
	
	private static String[] getWSASLibs(String project){
		File webContainerPath = new File(FacetContainerUtils.pathToWebProjectContainerLib(project));
		wsasClassPath = new String[webContainerPath.list().length];
		libCount = 0;
		visitAllFiles(webContainerPath);
		return wsasClassPath;
	}


	public static void visitAllFiles(File dir) {
		if(!dir.toString().endsWith(".txt")){
			if (dir.isDirectory()) {

				String[] children = dir.list();
				for (int i=0; i<children.length; i++) {
					visitAllFiles(new File(dir, children[i]));
				}

			} else {
				wsasClassPath[libCount]=dir.getAbsolutePath();
				libCount+=1;
			}

		}
		libsLoaded = true;
	}

	public static void cleanAntClassLoader(){
		if(initByClient){
			antClassLoader.cleanup();
			alreadyInit = false;
		}
}
	public static void setInitByClient(boolean status){
		initByClient = status;
	}
}
