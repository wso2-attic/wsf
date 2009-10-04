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

#ifndef WSFEXCEPTION_H
#define WSFEXCEPTION_H

#include <WSFDefines.h>
#include <iostream>
#include <string>

/**
 * @file Exception.h
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup exception Exception
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class Exception The Exception Class is an abstract base class that can be used
     * to implement any type of exception. All exception classes used in this
     * project are derived from this class. The process method is what does the
     * necessary processing of the exception that was generated. The others
     * are methods used for string manipulation.
     */
    class Exception
    {
        /**
         * Overloaded insertion operator, is used for printing the exception onto a console.
         * @param str existing stream.
         * @param e exception object.
         * @return a modified output stream is returned.
         */
        friend WSF_EXTERN std::ostream & WSF_CALL operator <<(std::ostream & str, Exception const & e);

        /**
         * Overloaded insertion operator, is used for printing the exception onto a console.
         * @param str existing stream.
         * @param e exception object.
         * @return a modified output stream is returned.
         */
        friend WSF_EXTERN std::ostream & WSF_CALL operator <<(std::ostream & str, Exception const * e);

    private:
        /**
         * _reason reason to what caused the exception.
         */
        std::string _reason;

		/**
		* _code Error code corresponding the exception.                                                  
		*/
		std::string _code;

    public:
        /**
         * destructor that can be overridden.
         */
        virtual WSF_CALL ~Exception();

        /**
         * Method for doing the required processing.
         * Must be overridden, for an class that can be constructed.
         */
        virtual void WSF_CALL process() const = 0;

        /**
         * Operation for obtaining string representation of the exception
         * object. No member fields can be modified within this function.
         * The derived class has the option to override the behavior.
         */
        virtual WSF_CALL operator std::string() const;

		/**
		* Method to obtain the exception fault reason                                                   
		* @return Returns the fault reason string
		*/
		std::string WSF_CALL getFaultReason();
		/**
		* Method to get the exception fault code                                                   
		* @return Returns the fault code
		*/
		std::string WSF_CALL getFaultCode();

    protected:
        /**
         * Constructor accepting a reason for the exception.
         * @param reason reason to exception.
         */
        WSF_CALL Exception(char const * reason);
		/**
		* Constructor accepting both the reason and code the exception                                                   
		* @param reason Reason for the exception.
		* @param code   The Fault code corresponding to the exception.
		*/
		WSF_CALL Exception(char const *reason, char const *code);
		
    };
    /** @} */

    inline std::ostream & WSF_CALL operator <<(std::ostream & str, Exception const & e)
    {
        return str << const_cast<Exception &>(e).operator std::string();
    }

    inline std::ostream & WSF_CALL operator <<(std::ostream & str, Exception const * e)
    {
        return str << const_cast<Exception *>(e)->operator std::string();
    }    
}
#endif // WSFEXCEPTION_H
