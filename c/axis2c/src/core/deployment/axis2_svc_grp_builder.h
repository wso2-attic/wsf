/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not svc_grp this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AXIS2_SVC_GRP_BUILDER_H
#define AXIS2_SVC_GRP_BUILDER_H

/** @defgroup axis2_svc_grp_builder Service Group Builder
 * @ingroup axis2_deployment
 * @{
 */

/**
 * @file axis2_svc_grp_builder.h
 * @brief Axis2 Service Group Builder interface
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_qname.h>
#include <axis2_desc_builder.h>
#include <axis2_svc_builder.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_svc_grp_builder */
    typedef struct axis2_svc_grp_builder axis2_svc_grp_builder_t;

    /** 
     * De-allocate memory
     * @param svc_grp_builder pointer to service group builder
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_svc_grp_builder_free(axis2_svc_grp_builder_t *svc_grp_builder,
        const axutil_env_t *env);
    
    /** 
     * @param grp_builder pointer to group builder
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_builder_populate_svc_grp(axis2_svc_grp_builder_t *grp_builder,
        const axutil_env_t *env,
        axis2_svc_grp_t *svc_grp);

    /**
     * To get the list og modules that is requird to be engage globally
     * @param grp_builder pointer to group builder
     * @param env pointer to environment struct
     * @param module_refs  <code>axiom_children_qname_iterator_t</code>
     * @param svc_group pointer to service group
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_builder_process_module_refs(axis2_svc_grp_builder_t *grp_builder,
        const axutil_env_t *env,
        axiom_children_qname_iterator_t *module_refs ,
                axis2_svc_grp_t *svc_grp);

    AXIS2_EXTERN axis2_desc_builder_t *AXIS2_CALL
    axis2_svc_grp_builder_get_desc_builder(const axis2_svc_grp_builder_t *svc_grp_builder,
        const axutil_env_t *env);

    /**
     * Creates svc_grp builder struct
     * @param env pointer to environment struct
     * @return pointer to newly created service group builder
     */
    AXIS2_EXTERN axis2_svc_grp_builder_t *AXIS2_CALL
    axis2_svc_grp_builder_create (const axutil_env_t *env);

    /**
     * Creates svc_grp builder struct
     * @param env pointer to environment strut
     * @param svc pointer to service
     * @param dep_engine pointer to deployment engine
     * @return pointer to newly created service group builder
     */
    AXIS2_EXTERN axis2_svc_grp_builder_t *AXIS2_CALL
    axis2_svc_grp_builder_create_with_svc_and_dep_engine(const axutil_env_t *env,
        axiom_node_t *svc,
        axis2_dep_engine_t *dep_engine);

/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_SVC_GRP_BUILDER_H */
