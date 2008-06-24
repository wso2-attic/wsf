

        #ifndef AXIS2_DEPOSITREQUEST_H
        #define AXIS2_DEPOSITREQUEST_H

        /**
        * axis2_depositRequest.h
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
        *  axis2_depositRequest class class
        */
        typedef struct axis2_depositRequest axis2_depositRequest_t;

        AXIS2_EXTERN axis2_depositRequest_t* AXIS2_CALL
        axis2_depositRequest_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_depositRequest_free (
            axis2_depositRequest_t* depositRequest,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_depositRequest_get_qname (
            axis2_depositRequest_t* depositRequest,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_depositRequest_serialize(
            axis2_depositRequest_t* depositRequest,
            const axutil_env_t *env,
            axiom_node_t* depositRequest_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_depositRequest_deserialize(
            axis2_depositRequest_t* depositRequest,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for useridr.
         */
        axis2_char_t* AXIS2_CALL
        axis2_depositRequest_get_useridr(
            axis2_depositRequest_t* depositRequest,
            const axutil_env_t *env);

        /**
         * setter for useridr
         */
        axis2_status_t AXIS2_CALL
        axis2_depositRequest_set_useridr(
            axis2_depositRequest_t* depositRequest,
            const axutil_env_t *env,
            axis2_char_t*  param_useridr);

        

        /**
         * getter for password.
         */
        axis2_char_t* AXIS2_CALL
        axis2_depositRequest_get_password(
            axis2_depositRequest_t* depositRequest,
            const axutil_env_t *env);

        /**
         * setter for password
         */
        axis2_status_t AXIS2_CALL
        axis2_depositRequest_set_password(
            axis2_depositRequest_t* depositRequest,
            const axutil_env_t *env,
            axis2_char_t*  param_password);

        

        /**
         * getter for amount.
         */
        float AXIS2_CALL
        axis2_depositRequest_get_amount(
            axis2_depositRequest_t* depositRequest,
            const axutil_env_t *env);

        /**
         * setter for amount
         */
        axis2_status_t AXIS2_CALL
        axis2_depositRequest_set_amount(
            axis2_depositRequest_t* depositRequest,
            const axutil_env_t *env,
            float  param_amount);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_DEPOSITREQUEST_H */
    

