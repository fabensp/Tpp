#include "BufferStructure.h"

namespace Tpp {
    int BufferStructure::line_length () {
    return 0;
    }
    
    int BufferStructure::line_length (int l) {
        return 0;
    }
    
    int BufferStructure::line_count () {
        return 0;
    }
    
    int BufferStructure::cursor_line () {
        return 0;
    }
    
    int BufferStructure::cursor_index () {
        return 0;
    }
    
    std::string BufferStructure::doc2str () {
        return "";
    }
    
    std::string BufferStructure::line2str () {
        return "";
    }
    
    std::string BufferStructure::line2str (int l) {
        return "";
    }
    
    std::string BufferStructure::line_dbg () {
        return "";
    }
    
    void BufferStructure::load_line_start (std::string s) {
    
    }
    
    void BufferStructure::load_line_end (std::string s) {
    
    }
    
    void BufferStructure::load_line_at (std::string s, int l) {
    
    }
    
    bool BufferStructure::cur_left () {
        return false;
    }
    
    bool BufferStructure::cur_left (int c) {
        return false;
    }
    
    bool BufferStructure::cur_begl () {
        return false;
    }
    
    bool BufferStructure::cur_right () {
        return false;
    }
    
    bool BufferStructure::cur_right (int c) {
        return false;
    }
    
    bool BufferStructure::cur_endl () {
        return false;
    }
    
    bool BufferStructure::cur_up () {
        return false;
    }
    
    bool BufferStructure::cur_up (int c) {
        return false;
    }
    
    bool BufferStructure::cur_topl () {
        return false;
    }
    
    bool BufferStructure::cur_down () {
        return false;
    }
    
    bool BufferStructure::cur_down (int c) {
        return false;
    }
    
    bool BufferStructure::cur_btml () {
        return false;
    }
    
    bool BufferStructure::ins_la () {
        return false;
    }
    
    bool BufferStructure::ins_lb () {
        return false;
    }
    
    bool BufferStructure::ins_text (char c) {
        return false;
    }
    
    bool BufferStructure::ins_text (const std::string s) {
        return false;
    }
    
    bool BufferStructure::rm_line () {
        return false;
    }
    
    bool BufferStructure::rm_left () {
        return false;
    }
    
    
    BufferStructure::BufferStructure () : type(Buffer::Gap), cursor(0) {
        auto* i = new GapBuffer();
        head = new StructNode(i, nullptr);
    }
    
    BufferStructure::BufferStructure (Buffer::BufferType t) : type(t), cursor(0) {
        auto i = (type == Buffer::Gap) ? (Buffer*) new GapBuffer() : (Buffer*) new LinkedListBuffer();
        head = new StructNode(i, nullptr);
    }
    
    BufferStructure::~BufferStructure () {
        delete head;
    }
    
}