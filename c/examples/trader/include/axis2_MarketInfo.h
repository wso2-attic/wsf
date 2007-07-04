

        #ifndef AXIS2_MARKETINFO_H
        #define AXIS2_MARKETINFO_H

        /**
        * axis2_MarketInfo.h
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
        *  axis2_MarketInfo class class
        */
        typedef struct axis2_MarketInfo axis2_MarketInfo_t;

        AXIS2_EXTERN axis2_MarketInfo_t* AXIS2_CALL
        axis2_MarketInfo_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_MarketInfo_free (
            axis2_MarketInfo_t* MarketInfo,
            const axutil_env_t *env);

        

        axiom_node_t* AXIS2_CALL
        axis2_MarketInfo_serialize(
            axis2_MarketInfo_t* MarketInfo,
            const axutil_env_t *env,
            axiom_node_t* MarketInfo_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_MarketInfo_deserialize(
            axis2_MarketInfo_t* MarketInfo,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for totalTraded.
         */
        float AXIS2_CALL
        axis2_MarketInfo_get_totalTraded(
            axis2_MarketInfo_t* MarketInfo,
            const axutil_env_t *env);

        /**
         * setter for totalTraded
         */
        axis2_status_t AXIS2_CALL
        axis2_MarketInfo_set_totalTraded(
            axis2_MarketInfo_t* MarketInfo,
            const axutil_env_t *env,
            float  param_totalTraded);

        

        /**
         * getter for avgPrice.
         */
        float AXIS2_CALL
        axis2_MarketInfo_get_avgPrice(
            axis2_MarketInfo_t* MarketInfo,
            const axutil_env_t *env);

        /**
         * setter for avgPrice
         */
        axis2_status_t AXIS2_CALL
        axis2_MarketInfo_set_avgPrice(
            axis2_MarketInfo_t* MarketInfo,
            const axutil_env_t *env,
            float  param_avgPrice);

        

        /**
         * getter for avgPriceOfTrade.
         */
        float AXIS2_CALL
        axis2_MarketInfo_get_avgPriceOfTrade(
            axis2_MarketInfo_t* MarketInfo,
            const axutil_env_t *env);

        /**
         * setter for avgPriceOfTrade
         */
        axis2_status_t AXIS2_CALL
        axis2_MarketInfo_set_avgPriceOfTrade(
            axis2_MarketInfo_t* MarketInfo,
            const axutil_env_t *env,
            float  param_avgPriceOfTrade);

        

        /**
         * getter for marketCap.
         */
        float AXIS2_CALL
        axis2_MarketInfo_get_marketCap(
            axis2_MarketInfo_t* MarketInfo,
            const axutil_env_t *env);

        /**
         * setter for marketCap
         */
        axis2_status_t AXIS2_CALL
        axis2_MarketInfo_set_marketCap(
            axis2_MarketInfo_t* MarketInfo,
            const axutil_env_t *env,
            float  param_marketCap);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_MARKETINFO_H */
    

