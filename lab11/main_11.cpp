#include <iostream>

#include "SimpleTextGenerator.h"

int main() {
    std::cout << "Hello, Lab_11" << std::endl;
    std::string word = "Now is not the time for sleep, now is the time for party!";

    SimpleTextGenerator gen;
    gen.trainFromText(word);

    return 0;
}
