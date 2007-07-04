

        #ifndef AXIS2_PORTFOLIOITEM_H
        #define AXIS2_PORTFOLIOITEM_H

        /**
        * axis2_PortFolioItem.h
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
        *  axis2_PortFolioItem class class
        */
        typedef struct axis2_PortFolioItem axis2_PortFolioItem_t;

        AXIS2_EXTERN axis2_PortFolioItem_t* AXIS2_CALL
        axis2_PortFolioItem_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_PortFolioItem_free (
            axis2_PortFolioItem_t* PortFolioItem,
            const axutil_env_t *env);

        

        axiom_node_t* AXIS2_CALL
        axis2_PortFolioItem_serialize(
            axis2_PortFolioItem_t* PortFolioItem,
            const axutil_env_t *env,
            axiom_node_t* PortFolioItem_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_PortFolioItem_deserialize(
            axis2_PortFolioItem_t* PortFolioItem,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for symbol.
         */
        axis2_char_t* AXIS2_CALL
        axis2_PortFolioItem_get_symbol(
            axis2_PortFolioItem_t* PortFolioItem,
            const axutil_env_t *env);

        /**
         * setter for symbol
         */
        axis2_status_t AXIS2_CALL
        axis2_PortFolioItem_set_symbol(
            axis2_PortFolioItem_t* PortFolioItem,
            const axutil_env_t *env,
            axis2_char_t*  param_symbol);

        

        /**
         * getter for amount.
         */
        int AXIS2_CALL
        axis2_PortFolioItem_get_amount(
            axis2_PortFolioItem_t* PortFolioItem,
            const axutil_env_t *env);

        /**
         * setter for amount
         */
        axis2_status_t AXIS2_CALL
        axis2_PortFolioItem_set_amount(
            axis2_PortFolioItem_t* PortFolioItem,
            const axutil_env_t *env,
            int  param_amount);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_PORTFOLIOITEM_H */
    

