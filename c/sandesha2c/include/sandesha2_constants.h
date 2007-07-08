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
 
#ifndef SANDESHA2_CONSTANTS_H
#define SANDESHA2_CONSTANTS_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @defgroup sandesha2_constants
 * @ingroup Sandesha2 Constants
 * @{
 */
	/**
	 * WSRM Spec versions
	 */
	#define SANDESHA2_SPEC_VERSION_1_0 "Spec_2005_02"
	#define SANDESHA2_SPEC_VERSION_1_1 "Spec_2006_08"
	
	/**
	 * Spec 2005-02
	 */
	#define SANDESHA2_SPEC_2005_02_NS_URI "http://schemas.xmlsoap.org/ws/2005/02/rm"
		
	#define SANDESHA2_SPEC_2005_02_ACTION_CREATE_SEQ "http://schemas.xmlsoap.org/ws/2005/02/rm/CreateSequence"

	#define SANDESHA2_SPEC_2005_02_ACTION_CREATE_SEQ_RESPONSE  "http://schemas.xmlsoap.org/ws/2005/02/rm/CreateSequenceResponse"

	#define SANDESHA2_SPEC_2005_02_ACTION_SEQ_ACKNOWLEDGEMENT  "http://schemas.xmlsoap.org/ws/2005/02/rm/SequenceAcknowledgement"

	#define SANDESHA2_SPEC_2005_02_ACTION_TERMINATE_SEQ  "http://schemas.xmlsoap.org/ws/2005/02/rm/TerminateSequence"

	#define SANDESHA2_SPEC_2005_02_ACTION_LAST_MESSAGE  "http://schemas.xmlsoap.org/ws/2005/02/rm/LastMessage"

	#define SANDESHA2_SPEC_2005_02_SOAP_ACTION_CREATE_SEQ  "http://schemas.xmlsoap.org/ws/2005/02/rm/CreateSequence"

	#define SANDESHA2_SPEC_2005_02_SOAP_ACTION_CREATE_SEQ_RESPONSE  "http://schemas.xmlsoap.org/ws/2005/02/rm/CreateSequenceResponse"

	#define SANDESHA2_SPEC_2005_02_SOAP_ACTION_SEQ_ACKNOWLEDGEMENT  "http://schemas.xmlsoap.org/ws/2005/02/rm/SequenceAcknowledgement"

	#define SANDESHA2_SPEC_2005_02_SOAP_ACTION_TERMINATE_SEQ  "http://schemas.xmlsoap.org/ws/2005/02/rm/TerminateSequence"

	#define SANDESHA2_SPEC_2005_02_SOAP_ACTION_LAST_MESSAGE  "http://schemas.xmlsoap.org/ws/2005/02/rm/LastMessage"
	
	/**
	 * Spec 2005-10
	 */
			
	#define SANDESHA2_SPEC_2006_08_NS_URI  "http://docs.oasis-open.org/ws-rx/wsrm/200608"
		
	#define SANDESHA2_SPEC_2006_08_ACTION_CREATE_SEQ  "http://docs.oasis-open.org/ws-rx/wsrm/200608/CreateSequence"

	#define SANDESHA2_SPEC_2006_08_ACTION_CREATE_SEQ_RESPONSE  "http://docs.oasis-open.org/ws-rx/wsrm/200608/CreateSequenceResponse"

	#define SANDESHA2_SPEC_2006_08_ACTION_SEQ_ACKNOWLEDGEMENT  "http://docs.oasis-open.org/ws-rx/wsrm/200608/SequenceAcknowledgement"

	#define SANDESHA2_SPEC_2006_08_ACTION_TERMINATE_SEQ  "http://docs.oasis-open.org/ws-rx/wsrm/200608/TerminateSequence"
			
	#define SANDESHA2_SPEC_2006_08_ACTION_TERMINATE_SEQ_RESPONSE  "http://docs.oasis-open.org/ws-rx/wsrm/200608/TerminateSequenceResponse"
			
	#define SANDESHA2_SPEC_2006_08_ACTION_ACK_REQUEST  "http://docs.oasis-open.org/ws-rx/wsrm/200608/AckRequested"
			
	#define SANDESHA2_SPEC_2006_08_ACTION_CLOSE_SEQ  "http://docs.oasis-open.org/ws-rx/wsrm/200608/CloseSequence"
			
	#define SANDESHA2_SPEC_2006_08_ACTION_CLOSE_SEQ_RESPONSE  "http://docs.oasis-open.org/ws-rx/wsrm/200608/CloseSequenceResponse"
	#define SANDESHA2_SPEC_2006_08_ACTION_MAKE_CONNECTION "http://docs.oasis-open.org/ws-rx/wsrm/200608/MakeConnection"

	#define SANDESHA2_SPEC_2006_08_SOAP_ACTION_CREATE_SEQ  "http://docs.oasis-open.org/ws-rx/wsrm/200608/CreateSequence"

	#define SANDESHA2_SPEC_2006_08_SOAP_ACTION_CREATE_SEQ_RESPONSE  "http://docs.oasis-open.org/ws-rx/wsrm/200608/CreateSequenceResponse"

	#define SANDESHA2_SPEC_2006_08_SOAP_ACTION_SEQ_ACKNOWLEDGEMENT  "http://docs.oasis-open.org/ws-rx/wsrm/200608/SequenceAcknowledgement"

	#define SANDESHA2_SPEC_2006_08_SOAP_ACTION_TERMINATE_SEQ  "http://docs.oasis-open.org/ws-rx/wsrm/200608/TerminateSequence"
			
	#define SANDESHA2_SPEC_2006_08_SOAP_ACTION_TERMINATE_SEQ_RESPONSE  "http://docs.oasis-open.org/ws-rx/wsrm/200608/TerminateSequenceResponse"
			
	#define SANDESHA2_SPEC_2006_08_SOAP_ACTION_ACK_REQUEST  "http://docs.oasis-open.org/ws-rx/wsrm/200608/AckRequested"
			
	#define SANDESHA2_SPEC_2006_08_SOAP_ACTION_CLOSE_SEQ  "http://docs.oasis-open.org/ws-rx/wsrm/200608/CloseSequence"
     
    #define SANDESHA2_SPEC_2006_08_SOAP_ACTION_MAKE_CONNECTION "http://docs.oasis-open.org/ws-rx/wsrm/200608/MakeConnection"
	/**
	 * WSRM Common constants
	 */

	#define SANDESHA2_WSRM_COMMON_NS_PREFIX_RM  "wsrm"

	#define SANDESHA2_WSRM_COMMON_MSG_NUMBER  "MessageNumber"

	#define SANDESHA2_WSRM_COMMON_LAST_MSG  "LastMessage"

	#define SANDESHA2_WSRM_COMMON_SEQ  "Sequence"

	#define SANDESHA2_WSRM_COMMON_SEQ_OFFER  "Offer"

	#define SANDESHA2_WSRM_COMMON_TERMINATE_SEQ  "TerminateSequence"

	#define SANDESHA2_WSRM_COMMON_CLOSE_SEQ  "CloseSequence"
		
	#define SANDESHA2_WSRM_COMMON_CLOSE_SEQ_RESPONSE  "CloseSequenceResponse"
		
	#define SANDESHA2_WSRM_COMMON_TERMINATE_SEQ_RESPONSE  "TerminateSequenceResponse"
		
	#define SANDESHA2_WSRM_COMMON_FAULT_CODE  "FaultCode"

	#define SANDESHA2_WSRM_COMMON_SEQ_FAULT  "SequenceFault"

	#define SANDESHA2_WSRM_COMMON_ACKS_TO  "AcksTo"

	#define SANDESHA2_WSRM_COMMON_EXPIRES  "Expires"

	#define SANDESHA2_WSRM_COMMON_CREATE_SEQ  "CreateSequence"

	#define SANDESHA2_WSRM_COMMON_CREATE_SEQ_RESPONSE  "CreateSequenceResponse"

	#define SANDESHA2_WSRM_COMMON_ACK_REQUESTED  "AckRequested"

	#define SANDESHA2_WSRM_COMMON_ACK_RANGE  "AcknowledgementRange"

	#define SANDESHA2_WSRM_COMMON_UPPER  "Upper"

	#define SANDESHA2_WSRM_COMMON_LOWER  "Lower"

	#define SANDESHA2_WSRM_COMMON_NACK  "Nack"

	#define SANDESHA2_WSRM_COMMON_SEQ_ACK  "SequenceAcknowledgement"

	#define SANDESHA2_WSRM_COMMON_IDENTIFIER  "Identifier"

	#define SANDESHA2_WSRM_COMMON_ACCEPT  "Accept"
		
	#define SANDESHA2_WSRM_COMMON_NONE  "None"
		
	#define SANDESHA2_WSRM_COMMON_FINAL  "Final"

    #define SANDESHA2_WSRM_COMMON_MESSAGE_PENDING "MessagePending"
    #define SANDESHA2_WSRM_COMMON_PENDING "pending"
    #define SANDESHA2_WSRM_COMMON_MAKE_CONNECTION "MakeConnection"
    
    /* Message Context Properties */
    #define SANDESHA2_MSG_CTX_PROP_INTERNAL_SEQUENCE_ID "Sandesha2InternalSequenceId"
    #define SANDESHA2_MSG_CTX_PROP_SEQUENCE_ID "WSRMSequenceId"
    #define SANDESHA2_MSG_CTX_PROP_MESSAGE_NUMBER "WSRMMessageNumber"
    #define SANDESHA2_MSG_CTX_PROP_SEQUENCE_PROPERTY_KEY "SequencePropertyKey"

	/**
	 * WS Addressing constants
	 */
	#define SANDESHA2_WSA_NS_PREFIX_ADDRESSING  "wsa"

	#define SANDESHA2_WSA_ADDRESS  "Address"

	#define SANDESHA2_WSA_SOAP_FAULT_ACTION  "http://schemas.xmlsoap.org/ws/2004/08/addressing/fault"

	enum sandesha2_message_types 
	{
		SANDESHA2_MSG_TYPE_UNKNOWN = 0,
		SANDESHA2_MSG_TYPE_CREATE_SEQ, /* 1 */
		SANDESHA2_MSG_TYPE_CREATE_SEQ_RESPONSE, /* 2 */
		SANDESHA2_MSG_TYPE_APPLICATION, /* 3 */
		SANDESHA2_MSG_TYPE_ACK, /* 4 */
		SANDESHA2_MSG_TYPE_CLOSE_SEQ, /* 5 */
		SANDESHA2_MSG_TYPE_CLOSE_SEQ_RESPONSE, /* 6 */
		SANDESHA2_MSG_TYPE_TERMINATE_SEQ, /* 7 */
		SANDESHA2_MSG_TYPE_ACK_REQUEST, /* 8 */
		SANDESHA2_MSG_TYPE_TERMINATE_SEQ_RESPONSE, /* 9 */
		SANDESHA2_MSG_TYPE_FAULT_MSG, /* 10 */
		SANDESHA2_MSG_TYPE_MAX_MESSAGE_TYPE, /* 11 */
        SANDESHA2_MSG_TYPE_MAKE_CONNECTION_MSG /* 12 */
	};

	enum sandesha2_message_parts 
	{
		SANDESHA2_MSG_PART_UNKNOWN = 0,
		SANDESHA2_MSG_PART_SEQ,
		SANDESHA2_MSG_PART_SEQ_ACKNOWLEDGEMENT,
		SANDESHA2_MSG_PART_ADDR_HEADERS,
		SANDESHA2_MSG_PART_CREATE_SEQ,
		SANDESHA2_MSG_PART_CREATE_SEQ_RESPONSE,
		SANDESHA2_MSG_PART_TERMINATE_SEQ,
		SANDESHA2_MSG_PART_CLOSE_SEQ,
		SANDESHA2_MSG_PART_CLOSE_SEQ_RESPONSE,
		SANDESHA2_MSG_PART_TERMINATE_SEQ_RESPONSE,
		SANDESHA2_MSG_PART_ACK_REQUEST,
        SANDESHA2_MSG_PART_USES_SEQ_STR,
		SANDESHA2_MSG_PART_MAKE_CONNECTION,
		SANDESHA2_MSG_PART_MESSAGE_PENDING,
		SANDESHA2_MSG_PART_MAX_MSG_PART_ID
	};

	/**
	 * Sequence Properties
	 */		
	#define SANDESHA2_SEQ_PROP_RM_SPEC_VERSION  "WSRMSpecVersion"

	/* This is not a seq property. This is used as the
	 * seqId to share data b/w seqs
	 */
	#define SANDESHA2_SEQ_PROP_ALL_SEQS  "AllSequences"
		
	/* Addressing version of a seq. All messages of a seq should 
	 * have this addressing version
	 */
	#define SANDESHA2_SEQ_PROP_ADDRESSING_NAMESPACE_VALUE  "AddressingNamespaceValue"

	/* For incoming seqs this gives the msg no's of the messages that were
	 * received (may be an ack was sent - depending on the policy)
	 * For out going seqs this gives the messages that were sent and that 
	 * were successfully acked by the other end point.
	 */
	#define SANDESHA2_SEQ_PROP_CLIENT_COMPLETED_MESSAGES  "ClientCompletedMessages"
	
	#define SANDESHA2_SEQ_PROP_SERVER_COMPLETED_MESSAGES  "ServerCompletedMessages"
		
	#define SANDESHA2_SEQ_PROP_TO_EPR  "ToEPR"

	#define SANDESHA2_SEQ_PROP_ACKS_TO_EPR  "acksToEPR"

	#define SANDESHA2_SEQ_PROP_OUT_SEQ_ID  "OutSequenceId"

	#define SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID  "TempSequenceId"

	#define SANDESHA2_SEQ_PROP_REPLY_TO_EPR  "ReplyToEPR"

	#define SANDESHA2_SEQ_PROP_APP_MSG_PROCESSOR_LIST  "AppMsgProcessorList"

	#define SANDESHA2_SEQ_PROP_OUT_CREATE_SEQ_SENT  "OutCreateSeqSent"

	#define SANDESHA2_SEQ_PROP_NEXT_MESSAGE_NUMBER  "NextMsgNo"

	#define SANDESHA2_SEQ_PROP_INCOMING_SEQ_LIST  "IncomingSequenceList"

	#define SANDESHA2_SEQ_PROP_CHECK_RESPONSE  "CheckResponse"

	#define SANDESHA2_SEQ_PROP_OFFERED_SEQ  "OfferedSequence"

	#define SANDESHA2_SEQ_PROP_TERMINATE_ADDED  "TerminateAdded"
		
	#define SANDESHA2_SEQ_PROP_TERMINATE_RECEIVED  "TerminateReceived"
		
	#define SANDESHA2_SEQ_PROP_LAST_ACTIVATED_TIME  "LastActivatedTime"
		
	#define SANDESHA2_SEQ_PROP_NO_OF_OUTGOING_MSGS_ACKED  "NoOfOutGoingMessagesAcked"
		
	#define SANDESHA2_SEQ_PROP_TRANSPORT_TO  "TransportTo"
		
	#define SANDESHA2_SEQ_PROP_OUT_SEQ_ACKSTO  "OutSequenceAcksTo"
		
	#define SANDESHA2_SEQ_PROP_SEQ_CLOSED  "SequenceClosed"
		
	#define SANDESHA2_SEQ_PROP_SEQ_TERMINATED  "SequenceTerminated"
		
	#define SANDESHA2_SEQ_PROP_SEQ_TIMED_OUT  "SequenceTimedOut"
		
	#define SANDESHA2_SEQ_PROP_LAST_MESSAGE  "LastMessage"

	#define SANDESHA2_SEQ_PROP_REQUEST_SIDE_SEQ_ID  "RequestSideSequenceID" 		//used only at the server side
		
	#define SANDESHA2_SEQ_PROP_HIGHEST_IN_MSG_NUMBER  "HighestInMsgNumber"
		
	#define SANDESHA2_SEQ_PROP_HIGHEST_IN_MSG_KEY  "HighestInMsgKey"
		
	#define SANDESHA2_SEQ_PROP_HIGHEST_OUT_MSG_NUMBER  "HighestOutMsgNumber"

    #define SANDESHA2_SEQ_PROP_HIGHEST_OUT_RELATES_TO "HighestOutRelatesTo"
		
	#define SANDESHA2_SEQ_PROP_HIGHEST_OUT_MSG_KEY  "HighestOutMsgKey"
		
	#define SANDESHA2_SEQ_PROP_LAST_OUT_MESSAGE_NO  "LastOutMessage"
		
	#define SANDESHA2_SEQ_PROP_LAST_IN_MESSAGE_NO  "LastInMessage"
	
    #define SANDESHA2_SEQ_PROP_LAST_IN_MESSAGE_ID  "LastInMessageId"

    #define SANDESHA2_SEQ_PROP_HIGHEST_IN_MSG_ID "HighestInMsgId"
	
	/**
	 * SOAP Versions
	 */
	#define SANDESHA2_SOAP_VERSION_1_1  1

	#define SANDESHA2_SOAP_VERSION_1_2  2

	/**
	 * QOS properties
	 */
	 /* Delivery Assurance */
	#define SANDESHA2_QOS_IN_ORDER  "InOrder"

	#define SANDESHA2_QOS_NOT_IN_ORDER  "NotInOrder"

	#define SANDESHA2_QOS_DEFAULT_DELIVERY_ASSURANCE  IN_ORDER
	
	/* Invocation Types */
	#define SANDESHA2_QOS_EXACTLY_ONCE  "ExactlyOnce"

	#define SANDESHA2_QOS_MORE_THAN_ONCE  "MoreThanOnce"

	#define SANDESHA2_QOS_DEFAULT_INVOCATION_TYPE  "ExactlyOnce"

	/**
	 * Bean Maps
	 */
	#define SANDESHA2_BEAN_MAP_CREATE_SEQUENCE  "CreateSequenceBeanMap"

	#define SANDESHA2_BEAN_MAP_RETRANSMITTER  "RetransmitterBeanMap"

	#define SANDESHA2_BEAN_MAP_SEQ_PROPERTY  "SequencePropertyBeanMap"

	#define SANDESHA2_BEAN_MAP_STORAGE_MAP  "StorageMapBeanMap"

	#define SANDESHA2_BEAN_MAP_NEXT_MESSAGE  "NextMsgBeanMap"
	
	/**
	 * SOAP Faults
	 */
	/* Fault subcodes */
	#define SANDESHA2_SOAP_FAULT_SUBCODE_SEQ_TERMINATED  "wsrm:SequenceTerminated"
			
	#define SANDESHA2_SOAP_FAULT_SUBCODE_SEQ_CLOSED  "wsrm:SequenceClosed"

	#define SANDESHA2_SOAP_FAULT_SUBCODE_UNKNOWN_SEQ  "wsrm:UnknownSequence"

	#define SANDESHA2_SOAP_FAULT_SUBCODE_INVALID_ACKNOWLEDGEMENT  "wsrm:InvalidAcknowledgement"

	#define SANDESHA2_SOAP_FAULT_SUBCODE_MESSAGE_NUMBER_ROLEOVER  "wsrm:MessageNumberRollover"

	#define SANDESHA2_SOAP_FAULT_SUBCODE_LAST_MESSAGE_NO_EXCEEDED  "wsrm:LastMessageNumberExceeded"

	#define SANDESHA2_SOAP_FAULT_SUBCODE_CREATE_SEQ_REFUSED  "wsrm:CreateSequenceRefused"
	
	/* Fault Types */
	#define SANDESHA2_SOAP_FAULT_TYPE_UNKNOWN_SEQ  1

	#define SANDESHA2_SOAP_FAULT_TYPE_MESSAGE_NUMBER_ROLLOVER  2

	#define SANDESHA2_SOAP_FAULT_TYPE_INVALID_ACKNOWLEDGEMENT  3

	#define SANDESHA2_SOAP_FAULT_TYPE_CREATE_SEQ_REFUSED  4
			
	#define SANDESHA2_SOAP_FAULT_TYPE_LAST_MESSAGE_NO_EXCEEDED  5

	#define SANDESHA2_PROPERTIES_RETRANSMISSION_INTERVAL  "RetransmissionInterval"
		
	#define SANDESHA2_PROPERTIES_ACK_INTERVAL  "AcknowledgementInterval"
		
	#define SANDESHA2_PROPERTIES_EXP_BACKOFF  "ExponentialBackoff"
		
	#define SANDESHA2_PROPERTIES_INACTIVETIMEOUT  "InactivityTimeout"
		
	#define SANDESHA2_PROPERTIES_INACTIVETIMEOUT_MEASURE  "InactivityTimeoutMeasure"
		
	#define SANDESHA2_PROPERTIES_STORAGE_MGR  "StorageManager"
		
	#define SANDESHA2_PROPERTIES_IN_MEMORY_STORAGE_MGR  "InMemoryStorageManager"
		
	#define SANDESHA2_PROPERTIES_PERM_STORAGE_MGR  "PermanentStorageManager"
		
	#define SANDESHA2_PROPERTIES_INORDER_INVOCATION  "InvokeInOrder"
		
	#define SANDESHA2_PROPERTIES_MSG_TYPES_TO_DROP  "MessageTypesToDrop"
		
	#define SANDESHA2_PROPERTIES_RETR_COUNT  "RetransmissionCount"
    
    #define SANDESHA2_PROPERTIES_MAX_RETRANS_COUNT "MaxRetransCount"
	
	/**
	 * Default Values
	 */
		
	#define SANDESHA2_DEF_VAL_RETRANSMISSION_INTERVAL 20000
			
	#define SANDESHA2_DEF_VAL_ACK_INTERVAL  4000
			
	#define SANDESHA2_DEF_VAL_EXP_BACKOFF  AXIS2_TRUE
			
	#define SANDESHA2_DEF_VAL_INACTIVETIMEOUT  -1
	/*  this can be - seconds,minutes,hours,days */		
	#define SANDESHA2_DEF_VAL_INACTIVETIMEOUT_MEASURE  "seconds"   
			
	#define SANDESHA2_DEF_VAL_STORAGE_MGR  "InMemoryStorageManager"
		
	#define SANDESHA2_DEF_VAL_IN_MEMORY_STORAGE_MGR  "InMemoryStorageManager"
			
	#define SANDESHA2_DEF_VAL_PERM_STORAGE_MGR  "InMemoryStorageManager"
			
	#define SANDESHA2_DEF_VAL_INORDER_INVOCATION  AXIS2_FALSE
			
	#define SANDESHA2_DEF_VAL_MSG_TYPES_TO_DROP  "none"
			
	#define SANDESHA2_DEF_VAL_RETR_COUNT  8
			
	#define SANDESHA2_DEF_VAL_MAX_RETR_COUNT  10

	#define SANDESHA2_IN_HANDLER_NAME  "SandeshaInHandler"

	#define SANDESHA2_OUT_HANDLER_NAME  "SandeshaOutHandler"

	#define SANDESHA2_GLOBAL_IN_HANDLER_NAME  "GlobalInHandler"

	#define SANDESHA2_APPLICATION_PROCESSING_DONE  "Sandesha2AppProcessingDone"

	#define SANDESHA2_ACK_WRITTEN  "AckWritten"

	#define SANDESHA2_INVOKER_SLEEP_TIME  1  /*4 1 */

	#define SANDESHA2_SENDER_SLEEP_TIME  1  /*4 1*/

    #define SANDESHA2_POLLING_MANAGER_WAIT_TIME 3 /* 4 3 */

	#define SANDESHA2_CLIENT_SLEEP_TIME  4 /* 32 16 */

	#define SANDESHA2_TERMINATE_DELAY  4 /* In seconds */

	#define SANDESHA2_TEMP_SEQ_ID  "uuid:tempID"

	#define SANDESHA2_ACK_PROCSSED  "AckProcessed"

	#define SANDESHA2_RM_ENABLE_KEY  "RMEnabled"

	#define SANDESHA2_MAXIMUM_RETRANSMISSION_ATTEMPTS  5
	
	#define SANDESHA2_PROPERTY_FILE  "sandesha2.properties"
	
	#define SANDESHA2_VALUE_NONE  "none"
	
	#define SANDESHA2_VALUE_EMPTY  "empty"
	
	#define SANDESHA2_MESSAGE_STORE_KEY  "Sandesha2MessageStoreKey"

	#define SANDESHA2_ORIGINAL_TRANSPORT_OUT_DESC  "Sandesha2OriginalTransportSender"
	
	#define SANDESHA2_SET_SEND_TO_TRUE  "Sandesha2SetSendToTrue"
	
	#define SANDESHA2_MESSAGE_TYPE  "Sandesha2MessageType"

	/*Sender will send messages only if this property is null (not set) or true.*/
	#define SANDESHA2_QUALIFIED_FOR_SENDING  "Sandesha2QualifiedForSending"  

	#define SANDESHA2_QNAME_SEPERATOR  ","
	
	#define SANDESHA2_EXECUTIN_CHAIN_SEPERATOR  "."
	
	#define SANDESHA2_INTERNAL_SEQ_PREFIX  "Sandesha2InternalSequence"
	
	#define SANDESHA2_SANDESHA_PROPERTY_BEAN  "Sandesha2PropertyBean"
	
	#define SANDESHA2_LIST_SEPERATOR ","
	
	#define SANDESHA2_LIST_PART_SEPERATOR "-"
	
	#define SANDESHA2_INMEMORY_STORAGE_MGR  "inmemory"
	
	#define SANDESHA2_PERMANENT_STORAGE_MGR  "persistent"
	
	#define SANDESHA2_DEFAULT_STORAGE_MGR "persistent"
	
	#define SANDESHA2_SENDER  "Sender"
	
	#define SANDESHA2_INVOKER  "Invoker"

    #define  SANDESHA2_POLLING_MGR "PollingManager"
	
	#define SANDESHA2_WITHIN_TRANSACTION  "WithinTransaction"
	
	#define SANDESHA2_STORAGE_MGR_PARAMETER   "Sandesha2StorageManager"
	
	#define SANDESHA2_POST_FAILURE_MESSAGE  "PostFailureMessage"
	
	#define SANDESHA2_REINJECTED_MESSAGE  "ReinjectedMessage"
	
	#define SANDESHA2_MODULE_CLASS_LOADER  "Sandesha2ModuleClassLoader"

    #define SANDESHA2_WSRM_ANON_URI_PREFIX "http://docs.oasis-open.org/ws-rx/wsrm/200608/anonymous"

    #define AXIS2_WS_RM_ANONYMOUS_URL "http://docs.oasis-open.org/ws-rx/wsmc/200702/anonymous?id="
    
    /**
     * Message context values
     */
    #define SANDESHA2_MSG_CTX_IN_FLOW 1
    #define SANDESHA2_MSG_CTX_IN_FAULT_FLOW 2
    #define SANDESHA2_MSG_CTX_OUT_FLOW 3
    #define SANDESHA2_MSG_CTX_OUT_FAULT_FLOW 4
	

    #define SANDESHA2_IN_MESSAGE_STORAGE_KEY "InMsgStoreKey"
    #define SANDESHA2_PERSISTANT_PROPERTY_SEPERATOR ",,,"
    #define SANDESHA2_BUSY_WAIT_TIME 1
    #define SANDESHA2_IS_SVR_SIDE "is_svr_side" 
    #define SANDESHA2_DB "sandesha2_db"
    #define SANDESHA2_DB_SERVER "sandesha2_server"
    #define SANDESHA2_DB_USER "db_user"
    #define SANDESHA2_DB_PASSWORD "db_password"
	#define SANDESHA2_SENDER_SLEEP  "SenderSleepTime"
	#define SANDESHA2_INVOKER_SLEEP  "InvokerSleepTime"
	#define SANDESHA2_POLLING_WAIT  "PollingWaitTime"
/** @} */
#ifdef __cplusplus
}
#endif
 
#endif /*SANDESHA2_CONSTANTS_H*/
