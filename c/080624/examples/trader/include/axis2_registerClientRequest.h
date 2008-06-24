

        #ifndef AXIS2_REGISTERCLIENTREQUEST_H
        #define AXIS2_REGISTERCLIENTREQUEST_H

        /**
        * axis2_registerClientRequest.h
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
        *  axis2_registerClientRequest class class
        */
        typedef struct axis2_registerClientRequest axis2_registerClientRequest_t;

        AXIS2_EXTERN axis2_registerClientRequest_t* AXIS2_CALL
        axis2_registerClientRequest_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_registerClientRequest_free (
            axis2_registerClientRequest_t* registerClientRequest,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_registerClientRequest_get_qname (
            axis2_registerClientRequest_t* registerClientRequest,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_registerClientRequest_serialize(
            axis2_registerClientRequest_t* registerClientRequest,
            const axutil_env_t *env,
            axiom_node_t* registerClientRequest_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_registerClientRequest_deserialize(
            axis2_registerClientRequest_t* registerClientRequest,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for ClientInfo.
         */
        axis2_ClientInfo_t* AXIS2_CALL
        axis2_registerClientRequest_get_ClientInfo(
            axis2_registerClientRequest_t* registerClientRequest,
            const axutil_env_t *env);

        /**
         * setter for ClientInfo
         */
        axis2_status_t AXIS2_CALL
        axis2_registerClientRequest_set_ClientInfo(
            axis2_registerClientRequest_t* registerClientRequest,
            const axutil_env_t *env,
            axis2_ClientInfo_t*  param_ClientInfo);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_REGISTERCLIENTREQUEST_H */
    

