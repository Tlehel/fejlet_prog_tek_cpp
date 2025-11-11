//
// Created by Lehel on 2025-11-11.
//

#ifndef FILE_H
#define FILE_H
#include <utility>

#include "FileSystemItem.h"
#include <iostream>

class File : FileSystemItem {
public:
    File(std::string name,long size) : FileSystemItem(std::move(name),size){}
    [[nodiscard]] long getSize() const override{return size;}
    void display(int depth = 0) const override{std::cout<<name<<" "<<size<<std::endl;}


};



#endif //FILE_H
