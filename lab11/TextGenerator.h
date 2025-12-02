//
// Created by Lehel on 2025-12-02.
//

#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H
#include <string>

class TextGenerator {
public:
virtual void trainFromText(std::string trainingText) = 0;
virtual void trainFromFile(std::string filename) = 0;
virtual std::string generate(std::string startWords, int numWords=10) = 0;
virtual ~TextGenerator() = default;
};


#endif //TEXTGENERATOR_H
