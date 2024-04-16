#include "math_engine.h"
#include <mathlibrary.h>
#include <stdexcept>

MathEngine::MathEngine() : last_op(Operation::DEFAULT), accumulator(0)
{
}

void MathEngine::SendNumber(long double number)
{
    long double result = 0;
    switch (last_op)
    {
    case Operation::ADD:
        result = accumulator + number;
        break;
    case Operation::SUBTRACT:
        result = accumulator - number;
        break;
    case Operation::MULTIPLY:
        result = accumulator * number;
        break;
    case Operation::DIVIDE:
        result = accumulator / number;
        break;
    case Operation::DEFAULT:
        result = number;
        break;
    case Operation::RESULT:
        result = accumulator;
        break;
    default:
        throw std::runtime_error("Unsupported mathematical operation");
        break;
    }
    accumulator = result;
}

void MathEngine::SendEquals()
{
    last_op = Operation::RESULT;
}

void MathEngine::SendAdd()
{
    last_op = Operation::ADD;
}

void MathEngine::SendSubtract()
{
    last_op = Operation::SUBTRACT;
}

void MathEngine::SendMultiply()
{
    last_op = Operation::MULTIPLY;
}

void MathEngine::SendDivide()
{
    last_op = Operation::DIVIDE;
}

void MathEngine::SendFactorial()
{
    last_op = Operation::FACTORIAL;
}

void MathEngine::Sendln()
{
    accumulator = ln(accumulator);
    last_op = Operation::RESULT;
}

void MathEngine::SendAbsVal()
{
    accumulator = AbsVal(accumulator);
    last_op = Operation::RESULT;
}

long double MathEngine::GetAccumulator() const
{
    return accumulator;
}

bool MathEngine::IsAccumulatorResult() const
{
    return last_op == Operation::RESULT;
}
