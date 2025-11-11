//
// Created by Lehel on 2025-10-21.
//


#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <string>


class QuizItem {
public:
    QuizItem();
    void addQ(std::string q){this->question = move(q);}
    void addA(std::string a[],int c);
    std::string it();
    [[nodiscard]] int correctA() const{return this->correctAnswer;}
private:
    static int counter;
    unsigned int id;
    std::string question;
    std::string answers[];
    int correctAnswer = 0;
};




#endif //QUIZITEM_H
