

        #ifndef AXIS2_LOGINREQUEST_H
        #define AXIS2_LOGINREQUEST_H

        /**
        * axis2_loginRequest.h
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
        *  axis2_loginRequest class class
        */
        typedef struct axis2_loginRequest axis2_loginRequest_t;

        AXIS2_EXTERN axis2_loginRequest_t* AXIS2_CALL
        axis2_loginRequest_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_loginRequest_free (
            axis2_loginRequest_t* loginRequest,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_loginRequest_get_qname (
            axis2_loginRequest_t* loginRequest,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_loginRequest_serialize(
            axis2_loginRequest_t* loginRequest,
            const axutil_env_t *env,
            axiom_node_t* loginRequest_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_loginRequest_deserialize(
            axis2_loginRequest_t* loginRequest,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for username.
         */
        axis2_char_t* AXIS2_CALL
        axis2_loginRequest_get_username(
            axis2_loginRequest_t* loginRequest,
            const axutil_env_t *env);

        /**
         * setter for username
         */
        axis2_status_t AXIS2_CALL
        axis2_loginRequest_set_username(
            axis2_loginRequest_t* loginRequest,
            const axutil_env_t *env,
            axis2_char_t*  param_username);

        

        /**
         * getter for password.
         */
        axis2_char_t* AXIS2_CALL
        axis2_loginRequest_get_password(
            axis2_loginRequest_t* loginRequest,
            const axutil_env_t *env);

        /**
         * setter for password
         */
        axis2_status_t AXIS2_CALL
        axis2_loginRequest_set_password(
            axis2_loginRequest_t* loginRequest,
            const axutil_env_t *env,
            axis2_char_t*  param_password);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_LOGINREQUEST_H */
    

