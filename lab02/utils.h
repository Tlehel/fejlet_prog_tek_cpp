//
// Created by Lehel on 2025-09-23.
//

#ifndef UTILS_H
#define UTILS_H
#include <utility>

#include "Point.h"

double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point&
d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);

std::pair<Point, Point> closestPoints(Point* points, int numPoints);



#endif //UTILS_H
