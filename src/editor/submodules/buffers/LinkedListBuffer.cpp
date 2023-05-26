#include "LinkedListBuffer.h"

#define CURSOR 7

namespace Tpp {
    LinkedListBuffer::LinkedListBuffer () {
        cursor = new CursorNode(CURSOR);
        head = cursor;
    }
    
    LinkedListBuffer::~LinkedListBuffer () {
        CharNode* temp = head;
        while ((temp = temp->next()) != nullptr) {
            delete temp->prev();
        }
        delete temp;
    }
    
    std::string LinkedListBuffer::line2str () {
        std::string out;
        CharNode* temp = head;
        do {
            if (temp->val() == CURSOR) continue;
            out += temp->val();
        } while ((temp = temp->next()) != nullptr);
        return out;
    }
    
    std::string LinkedListBuffer::line_dbg () {
        std::string out;
        CharNode* temp = head;
        do {
            if (temp->val() == CURSOR) out += '|';
            else out += temp->val();
        } while ((temp = temp->next()) != nullptr);
        return out;
    }
    
    int LinkedListBuffer::length () {
        int out = 0;
        CharNode* temp = head;
        while ((temp = temp->next()) != nullptr) out++;
        return out - 1; // subtract one for cursor
    }
    
    int LinkedListBuffer::cursor_index () {
        int out = 0;
        CharNode* temp = head;
        while ((temp = temp->next()) != cursor) out++;
        return out;
    }
    
    bool LinkedListBuffer::cur_left () {
        int out = 0;
        out += cursor->left();
        if (out && head->prev() == cursor) head = cursor;
        return out;
    }
    
    bool LinkedListBuffer::cur_right () {
        int out = 0;
        out += cursor->right();
        if (out && head == cursor) head = cursor->prev();
        return out;
    }
    
    bool LinkedListBuffer::ins_text (char c) {
        int out = 0;
        out += cursor->ins_text(c);
        if (out && head == cursor) head = cursor->prev();
        return out;
    }
    
    bool LinkedListBuffer::rm_left () {
        return cursor->rm_left();
    }
}