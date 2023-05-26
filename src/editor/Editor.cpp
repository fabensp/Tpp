#include "Editor.h"

namespace Tpp {
    TppArgs::TppArgs (int c, char** v) : type(Buffer::LinkedList) {
        for (int s = 0; s < c; s++) {
            // if there are fewer args in v than suggested by c param
            if (v[s] == nullptr || v[s][0] == '\0') break;
            // if arg is a valid option
            if (v[s][0] == '-' &&
                (v[s][1] == 'g' || v[s][1] == 'l') &&
                v[s][2] == '\0') {
                type = static_cast<Buffer::BufferType>(v[s][1]);
                continue;
            } else if (v[s][0] != '-') { // if not an option, make it a file
                file = v[s] + 1;
                break;
            }
        }
    }
    
    Editor::Editor () : Editor(TppArgs(1, (char**) "-l")){}
    
    Editor::Editor (TppArgs args) : settings(std::move(args)) {
        doc = new Document(settings.type, settings.file);
        initscr();
        curs_set(0);
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
    }
    
    Editor::~Editor() {
        endwin();
        delete doc;
    }
    
    bool Editor::run () {
        clear();
        refresh();
        mvprintw(10, 10, "hello world");
        int ch = getch();
        return ch != 'h';
    }
    
    bool Editor::execute (std::string& input) {
        return doc == nullptr;
    }
}