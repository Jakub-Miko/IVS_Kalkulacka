#include "math_engine.h"
#include <mathlibrary.h>
#include <stdexcept>

MathEngine::MathEngine() : context_stack()
{
    Context context;
    context.accumulator = 0;
    context.last_op = Operation::DEFAULT;
    context_stack.push(std::move(context));
}

void MathEngine::SendNumber(long double number)
{
    long double result = 0;
    long double accumulator = context_stack.top().accumulator;
    switch (context_stack.top().last_op)
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
    context_stack.top().accumulator = result;
}

void MathEngine::SendEquals()
{
    while(context_stack.size() > 1) {
        context_stack.top().last_op = Operation::RESULT;
        EndContext();
    }
    context_stack.top().last_op = Operation::RESULT;
}

void MathEngine::SendAdd()
{
    context_stack.top().last_op = Operation::ADD;
}

void MathEngine::SendSubtract()
{
    context_stack.top().last_op = Operation::SUBTRACT;
}

void MathEngine::SendMultiply()
{
    context_stack.top().last_op = Operation::MULTIPLY;
}

void MathEngine::SendDivide()
{
    context_stack.top().last_op = Operation::DIVIDE;
}

void MathEngine::SendFactorial()
{
     context_stack.top().accumulator = Factorial(context_stack.top().accumulator);
    context_stack.top().last_op = Operation::RESULT;
}

void MathEngine::Sendln()
{
    context_stack.top().accumulator = ln(context_stack.top().accumulator);
    context_stack.top().last_op = Operation::RESULT;
}

void MathEngine::SendAbsVal()
{
    context_stack.top().accumulator = AbsVal(context_stack.top().accumulator);
    context_stack.top().last_op = Operation::RESULT;
}

long double MathEngine::GetAccumulator() const
{
    return context_stack.top().accumulator;
}

bool MathEngine::IsAccumulatorResult() const
{
    return context_stack.top().last_op == Operation::RESULT;
}

bool MathEngine::IsResultAvailable() const
{
    return (context_stack.size() == 1) && (context_stack.top().last_op == Operation::RESULT);
}

void MathEngine::ClearAccumulator()
{
    context_stack.top().accumulator = 0;
    context_stack.top().last_op = Operation::DEFAULT;
}

void MathEngine::ResetAllContexts()
{
    while(context_stack.size() > 0) {
        context_stack.pop();
    }
    Context context;
    context.accumulator = 0;
    context.last_op = Operation::DEFAULT;
    context_stack.push(std::move(context));
}

void MathEngine::StartContext()
{
    Context context;
    context.accumulator = 0;
    context.last_op = Operation::DEFAULT;
    context_stack.push(std::move(context));
}

void MathEngine::EndContext()
{
    if(context_stack.size() <= 1) {
        throw std::runtime_error("Can't pop default context");
    }
    long double accumulator_temp = context_stack.top().accumulator;
    context_stack.pop();
    SendNumber(accumulator_temp);
}
