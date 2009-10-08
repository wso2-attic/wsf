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

#ifndef PARAMETER_H
#define PARAMETER_H

#include <WSFDefines.h>
#include <axutil_utils.h>
#include <string>


/**
 * @file Parameter.h
 * @brief Parameter which is a container class for associating name value pairs within wsf/cpp engine
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
     * Parameter is a class which abstract out name, value pairs which are used within Axis2/C Engine (WSF/CPP) to 
     * manage internal runtime configurations.
     */
    class Parameter
    {
    private:
        /**
         * _name private variable holds reference for Parameter name.
         */
        std::string _name;

        /**
         * _name private variable holds reference for Parameter value.
         */
        void * _value;

        /**
         * _name private variable holds reference for Parameter scope.
         */
        int _type;

    public:
        /**
         * Constructor for the Paramter class. 
         * @param name key string.
         * @param value pointer to property to be set.
         * @param type scode of the paramter.
         */
        WSF_EXTERN WSF_CALL Parameter(std::string name, void * value,int type );


        /**
         * Gets Parameter name.
         * @return Parameter key string.
         */
        WSF_EXTERN std::string WSF_CALL getName();

        /**
         * Gets Parameter value.
         * @return Parameter to Parameter to be set.
         */
        WSF_EXTERN void * WSF_CALL getValue();

        /**
         * Gets Parameter scope.
         * @return scope of Parameter.
         */
        WSF_EXTERN int WSF_CALL getType();
    };
    /** @} */
}
#endif // PARAMETER_H
