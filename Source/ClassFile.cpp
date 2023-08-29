#include "../Include/ClassFile.hpp"



ClassFile::ClassFile() {
    std::cout << "Hello World" << std::endl;
}

ClassFile::ClassFile(char *filename) {
    std::cout << "Classfile Name: " << filename << std::endl;
    std::ifstream file(filename, std::ios::binary);
    
    this->magic_number = readUnsignedInt(file);

    printClassFile();
}

unsigned int ClassFile::readUnsignedInt(std::ifstream &openfile) {
    const int WORD_SIZE = 4;
    unsigned int res = 0;
    char * buf = new char[WORD_SIZE];
    openfile.read(buf, WORD_SIZE);
    res =  *reinterpret_cast<unsigned int *>(buf);
    delete [] buf;
    res = htonl(res);
    return res;

}

unsigned short int ClassFile::readUnsignedShortInt(std::ifstream &openfile) {
    const unsigned int SHORT_SIZE = 2;
    unsigned short int res = 0;
    char * buf = new char[SHORT_SIZE];
    openfile.read(buf, SHORT_SIZE);
    res = *reinterpret_cast<unsigned short int *>(buf);
    delete [] buf;
    //res = htons(res);
    return res;
}

void ClassFile::printClassFile() {
    std::cout << "Magic Number: 0x" << std::hex << this->magic_number << std::endl;
}