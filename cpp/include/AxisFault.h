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

#ifndef AXISFAULT_H
#define AXISFAULT_H

#include <WSFDefines.h>
#include <WSFException.h>

/**
 * @file AxisFault.h
 */

/**
 * @brief namespace wso2wsf namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup axis_fault Axis Fault
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class AxisFault This Class is a derivation of the Exception Class, and
     * is used to implement exceptions generated within the Axis2/C core
     * on top of which WSF/C++ is implemented.
     */
    class AxisFault: public Exception
    {
    public:
        /**
         * Constructor accepting a reason for the exception.
         * @param reason reason to exception.
         */
        WSF_CALL AxisFault(char const * reason);

        /**
         * Method for doing the required processing, of the Axis Fault.
         */
        WSF_EXTERN void WSF_CALL process() const;
    };
    /** @} */
}
#endif // AXISFAULT_H
