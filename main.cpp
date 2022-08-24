#include "ascii_table.h"
#include <emscripten/bind.h>

using namespace emscripten;

std::string getTable(int format, bool extended) {
    AsciiTable asciiTable(extended);
    asciiTable.setFormat(format);

    return asciiTable.getStringData();
}
EMSCRIPTEN_BINDINGS(my_module) {
    function("getTable", &getTable);
}

int main() {
    return 0;
}
