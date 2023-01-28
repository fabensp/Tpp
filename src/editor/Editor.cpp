#include "Editor.h"

namespace Tpp {
    Editor::Editor () : arg({0, nullptr}) {
        doc = new Document ();
    }
    
    Editor::Editor (int c, char** v) : arg({c, v}) {
        for (int s = 0; s < c; s++) {
            if (v[s] == nullptr) break; // if there are fewer args than suggested by c
            char* o = v[s];
        }
    }
}