#pragma once

#include "Buffer.h"
namespace Tpp {
    class GapBuffer : public Buffer {
    
    public:
        std::string line2str () override;
        std::string line_dbg () override;
        int length () override;
        int cursor_index () override;
        
        bool cur_left () override; // cursor left 1 char
        bool cur_right () override; // cursor right 1 char
        
        bool ins_text (char c) override; // insert a character
        bool rm_left () override; // remove char to left
    };
}