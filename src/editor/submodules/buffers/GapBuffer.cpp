#include "GapBuffer.h"

namespace Tpp {
    GapBuffer::GapBuffer() : GapBuffer(12) {}
    
    GapBuffer::GapBuffer (int s) : size(s), cursor(0), line(new char[size + 1]) {
        for (int i = 0; i < size; i++) line[i] = 7;
        line[size] = '\0';
    }
    
    GapBuffer::~GapBuffer () {
        delete[] line;
    }
    
    std::string GapBuffer::line2str () {
        std::string out;
        for (int i = 0; i < size; i++) {
            if (line[i] == 7) continue;
            out += line[i];
        }
        return out;
    }
    
    std::string GapBuffer::line_dbg () {
        std::string out;
        for (int i = 0; i < size; i++) {
            if (line[i] == 7) out += '_';
            else out += line[i];
        }
        return out;
    }
    
    int GapBuffer::length () {
        int out = 0;
        for (int i = 0; i < size; i++) {
            if (line[i] == 7) continue;
            out++;
        }
        return out;
    }
    
    int GapBuffer::cursor_index () {
        return cursor;
    }
    
    
    bool GapBuffer::cur_left () {
        if (cursor == 0) return false;
        int buf_end = cursor;
        while (line[buf_end + 1] == 7) buf_end++;
        line[buf_end] = line[--cursor];
        line[cursor] = 7;
        return true;
    }
    
    bool GapBuffer::cur_right () {
        if (cursor == length()) return false;
        int buf_end = cursor;
        while (line[buf_end] == 7) buf_end++;
        line[cursor++] = line[buf_end];
        line[buf_end] = 7;
        return true;
    }
    
    bool GapBuffer::ins_text (char c) {
        if (c < 32) return false;
        line[cursor++] = c;
        check_size();
        return true;
    }
    
    bool GapBuffer::rm_left () {
        if (cursor == 0) return false;
        line[--cursor] = 7;
        check_size();
        return true;
    }
    
    void GapBuffer::check_size () {
        int new_size = size;
        if (size - 1 <= length()) { // if line almost full,
            new_size += size/2; // increase size by 50%
        } else if (size >= 15 && size * 2/3 > length()) { // if line larger than minimum and less than 2/3 full,
            new_size -= size/3; // decrease size by 33%
        } else return; // if neither needs to happen return
        
        char* temp = new char[new_size + 1]; // alloc new space and fill with empties
        for (int i = 0; i < new_size; i++) temp[i] = 7;
        temp[new_size] = '\0';
    
        int buf_end = cursor;
        while (line[buf_end] == 7) buf_end++; // find end of buffer
        for (int i = 0; i < cursor; i++) temp[i] = line[i]; // transfer first half of buffer
        for (int i = buf_end; i < size; i++) temp[i + new_size - size] = line[i]; // transfer second half
    
        delete[] line;
        line = temp;
        size = new_size;
    }
}