#ifndef JAVABYTECODECOMPILER_INCLUDE_CLASSFILE_HPP
#define JAVABYTECODECOMPILER_INCLUDE_CLASSFILE_HPP

#include <iostream>
#include <fstream>
#include <arpa/inet.h>
#include <iomanip>

class ClassFile {
public:
    ClassFile();
    ClassFile(char *filename);

private:
    unsigned int magic_number;

    unsigned short int readUnsignedShortInt(std::ifstream &openfile);
    unsigned int readUnsignedInt(std::ifstream &openfile);

    void printClassFile();
};

#endif //