#pragma once

/**
 * @param a First number
 * @param b Second number
 * @return Sum of 2 numbers
*/
long double Add(long double a, long double b);

/** 
 * @param a Minuend
 * @param b Subtrahend
 * @return Subtraction of 2 numbers
*/
long double Sub(long double a, long double b);

/**
 * @param a First factor
 * @param b Second factor
 * @return Multiplication of 2 numbers
*/
long double Mult(long double a, long double b);

/**
 * @param a Numerator 
 * @param b Denominator
 * @return Division of 2 numbers
*/
long double Div(long double a, long double b);

/**
 * @param n (natural) Number
 * @return Multiplication of numbers from 1 to n
*/
unsigned long Factorial(unsigned long n);

/**
 * @param a Base number
 * @param n Exponent (natural number)
 * @return a to the power of n
*/
long double Power(long double a, unsigned long n);

/**
 * @param a Radicand (If "N" is even, "A" has to be positive)
 * @param n Index (natural number)
 * @return n-th root of number a 
*/
long double Root(long double a, unsigned long n);


