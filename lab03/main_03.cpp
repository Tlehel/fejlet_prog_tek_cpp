#include <iostream>
#include <iomanip>
#include "PointSet.h"

int main() {
    std::cout << "Hello, Lab_03" << std::endl;
    int n = 2;
    std::cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"
    <<std::endl;
    std::cout<< std::fixed;
    for( int i= 0; i<12; ++i ){
        PointSet pSet( n );
        std::cout<<std::setw(6)<<n<<" ";
        std::cout<<std::setw(8)<<std::setprecision(2)<<pSet.minDistance()<<" ";
        std::cout<<std::setw(8)<<std::setprecision(2)<<pSet.maxDistance()<<" ";
        std::cout<<std::setw(10) << pSet.numDistances()<<" ";
        std::cout<<std::setw(16) << pSet.numDistinctDistances()<<std::endl;
        n = n << 1;
    }
    return 0;
}
