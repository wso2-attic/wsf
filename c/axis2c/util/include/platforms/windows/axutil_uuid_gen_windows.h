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

#ifndef AXIS2_UDDI_GEN_WINDOWS_H
#define AXIS2_UDDI_GEN_WINDOWS_H

#include <axutil_utils_defines.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* Function prototypes */

/**
  * Generate universally unique id
  * @return a char pointer to uuid
  */
AXIS2_EXTERN axis2_char_t* AXIS2_CALL axutil_platform_uuid_gen(char *s);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* AXIS2_UDDI_GEN_WINDOWS_H */
