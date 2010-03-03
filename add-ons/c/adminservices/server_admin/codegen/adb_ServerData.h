/*
* Copyright 2009-2010 WSO2, Inc. http://wso2.com
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


        #ifndef ADB_SERVERDATA_H
        #define ADB_SERVERDATA_H

       /**
        * adb_ServerData.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_ServerData class
        */

        

        #include <stdio.h>
        #include <axiom.h>
        #include <axis2_util.h>
        #include <axiom_soap.h>
        #include <axis2_client.h>

        #include "axis2_extension_mapper.h"

        #ifdef __cplusplus
        extern "C"
        {
        #endif

        #define ADB_DEFAULT_DIGIT_LIMIT 1024
        #define ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT 64
        

        typedef struct adb_ServerData adb_ServerData_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_ServerData_t
         * @param env pointer to environment struct
         * @return newly created adb_ServerData_t object
         */
        adb_ServerData_t* AXIS2_CALL
        adb_ServerData_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _ServerData adb_ServerData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_free (
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Free adb_ServerData_t object
         * @param  _ServerData adb_ServerData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_free_obj (
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for axis2Location. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_axis2Location(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for axis2Location.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_axis2Location axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_axis2Location(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_axis2Location);

        /**
         * Resetter for axis2Location
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_axis2Location(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for dbDriverName. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_dbDriverName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for dbDriverName.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_dbDriverName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_dbDriverName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_dbDriverName);

        /**
         * Resetter for dbDriverName
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_dbDriverName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for dbDriverVersion. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_dbDriverVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for dbDriverVersion.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_dbDriverVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_dbDriverVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_dbDriverVersion);

        /**
         * Resetter for dbDriverVersion
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_dbDriverVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for dbName. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_dbName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for dbName.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_dbName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_dbName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_dbName);

        /**
         * Resetter for dbName
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_dbName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for dbURL. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_dbURL(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for dbURL.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_dbURL axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_dbURL(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_dbURL);

        /**
         * Resetter for dbURL
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_dbURL(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for dbVersion. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_dbVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for dbVersion.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_dbVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_dbVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_dbVersion);

        /**
         * Resetter for dbVersion
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_dbVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for javaHome. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_javaHome(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for javaHome.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_javaHome axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_javaHome(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_javaHome);

        /**
         * Resetter for javaHome
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_javaHome(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for javaRuntimeName. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_javaRuntimeName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for javaRuntimeName.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_javaRuntimeName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_javaRuntimeName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_javaRuntimeName);

        /**
         * Resetter for javaRuntimeName
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_javaRuntimeName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for javaVMVendor. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_javaVMVendor(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for javaVMVendor.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_javaVMVendor axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_javaVMVendor(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_javaVMVendor);

        /**
         * Resetter for javaVMVendor
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_javaVMVendor(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for javaVMVersion. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_javaVMVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for javaVMVersion.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_javaVMVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_javaVMVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_javaVMVersion);

        /**
         * Resetter for javaVMVersion
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_javaVMVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for javaVersion. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_javaVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for javaVersion.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_javaVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_javaVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_javaVersion);

        /**
         * Resetter for javaVersion
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_javaVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for osName. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_osName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for osName.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_osName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_osName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_osName);

        /**
         * Resetter for osName
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_osName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for osVersion. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_osVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for osVersion.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_osVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_osVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_osVersion);

        /**
         * Resetter for osVersion
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_osVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for registryType. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_registryType(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for registryType.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_registryType axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_registryType(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_registryType);

        /**
         * Resetter for registryType
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_registryType(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for remoteRegistryChroot. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_remoteRegistryChroot(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for remoteRegistryChroot.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_remoteRegistryChroot axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_remoteRegistryChroot(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_remoteRegistryChroot);

        /**
         * Resetter for remoteRegistryChroot
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_remoteRegistryChroot(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for remoteRegistryURL. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_remoteRegistryURL(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for remoteRegistryURL.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_remoteRegistryURL axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_remoteRegistryURL(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_remoteRegistryURL);

        /**
         * Resetter for remoteRegistryURL
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_remoteRegistryURL(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for repoLocation. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_repoLocation(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for repoLocation.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_repoLocation axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_repoLocation(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_repoLocation);

        /**
         * Resetter for repoLocation
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_repoLocation(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serverIp. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_serverIp(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for serverIp.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_serverIp axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_serverIp(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_serverIp);

        /**
         * Resetter for serverIp
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_serverIp(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serverName. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_serverName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for serverName.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_serverName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_serverName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_serverName);

        /**
         * Resetter for serverName
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_serverName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serverStartTime. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_serverStartTime(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for serverStartTime.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_serverStartTime axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_serverStartTime(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_serverStartTime);

        /**
         * Resetter for serverStartTime
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_serverStartTime(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for systemUpTime. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_systemUpTime(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for systemUpTime.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_systemUpTime axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_systemUpTime(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_systemUpTime);

        /**
         * Resetter for systemUpTime
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_systemUpTime(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for userCountry. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_userCountry(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for userCountry.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_userCountry axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_userCountry(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_userCountry);

        /**
         * Resetter for userCountry
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_userCountry(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for userHome. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_userHome(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for userHome.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_userHome axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_userHome(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_userHome);

        /**
         * Resetter for userHome
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_userHome(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for userName. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_userName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for userName.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_userName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_userName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_userName);

        /**
         * Resetter for userName
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_userName(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for userTimezone. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_userTimezone(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for userTimezone.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_userTimezone axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_userTimezone(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_userTimezone);

        /**
         * Resetter for userTimezone
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_userTimezone(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for wso2wsasVersion. 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_wso2wsasVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        /**
         * Setter for wso2wsasVersion.
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param arg_wso2wsasVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_wso2wsasVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_wso2wsasVersion);

        /**
         * Resetter for wso2wsasVersion
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_reset_wso2wsasVersion(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether axis2Location is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_axis2Location_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set axis2Location to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_axis2Location_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether dbDriverName is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_dbDriverName_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set dbDriverName to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_dbDriverName_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether dbDriverVersion is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_dbDriverVersion_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set dbDriverVersion to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_dbDriverVersion_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether dbName is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_dbName_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set dbName to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_dbName_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether dbURL is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_dbURL_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set dbURL to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_dbURL_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether dbVersion is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_dbVersion_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set dbVersion to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_dbVersion_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether javaHome is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_javaHome_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set javaHome to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_javaHome_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether javaRuntimeName is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_javaRuntimeName_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set javaRuntimeName to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_javaRuntimeName_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether javaVMVendor is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_javaVMVendor_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set javaVMVendor to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_javaVMVendor_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether javaVMVersion is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_javaVMVersion_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set javaVMVersion to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_javaVMVersion_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether javaVersion is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_javaVersion_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set javaVersion to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_javaVersion_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether osName is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_osName_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set osName to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_osName_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether osVersion is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_osVersion_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set osVersion to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_osVersion_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether registryType is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_registryType_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set registryType to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_registryType_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether remoteRegistryChroot is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_remoteRegistryChroot_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set remoteRegistryChroot to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_remoteRegistryChroot_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether remoteRegistryURL is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_remoteRegistryURL_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set remoteRegistryURL to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_remoteRegistryURL_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether repoLocation is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_repoLocation_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set repoLocation to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_repoLocation_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether serverIp is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_serverIp_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set serverIp to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_serverIp_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether serverName is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_serverName_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set serverName to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_serverName_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether serverStartTime is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_serverStartTime_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set serverStartTime to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_serverStartTime_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether systemUpTime is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_systemUpTime_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set systemUpTime to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_systemUpTime_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether userCountry is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_userCountry_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set userCountry to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_userCountry_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether userHome is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_userHome_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set userHome to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_userHome_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether userName is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_userName_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set userName to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_userName_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether userTimezone is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_userTimezone_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set userTimezone to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_userTimezone_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**
         * Check whether wso2wsasVersion is nill
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_wso2wsasVersion_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);


        
        /**
         * Set wso2wsasVersion to nill (currently the same as reset)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_set_wso2wsasVersion_nil(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env);
        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_deserialize(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServerData_deserialize_obj(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_ServerData_declare_parent_namespaces(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param ServerData_om_node node to serialize from
         * @param ServerData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ServerData_serialize(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            axiom_node_t* ServerData_om_node, axiom_element_t *ServerData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @param ServerData_om_node node to serialize from
         * @param ServerData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ServerData_serialize_obj(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env,
            axiom_node_t* ServerData_om_node, axiom_element_t *ServerData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_ServerData is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_ServerData_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_ServerData_t
         * @param env pointer to environment struct
         * @param _axis2Location axis2_char_t*
         * @param _dbDriverName axis2_char_t*
         * @param _dbDriverVersion axis2_char_t*
         * @param _dbName axis2_char_t*
         * @param _dbURL axis2_char_t*
         * @param _dbVersion axis2_char_t*
         * @param _javaHome axis2_char_t*
         * @param _javaRuntimeName axis2_char_t*
         * @param _javaVMVendor axis2_char_t*
         * @param _javaVMVersion axis2_char_t*
         * @param _javaVersion axis2_char_t*
         * @param _osName axis2_char_t*
         * @param _osVersion axis2_char_t*
         * @param _registryType axis2_char_t*
         * @param _remoteRegistryChroot axis2_char_t*
         * @param _remoteRegistryURL axis2_char_t*
         * @param _repoLocation axis2_char_t*
         * @param _serverIp axis2_char_t*
         * @param _serverName axis2_char_t*
         * @param _serverStartTime axis2_char_t*
         * @param _systemUpTime axis2_char_t*
         * @param _userCountry axis2_char_t*
         * @param _userHome axis2_char_t*
         * @param _userName axis2_char_t*
         * @param _userTimezone axis2_char_t*
         * @param _wso2wsasVersion axis2_char_t*
         * @return newly created adb_ServerData_t object
         */
        adb_ServerData_t* AXIS2_CALL
        adb_ServerData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _axis2Location,
                axis2_char_t* _dbDriverName,
                axis2_char_t* _dbDriverVersion,
                axis2_char_t* _dbName,
                axis2_char_t* _dbURL,
                axis2_char_t* _dbVersion,
                axis2_char_t* _javaHome,
                axis2_char_t* _javaRuntimeName,
                axis2_char_t* _javaVMVendor,
                axis2_char_t* _javaVMVersion,
                axis2_char_t* _javaVersion,
                axis2_char_t* _osName,
                axis2_char_t* _osVersion,
                axis2_char_t* _registryType,
                axis2_char_t* _remoteRegistryChroot,
                axis2_char_t* _remoteRegistryURL,
                axis2_char_t* _repoLocation,
                axis2_char_t* _serverIp,
                axis2_char_t* _serverName,
                axis2_char_t* _serverStartTime,
                axis2_char_t* _systemUpTime,
                axis2_char_t* _userCountry,
                axis2_char_t* _userHome,
                axis2_char_t* _userName,
                axis2_char_t* _userTimezone,
                axis2_char_t* _wso2wsasVersion);

        


                /**
                 * Free adb_ServerData_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _ServerData adb_ServerData_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_ServerData_free_popping_value(
                        adb_ServerData_t* _ServerData,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for axis2Location by property number (1)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property1(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for dbDriverName by property number (2)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property2(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for dbDriverVersion by property number (3)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property3(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for dbName by property number (4)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property4(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for dbURL by property number (5)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property5(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for dbVersion by property number (6)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property6(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for javaHome by property number (7)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property7(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for javaRuntimeName by property number (8)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property8(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for javaVMVendor by property number (9)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property9(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for javaVMVersion by property number (10)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property10(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for javaVersion by property number (11)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property11(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for osName by property number (12)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property12(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for osVersion by property number (13)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property13(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for registryType by property number (14)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property14(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for remoteRegistryChroot by property number (15)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property15(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for remoteRegistryURL by property number (16)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property16(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for repoLocation by property number (17)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property17(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serverIp by property number (18)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property18(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serverName by property number (19)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property19(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serverStartTime by property number (20)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property20(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for systemUpTime by property number (21)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property21(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for userCountry by property number (22)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property22(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for userHome by property number (23)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property23(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for userName by property number (24)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property24(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for userTimezone by property number (25)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property25(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for wso2wsasVersion by property number (26)
         * @param  _ServerData adb_ServerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServerData_get_property26(
            adb_ServerData_t* _ServerData,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_SERVERDATA_H */
    

