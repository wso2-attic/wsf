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
package org.wso2.wsf.ide.consumption.core.utils;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.HashMap;
import java.util.Map;

import org.wso2.wsf.ide.core.utils.ClassLoadingUtil;

public class WSDL2JavaGenerator {
	
    /**
     * Maps a string containing the name of a language to a constant defined in 
     * CommandLineOptionConstants.LanguageNames
     * @param UILangValue a string containg a language, e.g. "java", "cs", "cpp" or "vb"
     * @return a normalized string constant
     */
    private String mapLanguagesWithCombo(String UILangValue)  {
       return UILangValue;
    }
    /**
     * Creates a list of parameters for the code generator based on the decisions made by 
     * the user on the OptionsPage(page2). For each setting, there is a Command-Line option for 
     * the Axis2 code generator.
     * @return a Map with keys from CommandLineOptionConstants with the values entered 
     * by the user on the Options Page.
     */
    public Map fillOptionMap(boolean isAyncOnly,
            		  boolean isSyncOnly,
            		  boolean isServerSide,
            		  boolean isServerXML,
            		  boolean isTestCase,
            		  boolean isGenerateAll,
            		  String serviceName,
            		  String portName,
            		  String databindingName,
            		  String WSDLURI,
            		  String packageName,
            		  String selectedLanguage,
            		  String outputLocation,
            		  String namespace2packageList,
            		  boolean isServerSideInterface,
            		  boolean isUnpackClasses
            		  ){
       Map optionMap = new HashMap();
       
     try{  
        //Reflection invocatin resources
		Class CommandLineOptionConstantsClass = ClassLoadingUtil.loadClassFromAntClassLoader(
							"org.apache.axis2.util.CommandLineOptionConstants$WSDL2JavaConstants");
		Class CommandLineOptionClass = ClassLoadingUtil.loadClassFromAntClassLoader(
														"org.apache.axis2.util.CommandLineOption");
		Constructor CommandLineOptionConstructor = CommandLineOptionClass.getConstructor(
														new Class[]{String.class,String[].class});
        //WSDL file name
       
							//       optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.WSDL_LOCATION_URI_OPTION, 
							//    		   		 new CommandLineOption(
							//    		   				 CommandLineOptionConstants.WSDL2JavaConstants.WSDL_LOCATION_URI_OPTION,
							//    		   				 getStringArray(WSDLURI)));
		
        //Reflection Invocation 
		Field WSDL_LOCATION_URI_OPTION_FIELD = CommandLineOptionConstantsClass.getField(
																		"WSDL_LOCATION_URI_OPTION");
		optionMap.put((String)WSDL_LOCATION_URI_OPTION_FIELD.get(String.class),
						CommandLineOptionConstructor.newInstance(
							new Object[]{(String)WSDL_LOCATION_URI_OPTION_FIELD.get(String.class),
							getStringArray(WSDLURI)}));
       
       //Async only
       if (isAyncOnly)
       {
							//          optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.CODEGEN_ASYNC_ONLY_OPTION, 
							//        		  	new CommandLineOption(
							//        		  			CommandLineOptionConstants.WSDL2JavaConstants.CODEGEN_ASYNC_ONLY_OPTION,
							//        		  			new String[0]));
        
    	//Reflection Invocation     	   
   		Field CODEGEN_ASYNC_ONLY_OPTION_FIELD = CommandLineOptionConstantsClass
   												.getField("CODEGEN_ASYNC_ONLY_OPTION");
		optionMap.put((String)CODEGEN_ASYNC_ONLY_OPTION_FIELD.get(
						String.class),
						CommandLineOptionConstructor.newInstance(
							new Object[]{(String)CODEGEN_ASYNC_ONLY_OPTION_FIELD.get(String.class),
							new String[0]}));
       }
       
       //sync only
       if (isSyncOnly)
       {
							//          optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.CODEGEN_SYNC_ONLY_OPTION, 
							//        		  new CommandLineOption(
							//        		  CommandLineOptionConstants.WSDL2JavaConstants.CODEGEN_SYNC_ONLY_OPTION,
							//        		  new String[0]));
       //Reflection Invocation
      		Field CODEGEN_SYNC_ONLY_OPTION_FIELD = CommandLineOptionConstantsClass
      												.getField("CODEGEN_SYNC_ONLY_OPTION");
    		optionMap.put((String)CODEGEN_SYNC_ONLY_OPTION_FIELD.get(String.class),
					CommandLineOptionConstructor.newInstance(
							new Object[]{(String)CODEGEN_SYNC_ONLY_OPTION_FIELD.get(String.class),
							new String[0]}));
       }
       //serverside
       if (isServerSide)
       {
							//          optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.SERVER_SIDE_CODE_OPTION, 
							//        		  new CommandLineOption(
							//        		  CommandLineOptionConstants.WSDL2JavaConstants.SERVER_SIDE_CODE_OPTION,
							//        		  new String[0]));
	    //Reflection Invocation
		Field SERVER_SIDE_CODE_OPTION_FIELD = CommandLineOptionConstantsClass
												.getField("SERVER_SIDE_CODE_OPTION");
		optionMap.put((String)SERVER_SIDE_CODE_OPTION_FIELD.get(String.class),
				CommandLineOptionConstructor.newInstance(
						new Object[]{(String)SERVER_SIDE_CODE_OPTION_FIELD.get(String.class),
						new String[0]}));
          //server xml
          if (isServerXML)
          {
          //optionMap.put(
							//            		 CommandLineOptionConstants.WSDL2JavaConstants.GENERATE_SERVICE_DESCRIPTION_OPTION,
          // 	new CommandLineOption(
          // 	CommandLineOptionConstants.WSDL2JavaConstants.GENERATE_SERVICE_DESCRIPTION_OPTION,
							//            		 new String[0]));
       		Field GENERATE_SERVICE_DESCRIPTION_OPTION_FIELD = CommandLineOptionConstantsClass
   												.getField("GENERATE_SERVICE_DESCRIPTION_OPTION");
    		optionMap.put((String)GENERATE_SERVICE_DESCRIPTION_OPTION_FIELD.get(String.class),
				CommandLineOptionConstructor.newInstance(
				   new Object[]{(String)GENERATE_SERVICE_DESCRIPTION_OPTION_FIELD.get(String.class),
				   new String[0]}));
          }
          if (isGenerateAll){
							//              optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.GENERATE_ALL_OPTION, 
							//            		  new CommandLineOption(
							//            		  CommandLineOptionConstants.WSDL2JavaConstants.GENERATE_ALL_OPTION,
							//            		  new String[0]));
			Field GENERATE_ALL_OPTION_FIELD = CommandLineOptionConstantsClass
														.getField("GENERATE_ALL_OPTION");
			optionMap.put((String)GENERATE_ALL_OPTION_FIELD.get(String.class),
					CommandLineOptionConstructor.newInstance(
							new Object[]{(String)GENERATE_ALL_OPTION_FIELD.get(String.class),
							new String[0]}));
          }
       }
       //test case
       if (isTestCase)
       {
							//          optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.GENERATE_TEST_CASE_OPTION,
							//        		  new CommandLineOption(
							//        		  CommandLineOptionConstants.WSDL2JavaConstants.GENERATE_TEST_CASE_OPTION,
							//        		  new String[0]));
		Field GENERATE_TEST_CASE_OPTION_FIELD = CommandLineOptionConstantsClass
													.getField("GENERATE_TEST_CASE_OPTION");
		optionMap.put((String)GENERATE_TEST_CASE_OPTION_FIELD.get(String.class),
				CommandLineOptionConstructor.newInstance(
						new Object[]{(String)GENERATE_TEST_CASE_OPTION_FIELD.get(String.class),
						new String[0]}));
       }
       //package name
							//       optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.PACKAGE_OPTION,
							//    		   new CommandLineOption(
							//    		   CommandLineOptionConstants.WSDL2JavaConstants.PACKAGE_OPTION,
							//    		   getStringArray(packageName)));
 		Field PACKAGE_OPTION_FIELD = CommandLineOptionConstantsClass.getField("PACKAGE_OPTION");
		optionMap.put((String)PACKAGE_OPTION_FIELD.get(String.class),
							CommandLineOptionConstructor.newInstance(
									new Object[]{(String)PACKAGE_OPTION_FIELD.get(String.class),
									getStringArray(packageName)}));
		
       //selected language
							//       optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.STUB_LANGUAGE_OPTION,
							//    		   new CommandLineOption(
							//    		   CommandLineOptionConstants.WSDL2JavaConstants.STUB_LANGUAGE_OPTION,
							//    		   getStringArray(mapLanguagesWithCombo(selectedLanguage))));
 		Field STUB_LANGUAGE_OPTION_FIELD = CommandLineOptionConstantsClass
 															.getField("STUB_LANGUAGE_OPTION");
		optionMap.put((String)STUB_LANGUAGE_OPTION_FIELD.get(String.class),
							CommandLineOptionConstructor.newInstance(
								new Object[]{(String)STUB_LANGUAGE_OPTION_FIELD.get(String.class),
								getStringArray(mapLanguagesWithCombo(selectedLanguage))}));
		
       //output location
							//       optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.OUTPUT_LOCATION_OPTION,
							//    		   new CommandLineOption(
							//    		   CommandLineOptionConstants.WSDL2JavaConstants.OUTPUT_LOCATION_OPTION,
							//    		   getStringArray(outputLocation)));
 		Field OUTPUT_LOCATION_OPTION_FIELD = CommandLineOptionConstantsClass
 														.getField("OUTPUT_LOCATION_OPTION");
		optionMap.put((String)OUTPUT_LOCATION_OPTION_FIELD.get(String.class),
							CommandLineOptionConstructor.newInstance(
								new Object[]{(String)OUTPUT_LOCATION_OPTION_FIELD.get(String.class),
								getStringArray(outputLocation)}));
       
      //databinding
							//       optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.DATA_BINDING_TYPE_OPTION,
							//    		   new CommandLineOption(
							//    		   CommandLineOptionConstants.WSDL2JavaConstants.DATA_BINDING_TYPE_OPTION,
							//    		   getStringArray(databindingName)));
 		Field DATA_BINDING_TYPE_OPTION_FIELD = CommandLineOptionConstantsClass
 													.getField("DATA_BINDING_TYPE_OPTION");
		optionMap.put((String)DATA_BINDING_TYPE_OPTION_FIELD.get(String.class),
							CommandLineOptionConstructor.newInstance(
							  new Object[]{(String)DATA_BINDING_TYPE_OPTION_FIELD.get(String.class),
							  getStringArray(databindingName)}));
       
       //port name
       if (portName!=null){
							//	       optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.PORT_NAME_OPTION,
							//	    		   new CommandLineOption(
							//	    		   CommandLineOptionConstants.WSDL2JavaConstants.PORT_NAME_OPTION,
							//	    		   getStringArray(portName)));
     		Field PORT_NAME_OPTION_FIELD = CommandLineOptionConstantsClass
     														.getField("PORT_NAME_OPTION");
    		optionMap.put((String)PORT_NAME_OPTION_FIELD.get(String.class),
    						CommandLineOptionConstructor.newInstance(
    								new Object[]{(String)PORT_NAME_OPTION_FIELD.get(String.class),
    								getStringArray(portName)}));
       }
       //service name
       if (serviceName!= null){
							//	       optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.SERVICE_NAME_OPTION,
							//	    		   new CommandLineOption(
							//	    		   CommandLineOptionConstants.WSDL2JavaConstants.SERVICE_NAME_OPTION,
							//	    		   getStringArray(serviceName)));
     		Field SERVICE_NAME_OPTION_FIELD = CommandLineOptionConstantsClass
     													.getField("SERVICE_NAME_OPTION");
    		optionMap.put((String)SERVICE_NAME_OPTION_FIELD.get(String.class),
    					CommandLineOptionConstructor.newInstance(
    							new Object[]{(String)SERVICE_NAME_OPTION_FIELD.get(String.class),
    									getStringArray(serviceName)}));
       }
       //ns2pkg mapping
       if (namespace2packageList!= null){
							//	       optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.NAME_SPACE_TO_PACKAGE_OPTION,
							//	    		   new CommandLineOption(
							//	    		   CommandLineOptionConstants.WSDL2JavaConstants.NAME_SPACE_TO_PACKAGE_OPTION
							//	    		   , getStringArray(namespace2packageList)));
     		Field NAME_SPACE_TO_PACKAGE_OPTION_FIELD = CommandLineOptionConstantsClass
     											.getField("NAME_SPACE_TO_PACKAGE_OPTION");
    		optionMap.put((String)NAME_SPACE_TO_PACKAGE_OPTION_FIELD.get(String.class),
    				CommandLineOptionConstructor.newInstance(
    					new Object[]{(String)NAME_SPACE_TO_PACKAGE_OPTION_FIELD.get(String.class),
    					getStringArray(namespace2packageList)}));
       }
       
       //server side interface  mapping
       if (isServerSideInterface){
							//	       optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.SERVER_SIDE_INTERFACE_OPTION,
							//	    		   new CommandLineOption(
							//	    		   CommandLineOptionConstants.WSDL2JavaConstants.SERVER_SIDE_INTERFACE_OPTION,
							//	    		   new String[0]));
     		Field SERVER_SIDE_INTERFACE_OPTION_FIELD = CommandLineOptionConstantsClass
     											.getField("SERVER_SIDE_INTERFACE_OPTION");
    		optionMap.put((String)SERVER_SIDE_INTERFACE_OPTION_FIELD.get(String.class),
    				CommandLineOptionConstructor.newInstance(
    					new Object[]{(String)SERVER_SIDE_INTERFACE_OPTION_FIELD.get(String.class),
    					new String[0]}));
       }
       //unpack classes mapping
       if (isUnpackClasses){
							//	       optionMap.put(CommandLineOptionConstants.WSDL2JavaConstants.UNPACK_CLASSES_OPTION,
							//	    		   new CommandLineOption(
							//	    		   CommandLineOptionConstants.WSDL2JavaConstants.UNPACK_CLASSES_OPTION,
							//	    		   new String[0]));
     		Field UNPACK_CLASSES_OPTION_FIELD = CommandLineOptionConstantsClass
     											.getField("UNPACK_CLASSES_OPTION");
    		optionMap.put((String)UNPACK_CLASSES_OPTION_FIELD.get(String.class),
    				CommandLineOptionConstructor.newInstance(
    					new Object[]{(String)UNPACK_CLASSES_OPTION_FIELD.get(String.class),
    					new String[0]}));
       }
       
     }catch(Exception e){
    	 e.printStackTrace();
     }
       return optionMap;
       
    }
    
    public String getBaseUri(String wsdlURI){
    	
    	try {
			URL url;
			if (wsdlURI.indexOf("://")==-1){
				url = new URL("file","",wsdlURI);
			}else{
				url = new URL(wsdlURI);	
			}

			
			String baseUri;
			if ("file".equals(url.getProtocol())){
				baseUri = new File(url.getFile()).getParentFile().toURL().toExternalForm();
			}else{
				baseUri = url.toExternalForm().substring(0,
						url.toExternalForm().lastIndexOf("/")
				);
			}
		
			
			return baseUri;
		} catch (MalformedURLException e) {
			throw new RuntimeException(e);
		}
    }
    
    /**
     * Reads the WSDL Object Model from the given location.
     * 
     * @param wsdlURI the filesystem location (full path) of the WSDL file to read in.
     * @return the WSDLDescription object containing the WSDL Object Model of the given WSDL file
     * @throws WSDLException when WSDL File is invalid
     * @throws IOException on errors reading the WSDL file
     */
    public Object getAxisService(String wsdlURI) throws Exception{
    	
    		URL url;
			if (wsdlURI.indexOf("://")==-1){
				url = new URL("file","",wsdlURI);
			}if (wsdlURI.indexOf(":/")==-1){
				url = new URL("file","",wsdlURI);
			}
			else{
				url = new URL(wsdlURI);	
			}

			//FIXME @author soi - 
		    // This quick fix assume that the wsdlURI points to a wsdl 1.1 version.
			// A better fix should be to determine which builder to use based on the wsdl version. 
			// The current implementation of the wsdl builder classes did not allow for this. 
			// I will suggestthat the determination of which builder to use should be done in
			// the builder classes, preferably in the parent builder class. Accessable through a
			// static reference to a method like getBuilderInstance(String wsdlURI) in the parent
			//builder class or through a builder Abstract Factor or Abstract factory methods.
			
			
			//WSDL11ToAxisServiceBuilder builder = new WSDL11ToAxisServiceBuilder(
			//											url.openConnection().getInputStream());
							//			builder.setBaseUri(getBaseUri(wsdlURI));
							//			return builder.populateService();
			
			//Reflection invocation
			//Class WSDL11ToAxisServiceBuilderClass = ClassLoadingUtil.loadClassFromAxis2LibPath(
			//                projectName,
			//                "org.apache.axis2.description.WSDL11ToAxisServiceBuilder");
			
			Class WSDL11ToAxisServiceBuilderClass = ClassLoadingUtil.loadClassFromAntClassLoader(
					"org.apache.axis2.description.WSDL11ToAxisServiceBuilder");
			Constructor constructor = WSDL11ToAxisServiceBuilderClass.getConstructor(
					new Class[]{InputStream.class});
			Object WSDL11ToAxisServiceBuilderInstance = constructor.newInstance(
					new Object[]{url.openConnection().getInputStream()});
			Method setBaseUriMethod = WSDL11ToAxisServiceBuilderClass.getMethod(
					"setBaseUri", 
					new Class[]{String.class});
			setBaseUriMethod.invoke(
					WSDL11ToAxisServiceBuilderInstance, 
					new Object[]{wsdlURI});
			
			//Fix for the Axis2 1.2 
			//builder.setCodegen(true);
			Method setCodegenMethod = WSDL11ToAxisServiceBuilderClass.getMethod(
					"setCodegen", 
					new Class[]{boolean.class});
			setCodegenMethod.invoke(
					WSDL11ToAxisServiceBuilderInstance, 
					new Object[]{true});
			
			Method populateServiceMethod = WSDL11ToAxisServiceBuilderClass.getMethod(
					"populateService", 
					null);
			return populateServiceMethod.invoke(WSDL11ToAxisServiceBuilderInstance, null);
			
			//return this import org.apache.axis2.description.AxisService;
    }

    /**
     * Converts a single String into a String Array
     * 
     * @param value a single string
     * @return an array containing only one element
     */
    private String[] getStringArray(String value)
    {
       String[] values = new String[1];
       values[0] = value;
       return values;
    }
}

