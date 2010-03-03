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


        #ifndef ADB_SYSTEMSTATISTICS_H
        #define ADB_SYSTEMSTATISTICS_H

       /**
        * adb_SystemStatistics.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_SystemStatistics class
        */

        
          #include "adb_Metric.h"
          
          #include "adb_Metric.h"
          

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
        

        typedef struct adb_SystemStatistics adb_SystemStatistics_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_SystemStatistics_t
         * @param env pointer to environment struct
         * @return newly created adb_SystemStatistics_t object
         */
        adb_SystemStatistics_t* AXIS2_CALL
        adb_SystemStatistics_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _SystemStatistics adb_SystemStatistics_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_free (
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Free adb_SystemStatistics_t object
         * @param  _SystemStatistics adb_SystemStatistics_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_free_obj (
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for avgResponseTime. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return double
         */
        double AXIS2_CALL
        adb_SystemStatistics_get_avgResponseTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for avgResponseTime.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_avgResponseTime double
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_avgResponseTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            const double  arg_avgResponseTime);

        /**
         * Resetter for avgResponseTime
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_avgResponseTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for faultCount. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_SystemStatistics_get_faultCount(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for faultCount.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_faultCount int
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_faultCount(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            const int  arg_faultCount);

        /**
         * Resetter for faultCount
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_faultCount(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for javaVersion. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SystemStatistics_get_javaVersion(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for javaVersion.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_javaVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_javaVersion(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            const axis2_char_t*  arg_javaVersion);

        /**
         * Resetter for javaVersion
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_javaVersion(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for maxResponseTime. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return int64_t
         */
        int64_t AXIS2_CALL
        adb_SystemStatistics_get_maxResponseTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for maxResponseTime.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_maxResponseTime int64_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_maxResponseTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            const int64_t  arg_maxResponseTime);

        /**
         * Resetter for maxResponseTime
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_maxResponseTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for minResponseTime. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return int64_t
         */
        int64_t AXIS2_CALL
        adb_SystemStatistics_get_minResponseTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for minResponseTime.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_minResponseTime int64_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_minResponseTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            const int64_t  arg_minResponseTime);

        /**
         * Resetter for minResponseTime
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_minResponseTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for requestCount. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_SystemStatistics_get_requestCount(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for requestCount.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_requestCount int
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_requestCount(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            const int  arg_requestCount);

        /**
         * Resetter for requestCount
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_requestCount(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for responseCount. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_SystemStatistics_get_responseCount(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for responseCount.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_responseCount int
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_responseCount(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            const int  arg_responseCount);

        /**
         * Resetter for responseCount
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_responseCount(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serverName. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SystemStatistics_get_serverName(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for serverName.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_serverName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_serverName(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            const axis2_char_t*  arg_serverName);

        /**
         * Resetter for serverName
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_serverName(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serverStartTime. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SystemStatistics_get_serverStartTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for serverStartTime.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_serverStartTime axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_serverStartTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            const axis2_char_t*  arg_serverStartTime);

        /**
         * Resetter for serverStartTime
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_serverStartTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for services. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_SystemStatistics_get_services(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for services.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_services int
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_services(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            const int  arg_services);

        /**
         * Resetter for services
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_services(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for systemUpTime. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SystemStatistics_get_systemUpTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for systemUpTime.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_systemUpTime axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_systemUpTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            const axis2_char_t*  arg_systemUpTime);

        /**
         * Resetter for systemUpTime
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_systemUpTime(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for totalMemory. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return adb_Metric_t*
         */
        adb_Metric_t* AXIS2_CALL
        adb_SystemStatistics_get_totalMemory(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for totalMemory.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_totalMemory adb_Metric_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_totalMemory(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            adb_Metric_t*  arg_totalMemory);

        /**
         * Resetter for totalMemory
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_totalMemory(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for usedMemory. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return adb_Metric_t*
         */
        adb_Metric_t* AXIS2_CALL
        adb_SystemStatistics_get_usedMemory(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for usedMemory.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_usedMemory adb_Metric_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_usedMemory(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            adb_Metric_t*  arg_usedMemory);

        /**
         * Resetter for usedMemory
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_usedMemory(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        
        

        /**
         * Getter for wso2wsasVersion. 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SystemStatistics_get_wso2wsasVersion(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        /**
         * Setter for wso2wsasVersion.
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param arg_wso2wsasVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_wso2wsasVersion(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            const axis2_char_t*  arg_wso2wsasVersion);

        /**
         * Resetter for wso2wsasVersion
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_reset_wso2wsasVersion(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether avgResponseTime is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_avgResponseTime_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        

        /**
         * Check whether faultCount is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_faultCount_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        

        /**
         * Check whether javaVersion is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_javaVersion_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        
        /**
         * Set javaVersion to nill (currently the same as reset)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_javaVersion_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);
        

        /**
         * Check whether maxResponseTime is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_maxResponseTime_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        

        /**
         * Check whether minResponseTime is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_minResponseTime_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        

        /**
         * Check whether requestCount is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_requestCount_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        

        /**
         * Check whether responseCount is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_responseCount_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        

        /**
         * Check whether serverName is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_serverName_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        
        /**
         * Set serverName to nill (currently the same as reset)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_serverName_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);
        

        /**
         * Check whether serverStartTime is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_serverStartTime_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        
        /**
         * Set serverStartTime to nill (currently the same as reset)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_serverStartTime_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);
        

        /**
         * Check whether services is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_services_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        

        /**
         * Check whether systemUpTime is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_systemUpTime_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        
        /**
         * Set systemUpTime to nill (currently the same as reset)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_systemUpTime_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);
        

        /**
         * Check whether totalMemory is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_totalMemory_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        
        /**
         * Set totalMemory to nill (currently the same as reset)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_totalMemory_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);
        

        /**
         * Check whether usedMemory is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_usedMemory_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        
        /**
         * Set usedMemory to nill (currently the same as reset)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_usedMemory_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);
        

        /**
         * Check whether wso2wsasVersion is nill
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_wso2wsasVersion_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);


        
        /**
         * Set wso2wsasVersion to nill (currently the same as reset)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_set_wso2wsasVersion_nil(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env);
        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_deserialize(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_deserialize_obj(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_SystemStatistics_declare_parent_namespaces(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param SystemStatistics_om_node node to serialize from
         * @param SystemStatistics_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_SystemStatistics_serialize(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            axiom_node_t* SystemStatistics_om_node, axiom_element_t *SystemStatistics_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @param SystemStatistics_om_node node to serialize from
         * @param SystemStatistics_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_SystemStatistics_serialize_obj(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env,
            axiom_node_t* SystemStatistics_om_node, axiom_element_t *SystemStatistics_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_SystemStatistics is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_SystemStatistics_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_SystemStatistics_t
         * @param env pointer to environment struct
         * @param _avgResponseTime double
         * @param _faultCount int
         * @param _javaVersion axis2_char_t*
         * @param _maxResponseTime int64_t
         * @param _minResponseTime int64_t
         * @param _requestCount int
         * @param _responseCount int
         * @param _serverName axis2_char_t*
         * @param _serverStartTime axis2_char_t*
         * @param _services int
         * @param _systemUpTime axis2_char_t*
         * @param _totalMemory adb_Metric_t*
         * @param _usedMemory adb_Metric_t*
         * @param _wso2wsasVersion axis2_char_t*
         * @return newly created adb_SystemStatistics_t object
         */
        adb_SystemStatistics_t* AXIS2_CALL
        adb_SystemStatistics_create_with_values(
            const axutil_env_t *env,
                double _avgResponseTime,
                int _faultCount,
                axis2_char_t* _javaVersion,
                int64_t _maxResponseTime,
                int64_t _minResponseTime,
                int _requestCount,
                int _responseCount,
                axis2_char_t* _serverName,
                axis2_char_t* _serverStartTime,
                int _services,
                axis2_char_t* _systemUpTime,
                adb_Metric_t* _totalMemory,
                adb_Metric_t* _usedMemory,
                axis2_char_t* _wso2wsasVersion);

        


                /**
                 * Free adb_SystemStatistics_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _SystemStatistics adb_SystemStatistics_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                double AXIS2_CALL
                adb_SystemStatistics_free_popping_value(
                        adb_SystemStatistics_t* _SystemStatistics,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for avgResponseTime by property number (1)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return double
         */
        double AXIS2_CALL
        adb_SystemStatistics_get_property1(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for faultCount by property number (2)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_SystemStatistics_get_property2(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for javaVersion by property number (3)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SystemStatistics_get_property3(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for maxResponseTime by property number (4)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return int64_t
         */
        int64_t AXIS2_CALL
        adb_SystemStatistics_get_property4(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for minResponseTime by property number (5)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return int64_t
         */
        int64_t AXIS2_CALL
        adb_SystemStatistics_get_property5(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for requestCount by property number (6)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_SystemStatistics_get_property6(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for responseCount by property number (7)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_SystemStatistics_get_property7(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serverName by property number (8)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SystemStatistics_get_property8(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serverStartTime by property number (9)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SystemStatistics_get_property9(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for services by property number (10)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_SystemStatistics_get_property10(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for systemUpTime by property number (11)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SystemStatistics_get_property11(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for totalMemory by property number (12)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return adb_Metric_t*
         */
        adb_Metric_t* AXIS2_CALL
        adb_SystemStatistics_get_property12(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for usedMemory by property number (13)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return adb_Metric_t*
         */
        adb_Metric_t* AXIS2_CALL
        adb_SystemStatistics_get_property13(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
        

        /**
         * Getter for wso2wsasVersion by property number (14)
         * @param  _SystemStatistics adb_SystemStatistics_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SystemStatistics_get_property14(
            adb_SystemStatistics_t* _SystemStatistics,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_SYSTEMSTATISTICS_H */
    

