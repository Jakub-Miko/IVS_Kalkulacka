#include "math_engine.h"
#include <mathlibrary.h>
#include <stdexcept>

MathEngine::MathEngine() : context_stack()
{
    Context context; 
    context.accumulator = 0;
    context.last_op = Operation::DEFAULT;
    context_stack.push_back(std::move(context));
}

void MathEngine::SendNumber(long double number)
{
    // based on the last submitted operation, perform a calculation with the accumulator and the input number
    // and then save the result back into the accumulator
    long double result = 0;
    long double accumulator = context_stack.back().accumulator;
    switch (context_stack.back().last_op)
    {
    case Operation::ADD:
        result = Add(accumulator, number);
        break;
    case Operation::SUBTRACT:
        result = Sub(accumulator, number);
        break;
    case Operation::MULTIPLY:
        result = Mult(accumulator, number);
        break;
    case Operation::DIVIDE:
        result = Div(accumulator, number);
        break;
    case Operation::POWER:
        if(number < 0) throw std::runtime_error("Exponent cant be negative");
        result = Power(accumulator, number);
        break;
    case Operation::ROOT:
        result = Root(number, accumulator);
        break;
    case Operation::RESULT:
    case Operation::DEFAULT:
        result = number;
        break;
    default:
        throw std::runtime_error("Unsupported mathematical operation");
        break;
    }
    context_stack.back().accumulator = result;
}

void MathEngine::SendEquals()
{
    // Make sure to close all the paranthesis to get the final result
    while(context_stack.size() > 1) {
        context_stack.back().last_op = Operation::RESULT;
        EndContext();
    }
    context_stack.back().last_op = Operation::RESULT;
}

void MathEngine::SendAdd()
{
    context_stack.back().last_op = Operation::ADD;
}

void MathEngine::SendSubtract()
{
    context_stack.back().last_op = Operation::SUBTRACT;
}

void MathEngine::SendMultiply()
{
    context_stack.back().last_op = Operation::MULTIPLY;
}

void MathEngine::SendPower()
{
    context_stack.back().last_op = Operation::POWER;
}

void MathEngine::SendRoot()
{
    if(context_stack.back().accumulator == 0) throw std::runtime_error("0th root not allowed");
    if(context_stack.back().accumulator < 0) throw std::runtime_error("Exponent cant be negative");
    context_stack.back().last_op = Operation::ROOT;
}

void MathEngine::SendDivide()
{
    context_stack.back().last_op = Operation::DIVIDE;
}

void MathEngine::SendFactorial()
{
    if(context_stack.back().accumulator < 0) throw std::runtime_error("Factorial of negative numbers not allowed");
    // Unary operations only need the accumulator, so their calculation doesnt need to be deffered
    context_stack.back().accumulator = Factorial(context_stack.back().accumulator);
    // After the calculation is complete, since no other operand is awaited
    // we can consider the value to be a complete result
    context_stack.back().last_op = Operation::RESULT; 
}

void MathEngine::Sendln()
{
    // Unary operations only need the accumulator, so their calculation doesnt need to be deffered
    context_stack.back().accumulator = ln(context_stack.back().accumulator);
    // After the calculation is complete, since no other operand is awaited
    // we can consider the value to be a complete result
    context_stack.back().last_op = Operation::RESULT;
}

void MathEngine::SendAbsVal()
{
    // Unary operations only need the accumulator, so their calculation doesnt need to be deffered
    context_stack.back().accumulator = AbsVal(context_stack.back().accumulator);
    // After the calculation is complete, since no other operand is awaited
    // we can consider the value to be a complete result
    context_stack.back().last_op = Operation::RESULT;
}

void MathEngine::SendSine()
{
    // Unary operations only need the accumulator, so their calculation doesnt need to be deffered
    context_stack.back().accumulator = Sine(context_stack.back().accumulator);
    // After the calculation is complete, since no other operand is awaited
    // we can consider the value to be a complete result
    context_stack.back().last_op = Operation::RESULT;
}

void MathEngine::SendCosine()
{
    // Unary operations only need the accumulator, so their calculation doesnt need to be deffered
    context_stack.back().accumulator = Cosine(context_stack.back().accumulator);
    // After the calculation is complete, since no other operand is awaited
    // we can consider the value to be a complete result
    context_stack.back().last_op = Operation::RESULT;
}

void MathEngine::SendTangent()
{
    // Unary operations only need the accumulator, so their calculation doesnt need to be deffered
    context_stack.back().accumulator = Tangent(context_stack.back().accumulator);
    // After the calculation is complete, since no other operand is awaited
    // we can consider the value to be a complete result
    context_stack.back().last_op = Operation::RESULT;
}

long double MathEngine::GetAccumulator() const
{
    return context_stack.back().accumulator;
}

bool MathEngine::IsAccumulatorResult() const
{
    return context_stack.back().last_op == Operation::RESULT;
}

bool MathEngine::IsResultAvailable() const
{
    // For a complete result, the accumulator result needs to be the only one (all paranthesis need to be closed)
    return (context_stack.size() == 1) && (context_stack.back().last_op == Operation::RESULT);
}

void MathEngine::ClearAccumulator()
{
    context_stack.back().accumulator = 0;
    context_stack.back().last_op = Operation::DEFAULT;
}

void MathEngine::ResetAllContexts()
{
    while(context_stack.size() > 0) {
        context_stack.pop_back();
    }
    Context context;
    context.accumulator = 0;
    context.last_op = Operation::DEFAULT;
    context_stack.push_back(std::move(context));
}

void MathEngine::StartContext()
{
    // By moving the accumulator and last_op up the stack, we start a fresh calculations, 
    // while retaining information about the current one.
    Context context;
    context.accumulator = 0;
    context.last_op = Operation::DEFAULT;
    context_stack.push_back(std::move(context));
}

void MathEngine::EndContext()
{
    // After the paranthesis ends, we take the result of the paranthesis, and restore the original operation
    // before the paranthesis, supplying the paranthesis result as an input
    if(context_stack.size() <= 1) {
        throw std::runtime_error("Can't pop default context");
    }
    long double accumulator_temp = context_stack.back().accumulator;
    context_stack.pop_back();
    SendNumber(accumulator_temp);
}

const std::vector<MathEngine::Context>& MathEngine::GetContextStack() const
{
    return context_stack;
}
