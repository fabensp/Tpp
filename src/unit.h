#pragma once

#include <iostream>

#define ASSERT(expr) { if (!(expr)) std::cout << "Assertion failed: '" << #expr << "'" <<  " in " << __PRETTY_FUNCTION__ << std::endl; }
#define ASSERT_EQ(op1, op2) { if (!(op1 == op2)) std::cout << "Assertion failed: \n    " << #op1 << " which is \"" << op1 << "\" \n        compared with \n    " << #op2 << " which is \"" << op2 << "\" \n        in function '" << __PRETTY_FUNCTION__ << "'" << std::endl;}