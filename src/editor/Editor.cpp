#include "Editor.h"

#include <utility>

namespace Tpp {
    TppArgs::TppArgs (int c, char** v) : type(Buffer::LinkedList), dbg(0) {
        for (int s = 1; s < c; s++) {
            // if arg is a valid option
            if (v[s][0] == '-' && v[s][2] == '\0') {
                if (v[s][1] == 'g') type = Buffer::Gap;
                if (v[s][1] == 'd') dbg = 1;
                continue;
            } else { // if not an option, make it a file
                file = v[s];
                break;
            }
        }
    }
    
    Editor::Editor () : Editor(TppArgs()){}
    
    Editor::Editor (TppArgs args) :
            settings(std::move(args)), view_start(0), cmd(0) {
        initscr();
        cbreak();
        keypad(stdscr, TRUE);
        noecho();
        doc = new Document(settings.file, settings.type);
        cmd_line = settings.type == Buffer::LinkedList ?
                (Buffer*) new LinkedListBuffer() :
                (Buffer*) new GapBuffer();
    }
    
    Editor::~Editor() {
        endwin();
        delete doc;
        delete cmd_line;
    }
    
    bool Editor::run () {
        clear();
        draw_screen();
        refresh();
        
        int ch = getch();
        if (!cmd) {
            switch (ch) {
                case KEY_DOWN:if (!doc->cursor_down()) beep();
                    break;
                case KEY_UP:if (!doc->cursor_up()) beep();
                    break;
                case KEY_LEFT:
                    if (!doc->cursor_left())
                        doc->cursor_up() ?
                        doc->cursor_endl() :
                        beep();
                    break;
                case KEY_RIGHT:
                    if (!doc->cursor_right())
                        doc->cursor_down() ?
                        doc->cursor_begl() :
                        beep();
                    break;
                case KEY_BACKSPACE:
                case 127:
                case '\b':
                    if (!cursor_index()) {
                        std::string temp = line2str();
                        doc->rm_line();
                        doc->cursor_endl();
                        doc->ins_text(temp);
                        doc->cursor_left((int) temp.length());
                    } else doc->rm_left();
                    break;
                case KEY_ENTER:
                case '\n':
                case 13: {
                    doc->ins_lb();
                    int pos = cursor_index();
                    doc->cursor_endl();
                    std::string temp_beg = line2str().substr(0, pos);
                    std::string temp_end = line2str().substr(pos);
                    while (doc->rm_left());
                    doc->ins_text(temp_beg);
                    doc->cursor_down();
                    doc->ins_text(temp_end);
                    doc->cursor_begl();
                }
                    break;
                case KEY_EXIT:
                case 27:
                    cmd = 1;
                    break;
                default:
                    if (ch < 128 && ch > 31 && line_length() < 80)
                        cmd_line.ins_text((char) ch);
            }
        } else {
            switch (ch) {
                case KEY_ENTER:
                case '\n':
                case 13:
                    break;
                case KEY_BACKSPACE:
                case 127:
                case '\b':
                    break;
                default:
                    if (ch < 128 && ch > 31 && line_length() < 80)
                        doc->ins_text((char) ch);
            }
        }
        return true;
    }
    
    void Editor::draw_screen () {
        clear();
        resize_term(13, 100);
        
        mvprintw(0, 0, "Tpp : ");
        std::string file = current_file_name();
        printw(file.empty() ? "<no file open>" : file.c_str());
        mvprintw(1, 4, ":");
        
        while(cursor_line() > view_start + 9)
            view_start++;
        while(cursor_line() < view_start)
            view_start--;
        
        for (int i = 0; i < 10; i++) {
            if (i < line_count()) {
                mvprintw(i + 2, 1, std::to_string(view_start + i + 1).c_str());
                mvprintw(i + 2, 4, "|");
                if (!settings.dbg) printw(doc->line2str(view_start + i).c_str());
                else printw(doc->line_dbg(view_start + i).c_str());
            } else {
                mvprintw(i + 2, 4, ".");
            }
        }
        mvprintw(12, 0,"LC: ");
        printw(std::to_string(line_count()).c_str());
        
        curs_set(2);
        move(cursor_line() + 2 - view_start, cursor_index() + 5);
    }
}
