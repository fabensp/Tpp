#include "CursorNode.h"

namespace Tpp {
    bool CursorNode::left () {
        if (!p) return false;
        if (n) n->s_prev(p); // make current neighbors see each other
        p->s_next(n);
        n = p; // shift self back
        p = p->prev();
        if (p) p->s_next(this); // tell new neighbors about self
        n->s_prev(this);
        return true;
    }
    
    bool CursorNode::right () {
        if (!n) return false;
        if (p) p->s_next(n); // make current neighbors see each other
        n->s_prev(p);
        p = n; // shift self forward
        n = n->next();
        if (n) n->s_prev(this); // tell new neighbors about self
        p->s_next(this);
        return true;
    }
    
    bool CursorNode::rm_left () {
        if (!p) return false;
        CharNode* temp = p;
        p = p->prev();
        p->s_next(this);
        delete temp;
        return true;
    }
    
    bool CursorNode::ins_text (char val) {
        if (val < 32) return false; // don't allow empty chars
        auto temp = new CharNode(val);
        temp->s_prev(p);
        temp->s_next(this);
        if (p) p->s_next(temp);
        p = temp;
        return true;
    }
}