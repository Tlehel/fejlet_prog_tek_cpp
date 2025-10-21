//
// Created by Lehel on 2025-10-21.
//

#include "Quiz.h"

#include <utility>

Quiz::Quiz(std::string name) {
    counter++;
    this->id = counter;
    this->name = std::move(name);
}

void Quiz::addItem(const QuizItem& a) {
    if (!this->isReady)
    this->items.emplace_back(a);
}

void Quiz::finalize() {
    this->isReady = true;
}

