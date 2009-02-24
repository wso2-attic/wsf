/*
 * Copyright 2005,2009 WSO2, Inc. http://wso2.com
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

#ifndef PARAMETER_H
#define PARAMETER_H

#include <WSFDefines.h>
#include <axutil_utils.h>
#include <string>
/**
 * @file Property.h
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
    * @defgroup Parameter Parameter
    * @ingroup wso2wsf
    * @{
    */

    /**
     * @brief class Parameter
     */
	class Parameter
    {
    private:
        /**
         * @var _name private variable holds reference for
         * Property name.
         */
        std::string _name;

        /**
         * @var _name private variable holds reference for
         * Property value.
         */
        void * _value;

        /**
         * @var _name private variable holds reference for
         * Property scope.
         */
        int _type;

    public:
        /**
         * Creates a node struct.
         * @param name property key string.
         * @param value pointer to property to be set.
         */
        WSF_EXTERN WSF_CALL Parameter(std::string name, void * value,int type );


        /**
         * Gets Parameter name.
         * @return Parameter key string.
         */
        WSF_EXTERN std::string WSF_CALL getName();

        /**
         * Gets Parameter value.
         * @return Parameter to property to be set.
         */
        WSF_EXTERN void * WSF_CALL getValue();

        /**
         * Gets Parameter scope.
         * @return scope of property.
         */
        WSF_EXTERN int WSF_CALL getType();
    };
    /** @} */
}
#endif // PARAMETER_H
