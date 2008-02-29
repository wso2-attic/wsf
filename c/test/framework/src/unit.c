
/*
 * Copyright 2005-2008 WSO2, Inc. http://wso2.com
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

#include <wsf_unit.h>
#include <signal.h>
#include <setjmp.h>

wsf_unit_bool_t quiet = WSF_UNIT_FALSE;
wsf_unit_bool_t list_tests = WSF_UNIT_FALSE;
wsf_unit_bool_t invert = WSF_UNIT_FALSE;
wsf_unit_bool_t detailed_report = WSF_UNIT_FALSE;
wsf_unit_bool_t only_if_needed = WSF_UNIT_FALSE;
wsf_unit_bool_t skip_segv = WSF_UNIT_FALSE;
wsf_unit_bool_t in_run_test = WSF_UNIT_FALSE;
wsf_unit_bool_t in_execute = WSF_UNIT_FALSE;
FILE *log_file = NULL;
const wsf_unit_char_t **test_list = NULL;
int errors = 0;
jmp_buf x;
jmp_buf y;
jmp_buf z;

void sig_handler(
    int signal);

static wsf_unit_bool_t
wsf_unit_test_exists(
    const wsf_unit_char_t *name);

static wsf_unit_bool_t
wsf_unit_test_required(
    const wsf_unit_char_t *name);

static void
wsf_unit_report_sub_suite(
    wsf_unit_sub_suite_t *sub_suite);

static void
wsf_unit_report_suite(
    wsf_unit_suite_t *suite);

struct wsf_unit_sub_suite
{
    wsf_unit_char_t *name;
    int total;
    int failed;
    wsf_unit_bool_t omit;
    int not_implemented;
    wsf_unit_sub_suite_t *next;
};

struct wsf_unit_suite
{
    wsf_unit_sub_suite_t *head;
    wsf_unit_sub_suite_t *tail;
};

struct wsf_unit_test_case
{
    wsf_unit_status_t status;
    wsf_unit_sub_suite_t *sub_suite;
};

WSF_UNIT_EXTERN wsf_unit_suite_t *WSF_UNIT_CALL
wsf_unit_suite_create(
    const wsf_unit_char_t *suite_name)
{
    wsf_unit_suite_t *suite = NULL;

    suite = (wsf_unit_suite_t *) malloc(sizeof(wsf_unit_suite_t));
    if (suite)
    {
        wsf_unit_status_t status = WSF_UNIT_FAILURE;

        suite->head = NULL;
        suite->tail = NULL;
        if (!suite_name)
        {
            return suite;
        }
        status = wsf_unit_suite_add_sub_suite(suite, suite_name);
        if (status)
        {
            return suite;
        }
        free(suite);
        suite = NULL;
    }
    else
    {
        wsf_unit_print_error_message("[error] %s\n", "No memmory available");
    }
    return suite;
}

WSF_UNIT_EXTERN wsf_unit_status_t WSF_UNIT_CALL
wsf_unit_suite_add_sub_suite(
    wsf_unit_suite_t * suite,
    const wsf_unit_char_t *suite_name)
{
    wsf_unit_sub_suite_t *sub_suite = NULL;
    const wsf_unit_char_t *tmp1 = NULL;
    const wsf_unit_char_t *tmp2 = NULL;

    if (!suite)
    {
        return WSF_UNIT_FAILURE;
    }
    else if (suite->tail && !suite->tail->omit)
        /* Report Last sub_suite */
    {
        wsf_unit_report_sub_suite(suite->tail);
    }

    sub_suite =
        (wsf_unit_sub_suite_t *) malloc(sizeof(wsf_unit_sub_suite_t));

    if (!sub_suite)
    {
        wsf_unit_print_error_message("[error] %s\n", "No memmory available");
        return WSF_UNIT_FAILURE;
    }
    sub_suite->name = NULL;
    sub_suite->total = 0;
    sub_suite->omit = WSF_UNIT_FALSE;
    sub_suite->not_implemented = 0;
    sub_suite->failed = 0;
    sub_suite->next = NULL;

    if (suite_name)
    {
        tmp1 = strrchr(suite_name, '/');
        tmp2 = strrchr(suite_name, '.');
        if (!tmp1 || *tmp1)
        {
            tmp1 = suite_name;
        }
        else
        {
            tmp1++;
        }
    }
    if (tmp2)
    {
        sub_suite->name = calloc((int)(tmp2 - tmp1) + 1,
                                 sizeof(wsf_unit_char_t));
        memcpy(sub_suite->name, tmp1, (int)(tmp2 - tmp1));
    }
    else if (tmp1)
    {
        sub_suite->name = calloc((int)strlen(tmp1) + 1,
                                 sizeof(wsf_unit_char_t));
        memcpy(sub_suite->name, tmp1, (int)strlen(tmp1));
    }

    if (suite->tail)
    {
        suite->tail->next = sub_suite;
    }
    else
    {
        suite->head = sub_suite;
    }
    suite->tail = sub_suite;

    if (!wsf_unit_test_required(sub_suite->name))
    {
        sub_suite->omit = WSF_UNIT_TRUE;
        if (list_tests)
        {
            wsf_unit_print_message("%s\n", sub_suite->name);
        }
        if(only_if_needed)
        {
            longjmp(y, (int)WSF_UNIT_TRUE);
        }
        return WSF_UNIT_SUCCESS;
    }

    if (!quiet)
    {
        wsf_unit_print_message("\n%-20s:  ", sub_suite->name);
    }

    return WSF_UNIT_SUCCESS;
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_suite_free(
    wsf_unit_suite_t * suite)
{
    if (suite)
    {
        if (suite->head)
        {
            wsf_unit_sub_suite_t *current = NULL;
            
            current = suite->head;

            while(current)
            {
                wsf_unit_sub_suite_t *temp = NULL;
                if (current->name)
                {
                    free(current->name);
                }
                temp = current->next;
                free(current);
                current = temp;
            }
        }
        else if (suite->tail)
        {
            if (suite->tail->name)
            {
                free(suite->tail->name);
            }
            free(suite->tail);
        }
        free(suite);
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_run_test(
    wsf_unit_suite_t * suite,
    WSF_UNIT_TEST test,
    void *value)
{
    wsf_unit_test_case_t *test_case = NULL;
    wsf_unit_sub_suite_t *sub_suite = NULL;
    wsf_unit_bool_t is_exception = WSF_UNIT_FALSE;

    if (!wsf_unit_test_required(suite->tail->name))
    {
        return;
    }
    
    test_case = malloc(sizeof(wsf_unit_test_case_t));
    if (!test_case)
    {
        return;
    }
    test_case->status = WSF_UNIT_SUCCESS;

    sub_suite = suite->tail;
    sub_suite->total++;
    test_case->sub_suite = sub_suite;

    if (!skip_segv)
    {
        signal(SIGSEGV, sig_handler);
        is_exception = (wsf_unit_bool_t)setjmp(x);

        if (!is_exception)
        {
            in_run_test = WSF_UNIT_TRUE;
            test(test_case, value);
            in_run_test = WSF_UNIT_FALSE;
        }
        else
        {
            test_case->status = WSF_UNIT_FAILURE;
            wsf_unit_print_error_message(
                "Line --: Segmentation Fault in Test No. %d\n%-20s:  ",
                sub_suite->total, "");
            /*
             * Getting the line number of where the segfault
             * occured requires debugging information. Thus,
             * it requires some peek into something like GDB
             * to figure this out. This seem lot of work for
             * the moment. Perhaps someday in the future. :D
             */
        }
    }
    else
    {
        test(test_case, value);
    }
    if (!test_case->status)
    {
        sub_suite->failed++;
    } 
    free(test_case);
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_print_error_message(
    const char *format,
    ...)
{
    va_list args;

    if (!quiet)
    {
        if (!log_file)
        {
            va_start(args, format);
            vfprintf(stderr, format, args);
            va_end(args);
            fflush(stderr);
        }
        else
        {
            va_start(args, format);
            vfprintf(log_file, format, args);
            va_end(args);
            fflush(log_file);
        }
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_print_message(
    const char *format,
    ...)
{
    va_list args;

    if (!log_file)
        {
            va_start(args, format);
            vfprintf(stdout, format, args);
            va_end(args);
            fflush(stdout);
        }
        else
        {
            va_start(args, format);
            vfprintf(log_file, format, args);
            va_end(args);
            fflush(log_file);
        }
}

static wsf_unit_bool_t
wsf_unit_test_exists(
    const wsf_unit_char_t *name)
{
    int i = -1;
    while(test_list[++i])
    {
        if (!strcmp(test_list[i], name))
        {
            return WSF_UNIT_TRUE;
        }
    }
    return WSF_UNIT_FALSE;
}

static wsf_unit_bool_t
wsf_unit_test_required(
    const wsf_unit_char_t *name)
{
    if (list_tests)
    {
        return WSF_UNIT_FALSE;
    }
    else if (!test_list)
    {
        return WSF_UNIT_TRUE;
    }
    else if ((wsf_unit_test_exists(name) && !invert)
        || ((!wsf_unit_test_exists(name) && invert)))
    {
        return WSF_UNIT_TRUE;
    }
    return WSF_UNIT_FALSE;
}

static void
wsf_unit_report_sub_suite(
    wsf_unit_sub_suite_t *sub_suite)
{
    if (sub_suite && !quiet)
    {
        if (sub_suite->failed != 0)
        {
            wsf_unit_print_message("FAILED %d of %d\n",
                sub_suite->failed, sub_suite->total);
        }
        else
        {
            wsf_unit_print_message("SUCCESS\n");
        }
    }
}

static void
wsf_unit_report_suite(
    wsf_unit_suite_t *suite)
{
    int failed = 0;
    int total = 0;
    int not_implemented = 0;
    wsf_unit_sub_suite_t *temp = NULL;

    if (!suite || list_tests)
    {
        return;
    }

    if (suite->tail && !suite->tail->omit)
    {
        wsf_unit_report_sub_suite(suite->tail);
    }

    for (temp = suite->head; temp; temp = temp->next)
    {
        if (!temp->omit)
        {
            failed += temp->failed;
            not_implemented += temp->not_implemented;
            total += temp->total;
        }
    }

    if (failed == 0)
    {
        if (errors != 0)
        {
            wsf_unit_print_message("\nSome Tests had Errors. Failed Test Sets: %d\n",
                                   errors);
            return;
        }
        else if (not_implemented == 0)
        {
            wsf_unit_print_message("\nAll Tests Passed\n");
            return;
        }
        else if (!detailed_report)
        {
            wsf_unit_print_message("\nAll Implemented Tests Passed. Not Implemented: %d\n",
                                   not_implemented);
            return;
        }
        temp = suite->head;
        wsf_unit_print_message("\n---------------------------------------------------\n");
        wsf_unit_print_message("%-15s\tTotal\tImpl.\t Impl. %%\n", "Implementation Report");
        wsf_unit_print_message("---------------------------------------------------\n");
        while (temp)
        {
            if (!temp->omit)
            {
                float percent = ((float)(temp->total - temp->not_implemented) / (float)temp->total);
                if (strlen(temp->name) > 15 && strlen(temp->name) < 20)
                {
                    wsf_unit_print_message("%-20s\t%5d\t%5d\t%6.2f%%\n", temp->name,
                        temp->total, (temp->total - temp->not_implemented), percent * 100);
                }
                else if (strlen(temp->name) > 20)
                {
                    temp->name[20] = '\0';
                    wsf_unit_print_message("%-20s\t%5d\t%5d\t%6.2f%%\n", temp->name,
                        temp->total, (temp->total - temp->not_implemented), percent * 100);
                }
                else
                {
                    wsf_unit_print_message("%-15s\t\t%5d\t%5d\t%6.2f%%\n", temp->name,
                        temp->total, (temp->total - temp->not_implemented), percent * 100);
                }
            }
            temp = temp->next;
        }
        wsf_unit_print_message("___________________________________________________\n\n");
        wsf_unit_print_message("%-15s\t\t%5d\t%5d\t%6.2f%%\n", "",
                        total, (total - not_implemented), ((float)(total - not_implemented) / (float)total) * 100);
        wsf_unit_print_message("===================================================\n");
        return;
    }

    temp = suite->head;
    wsf_unit_print_message("\n---------------------------------------------------\n");
    wsf_unit_print_message("%-15s\t\tTotal\tFailed\tFailure %%\n", "Failure Report");
    wsf_unit_print_message("---------------------------------------------------\n");
    while (temp)
    {
        if (!temp->omit)
        {
            float percent = ((float)temp->failed / (float)temp->total);
            if (strlen(temp->name) > 15 && strlen(temp->name) < 20)
            {
                wsf_unit_print_message("%-20s\t%5d\t%6d\t%6.2f%%\n", temp->name,
                    temp->total, temp->failed, percent * 100);
            }
            else if (strlen(temp->name) > 20)
            {
                temp->name[20] = '\0';
                wsf_unit_print_message("%-20s\t%5d\t%6d\t%6.2f%%\n", temp->name,
                    temp->total, temp->failed, percent * 100);
            }
            else
            {
                wsf_unit_print_message("%-15s\t\t%5d\t%6d\t%6.2f%%\n", temp->name,
                    temp->total, temp->failed, percent * 100);
            }
        }
        temp = temp->next;
    }
    wsf_unit_print_message("___________________________________________________\n\n");
    wsf_unit_print_message("%-15s\t\t%5d\t%6d\t%6.2f%%\n", "",
                    total, failed, ((float)failed / (float)total) * 100);
    wsf_unit_print_message("===================================================\n");
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_equals_int(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const int expected,
    const int actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected == actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: expected <%d>, but saw <%d>\n%-20s:  ", line_no,
             expected, actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_equals_long(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const long expected,
    const long actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected == actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: expected <%ld>, but saw <%ld>\n%-20s:  ", line_no,
             expected, actual, "");
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_equals_float(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const float expected,
    const float actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected == actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: expected <%f>, but saw <%f>\n%-20s:  ", line_no,
             expected, actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_equals_double(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const double expected,
    const double actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected == actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: expected <%f>, but saw <%f>\n%-20s:  ", line_no,
             expected, actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_equals_char(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const char expected,
    const char actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected == actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: expected <%c>, but saw <%c>\n%-20s:  ", line_no,
             expected, actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_equals_string(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const char *expected,
    const char *actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (!expected && !actual)
    {
        return;
    }
    else if (expected && actual && !strcmp(expected, actual))
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: expected <%s>, but saw <%s>\n%-20s:  ", line_no,
             expected, actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_equals_ptr(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const void *expected,
    const void *actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected == actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: expected <%p>, but saw <%p>\n%-20s:  ", line_no,
             expected, actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_equals_size(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const size_t expected,
    const size_t actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected == actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: expected <size:%lu>, but saw <size:%lu>\n%-20s:  ", line_no,
             (unsigned long)expected, (unsigned long)actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_not_equals_int(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const int expected,
    const int actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected != actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: did not expect <%d>, but saw <%d>\n%-20s:  ", line_no,
             expected, actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_not_equals_long(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const long expected,
    const long actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected != actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: did not expect <%ld>, but saw <%ld>\n%-20s:  ", line_no,
             expected, actual, "");  
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_not_equals_float(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const float expected,
    const float actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected != actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: did not expect <%f>, but saw <%f>\n%-20s:  ", line_no,
             expected, actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_not_equals_double(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const double expected,
    const double actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected != actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: did not expect <%f>, but saw <%f>\n%-20s:  ", line_no,
             expected, actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_not_equals_char(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const char expected,
    const char actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected != actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: did not expect <%c>, but saw <%c>\n%-20s:  ", line_no,
             expected, actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_not_equals_string(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const char *expected,
    const char *actual,
    const int line_no)
{
    int count = 0;

    if (!test_case->status)
    {
        return;
    }

    if (!expected || !actual)
    {
        return;
    }
    count = (int)strlen(expected);
    if ((int)strlen(actual) < count)
    {
        count = (int)strlen(actual);
    }
    if (expected && actual && strncmp(expected, actual, count))
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: did not expect <%s>, but saw <%s>\n%-20s:  ", line_no,
             expected, actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_not_equals_ptr(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const void *expected,
    const void *actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected != actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: did not expect <%p>, but saw <%p>\n%-20s:  ", line_no,
             expected, actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_not_equals_size(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const size_t expected,
    const size_t actual,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (expected != actual)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: did not expect <size:%lu>, but saw <size:%lu>\n%-20s:  ", line_no,
             (unsigned long)expected, (unsigned long)actual, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_null(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const void *pointer,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (!pointer)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: expected <NULL>, but did not see <NULL>\n%-20s:  ", line_no, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_not_null(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const void *pointer,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (pointer)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: did not expect <NULL>, but saw <NULL>\n%-20s:  ", line_no, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_true(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const int condition,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (condition)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: expected <TRUE>, but saw <FALSE>\n%-20s:  ", line_no, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_assert_false(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const int condition,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    if (!condition)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ",line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: expected <FALSE>, but saw <TRUE>\n%-20s:  ", line_no, "");   
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_not_implemented(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const int line_no)
{
    test_case->sub_suite->not_implemented++;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
}

WSF_UNIT_EXTERN void WSF_UNIT_CALL
wsf_unit_fail(
    wsf_unit_test_case_t *test_case,
    const char *message,
    const int line_no)
{
    if (!test_case->status)
    {
        return;
    }

    test_case->status = WSF_UNIT_FAILURE;
    if (message)
    {
        wsf_unit_print_error_message("Line %d: %s\n%-20s:  ", line_no, message, "");
    }
    else
    {
        wsf_unit_print_error_message(
             "Line %d: Failed\n%-20s:  ", line_no, "");   
    }
}

WSF_UNIT_EXTERN int WSF_UNIT_CALL
wsf_unit_execute(
    const int argc,
    const char *const argv[],
    const wsf_unit_char_t *suite_name,
    const int testc,
    const wsf_unit_test_list_t testv[])
{
    int i = 0, j = 0;
    wsf_unit_bool_t list_provided = WSF_UNIT_FALSE;
    wsf_unit_suite_t *suite = NULL;

    list_tests = WSF_UNIT_FALSE;
    invert = WSF_UNIT_FALSE;
    test_list = NULL;
#ifndef WIN32
    quiet = !isatty(STDOUT_FILENO);
#endif

    for (i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-h"))
        {
            printf("Usage: %s [options] [-f log_file] [test_names]\n", argv[0]);
            printf(" -f to provide a log_file\n");
            printf(" -l to list available tests instead of running\n");
            printf(" -n to run tests only if neccessary and if not\n");
            printf("    abort immediately. It is important to know\n");
            printf("    that this might cause memory leaks in poor\n");
            printf("    implementations of test cases. To use this\n");
            printf("    option initialize the test suite/sub-suite\n");
            printf("    before any local memory allocations\n");
            printf(" -q for a quite mode operation\n");
            printf(" -r to report not-implemented tests in detail.\n");
            printf(" -s to stop catching Segmentation Faults. This\n");
            printf("    is useful for debugging\n");
            printf(" -x to skip provided test names. If you do not\n");
            printf("    provide this option all the tests provided\n");
            printf("    will run\n");
            return 0;
        }
        if (!list_tests && !strcmp(argv[i], "-l"))
        {
            list_tests = WSF_UNIT_TRUE;
            continue;
        }
        if (!invert && !strcmp(argv[i], "-x"))
        {
            invert = WSF_UNIT_TRUE;
            continue;
        }
        if (!quiet && !strcmp(argv[i], "-q"))
        {
            quiet = WSF_UNIT_TRUE;
            continue;
        }
        if (!only_if_needed && !strcmp(argv[i], "-n"))
        {
            only_if_needed = WSF_UNIT_TRUE;
            continue;
        }
        if (!detailed_report && !strcmp(argv[i], "-r"))
        {
            detailed_report = WSF_UNIT_TRUE;
            continue;
        }
        if (!skip_segv && !strcmp(argv[i], "-s"))
        {
            skip_segv = WSF_UNIT_TRUE;
            continue;
        }
        if (!log_file && !strcmp(argv[i], "-f"))
        {
            if (++i < argc)
            {
                log_file = fopen(argv[i], "a+");
            }
            else
            {
                fprintf(stderr, "No log file provided.\n");
            }
            continue;
        }
        if (argv[i][0] == '-')
        {
            fprintf(stderr, "Invalid option: `%s'\n", argv[i]);
            exit(1);
        }
        if (!list_provided)
        {
            j = i;
            list_provided = WSF_UNIT_TRUE;
        }
    }

    wsf_unit_print_message("\n---------------------------------------------------");
    wsf_unit_print_message("\nUnit Test Suite     :  %s", suite_name);
    wsf_unit_print_message("\nAvailable Test Sets :  %d", testc);
    wsf_unit_print_message("\n===================================================\n");

    if (list_provided)
    {
        /* Save as much as possible space */
        test_list = calloc(argc - j + 1, sizeof(char *));
        i = j;
        for (j = 0; i < argc; i++, j++)
        {
            test_list[j] = argv[i];
        }
    }

    suite = wsf_unit_suite_create(NULL);

    for (i = 0; i < testc; i++)
    {
        wsf_unit_bool_t is_list_only = WSF_UNIT_FALSE;
        wsf_unit_bool_t is_exception = WSF_UNIT_FALSE;

        if (!skip_segv)
        {
            signal(SIGSEGV, sig_handler);
            is_list_only = (wsf_unit_bool_t)setjmp(y);
            is_exception = (wsf_unit_bool_t)setjmp(z);
            in_execute = WSF_UNIT_TRUE;
            if(!is_list_only && !is_exception && !testv[i].execute(suite) && !list_tests)
            {
                wsf_unit_print_error_message(
                    "Test Set Reported Failure\n%-20s:  ", "");
                errors++;
            }
            else if(is_exception && !list_tests)
            {
                wsf_unit_print_error_message(
                    "Segmentation Fault in Test Initialization\n%-20s:  ", "");
                errors++;
            }
            in_execute = WSF_UNIT_FALSE;
        }
        else
        {
            if(!is_list_only && !testv[i].execute(suite) && !list_tests)
            {
                wsf_unit_print_error_message(
                    "Test Set Reported Failure\n%-20s:  ", "");
                errors++;
            }
        }
    }

    wsf_unit_report_suite(suite);
    wsf_unit_suite_free(suite);
    if (test_list)
    {
        free(test_list);
        test_list = NULL;
    }
    if (log_file)
    {
        fclose(log_file);
        log_file = NULL;
    }
    return 0;
}

void
sig_handler(
    int signal)
{
    switch (signal)
    {
    case SIGSEGV:
        if (in_run_test)
        {
            in_run_test = WSF_UNIT_FALSE;
            longjmp(x, (int)WSF_UNIT_TRUE);
        }
        else if (in_execute)
        {
            in_execute = WSF_UNIT_FALSE;
            longjmp(z, (int)WSF_UNIT_TRUE);
        }
        break;
    default:
        break;
    }
    return;
}

