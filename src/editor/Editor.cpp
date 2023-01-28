#include <string>
#include <utility>
#include <string_view>
#include <cstring>

#include "Editor.h"

namespace Tpp {
    TppArgs::TppArgs (int c, char** v) : type(Buffer::LinkedList) {
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
                file = str2filename(v[s] + 1);
                break;
            }
        }
    }
    
    std::string& TppArgs::str2filename (char* s) {
        int i = 0;
        auto len = std::strlen(s);
        do {
            if (s[i] == '.') break;
            i++;
        } while (s[i] != '\0');
        s[i] = '\0';
        std::string_view ext(s + i + 1, len - i);
        ext = (ext == "txt" || ext == "csv" || ext == "cpp") ? ext : "txt";
        //return s + (s + i + 1);
    }
    
    Editor::Editor () {
        doc = new Document(settings.type);
    }
    
    Editor::Editor (TppArgs args) : settings(std::move(args)) {
        doc = new Document(settings.type, settings.file);
    }
}