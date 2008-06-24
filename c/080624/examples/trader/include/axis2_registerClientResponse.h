

        #ifndef AXIS2_REGISTERCLIENTRESPONSE_H
        #define AXIS2_REGISTERCLIENTRESPONSE_H

        /**
        * axis2_registerClientResponse.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2 version: #axisVersion# #today#
        */

        

        #include <stdio.h>
        #include <axiom.h>
        #include <axutil_utils.h>
        #include <axiom_soap.h>
        #include <axis2_client.h>

        #ifdef __cplusplus
        extern "C"
        {
        #endif

        #define AXIS2_DEFAULT_DIGIT_LIMIT 64
        /**
        *  axis2_registerClientResponse class class
        */
        typedef struct axis2_registerClientResponse axis2_registerClientResponse_t;

        AXIS2_EXTERN axis2_registerClientResponse_t* AXIS2_CALL
        axis2_registerClientResponse_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_registerClientResponse_free (
            axis2_registerClientResponse_t* registerClientResponse,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_registerClientResponse_get_qname (
            axis2_registerClientResponse_t* registerClientResponse,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_registerClientResponse_serialize(
            axis2_registerClientResponse_t* registerClientResponse,
            const axutil_env_t *env,
            axiom_node_t* registerClientResponse_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_registerClientResponse_deserialize(
            axis2_registerClientResponse_t* registerClientResponse,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for userid.
         */
        axis2_char_t* AXIS2_CALL
        axis2_registerClientResponse_get_userid(
            axis2_registerClientResponse_t* registerClientResponse,
            const axutil_env_t *env);

        /**
         * setter for userid
         */
        axis2_status_t AXIS2_CALL
        axis2_registerClientResponse_set_userid(
            axis2_registerClientResponse_t* registerClientResponse,
            const axutil_env_t *env,
            axis2_char_t*  param_userid);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_REGISTERCLIENTRESPONSE_H */
    

