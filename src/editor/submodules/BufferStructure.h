#pragma once

#include <string>
#include "buffers/Buffer.h"
#include "StructNode.h"

namespace Tpp {
    class BufferStructure { // holds lines together
    private: // members
        StructNode* head;
        int cursor;
        Buffer::BufferType type;
    public: // methods
        int line_length (); // length of current line
        int line_length (int l); // length of line l
        int line_count (); // # lines in doc
        int cursor_line (); // line the cursor is on
        int cursor_index (); // index of cursor in line
        std::string doc2str (); // text contents of doc
        std::string line2str (); // text contents of current line
        std::string line2str (int l); // text contents of line l
        std::string line_dbg (); // debug representation of the current line
        void load_line_start (std::string s);
        void load_line_end (std::string s);
        void load_line_at (std::string s, int l);
        
        bool cur_left (); // cursor left 1 char
        bool cur_left (int c); // cursor left c chars
        bool cur_begl (); // cursor all the way left
        bool cur_right (); // cursor right 1 char
        bool cur_right (int c); // cursor right c chars
        bool cur_endl (); // cursor all the way right
        bool cur_up (); // cursor up 1 char
        bool cur_up (int c); // cursor up c chars
        bool cur_topl (); // cursor  1 char up
        bool cur_down (); // cursor down 1 char
        bool cur_down (int c); // cursor down c chars
        bool cur_btml (); // cursor  1 char down
    
        bool ins_la (); // insert line above
        bool ins_lb (); // insert line below
        bool ins_text (char c); // insert a character
        bool ins_text (const std::string s); // insert characters
        bool rm_line (); // remove current line
        bool rm_left (); // remove char to left
        
        BufferStructure ();
        BufferStructure (Buffer::BufferType t);
        ~BufferStructure ();
    
    private: // methods
        StructNode* get_node (int i); // iterate through lines to get a specific index
        Buffer* new_buffer (); // return a new buffer of the correct type
    };
}