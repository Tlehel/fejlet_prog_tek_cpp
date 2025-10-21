//
// Created by Lehel on 2025-10-21.
//

#ifndef USER_H
#define USER_H
#include <map>
#include <string>


class User {
private:
    static int counter;
    int id;
    std::string name;
    std::map<int,double> results;
public:
    explicit User(std::string name);
    void addResult(std::pair<int,double>);
};



#endif //USER_H
