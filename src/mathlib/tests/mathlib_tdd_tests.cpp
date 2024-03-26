/**
 * @file mathlib_tdd_tests.cpp
 * @author Nikola Jordanov
 *
 * @brief implementace testu test driven development
 */

#include "mathlibrary.h"

#include <gtest/gtest.h>

TEST(ADD, natural_numbers){
    EXPECT_EQ(Add(36, 6), 42);
    EXPECT_EQ(Add(45, 55), 100);
    EXPECT_EQ(Add(12345678, 9876543), 22222221);
}

TEST(ADD, whole_numbers){
   EXPECT_EQ(Add(-2, 3), 1);
   EXPECT_EQ(Add(-4, -5), -9);
   EXPECT_EQ(Add(-100, 100), 0);
   EXPECT_EQ(Add(-4556, -23454), −28010);
}

TEST(ADD, real_numbers){
   EXPECT_EQ(Add(4.2, 6.9), 11.1);
   EXPECT_EQ(Add(35.45, 34.55), 70.00);
   EXPECT_EQ(Add(-23.5, 33,6), 10.1);
   EXPECT_EQ(Add(45632.543422, 112334567.4555), 112380199.998922);
}

