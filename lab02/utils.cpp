//
// Created by Lehel on 2025-09-23.
//

#include "utils.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <bits/random.h>

#include "def.h"

double distance(const Point& a, const Point& b){
return sqrt(std::pow(a.getX() - b.getX(),2) + std::pow(a.getY() - b.getY(),2));
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d) {
    if (a.getX()==b.getX()==c.getX()==d.getX() && a.getY()==b.getY()==c.getY()==d.getY()) return false;
    if (distance(a,b)==distance(c,d)) {
        if (distance(a,c)==distance(b,d)) {
            if (distance(a,c)==distance(b,d)) {
                return true;
            }
        }
    }
    if (distance(c,b)==distance(a,d)) {
        if (distance(a,c)==distance(b,d)) {
            if (distance(c,d)==distance(a,b)) {
                return true;
            }
        }
    }
    return false;
}

void testIsSquare(const char * filename) {
    std::ifstream file(filename);
    if(!file.is_open()) return;
    while (!file.eof()) {
        Point *pointa[4]={};
        fort(4) {
            int x,y;
            file>>x>>y;
            pointa[i] = new Point(x,y);
        }
        if (isSquare(*pointa[0],*pointa[1],*pointa[2],*pointa[3])) {
            std::cout << "yaaaaa" <<std::endl;
        }
    }
    std::cout << ex_end;
}

Point* createArray(int numPoints) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,2000);

    auto *points = new Point(numPoints);

    fort(numPoints) {
        int y;
        int x = dis(gen);
        y = dis(gen);
        auto* p = new Point(x,y);
        points[i] = *p;
    }
    return points;
}

void printArray(Point* points, int numPoints){
    fort(numPoints) {
        points[i].print();
    }
}

std::pair<Point, Point> closestPoints(Point* points, int numPoints) {
    int minDist = 2001;
    fort(numPoints) {
        for (int j = i+1)
    }
}





