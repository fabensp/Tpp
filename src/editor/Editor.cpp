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
    
    Editor::Editor (TppArgs args) : settings(std::move(args)), Screen() {
        doc = new Document(settings.file, settings.type);
    }

    Editor::~Editor() { delete doc; }

    void Editor::run () {
        int continue_looping = 1;

        do {
            draw_screen();

            // draw the new screen
            refresh_screen();
        
            // obtain character from keyboard
            int ch = get_input();
        
            // operate based on input character
            switch (ch) {
                case KEY_DOWN:
                    doc->cursor_down();
                    break;
                case KEY_UP:
                    doc->cursor_up();
                    break;
                case KEY_LEFT:
                    doc->cursor_left();
                    break;
                case KEY_RIGHT:
                    doc->cursor_right();
                    break;
                case KEY_BACKSPACE:
                    doc->rm_left();
                case 'q':
                    continue_looping = false;
                default:
                    if (ch < 256)
                        doc->ins_text((char) ch);
                }

        } while (continue_looping);
    }
    
    bool Editor::execute (std::string& input) {
        return doc == nullptr;
    }
    
    void Editor::draw_screen () {
        clear_screen();

        print(0, 0, "Tpp | ");
        print(0, 6, doc->current_file_name().c_str());
        print(1, 0, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        print(2, 2, doc->line2str(0).c_str());
    }
}
