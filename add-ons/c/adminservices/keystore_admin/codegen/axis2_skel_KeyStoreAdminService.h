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


    /**
     * axis2_skel_KeyStoreAdminService.h
     *
     * This file was auto-generated from WSDL for "KeyStoreAdminService|http://service.keystore.security.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_KeyStoreAdminService Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_getStoreEntries.h"
    
     #include "adb_getStoreEntriesResponse.h"
    
     #include "adb_SecurityConfigExceptionE0.h"
    
     #include "adb_addKeyStore.h"
    
     #include "adb_SecurityConfigExceptionE0.h"
    
     #include "adb_importCertToStore.h"
    
     #include "adb_SecurityConfigExceptionE0.h"
    
     #include "adb_getKeystoreInfo.h"
    
     #include "adb_getKeystoreInfoResponse.h"
    
     #include "adb_SecurityConfigExceptionE0.h"
    
     #include "adb_deleteStore.h"
    
     #include "adb_SecurityConfigExceptionE0.h"
    
     #include "adb_getKeyStoresResponse.h"
    
     #include "adb_SecurityConfigExceptionE0.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     
            /**
             * the generated fault union for operation "getStoreEntries|http://service.keystore.security.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_SecurityConfigExceptionE0_t* SecurityConfigException;
                
            } axis2_skel_KeyStoreAdminService_getStoreEntries_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getStoreEntries|http://service.keystore.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getStoreEntries of the adb_getStoreEntries_t*
         *
         * @return adb_getStoreEntriesResponse_t*
         */
        adb_getStoreEntriesResponse_t* axis2_skel_KeyStoreAdminService_getStoreEntries(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getStoreEntries_t* _getStoreEntries,
                                          axis2_skel_KeyStoreAdminService_getStoreEntries_fault *fault);


     
            /**
             * the generated fault union for operation "addKeyStore|http://service.keystore.security.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_SecurityConfigExceptionE0_t* SecurityConfigException;
                
            } axis2_skel_KeyStoreAdminService_addKeyStore_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addKeyStore|http://service.keystore.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addKeyStore of the adb_addKeyStore_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_KeyStoreAdminService_addKeyStore(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addKeyStore_t* _addKeyStore,
                                          axis2_skel_KeyStoreAdminService_addKeyStore_fault *fault);


     
            /**
             * the generated fault union for operation "importCertToStore|http://service.keystore.security.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_SecurityConfigExceptionE0_t* SecurityConfigException;
                
            } axis2_skel_KeyStoreAdminService_importCertToStore_fault;
         

		 
        /**
         * auto generated function declaration
         * for "importCertToStore|http://service.keystore.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _importCertToStore of the adb_importCertToStore_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_KeyStoreAdminService_importCertToStore(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_importCertToStore_t* _importCertToStore,
                                          axis2_skel_KeyStoreAdminService_importCertToStore_fault *fault);


     
            /**
             * the generated fault union for operation "getKeystoreInfo|http://service.keystore.security.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_SecurityConfigExceptionE0_t* SecurityConfigException;
                
            } axis2_skel_KeyStoreAdminService_getKeystoreInfo_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getKeystoreInfo|http://service.keystore.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getKeystoreInfo of the adb_getKeystoreInfo_t*
         *
         * @return adb_getKeystoreInfoResponse_t*
         */
        adb_getKeystoreInfoResponse_t* axis2_skel_KeyStoreAdminService_getKeystoreInfo(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getKeystoreInfo_t* _getKeystoreInfo,
                                          axis2_skel_KeyStoreAdminService_getKeystoreInfo_fault *fault);


     
            /**
             * the generated fault union for operation "deleteStore|http://service.keystore.security.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_SecurityConfigExceptionE0_t* SecurityConfigException;
                
            } axis2_skel_KeyStoreAdminService_deleteStore_fault;
         

		 
        /**
         * auto generated function declaration
         * for "deleteStore|http://service.keystore.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _deleteStore of the adb_deleteStore_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_KeyStoreAdminService_deleteStore(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_deleteStore_t* _deleteStore,
                                          axis2_skel_KeyStoreAdminService_deleteStore_fault *fault);


     
            /**
             * the generated fault union for operation "getKeyStores|http://service.keystore.security.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_SecurityConfigExceptionE0_t* SecurityConfigException;
                
            } axis2_skel_KeyStoreAdminService_getKeyStores_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getKeyStores|http://service.keystore.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getKeyStoresResponse_t*
         */
        adb_getKeyStoresResponse_t* axis2_skel_KeyStoreAdminService_getKeyStores(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_KeyStoreAdminService_getKeyStores_fault *fault);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_KEYSTOREADMINSERVICE_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_KEYSTOREADMINSERVICE_ERROR_NONE = AXIS2_SKEL_KEYSTOREADMINSERVICE_ERROR_CODES_START,
        
        AXIS2_SKEL_KEYSTOREADMINSERVICE_GETSTOREENTRIES_FAULT_SECURITYCONFIGEXCEPTION,
            AXIS2_SKEL_KEYSTOREADMINSERVICE_ADDKEYSTORE_FAULT_SECURITYCONFIGEXCEPTION,
            AXIS2_SKEL_KEYSTOREADMINSERVICE_IMPORTCERTTOSTORE_FAULT_SECURITYCONFIGEXCEPTION,
            AXIS2_SKEL_KEYSTOREADMINSERVICE_GETKEYSTOREINFO_FAULT_SECURITYCONFIGEXCEPTION,
            AXIS2_SKEL_KEYSTOREADMINSERVICE_DELETESTORE_FAULT_SECURITYCONFIGEXCEPTION,
            AXIS2_SKEL_KEYSTOREADMINSERVICE_GETKEYSTORES_FAULT_SECURITYCONFIGEXCEPTION,
            AXIS2_SKEL_KEYSTOREADMINSERVICE_ERROR_LAST
    } axis2_skel_KeyStoreAdminService_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

