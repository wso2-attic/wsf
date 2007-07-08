/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
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
 
#ifndef SAVAN_ERROR_H
#define SAVAN_ERROR_H

#include <axutil_error.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @defgroup savan_error
 * @ingroup Savan Error
 * @{
 */
   /**
    * Since we use the same env->error from Axis2 we need to start from
    * a AXIS2_ERROR_LAST + some number to prevent ambiguity 
    */  
    #define SAVAN_ERROR_CODES_START (AXIS2_ERROR_LAST + 2000)
	/**
    * \brief Savan error codes
    *
    * Set of error codes for Savan
    */
    typedef enum savan_error_codes
    { 
        /* No error */
        SAVAN_ERROR_NONE = SAVAN_ERROR_CODES_START,
    
        /* The soap action of an eventing message was missing */    
        SAVAN_ERROR_SOAP_ACTION_NULL,
        /* Failed to create an instance of subscription processor */
        SAVAN_ERROR_FAILED_TO_CREATE_SUB_PROCESSOR,
        /* Failed to create an instance of subscriber */
        SAVAN_ERROR_FAILED_TO_CREATE_SUBSCRIBER,
        /* Cannot determinet messsage type */    
        SAVAN_ERROR_UNKNOWN_MSG_TYPE,
        /* Unhandled message type */
        SAVAN_ERROR_UNHANDLED_MSG_TYPE,
        /* Service instance could not be found */
        SAVAN_ERROR_SERVICE_NOT_FOUND,
        /* Subscriber store could not be found */
        SAVAN_ERROR_STORE_NOT_FOUND,
        /* Failed to build a default soap envelope */
        SAVAN_ERROR_FAILED_TO_BUILD_SOAP_ENV,
        
        SAVAN_ERROR_LAST
    
    } savan_error_codes_t;
        
/** @} */
#ifdef __cplusplus
}
#endif
 
#endif /*SAVAN_ERROR_H*/
