#include <iostream>

#include "Directory.h"

int main() {
    std::cout << "Hello, Lab_08" << std::endl;

    Directory a("root");
    Directory b("documents");
    a.add(&b);
    b.add(FileSystemItem("reports.txt",1500));
    b.add(FileSystemItem("notes.txt",1500));
    Directory c("pictures");
    a.add(&c);
    c.add(FileSystemItem("photo1",200000));
    c.add(FileSystemItem("photo2",200000));
    a.add(FileSystemItem("aaaa",3));
    return 0;
}
