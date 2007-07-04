

        #ifndef AXIS2_GETINFOREQUEST_H
        #define AXIS2_GETINFOREQUEST_H

        /**
        * axis2_getInfoRequest.h
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
        *  axis2_getInfoRequest class class
        */
        typedef struct axis2_getInfoRequest axis2_getInfoRequest_t;

        AXIS2_EXTERN axis2_getInfoRequest_t* AXIS2_CALL
        axis2_getInfoRequest_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_getInfoRequest_free (
            axis2_getInfoRequest_t* getInfoRequest,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_getInfoRequest_get_qname (
            axis2_getInfoRequest_t* getInfoRequest,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_getInfoRequest_serialize(
            axis2_getInfoRequest_t* getInfoRequest,
            const axutil_env_t *env,
            axiom_node_t* getInfoRequest_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_getInfoRequest_deserialize(
            axis2_getInfoRequest_t* getInfoRequest,
            const axutil_env_t *env, axiom_node_t* parent);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_GETINFOREQUEST_H */
    

