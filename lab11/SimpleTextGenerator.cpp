//
// Created by Lehel on 2025-12-02.
//

#include "SimpleTextGenerator.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>

void SimpleTextGenerator::trainFromText(std::string trainingText) {
    std::stringstream temp(trainingText);
    std::vector<std::string> words;
    std::string word;
    while (temp >> word) {
        words.emplace_back(word);
    }
    for (std::string wor : words) {
        std::for_each(words.begin(), words.end(),[&wor](char& c) {
            c = tolower(c);
            if (c == ',' or c =='!') {
                wor = wor.substr(0,wor.length()-1);
            }
        });
        //std::cout << wor;
    }
    std::vector<std::string> values;
    for (int i=0;i<=words.size()-2;i++) {
        values.emplace_back(words[i+2]);
        std::string key = words.at(i)+"-"+words.at(i+1);
        if (i==words.size()-3) {
            std::vector<std::string> defaultvec;
            if(statistic.find(key)==statistic.end())
                statistic[key] = defaultvec;
            break;
        }
        if (statistic.find(key)==statistic.end()) {
            statistic[key] = values;
        }else {
            statistic[key].emplace_back(values.at(i+2));
        }
        values.clear();
    }
    std::string key = words.at(words.size()-3)+"-"+words.at(words.size()-2);
    std::vector<std::string> items;
    items.emplace_back(words.at(words.size()-1));
    if(statistic.find(key)==statistic.end())
    statistic[key] = items;
    else
        statistic[key].emplace_back(words.at(words.size()-1));
}

void SimpleTextGenerator::trainFromFile(std::string filename) {
    std::ifstream f(filename);
    if(!f.is_open()) exit(-3);

}

std::string SimpleTextGenerator::generate(std::string startWords, int numWords) {
    std::stringstream temp(startWords);
    std::string word1 ;
    std::getline(temp,word1);
    std::string word2 ;
    temp >> word2;
    std::string sentence;

    sentence += word1+" "+word2;
    for (int i=0;i<numWords;i++) {
        std::vector<std::string> values = getStatistics()[startWords];
        std::string s;
        if (values.size() > 1) {
            s = values.at(1);
        }else {
            s = values.at(0);
        }
        word1 = word2;
        word2 = s;
        startWords = word1+"-"+word2;
        sentence += " "+s;
    }
    return sentence;
}

SimpleTextGenerator::~SimpleTextGenerator() = default;
