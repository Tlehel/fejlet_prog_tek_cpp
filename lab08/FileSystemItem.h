//
// Created by Lehel on 2025-11-11.
//

#ifndef FILESYSTEMITEM_H
#define FILESYSTEMITEM_H

#include <string>
#include <utility>

class FileSystemItem {
protected:
    std::string name;
    long size = 0;
public:
    FileSystemItem(std::string name,long size) : name(std::move(name)),size(size){}
    [[nodiscard]] virtual long getSize() const = 0;
    virtual void display(int depth = 0) const = 0;
    [[nodiscard]] virtual FileSystemItem* clone() const = 0;
    friend std::ostream& operator<<(std::ostream& os,FileSystemItem& f);
    friend bool operator<(const FileSystemItem& f1, const FileSystemItem& f2){return f1.name<f2.name;}
    virtual std::string getName(){return name;}
};



#endif //FILESYSTEMITEM_H
