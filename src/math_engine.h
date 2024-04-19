/** @file math_engine.h
 * @brief Abstraction of UI math logic
 * 
 * @author Jakub Miko 
*/
#pragma once
#include <vector>

/// @brief Abstraction of UI math logic
class MathEngine {
public:


    /// @brief Type defining last active mathematical operation
    enum class Operation {
        DEFAULT, RESULT, ADD, SUBTRACT, MULTIPLY, DIVIDE, FACTORIAL, LN, ABSVAL, POWER, ROOT
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
    void SendNumber(long double number);

    /// @brief After user clicked the equals sign, calculate the result of the whole expression
    void SendEquals();

    /// @brief User clicked the add button.
    void SendAdd();

    /// @brief User clicked the subtract button.
    void SendSubtract();

    /// @brief User clicked the multiply button.
    void SendMultiply();

    /// @brief User clicked the Power button
    void SendPower();

    /// @brief User clicked the Root button
    void SendRoot();

    /// @brief User clicked the divide button.
    void SendDivide();

    /// @brief User clicked the factorial button.
    void SendFactorial();

    /// @brief User clicked the ln button.
    void Sendln();

    /// @brief User clicked the ABS button.
    void SendAbsVal();

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
    void EndContext();

    /// @brief Get the context stack, needed to display the equation
    /// @return context stack @ref Context
    const std::vector<Context>& GetContextStack() const;

private:

    /// @brief Stack of paranthesis (@ref Context), enabling nested paranthesis
    std::vector<Context> context_stack; 
};