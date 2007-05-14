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


public class CommonUtils {
	
	 public static String classNameFromQualifiedName(String qualifiedCalssName){
		 //This was done due to not splitting with . Strange
		 qualifiedCalssName = qualifiedCalssName.replace('.', ':');
		 String[] parts = qualifiedCalssName.split(":");
		 if (parts.length == 0){
			 return "";
		 }
		 return parts[parts.length-1];
	 }
	  
	 public static String packageNameFromQualifiedName(String qualifiedCalssName){
		 //This was done due to not splitting with . Strange
		 qualifiedCalssName = qualifiedCalssName.replace('.', ':');
		 String[] parts = qualifiedCalssName.split(":");
		 StringBuffer packageName = new StringBuffer();
		 for (int i = 0; i < parts.length-1; i++) {
			 packageName.append(parts[i]);
			 if (! (i == parts.length-2)){
				 packageName.append(".");
			 }
		 }
		 return packageName.toString();
	 }
	 
	 
	 public static String packgeName2PathName(String packageName){
		 packageName = packageName.replace('.', '/');
		 return packageName;
	 }
	 

}
