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
        axis2_char_t *sub_key_str = NULL;
        sub_data = wsdl_data_create_object(env);
        while(PyDict_Next(value, &pos, &d_key, &d_value))
        {
            if(PyString_Check(d_key))
            { 
                sub_key_str = axutil_strdup(env, PyString_AsString(d_key));
                wsf_wsdl_convert_user_params_to_wsdl_data(
                                            env,
                                            sub_key_str,
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
        else if(PyFloat_CheckExact(value))
        {
            double from_float = 0;
            char double_str[32];    
            type_str = axutil_strdup(env, "float");
            from_float = PyFloat_AsDouble(value);
            sprintf(double_str, "%f", from_float);
            val_str = axutil_strdup(env, double_str); 
        }
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


static PyObject * 
wsf_wsdl_convert_wsdl_data_to_python_dict(
    axutil_env_t *env,
    wsf_wsdl_data_t *response)
{
    PyObject *element = NULL;
    wsf_wsdl_data_iterator_t *iterator = NULL;
    
    if(response->children_type == CHILDREN_TYPE_NONE)
    {
        axis2_char_t* data_type = response->data_type;
        axis2_char_t* data = (axis2_char_t *)(response->data);
        if (strcmp(data_type, "str") == 0)
        {
            /* Convert C string to Python String*/
            element = PyString_FromString(data);            
        }
        else if(strcmp(data_type, "int") == 0)
        {
            /* Convert C string to python int */
            element = PyInt_FromString(data, NULL, 10);
        }
        else if(strcmp(data_type, "long") == 0)
        {
            /* Create Python long from C string. */
            element = PyLong_FromString(data, NULL, 10);
        }
        else if(strcmp(data_type, "float") == 0)
        {
            /* Create Python Float from string */
            PyObject *float_str = PyString_FromString(data);
            element = PyFloat_FromString(float_str, NULL);
        }
        else
        {
            element = PyString_FromString(data);
        }
        return element;
    }

    iterator = wsdl_data_iterator_create(env, response);
    /* Handle there is no return data in respose wsdl_data_t */
    if(!wsdl_data_iterator_first(env, &iterator))
        return Py_None;

    if(iterator->type == CHILDREN_TYPE_ARRAY_ELEMENTS)
    {   
        /* When XML schema support array of elements, text value of those elements will
         * return as Python list.
         */
        element = PyList_New(0);
        do
        {
            PyObject *sub_element;
            wsf_wsdl_data_t *data = iterator->this;

            sub_element = wsf_wsdl_convert_wsdl_data_to_python_dict(env, data);
            
            PyList_Append(element, sub_element);            
        }while(wsdl_data_iterator_next(env, &iterator));
    } 
    else if(iterator->type == CHILDREN_TYPE_ATTRIBUTES)
    {
        /* XML element attributes will return as python dictionary. */
        element = PyDict_New();
        do
        {
            PyObject *sub_element;
            PyObject *key;
            wsf_wsdl_data_t *data = iterator->this;
            sub_element = wsf_wsdl_convert_wsdl_data_to_python_dict(env, data);
            key = PyString_FromString(iterator->name);
            PyDict_SetItem(element, key, sub_element);
        }while(wsdl_data_iterator_next(env, &iterator));
    }

    wsdl_data_iterator_free(env, iterator);

    return element;
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
    wsf_wsdl_data_t *response = NULL;
    wsf_wsdl_data_t *user_params = NULL;
    axis2_bool_t wsdl_request_success = AXIS2_FALSE; 
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
        axis2_char_t *key_string = NULL;
        while(PyDict_Next(options, &pos, &d_key, &d_value))
        {
            if(PyString_Check(d_key))
            {
                key_string = axutil_strdup(env, PyString_AsString(d_key));
                svc_client_options = axutil_hash_make(env);
                wsf_evaluate_client_options_and_insert_to_hash(env, key_string, d_value, svc_client_options);       
            }
        }
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] Service client options should be a Python dictionary.");
        return NULL;
    }
    
    /* Convert input to the Web service opration from python dictionary to 
     * wsdl_data_t structure.
     */
    if(PyDict_Check(arg))
    {
        PyObject *d_key, *d_value;
        int pos = 0;
        char *key_string = NULL;
        while(PyDict_Next(arg, &pos, &d_key, &d_value))
        {
            if(PyString_Check(d_key))
            {
                key_string = axutil_strdup(env, PyString_AsString(d_key));
                user_params = wsdl_data_create_object(env);
                wsf_wsdl_convert_user_params_to_wsdl_data(env, key_string, d_value, user_params);
            }
        }
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] Arguments to web service operations should be a Python Dictionary.");
        return NULL;
    }
    
    /* call wsdl request by giving required parameters get from user */
    wsdl_request_success = wsf_wsdl_request(env,
                                wsdl_file_name,
                                operation_name,
                                user_params,
                                location_of_python_home,
                                svc_client,
                                svc_client_options, 
                                service_name,
                                port_name,
                                &response);

    if (wsdl_request_success == AXIS2_FAILURE)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] wsf_wsdl_request returned fault.");
        PyErr_SetFromErrno(PyExc_SystemError);
        return NULL;
    }

    if(response)
    {
        PyObject *reponse_python;
        /* Convert wsdl_data_t to Python dictionary and return. */
        reponse_python = wsf_wsdl_convert_wsdl_data_to_python_dict(env, response);
        return reponse_python;
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-python][wsdl_mode] wsf_wsdl_request response is null.");
        PyErr_SetFromErrno(PyExc_SystemError);
        return NULL;
    }
    return NULL;
}


%}

