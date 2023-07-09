#include "Document.h"

namespace Tpp {
    Document::Document (Buffer::BufferType t) :
            type(t), buf_st(new BufferStructure(type)), dio() {}
    
    Document::Document (const std::string& f, Buffer::BufferType t) : Document(t) {
        load_file(f);
    }
    
    Document::~Document () {
        dio.close_file();
    }
    
    bool Document::load_file (const std::string& f) {
        if (f.empty()) return false;
        dio.open_file(f);
        buf_st->clear();
        buf_st->ins_text(dio.read_line());
        while (dio.has_more_lines())
            buf_st->load_line_end(dio.read_line());
        buf_st->cur_topl();
        buf_st->cur_begl();
        return true;
    }
    
    bool Document::store_file (const std::string& f) {
        dio.open_file(f);
        return dio.write_file(buf_st->doc2str());
    }
}