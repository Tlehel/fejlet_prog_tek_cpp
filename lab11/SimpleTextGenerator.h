//
// Created by Lehel on 2025-12-02.
//

#ifndef SIMPLETEXTGENERATOR_H
#define SIMPLETEXTGENERATOR_H
#include "TextGenerator.h"
#include <string>
#include <map>
#include <vector>

class SimpleTextGenerator:public TextGenerator{
  std::map<std::string,std::vector<std::string>> statistic;
public:
  void trainFromText(std::string trainingText) override = 0;
  void trainFromFile(std::string filename) override;
  std::string generate(std::string startWords, int numWords=10) override;
  ~SimpleTextGenerator() override;
  SimpleTextGenerator() = default;
  std::map<std::string,std::vector<std::string>> getStatistics(){return statistic;}
};



#endif //SIMPLETEXTGENERATOR_H
