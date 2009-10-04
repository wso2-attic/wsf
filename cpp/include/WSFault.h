/*
 * Copyright 2005-2009 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WSFAULT_H
#define WSFAULT_H

#include <WSFDefines.h>
#include <WSFException.h>

/**
 * @file WSFault.h
 */

/**
 * @brief namespace wso2wsf namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup WSFault WS Fault
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class WSFault. This class is a derivation of the Exception Class, and
     * is used to implement exceptions generated from WSF/C++ Framework when a client 
	 * or a server error happens.
     */
    class WSFault: public Exception
    {
	
	private:
		/**
		* _detail corresponds to SOAP Fault detail string                                                   
		*/
		std::string _detail;

		/**
		* _role Corresponds to SOAP Fault role                             
		*/
		std::string _role;

		/**
		*  Initialize private variables
		*/
		void init();

    public:
        /**
         * Constructor accepting a reason for the exception.
         * @param reason reason to exception.
         */
        WSF_EXTERN WSF_CALL WSFault(char const * reason);

		/**
		* Constructor accepting a reason and a code for the exception.                                                   
		* @param reason, Reason explaining the exception or soap fault reason
		* @param code,    Exception code
		*/
		WSF_EXTERN WSF_CALL WSFault(char const* reason, char const *detail);

		/**
		* Constructor accepting a reason and a code for the exception.                                                   
		* @param reason, Reason explaining the exception.
		* @param code,   Fault code
		* @param detail  Fault Detail
		*/
		WSF_EXTERN WSF_CALL WSFault(char const *reason, char const *detail, char const* code);

		/**
		* Constructor accepting a reason and a code for the exception.                                                   
		* @param reason, Reason explaining the exception.
		* @param code,   Fault code
		* @param detail  Fault Detail
		* @param role    Role
		*/

		WSF_EXTERN WSF_CALL WSFault(char const *reason, char const *detail, char const* code, char const *role);

		/**
		* @returns Returns the soap fault detail string                                                  
		*/
		WSF_EXTERN std::string WSF_CALL getFaultDetail();
		
		/**
		* @returns Returns the soap fault role string                                                  
		*/
		WSF_EXTERN std::string WSF_CALL getFaultRole();

		/**
		* Sets Soap Fault detail information
		* @param detail SOAP Fault detail information.
		*/
		WSF_EXTERN void WSF_CALL setFaultDetail(char const* detail);
		/**
		* Sets Soap Fault detail information
		* @param role SOAPFault role information
		*/
		WSF_EXTERN void WSF_CALL setFaultRole(char const* role);
		/**
         * Method for doing the required processing, of the Axis Fault.
         */
        WSF_EXTERN void WSF_CALL process() const;
    };
    /** @} */
}
#endif // WSFAULT_H
