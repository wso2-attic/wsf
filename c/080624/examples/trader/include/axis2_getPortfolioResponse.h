

        #ifndef AXIS2_GETPORTFOLIORESPONSE_H
        #define AXIS2_GETPORTFOLIORESPONSE_H

        /**
        * axis2_getPortfolioResponse.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2 version: #axisVersion# #today#
        */

        
          #include "axis2_PortFolio.h"
          

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
        *  axis2_getPortfolioResponse class class
        */
        typedef struct axis2_getPortfolioResponse axis2_getPortfolioResponse_t;

        AXIS2_EXTERN axis2_getPortfolioResponse_t* AXIS2_CALL
        axis2_getPortfolioResponse_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_getPortfolioResponse_free (
            axis2_getPortfolioResponse_t* getPortfolioResponse,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_getPortfolioResponse_get_qname (
            axis2_getPortfolioResponse_t* getPortfolioResponse,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_getPortfolioResponse_serialize(
            axis2_getPortfolioResponse_t* getPortfolioResponse,
            const axutil_env_t *env,
            axiom_node_t* getPortfolioResponse_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_getPortfolioResponse_deserialize(
            axis2_getPortfolioResponse_t* getPortfolioResponse,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for portFolio.
         */
        axis2_PortFolio_t* AXIS2_CALL
        axis2_getPortfolioResponse_get_portFolio(
            axis2_getPortfolioResponse_t* getPortfolioResponse,
            const axutil_env_t *env);

        /**
         * setter for portFolio
         */
        axis2_status_t AXIS2_CALL
        axis2_getPortfolioResponse_set_portFolio(
            axis2_getPortfolioResponse_t* getPortfolioResponse,
            const axutil_env_t *env,
            axis2_PortFolio_t*  param_portFolio);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_GETPORTFOLIORESPONSE_H */
    

