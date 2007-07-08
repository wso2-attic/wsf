/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AXIOM_DATA_SOURCE_H
#define AXIOM_DATA_SOURCE_H

/**
 * @file axiom_data_source.h
 * @brief Axis2 AXIOM XML data_source
 */

#include <axutil_env.h>
#include <axiom_node.h>
#include <axiom_output.h>
#include <axutil_stream.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axiom_data_source data_source
     * @ingroup axiom_om
     * @{
     */


    /**
      * \brief data_source struct
      * Handles the XML data_source in OM
      */
    typedef struct axiom_data_source axiom_data_source_t;


    /**
      * Creates a new data_source struct
      * @param env Environment. MUST  NOT be NULL, .
      * @param parent parent of the new node. Optinal, can be NULL. 
      *          The parent element must be of type AXIOM_ELEMENT
      * @param value Text value. Optinal, can be NULL.
      * @param comment_node This is an out parameter.  cannot be NULL.
      *                       Returns the node corresponding to the data_source struct created.
      *                       Node type will be set to AXIOM_DATA_SOURCE  
      * @return pointer to newly created data_source struct 
      */
    AXIS2_EXTERN axiom_data_source_t * AXIS2_CALL
    axiom_data_source_create(const axutil_env_t *env,
            axiom_node_t *parent,
            axiom_node_t ** node);

    /**
      * Free an axiom_data_source struct
      * @param env environment.  MUST NOT be NULL.
      * @param om_data_source pointer to om data_source struct to be freed.
      * @return satus of the op. AXIS2_SUCCESS on success
      *         AXIS2_FAILURE on error.
      */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_data_source_free(struct axiom_data_source *om_data_source,
            const axutil_env_t *env);

    /**
      * Serialize op
      * @param env environment.  MUST NOT be NULL.
      * @param om_data_source pointer to om data_source struct to be serialized.
      * @param om_output AXIOM output handler to be used in serializing.
      * @return satus of the op. AXIS2_SUCCESS on success,
      *            AXIS2_FAILURE on error
      */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_data_source_serialize(struct axiom_data_source *om_data_source,
            const axutil_env_t *env,
            axiom_output_t *om_output);
    /**
     *  set the data_source value
     * @param om_data_source om_data_source struct
     * @param env environment , MUST NOT be NULL.
     * @param value data_source 
     * @return status of the op. AXIS2_SUCCESS on success,
     *           AXIS2_FAILURE on error.   
     */
    AXIS2_EXTERN axutil_stream_t * AXIS2_CALL
    axiom_data_source_get_stream(struct axiom_data_source *om_data_source,
            const axutil_env_t *env);


    /** @} */

#ifdef __cplusplus
}
#endif

#endif                          /* AXIOM_DATA_SOURCE_H */
