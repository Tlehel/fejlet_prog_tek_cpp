//
// Created by Lehel on 2025-09-16.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <utility>
#include <string>

int countBits(int);
bool setBit(int&, int);
double mean(const double array[], int );
double stddev(const double array[], int );

std::pair<double, double> max2(double array[], int );

int countWords(const std::string& text);
std::string code(const std::string& text);
std::string decode(const std::string& text);

#endif //FUNCTIONS_H