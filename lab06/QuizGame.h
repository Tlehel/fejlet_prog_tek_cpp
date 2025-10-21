//
// Created by Lehel on 2025-10-21.
//

#ifndef QUIZGAME_H
#define QUIZGAME_H
#include <utility>

#include "Quiz.h"
#include "User.h"


class QuizGame {
private:
    Quiz quiz;
    User user;
    int correct = 0;
    int total = 0;
public:
    QuizGame(Quiz q,User u): quiz(std::move(q)), user(std::move(u)){}
    void runQuiz();
    void score();
};



#endif //QUIZGAME_H
