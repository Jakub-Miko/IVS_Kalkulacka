#include <gtest/gtest.h>
#include <math_engine.h>
#include <mathlib/include/mathlibrary.h>

class MathEngineTests : public testing::Test {
public:
    MathEngine engine;
};



TEST_F(MathEngineTests, AdditionSubtraction) {
    engine.SendNumber(5);
    engine.SendAdd();
    engine.SendNumber(15);
    engine.SendEquals();
    EXPECT_TRUE(engine.IsAccumulatorResult());
    EXPECT_TRUE(engine.IsResultAvailable());
    EXPECT_EQ(engine.GetAccumulator(), 20);
    engine.SendSubtract();
    engine.SendNumber(10);
    engine.SendEquals();
    EXPECT_TRUE(engine.IsAccumulatorResult());
    EXPECT_TRUE(engine.IsResultAvailable());
    EXPECT_EQ(engine.GetAccumulator(), 10);
}

TEST_F(MathEngineTests, AdditionSubtraction2) {
    engine.SendNumber(5.56);
    engine.SendAdd();
    engine.SendNumber(20.476);
    engine.SendEquals();
    EXPECT_TRUE(engine.IsAccumulatorResult());
    EXPECT_TRUE(engine.IsResultAvailable());
    EXPECT_DOUBLE_EQ(engine.GetAccumulator(), 26.036);
    engine.SendSubtract();
    engine.SendNumber(111.12);
    engine.SendEquals();
    EXPECT_TRUE(engine.IsAccumulatorResult());
    EXPECT_TRUE(engine.IsResultAvailable());
    EXPECT_DOUBLE_EQ(engine.GetAccumulator(), -85.084);
}

TEST_F(MathEngineTests, MultiplicationDivision) {
    engine.SendNumber(5.56);
    engine.SendMultiply();
    engine.SendNumber(20.476);
    engine.SendEquals();
    EXPECT_TRUE(engine.IsAccumulatorResult());
    EXPECT_TRUE(engine.IsResultAvailable());
    EXPECT_DOUBLE_EQ(engine.GetAccumulator(), 113.84656);
    engine.SendDivide();
    engine.SendNumber(20.476);
    engine.SendEquals();
    EXPECT_TRUE(engine.IsAccumulatorResult());
    EXPECT_TRUE(engine.IsResultAvailable());
    EXPECT_DOUBLE_EQ(engine.GetAccumulator(), 5.56);
}

TEST_F(MathEngineTests, Factorial) {
    engine.SendNumber(5);
    engine.SendFactorial();
    engine.SendEquals();
    EXPECT_TRUE(engine.IsAccumulatorResult());
    EXPECT_TRUE(engine.IsResultAvailable());
    EXPECT_DOUBLE_EQ(engine.GetAccumulator(), 120);
}

TEST_F(MathEngineTests, AbsVal) {
    engine.SendNumber(-5);
    engine.SendAbsVal();
    engine.SendEquals();
    EXPECT_TRUE(engine.IsAccumulatorResult());
    EXPECT_TRUE(engine.IsResultAvailable());
    EXPECT_DOUBLE_EQ(engine.GetAccumulator(), 5);
    engine.ClearAccumulator();
    engine.SendNumber(5);
    engine.SendAbsVal();
    engine.SendEquals();
    EXPECT_TRUE(engine.IsAccumulatorResult());
    EXPECT_TRUE(engine.IsResultAvailable());
    EXPECT_DOUBLE_EQ(engine.GetAccumulator(), 5);
}

TEST_F(MathEngineTests, ln) {
    engine.SendNumber(constants::const_e);
    engine.Sendln();
    engine.SendEquals();
    EXPECT_TRUE(engine.IsAccumulatorResult());
    EXPECT_TRUE(engine.IsResultAvailable());
    EXPECT_DOUBLE_EQ(engine.GetAccumulator(), 1);
}

TEST_F(MathEngineTests, Braces) {
    engine.SendNumber(constants::const_e);
    engine.Sendln();
    engine.SendAdd();
    engine.StartContext();
    engine.SendNumber(5);
    engine.SendMultiply();
    engine.SendNumber(4);
    engine.EndContext();
    engine.SendEquals();
    EXPECT_TRUE(engine.IsAccumulatorResult());
    EXPECT_TRUE(engine.IsResultAvailable());
    EXPECT_DOUBLE_EQ(engine.GetAccumulator(), 21);
}