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
    if (!numElements) return NAN;
    double result = 0;
    fort(numElements) {
        result += array[i];
    }
    return result/numElements;
}
double stddev(double array[], int numElements) {
    if (!numElements) return NAN;
    double result = 0;
    fort(numElements) {
        result += array[i];
    }
    result /= numElements;
    double dev = 0;
    fort(numElements) {
        dev += (array[i]-result)*(array[i]-result);
    }
    return sqrt(dev/(numElements));
}
std::pair<double, double> max2(double array[], int numElements) {
    if (!numElements) return std::make_pair(NAN,NAN);
    if (numElements==1) return std::make_pair(array[0],array[0]);
    double maxn1,maxn2;
    if (array[0]>array[1]) {
        maxn1 = array[0];
        maxn2 = array[1];
    }
    else {
        maxn2 = array[0];
        maxn1 = array[1];
    }
    for (int i=2;i<numElements;i++) {
        if (array[i]>maxn1) {
            maxn2 = maxn1;
            maxn1 = array[i];
            continue;
        }
        if (array[i]>maxn2 && array[i]!=maxn1) {
            maxn2 = array[i];
        }
    }
    return std::make_pair(maxn1,maxn2);
}
