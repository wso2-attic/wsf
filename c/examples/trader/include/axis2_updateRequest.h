

        #ifndef AXIS2_UPDATEREQUEST_H
        #define AXIS2_UPDATEREQUEST_H

        /**
        * axis2_updateRequest.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2 version: #axisVersion# #today#
        */

        
          #include "axis2_StockQuote.h"
          

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
        *  axis2_updateRequest class class
        */
        typedef struct axis2_updateRequest axis2_updateRequest_t;

        AXIS2_EXTERN axis2_updateRequest_t* AXIS2_CALL
        axis2_updateRequest_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_updateRequest_free (
            axis2_updateRequest_t* updateRequest,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_updateRequest_get_qname (
            axis2_updateRequest_t* updateRequest,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_updateRequest_serialize(
            axis2_updateRequest_t* updateRequest,
            const axutil_env_t *env,
            axiom_node_t* updateRequest_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_updateRequest_deserialize(
            axis2_updateRequest_t* updateRequest,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for stock_quote.
         */
        axis2_StockQuote_t* AXIS2_CALL
        axis2_updateRequest_get_stock_quote(
            axis2_updateRequest_t* updateRequest,
            const axutil_env_t *env);

        /**
         * setter for stock_quote
         */
        axis2_status_t AXIS2_CALL
        axis2_updateRequest_set_stock_quote(
            axis2_updateRequest_t* updateRequest,
            const axutil_env_t *env,
            axis2_StockQuote_t*  param_stock_quote);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_UPDATEREQUEST_H */
    

