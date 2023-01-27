#pragma once

#include "BufferStructure.h"
#include "DocumentIO.h"

namespace Tpp {
    class Document { // connects fs with working data
    private: // members
        Buffer::BufferType type;
        BufferStructure* buf_st; // text buffer structure
        DocumentIO dio;
    public: // methods
        bool load_file (const std::string& f); // read file f in to the editor. returns success
        bool store_file (); // write contents of buf_st to last read file
        bool store_file (const std::string& f); // write contents of buf_st to file f. returns success
        bool file_exists (const std::string& f) { return dio.file_exists(f); } // checks if file f exists in the fs
        const std::string& current_file_name () { return dio.file_name(); } // current file name
        std::string& doc2str () { return buf_st->doc2str(); } // text contents of doc
        std::string& line2str () { return buf_st->line2str(); } // text contents of current line
        std::string& line2str (int l) { return buf_st->line2str(l); } // text contents of line l
        int line_length () { return buf_st->line_length(); } // length of current line
        int line_length (int l) { return buf_st->line_length(l); } // length of line l
        int line_count () { return buf_st->line_count(); } // # lines in doc
        int cursor_line () { return buf_st->cursor_line(); } // line the cursor is on
        int cursor_index () { return buf_st->cursor_index(); } // index of cursor in line
        
        bool cur_left () { return buf_st->cur_left(); } // cursor left 1 char
        bool cur_left (int c) { return buf_st->cur_left(c); } // cursor left c chars
        bool cur_begl () { return buf_st->cur_begl(); } // cursor all the way left
        bool cur_right () { return buf_st->cur_right(); } // cursor right 1 char
        bool cur_right (int c) { return buf_st->cur_right(c); } // cursor right c chars
        bool cur_endl () { return buf_st->cur_endl(); } // cursor all the way right
        bool cur_up () { return buf_st->cur_up(); } // cursor up 1 char
        bool cur_up (int c) { return buf_st->cur_up(c); } // cursor up c chars
        bool cur_topl () { return buf_st->cur_topl(); } // cursor  1 char up
        bool cur_down () { return buf_st->cur_down(); } // cursor down 1 char
        bool cur_down (int c) { return buf_st->cur_down(c); } // cursor down c chars
        bool cur_btml () { return buf_st->cur_btml(); } // cursor  1 char down
        
        bool ins_la () { return buf_st->ins_la(); } // insert line above
        bool ins_lb () { return buf_st->ins_lb(); } // insert line below
        bool ins_text (char c) { return buf_st->ins_text(c); } // insert a character
        bool ins_text (std::string& s) { return buf_st->ins_text(s); } // insert characters
        bool rm_line () { return buf_st->rm_line(); } // remove current line
        bool rm_left () { return buf_st->rm_left(); } // remove char to left
        
        Document ();
        explicit Document (Buffer::BufferType t);
        ~Document () {
            delete buf_st, this;
        }
    };
}