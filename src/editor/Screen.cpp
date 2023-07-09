#include "screen.h"

Screen::Screen() : Screen(0, 0) {}

Screen::Screen(int cursor, int echo) {
    initscr();
    
    curs_set(cursor);
    
    // disables line buffering and erase/kill character-processing
    // (interrupt and flow control characters are unaffected),
    // making characters typed by the  user  immediately
    // available to the program
    cbreak();
    
    // control whether characters  typed  by  the user  are echoed
    // by getch as they are typed
    if (!echo) noecho();
    
    // the user can press a function key (such as an arrow key) and
    // getch returns a single value representing the  function  key,
    // as in KEY_LEFT
    keypad(stdscr, TRUE);
}

Screen::~Screen() { close_window(); }

void Screen::run() {}

void Screen::echo_set(int e) {
    if (e)  echo();
    else    noecho();
}

void Screen::cursor_set(int c) {
    curs_set(c);
}

void Screen::refresh_screen() {
    refresh();
}

void Screen::clear_screen() {
    clear();
}

void Screen::close_window() {
    endwin();
}

void Screen::print(int row, int col, const char str[]) {
    mvprintw(row, col, str);
}
