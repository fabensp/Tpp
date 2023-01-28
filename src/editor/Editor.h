#pragma once

#include <string>

#include "Document.h"

namespace Tpp {
    class Editor { // highest layer of abstraction, holds document
    private: // members
        Document* doc;
        const struct { // holds the command line arguments passed when the application was run
            int c; // arg count
            char** v; // array of args
        } arg;
    public: // methods
        bool run (); // run an application cycle. returns whether to keep running
        bool execute (std::string& input); // execute a command. returns success
        std::string& str2filename (const char* s); // parse a string and format it to be an acceptable file name and format
        const std::string& current_file_name () { return doc->current_file_name(); } // current file name
        std::string& line2str () { return doc->line2str(); } // text contents of current line
        int line_length () { return doc->line_length(); } // length of current line
        int line_length (int l) { return doc->line_length(l); } // length of line l
        int line_count () { return doc->line_count(); } // # lines in doc
        int cursor_line () { return doc->cursor_line(); } // line the cursor is on
        int cursor_index () { return doc->cursor_index(); } // index of cursor in line
        
        Editor (); // default constructor
        Editor (int c, char** v); // cmd args constructor
        explicit Editor (char t); // doctype constructor
        ~Editor (); // destructor
        void operator delete (void* e); // delete overload
    };
}