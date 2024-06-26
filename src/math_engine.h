/** @file math_engine.h
 * @brief Abstraction of UI math logic
 * 
 * @author Jakub Miko 
*/
#pragma once
#include <vector>
#include <string>

#define PRECISION_OF_NUMBER 12

/// @brief Abstraction of UI math logic
class MathEngine {
private:
    static const char* op_symbols[];

public:


    /// @brief Type defining last active mathematical operation
    enum class Operation {
        DEFAULT, RESULT, ADD, SUBTRACT, MULTIPLY, DIVIDE, FACTORIAL, LN, ABSVAL, POWER, ROOT
    };

    enum class Status {
        OK, ROUNDING
    };

    struct ReturnCode {
        Status status = Status::OK;
        const char* msg = nullptr;
    };

    /// @brief The current status of the operation and result of a paranthesis
    struct Context {
        long double accumulator; ///< result value of the current context
        Operation last_op; ///< last operation initiated on the context
    };

public:

    MathEngine();

    MathEngine(const MathEngine& ref) = delete;
    MathEngine(MathEngine&& ref) = delete;
    MathEngine& operator=(const MathEngine& ref) = delete;
    MathEngine& operator=(MathEngine&& ref) = delete;

    /// @brief Submit number entered by the user
    /// @param number the number submitted by the user
    /// @return Status indicating whether rounding happened withing the last operation
    ReturnCode SendNumber(long double number);

    /// @brief After user clicked the equals sign, calculate the result of the whole expression
    ReturnCode SendEquals();

    /// @brief User clicked the add button.
    void SendAdd();

    /// @brief User clicked the subtract button.
    void SendSubtract();

    /// @brief User clicked the multiply button.
    void SendMultiply();

    /// @brief User clicked the Power button
    /// Be Aware the exponent can only be an argument so rounding may occur (can be checked by the return value of send number)
    void SendPower();

    /// @brief User clicked the Root button
    /// Be Aware the exponent can only be an argument so rounding may occur (can be checked by the return value of send number)
    void SendRoot();

    /// @brief User clicked the divide button.
    void SendDivide();

    /// @brief User clicked the factorial button.
    /// Be Aware Factorial only takes integer arguments so rounding may occur
    /// @return Status indicating whether rounding happened withing this operation
    ReturnCode SendFactorial();

    /// @brief User clicked the ln button.
    void Sendln();

    /// @brief User clicked the ABS button.
    void SendAbsVal();

    /// @brief User clicked the SIN button.
    void SendSine();

    /// @brief User clicked the COS button.
    void SendCosine();

    /// @brief User clicked the TAN button.
    void SendTangent();

    /// @brief Get the current value of the accumulator (result from the current paranthesis)
    /// @return accumulator value
    long double GetAccumulator() const;

    /// @brief The value of the accumulator is the result, and no other operation is currently in progress
    /// @return Whether no operation is in progress on the current accumulator
    bool IsAccumulatorResult() const;

    /// @brief All stacks have been calculated and the accumulator contains the final result
    /// @return Whether the accumulator contains the final result (combination of all the paranthesis)
    bool IsResultAvailable() const;
    
    /// @brief Clear the current accumulator and reset the operation to default
    void ClearAccumulator();

    /// @brief Clear all the contexts (paranthesis)
    void ResetAllContexts();

    /// @brief Start a paranthesis
    void StartContext();

    /// @brief End a paranthesis
    /// @return
    ReturnCode EndContext();

    /// @brief Get the context stack, needed to display the equation
    /// @return context stack @ref Context
    const std::vector<Context>& GetContextStack() const;

    /// @brief Gets the result display containg all pending(unclosed) contexts(paranthesis)
    std::string GetDisplay() const;

private:

    /// @brief Stack of paranthesis (@ref Context), enabling nested paranthesis
    std::vector<Context> context_stack; 
};
