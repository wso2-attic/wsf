

        #ifndef AXIS2_GETINFORESPONSE_H
        #define AXIS2_GETINFORESPONSE_H

        /**
        * axis2_getInfoResponse.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2 version: #axisVersion# #today#
        */

        
          #include "axis2_MarketInfo.h"
          

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
        *  axis2_getInfoResponse class class
        */
        typedef struct axis2_getInfoResponse axis2_getInfoResponse_t;

        AXIS2_EXTERN axis2_getInfoResponse_t* AXIS2_CALL
        axis2_getInfoResponse_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_getInfoResponse_free (
            axis2_getInfoResponse_t* getInfoResponse,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_getInfoResponse_get_qname (
            axis2_getInfoResponse_t* getInfoResponse,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_getInfoResponse_serialize(
            axis2_getInfoResponse_t* getInfoResponse,
            const axutil_env_t *env,
            axiom_node_t* getInfoResponse_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_getInfoResponse_deserialize(
            axis2_getInfoResponse_t* getInfoResponse,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for marketInfo.
         */
        axis2_MarketInfo_t* AXIS2_CALL
        axis2_getInfoResponse_get_marketInfo(
            axis2_getInfoResponse_t* getInfoResponse,
            const axutil_env_t *env);

        /**
         * setter for marketInfo
         */
        axis2_status_t AXIS2_CALL
        axis2_getInfoResponse_set_marketInfo(
            axis2_getInfoResponse_t* getInfoResponse,
            const axutil_env_t *env,
            axis2_MarketInfo_t*  param_marketInfo);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_GETINFORESPONSE_H */
    

