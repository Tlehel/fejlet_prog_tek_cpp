//
// Created by Lehel on 2025-09-16.
//

#include "functions.h"

#include <cmath>
#include <iostream>
#include <sstream>
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
double mean(const double array[], int numElements) {
    if (!numElements) return NAN;
    double result = 0;
    fort(numElements) {
        result += array[i];
    }
    return result/numElements;
}
double stddev(const double array[], int numElements) {
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
int countWords(const std::string& text) {
    std::istringstream txt(text);
    std::string word;
    int count = 0;
    while(txt >> word) count++;
    return count;
}
std::string code(const std::string& text) {
    std::istringstream txt(text);
    char c;
    std::string words;
    while (txt >> c) {
        if (c>=65 && c<90) {
            c++;
        }
        else if(c==90) {
            c=65;
        }
        if (c>=97 && c<122) {
            c++;
        }
        else if (c==122) {
            c=97;
        }
        words +=c;
    }
    return words;
}
std::string decode(const std::string& text) {
    std::istringstream txt(text);
    char c;
    std::string words;
    while (txt >> c) {
        if (c>65 && c<=90) {
            c--;
        }
        else if(c==65) {
            c=90;
        }
        if (c>97 && c<=122) {
            c--;
        }
        else if (c==97) {
            c=122;
        }
        words +=c;
    }
    return words;
}
