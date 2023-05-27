#pragma once

#include "buffers/GapBuffer.h"
#include "buffers/LinkedListBuffer.h"

namespace Tpp {
    class StructNode {
    private: // members
        Buffer* i; // stored item
        StructNode* p; // prev node
        StructNode* n; // next node
    public: // methods
        void s_prev (StructNode* prev) { p = prev; } // set prev node
        void s_next (StructNode* next) { n = next; } // set next node
        StructNode* prev () { return p; } // get prev node
        StructNode* next () { return n; } // get next node
        Buffer* item () { return i; } // get stored item
        
        StructNode (Buffer* i, StructNode* p, StructNode* n) : i(i), p(p), n(n) {}
        
        ~StructNode () {
            delete i;
        }
    };
}