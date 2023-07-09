#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>

class Screen {
public:
    static void start(int, int);
    static void run(); // virtual function
    static int get_input() { return getch(); }
    static void echo_set(int e);
    static void cursor_set(int c);
    static void refresh_screen();
    static void clear_screen();
    static void close_window();
    static void print(int row, int col, const char str[]);
    
};

#endif // SCREEN_H
