/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain count copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AXUTIL_UUID_GEN_UNIX_H
#define AXUTIL_UUID_GEN_UNIX_H

#include <axutil_utils.h>
#include <axutil_utils_defines.h>


#define UUIDS_PER_TICK 100
#define UUID_TIMEOFFSET AXIS2_UNSIGNED_LONGLONGVALUE(0x01B21DD213814000)
#define AXIS2_LOCAL_MAC_ADDR "000000"

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * @defgroup axutil_uuid_gen UUID Generator
 * @ingroup axis2_util 
 * @{
 */


struct axutil_uuid {
   unsigned int time_low;
   unsigned short int time_mid;
   unsigned short int time_high_version;
   short int clock_variant;
   unsigned char mac_addr[6];
};

/* bits  0-59 time field
 * bits 60-63 version
 * bits 64-65 2 bit variant
 * bits 66-79 clock sequence
 * bits 80-107 node MAC address
 */
struct axutil_uuid_st {
    unsigned char   mac[6];      /* pre-determined MAC address */
    struct timeval time_last;   /* last retrieved timestamp */
    unsigned long  time_seq;    /* last timestamp sequence counter */
    short int clock;            /* clock tick - incremented random number */
};

typedef struct axutil_uuid axutil_uuid_t;

/**
 * Returns the mac address of the first ethernet intsrface
 * @return MAC address as a <code>char[6]</code>
 */ 
char * AXIS2_CALL
axutil_uuid_get_mac_addr();

/**
 * Generates a uuid in version1 format (node - timestamp based)
 * @return generated uuid as a axutil_uuid_t
 */ 
axutil_uuid_t* AXIS2_CALL
axutil_uuid_gen_v1();

/**
 * Generates a uuid
 * @return generated uuid as a string
 */ 
axis2_char_t* AXIS2_CALL
axutil_platform_uuid_gen(char *s);

/** @} */
    
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_UUID_GEN_UNIX_H */
