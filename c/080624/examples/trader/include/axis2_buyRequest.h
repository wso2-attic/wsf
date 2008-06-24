

        #ifndef AXIS2_BUYREQUEST_H
        #define AXIS2_BUYREQUEST_H

        /**
        * axis2_buyRequest.h
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
        *  axis2_buyRequest class class
        */
        typedef struct axis2_buyRequest axis2_buyRequest_t;

        AXIS2_EXTERN axis2_buyRequest_t* AXIS2_CALL
        axis2_buyRequest_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_buyRequest_free (
            axis2_buyRequest_t* buyRequest,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_buyRequest_get_qname (
            axis2_buyRequest_t* buyRequest,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_buyRequest_serialize(
            axis2_buyRequest_t* buyRequest,
            const axutil_env_t *env,
            axiom_node_t* buyRequest_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_buyRequest_deserialize(
            axis2_buyRequest_t* buyRequest,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for userid.
         */
        axis2_char_t* AXIS2_CALL
        axis2_buyRequest_get_userid(
            axis2_buyRequest_t* buyRequest,
            const axutil_env_t *env);

        /**
         * setter for userid
         */
        axis2_status_t AXIS2_CALL
        axis2_buyRequest_set_userid(
            axis2_buyRequest_t* buyRequest,
            const axutil_env_t *env,
            axis2_char_t*  param_userid);

        

        /**
         * getter for password.
         */
        axis2_char_t* AXIS2_CALL
        axis2_buyRequest_get_password(
            axis2_buyRequest_t* buyRequest,
            const axutil_env_t *env);

        /**
         * setter for password
         */
        axis2_status_t AXIS2_CALL
        axis2_buyRequest_set_password(
            axis2_buyRequest_t* buyRequest,
            const axutil_env_t *env,
            axis2_char_t*  param_password);

        

        /**
         * getter for symbol.
         */
        axis2_char_t* AXIS2_CALL
        axis2_buyRequest_get_symbol(
            axis2_buyRequest_t* buyRequest,
            const axutil_env_t *env);

        /**
         * setter for symbol
         */
        axis2_status_t AXIS2_CALL
        axis2_buyRequest_set_symbol(
            axis2_buyRequest_t* buyRequest,
            const axutil_env_t *env,
            axis2_char_t*  param_symbol);

        

        /**
         * getter for qty.
         */
        int AXIS2_CALL
        axis2_buyRequest_get_qty(
            axis2_buyRequest_t* buyRequest,
            const axutil_env_t *env);

        /**
         * setter for qty
         */
        axis2_status_t AXIS2_CALL
        axis2_buyRequest_set_qty(
            axis2_buyRequest_t* buyRequest,
            const axutil_env_t *env,
            int  param_qty);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_BUYREQUEST_H */
    

