//
// Created by Lehel on 2025-11-25.
//

#ifndef SETTLEMENT_H
#define SETTLEMENT_H
#include <string>


class Settlement {
std::string name = "";
std::string county = "";
int population = 0;
// constructor, getters, setters, inserter operator
public:
    Settlement():population(0){}
    Settlement(std::string n,std::string c,int p);

    std::string getname();
    std::string getcountry();
    int getpop();

    void setname(std::string n);
    void setcountry(std::string c);
    void setpop(int p);

    friend std::ostream& operator<<(std::ostream& os);
};




#endif //SETTLEMENT_H
