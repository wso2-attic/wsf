

        #ifndef AXIS2_GETPORTFOLIOREQUEST_H
        #define AXIS2_GETPORTFOLIOREQUEST_H

        /**
        * axis2_getPortfolioRequest.h
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
        *  axis2_getPortfolioRequest class class
        */
        typedef struct axis2_getPortfolioRequest axis2_getPortfolioRequest_t;

        AXIS2_EXTERN axis2_getPortfolioRequest_t* AXIS2_CALL
        axis2_getPortfolioRequest_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_getPortfolioRequest_free (
            axis2_getPortfolioRequest_t* getPortfolioRequest,
            const axutil_env_t *env);

        
        axutil_qname_t* AXIS2_CALL
        axis2_getPortfolioRequest_get_qname (
            axis2_getPortfolioRequest_t* getPortfolioRequest,
            const axutil_env_t *env);
        

        axiom_node_t* AXIS2_CALL
        axis2_getPortfolioRequest_serialize(
            axis2_getPortfolioRequest_t* getPortfolioRequest,
            const axutil_env_t *env,
            axiom_node_t* getPortfolioRequest_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_getPortfolioRequest_deserialize(
            axis2_getPortfolioRequest_t* getPortfolioRequest,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for userid.
         */
        axis2_char_t* AXIS2_CALL
        axis2_getPortfolioRequest_get_userid(
            axis2_getPortfolioRequest_t* getPortfolioRequest,
            const axutil_env_t *env);

        /**
         * setter for userid
         */
        axis2_status_t AXIS2_CALL
        axis2_getPortfolioRequest_set_userid(
            axis2_getPortfolioRequest_t* getPortfolioRequest,
            const axutil_env_t *env,
            axis2_char_t*  param_userid);

        

        /**
         * getter for password.
         */
        axis2_char_t* AXIS2_CALL
        axis2_getPortfolioRequest_get_password(
            axis2_getPortfolioRequest_t* getPortfolioRequest,
            const axutil_env_t *env);

        /**
         * setter for password
         */
        axis2_status_t AXIS2_CALL
        axis2_getPortfolioRequest_set_password(
            axis2_getPortfolioRequest_t* getPortfolioRequest,
            const axutil_env_t *env,
            axis2_char_t*  param_password);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_GETPORTFOLIOREQUEST_H */
    

