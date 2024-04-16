#pragma once



class MathEngine {
public:

    enum class Operation {
        DEFAULT, RESULT, ADD, SUBTRACT, MULTIPLY, DIVIDE, FACTORIAL, LN, ABSVAL
    };

public:

    MathEngine();

    MathEngine(const MathEngine& ref) = delete;
    MathEngine(MathEngine&& ref) = delete;
    MathEngine& operator=(const MathEngine& ref) = delete;
    MathEngine& operator=(MathEngine&& ref) = delete;

    void SendNumber(long double number);

    void SendEquals();

    void SendAdd();

    void SendSubtract();

    void SendMultiply();

    void SendDivide();

    void SendFactorial();

    void Sendln();

    void SendAbsVal();

    long double GetAccumulator() const;

    bool IsAccumulatorResult() const ;

private:
    long double accumulator;
    Operation last_op;
};