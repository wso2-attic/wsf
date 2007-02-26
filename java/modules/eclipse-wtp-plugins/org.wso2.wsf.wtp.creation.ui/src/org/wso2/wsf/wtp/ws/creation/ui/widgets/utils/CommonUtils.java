package org.wso2.wsf.wtp.ws.creation.ui.widgets.utils;


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
