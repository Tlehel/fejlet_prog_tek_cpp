//
// Created by Lehel on 2025-10-21.
//

#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>

#include "QuizItem.h"


class Quiz {
public:
    explicit Quiz(std::string);
    void addItem(const QuizItem&);
    void finalize();
    std::vector<QuizItem> items;
    int getid(){return this->id;}

private:
    static int counter;
    unsigned int id;
    std::string name;
    bool isReady = false;
};



#endif //QUIZ_H
