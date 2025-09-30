//
// Created by Lehel on 2025-09-30.
//

#include "PointSet.h"

#include <algorithm>
#include <random>
#include <iostream>

PointSet::PointSet(int n) {
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd()); // Mersenne Twister algorithm to generate random numbers
    uniform_int_distribution<int> dist(0, M); // return a number in the given range
    for(int i=0;i<n;i++) {
        int x = dist(mt);
        int y = dist(mt);
        points.emplace_back(x,y);
    }
    computeDistances();
}
void PointSet::computeDistances() {
    for (int i=0;i<points.size();i++) {
        for (int j=i+1;j<points.size();j++) {
            distances.emplace_back(points[i].distanceTo(points[j]));
        }
    }
}
double PointSet::maxDistance() const {
    return *max_element(distances.begin(),distances.end());
}
double PointSet::minDistance() const {

    return *min_element(distances.begin(),distances.end());;
}
int PointSet::numDistances() const {
    return static_cast<int>(distances.size());
}
void PointSet::printDistances() const {
    for (auto v:distances) {
        std::cout << v << std::endl;
    }
}
void PointSet::printPoints() const {
    for (auto v:points) {
        std::cout << v.getX() << " " << v.getY() <<std::endl;
    }
}
void PointSet::sortDistances() {
    std::sort(distances.begin(),distances.end());
}
void PointSet::sortPoint() {
    std::sort(points.begin(),points.end(),[](const Point&a,const Point&b) {
        return a.getX()>b.getX();
    });
}
int PointSet::numDistinctDistances() {
    return static_cast<int>(std::unique(distances.begin(),distances.end())-distances.begin());
}
void PointSet::sortPointsY() {
    std::sort(points.begin(),points.end(),[](const Point&a,const Point&b) {
        return a.getY()>b.getY();
    });
}










