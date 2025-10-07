#include <iostream>

#include "Polynomial.h"

int main() {
    std::cout << "Hello, Lab_04" << std::endl;

    double t1[] = {1,-9,1.2,54,6.4,-8,25},t2[] = {23,3.14,8.5,-61,2.7,9.7,23,11};
    auto *p1 = new Polynomial(6,t1);
    auto *p2 = new Polynomial(7,t2);

    std::cout <<*p1 <<std::endl;
    std::cout <<-*p1 << std::endl;
    std::cout <<*p1 + -*p2 << std::endl;
    return 0;
}
