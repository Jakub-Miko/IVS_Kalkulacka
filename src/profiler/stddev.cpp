/**
 * @file stddev.cpp
 * @brief Calculation of sample standard deviation
 * 
 * @author Alexander Žikla
*/

#include <iostream>
#include <vector>
#include "mathlibrary.h"


/**
 * @param arr Vector of long double numbers
 * @return Arithmetic mean
*/
long double CalculateMean(const std::vector<long double>& arr)
{
    long double sum = 0;
    for (long double number : arr) {
        sum = Add(sum, number);
    }
    return Div(sum, arr.size());
}

/**
 * @param arr Vector of long double numbers
 * @return Sample Standard Deviation
*/
long double CalculateSampleStandardDeviation(const std::vector<long double>& arr)
{
    long double mean = CalculateMean(arr);
    long double deviation = 0;
    for (long double number : arr) {
        deviation = Add(deviation, Power(Sub(number, mean), 2) );
    }
    deviation = Div(deviation, arr.size());
    return Root(deviation, 2);
}

int main()
{
    long double number;
    std::vector<long double> arr;
    std::cout << "Enter numbers: " << std::endl;
    while (std::cin >> number) {
        arr.push_back(number);
    }

    if (arr.empty()) {
        std::cerr << "No numbers entered." << std::endl;
        return 1;
    }

    long double deviation = CalculateSampleStandardDeviation(arr);
    std::cout << deviation << std::endl;

    return 0; 
}