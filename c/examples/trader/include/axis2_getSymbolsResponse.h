

        #ifndef AXIS2_GETSYMBOLSRESPONSE_H
        #define AXIS2_GETSYMBOLSRESPONSE_H

        /**
        * axis2_getSymbolsResponse.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2 version: #axisVersion# #today#
        */

        
          #include "axis2_ArrayOfString.h"
          

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
        *  axis2_getSymbolsResponse class class
        */
        typedef struct axis2_getSymbolsResponse axis2_getSymbolsResponse_t;

        AXIS2_EXTERN axis2_getSymbolsResponse_t* AXIS2_CALL
        axis2_getSymbolsResponse_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_getSymbolsResponse_free (
            axis2_getSymbolsResponse_t* getSymbolsResponse,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_getSymbolsResponse_get_qname (
            axis2_getSymbolsResponse_t* getSymbolsResponse,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_getSymbolsResponse_serialize(
            axis2_getSymbolsResponse_t* getSymbolsResponse,
            const axutil_env_t *env,
            axiom_node_t* getSymbolsResponse_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_getSymbolsResponse_deserialize(
            axis2_getSymbolsResponse_t* getSymbolsResponse,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for return.
         */
        axis2_ArrayOfString_t* AXIS2_CALL
        axis2_getSymbolsResponse_get_return(
            axis2_getSymbolsResponse_t* getSymbolsResponse,
            const axutil_env_t *env);

        /**
         * setter for return
         */
        axis2_status_t AXIS2_CALL
        axis2_getSymbolsResponse_set_return(
            axis2_getSymbolsResponse_t* getSymbolsResponse,
            const axutil_env_t *env,
            axis2_ArrayOfString_t*  param_return);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_GETSYMBOLSRESPONSE_H */
    

