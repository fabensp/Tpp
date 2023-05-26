#include "Document.h"

namespace Tpp {
    Document::Document () : type(Buffer::Gap), buf_st(new BufferStructure(type)), dio() {}
    
    Document::Document (Buffer::BufferType t) : type(t), buf_st(new BufferStructure(type)), dio() {}
    
    Document::Document (Buffer::BufferType t, std::string const& f) :
            type(t), buf_st(new BufferStructure(type)), dio(f) {}
    
    Document::~Document () {
        delete buf_st;
    }
    
    bool Document::load_file (const std::string& f) {
    return buf_st == nullptr;
    }
    
    bool Document::store_file () {
    return buf_st == nullptr;
    }
    
    bool Document::store_file (const std::string& f) {
    return buf_st == nullptr;
    }
    
}