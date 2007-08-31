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
package org.wso2.wsf.ide.wtp.ext.java2wsdl.util;

public interface SettingsConstants {

    //##################################################################################
    //Java source file selection page
    static final String JAVA_CLASS_NAME = "JAVA_CLASS_NAME";
    static final String JAVA_CLASS_PATH_ENTRIES = "JAVA_CLASS_PATH_NAME";
    
    //##################################################################################
    // Java2wsdl options selection page
    static final String PREF_JAVA_TARGET_NS = "TARGET_NS";
    static final String PREF_JAVA_TARGET_NS_PREF = "TARGET_NS_PREF";
    static final String PREF_JAVA_SCHEMA_TARGET_NS = "SCHEMA_TARGET_NS";
    static final String PREF_JAVA_SERVICE_NAME = "SCHEMA_SERVICE";
    static final String PREF_JAVA_STYLE_INDEX = "STYLE_INDEX";
    static final String PREF_JAVA_SCHEMA_TARGET_NS_PREF = "SCHEMA_TARGET_NS_PREF";
    
    //##################################################################################
    //output page
    static final String JAVA_OUTPUT_WSDL_NAME = "OUTPUT_WSDL";
    static final String PREF_JAVA_OUTPUT_WSDL_LOCATION = "OUTPUT_WSDL_LOCATION";
    static final String PREF_JAVA_OUTPUT_FILESYATEM= "OUTPUT_WSDL_LOCATION_FILESYATEM";
    static final String PREF_JAVA_OUTPUT_WORKSPACE = "OUTPUT_WSDL_LOCATION_WORKSPACE";
    
    //##################################################################################
    //Page constants
     static final int WSDL_2_JAVA_TYPE = 1;
     static final int JAVA_2_WSDL_TYPE = 2;
     static final int UNSPECIFIED_TYPE = 3;
     
    //##################################################################################
    //Codegen Options constants
      static final int CODEGEN_DEFAULT_TYPE = 11;
      static final int CODEGEN_CUSTOM_TYPE = 12;
      static final int CODEGEN_UNDECLEARED_TYPE = 13;
    
    //##################################################################################
    // WSDL Mode constants
     static final String WSDL_ALL = "All";
     static final String WSDL_INTERFACE_ONLY = "Interface only";
     static final String WSDL_IMPLEMENTATION_ONLY = "Implementation only";
     
     //###########################################################
     static final String WSDL_STYLE_DOCUMENT="Document";
     static final String WSDL_STYLE_RPC="rpc";
     static final String WSDL_STYLE_WRAPPED="wrapped";

     //###########################################################
     static final String PREF_CHECK_WORKSPACE ="PREF_CHECK_WORKSPACE";
     
     static final String PREF_CHECK_FILE_SYSTEM ="PREF_CHECK_FILE_SYSTEM";

     static final String PREF_CHECK_AXIS_LIB_COPY ="PREF_CHECK_FILE_SYSTEM";
     
     static final String PREF_CHECK_JAR_CREATION ="PREF_CHECK_FILE_SYSTEM";
     
     static final String PREF_AXIS_HOME_OUTPUT_LOCATION = "PREF_OUTPUT_LOCATION";
     
     static final String PREF_AXIS_LIB_LOCATION = "PREF_OUTPUT_LOCATION";
     
     static final String PREF_JAR_FILE_NAME = "PREF_OUTPUT_LOCATION";
     
     static final String PREF_CODEGEN_OPTION_INDEX = "PREF_CODEGEN_OPTION_INDEX";
     
     static final String PREF_CHECK_AXIS_PLUGIN_LIB_COPY ="PREF_CHECK_AXIS_PLUGIN_LIB_COPY";
     
     
    
}
