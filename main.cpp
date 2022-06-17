#include <iostream>
#include "ascii_table.h"
#include <emscripten/bind.h>

using namespace emscripten;

std::string getTable(int format) {
    AsciiTable asciiTable;
    std::cout << "from getTable " << format << std::endl;
    asciiTable.setFormat(format);
    asciiTable.printTable();
    return "";
//    return asciiTable.getStringData();
}
int getNum(int n) {
    return n;
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("getTable", &getTable);
//    function("getNum", &getNum);
}

int main() {
//    getTable(4);
    return 0;
}
