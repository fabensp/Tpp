#pragma once

#include <iostream>

static int A_CNT_TEST = 0;
static int A_CNT_FAIL = 0;
static int A_LCL_FAIL = 0;
static int T_CNT_FAIL = 0;
static int T_CNT_TEST = 0;

#define TEST(desc, name, body)                                                  \
static void test_ ## name (){                                                          \
std::cout << "Testing that " << desc << "... ";                                 \
A_LCL_FAIL = 0;                                                                 \
body;                                                                           \
if (A_LCL_FAIL) {                                                               \
T_CNT_FAIL++;                                                                   \
std::cout << "[FAIL]\n";                                                        \
} else                                                                          \
std::cout << "[PASS]\n";                                                        \
T_CNT_TEST++;}                                                                  \

#define ASSERT(expr)                                                            \
if (!(expr)) {                                                                  \
std::cout << "Assertion failed: '" << #expr << "'"                              \
<<  " in " << __FILE__ << ":" << __LINE__ << std::endl;                         \
A_CNT_FAIL++; A_LCL_FAIL++;                                                     \
} A_CNT_TEST++                                                                  \

#define ASSERT_EQ(op1, op2)                                                     \
if (!(op1 == op2)) {                                                            \
std::cout << "Assertion failed in " << __FILE__ << ":" << __LINE__              \
<< "\n    " << #op1 << " which is \"" << op1                                    \
<< "\" \n        compared with \n    "                                          \
<< #op2 << " which is \"" << op2 << "\"\n" << std::endl;                        \
A_CNT_FAIL++; A_LCL_FAIL++;                                                     \
} A_CNT_TEST++                                                                  \

#define A_REPORT()                                                              \
std::cout << "\n---\n"                                                          \
<< "Total:  " << A_CNT_TEST << "\n"                                             \
<< "Passed: " << (A_CNT_TEST - A_CNT_FAIL) << "\n"                              \
<< "Failed: " << A_CNT_FAIL << "\n"                                             \

#define T_REPORT()                                                              \
std::cout << "\n---\n"                                                          \
<< "Total:  " << T_CNT_TEST << "\n"                                             \
<< "Passed: " << (T_CNT_TEST - T_CNT_FAIL) << "\n"                              \
<< "Failed: " << T_CNT_FAIL << "\n"                                             \
