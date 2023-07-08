#include "Document.h"

namespace Tpp {
    Document::Document (Buffer::BufferType t) :
            type(t), buf_st(new BufferStructure(type)), dio() {}
    
    Document::Document (std::string const& f, Buffer::BufferType t) : Document(t) {
        load_file(f);
    }
    
    Document::~Document () {
        dio.close_file();
        delete buf_st;
    }
    
    void Document::load_file (const std::string& f) {
        dio.open_file(f);
        buf_st->ins_text(dio.read_line());
        while (dio.has_more_lines())
            buf_st->load_line_end(dio.read_line());
        buf_st->cur_topl();
        buf_st->cur_begl();
    }
    
    bool Document::store_file () {
        return dio.write_file(buf_st->doc2str());
    }
    
    void Document::dbg() {
        buf_st->cur_topl();
        std::cout << "{type=" << type << ", buf_st=[";
        for (int i = 0; i < buf_st->line_count() - 1; i++) {
            std:: cout << "\"" << buf_st->line_dbg() << "\", ";
            buf_st->cur_down();
        }
        std:: cout << "\"" << buf_st->line_dbg() << "\"], "
        << "dio={filename=" << dio.file_name() << "}}" << std::endl;
    }
}