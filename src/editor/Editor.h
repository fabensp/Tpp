#pragma once

#include <string>
#include <ncurses.h>
#include "Document.h"

namespace Tpp {
    struct TppArgs { // holds info on currently open document file and buffer type
    public:
        Buffer::BufferType type;
        std::string file;
        int dbg;
        
        TppArgs () : type(Buffer::LinkedList) {}
        TppArgs (int c, char** v);
    };
    
    class Editor { // highest layer of abstraction, holds document
    private: // members
        Document* doc;
        TppArgs settings;
        int view_start;
        int cmd_mode;
        Buffer* cmd_line;
    public: // methods
        bool run (); // run an application cycle. returns whether to keep running
        int execute(const std::string& command); // execute application command
        std::string current_file_name () { return doc->current_file_name(); } // current file name
        std::string line2str () { return doc->line2str(); } // text contents of current line
        int line_length () { return doc->line_length(); } // length of current line
        int line_length (int l) { return doc->line_length(l); } // length of line l
        int line_count () { return doc->line_count(); } // # lines in doc
        int cursor_line () { return doc->cursor_line(); } // line the cursor is on
        int cursor_index () { return doc->cursor_index(); } // index of cursor in line
        
        Editor (); // default constructor
        explicit Editor (TppArgs args); // cmd_mode args constructor
        ~Editor (); // destructor
    private: // methods
        void draw_screen();
    };
}