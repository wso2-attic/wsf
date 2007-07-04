

        #ifndef AXIS2_TRADESTATUS_H
        #define AXIS2_TRADESTATUS_H

        /**
        * axis2_TradeStatus.h
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
        *  axis2_TradeStatus class class
        */
        typedef struct axis2_TradeStatus axis2_TradeStatus_t;

        AXIS2_EXTERN axis2_TradeStatus_t* AXIS2_CALL
        axis2_TradeStatus_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_TradeStatus_free (
            axis2_TradeStatus_t* TradeStatus,
            const axutil_env_t *env);

        

        axiom_node_t* AXIS2_CALL
        axis2_TradeStatus_serialize(
            axis2_TradeStatus_t* TradeStatus,
            const axutil_env_t *env,
            axiom_node_t* TradeStatus_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_TradeStatus_deserialize(
            axis2_TradeStatus_t* TradeStatus,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for status.
         */
        axis2_bool_t AXIS2_CALL
        axis2_TradeStatus_get_status(
            axis2_TradeStatus_t* TradeStatus,
            const axutil_env_t *env);

        /**
         * setter for status
         */
        axis2_status_t AXIS2_CALL
        axis2_TradeStatus_set_status(
            axis2_TradeStatus_t* TradeStatus,
            const axutil_env_t *env,
            axis2_bool_t  param_status);

        

        /**
         * getter for reason.
         */
        axis2_char_t* AXIS2_CALL
        axis2_TradeStatus_get_reason(
            axis2_TradeStatus_t* TradeStatus,
            const axutil_env_t *env);

        /**
         * setter for reason
         */
        axis2_status_t AXIS2_CALL
        axis2_TradeStatus_set_reason(
            axis2_TradeStatus_t* TradeStatus,
            const axutil_env_t *env,
            axis2_char_t*  param_reason);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_TRADESTATUS_H */
    

