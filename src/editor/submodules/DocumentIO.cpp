#include "DocumentIO.h"

namespace Tpp {
    void DocumentIO::open_file (std::string f) {
    
    }
    
    void DocumentIO::close_file () {
    
    }
    
    void DocumentIO::write_file (std::string const& s) {
    
    }
    
    std::string DocumentIO::read_line() {
        return "";
    }
    
    bool DocumentIO::has_more_lines () {
        return false;
    }
    
    bool DocumentIO::file_exists (std::string f) {
        return false;
    }
    
    std::string const& DocumentIO:: file_name () {
        return "";
    }
    
    DocumentIO::DocumentIO () = default;
    
    DocumentIO::DocumentIO (const std::string& f) {
        file.open(f);
    }
    
    DocumentIO::~DocumentIO () = default;
    
}