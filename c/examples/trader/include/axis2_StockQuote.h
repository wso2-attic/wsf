

        #ifndef AXIS2_STOCKQUOTE_H
        #define AXIS2_STOCKQUOTE_H

        /**
        * axis2_StockQuote.h
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
        *  axis2_StockQuote class class
        */
        typedef struct axis2_StockQuote axis2_StockQuote_t;

        AXIS2_EXTERN axis2_StockQuote_t* AXIS2_CALL
        axis2_StockQuote_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_StockQuote_free (
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env);

        

        axiom_node_t* AXIS2_CALL
        axis2_StockQuote_serialize(
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env,
            axiom_node_t* StockQuote_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_StockQuote_deserialize(
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for name.
         */
        axis2_char_t* AXIS2_CALL
        axis2_StockQuote_get_name(
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env);

        /**
         * setter for name
         */
        axis2_status_t AXIS2_CALL
        axis2_StockQuote_set_name(
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env,
            axis2_char_t*  param_name);

        

        /**
         * getter for symbol.
         */
        axis2_char_t* AXIS2_CALL
        axis2_StockQuote_get_symbol(
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env);

        /**
         * setter for symbol
         */
        axis2_status_t AXIS2_CALL
        axis2_StockQuote_set_symbol(
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env,
            axis2_char_t*  param_symbol);

        

        /**
         * getter for price.
         */
        float AXIS2_CALL
        axis2_StockQuote_get_price(
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env);

        /**
         * setter for price
         */
        axis2_status_t AXIS2_CALL
        axis2_StockQuote_set_price(
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env,
            float  param_price);

        

        /**
         * getter for high.
         */
        float AXIS2_CALL
        axis2_StockQuote_get_high(
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env);

        /**
         * setter for high
         */
        axis2_status_t AXIS2_CALL
        axis2_StockQuote_set_high(
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env,
            float  param_high);

        

        /**
         * getter for low.
         */
        float AXIS2_CALL
        axis2_StockQuote_get_low(
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env);

        /**
         * setter for low
         */
        axis2_status_t AXIS2_CALL
        axis2_StockQuote_set_low(
            axis2_StockQuote_t* StockQuote,
            const axutil_env_t *env,
            float  param_low);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_STOCKQUOTE_H */
    

