

        #ifndef AXIS2_PORTFOLIO_H
        #define AXIS2_PORTFOLIO_H

        /**
        * axis2_PortFolio.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2 version: #axisVersion# #today#
        */

        
          #include "axis2_PortFolioItem.h"
          

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
        *  axis2_PortFolio class class
        */
        typedef struct axis2_PortFolio axis2_PortFolio_t;

        AXIS2_EXTERN axis2_PortFolio_t* AXIS2_CALL
        axis2_PortFolio_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_PortFolio_free (
            axis2_PortFolio_t* PortFolio,
            const axutil_env_t *env);

        

        axiom_node_t* AXIS2_CALL
        axis2_PortFolio_serialize(
            axis2_PortFolio_t* PortFolio,
            const axutil_env_t *env,
            axiom_node_t* PortFolio_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_PortFolio_deserialize(
            axis2_PortFolio_t* PortFolio,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for portFolioItem.
         */
        axutil_array_list_t* AXIS2_CALL
        axis2_PortFolio_get_portFolioItem(
            axis2_PortFolio_t* PortFolio,
            const axutil_env_t *env);

        /**
         * setter for portFolioItem
         */
        axis2_status_t AXIS2_CALL
        axis2_PortFolio_set_portFolioItem(
            axis2_PortFolio_t* PortFolio,
            const axutil_env_t *env,
            axutil_array_list_t*  param_portFolioItem);

        
        /**
        * resetter for portFolioItem
        */
        axis2_status_t AXIS2_CALL
        axis2_PortFolio_reset_portFolioItem(
            axis2_PortFolio_t* PortFolio,
            const axutil_env_t *env);
        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_PORTFOLIO_H */
    

