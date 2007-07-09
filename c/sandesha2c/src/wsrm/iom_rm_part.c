/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
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
 #include <sandesha2_iom_rm_part.h>


axis2_status_t AXIS2_CALL
sandesha2_iom_rm_part_free(
    sandesha2_iom_rm_part_t *part,
    const axutil_env_t *env)
{
    return ((part)->element.ops->free ((sandesha2_iom_rm_element_t *) part, env));
}
    
axis2_status_t AXIS2_CALL
sandesha2_iom_rm_part_to_soap_envelope( 
    sandesha2_iom_rm_part_t *part,
    const axutil_env_t *env, 
    axiom_soap_envelope_t *envelope)
{
    return ((sandesha2_iom_rm_part_t*)(part))->ops->to_soap_env(
        (sandesha2_iom_rm_part_t*)part, env, envelope);
}

