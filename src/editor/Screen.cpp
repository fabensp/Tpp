#include "screen.h"

void Screen::start(int cursor, int echo) {
    initscr();
    curs_set(cursor);
    cbreak();
    if (!echo) noecho();
    keypad(stdscr, TRUE);
}

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
