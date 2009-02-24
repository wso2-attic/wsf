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

#ifndef OMOBJECT_H
#define OMOBJECT_H

#include <WSFDefines.h>
#include <AxisObject.h>

/**
 * @file OMObject.h
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup om_object OM Object
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class OMObject This creates a base object that serves as the
     * building block for other components of Axiom.
     */
    class OMObject: public AxisObject
    {
    protected:
        /**
         * Constructor setting up the OMObject.
         */
        WSF_CALL OMObject();
    };
    /** @} */
}
#endif // OMOBJECT_H
