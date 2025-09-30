//
// Created by Lehel on 2025-09-30.
//

#include "Point.h"

#include <cmath>

Point::Point(int x, int y) {
    this->x=x;
    this->y=y;
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}
double Point::distanceTo(const Point &point) const {
    return std::sqrt(pow(point.getX()-this->getX(),2)-pow(point.getY()-this->getY(),2));
}


