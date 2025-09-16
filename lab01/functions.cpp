//
// Created by Lehel on 2025-09-16.
//

#include "functions.h"

#include <cmath>
#include "def.h"

int countBits(int number) {
    int result = 0;

    while (number) {
        result += number & 1;
        number >>= 1;
    }

    return result;
}
bool setBit(int& number, int order) {
    if (order>31) return false;
    int setter = 1;
    for (int i=1;i<order;i++) {
        setter <<= 1;
    }
    number = number | setter;
    return true;
}
double mean(double array[], int numElements) {
    double result = 0;
    fort(numElements) {
        result += array[i];
    }
    if (!result) return NAN;
    return result/numElements;
}
double stddev(double array[], int numElements) {
    double result = 0;
    fort(numElements) {
        result += array[i];
    }
    if (!result) return NAN;
    result /= numElements;
    double dev = 0;
    fort(numElements) {
        dev += (array[i]-result)*(array[i]-result);
    }
    return sqrt(dev/(numElements));
}
std::pair<double, double> max2(double array[], int numElements) {
    
}
