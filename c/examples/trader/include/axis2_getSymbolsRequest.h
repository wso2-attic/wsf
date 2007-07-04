

        #ifndef AXIS2_GETSYMBOLSREQUEST_H
        #define AXIS2_GETSYMBOLSREQUEST_H

        /**
        * axis2_getSymbolsRequest.h
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
        *  axis2_getSymbolsRequest class class
        */
        typedef struct axis2_getSymbolsRequest axis2_getSymbolsRequest_t;

        AXIS2_EXTERN axis2_getSymbolsRequest_t* AXIS2_CALL
        axis2_getSymbolsRequest_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_getSymbolsRequest_free (
            axis2_getSymbolsRequest_t* getSymbolsRequest,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_getSymbolsRequest_get_qname (
            axis2_getSymbolsRequest_t* getSymbolsRequest,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_getSymbolsRequest_serialize(
            axis2_getSymbolsRequest_t* getSymbolsRequest,
            const axutil_env_t *env,
            axiom_node_t* getSymbolsRequest_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_getSymbolsRequest_deserialize(
            axis2_getSymbolsRequest_t* getSymbolsRequest,
            const axutil_env_t *env, axiom_node_t* parent);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_GETSYMBOLSREQUEST_H */
    

