#ifndef FILEEDITOR_H
#define FILEEDITOR_H
#include<string>
#include<vector>
#include<iostream>
// DO NOT use std namespace;

class FileEditor: public std::vector<std::string> {
public:
    FileEditor(char* fName);
    void write(std::ostream& out = std::cout);
};

#endif
