//
// Created by Lehel on 2025-10-21.
//

#include "QuizItem.h"

QuizItem::QuizItem() {
    counter ++;
    this->id = counter;
}

void QuizItem::addA(std::string a[], const int c) {
    for (int i=0;i<4;i++) {
        this->answers[i] = move(a[i]);
    }
    this->correctAnswer = c;
}

std::string QuizItem::it() {
    std::string a = question + "\n1" + answers[0] + "\n2" + answers[1] + "\n3" + answers[2] + "\n4" + answers[3] + "\n";
    return a;
}


