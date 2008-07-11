%{
#include "wsf_wsdl_mode.h"

#define WS_USE_SOAP         "use_soap"
#define WS_RESPONSE_XOP     "response_xop"
#define WS_HTTP_METHOD      "http_method"
#define WS_USE_MTOM         "use_mtom"
#define WS_USE_WSA          "use_wsa"
#define WS_POLICY           "policy"
#define WS_SECURITY_TOKEN   "security_token"
#define WS_PROXY_HOST       "proxy_host"
#define WS_PROXY_PORT       "proxy_port"
#define WS_WSDL             "wsdl"

#define WS_SOAP_11          "1.1"
#define WS_SOAP_12          "1.2"
#define WS_TRUE             "true"
#define WS_FALSE            "false"

#define WS_TIMESTAMP        "time_stamp"
#define WS_USERNAME_TOKEN   "username_token"
#define WS_ENCRYPTION       "encryption"
#define WS_ALGORITHM        "algorithm"
#define WS_SIGNING          "signing"
#define WS_TOKEN_REFERENCE  "token_reference"
#define WS_ENCRYPT_SIGNATURE "encrypt_signature"
#define WS_PROTECTION_ORDER  "protection_order"

%}

%inline %{

static PyObject*
wsf_wsdl_request_function(
    axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    PyObject *options,          /* Python client options*/
    PyObject *wsdl,             /* wsdl file*/
    PyObject *operation,        /* operation name*/
    PyObject *arg,              /* arguments to operation*/
    PyObject *service,          /* Service name*/
    PyObject *port,             /* Port name*/
    PyObject *loc_xslt)         /* Location to find xslt templates*/
{
    wsf_wsdl_data_t *response = NULL;
    wsf_wsdl_data_t *user_params = NULL;
    axis2_bool_t wsdl_request_success = AXIS2_FALSE;
    axis2_char_t *wsdl_file_name = NULL;
    axis2_char_t *operation_name = NULL;
    axis2_char_t *location_of_xslr = NULL;
    axutil_hash_t *svc_client_options = NULL;
    axis2_char_t *service_name = NULL;
    axis2_char_t *port_name = NULL;
    
    AXIS2_LOG_INFO(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] Calling wsf_wsdl_request_function..");

    /* Get the WSDL file name from PyObject */
    if(PyString_Check(wsdl))
    {
        axis2_char_t *wsdl_file_name_python = NULL;
        wsdl_file_name_python = PyString_AsString(wsdl);

        if(!wsdl_file_name_python)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] WSDL file name cannot be null");
            return NULL; 
        }
        wsdl_file_name = AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t)*strlen(wsdl_file_name_python));  
        wsdl_file_name = strcpy(wsdl_file_name, wsdl_file_name_python);
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] WSDL file name should be a string.");
        return NULL;
    }

    /* Get the operation name from the PyObject */
    if(PyString_Check(operation))
    {
        axis2_char_t *operation_name_python = NULL;
        operation_name_python = PyString_AsString(operation);
        if(!operation_name_python)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] Operation name cannot be null.");
            return NULL;
        }
        operation_name = AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t)*strlen(operation_name_python));
        operation_name = strcpy(operation_name, operation_name_python);
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] Operation name should be a string.");
        return NULL;
    }
}
