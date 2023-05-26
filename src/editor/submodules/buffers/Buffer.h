#pragma once

#include <string>

namespace Tpp {
    class Buffer {
    public:
        enum BufferType { // type of line buffer to use
            Gap = 'g',
            LinkedList = 'l',
        };
    public:
        virtual std::string line2str () = 0;
        virtual std::string line_dbg () = 0;
        virtual int length () = 0;
        virtual int cursor_index () = 0;
        
        virtual bool cur_left () { return false; }; // cursor left 1 char
        virtual bool cur_right () { return false; }; // cursor right 1 char
        
        virtual bool ins_text (char c) { return false; }; // insert a character
        virtual bool rm_left () { return false; }; // remove char to left
    
        void load_string (const std::string& s);
        bool cur_left (int c); // cursor left c chars
        bool cur_begl (); // cursor all the way left
        bool cur_right (int c); // cursor right c chars
        bool cur_endl (); // cursor all the way right
        bool ins_text (const std::string& s); // insert characters
        bool rm_left (int c); // remove c chars to left
    };
}