

        #ifndef AXIS2_CREATEACCOUNTREQUEST_H
        #define AXIS2_CREATEACCOUNTREQUEST_H

        /**
        * axis2_createAccountRequest.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2 version: #axisVersion# #today#
        */

        
          #include "axis2_ClientInfo.h"
          

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
        *  axis2_createAccountRequest class class
        */
        typedef struct axis2_createAccountRequest axis2_createAccountRequest_t;

        AXIS2_EXTERN axis2_createAccountRequest_t* AXIS2_CALL
        axis2_createAccountRequest_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_createAccountRequest_free (
            axis2_createAccountRequest_t* createAccountRequest,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_createAccountRequest_get_qname (
            axis2_createAccountRequest_t* createAccountRequest,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_createAccountRequest_serialize(
            axis2_createAccountRequest_t* createAccountRequest,
            const axutil_env_t *env,
            axiom_node_t* createAccountRequest_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_createAccountRequest_deserialize(
            axis2_createAccountRequest_t* createAccountRequest,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for clientinfo.
         */
        axis2_ClientInfo_t* AXIS2_CALL
        axis2_createAccountRequest_get_clientinfo(
            axis2_createAccountRequest_t* createAccountRequest,
            const axutil_env_t *env);

        /**
         * setter for clientinfo
         */
        axis2_status_t AXIS2_CALL
        axis2_createAccountRequest_set_clientinfo(
            axis2_createAccountRequest_t* createAccountRequest,
            const axutil_env_t *env,
            axis2_ClientInfo_t*  param_clientinfo);

        

        /**
         * getter for password.
         */
        axis2_char_t* AXIS2_CALL
        axis2_createAccountRequest_get_password(
            axis2_createAccountRequest_t* createAccountRequest,
            const axutil_env_t *env);

        /**
         * setter for password
         */
        axis2_status_t AXIS2_CALL
        axis2_createAccountRequest_set_password(
            axis2_createAccountRequest_t* createAccountRequest,
            const axutil_env_t *env,
            axis2_char_t*  param_password);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_CREATEACCOUNTREQUEST_H */
    

