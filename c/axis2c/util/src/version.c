/**
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

#include <axutil_version.h>

AXIS2_EXTERN void AXIS2_CALL 
axis2_version(axis2_version_t *pvsn)
{
    pvsn->major = AXIS2_MAJOR_VERSION;
    pvsn->minor = AXIS2_MINOR_VERSION;
    pvsn->patch = AXIS2_PATCH_VERSION;
#ifdef AXIS2_IS_DEV_VERSION
    pvsn->is_dev = 1;
#else
    pvsn->is_dev = 0;
#endif
}

AXIS2_EXTERN const char *AXIS2_CALL 
axis2_version_string(void)
{
    return AXIS2_VERSION_STRING;
}

