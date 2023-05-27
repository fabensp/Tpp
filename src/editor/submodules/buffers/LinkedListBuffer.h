#pragma once

#include "Buffer.h"
#include "CharNode.h"
#include "CursorNode.h"

namespace Tpp {
    class LinkedListBuffer : public Buffer {
    private:
        CursorNode* cursor;
        CharNode* head;
    public:
        LinkedListBuffer();
        ~LinkedListBuffer() override;
        
        std::string line2str () override;
        std::string line_dbg () override;
        int length () override;
        int cursor_index () override;
    
        using Buffer::cur_left;
        using Buffer::cur_right;
        using Buffer::ins_text;
        using Buffer::rm_left;
    
        bool cur_left () override; // cursor left 1 char
        bool cur_right () override; // cursor right 1 char
    
        bool ins_text (char c) override; // insert a character
        bool rm_left () override; // remove char to left
    };
}