/**
 * @file mathlib_tdd_tests.cpp
 * @author Nikola Jordanov
 *
 * @brief implementace testu test driven development
 */

#include "mathlibrary.h"

#include <gtest/gtest.h>

TEST(ADD, natural_numbers){
    EXPECT_DOUBLE_EQ(Add(36, 6), 42);
    EXPECT_DOUBLE_EQ(Add(45, 55), 100);
    EXPECT_DOUBLE_EQ(Add(12345678, 9876543), 22222221);
}

TEST(ADD, whole_numbers){
    EXPECT_DOUBLE_EQ(Add(-2, 3), 1);
    EXPECT_DOUBLE_EQ(Add(-4, -5), -9);
    EXPECT_DOUBLE_EQ(Add(-100, 100), 0);
    EXPECT_DOUBLE_EQ(Add(-4556, -23454), -28010);
}

TEST(ADD, real_numbers){
    EXPECT_DOUBLE_EQ(Add(4.2, 6.9), 11.1);
    EXPECT_DOUBLE_EQ(Add(35.45, 34.55), 70.00);
    EXPECT_DOUBLE_EQ(Add(-23.5, 33.6), 10.1);
    EXPECT_DOUBLE_EQ(Add(45632.543422, 112334567.4555), 112380199.998922);
}

TEST(SUB, natural_numbers){
    EXPECT_DOUBLE_EQ(Sub(100, 58), 42);
    EXPECT_DOUBLE_EQ(Sub(54544, 54544), 0);
    EXPECT_DOUBLE_EQ(Sub(1222345667, 1123476), 1221222191);
}

TEST(SUB, whole_numbers){
    EXPECT_DOUBLE_EQ(Sub(-23, 44), -67);
    EXPECT_DOUBLE_EQ(Sub(43, -23), 66);
    EXPECT_DOUBLE_EQ(Sub(-122345, 22345), -144690);
    EXPECT_DOUBLE_EQ(Sub(2234586, 3335467), -1100881);
}

TEST(SUB, real_numbers){
    EXPECT_DOUBLE_EQ(Sub(334.4456, 4567.45), -4233.0044);
    EXPECT_DOUBLE_EQ(Sub(-34.2323, 0.6666), -34.8989);
    EXPECT_DOUBLE_EQ(Sub(440567.66504, 3345.55565), 437222.10939);
}

TEST(MULT, natural_numbers){
    EXPECT_DOUBLE_EQ(Mult(42, 96), 4032);
    EXPECT_DOUBLE_EQ(Mult(110, 234), 25740);
    EXPECT_DOUBLE_EQ(Mult(2222, 45456), 101003232);
}

TEST(MULT, whole_numbers){
    EXPECT_DOUBLE_EQ(Mult(-22, 33), -726);
    EXPECT_DOUBLE_EQ(Mult(-55, -303), 16665);
    EXPECT_DOUBLE_EQ(Mult(222345, -333232), -74092469040);
    EXPECT_DOUBLE_EQ(Mult(-33434, -33322), 1114087748);
}

TEST(MULT, real_numbers){
    EXPECT_DOUBLE_EQ(Mult(11234.2234, 2234.44), 25102198.133896);
    EXPECT_DOUBLE_EQ(Mult(-22323.23223, 2323.445), -51866802.30863235);
    EXPECT_DOUBLE_EQ(Mult(-223.2223, -22546.34), 5032845.871382);
}

TEST(DIV, natural_nubers){
    EXPECT_TRUE((Div(4456, 22)>=202.54545)&&(Div(4456, 22)<=202.54546));
    EXPECT_TRUE((Div(1024, 16)>=64.00000)&&(Div(1024, 16)<=64.00001));
    EXPECT_TRUE((Div(334536, 334)>=1001.60479)&&(Div(334536, 334)<=1001.60480));
}

TEST(DIV, whole_numbers){
    EXPECT_TRUE((Div(-2233, 445)<=-5.01797)&&(Div(-2233, 445)>=-5.01798));
    EXPECT_TRUE((Div(-55430, -123)>=450.65040)&&(Div(-55430, -123)<=450.65041));
    EXPECT_ANY_THROW(Div(34, 0));
}

TEST(DIV, real_numbers){
    EXPECT_TRUE((Div(3345.556, 2234.90)>=1.49696)&&(Div(3345.556, 2234.90)<=1.49697));
    EXPECT_TRUE((Div(-325.5554, 0.332)<=-980.58855)&&(Div(-325.5554, 0.332)>=-980.58856));
    EXPECT_TRUE((Div(1, -334.45)<=-0.00298)&&(Div(1, -334.45)>=-0.00299));
}

TEST(FACTORIAL, suite){
    EXPECT_EQ(Factorial(5), 120);
    EXPECT_EQ(Factorial(1), 1);
    EXPECT_EQ(Factorial(0), 1);
}

TEST(POWER, suite){
    EXPECT_DOUBLE_EQ(Power(2, 10), 1024);
    EXPECT_DOUBLE_EQ(Power(34, 5), 45435424);
    EXPECT_DOUBLE_EQ(Power(42, 0), 1);
    EXPECT_DOUBLE_EQ(Power(-42, 4), 3111696);
    EXPECT_DOUBLE_EQ(Power(-42, 5), -130691232);
}

TEST(ROOT, suite){
    EXPECT_DOUBLE_EQ(Root(144, 2), 12);
    EXPECT_TRUE((Root(4435, 3)>=16.42975)&&(Root(4435, 3)<=16.42976));
    EXPECT_TRUE((Root(-3342, 5)<=-5.06758)&&(Root(-3342, 5)>=-5.06759));
    EXPECT_ANY_THROW(Root(-42, 2));
    EXPECT_ANY_THROW(Root(42, 0));
}
