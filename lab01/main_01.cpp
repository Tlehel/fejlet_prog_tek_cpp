#include <iostream>
#include <sstream>
#include <string>
#include "functions.h"
#include "def.h"
using namespace std;

int countWords(string text);
string code(string text);

int main() {

    std::cout << "Hello, Lab_01" << std::endl;

    fort(128) {
        cout << countBits(i) << endl;
    }

    cout << ex_end;

    fort(35) {
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

    pair<double,double> k = max2(array,numelements);

    cout << k.first <<" "<<k.second << endl;
    cout << ex_end << ex_end;

    string str;
    str = "./a.out 1.1 2.2 3.3 alma korte 4.4";
    //cin >> str;
    istringstream inputstream(str);
    string word;

    double sum = 0;
    while(inputstream >> word){
        istringstream wordstream(word);
        double number;
        if( wordstream >> number ) {
            sum+= number;
        }
    }
    cout << sum << endl << ex_end;

    cout << countWords("az alma egy mosolygos allat nagy fogakkal") << endl << ex_end;




    return 0;
}

int countWords(string text) {
    istringstream txt(text);
    string word;
    int count = 0;
    while(txt >> word) count++;
    return count;
}
string code(string text) {
    
}