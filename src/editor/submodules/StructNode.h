#pragma once

#include "buffers/GapBuffer.h"
#include "buffers/LinkedListBuffer.h"

namespace Tpp {
    class StructNode {
    private: // members
        Buffer* i; // stored item
        StructNode* n; // next node
    public: // methods
        void s_next (StructNode* next) { n = next; } // set next node
        StructNode* next () { return n; } // get next node
        Buffer* item () { return i; } // get stored item
        
        StructNode (Buffer* i, StructNode* n) : i(i), n(n) {}
        
        ~StructNode () {
            delete i;
            delete n;
        }
    };
}