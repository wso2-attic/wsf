#ifndef OMEXCEPTION_H
#define OMEXCEPTION_H


#include <Exception.h>
#include <OMObject.h>

/**
 * @file OMException.h
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup om_exception OMException
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class OMException This Class is a derivation of the Exception Class, and
     * is used to implement exceptions generated within the axiom objects used in WSF/C++.
     */
    class OMException: public Exception
    {
    private:
        /**
         * @var _sender private variable holds the reference to the
         * sender of the exception.
         */
        OMObject * _sender;

    public:
        /**
         * Constructor accepting a reason for the exception.
         * @param reason reason to exception.
         */
        OMException(char const * reason);

        /**
         * Constructor accepting a reason for the exception, and the
         * object that triggered the exception.
         * @param reason reason to exception.
         * @param sender object that triggered the exception.
         */
        OMException(char const * reason, OMObject * sender);

        /**
         * Method for doing the required processing, of the OM Exception.
         */
        void process() const;

        /**
         * desctructor that can be overriden.
         */
        virtual ~OMException();
    };
    /** @} */
}
#endif // OMEXCEPTION_H
