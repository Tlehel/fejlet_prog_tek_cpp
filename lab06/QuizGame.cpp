//
// Created by Lehel on 2025-10-21.
//

#include "QuizGame.h"

#include <iostream>


void QuizGame::runQuiz() {
    for (auto e:this->quiz.items) {
        std::cout<<e.it();
        int x;
        std::cin>>x;
        if (x-1 == e.correctA()) {
            this->correct++;
        }
        this->total++;
    }
}

void QuizGame::score() {
    std::cout<<this->correct << "correct answears from: " << this->total;
    double prs = correct/total;
    std::cout<<std::endl<<prs<<"%"<<std::endl;
    this.user.addResult(std::make_pair(this->quiz.getid(),prs));
}


