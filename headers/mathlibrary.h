#pragma once

/**
 * @param A First number
 * @param B Second number
 * @return Sum of 2 numbers
*/
long double Add(long double A, long double B);

/** 
 * @param A Minuend
 * @param B Subtrahend
 * @return Subtraction of 2 numbers
*/
long double Sub(long double A, long double B);

/**
 * @param A First factor
 * @param B Second factor
 * @return Multiplication of 2 numbers
*/
long double Mult(long double A, long double B);

/**
 * @param A Numerator 
 * @param B Denominator
 * @return Division of 2 numbers
*/
long double Div(long double A, long double B);

/**
 * @param N (natural) Number
 * @return Multiplication of numbers from 1 to N
*/
long unsigned int Factorial(long unsigned int N);

/**
 * @param A Base number
 * @param N Exponent (natural number)
 * @return Repeated multiplication of the number "A" N-times
*/
long double Power(long double A, long unsigned int N);

/**
 * @param A Radicand (If "N" is even, "A" has to be positive)
 * @param N Index (natural number)
 * @return A number which, when multiplied by itself N-times, gives the original number
*/
long double Root(long double A, long unsigned int N);


