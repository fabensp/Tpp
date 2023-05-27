#pragma once

#include <iostream>

#define TEST(name) std::cout << "Testing " << #name << "..." << std::endl
#define ASSERT(expr) if (!(expr)) std::cout << "Assertion failed: '" << #expr << "'" <<  " in " << __FILE__ << ":" << __LINE__ << std::endl
#define ASSERT_EQ(op1, op2) if (!(op1 == op2)) std::cout << "Assertion failed in " << __FILE__ << ":" << __LINE__ << "\n    " << #op1 << " which is \"" << op1 << "\" \n        compared with \n    " << #op2 << " which is \"" << op2 << "\"\n" << std::endl