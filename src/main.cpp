#include <iostream>

#include "Editor.h"

int main (int argc, char** argv) {
    
    auto app = new Tpp::Editor(argc, argv);
    while (app->run());
    delete app;
    std::cout << "Goodbye!";
    return 0;
}