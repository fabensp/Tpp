#pragma once

#include "submodules/BufferStructure.h"
#include "submodules/DocumentIO.h"
#include <iostream>

namespace Tpp {
    class Document { // connects fs with working data
    private: // members
        Buffer::BufferType type;
        BufferStructure* buf_st; // text buffer structure
        DocumentIO dio;
    public: // methods
        bool load_file (const std::string& f); // read file f in to the editor. returns success
        bool store_file () { return dio.write_file(buf_st->doc2str()); } // write contents of buf_st to last read file
        bool store_file (const std::string& f); // write contents of buf_st to file f. returns success
        bool file_exists (const std::string& f) { return dio.file_exists(f); }
        std::string const& current_file_name () { return dio.file_name(); } // current file name
        std::string doc2str () { return buf_st->doc2str(); } // text contents of doc
        std::string line2str () { return buf_st->line2str(); } // text contents of current line
        std::string line2str (int l) { return buf_st->line2str(l); } // text contents of line l
        int line_length () { return buf_st->line_length(); } // length of current line
        int line_length (int l) { return buf_st->line_length(l); } // length of line l
        int line_count () { return buf_st->line_count(); } // # lines in doc
        int cursor_line () { return buf_st->cursor_line(); } // line the cursor is on
        int cursor_index () { return buf_st->cursor_index(); } // index of cursor in line
        std::string line_dbg() { return buf_st->line_dbg(); }
        std::string line_dbg(int l) { return buf_st->line_dbg(l); }
        
        bool cursor_left () { return buf_st->cur_left(); } // cursor left 1 char
        bool cursor_left (int c) { return buf_st->cur_left(c); } // cursor left c chars
        bool cursor_begl () { return buf_st->cur_begl(); } // cursor all the way left
        bool cursor_right () { return buf_st->cur_right(); } // cursor right 1 char
        bool cursor_right (int c) { return buf_st->cur_right(c); } // cursor right c chars
        bool cursor_endl () { return buf_st->cur_endl(); } // cursor all the way right
        bool cursor_up () { return buf_st->cur_up(); } // cursor up 1 char
        bool cursor_up (int c) { return buf_st->cur_up(c); } // cursor up c chars
        bool cursor_topl () { return buf_st->cur_topl(); } // cursor  1 char up
        bool cursor_down () { return buf_st->cur_down(); } // cursor down 1 char
        bool cursor_down (int c) { return buf_st->cur_down(c); } // cursor down c chars
        bool cursor_btml () { return buf_st->cur_btml(); } // cursor  1 char down
        
        bool ins_la () { return buf_st->ins_la(); } // insert line above
        bool ins_lb () { return buf_st->ins_lb(); } // insert line below
        bool ins_text (char c) { return buf_st->ins_text(c); } // insert a character
        bool ins_text (const std::string& s) { return buf_st->ins_text(s); } // insert characters
        bool rm_line () { return buf_st->rm_line(); } // remove current line
        bool rm_left () { return buf_st->rm_left(); } // remove char to left
        
        explicit Document (Buffer::BufferType t = Buffer::Gap); // doctype constructor
        explicit Document (const std::string& f, Buffer::BufferType t = Buffer::Gap); // doctype + file constructor
        ~Document ();
    };
}