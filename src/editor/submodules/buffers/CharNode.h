#pragma once

#include <string>

namespace Tpp {
    class CharNode {
    protected:
        char v;
        CharNode* n;
        CharNode* p;
    public:
        explicit CharNode(char val) : p(0), n(0) { v = val; }
        CharNode(char val, CharNode* prev, CharNode* next) { v = val; p = prev; n = next; }
        
        void s_val  (char val)          { v = val; }
        void s_prev (CharNode* prev)    { p = prev; }
        void s_next (CharNode* next)    { n = next; }
        
        char        val ()  { return v; }
        CharNode*   prev () { return p; }
        CharNode*   next () { return n; }
        
    };
}