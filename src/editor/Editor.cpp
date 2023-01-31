#include <iostream>
#include <string>
#include <utility>
#include <string_view>
#include <cstring>

#include "Editor.h"

namespace Tpp {
    TppArgs::TppArgs(int c, char **v) : type(Buffer::LinkedList) {
        for (int s = 0; s < c; s++) {
            // if there are fewer args in v than suggested by c param
            if (v[s] == nullptr || v[s][0] == '\0') break;
            // if arg is a valid option
            if (v[s][0] == '-'
                && (v[s][1] == 'g' || v[s][1] == 'l')
                && v[s][2] == '\0') {
                type = static_cast<Buffer::BufferType>(v[s][1]);
                continue;
            } else if (v[s][0] != '-') { // if not an option, make it a file
                if (check_filename(v[s]))
                    file = v[s];
                break;
            }
        }
    }

    bool TppArgs::check_filename(const char* s) {
        size_t len = std::strlen(s);
        auto ext = std::string_view(s + len - 3, 3);
        if (len > 4 &&
            s[len - 4] == '.' &&
                (ext == "txt" ||
                ext == "csv" ||
                ext == "cpp"))
            return true;
        return false;
    }

    void TppArgs::dbg() {
        std:: cout << typeid(this).name() << " [ " << type << ", " << file << " ],\n";
    }

    Editor::Editor() {
        doc = new Document(settings.type);
    }

    Editor::Editor(TppArgs args) : settings(std::move(args)) {
        doc = new Document(settings.type, settings.file);
    }

    Editor::~Editor() {
        delete doc;
    }

    bool Editor::run() {

    }

    bool Editor::execute(std::string &input) {

    }

    void Editor::dbg () {
        std::cout << typeid(this).name() << " {\n";
        settings.dbg();
        //doc.dbg();
        std::cout << "}";
    }
}