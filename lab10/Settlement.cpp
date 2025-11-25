//
// Created by Lehel on 2025-11-25.
//

#include "Settlement.h"

Settlement::Settlement(std::string n, std::string c, int p) {
    name = std::move(n);
    county = std::move(c);
    population = p;
}

std::string Settlement::getname() {
    return name;
}

std::string Settlement::getcountry() {
    return county;
}

int Settlement::getpop() {
    return population;
}

void Settlement::setname(std::string n) {
    name = std::move(n);
}

void Settlement::setcountry(std::string c) {
    county = std::move(c);
}

void Settlement::setpop(int p) {
    population = p;
}

std::ostream & operator<<(std::ostream &os) {

}

