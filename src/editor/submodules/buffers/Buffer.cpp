#include <iostream>
#include "Buffer.h"

namespace Tpp {
    void Buffer::load_string (const std::string& s) {
        cur_endl();
        while(rm_left());
        ins_text(s);
    }
    
    bool Buffer::cur_begl () {
        int out = 0;
        while (cur_left()) out++;
        return out;
    }
    
    bool Buffer::cur_endl () {
        int out = 0;
        while (cur_right()) out++;
        return out;
    }
    
    bool Buffer::cur_right (int c) {
        int out = 0;
        for (int i = 0; i < c; i++) {
            out += cur_right();
        }
        return out;
    }
    
    bool Buffer::cur_left (int c) {
        int out = 0;
        for (int i = 0; i < c; i++) {
            out += cur_left();
        }
        return out;
    }
    
    bool Buffer::ins_text (const std::string& s) {
        int out = 0;
        for (char c : s) {
            out += ins_text(c);
        }
        return out;
    }
    
    bool Buffer::rm_left (int c) {
        int out = 0;
        for (int i = 0; i < c; i++) {
            out += rm_left();
        }
        return out;
    }
}