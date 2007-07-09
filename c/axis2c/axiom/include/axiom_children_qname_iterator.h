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

#ifndef AXIOM_CHILDREN_QNAME_ITERATOR_H
#define AXIOM_CHILDREN_QNAME_ITERATOR_H

/**
 *@file axiom_children_qname_iterator.h
 *@brief this is the iterator for om nodes using qname
 */

#include <axiom_node.h>
#include <axiom_namespace.h>
#include <axutil_qname.h>


#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axiom_children_qname_iterator axiom_children_qname_iterator_t;

    /**
     * @defgroup axiom_children_qname_iterator children qname iterator
     * @ingroup axiom_om
     * @{
     */

    AXIS2_EXTERN axiom_children_qname_iterator_t * AXIS2_CALL
    axiom_children_qname_iterator_create(const axutil_env_t *env,
            axiom_node_t *current_child,
            axutil_qname_t *given_qname);

    /**
     * free om_children_qname_iterator struct 
     */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_children_qname_iterator_free(axiom_children_qname_iterator_t *iterator,
            const axutil_env_t *env);

    /**
     * Removes from the underlying collection the last element returned by the
     * iterator (optional operation).  This method can be called only once per
     * call to <tt>next</tt>.  The behavior of an iterator is unspecified if
     * the underlying collection is modified while the iteration is in
     * progress in any way other than by calling this method.
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_children_qname_iterator_remove(axiom_children_qname_iterator_t *iterator,
            const axutil_env_t *env);

    /**
     * Returns <tt>true</tt> if the iteration has more elements. (In other
     * words, returns <tt>true</tt> if <tt>next</tt> would return an 
     * axiom_node_t struct rather than null with error code set in environment
     */

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_children_qname_iterator_has_next(axiom_children_qname_iterator_t *iterator,
            const axutil_env_t *env);

    /**
     * Returns the next element in the iteration.
     */
    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    axiom_children_qname_iterator_next(axiom_children_qname_iterator_t *iterator,
            const axutil_env_t *env);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif /* AXIOM_CHILDREN_QNAME_ITERATOR_H */
