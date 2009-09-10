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

#ifndef PROPERTY_H
#define PROPERTY_H

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
    * @defgroup property Property
    * @ingroup wso2wsf
    * @{
    */

    /**
     * @brief class Property is an entity that contains various properties
     * that can be set in an Options object. You can set properties using the
     * appropriate constructor and retrieve them using a get method.
     */
    class Property
    {
    private:
        /**
         * _name private variable holds reference for
         * Property name.
         */
        std::string _name;

        /**
         * _name private variable holds reference for
         * Property value.
         */
        void * _value;

        /**
         * _name private variable holds reference for
         * Property scope.
         */
        axis2_scope_t _scope;

    public:
        /**
         * Creates a node struct.
         * @param name property key string.
         * @param value pointer to property to be set.
         */
        WSF_EXTERN WSF_CALL Property(std::string name, void * value);

        /**
         * Creates a node struct.
         * @param name property key string.
         * @param value pointer to property to be set.
         * @param scope scope of property.
         */
        WSF_EXTERN WSF_CALL Property(std::string name, void * value, axis2_scope_t scope);

        /**
         * Gets Property name.
         * @return property key string.
         */
        WSF_EXTERN std::string WSF_CALL getName();

        /**
         * Gets Property value.
         * @return pointer to property to be set.
         */
        WSF_EXTERN void * WSF_CALL getValue();

        /**
         * Gets Property scope.
         * @return scope of property.
         */
        WSF_EXTERN axis2_scope_t WSF_CALL getScope();
    };
    /** @} */
}
#endif // PROPERTY_H
