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
* axis2_skel_KeyStoreAdminService.c
*
* This file was auto-generated from WSDL for "KeyStoreAdminService|http://service.keystore.security.carbon.wso2.org" service
* by the Apache Axis2/C version: #axisVersion# #today#
* axis2_skel_KeyStoreAdminService Axis2/C skeleton for the axisService
*/	

#include "codegen/axis2_skel_KeyStoreAdminService.h"
#include "../include/keystore_admin_util.h"
#include <openssl_pkcs12_keystore.h>

static void
axis2_keystore_admin_create_fault(
    const axutil_env_t *env,
    axis2_char_t *reason,
    axis2_skel_KeyStoreAdminService_error_codes error_code,
    adb_SecurityConfigExceptionE0_t **exception,
    const axis2_char_t *file_name,
    const int line_number);

axis2_status_t
axis2_keystore_admin_save_keystore_details(
    const axutil_env_t* env,
	axis2_msg_ctx_t* msg_ctx,
    adb_addKeyStore_t* addKeyStore);

/**
* auto generated function definition signature
* for "getStoreEntries|http://service.keystore.security.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getStoreEntries of the adb_getStoreEntries_t*
*
* @return adb_getStoreEntriesResponse_t*
*/
adb_getStoreEntriesResponse_t* 
axis2_skel_KeyStoreAdminService_getStoreEntries(const axutil_env_t *env , 
												axis2_msg_ctx_t *msg_ctx,
												adb_getStoreEntries_t* _getStoreEntries,
												axis2_skel_KeyStoreAdminService_getStoreEntries_fault *fault )
{
	axis2_char_t* keystore_name = NULL;
	axis2_conf_ctx_t* conf_ctx = NULL;
	axis2_conf_t* axis2_conf = NULL;
	axis2_char_t* repo_path = NULL;
	axis2_char_t* keystore_file = NULL;
	axis2_char_t* keystore_details_file = NULL;
	axis2_char_t password[10];
	axis2_char_t provider[20];
	axis2_char_t pvt_key_pass[10];
	pkcs12_keystore_t* pkcs12_keystore = NULL;
	axutil_array_list_t* cert_array_tmp = NULL;
	int cert_count = 0;
	oxs_x509_cert_t* oxs_cert = NULL;
	adb_getStoreEntriesResponse_t* response = NULL;

	/* Get required keystore name*/
	keystore_name = axutil_strdup(env, 
		adb_getStoreEntries_get_keyStoreName(_getStoreEntries, env));
	if (!keystore_name) return NULL;
	keystore_name = strtok(keystore_name, ".");

	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    axis2_conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    repo_path = axis2_conf_get_repo(axis2_conf, env);
	
	/* Get password, provider and pvt_key_pass from details file */
	if (!keystore_admin_util_get_keystore_details(env, repo_path, keystore_name, 
		password, provider, pvt_key_pass))
	{
		AXIS2_FREE(env->allocator, keystore_name);
		return NULL;
	}

	/* Load keystore file */
	keystore_file = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
		AXIS2_PATH_SEP_STR, "KeyStoreAdminService", AXIS2_PATH_SEP_STR, "keystores", 
		AXIS2_PATH_SEP_STR, keystore_name, ".p12", NULL);

	pkcs12_keystore = pkcs12_keystore_create(env, keystore_file, password);
	AXIS2_FREE(env->allocator, keystore_file);
	AXIS2_FREE(env->allocator, keystore_name);

	if (!pkcs12_keystore) return NULL;

	/* Create response*/
	response = adb_getStoreEntriesResponse_create(env);

	/* Get public cert alias*/
	cert_array_tmp = pkcs12_keystore_populate_cert_array(env, 
		pkcs12_keystore_get_other_certs(pkcs12_keystore));
	cert_count = axutil_array_list_size(cert_array_tmp, env);

	if (0 < cert_count) /* Public certs available */
	{
		int index = 0;

		for (index = 0; index < cert_count; ++index)
		{
			oxs_cert = (oxs_x509_cert_t*)
				axutil_array_list_get(cert_array_tmp, env, index);
			
			if (oxs_x509_cert_get_alias(oxs_cert, env))
			{
				adb_getStoreEntriesResponse_add_return(response, env, 
					oxs_x509_cert_get_alias(oxs_cert, env));
			}

			oxs_x509_cert_free(oxs_cert, env);
		}

		axutil_array_list_free(cert_array_tmp, env);
	}

	/* Set private cert alias*/
	oxs_cert = pkcs12_keystore_get_owner_certificate(pkcs12_keystore, env);
	if (oxs_cert)
	{
		adb_getStoreEntriesResponse_add_return(response, env, 
					oxs_x509_cert_get_alias(oxs_cert, env));

		oxs_x509_cert_free(oxs_cert, env);
	}

	return response;
}



/**
* auto generated function definition signature
* for "addKeyStore|http://service.keystore.security.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _addKeyStore of the adb_addKeyStore_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_KeyStoreAdminService_addKeyStore(const axutil_env_t *env , 
											axis2_msg_ctx_t *msg_ctx,
											adb_addKeyStore_t* _addKeyStore,
											axis2_skel_KeyStoreAdminService_addKeyStore_fault *fault )
{
	axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *axis2_conf = NULL;
    axis2_char_t *repo_path = NULL;
    axis2_char_t *file_name = NULL;
    FILE *file = NULL;
    axis2_char_t *file_content = NULL;
    axis2_char_t *encoded_file_content = NULL;
    int file_content_size = 0;

    /* Validate the contents of the request */
    if(!adb_addKeyStore_get_filename(_addKeyStore, env))
    {
        axis2_keystore_admin_create_fault(env, "Key store file name is not given",
            AXIS2_SKEL_KEYSTOREADMINSERVICE_ADDKEYSTORE_FAULT_SECURITYCONFIGEXCEPTION,
            &(fault->SecurityConfigException), AXIS2_LOG_SI);
        return AXIS2_FAILURE;
    }
    if(!adb_addKeyStore_get_fileData(_addKeyStore, env))
    {
        axis2_keystore_admin_create_fault(env, "Key store data is not given",
            AXIS2_SKEL_KEYSTOREADMINSERVICE_ADDKEYSTORE_FAULT_SECURITYCONFIGEXCEPTION,
            &(fault->SecurityConfigException), AXIS2_LOG_SI);
        return AXIS2_FAILURE;
    }
    if(!adb_addKeyStore_get_password(_addKeyStore, env))
    {
        axis2_keystore_admin_create_fault(env, "Keystore password is not given",
            AXIS2_SKEL_KEYSTOREADMINSERVICE_ADDKEYSTORE_FAULT_SECURITYCONFIGEXCEPTION,
            &(fault->SecurityConfigException), AXIS2_LOG_SI);
        return AXIS2_FAILURE;
    }
    if(!adb_addKeyStore_get_pvtkeyPass(_addKeyStore, env))
    {
        axis2_keystore_admin_create_fault(env, "Private key password is not given",
            AXIS2_SKEL_KEYSTOREADMINSERVICE_ADDKEYSTORE_FAULT_SECURITYCONFIGEXCEPTION,
            &(fault->SecurityConfigException), AXIS2_LOG_SI);
        return AXIS2_FAILURE;
    }
    if(!adb_addKeyStore_get_type(_addKeyStore, env))
    {
        axis2_keystore_admin_create_fault(env, "Key store type is not given",
            AXIS2_SKEL_KEYSTOREADMINSERVICE_ADDKEYSTORE_FAULT_SECURITYCONFIGEXCEPTION,
            &(fault->SecurityConfigException), AXIS2_LOG_SI);
        return AXIS2_FAILURE;
    }

    /* construct file name with path */
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    axis2_conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    repo_path = axis2_conf_get_repo(axis2_conf, env);
    file_name = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
		AXIS2_PATH_SEP_STR, "KeyStoreAdminService", AXIS2_PATH_SEP_STR, "keystores",
        AXIS2_PATH_SEP_STR, adb_addKeyStore_get_filename(_addKeyStore, env), NULL);
    if(!file_name)
    {
        axis2_keystore_admin_create_fault(env, "Internal Server Error; File path is invalid",
            AXIS2_SKEL_KEYSTOREADMINSERVICE_ADDKEYSTORE_FAULT_SECURITYCONFIGEXCEPTION,
            &(fault->SecurityConfigException), AXIS2_LOG_SI);
        return AXIS2_FAILURE;
    }

    /* check whether already a file exists */
    file = fopen(file_name, "r");
    if(file)
    {
        axis2_keystore_admin_create_fault(env, "Key store with given name already exists",
            AXIS2_SKEL_KEYSTOREADMINSERVICE_ADDKEYSTORE_FAULT_SECURITYCONFIGEXCEPTION,
            &(fault->SecurityConfigException), AXIS2_LOG_SI);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
            "[KeyStoreAdmin] already a file exists with name [%s]", file_name);
        AXIS2_FREE(env->allocator, file_name);
        fclose(file);
        return AXIS2_FAILURE;
    }

    /* file does not exist. Create one and write the contents */
    file = fopen(file_name, "wb");
    if(!file)
    {
        axis2_keystore_admin_create_fault(env, "Internal Server Error; File cannot be open to write",
            AXIS2_SKEL_KEYSTOREADMINSERVICE_ADDKEYSTORE_FAULT_SECURITYCONFIGEXCEPTION,
            &(fault->SecurityConfigException), AXIS2_LOG_SI);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
            "[KeyStoreAdmin] file [%s] cannot be open to write", file_name);
        AXIS2_FREE(env->allocator, file_name);
        return AXIS2_FAILURE;
    }

    encoded_file_content = adb_addKeyStore_get_fileData(_addKeyStore, env);
    file_content = AXIS2_MALLOC(env->allocator, axutil_strlen(encoded_file_content));
    file_content_size = axutil_base64_decode_binary(file_content, encoded_file_content);
    fwrite(file_content, sizeof(axis2_char_t), file_content_size, file);
    AXIS2_FREE(env->allocator, file_content);

    if(ferror(file))
    {
        axis2_keystore_admin_create_fault(env, "Internal Server Error; File writing failed",
            AXIS2_SKEL_KEYSTOREADMINSERVICE_ADDKEYSTORE_FAULT_SECURITYCONFIGEXCEPTION,
            &(fault->SecurityConfigException), AXIS2_LOG_SI);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
            "[KeyStoreAdmin] cannot write to file [%s]", file_name);
        AXIS2_FREE(env->allocator, file_name);
        fclose(file);
        return AXIS2_FAILURE;
    }

    fflush(file);
    fclose(file);

    /* Persist keystore details*/
    if(axis2_keystore_admin_save_keystore_details(env, msg_ctx, _addKeyStore)
        != AXIS2_SUCCESS)
    {
        axis2_keystore_admin_create_fault(env,
            "Internal Server Error; Cannot save key store to registry",
            AXIS2_SKEL_KEYSTOREADMINSERVICE_ADDKEYSTORE_FAULT_SECURITYCONFIGEXCEPTION,
            &(fault->SecurityConfigException), AXIS2_LOG_SI);
        AXIS2_FREE(env->allocator, file_name);
        return AXIS2_FAILURE;
    }

    AXIS2_FREE(env->allocator, file_name);

    return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "importCertToStore|http://service.keystore.security.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _importCertToStore of the adb_importCertToStore_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_KeyStoreAdminService_importCertToStore(const axutil_env_t *env , 
												  axis2_msg_ctx_t *msg_ctx,
												  adb_importCertToStore_t* _importCertToStore,
												  axis2_skel_KeyStoreAdminService_importCertToStore_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "getKeystoreInfo|http://service.keystore.security.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getKeystoreInfo of the adb_getKeystoreInfo_t*
*
* @return adb_getKeystoreInfoResponse_t*
*/
adb_getKeystoreInfoResponse_t* 
axis2_skel_KeyStoreAdminService_getKeystoreInfo(const axutil_env_t *env , 
												axis2_msg_ctx_t *msg_ctx,
												adb_getKeystoreInfo_t* _getKeystoreInfo,
												axis2_skel_KeyStoreAdminService_getKeystoreInfo_fault *fault )
{
	axis2_char_t* keystore_name = NULL;
	axis2_conf_ctx_t* conf_ctx = NULL;
	axis2_conf_t* axis2_conf = NULL;
	axis2_char_t* repo_path = NULL;
	axis2_char_t* keystore_file = NULL;
	axis2_char_t password[10];
	axis2_char_t provider[20];
	axis2_char_t pvt_key_pass[10];
	pkcs12_keystore_t* pkcs12_keystore = NULL;
	axutil_array_list_t* cert_array_tmp = NULL;
	int cert_count = 0;
	adb_CertData_t* cert_data = NULL;
	oxs_x509_cert_t* oxs_cert = NULL;
	adb_KeyStoreData_t* data = NULL;
	adb_getKeystoreInfoResponse_t* response = NULL;

	/* Get required keystore name*/
	keystore_name = axutil_strdup(env, 
		adb_getKeystoreInfo_get_keyStoreName(_getKeystoreInfo, env));
	if (!keystore_name) return NULL;
	keystore_name = strtok(keystore_name, ".");

	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    axis2_conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    repo_path = axis2_conf_get_repo(axis2_conf, env);
	
	/* Get password, provider and pvt_key_pass from details file */
	if (!keystore_admin_util_get_keystore_details(env, repo_path, keystore_name, 
		password, provider, pvt_key_pass))
	{
		AXIS2_FREE(env->allocator, keystore_name);
		return NULL;
	}

	/* Load keystore file */
	keystore_file = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
		AXIS2_PATH_SEP_STR, "KeyStoreAdminService", AXIS2_PATH_SEP_STR, "keystores", 
		AXIS2_PATH_SEP_STR, keystore_name, ".p12", NULL);

	pkcs12_keystore = pkcs12_keystore_create(env, keystore_file, password);
	AXIS2_FREE(env->allocator, keystore_file);
	AXIS2_FREE(env->allocator, keystore_name);

	if (!pkcs12_keystore) return NULL;

	/* Create data*/
	data = adb_KeyStoreData_create(env);

	/* Set keystore name*/
	adb_KeyStoreData_set_keyStoreName(data, env, 
		(axis2_char_t*)axutil_strdup(env, 
		adb_getKeystoreInfo_get_keyStoreName(_getKeystoreInfo, env)));

	/* Set keystore type*/
	adb_KeyStoreData_set_keyStoreType(data, env, "PKCS12");

	/* Set provider*/
	adb_KeyStoreData_set_provider(data, env, provider);

	/* Add certs*/
	cert_array_tmp = pkcs12_keystore_populate_cert_array(env, 
		pkcs12_keystore_get_other_certs(pkcs12_keystore));
	cert_count = axutil_array_list_size(cert_array_tmp, env);

	if (0 < cert_count) /* Public certs available */
	{
		axutil_array_list_t* cert_array = NULL;
		int index = 0;

		cert_array = axutil_array_list_create(env, cert_count);

		for (index = 0; index < cert_count; ++index)
		{
			oxs_cert = (oxs_x509_cert_t*)
				axutil_array_list_get(cert_array_tmp, env, index);
			
			if (oxs_x509_cert_get_alias(oxs_cert, env))
			{
				axis2_char_t not_after[20];
				axis2_char_t not_before[20];

				/* Create and store cert data*/
				cert_data = adb_CertData_create(env);

				keystore_admin_util_format_date(env, oxs_x509_cert_get_date(oxs_cert, env), not_after);
				keystore_admin_util_format_date(env, oxs_x509_cert_get_valid_from(oxs_cert, env), not_before);

				adb_CertData_set_alias(cert_data, env, oxs_x509_cert_get_alias(oxs_cert, env));
				adb_CertData_set_issuerDN(cert_data, env, oxs_x509_cert_get_issuer(oxs_cert, env));
				adb_CertData_set_notAfter(cert_data, env, not_after);
				adb_CertData_set_notBefore(cert_data, env, not_before);
				adb_CertData_set_serialNumber(cert_data, env, oxs_x509_cert_get_serial_number(oxs_cert, env));
				adb_CertData_set_subjectDN(cert_data, env, oxs_x509_cert_get_subject(oxs_cert, env));
				adb_CertData_set_version(cert_data, env, oxs_x509_cert_get_version(oxs_cert, env));

				axutil_array_list_add(cert_array, env, cert_data);
			}

			oxs_x509_cert_free(oxs_cert, env);
		}

		adb_KeyStoreData_set_certs(data, env, cert_array);

		axutil_array_list_free(cert_array_tmp, env);
	}
	else
	{
		adb_KeyStoreData_set_certs_nil(data, env);
	}

	/* Set private cert*/
	oxs_cert = pkcs12_keystore_get_owner_certificate(pkcs12_keystore, env);
	if (oxs_cert)
	{
		axis2_char_t not_after[20];
		axis2_char_t not_before[20];

		cert_data = adb_CertData_create(env);

		keystore_admin_util_format_date(env, oxs_x509_cert_get_date(oxs_cert, env), not_after);
		keystore_admin_util_format_date(env, oxs_x509_cert_get_valid_from(oxs_cert, env), not_before);

		adb_CertData_set_alias(cert_data, env, oxs_x509_cert_get_alias(oxs_cert, env));
		adb_CertData_set_issuerDN(cert_data, env, oxs_x509_cert_get_issuer(oxs_cert, env));
		adb_CertData_set_notAfter(cert_data, env, not_after);
		adb_CertData_set_notBefore(cert_data, env, not_before);
		adb_CertData_set_serialNumber(cert_data, env, oxs_x509_cert_get_serial_number(oxs_cert, env));
		adb_CertData_set_subjectDN(cert_data, env, oxs_x509_cert_get_subject(oxs_cert, env));
		adb_CertData_set_version(cert_data, env, oxs_x509_cert_get_version(oxs_cert, env));

		adb_KeyStoreData_set_key(data, env, cert_data);

		oxs_x509_cert_free(oxs_cert, env);
	}
	else
	{
		adb_KeyStoreData_set_key_nil(data, env);
	}

	/* Create response*/
	response = adb_getKeystoreInfoResponse_create(env);
	adb_getKeystoreInfoResponse_set_return(response, env, data);

	return response;
}



/**
* auto generated function definition signature
* for "deleteStore|http://service.keystore.security.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _deleteStore of the adb_deleteStore_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_KeyStoreAdminService_deleteStore(const axutil_env_t *env , 
											axis2_msg_ctx_t *msg_ctx,
											adb_deleteStore_t* _deleteStore,
											axis2_skel_KeyStoreAdminService_deleteStore_fault *fault )
{
	axis2_svc_t* svc = NULL;
	axutil_param_t* param = NULL;
	axis2_char_t* primary_keystore = NULL;
	axis2_char_t* keystore_name = NULL;
	axis2_conf_ctx_t* conf_ctx = NULL;
	axis2_conf_t* conf = NULL;
	axis2_char_t* repo_path = NULL;
	axis2_char_t* keystore_file = NULL;
	axis2_char_t* keystore_details_file = NULL;
	int status = 0;

	/* Get required keystore name*/
	keystore_name = axutil_strdup(
		env, adb_deleteStore_get_keyStoreName(_deleteStore, env));
	if (!keystore_name) return AXIS2_FAILURE;

	/* Get primary keystore filename */
	svc = axis2_msg_ctx_get_svc(msg_ctx, env);
	param = axis2_svc_get_param(svc, env, "PrimaryKeystore");
	if (param)
	{
		primary_keystore = (axis2_char_t*)
			axutil_param_get_value(param, env);
	}

	/* Primary keystore should not be deleted*/
	if (0 == axutil_strcmp(keystore_name, primary_keystore))
		return AXIS2_FAILURE;

	keystore_name = strtok(keystore_name, ".");

	/* Form keystore file names*/
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    repo_path = axis2_conf_get_repo(conf, env);
	keystore_file = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
		AXIS2_PATH_SEP_STR, "KeyStoreAdminService", AXIS2_PATH_SEP_STR, "keystores", 
		AXIS2_PATH_SEP_STR, keystore_name, ".p12", NULL);
	keystore_details_file = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
		AXIS2_PATH_SEP_STR, "KeyStoreAdminService", AXIS2_PATH_SEP_STR, "keystores", 
		AXIS2_PATH_SEP_STR, keystore_name, ".dat", NULL);

	/* Remove keystore and detail files*/
	status = remove(keystore_file);
	if (0 == status)
		status = remove(keystore_details_file);

	AXIS2_FREE(env->allocator, keystore_name);
	AXIS2_FREE(env->allocator, keystore_file);
	AXIS2_FREE(env->allocator, keystore_details_file);
	
	if (0 != status) return AXIS2_FAILURE;

	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "getKeyStores|http://service.keystore.security.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_getKeyStoresResponse_t*
*/
adb_getKeyStoresResponse_t* 
axis2_skel_KeyStoreAdminService_getKeyStores(const axutil_env_t *env , 
											 axis2_msg_ctx_t *msg_ctx,
											 axis2_skel_KeyStoreAdminService_getKeyStores_fault *fault )
{
	axis2_svc_t* svc = NULL;
	axutil_param_t* param = NULL;
	axis2_char_t* primary_keystore = NULL;
	axis2_bool_t is_primary_keystore = AXIS2_FALSE;
	axis2_conf_ctx_t* conf_ctx = NULL;
	axis2_conf_t* conf = NULL;
	axis2_char_t* repo_path = NULL;
	axutil_array_list_t* keystore_filenames = NULL;
	int keystore_file_count = 0;
	int index = 0;
	adb_getKeyStoresResponse_t* response = NULL;
	axis2_char_t* keystore_filename = NULL;
	axis2_char_t* keystore_name = NULL;
	axis2_char_t* extension = NULL;
	axis2_char_t* keystore_type = NULL;
	axis2_char_t* provider = NULL;
	axis2_bool_t private_store = AXIS2_FALSE;
	axis2_char_t* tok = NULL;
	adb_KeyStoreData_t* data = NULL;

	/* Get primary keystore filename */
	svc = axis2_msg_ctx_get_svc(msg_ctx, env);
	param = axis2_svc_get_param(svc, env, "PrimaryKeystore");
	if (param)
	{
		primary_keystore = (axis2_char_t*)
			axutil_param_get_value(param, env);
	}

	/* Form keystore directory name*/
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    repo_path = axis2_conf_get_repo(conf, env);

	/* Read file names in keystore directory */	
	keystore_filenames = keystore_admin_util_get_keystore_filenames(
		env, repo_path);

	if (!keystore_filenames) return NULL;
	
	/* Create response */
	response = adb_getKeyStoresResponse_create(env);

	/* Fill data */
	keystore_file_count = axutil_array_list_size(keystore_filenames, env);
	for (index = 0; index < keystore_file_count; ++index)
	{
		axis2_char_t* filename = NULL;

		keystore_filename = NULL;
		keystore_name = NULL;
		extension = NULL;
		keystore_type = NULL;
		provider = NULL;
		private_store = AXIS2_FALSE;
		tok = NULL;

		/* Get name */
		filename = (axis2_char_t*)axutil_array_list_get(keystore_filenames, env, index);
		keystore_filename = axutil_strdup(env, filename);

		tok = strtok(filename, ".");
		if (tok) /* Keystore name */
		{
			keystore_name = tok;
			
			tok = strtok(NULL, " .");
			if (tok) /* Extension */
			{
				extension = tok;
			}
		}

		if (NULL == extension) /* No extension found */
		{
			AXIS2_FREE(env->allocator, filename);
			AXIS2_FREE(env->allocator, keystore_filename);
			keystore_filename = filename = NULL;
			continue;
		}

		if (0 == axutil_strcmp(extension, "p12")) /* PKCS12 */
		{
			keystore_type = "PKCS12";
		}
		else
		{
			AXIS2_FREE(env->allocator, filename);
			AXIS2_FREE(env->allocator, keystore_filename);
			keystore_filename = filename = NULL;
			continue;
		}

		is_primary_keystore = 
			(0 == axutil_strcmp(keystore_filename, primary_keystore)) ? AXIS2_TRUE : AXIS2_FALSE;

		if (is_primary_keystore)
		{
			/* Primary keystore */
			provider = axutil_strcat(env, " ", NULL);
			private_store = AXIS2_TRUE;
		}
		else
		{
			axis2_char_t password_tmp[10];
			axis2_char_t provider_tmp[20];
			axis2_char_t pvt_key_pass_tmp[10];

			/* Get password, provider and pvt_key_pass */
			if (!keystore_admin_util_get_keystore_details(env, repo_path, keystore_name, 
				password_tmp, provider_tmp, pvt_key_pass_tmp))
			{
				AXIS2_FREE(env->allocator, filename);
				AXIS2_FREE(env->allocator, keystore_filename);
				keystore_filename = filename = NULL;
				continue;
			}

			provider = axutil_strdup(env, provider_tmp);

			private_store = keystore_admin_util_get_private_store(env, repo_path,
				keystore_name, password_tmp);
		}
		
		data = adb_KeyStoreData_create(env);

		adb_KeyStoreData_set_keyStoreName(data, env, keystore_filename);
		adb_KeyStoreData_set_keyStoreType(data, env, keystore_type);
		adb_KeyStoreData_set_provider(data, env, provider);
		adb_KeyStoreData_set_privateStore(data, env, private_store);

		adb_getKeyStoresResponse_add_return(response, env, data);
	}

	axutil_array_list_free(keystore_filenames, env);
	
	return response;
}

static void
axis2_keystore_admin_create_fault(
    const axutil_env_t *env,
    axis2_char_t *reason,
    axis2_skel_KeyStoreAdminService_error_codes error_code,
    adb_SecurityConfigExceptionE0_t **exception,
    const axis2_char_t *file_name,
    const int line_number)
{
    /*TODO has to set the xsi:type for anytype. Modification should be in adb codegen
    adb_ProxyAdminException_t* exp = NULL;
    axiom_node_t *fault_text_node = NULL;
    axiom_text_create(env, NULL, reason, &fault_text_node);
    exp = adb_ProxyAdminException_create_with_values(env, fault_text_node);*/

    *exception = adb_SecurityConfigExceptionE0_create(env);
    AXIS2_ERROR_SET(env->error, error_code, AXIS2_FAILURE);
    axutil_error_set_error_message(env->error, reason);

    AXIS2_LOG_ERROR(env->log, file_name, line_number, "[KeyStoreAdmin]%s", reason);
}

axis2_status_t
axis2_keystore_admin_save_keystore_details(
    const axutil_env_t* env,
	axis2_msg_ctx_t* msg_ctx,
    adb_addKeyStore_t* addKeyStore)
{
	axis2_char_t* file_name = NULL;
	axis2_char_t* password = NULL;
	axis2_char_t* provider = NULL;
	axis2_char_t* pvt_key_pass = NULL;
	axis2_char_t* record = NULL;
	axis2_conf_ctx_t* conf_ctx = NULL;
	axis2_conf_t* axis2_conf = NULL;
	axis2_char_t* repo_path = NULL;
	axis2_char_t* data_file_name = NULL;
	FILE* file = NULL;
	axis2_char_t* encoded_record = NULL;
	int encoded_length = 0;

	/* Get parameters*/
	file_name = axutil_strdup(env, adb_addKeyStore_get_filename(addKeyStore, env));
	file_name = strtok(file_name, ".");
	password = adb_addKeyStore_get_password(addKeyStore, env);
	provider = adb_addKeyStore_get_provider(addKeyStore, env);
	pvt_key_pass = adb_addKeyStore_get_pvtkeyPass(addKeyStore, env);

	/* Persist keystore details*/
	record = axutil_strcat(env, password, "|", pvt_key_pass, "|", provider, NULL);

	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    axis2_conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    repo_path = axis2_conf_get_repo(axis2_conf, env);
    data_file_name = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
		AXIS2_PATH_SEP_STR, "KeyStoreAdminService", AXIS2_PATH_SEP_STR, "keystores",
        AXIS2_PATH_SEP_STR, file_name, ".dat", NULL);

	file = fopen(data_file_name, "w");
	/*encoded_record = (axis2_char_t*)
		AXIS2_MALLOC(env->allocator, axutil_strlen(record));
	encoded_length = axutil_base64_encode(encoded_record, record, 
		axutil_strlen(record));*/

	fwrite(record, sizeof(axis2_char_t), axutil_strlen(record), file);
	fflush(file);
	fclose(file);

	AXIS2_FREE(env->allocator, file_name);
	AXIS2_FREE(env->allocator, record);
	AXIS2_FREE(env->allocator, data_file_name);

	return AXIS2_SUCCESS;
}


