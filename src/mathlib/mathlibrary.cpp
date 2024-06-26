#include "mathlibrary.h"
#include <stdexcept>
#include <cmath>

long double Add(long double a, long double b)
{
    return a+b;
}

long double Sub(long double a, long double b)
{
    return a-b;
}

long double Mult(long double a, long double b)
{
    return a*b;
}

long double Div(long double a, long double b)
{
    if (b == 0) {
        throw std::runtime_error("Can't divide by zero");
    }
    return a/b;
}

std::uint64_t Factorial(std::uint64_t n)
{
    if (n == 0 || n == 1) {
        return 1;
    }
    std::uint64_t result = 1;
    while (n > 1) {
        if (UINT64_MAX / result < n) {
            throw std::overflow_error("The number is too large to get the factorial");
        }
        result *= n;
        n--;
    }
    return result;
}

long double Power(long double a, std::uint64_t n)
{
    if (n == 0) {
        return 1;
    }
    long double result = 1;
    while (n > 0) {
        result *= a;
        n--;
        if (std::isinf(result)) {
            throw std::runtime_error("Result is infinite.");
        }
    }
    return result;
}

long double Root(long double a, std::uint64_t n)
{
    if ((n%2) == 0 && (a < 0)) {
        throw std::runtime_error("Negative number cannot have even root");
    }
    if (n == 0) {
        throw std::runtime_error("Root exponent cannot be zero");
    }
    if (a > 0) {
        return std::pow(a, 1.0 / static_cast<long double>(n));
    } else {
         return -std::pow(-a, 1.0 / static_cast<long double>(n));
    }
}

long double ln(long double a)
{
    if (a <= 0) {
        throw std::runtime_error("Input must be a positive number");
    }
    return std::log(a);
}

long double AbsVal(long double a)
{
    return std::abs(a);
}

long double Sine(long double a)
{
    return std::sin(a);
}

long double Cosine(long double a)
{
    return std::cos(a);
}

long double Tangent(long double a)
{
    return std::tan(a);
}