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


/* base64 encoder/decoder. Originally part of main/util.c
 * but moved here so that support/ab and axis2_sha1.c could
 * use it. This meant removing the axis2_palloc()s and adding
 * ugly 'len' functions, which is quite a nasty cost.
 */

#include <axutil_base64.h>

static const unsigned char pr2six[256] =
    {
#ifndef __OS400__
        /* ASCII table */
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 62, 64, 64, 64, 63,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 64, 64, 64, 64, 64, 64,
        64,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 64, 64, 64, 64, 64,
        64, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64
#else /* __OS400__ */
        /* EBCDIC table */
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 62, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 63, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 26, 27, 28, 29, 30, 31, 32, 33, 34, 64, 64, 64, 64, 64, 64,
        64, 35, 36, 37, 38, 39, 40, 41, 42, 43, 64, 64, 64, 64, 64, 64,
        64, 64, 44, 45, 46, 47, 48, 49, 50, 51, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64,  0,  1,  2,  3,  4,  5,  6,  7,  8, 64, 64, 64, 64, 64, 64,
        64,  9, 10, 11, 12, 13, 14, 15, 16, 17, 64, 64, 64, 64, 64, 64,
        64, 64, 18, 19, 20, 21, 22, 23, 24, 25, 64, 64, 64, 64, 64, 64,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 64, 64, 64, 64, 64, 64
#endif /* AXIS2_CHARSET_EBCDIC */
    };

#ifdef __OS400__

static unsigned char os_toascii[256] =
    {
        /* 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F */
        0,   1,   2,   3, 156,   9, 134, 127, 151, 141, 142,  11,  12,  13,  14,  15,
        16,  17,  18,  19, 157, 133,   8, 135,  24,  25, 146, 143,  28,  29,  30,  31,
        128, 129, 130, 131, 132,  10,  23,  27, 136, 137, 138, 139, 140,   5,   6,   7,
        144, 145,  22, 147, 148, 149, 150,   4, 152, 153, 154, 155,  20,  21, 158,  26,
        32, 160, 226, 228, 224, 225, 227, 229, 231, 241, 162,  46,  60,  40,  43, 124,
        38, 233, 234, 235, 232, 237, 238, 239, 236, 223,  33,  36,  42,  41,  59, 172,
        45,  47, 194, 196, 192, 193, 195, 197, 199, 209, 166,  44,  37,  95,  62,  63,
        248, 201, 202, 203, 200, 205, 206, 207, 204,  96,  58,  35,  64,  39,  61,  34,
        216,  97,  98,  99, 100, 101, 102, 103, 104, 105, 171, 187, 240, 253, 254, 177,
        176, 106, 107, 108, 109, 110, 111, 112, 113, 114, 170, 186, 230, 184, 198, 164,
        181, 126, 115, 116, 117, 118, 119, 120, 121, 122, 161, 191, 208, 221, 222, 174,
        94, 163, 165, 183, 169, 167, 182, 188, 189, 190,  91,  93, 175, 168, 180, 215,
        123,  65,  66,  67,  68,  69,  70,  71,  72,  73, 173, 244, 246, 242, 243, 245,
        125,  74,  75,  76,  77,  78,  79,  80,  81,  82, 185, 251, 252, 249, 250, 255,
        92, 247,  83,  84,  85,  86,  87,  88,  89,  90, 178, 212, 214, 210, 211, 213,
        48,  49,  50,  51,  52,  53,  54,  55,  56,  57, 179, 219, 220, 217, 218, 159
    };

#endif /* __OS400__ */

AXIS2_EXTERN int AXIS2_CALL axutil_base64_decode_len(const char *bufcoded)
{
    int nbytesdecoded;
    register const unsigned char *bufin;
    register int nprbytes;

    bufin = (const unsigned char *) bufcoded;
    while (pr2six[*(bufin++)] <= 63);

    nprbytes = (bufin - (const unsigned char *) bufcoded) - 1;
    nbytesdecoded = ((nprbytes + 3) / 4) * 3;

    return nbytesdecoded + 1;
}

AXIS2_EXTERN int AXIS2_CALL axutil_base64_decode(char *bufplain, const char *bufcoded)
{
    int len;
    len = axutil_base64_decode_binary((unsigned char *) bufplain, bufcoded);
    bufplain[len] = '\0';
    return len;
}

/* This is the same as axutil_base64_decode() except on EBCDIC machines, where
 * the conversion of the output to ebcdic is left out.
 */

AXIS2_EXTERN int AXIS2_CALL axutil_base64_decode_binary(unsigned char *bufplain,
        const char *bufcoded)
{
    int nbytesdecoded;
    register const unsigned char *bufin;
    register unsigned char *bufout;
    register int nprbytes;

    bufin = (const unsigned char *) bufcoded;
    while (pr2six[*(bufin++)] <= 63);
    nprbytes = (bufin - (const unsigned char *) bufcoded) - 1;
    nbytesdecoded = ((nprbytes + 3) / 4) * 3;

    bufout = (unsigned char *) bufplain;
    bufin = (const unsigned char *) bufcoded;

    while (nprbytes > 4)
    {
        *(bufout++) =
            (unsigned char)(pr2six[*bufin] << 2 | pr2six[bufin[1]] >> 4);
        *(bufout++) =
            (unsigned char)(pr2six[bufin[1]] << 4 | pr2six[bufin[2]] >> 2);
        *(bufout++) =
            (unsigned char)(pr2six[bufin[2]] << 6 | pr2six[bufin[3]]);
        bufin += 4;
        nprbytes -= 4;
    }

    /* Note: (nprbytes == 1) would be an error, so just ingore that case */
    if (nprbytes > 1)
    {
        *(bufout++) =
            (unsigned char)(pr2six[*bufin] << 2 | pr2six[bufin[1]] >> 4);
    }
    if (nprbytes > 2)
    {
        *(bufout++) =
            (unsigned char)(pr2six[bufin[1]] << 4 | pr2six[bufin[2]] >> 2);
    }
    if (nprbytes > 3)
    {
        *(bufout++) =
            (unsigned char)(pr2six[bufin[2]] << 6 | pr2six[bufin[3]]);
    }

    nbytesdecoded -= (4 - nprbytes) & 3;
    return nbytesdecoded;
}

static const char basis_64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

AXIS2_EXTERN int AXIS2_CALL axutil_base64_encode_len(int len)
{
    return ((len + 2) / 3 * 4) + 1;
}

AXIS2_EXTERN int AXIS2_CALL axutil_base64_encode(char *encoded, const char *string, int len)
{
#ifndef __OS400__
    return axutil_base64_encode_binary(encoded, (const unsigned char *) string, len);
#else /* __OS400__ */
    int i;
    char *p;

    p = encoded;
    for (i = 0; i < len - 2; i += 3)
    {
        *p++ = basis_64[(os_toascii[string[i]] >> 2) & 0x3F];
        *p++ = basis_64[((os_toascii[string[i]] & 0x3) << 4) |
                ((int)(os_toascii[string[i + 1]] & 0xF0) >> 4)];
        *p++ = basis_64[((os_toascii[string[i + 1]] & 0xF) << 2) |
                ((int)(os_toascii[string[i + 2]] & 0xC0) >> 6)];
        *p++ = basis_64[os_toascii[string[i + 2]] & 0x3F];
    }
    if (i < len)
    {
        *p++ = basis_64[(os_toascii[string[i]] >> 2) & 0x3F];
        if (i == (len - 1))
        {
            *p++ = basis_64[((os_toascii[string[i]] & 0x3) << 4)];
            *p++ = '=';
        }
        else
        {
            *p++ = basis_64[((os_toascii[string[i]] & 0x3) << 4) |
                    ((int)(os_toascii[string[i + 1]] & 0xF0) >> 4)];
            *p++ = basis_64[((os_toascii[string[i + 1]] & 0xF) << 2)];
        }
        *p++ = '=';
    }

    *p++ = '\0';
    return p - encoded;
#endif                /* __OS400__ */
}

/* This is the same as axutil_base64_encode() except on EBCDIC machines, where
 * the conversion of the input to ascii is left out.
 */
AXIS2_EXTERN int AXIS2_CALL axutil_base64_encode_binary(char *encoded,
        const unsigned char *string, int len)
{
    int i;
    char *p;

    p = encoded;
    for (i = 0; i < len - 2; i += 3)
    {
        *p++ = basis_64[(string[i] >> 2) & 0x3F];
        *p++ = basis_64[((string[i] & 0x3) << 4) |
                ((int)(string[i + 1] & 0xF0) >> 4)];
        *p++ = basis_64[((string[i + 1] & 0xF) << 2) |
                ((int)(string[i + 2] & 0xC0) >> 6)];
        *p++ = basis_64[string[i + 2] & 0x3F];
    }
    if (i < len)
    {
        *p++ = basis_64[(string[i] >> 2) & 0x3F];
        if (i == (len - 1))
        {
            *p++ = basis_64[((string[i] & 0x3) << 4)];
            *p++ = '=';
        }
        else
        {
            *p++ = basis_64[((string[i] & 0x3) << 4) |
                    ((int)(string[i + 1] & 0xF0) >> 4)];
            *p++ = basis_64[((string[i + 1] & 0xF) << 2)];
        }
        *p++ = '=';
    }

    *p++ = '\0';
    return p - encoded;
}
