#ifndef OMOBJECT_H
#define OMOBJECT_H

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
        OMObject();
    };
    /** @} */
}
#endif // OMOBJECT_H
