#pragma once

#include <fstream>

class DocumentIO {
private: // members
    std::string filename;
    std::fstream file;
public: // methods
    void open_file (char* f);
    void close_file ();
    void write_file (std::string& s);
    std::string& read_line();
    bool has_more_lines ();
    bool file_exists ();
    const std::string& file_name ();
    
    DocumentIO ();
    DocumentIO (std::string& f);
    ~DocumentIO ();
private: // methods

};