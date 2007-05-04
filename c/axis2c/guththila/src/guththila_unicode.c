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


#include "guththila_unicode.h"
#include <stdlib.h>
#include <string.h>
#ifdef UNICODE_OUT              /* This variable for Obtain UTF-16 Output */

/*! In order to determine length of UTF-16 Buffer
 * Basicall guththila_char_t *p should be a Utf-16 Buffer  */

guththila_UTF8_char
guththila_strlen_unicode(guththila_char_t * p)
{
    guththila_UTF8_char len = 0;
    guththila_UTF8_char d;
    guththila_UTF16_char c;
    guththila_char_t *s = p;
    c = *((guththila_UTF16_char *) & s[len]);
    if (c)
    {
        while (c)
        {
            c = *((guththila_UTF16_char *) & s[len]);
            len += 2;
            d = s[len];
            if (!d)
            {
                return len;
                break;
            }
        }
        return (len - 2);
    }
    else
        return 0;
}

/*!To Duplicate UTF-16 String  */
guththila_char_t *
guththila_strdup_unicode(guththila_char_t * p, int length)
{
    guththila_char_t *s;
    s = (guththila_char_t *) calloc(length + 1, 1);
    s[length] = 0;
    return (guththila_char_t *) memcpy(s, p, length);
}
#endif /*end of UNICODE_OUT definition  */
