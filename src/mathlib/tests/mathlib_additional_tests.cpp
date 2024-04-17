/**
 * @file mathlib_additional_tests.cpp
 * @author Nikola Jordanov
 *
 * @brief implementation of additional tests fro the math library
 */

#include "mathlibrary.h"
#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;

TEST(FACTORIAL, OF_Check){
    EXPECT_ANY_THROW(Factorial(21));
    EXPECT_ANY_THROW(Factorial(22));
    EXPECT_ANY_THROW(Factorial(100));
}

TEST(LN, functionality){
    EXPECT_EQ(ln(1),0);
    EXPECT_TRUE(ln(5)>=1.60943 && ln(5)<=1.60944);
    EXPECT_TRUE(ln(42)>=3.73766 && ln(42)<=3.73767);
    EXPECT_ANY_THROW(ln(0));
    EXPECT_ANY_THROW(ln(-5));
    EXPECT_ANY_THROW(ln(-42));
}

TEST(ABSVAL, functionality){
    EXPECT_EQ(AbsVal(42), 42);
    EXPECT_EQ(AbsVal(-42), 42);
    EXPECT_EQ(AbsVal(2.71), 2.71);
    EXPECT_EQ(AbsVal(-2.71), 2.71);
}
