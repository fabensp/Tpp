#pragma once

#include <fstream>
namespace Tpp {
    class DocumentIO {
    private: // members
        std::string filename;
        std::fstream file;
    public: // methods
        void open_file (std::string f);
        void close_file ();
        void write_file (std::string const& s);
        std::string read_line ();
        bool has_more_lines ();
        bool file_exists (std::string f);
        const std::string& file_name ();
        
        DocumentIO ();
        explicit DocumentIO (const std::string& f);
        ~DocumentIO ();
    private: // methods
    
    };
}