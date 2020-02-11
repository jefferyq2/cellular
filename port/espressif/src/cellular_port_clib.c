/*
 * Copyright 2020 u-blox Cambourne Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "cellular_port_clib.h"
#include "cellular_port.h"

#include "stdlib.h" // For malloc(), free(), strtof(), strtol()
#include "string.h"
#include "stdarg.h" // For va_blah
#include "stdio.h" // For vsscanf()
#include "ctype.h" // For isprint(), isctrl()
#include "math.h" // For log10() and pow()
#include "time.h" // For mktime()
#include "assert.h"
#include "errno.h"

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * TYPES
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * VARIABLES
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * STATIC FUNCTIONS
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * PUBLIC FUNCTIONS: MEMORY
 * -------------------------------------------------------------- */

// free().
void cellularPort_free(void *pMem)
{
    free(pMem);
}

// malloc().
void *pCellularPort_malloc(size_t sizeBytes)
{
    return malloc(sizeBytes);
}

// memcpy().
void *pCellularPort_memcpy(void *pDst, const void *pSrc,
                           size_t sizeBytes)
{
    return memcpy(pDst, pSrc, sizeBytes);
}

// memmove().
void *pCellularPort_memmove(void *pDst, const void *pSrc,
                            size_t sizeBytes)
{
    return memmove(pDst, pSrc, sizeBytes);
}

// memset().
void *pCellularPort_memset(void *pDst, int32_t value,
                           size_t sizeBytes)
{
    return memset(pDst, value, sizeBytes);
}

// memcmp().
int32_t cellularPort_memcmp(const void *p1, const void *p2,
                            size_t sizeBytes)
{
    return memcmp(p1, p2, sizeBytes);
}

/* ----------------------------------------------------------------
 * PUBLIC FUNCTIONS: STRING
 * -------------------------------------------------------------- */

// strlen().
size_t cellularPort_strlen(const char *pStr)
{
    return strlen(pStr);
}

// strcpy().
char *pCellularPort_strcpy(char *pDst, const char *pSrc)
{
    return strcpy(pDst, pSrc);
}

// strncpy().
char *pCellularPort_strncpy(char *pDst, const char *pSrc,
                            size_t sizeBytes)
{
    return strncpy(pDst, pSrc, sizeBytes);
}

// strcmp()
int32_t cellularPort_strcmp(const char *pStr1, const char *pStr2)
{
    return strcmp(pStr1, pStr2);
}

// sprintf().
int32_t cellularPort_sprintf(char *pBuffer, const char *pFormat,
                            ...)
{
    int32_t result;

    va_list args;
    va_start(args, pFormat);
    result = vsprintf(pBuffer, pFormat, args);
    va_end(args);

    return result;
}

// sscanf().
int32_t cellularPort_sscanf(const char *pStr, const char *pFormat,
                            ...)
{
    int32_t result;

    va_list args;
    va_start(args, pFormat);
    result = vsscanf(pStr, pFormat, args);
    va_end(args);

    return result;
}

// isprint().
int32_t cellularPort_isprint(int32_t c)
{
    return isprint(c);
}

// isctrl().
int32_t cellularPort_iscntrl(int32_t c)
{
    return iscntrl(c);
}

/* ----------------------------------------------------------------
 * PUBLIC FUNCTIONS: CONVERSION
 * -------------------------------------------------------------- */

// atoi().
int32_t cellularPort_atoi(const char *pStr)
{
    return atoi(pStr);
}

// strtol().
int32_t cellularPort_strtol(const char *pStr, char **ppEnd,
                            int32_t base)
{
    return strtol(pStr, ppEnd, base);
}

/** strtof().
 *
 * @param pStr  the string to convert to a float.
 * @param ppEnd pointer to a char * that will be populated
 *              with the first character after the converted
 *              string.  May be NULL.
 * @return      the float.
 */
float cellularPort_strtof(const char *pStr, char **ppEnd)
{
    return strtof(pStr, ppEnd);
}

/* ----------------------------------------------------------------
 * PUBLIC FUNCTIONS: TIME
 * -------------------------------------------------------------- */

// mktime().
int32_t cellularPort_mktime(CellularPort_tm *pTime)
{
    return (int32_t) mktime((struct tm *) pTime);
}

/* ----------------------------------------------------------------
 * PUBLIC FUNCTIONS: MATHS
 * -------------------------------------------------------------- */

// log10().
double cellularPort_log10(double x)
{
    return log10(x);
}

// pow().
double cellularPort_pow(double base, double exponent)
{
    return pow(base, exponent);
}

/* ----------------------------------------------------------------
 * PUBLIC FUNCTIONS: SYSTEM
 * -------------------------------------------------------------- */

// assert().
void cellularPort_assert(bool condition)
{
    return assert(condition);
}

// errno get.
int32_t cellularPort_errno_get()
{
    return errno;
}

// errno set.
void cellularPort_errno_set(int32_t _errno)
{
    errno = _errno;
}

// End of file
