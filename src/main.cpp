#include <iostream>
#include "editor/Editor.h"
#include "tests/tests.h"

int main(int argc, char** argv) {
#ifdef TESTS
    test_LinkedListBuffer();
    test_GapBuffer();
    test_BufferStructure();
    test_DocumentIO();
    test_Document();
    T_REPORT();
#else
    auto args = Tpp::TppArgs(argc, argv);
    auto app = new Tpp::Editor(args);
    app->run();
    delete app;
#endif
    return 0;
}
