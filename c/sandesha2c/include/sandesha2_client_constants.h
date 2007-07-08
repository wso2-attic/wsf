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
 
#ifndef SANDESHA2_CLIENT_CONSTANTS_H
#define SANDESHA2_CLIENT_CONSTANTS_H

/**
 * @file sandesha2_client_constants.h
 * @brief Axis2 Xml Sandesha Constants
 */
 
#include <axutil_utils.h>

#ifdef __cplusplus
extern "C" 
{
#endif
    
/** @defgroup sandesha2_client_constants 
  * @ingroup sandesha2_client
  * @{
  */
/*********************************** Constansts********************************/
#define SANDESHA2_CLIENT_ACKS_TO "Sandesha2AcksTo"
#define SANDESHA2_CLIENT_LAST_MESSAGE "Sandesha2LastMessage"
#define SANDESHA2_CLIENT_OFFERED_SEQ_ID "Sandesha2OfferedSequenceId"
#define SANDESHA2_CLIENT_DEBUG_MODE "Sandesha2DebugMode"
#define SANDESHA2_CLIENT_SEQ_KEY "Sandesha2SequenceKey"
#define SANDESHA2_CLIENT_MESSAGE_NUMBER "Sandesha2MessageNumber"
#define SANDESHA2_CLIENT_RM_SPEC_VERSION "Sandesha2RMSpecVersion"
#define SANDESHA2_CLIENT_DUMMY_MESSAGE "Sandesha2DummyMessage" /* If this 
 property is set, even though this message will invoke the RM handlers, 
 this will not be sent as an actual application message
 */
#define SANDESHA2_CLIENT_LISTENER "Sandesha2Listener"



/*********************************** Constants*********************************/   
   
   
#ifdef __cplusplus
}
#endif

#endif /* SANDESHA2_CLIENT_CONSTANTS_H */


