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

static void
wsf_evaluate_client_options_and_insert_to_hash(
    axutil_env_t *env,
    axis2_char_t *key,
    PyObject *value,
    axutil_hash_t *hash)
{
    if(!strcmp(key, WS_USE_SOAP))
    {
        axis2_char_t *use_soap_val = NULL;
        if(PyString_Check(value))
        {
            use_soap_val = axutil_strdup(env, PyString_AsString(value));
            if((!strcmp(use_soap_val, WS_TRUE)) ||
                (!strcmp(use_soap_val, WS_SOAP_12)))
            {
                axutil_hash_set(hash,
                    WSF_WSDL_USE_SOAP,
                    AXIS2_HASH_KEY_STRING,
                    WSF_WSDL_SOAP_1_2);
            }
            else if(!strcmp(use_soap_val, WS_SOAP_11))
            {
                axutil_hash_set(hash,
                    WSF_WSDL_USE_SOAP,
                    AXIS2_HASH_KEY_STRING,
                    WSF_WSDL_SOAP_1_1);       
            }
            else if(!strcmp(use_soap_val, WS_FALSE))
            {
                axutil_hash_set(hash,
                    WSF_WSDL_USE_SOAP,
                    AXIS2_HASH_KEY_STRING,
                    WSF_WSDL_REST);
            }
        }
    }
}

static void
wsf_wsdl_convert_user_params_to_wsdl_data(
    axutil_env_t *env,
    axis2_char_t *key,
    PyObject *value,
    wsf_wsdl_data_t *wsdl_data)
{
    axis2_char_t *key_str = NULL;
    
    key_str = axutil_strdup(env, key);

    if(PyDict_Check(value))
    {
        wsf_wsdl_data_t *sub_data = NULL;
        PyObject *d_key, *d_value = NULL;
        int pos = 0;
        char *sub_key_str = NULL;
        while(PyDict_Next(value, &pos, &d_key, &d_value))
        {
            if(PyString_Check(d_key))
            { 
                sub_key_str = PyString_AsString(d_key);
                wsf_wsdl_convert_user_params_to_wsdl_data(
                                            env,
                                            (axis2_char_t*)sub_key_str,
                                            d_value,
                                            sub_data);                                                  
            }
            else
            {
                wsdl_data = NULL;
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                    "[wsf-python][wsdl_data] Wrong format in client options");
                return;
            }
        }
        wsdl_data_add_object(
            env, 
            wsdl_data, 
            key_str, 
            "whatever", 
            sub_data, 
            "http://www.example.org/sample/", 
            NULL); 
    }
    else
    {
        axis2_char_t *type_str = NULL;
        axis2_char_t *val_str = NULL;
        if(PyInt_CheckExact(value))
        {
            PyObject *val_str_object = NULL;
            long int_val;
            type_str = axutil_strdup(env, "int");       
            int_val = PyInt_AsLong(value);
            if(PyErr_Occurred() != NULL)
            {
                wsdl_data = NULL;
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                    "[wsf-python][wsdl_data] Errorr occurred during type converion!");
                return;
            }
            val_str_object = PyString_FromFormat("%ld", int_val);            
            val_str = axutil_strdup(env, PyString_AsString(val_str_object)); 
        } 
        else if(PyBool_Check(value))
        {
            if(value == Py_False)
            {
                val_str = axutil_strdup(env, "False");
            }
            else if(value == Py_True)
            {
                val_str = axutil_strdup(env, "True");
            }
            type_str = axutil_strdup(env, "bool");
        }
        else if(PyLong_CheckExact(value))
        {
            long long_val;
            PyObject *val_str_object = NULL;
            long_val = PyLong_AsLong(value);
            val_str_object = PyString_FromFormat("%ld", long_val);
            type_str = axutil_strdup(env, "long");
            val_str = axutil_strdup(env, PyString_AsString(val_str_object));
        }
        /*else if(PyFloat_CheckExact(value))
        {
            
            type_str = axutil_strdup(env, "float");
        }*/
        /* Float type is not supported. TODO: Fix float */
        else if(PyString_CheckExact(value))
        {
            type_str = axutil_strdup(env, "str");
            val_str = axutil_strdup(env, PyString_AsString(value));
        }

        wsdl_data_add_simple_element(
            env,    
            wsdl_data, 
            key_str, 
            type_str, 
            val_str, 
            "http://www.w3.org/2001/XMLSchema",
            "http://www.example.org/sample/"); 
    }
}

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
    PyObject *python_home)         /* Location to find xslt templates and type map*/
{
    /*wsf_wsdl_data_t *response = NULL;*/
    /* wsf_wsdl_data_t *user_params = NULL;*/
    /* axis2_bool_t wsdl_request_success = AXIS2_FALSE; */
    axis2_char_t *wsdl_file_name = NULL;
    axis2_char_t *operation_name = NULL;
    axis2_char_t *location_of_python_home = NULL;
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

    /* Service name from PyObject */
    if(PyString_Check(service))
    {
        axis2_char_t *service_name_python = NULL;
        service_name_python = PyString_AsString(service);
        if(!service_name_python)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] Service name cannot be null");
            return NULL;
        }
        service_name = AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t)*strlen(service_name_python));
        service_name = strcpy(service_name, service_name_python);
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] Service name should be a string.");
        return NULL;
    }

    /* Port name */
    if(PyString_Check(port))
    {
        axis2_char_t *port_name_python = NULL;
        port_name_python = PyString_AsString(port);
        if(!port_name_python)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] Port name cannot be null.");
            return NULL;
        }

        port_name = AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t)*strlen(port_name_python));
        port_name = strcpy(port_name, port_name_python);
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] Port name should be a string.");
        return NULL;
    }

    /* Getting XSLT file location from PyObject */
    if(PyString_Check(python_home))
    {
        axis2_char_t *python_home_str = NULL;
        python_home_str = PyString_AsString(python_home);
        if(!python_home_str)
        {   
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] Location of XSLT cannot be null.");
            return NULL;
        }

        location_of_python_home = AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t)*strlen(python_home_str));
        location_of_python_home = strcpy(location_of_python_home, python_home_str);
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] Location of XSLT should be a string.");
        return NULL;
    }

    /* Getting service client options from PyDictObject */
    if(PyDict_Check(options))
    {
        PyObject *d_key, *d_value;
        int pos = 0;
        char *key_string = NULL;
        while(PyDict_Next(options, &pos, &d_key, &d_value))
        {
            if(PyString_Check(d_key))
            {
                key_string = PyString_AsString(d_key);
                wsf_evaluate_client_options_and_insert_to_hash(env, key_string, d_value, svc_client_options);       
            }
        }
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] Service client options should be a Python dictionary.");
        return NULL;
    }

    return NULL;
}


%}

