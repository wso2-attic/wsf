

        #ifndef AXIS2_GETQUOTERESPONSE_H
        #define AXIS2_GETQUOTERESPONSE_H

        /**
        * axis2_getQuoteResponse.h
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
        *  axis2_getQuoteResponse class class
        */
        typedef struct axis2_getQuoteResponse axis2_getQuoteResponse_t;

        AXIS2_EXTERN axis2_getQuoteResponse_t* AXIS2_CALL
        axis2_getQuoteResponse_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_getQuoteResponse_free (
            axis2_getQuoteResponse_t* getQuoteResponse,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_getQuoteResponse_get_qname (
            axis2_getQuoteResponse_t* getQuoteResponse,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_getQuoteResponse_serialize(
            axis2_getQuoteResponse_t* getQuoteResponse,
            const axutil_env_t *env,
            axiom_node_t* getQuoteResponse_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_getQuoteResponse_deserialize(
            axis2_getQuoteResponse_t* getQuoteResponse,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for stock_quote.
         */
        axis2_StockQuote_t* AXIS2_CALL
        axis2_getQuoteResponse_get_stock_quote(
            axis2_getQuoteResponse_t* getQuoteResponse,
            const axutil_env_t *env);

        /**
         * setter for stock_quote
         */
        axis2_status_t AXIS2_CALL
        axis2_getQuoteResponse_set_stock_quote(
            axis2_getQuoteResponse_t* getQuoteResponse,
            const axutil_env_t *env,
            axis2_StockQuote_t*  param_stock_quote);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_GETQUOTERESPONSE_H */
    

