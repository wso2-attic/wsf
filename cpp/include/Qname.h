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

#ifndef QNAME_H
#define QNAME_H

#include <WSFDefines.h>
#include <axutil_utils.h>
#include <axutil_qname.h>
#include <string>
#include <AxisObject.h>
/**
 * @file Property.h
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
    * @defgroup property Property
    * @ingroup wso2wsf
    * @{
    */

    /**
     * @brief class Qname
	 */
	class Qname : public AxisObject
    {
    private:
        /**
         * Namespace uri of the qname
         */
		axutil_qname_t *_qname;	

    public:
        /**
		 * Creates a Qname from namespace uri and localPart
         */
		WSF_EXTERN WSF_CALL Qname(std::string namespaceURI, std::string localPart);

        /**
		 * Creates a Qname from namespaceURI , local part , prefix 
         */
		WSF_EXTERN WSF_CALL Qname(std::string namespaceURI, std::string localPart, std::string prefix);

        /**
		 * 
         */
		WSF_EXTERN WSF_CALL Qname(std::string localPart);

		
		WSF_EXTERN WSF_CALL Qname(axutil_qname_t *qname);



        WSF_EXTERN std::string WSF_CALL getLocalPart();

        /**
         */
		WSF_EXTERN std::string WSF_CALL getNamespaceURI();

		/**
		*/
		WSF_EXTERN std::string WSF_CALL getPrefix();


		WSF_EXTERN bool WSF_CALL equals(Qname *qnameToTest);

		WSF_EXTERN axutil_qname_t* WSF_CALL getQname();

	};
    /** @} */
}
#endif // PROPERTY_H
