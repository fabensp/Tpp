#pragma once

#include <fstream>
#include <filesystem>

namespace Tpp {
    class DocumentIO {
    private: // members
        std::string filename;
        std::ifstream is;
    public: // methods
        void open_file (const std::string& f);
        void close_file ();
        bool write_file (std::string const& s);
        std::string read_line ();
        bool has_more_lines ();
        static bool file_exists (const std::string& f);
        const std::string& file_name ();
        
        DocumentIO ();
        explicit DocumentIO (const std::string& f);
        ~DocumentIO ();
    };
}