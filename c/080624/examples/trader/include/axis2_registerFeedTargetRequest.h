

        #ifndef AXIS2_REGISTERFEEDTARGETREQUEST_H
        #define AXIS2_REGISTERFEEDTARGETREQUEST_H

        /**
        * axis2_registerFeedTargetRequest.h
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
        *  axis2_registerFeedTargetRequest class class
        */
        typedef struct axis2_registerFeedTargetRequest axis2_registerFeedTargetRequest_t;

        AXIS2_EXTERN axis2_registerFeedTargetRequest_t* AXIS2_CALL
        axis2_registerFeedTargetRequest_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_registerFeedTargetRequest_free (
            axis2_registerFeedTargetRequest_t* registerFeedTargetRequest,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_registerFeedTargetRequest_get_qname (
            axis2_registerFeedTargetRequest_t* registerFeedTargetRequest,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_registerFeedTargetRequest_serialize(
            axis2_registerFeedTargetRequest_t* registerFeedTargetRequest,
            const axutil_env_t *env,
            axiom_node_t* registerFeedTargetRequest_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_registerFeedTargetRequest_deserialize(
            axis2_registerFeedTargetRequest_t* registerFeedTargetRequest,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for EPR.
         */
        axis2_char_t* AXIS2_CALL
        axis2_registerFeedTargetRequest_get_EPR(
            axis2_registerFeedTargetRequest_t* registerFeedTargetRequest,
            const axutil_env_t *env);

        /**
         * setter for EPR
         */
        axis2_status_t AXIS2_CALL
        axis2_registerFeedTargetRequest_set_EPR(
            axis2_registerFeedTargetRequest_t* registerFeedTargetRequest,
            const axutil_env_t *env,
            axis2_char_t*  param_EPR);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_REGISTERFEEDTARGETREQUEST_H */
    

