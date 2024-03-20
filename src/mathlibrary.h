#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

/**
 * Function to add 2 numbers
 * 
 * @param a First number
 * @param b Second number
 * @return Sum of 2 numbers
*/
double Add(double a, double b);

/**
 * Function to subtract 2 numbers
 * 
 * @param a First number
 * @param b Second number
 * @return Subtraction of 2 numbers
*/
double Sub(double a, double b);

/**
 * Function to multiply 2 numbers
 * 
 * @param a First number
 * @param b Second number
 * @return Multiplication of 2 numbers
*/
double Mult(double a, double b);

/**
 * Function to divide 2 numbers
 * 
 * @param a First number
 * @param b Second number
 * @return Division of 2 numbers
*/
double Div(double a, double b);

/**
 * Factorial function
 * 
 * @param N (natural) Number
 * @return Multiplication of numbers from 1 to N
*/
int Factorial(int N);

/**
 * Function to exponentiate a number
 * 
 * @param a First number
 * @param N Second (natural) number
 * @return Repeated multiplication of the number "a" N times
*/
double Exponentiation(double a, int N);

/**
 * Function to root a number
 * 
 * @param a First number
 * @param N Second (natural) number
 * @return A number which, when multiplied by itself N-times, gives the original number
*/
double Root(double a, int N);


#endif /***  End of MATHLIBRARY_H ***/