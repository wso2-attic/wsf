

        #ifndef AXIS2_BUYRESPONSE_H
        #define AXIS2_BUYRESPONSE_H

        /**
        * axis2_buyResponse.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2 version: #axisVersion# #today#
        */

        
          #include "axis2_TradeStatus.h"
          

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
        *  axis2_buyResponse class class
        */
        typedef struct axis2_buyResponse axis2_buyResponse_t;

        AXIS2_EXTERN axis2_buyResponse_t* AXIS2_CALL
        axis2_buyResponse_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_buyResponse_free (
            axis2_buyResponse_t* buyResponse,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_buyResponse_get_qname (
            axis2_buyResponse_t* buyResponse,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_buyResponse_serialize(
            axis2_buyResponse_t* buyResponse,
            const axutil_env_t *env,
            axiom_node_t* buyResponse_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_buyResponse_deserialize(
            axis2_buyResponse_t* buyResponse,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for trade_status.
         */
        axis2_TradeStatus_t* AXIS2_CALL
        axis2_buyResponse_get_trade_status(
            axis2_buyResponse_t* buyResponse,
            const axutil_env_t *env);

        /**
         * setter for trade_status
         */
        axis2_status_t AXIS2_CALL
        axis2_buyResponse_set_trade_status(
            axis2_buyResponse_t* buyResponse,
            const axutil_env_t *env,
            axis2_TradeStatus_t*  param_trade_status);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_BUYRESPONSE_H */
    

