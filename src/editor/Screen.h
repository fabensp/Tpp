#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>

class Screen
{
public:
    Screen();
    Screen(int cursor, int echo);
    virtual ~Screen();
    
    virtual void run(); // virtual function
    int get_input() { return getch(); }
    void echo_set(int e);
    void cursor_set(int c);
    void refresh_screen();
    void clear_screen();
    void close_window();
    void print(int row, int col, const char str[]);
    
};

#endif // SCREEN_H
