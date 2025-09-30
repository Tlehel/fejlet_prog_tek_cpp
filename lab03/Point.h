//
// Created by Lehel on 2025-09-30.
//

#ifndef POINT_H
#define POINT_H

const int M = 2000;
class Point{
private:
    int x, y;
public:
    explicit Point( int x=0, int y=0);
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] double distanceTo(const Point& point)const;
};

#endif //POINT_H
