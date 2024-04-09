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
    unsigned long min_OF=1;//lowest whole number that tha factorial function cannot take as an input
    long long int fact;	   //factrial of min_OF
/*This loop increments the value of min_OF until it's factrial overflows
 *  or it exceeds the limits of ulong*/
    for (fact=1; fact<=ULONG_MAX/min_OF; min_OF++){
	if (fact<0) break;//if fact overflows the result is negative
	fact=fact*min_OF;
    }
    for(long i=min_OF; i<100; i+=10){
	EXPECT_ANY_THROW(Factorial(min_OF));
    }
}

TEST(LN, functionality){
    EXPECT_EQ(ln(1),0);
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
