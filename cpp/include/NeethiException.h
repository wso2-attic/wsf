#ifndef NEETHIEXCEPTION_H
#define NEETHIEXCEPTION_H

#include <WSFDefines.h>
#include <Exception.h>
#include <NeethiObject.h>

/**
 * @file NeethiException.h
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup neethi_exception NeethiException
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class NeethiException This Class is a derivation of the Exception Class, and
     * is used to implement exceptions generated within the neethi objects used in WSF/C++.
     */
    class NeethiException: public Exception
    {
    private:
        /**
         * @var _sender private variable holds the reference to the
         * sender of the exception.
         */
        NeethiObject * _sender;

    public:
        /**
         * Constructor accepting a reason for the exception.
         * @param reason reason to exception.
         */
        WSF_CALL NeethiException(char const * reason);

        /**
         * Constructor accepting a reason for the exception, and the
         * object that triggered the exception.
         * @param reason reason to exception.
         * @param sender object that triggered the exception.
         */
        WSF_CALL NeethiException(char const * reason, NeethiObject * sender);

        /**
         * Method for doing the required processing, of the Neethi Exception.
         */
        WSF_EXTERN void WSF_CALL process() const;

        /**
         * desctructor that can be overriden.
         */
        virtual WSF_CALL ~NeethiException();
    };
    /** @} */
}
#endif // NEETHIEXCEPTION_H
