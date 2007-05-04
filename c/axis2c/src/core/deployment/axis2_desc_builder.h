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

#ifndef AXIS2_DESC_BUILDER_H
#define AXIS2_DESC_BUILDER_H

/** @defgroup axis2_desc_builder Description Builder
 * @ingroup axis2_deployment
 * @{
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include "axis2_deployment.h"
#include "axis2_dep_engine.h"
#include <axis2_flow.h>
#include <axiom_stax_builder.h>
#include <axiom_document.h>
#include <axiom_element.h>
#include <axiom_node.h>
#include <axutil_param_container.h>
#include <axis2_handler_desc.h>
#include <axiom_attribute.h>
#include <axiom_xml_reader.h>
#include <axis2_handler_desc.h>
#include <axis2_op.h>
#include <axiom_children_with_specific_attribute_iterator.h>
#include <axis2_phase.h>
#include <axutil_dll_desc.h>


#ifdef __cplusplus
extern "C"
{
#endif

    struct axis2_flow;
    struct axis2_phase;
    struct axis2_dep_engine;

    /** Type name for struct axis2_desc_builder */
    typedef struct axis2_desc_builder axis2_desc_builder_t;

    /** 
     * De-allocate memory
     * @param desc_builder pointer to desc builder
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_desc_builder_free(axis2_desc_builder_t *desc_builder,
        const axutil_env_t *env);

    /**
     * This will creat OMElemnt for a given descrition document (axis2.xml , 
     * services.xml and module.xml)
     * @param desc_builder pointer to desc builder
     * @param env pointer to environment struct
     * @return OMElement <code>OMElement</code>
     */
    AXIS2_EXTERN axiom_node_t *AXIS2_CALL
    axis2_desc_builder_build_om(axis2_desc_builder_t *desc_builder,
        const axutil_env_t *env);

    /**
     * To process Flow elements in services.xml
     * @param desc_builder pointer to desc builder
     * @param env pointer to environment struct
     * @param flow_element <code>axiom_element_t</code>
     * @param parent pointer to parent
     * @param node pointer to node
     * @return flow
     */
    AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
    axis2_desc_builder_process_flow(axis2_desc_builder_t *desc_builder,
        const axutil_env_t *env,
        axiom_element_t *flow_element,
        axutil_param_container_t *parent,
        axiom_node_t *node);

    /**
     * To process Handler element
     * @param handler_element    <code>OMElement</code>
     * @param desc_builder pointer to desc builder
     * @param env pointer to environment struct
     * @param handler_element pointer to handler element
     * @param parent pointer to parent
     */
    AXIS2_EXTERN axis2_handler_desc_t *AXIS2_CALL
    axis2_desc_builder_process_handler(axis2_desc_builder_t *desc_builder,
        const axutil_env_t *env,
        axiom_node_t *handler_element,
        axutil_param_container_t *parent);

    /**
     * To get the Param out from the OM
     * @param desc_builder pointer to desc builder
     * @param env pointer to environment struct
     * @param params <code>axutil_param_t</code>
     * @param param_container <code>axutil_param_container_t</code>
     * @param parent <code>axutil_param_container_t</code>
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_desc_builder_process_params(axis2_desc_builder_t *desc_builder,
        const axutil_env_t *env,
        axiom_children_qname_iterator_t *params,
        axutil_param_container_t *param_container,
        axutil_param_container_t *parent );

    /**
     * @param desc_builder pointer to desc builder
     * @param env pointer to environment struct
     * @param module_refs pointer to module refs
     * @param op pointer to op
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_desc_builder_process_op_module_refs(axis2_desc_builder_t *desc_builder,
        const axutil_env_t *env,
        axiom_children_qname_iterator_t *module_refs,
        axis2_op_t *op);

    /**
     * @param desc_builder pointer to desc builder
     * @param env pointer to environment struct
     * @param recv_element pointer to recv element
     */
    AXIS2_EXTERN axis2_msg_recv_t *AXIS2_CALL
    axis2_desc_builder_load_msg_recv(axis2_desc_builder_t *desc_builder,
        const axutil_env_t *env,
        axiom_element_t *recv_element);

    /**
     * This method is used to retrive service name form the arechive file name
     * if the archive file name is service1.aar , then axis service name would be service1
     * @param desc_builder pointer to desc builder
     * @param env pointer to environment struct
     * @param file_name pointer to file name
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_desc_builder_get_short_file_name(const axis2_desc_builder_t *desc_builder,
        const axutil_env_t *env,
        axis2_char_t *file_name);

    /**
     * @param desc_builder pointer to desc builder
     * @param env pointer to environment struct
     * @param short_file_name pointer to short file name
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_desc_builder_get_file_name_without_prefix(const axis2_desc_builder_t *desc_builder,
        const axutil_env_t *env,
        axis2_char_t *short_file_name);

    /**
     * this method is to get the value of attribue
     * eg xsd:anyVal --> anyVal
     * @param desc_builder pointer to desc builder
     * @param env pointer to environment struct
     * @param in pointer to in
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_desc_builder_get_value(const axis2_desc_builder_t *desc_builder,
        const axutil_env_t *env,
        axis2_char_t *in);

    /**
     * Populate the Axis2 Operation with details from the actionMapping,
     * outputActionMapping and faultActionMapping elements from the operation
     * element.
     * @param operation
     * @param op_desc
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_desc_builder_process_action_mappings(axis2_desc_builder_t *desc_builder,
        const axutil_env_t *env,
        axiom_node_t *op_node,
        axis2_op_t *op_desc);

    /**
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN struct axis2_msg_recv *AXIS2_CALL
    axis2_desc_builder_load_default_msg_recv(const axutil_env_t *env);

    AXIS2_EXTERN struct axis2_dep_engine *AXIS2_CALL
    axis2_desc_builder_get_dep_engine(const axis2_desc_builder_t *desc_builder,
        const axutil_env_t *env);

    /**
     * Creates description builder struct
     * @param env pointer to environment struct
     * @return pointer to newly created description builder
     */
    AXIS2_EXTERN axis2_desc_builder_t *AXIS2_CALL
    axis2_desc_builder_create(const axutil_env_t *env);

    /**
     * Creates description builder struct
     * @param env pointer to environment struct
     * @param engine pointer to engine
     * @return pointer to newly created description builder
     */
    AXIS2_EXTERN axis2_desc_builder_t *AXIS2_CALL
    axis2_desc_builder_create_with_dep_engine(const axutil_env_t *env,
        struct axis2_dep_engine *engine);
    /**
     * Creates description builder struct
     * @param env pointer to environment struct
     * @param file_name pointer to file name
     * @param engine pointer to engine
     * @return pointer to newly created description builder
     */
    AXIS2_EXTERN axis2_desc_builder_t *AXIS2_CALL
    axis2_desc_builder_create_with_file_and_dep_engine(const axutil_env_t *env,
        axis2_char_t *file_name,
        struct axis2_dep_engine *engine);

/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_DESC_BUILDER_H */
