#pragma once

class Buffer {
public:
    enum BufferType { // type of line buffer to use
        Gap = 'g',
        Link = 'l',
    };
public:
    void load_string (const std::string& s) {
        cur_endl();
        rm_left(length());
        ins_text(s);
    }
    virtual std::string& line2str ();
    virtual std::string& line_dbg ();
    virtual int length ();
    virtual int cursor_index ();
    
    bool cur_left (); // cursor left 1 char
    bool cur_left (int c); // cursor left c chars
    bool cur_begl (); // cursor all the way left
    bool cur_right (); // cursor right 1 char
    bool cur_right (int c); // cursor right c chars
    bool cur_endl (); // cursor all the way right
    
    bool ins_text (char c); // insert a character
    bool ins_text (const std::string& s); // insert characters
    bool rm_left (); // remove char to left
    bool rm_left (int c); // remove c chars to left
    
};