#ifndef NEETHIOBJECT_H
#define NEETHIOBJECT_H

#include <AxisObject.h>

/**
 * @file NeethiObject.h
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup neethi_object Neethi Object
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class NeethiObject This creates a base object that serves as the
     * building block for other components of Neethi.
     */
    class NeethiObject: public AxisObject
    {
    protected:
        /**
         * Constructor setting up the NeethiObject.
         */
        NeethiObject();
    };
    /** @} */
}
#endif // NEETHIOBJECT_H
