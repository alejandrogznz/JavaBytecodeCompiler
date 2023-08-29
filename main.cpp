#include <iostream>
#include "./Include/ClassFile.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << endl;
    }

    ClassFile f;
    return 0;
}