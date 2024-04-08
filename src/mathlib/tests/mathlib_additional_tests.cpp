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
    unsigned long max=1;
    long long int fact;
    for (fact=1; fact+>ULONG_MAX/max; max++){
	if (fact<0) break;
	fact=fact*max;
    }
    for(long i=max; i<100; i+=10){
	EXPECT_ANY_THROW(Factorial(max));
    }
}

TEST(LN, functionality){
    EXPECT_TRUE(ln(1)=0);
    EXPECT_TRUE(ln(5)>=1.60943 && ln(5)<=1.60944);
    EXPECT_TRUE(ln(42)>=3.73766 && ln(42)<=3.73767);
    EXPECT_ANY_THROW(ln(-1));
    EXPECT_ANY_THROW(ln(-5));
    EXPECT_ANY_THROW(ln(-42));
}

TEST(ABSVAL, functionality){
    EXPECT_EQ(AbsVal(42), 42);
    EXPECT_EQ(AbsVal(-42), 42);
    EXPECT_EQ(AbsVal(2.71), 2.71);
    EXPECT_EQ(AbsVal(-2.71), 2.71);
}
