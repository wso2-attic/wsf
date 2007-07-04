

        #ifndef AXIS2_DEPOSITRESPONSE_H
        #define AXIS2_DEPOSITRESPONSE_H

        /**
        * axis2_depositResponse.h
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
        *  axis2_depositResponse class class
        */
        typedef struct axis2_depositResponse axis2_depositResponse_t;

        AXIS2_EXTERN axis2_depositResponse_t* AXIS2_CALL
        axis2_depositResponse_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_depositResponse_free (
            axis2_depositResponse_t* depositResponse,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_depositResponse_get_qname (
            axis2_depositResponse_t* depositResponse,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_depositResponse_serialize(
            axis2_depositResponse_t* depositResponse,
            const axutil_env_t *env,
            axiom_node_t* depositResponse_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_depositResponse_deserialize(
            axis2_depositResponse_t* depositResponse,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for depositStatus.
         */
        axis2_char_t* AXIS2_CALL
        axis2_depositResponse_get_depositStatus(
            axis2_depositResponse_t* depositResponse,
            const axutil_env_t *env);

        /**
         * setter for depositStatus
         */
        axis2_status_t AXIS2_CALL
        axis2_depositResponse_set_depositStatus(
            axis2_depositResponse_t* depositResponse,
            const axutil_env_t *env,
            axis2_char_t*  param_depositStatus);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_DEPOSITRESPONSE_H */
    

