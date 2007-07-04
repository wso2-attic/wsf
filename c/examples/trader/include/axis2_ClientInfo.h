

        #ifndef AXIS2_CLIENTINFO_H
        #define AXIS2_CLIENTINFO_H

        /**
        * axis2_ClientInfo.h
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
        *  axis2_ClientInfo class class
        */
        typedef struct axis2_ClientInfo axis2_ClientInfo_t;

        AXIS2_EXTERN axis2_ClientInfo_t* AXIS2_CALL
        axis2_ClientInfo_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_ClientInfo_free (
            axis2_ClientInfo_t* ClientInfo,
            const axutil_env_t *env);

        

        axiom_node_t* AXIS2_CALL
        axis2_ClientInfo_serialize(
            axis2_ClientInfo_t* ClientInfo,
            const axutil_env_t *env,
            axiom_node_t* ClientInfo_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_ClientInfo_deserialize(
            axis2_ClientInfo_t* ClientInfo,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for name.
         */
        axis2_char_t* AXIS2_CALL
        axis2_ClientInfo_get_name(
            axis2_ClientInfo_t* ClientInfo,
            const axutil_env_t *env);

        /**
         * setter for name
         */
        axis2_status_t AXIS2_CALL
        axis2_ClientInfo_set_name(
            axis2_ClientInfo_t* ClientInfo,
            const axutil_env_t *env,
            axis2_char_t*  param_name);

        

        /**
         * getter for ssn.
         */
        axis2_char_t* AXIS2_CALL
        axis2_ClientInfo_get_ssn(
            axis2_ClientInfo_t* ClientInfo,
            const axutil_env_t *env);

        /**
         * setter for ssn
         */
        axis2_status_t AXIS2_CALL
        axis2_ClientInfo_set_ssn(
            axis2_ClientInfo_t* ClientInfo,
            const axutil_env_t *env,
            axis2_char_t*  param_ssn);

        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_CLIENTINFO_H */
    

