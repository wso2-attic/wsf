

        #ifndef AXIS2_SELLRESPONSE_H
        #define AXIS2_SELLRESPONSE_H

        /**
        * axis2_sellResponse.h
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
        *  axis2_sellResponse class class
        */
        typedef struct axis2_sellResponse axis2_sellResponse_t;

        AXIS2_EXTERN axis2_sellResponse_t* AXIS2_CALL
        axis2_sellResponse_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_sellResponse_free (
            axis2_sellResponse_t* sellResponse,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_sellResponse_get_qname (
            axis2_sellResponse_t* sellResponse,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_sellResponse_serialize(
            axis2_sellResponse_t* sellResponse,
            const axutil_env_t *env,
            axiom_node_t* sellResponse_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_sellResponse_deserialize(
            axis2_sellResponse_t* sellResponse,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for trade_status.
         */
        axis2_TradeStatus_t* AXIS2_CALL
        axis2_sellResponse_get_trade_status(
            axis2_sellResponse_t* sellResponse,
            const axutil_env_t *env);

        /**
         * setter for trade_status
         */
        axis2_status_t AXIS2_CALL
        axis2_sellResponse_set_trade_status(
            axis2_sellResponse_t* sellResponse,
            const axutil_env_t *env,
            axis2_TradeStatus_t*  param_trade_status);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_SELLRESPONSE_H */
    

