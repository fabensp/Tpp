#include <iostream>

#include "editor/Editor.h"

int main (int argc, char** argv) {
    
    auto app = new Tpp::Editor(argc, argv);
    while (app->run());
    delete app;
    
    return 0;
}

namespace Tpp {

}