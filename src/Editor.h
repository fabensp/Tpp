#pragma once

#include <string>

#include "Document.h"

class Editor { // highest layer of abstraction, holds document
public: // members

private: // members
    Document* doc;
    struct { // holds the command line arguments passed when the application was run
        int c; // arg count
        char** v; // array of args
    } arg;
public: // methods
    bool run (); // run an application cycle. returns whether to keep running
    bool execute (std::string input); // execute a command. returns success
    const char** str2filename (const char* s); // parse a string and format it to be an acceptable file name and format
    const char** current_file_name () { return doc->current_file_name(); } // current file name
    char** line2str () { return doc->line2str(); } // text contents of current line
    int line_length () { return doc->line_length(); } // length of current line
    int line_length (int l) { return doc->line_length(l); } // length of line l
    int line_count () { return doc->line_count(); } // # lines in doc
    int cursor_line () { return doc->cursor_line(); } // line the cursor is on
    int cursor_index () { return doc->cursor_index(); } // index of cursor in line

    Editor (); // default constructor
    Editor (int c, char** v); // cmd args constructor
    explicit Editor (char t); // doctype constructor
    ~Editor (); // destructor
private: // methods

};