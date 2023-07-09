#include "BufferStructure.h"

namespace Tpp {
    int BufferStructure::line_length () {
    return cursor->item()->length();
    }
    
    int BufferStructure::line_length (int l) {
        StructNode* temp = get_node(l);
        if (!temp) return -1;
        return temp->item()->length();
    }
    
    int BufferStructure::line_count () {
        StructNode* temp = head;
        int out = 1;
        while ((temp = temp->next()) != nullptr) out++;
        return out;
    }
    
    int BufferStructure::cursor_line () {
        StructNode* temp = head;
        int out = 0;
        while (temp != cursor) {
            out++;
            temp = temp->next();
            if (!temp) return -1;
        }
        return out;
    }
    
    int BufferStructure::cursor_index () {
        return cursor->item()->cursor_index();
    }
    
    std::string BufferStructure::doc2str () {
        StructNode* temp = head;
        std::string out = temp->item()->line2str();
        while ((temp = temp->next()) != nullptr) {
            out += "\n" + temp->item()->line2str();
        }
        return out;
    }
    
    std::string BufferStructure::line2str () {
        return cursor->item()->line2str();
    }
    
    std::string BufferStructure::line2str (int l) {
        StructNode* temp = get_node(l);
        if (!temp) return "\a";
        return temp->item()->line2str();
    }
    
    std::string BufferStructure::line_dbg () {
        return cursor->item()->line_dbg();
    }
    
    std::string BufferStructure::line_dbg (int l) {
        return get_node(l)->item()->line_dbg();
    }
    
    void BufferStructure::load_line_start (const std::string& s) {
        cur_topl();
        ins_la();
        cur_up();
        ins_text(s);
    }
    
    void BufferStructure::load_line_end (const std::string& s) {
        cur_btml();
        ins_lb();
        cur_down();
        ins_text(s);
        
    }
    
    void BufferStructure::load_line_at (const std::string& s, int l) {
        StructNode* temp = get_node(l);
        if (!temp) return;
        cursor = temp;
        ins_la();
        cur_up();
        ins_text(s);
    }
    
    bool BufferStructure::cur_left () {
        return cursor->item()->cur_left();
    }
    
    bool BufferStructure::cur_left (int c) {
        return cursor->item()->cur_left(c);
    }
    
    bool BufferStructure::cur_begl () {
        return cursor->item()->cur_begl();
    }
    
    bool BufferStructure::cur_right () {
        return cursor->item()->cur_right();
    }
    
    bool BufferStructure::cur_right (int c) {
        return cursor->item()->cur_right(c);
    }
    
    bool BufferStructure::cur_endl () {
        return cursor->item()->cur_endl();
    }
    
    bool BufferStructure::cur_up () {
        if (!cursor->prev()) return false;
        cursor = cursor->prev();
        return true;
    }
    
    bool BufferStructure::cur_up (int c) {
        int out = 0;
        for (; c > 0; c--) out += cur_up();
        return out;
    }
    
    bool BufferStructure::cur_topl () {
        cursor = head;
        return true;
    }
    
    bool BufferStructure::cur_down () {
        if (!cursor->next()) return false;
        int pos = cursor->item()->cursor_index();
        cursor = cursor->next();
        cursor->item()->cur_begl();
        cursor->item()->cur_right(pos);
        return true;
    }
    
    bool BufferStructure::cur_down (int c) {
        int out = 0;
        for (; c > 0; c--) out += cur_down();
        return out;
    }
    
    bool BufferStructure::cur_btml () {
        while (cur_down());
        return true;
    }
    
    bool BufferStructure::ins_la () {
        Buffer* item;
        if (type == Buffer::Gap) item = new GapBuffer();
        else item = new LinkedListBuffer();
        
        auto temp = new StructNode(item, cursor->prev(), cursor);
        if (cursor->prev()) cursor->prev()->s_next(temp);
        cursor->s_prev(temp);
        if (cursor == head) head = cursor->prev();
        return true;
    }
    
    bool BufferStructure::ins_lb () {
        Buffer* item;
        if (type == Buffer::Gap) item = new GapBuffer();
        else item = new LinkedListBuffer();
    
        auto temp = new StructNode(item, cursor, cursor->next());
        if (cursor->next()) cursor->next()->s_prev(temp);
        cursor->s_next(temp);
        return true;
    }
    
    bool BufferStructure::ins_text (char c) {
        return cursor->item()->ins_text(c);
    }
    
    bool BufferStructure::ins_text (const std::string& s) {
        return cursor->item()->ins_text(s);
    }
    
    bool BufferStructure::rm_line () {
        if (cursor == head && !cursor->next()) ins_la();
        cursor->prev()->s_next(cursor->next());
        if (cursor->next()) cursor->next()->s_prev(cursor->prev());
        StructNode* temp = cursor;
        if (cursor->prev()) cursor = cursor->prev();
        delete temp;
        return true;
    }
    
    bool BufferStructure::rm_left () {
        return cursor->item()->rm_left();
    }
    
    bool BufferStructure::clear() {
        delete head;
        auto i = (type == Buffer::Gap) ? (Buffer*) new GapBuffer() : (Buffer*) new LinkedListBuffer();
        head = cursor = new StructNode(i, nullptr, nullptr);
    }
    
    StructNode* BufferStructure::get_node (int i) {
        StructNode* temp = head;
        for (; i > 0; i--) {
            if ((temp = temp->next()) == nullptr) break;
        }
        return temp;
    }
    
    BufferStructure::BufferStructure () : BufferStructure(Buffer::LinkedList) {}
    
    BufferStructure::BufferStructure (Buffer::BufferType t) : type(t) {
        auto i = (type == Buffer::Gap) ? (Buffer*) new GapBuffer() : (Buffer*) new LinkedListBuffer();
        head = new StructNode(i, nullptr, nullptr);
        cursor = head;
    }
    
    BufferStructure::~BufferStructure () {
        StructNode* temp = head;
        while (temp->next() != nullptr) {
            temp = temp->next();
            delete temp->prev();
        }
        delete temp;
    }
    
}