/**
 * @file mathlib_goniometry_test.cpp
 * @author Nikola Jordanov
 *
 * @brief implementation of tests for goniometry functions
 */

#include "mathlibrary.h"
#include <math.h>
#include <gtest/gtest.h>


TEST(SIN, suite){
    EXPECT_TRUE(Sine(0)>= 0.00000 && Sine(0)<0.00001);
    EXPECT_TRUE(Sine(M_PI)> -0.00001 && Sine(M_PI)<0.00001);
    EXPECT_TRUE(Sine(M_PI/2)> 0.99999 && Sine(M_PI/2)<1.00001);
    EXPECT_TRUE(Sine(3*M_PI/2)< -0.99999 && Sine(3*M_PI/2)> -1.00001);
    EXPECT_TRUE(Sine(3)>=0.14112 && Sine(3)<0.14113);
}

TEST(COSINE, suite){
    EXPECT_TRUE(Cosine(0)>= 1.00000 && Cosine(0)<1.00001);
    EXPECT_TRUE(Cosine(M_PI)< -0.99999 && Cosine(M_PI)> -1.00001);
    EXPECT_TRUE(Cosine(M_PI/2)> -0.00001 && Cosine(M_PI/2)<0.00001);
    EXPECT_TRUE(Cosine(3*M_PI/2)> -0.00001 && Cosine(3*M_PI/2)<0.00001);
    EXPECT_TRUE(Cosine(2)<= -0.41614 && Cosine(2)> -0.41615);
}

TEST(TANGENT, suite){
    EXPECT_TRUE(Tangent(0)>= 0.00000 && Tangent(0)<0.00001 );
    EXPECT_TRUE(Tangent(M_PI)> -0.00001 && Tangent(M_PI)<0.00001);
    EXPECT_TRUE(Tangent(1)>=1.55740 && Tangent(1)<1.55741);
    EXPECT_TRUE(Tangent(2)<= -2.18503 && Tangent(2)> -2.18504);
}
