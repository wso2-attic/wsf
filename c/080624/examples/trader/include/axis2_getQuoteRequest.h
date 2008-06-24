

        #ifndef AXIS2_GETQUOTEREQUEST_H
        #define AXIS2_GETQUOTEREQUEST_H

        /**
        * axis2_getQuoteRequest.h
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
        *  axis2_getQuoteRequest class class
        */
        typedef struct axis2_getQuoteRequest axis2_getQuoteRequest_t;

        AXIS2_EXTERN axis2_getQuoteRequest_t* AXIS2_CALL
        axis2_getQuoteRequest_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_getQuoteRequest_free (
            axis2_getQuoteRequest_t* getQuoteRequest,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_getQuoteRequest_get_qname (
            axis2_getQuoteRequest_t* getQuoteRequest,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_getQuoteRequest_serialize(
            axis2_getQuoteRequest_t* getQuoteRequest,
            const axutil_env_t *env,
            axiom_node_t* getQuoteRequest_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_getQuoteRequest_deserialize(
            axis2_getQuoteRequest_t* getQuoteRequest,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for symbol.
         */
        axis2_char_t* AXIS2_CALL
        axis2_getQuoteRequest_get_symbol(
            axis2_getQuoteRequest_t* getQuoteRequest,
            const axutil_env_t *env);

        /**
         * setter for symbol
         */
        axis2_status_t AXIS2_CALL
        axis2_getQuoteRequest_set_symbol(
            axis2_getQuoteRequest_t* getQuoteRequest,
            const axutil_env_t *env,
            axis2_char_t*  param_symbol);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_GETQUOTEREQUEST_H */
    

