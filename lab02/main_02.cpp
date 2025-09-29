#include <iostream>
#include "Point.h"
#include "def.h"
#include "utils.h"

int main() {
    std::cout << "Hello, Lab_02" << std::endl;

        Point p1(2,3);
        std::cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<std::endl;
        Point p2(100, 200);
        std::cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<std::endl;
        Point * pp1 = new Point(300, 400);
        Point * pp2 = new Point(500, 1000);
        std::cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<std::endl;
        std::cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<std::endl;

    std::cout << ex_end;

    pp1->print();

    std::cout << distance(*pp1,*pp2) << std::endl << ex_end;

    Point * pp3 = new Point(10,0);
    Point * pp4 = new Point(10,10);

    std::cout << isSquare(*pp1,*pp2,*pp3,*pp4) << std::endl << ex_end;

    testIsSquare("points.txt");

    Point * pp5 = createArray(10);
    printArray(pp5,10);
        delete pp1;
        delete pp2;
        delete pp3;
        delete pp4;




    return 0;
}
