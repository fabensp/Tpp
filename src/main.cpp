#include <iostream>

#include "unit.h"
#include "editor/Editor.h"

void testLinkedListBuffer() {
    Tpp::LinkedListBuffer llb;
    llb.load_string("hello \nworld");
    ASSERT_EQ(llb.line2str(), "hello world") // ignore the \n and print correctly
    ASSERT_EQ(llb.line_dbg(), "hello world|") // cursor at eol
    llb.rm_left();
    ASSERT_EQ(llb.line_dbg(), "hello worl|") // remove left of cursor
    llb.cur_left();
    ASSERT_EQ(llb.line_dbg(), "hello wor|l") // move within line
    llb.ins_text('d');
    ASSERT_EQ(llb.line_dbg(), "hello word|l") // insert mid-line
    llb.cur_begl();
    ASSERT_EQ(llb.line_dbg(), "|hello wordl") // start of line
    llb.ins_text('s');
    ASSERT_EQ(llb.line_dbg(), "s|hello wordl") // insert start of line
}

int main (int argc, char** argv) {
    
    testLinkedListBuffer();
    
    auto app = new Tpp::Editor(Tpp::TppArgs(argc, argv));
    while (app->run());
    delete app;
    
    return 0;
}
