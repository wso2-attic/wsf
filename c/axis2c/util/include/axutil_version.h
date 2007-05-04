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

#ifndef AXUTIL_VERSION_H
#define AXUTIL_VERSION_H

/* The numeric compile-time version constants. These constants are the
 * authoritative version numbers for AXIS2. 
 */

/** major version 
 * Major API changes that could cause compatibility problems for older
 * programs such as structure size changes.  No binary compatibility is
 * possible across a change in the major version.
 */
#define AXIS2_MAJOR_VERSION       1

/** minor version
 * Minor API changes that do not cause binary compatibility problems.
 * Reset to 0 when upgrading AXIS2_MAJOR_VERSION
 */
#define AXIS2_MINOR_VERSION       0

/** patch level 
 * The Patch Level never includes API changes, simply bug fixes.
 * Reset to 0 when upgrading AXIS2_MINOR_VERSION
 */
#define AXIS2_PATCH_VERSION       0

/** 
 * The symbol AXIS2_IS_DEV_VERSION is only defined for internal,
 * "development" copies of AXIS2.  It is undefined for released versions
 * of AXIS2.
 */
#undef AXIS2_IS_DEV_VERSION


#if defined(AXIS2_IS_DEV_VERSION) || defined(DOXYGEN)
/** Internal: string form of the "is dev" flag */
#define AXIS2_IS_DEV_STRING "-dev"
#else
#define AXIS2_IS_DEV_STRING ""
#endif

/** Properly quote a value as a string in the C preprocessor */
#define AXIS2_STRINGIFY(n) AXIS2_STRINGIFY_HELPER(n)
/** Helper macro for AXIS2_STRINGIFY */
#define AXIS2_STRINGIFY_HELPER(n) #n

/** The formatted string of AXIS2's version */
#define AXIS2_VERSION_STRING \
     AXIS2_STRINGIFY(AXIS2_MAJOR_VERSION) "." \
     AXIS2_STRINGIFY(AXIS2_MINOR_VERSION) "." \
     AXIS2_STRINGIFY(AXIS2_PATCH_VERSION) \
     AXIS2_IS_DEV_STRING

/** An alternative formatted string of AXIS2's version */
/* macro for Win32 .rc files using numeric csv representation */
#define AXIS2_VERSION_STRING_CSV AXIS2_MAJOR_VERSION ##, \
                             ##AXIS2_MINOR_VERSION ##, \
                             ##AXIS2_PATCH_VERSION


#ifndef AXIS2_VERSION_ONLY

/* The C language API to access the version at run time, 
 * as opposed to compile time.  AXIS2_VERSION_ONLY may be defined 
 * externally when preprocessing axutil_version.h to obtain strictly 
 * the C Preprocessor macro declarations.
 */

#include "axutil_env.h"

#ifdef __cplusplus
extern "C" {
#endif

/** 
 * The numeric version information is broken out into fields within this 
 * structure. 
 */
typedef struct {
    int major;      /**< major number */
    int minor;      /**< minor number */
    int patch;      /**< patch number */
    int is_dev;     /**< is development (1 or 0) */
} axis2_version_t;

/**
 * Return AXIS2's version information information in a numeric form.
 *
 *  @param pvsn Pointer to a version structure for returning the version
 *              information.
 */
AXIS2_EXTERN void AXIS2_CALL 
axis2_version(axis2_version_t *pvsn);

/** Return AXIS2's version information as a string. */
AXIS2_EXTERN const char *AXIS2_CALL 
axis2_version_string(void);

#ifdef __cplusplus
}
#endif
#endif

#endif                          /* AXIS2_VERSION_H */

