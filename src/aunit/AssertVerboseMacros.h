/*
MIT License

Copyright (c) 2018 Brian T. Park

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// Significant portions of the design and implementation of this file came from
// https://github.com/mmurdoch/arduinounit/blob/master/src/ArduinoUnit.h

/**
 * @file AssertVerboseMacros.h
 *
 * Verbose versions of the macros in AssertMacros.h. These capture the string
 * of the actual arguments and pass them to the respective assertionVerbose()
 * methods so that verbose messages can be printed.
 */

#ifndef AUNIT_ASSERT_VERBOSE_MACROS_H
#define AUNIT_ASSERT_VERBOSE_MACROS_H

/** Assert that arg1 is equal to arg2. */
#define assertEqual(arg1,arg2) \
    assertOpVerboseInternal(arg1,aunit::internal::compareEqual,"==",arg2)

/** Assert that arg1 is not equal to arg2. */
#define assertNotEqual(arg1,arg2) \
    assertOpVerboseInternal(arg1,aunit::internal::compareNotEqual,"!=",arg2)

/** Assert that arg1 is less than arg2. */
#define assertLess(arg1,arg2) \
    assertOpVerboseInternal(arg1,aunit::internal::compareLess,"<",arg2)

/** Assert that arg1 is more than arg2. */
#define assertMore(arg1,arg2) \
    assertOpVerboseInternal(arg1,aunit::internal::compareMore,">",arg2)

/** Assert that arg1 is less than or equal to arg2. */
#define assertLessOrEqual(arg1,arg2) \
    assertOpVerboseInternal(arg1,aunit::internal::compareLessOrEqual,"<=",arg2)

/** Assert that arg1 is more than or equal to arg2. */
#define assertMoreOrEqual(arg1,arg2) \
    assertOpVerboseInternal(arg1,aunit::internal::compareMoreOrEqual,">=",arg2)

/** Assert that string arg1 is equal to string arg2, case-insensitive. */
#define assertStringCaseEqual(arg1,arg2) \
    assertOpVerboseInternal(arg1,aunit::internal::compareStringCaseEqual,\
    "==",arg2)

/** Assert that string arg1 is not equal to string arg2, case-insensitive. */
#define assertStringCaseNotEqual(arg1,arg2) \
    assertOpVerboseInternal(arg1,aunit::internal::compareStringCaseNotEqual,\
    "!=",arg2)

/** Assert that arg is true. */
#define assertTrue(arg) assertBoolVerboseInternal(arg,true)

/** Assert that arg is false. */
#define assertFalse(arg) assertBoolVerboseInternal(arg,false)

/** Internal helper macro, shouldn't be called directly by users. */
#define assertOpVerboseInternal(arg1,op,opName,arg2) do {\
  if (!assertionVerbose(__FILE__,__LINE__,\
      (arg1),AUNIT_F(#arg1),opName,op,(arg2),AUNIT_F(#arg2)))\
    return;\
} while (false)

/** Internal helper macro, shouldn't be called directly by users. */
#define assertBoolVerboseInternal(arg,value) do {\
  if (!assertionBoolVerbose(__FILE__,__LINE__,(arg),AUNIT_F(#arg),(value)))\
    return;\
} while (false)

/** Assert that arg1 and arg2 are within error of each other. */
#define assertNear(arg1, arg2, error) do { \
  if (!assertionNearVerbose(__FILE__, __LINE__, \
      arg1, AUNIT_F(#arg1), arg2, AUNIT_F(#arg2), error, AUNIT_F(#error), \
      "<=", aunit::internal::compareNear)) \
    return;\
} while (false)

/** Assert that arg1 and arg2 are NOT within error of each other. */
#define assertNotNear(arg1, arg2, error) do { \
  if (!assertionNearVerbose(__FILE__, __LINE__, \
      arg1, AUNIT_F(#arg1), arg2, AUNIT_F(#arg2), error, AUNIT_F(#error), \
      ">", aunit::internal::compareNotNear)) \
    return;\
} while (false)

#endif
