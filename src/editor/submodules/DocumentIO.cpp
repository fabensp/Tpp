#include "DocumentIO.h"

namespace Tpp {
    void DocumentIO::open_file (std::string f) {
        if (f.empty()) return;
        close_file();
        if (file_exists(f)) is.open(f);
        filename = f;
    }
    
    void DocumentIO::close_file () {
        if (is.is_open()) is.close();
        filename = "";
    }
    
    bool DocumentIO::write_file (const std::string& s) {
        if (filename.empty()) return false;
        std::ofstream os;
        is.close();
        os.open(filename);
        os << s;
        os.close();
        return true;
    }
    
    std::string DocumentIO::read_line() {
        if (!is.is_open()) is.open(filename);
        std::string out;
        getline(is, out);
        return out;
    }
    
    bool DocumentIO::has_more_lines () {
        return is.good();
    }
    
    bool DocumentIO::file_exists (const std::string& f) {
        return std::filesystem::exists(f);
    }
    
    const std::string& DocumentIO::file_name () {
        return filename;
    }
    
    DocumentIO::DocumentIO () = default;
    
    DocumentIO::DocumentIO (const std::string& f) {
        open_file("./testing.txt");
    }
    
    DocumentIO::~DocumentIO () = default;
    
}