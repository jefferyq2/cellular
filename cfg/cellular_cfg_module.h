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

#ifndef _CELLULAR_CFG_MODULE_H_
#define _CELLULAR_CFG_MODULE_H_

/* No #includes allowed here */

/* This header file contains configuration information for all the
 * possible cellular module types.
 */

/* ----------------------------------------------------------------
 * COMPILE-TIME MACRO CROSS CHECKING
 * -------------------------------------------------------------- */

/* #define cross-checking.
 */
#if defined(CELLULAR_CFG_MODULE_SARA_R4) && defined(CELLULAR_CFG_MODULE_SARA_R5)
# error More than one module type defined.
#endif

#if !defined(CELLULAR_CFG_MODULE_SARA_R4) && !defined(CELLULAR_CFG_MODULE_SARA_R5)
# error Must define a module type (e.g. CELLULAR_CFG_MODULE_SARA_R4 or CELLULAR_CFG_MODULE_SARA_R5).
#endif

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS COMMON TO ALL MODULES
 * -------------------------------------------------------------- */

#ifndef CELLULAR_CFG_BAUD_RATE
/** The baud rate to use on the UART interface
 */
# define CELLULAR_CFG_BAUD_RATE                      115200
#endif

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS FOR SARA-R5
 * -------------------------------------------------------------- */

#ifdef CELLULAR_CFG_MODULE_SARA_R5
    // None yet
#endif

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS FOR SARA-R4
 * -------------------------------------------------------------- */

#ifdef CELLULAR_CFG_MODULE_SARA_R4
    // None yet
#endif

#endif // _CELLULAR_CFG_MODULE_H_

// End of file