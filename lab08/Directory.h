//
// Created by Lehel on 2025-11-11.
//

#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <algorithm>
#include <iostream>

#include "FileSystemItem.h"
#include <vector>


class Directory : FileSystemItem{
    std::vector<FileSystemItem*> children;
public:
    explicit Directory(const std::string& name) : FileSystemItem(name,0){}
    ~Directory(){
        for (auto e: children)delete e;
    }
    void add(FileSystemItem* item){children.emplace_back(item);}
    void remove(const std::string& name) {
        auto pos = std::find_if(children.begin(),children.end(),[name](FileSystemItem& f) {
            return name == f.getName();
        });
        children.erase(pos);
    }
    FileSystemItem* find(const std::string& name) {
        for (auto c: children) {
            if (name == c->getName()) {
                return c;
            }
        }
        return nullptr;
    }
    long getSize(){return size;}
    void display() {
        std::cout << name <<": "<<std::endl;
        for (auto c: children) {
            c->display();
        }
    }

};



#endif //DIRECTORY_H
