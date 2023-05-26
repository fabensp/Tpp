#pragma once

#include "CharNode.h"

namespace Tpp {
    class CursorNode : public CharNode {
    public:
        CursorNode(char val) : CharNode(val) {};
        
        bool left ();
        bool right ();
        bool rm_left ();
        bool ins_text (char val);
    };
}