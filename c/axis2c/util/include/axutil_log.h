/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AXUTIL_LOG_H
#define AXUTIL_LOG_H

#include <axutil_allocator.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axutil_log_ops axutil_log_ops_t;
    typedef struct axutil_log axutil_log_t;


#define AXIS2_LOG_SI __FILE__,__LINE__

    /**
     * @defgroup axutil_log log
     * @ingroup axis2_util
     * @{
     */

    /**
      *Examples
      *To write debug information to log
      *AXIS2_LOG_DEBUG(log,AXIS2_LOG_SI,"log this %s %d","test",123);
      *This would log
      *"log this test 123" into the log file
      *
      *similar macros are defined for different log levels: CRITICAL,ERROR,WARNING and INFO
      *
      *CRITICAL and ERROR logs are always written to file and other logs are written 
      *depending on the log level set (log->level)
      */
    /**
      * \brief Axis2 log levels
      */
    typedef enum axutil_log_levels
    {
        /** Critical level, logs only critical errors */
        AXIS2_LOG_LEVEL_CRITICAL = 0,
        /** Error level, logs only errors */
        AXIS2_LOG_LEVEL_ERROR,
        /** Warning level, logs only warnings */
        AXIS2_LOG_LEVEL_WARNING,
        /** Info level, logs information */
        AXIS2_LOG_LEVEL_INFO,
        /** Debug level, logs everything */
        AXIS2_LOG_LEVEL_DEBUG,
        /** Trace level, Enable with compiler time option AXIS2_TRACE */
        AXIS2_LOG_LEVEL_TRACE
    } axutil_log_levels_t;

    /**
      * \brief Axis2 log ops struct
      *
      * Encapsulator struct for ops of axutil_log
      */
    struct axutil_log_ops
    {

        /**
         * deletes the log
         * @return axis2_status_t AXIS2_SUCCESS on success else AXIS2_FAILURE
         */

        void(AXIS2_CALL *
        free)(axutil_allocator_t *allocator,
            struct axutil_log *log);

        /**
          * writes to the log
          * @param buffer buffer to be written to log
          * @param size size of the buffer to be written to log
          * @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE
          */
        void(AXIS2_CALL *
        write)(axutil_log_t *log,
            const axis2_char_t *buffer,
            axutil_log_levels_t level,
            const axis2_char_t *file,
            const int line);
    };

    /**
      * \brief Axis2 Log struct
      *
      * Log is the encapsulating struct for all log related data and ops
      */
    struct axutil_log
    {
        /** Log related ops */
        const axutil_log_ops_t *ops;
        /** Log level */
        axutil_log_levels_t level;
        /** Is logging enabled? */
        axis2_bool_t enabled;

    };

    AXIS2_EXTERN void AXIS2_CALL
    axutil_log_impl_log_critical(axutil_log_t *log,
            const axis2_char_t *filename,
            const int linenumber,
            const axis2_char_t *format, ...);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_log_impl_log_error(axutil_log_t *log,
            const axis2_char_t *filename,
            const int linenumber,
            const axis2_char_t *format, ...);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_log_impl_log_warning(axutil_log_t *log,
            const axis2_char_t *filename,
            const int linenumber,
            const axis2_char_t *format, ...);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_log_impl_log_info(axutil_log_t *log,
            const axis2_char_t *format, ...);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_log_impl_log_debug(axutil_log_t *log,
            const axis2_char_t *filename,
            const int linenumber,
            const axis2_char_t *format, ...);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_log_impl_log_trace(axutil_log_t *log,
            const axis2_char_t *filename,
            const int linenumber,
            const axis2_char_t *format, ...);

    AXIS2_EXTERN void AXIS2_CALL 
    axutil_log_free(axutil_allocator_t *allocator,
        struct axutil_log *log);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_log_write(axutil_log_t *log,
        const axis2_char_t *buffer,
        axutil_log_levels_t level,
        const axis2_char_t *file,
        const int line);

#define AXIS2_LOG_FREE(allocator, log) \
      axutil_log_free(allocator, log)

#define AXIS2_LOG_WRITE(log, buffer, level, file) \
      axutil_log_write(log, buffer, level, file, AXIS2_LOG_SI)

#define AXIS2_LOG_DEBUG axutil_log_impl_log_debug
#define AXIS2_LOG_INFO axutil_log_impl_log_info
#define AXIS2_LOG_WARNING axutil_log_impl_log_warning
#define AXIS2_LOG_ERROR axutil_log_impl_log_error
#define AXIS2_LOG_CRITICAL axutil_log_impl_log_critical

#ifdef AXIS2_TRACE
#define AXIS2_LOG_TRACE axutil_log_impl_log_trace
#else
# ifdef HAVE_GNUC_VARARGS
#  define AXIS2_LOG_TRACE(params, args ...)
# elif defined HAVE_ISO_VARARGS
#  define AXIS2_LOG_TRACE(params, ...)
# elif __STDC__ && __STDC_VERSION > 199901L
#  define AXIS2_LOG_TRACE(params, ...)
# elif WIN32
#  define AXIS2_LOG_TRACE axutil_log_impl_log_trace
# else
#  define AXIS2_LOG_TRACE axutil_log_impl_log_trace
# endif
#endif

    /** @} */

#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_LOG_H */




