#include <iostream>
#include "functions.h"
#include "def.h"
using namespace std;


int main() {

    std::cout << "Hello, Lab_01" << std::endl;

    fort(128) {
        cout << countBits(i) << endl;
    }

    cout << ex_end;

    for (int i = 0; i < 35; ++i) {
    int n = 0;
    if(setBit(n, i)) {
    cout<<i<<" ---> " << n <<endl;
    } else {
    cout<<"Impossible operation!" << endl;
    }
    }

    cout << ex_end;

    int numelements = 3;
    double array[numelements] = {2,3,4};

    cout << mean(array,numelements)<< endl;

    cout << ex_end;

    cout << stddev(array,numelements) << endl;

    cout << ex_end;

    return 0;
}
