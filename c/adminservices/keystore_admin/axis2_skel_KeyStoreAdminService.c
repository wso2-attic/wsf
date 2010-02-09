

/**
* axis2_skel_KeyStoreAdminService.c
*
* This file was auto-generated from WSDL for "KeyStoreAdminService|http://service.keystore.security.carbon.wso2.org" service
* by the Apache Axis2/C version: #axisVersion# #today#
* axis2_skel_KeyStoreAdminService Axis2/C skeleton for the axisService
*/

#include "codegen/axis2_skel_KeyStoreAdminService.h"
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
	/* TODO fill this with the necessary business logic */
	return (adb_getStoreEntriesResponse_t*)NULL;
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

    // Persist keystore details
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
	pkcs12_keystore_t* pkcs12_keystore = NULL;
	adb_getKeystoreInfoResponse_t* response = NULL;
	adb_KeyStoreData_t* data = NULL;

	// Get required keystore name
	keystore_name = adb_getKeystoreInfo_get_keyStoreName(_getKeystoreInfo, env);
	if (!keystore_name) return NULL;

	// Load keystore file
	//pkcs12_keystore = pkcs12_keystore_create(env, 

	// Create data
	data = adb_KeyStoreData_create(env);

	// Set keystore name
	adb_KeyStoreData_set_keyStoreName(data, env, 
		(axis2_char_t*)axutil_strdup(env, keystore_name));

	// Set keystore type
	adb_KeyStoreData_set_keyStoreType(data, env, "PKCS12");

	// Create response
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
	axis2_char_t* keystore_name = NULL;
	axis2_conf_ctx_t* conf_ctx = NULL;
	axis2_conf_t* conf = NULL;
	axis2_char_t* repo_path = NULL;
	axis2_char_t* keystore_file = NULL;
	axis2_char_t* keystore_details_file = NULL;
	int status = 0;

	// Get required keystore name
	keystore_name = axutil_strdup(
		env, adb_deleteStore_get_keyStoreName(_deleteStore, env));
	if (!keystore_name) return AXIS2_FAILURE;
	keystore_name = strtok(keystore_name, ".");

	// Primary keystore should not be deleted
	if (0 == axutil_strcmp(keystore_name, "wso2wsfc.p12"))
		return AXIS2_FAILURE;

	// Form keystore directory name
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    repo_path = axis2_conf_get_repo(conf, env);
	keystore_file = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
		AXIS2_PATH_SEP_STR, "KeyStoreAdminService", AXIS2_PATH_SEP_STR, "keystores", 
		AXIS2_PATH_SEP_STR, keystore_name, ".p12", NULL);
	keystore_details_file = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
		AXIS2_PATH_SEP_STR, "KeyStoreAdminService", AXIS2_PATH_SEP_STR, "keystores", 
		AXIS2_PATH_SEP_STR, keystore_name, ".dat", NULL);

	// Remove keystore and detail files
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
	axis2_conf_ctx_t* conf_ctx = NULL;
	axis2_conf_t* conf = NULL;
	axis2_char_t* repo_path = NULL;
	axis2_char_t* keystore_dir_path = NULL;
	WIN32_FIND_DATA find_data;
	HANDLE file_handle = NULL;
	adb_getKeyStoresResponse_t* response = NULL;
	axis2_char_t* keystore_name = NULL;
	axis2_char_t* keystore_type = NULL;
	axis2_char_t* tok = NULL;
	adb_KeyStoreData_t* data = NULL;

	// Form keystore directory name
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    repo_path = axis2_conf_get_repo(conf, env);
	keystore_dir_path = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
		AXIS2_PATH_SEP_STR, "KeyStoreAdminService", AXIS2_PATH_SEP_STR, "keystores/*.*", NULL);

	// Read file names in keystore directory	
	file_handle = FindFirstFile(keystore_dir_path, &find_data);
	AXIS2_FREE(env->allocator, keystore_dir_path);

	if (INVALID_HANDLE_VALUE == file_handle) return NULL;
	
	// Create response
	response = adb_getKeyStoresResponse_create(env);

	// Fill data
	do
	{
		keystore_name = NULL;
		keystore_type = NULL;
		tok = NULL;

		// Get name
		keystore_name = axutil_strdup(env, find_data.cFileName);

		// Get type
		tok = strtok(find_data.cFileName, ".");
		if (tok) tok = strtok(NULL, " .");
		if (NULL == tok) // No extension found
		{
			AXIS2_FREE(env->allocator, keystore_name);
			keystore_name = NULL;
			continue;
		}

		if (0 == axutil_strcmp(tok, "p12")) // PKCS12
		{
			keystore_type = "PKCS12";
		}
		else
		{
			AXIS2_FREE(env->allocator, keystore_name);
			keystore_name = NULL;
			continue;
		}

		data = adb_KeyStoreData_create(env);
		adb_KeyStoreData_set_keyStoreName(data, env, keystore_name);
		adb_KeyStoreData_set_keyStoreType(data, env, keystore_type);

		adb_getKeyStoresResponse_add_return(response, env, data);
	} while (FindNextFile(file_handle, &find_data));
	
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

	// Get parameters
	file_name = axutil_strdup(env, adb_addKeyStore_get_filename(addKeyStore, env));
	file_name = strtok(file_name, ".");
	password = adb_addKeyStore_get_password(addKeyStore, env);
	provider = adb_addKeyStore_get_provider(addKeyStore, env);
	pvt_key_pass = adb_addKeyStore_get_pvtkeyPass(addKeyStore, env);

	// Persist keystore details
	record = axutil_strcat(env, password, "|", provider, "|", pvt_key_pass, NULL);

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


