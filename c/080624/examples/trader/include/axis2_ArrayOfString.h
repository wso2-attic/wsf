

        #ifndef AXIS2_ARRAYOFSTRING_H
        #define AXIS2_ARRAYOFSTRING_H

        /**
        * axis2_ArrayOfString.h
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
        *  axis2_ArrayOfString class class
        */
        typedef struct axis2_ArrayOfString axis2_ArrayOfString_t;

        AXIS2_EXTERN axis2_ArrayOfString_t* AXIS2_CALL
        axis2_ArrayOfString_create(
            const axutil_env_t *env );

        axis2_status_t AXIS2_CALL
        axis2_ArrayOfString_free (
            axis2_ArrayOfString_t* ArrayOfString,
            const axutil_env_t *env);

        

        axiom_node_t* AXIS2_CALL
        axis2_ArrayOfString_serialize(
            axis2_ArrayOfString_t* ArrayOfString,
            const axutil_env_t *env,
            axiom_node_t* ArrayOfString_om_node, int has_parent);

        axis2_status_t AXIS2_CALL
        axis2_ArrayOfString_deserialize(
            axis2_ArrayOfString_t* ArrayOfString,
            const axutil_env_t *env, axiom_node_t* parent);

        

        /**
         * getter for value.
         */
        axutil_array_list_t* AXIS2_CALL
        axis2_ArrayOfString_get_value(
            axis2_ArrayOfString_t* ArrayOfString,
            const axutil_env_t *env);

        /**
         * setter for value
         */
        axis2_status_t AXIS2_CALL
        axis2_ArrayOfString_set_value(
            axis2_ArrayOfString_t* ArrayOfString,
            const axutil_env_t *env,
            axutil_array_list_t*  param_value);

        
        /**
        * resetter for value
        */
        axis2_status_t AXIS2_CALL
        axis2_ArrayOfString_reset_value(
            axis2_ArrayOfString_t* ArrayOfString,
            const axutil_env_t *env);
        

     #ifdef __cplusplus
     }
     #endif

     #endif /* AXIS2_ARRAYOFSTRING_H */
    

