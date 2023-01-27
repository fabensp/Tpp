#pragma once

#include "buffers/Buffer.h"
#include "StructNode.h"

class BufferStructure { // holds lines together
private: // members
    StructNode* head;
    int cursor;
    Buffer::BufferType type;
public: // methods
    int line_length ();
    int line_length (int l);
    char** line2str ();
    char** line2str (int l);
    char** line_dbg ();
    char** doc2str ();
    void

    BufferStructure ();
    BufferStructure (Buffer::BufferType t);
    ~BufferStructure ();
private: // methods

};