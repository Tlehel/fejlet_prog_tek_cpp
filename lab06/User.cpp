//
// Created by Lehel on 2025-10-21.
//

#include "User.h"

User::User(std::string name) {
    this->name = move(name);
    counter++;
    this->id = counter;
}

void User::addResult(std::pair<int,double> ab) {
    this->results.insert(ab);
}

