#include <iostream>
#include "unit.h"
#include "editor/Editor.h"

#define UNIT

void testLinkedListBuffer() {
    TEST(Tpp::LinkedListBuffer);
    Tpp::LinkedListBuffer b;
    b.load_string("hello \n");
    ASSERT_EQ(b.line2str(), "hello "); // ignore the \n and print correctly
    ASSERT_EQ(b.line_dbg(), "hello |"); // cursor at eol
    ASSERT(b.ins_text("world"));
    ASSERT_EQ(b.line_dbg(), "hello world|");
    ASSERT(b.rm_left());
    ASSERT_EQ(b.line_dbg(), "hello worl|"); // remove left of cursor
    ASSERT(b.cur_left());
    ASSERT_EQ(b.line_dbg(), "hello wor|l"); // move within line
    ASSERT(b.ins_text('d'));
    ASSERT_EQ(b.line_dbg(), "hello word|l"); // insert mid-line
    ASSERT(b.cur_begl());
    ASSERT_EQ(b.line_dbg(), "|hello wordl"); // start of line
    ASSERT(b.ins_text('s'));
    ASSERT_EQ(b.line_dbg(), "s|hello wordl"); // insert start of line
    ASSERT_EQ(b.line2str(), "shello wordl"); // still prints correctly with cursor mid-line
    ASSERT_EQ(b.cursor_index(), 1);
    ASSERT_EQ(b.length(), 12);
}

void testGapBuffer() {
    TEST(Tpp::GapBuffer);
    Tpp::GapBuffer b;
    b.load_string("hello \n");
    ASSERT_EQ(b.line2str(), "hello "); // ignore the \n and print correctly
    ASSERT_EQ(b.line_dbg(), "hello ______"); // cursor at eol
    ASSERT(b.ins_text("world"));
    ASSERT_EQ(b.line_dbg(), "hello world_______"); // insert text, grow by 6
    ASSERT(b.rm_left());
    ASSERT_EQ(b.line_dbg(), "hello worl__"); // remove left of cursor, shrink by 6
    ASSERT(b.cur_left());
    ASSERT_EQ(b.line_dbg(), "hello wor__l"); // move within line
    ASSERT(b.ins_text('d'));
    ASSERT_EQ(b.line_dbg(), "hello word_______l"); // insert mid-line, grow by 6
    ASSERT(b.cur_begl());
    ASSERT_EQ(b.line_dbg(), "_______hello wordl"); // start of line
    ASSERT(b.ins_text('s'));
    ASSERT_EQ(b.line_dbg(), "s______hello wordl"); // insert start of line
    ASSERT_EQ(b.line2str(), "shello wordl"); // still prints correctly with cursor mid-line
    ASSERT_EQ(b.cursor_index(), 1);
    ASSERT_EQ(b.length(), 12);
}

void testLLBufferStructure() {
    TEST(Tpp::BufferStructure (Linked List));
    Tpp::BufferStructure s (Tpp::Buffer::LinkedList);
    ASSERT(s.ins_text("hello world"));
    ASSERT_EQ(s.line2str(), "hello world");
    ASSERT(s.ins_lb());
    ASSERT(s.cur_down());
    ASSERT(s.ins_text("peas and carrots"));
    ASSERT_EQ(s.doc2str(), "hello world\npeas and carrots\n");
    ASSERT(s.cur_left(7));
    ASSERT(s.ins_text("glazed "));
    ASSERT_EQ(s.doc2str(), "hello world\npeas and glazed carrots\n");
    ASSERT(s.cur_up());
    ASSERT(s.ins_text(" :D"));
    ASSERT_EQ(s.doc2str(), "hello world :D\npeas and glazed carrots\n");
    ASSERT_EQ(s.line_dbg(), "hello world :D|");
    ASSERT(s.cur_down());
    ASSERT_EQ(s.line_dbg(), "peas and glaze|d carrots");
    s.load_line_start("welcome");
    ASSERT_EQ(s.doc2str(), "welcome\nhello world :D\npeas and glazed carrots\n");
    s.load_line_end("the end");
    ASSERT_EQ(s.doc2str(), "welcome\nhello world :D\npeas and glazed carrots\nthe end\n");
    s.load_line_at("intermission", 2);
    ASSERT_EQ(s.doc2str(), "welcome\nhello world :D\nintermission\npeas and glazed carrots\nthe end\n");
}

void testGBufferStructure() {
    TEST(Tpp::BufferStructure (Gap));
    Tpp::BufferStructure s (Tpp::Buffer::Gap);
    ASSERT(s.ins_text("hello world"));
    ASSERT_EQ(s.line2str(), "hello world");
    ASSERT(s.ins_lb());
    ASSERT(s.cur_down());
    ASSERT(s.ins_text("peas and carrots"));
    ASSERT_EQ(s.doc2str(), "hello world\npeas and carrots\n");
    ASSERT(s.cur_left(7));
    ASSERT(s.ins_text("glazed "));
    ASSERT_EQ(s.doc2str(), "hello world\npeas and glazed carrots\n");
    ASSERT(s.cur_up());
    ASSERT(s.ins_text(" :D"));
    ASSERT_EQ(s.doc2str(), "hello world :D\npeas and glazed carrots\n");
    ASSERT_EQ(s.line_dbg(), "hello world :D____");
    ASSERT(s.cur_down());
    ASSERT_EQ(s.line_dbg(), "peas and glaze____d carrots");
    s.load_line_start("welcome");
    ASSERT_EQ(s.doc2str(), "welcome\nhello world :D\npeas and glazed carrots\n");
    s.load_line_end("the end");
    ASSERT_EQ(s.doc2str(), "welcome\nhello world :D\npeas and glazed carrots\nthe end\n");
    s.load_line_at("intermission", 2);
    ASSERT_EQ(s.doc2str(), "welcome\nhello world :D\nintermission\npeas and glazed carrots\nthe end\n");
}

void testDocumentIO() {
    TEST(Tpp::DocumentIO);
    Tpp::DocumentIO dio ("./testing.txt");
    
    ASSERT_EQ(dio.read_line(), "hello");
    ASSERT_EQ(dio.read_line(), "hello");
    ASSERT_EQ(dio.read_line(), "hello");
    
    ASSERT(!dio.has_more_lines());
    dio.write_file("test\ntest\ntest");
    ASSERT_EQ(dio.read_line(), "test");
    ASSERT_EQ(dio.read_line(), "test");
    ASSERT_EQ(dio.read_line(), "test");
    ASSERT(!dio.has_more_lines());
    
    dio.write_file("hello\nhello\nhello");
    ASSERT_EQ(dio.read_line(), "hello");
    ASSERT_EQ(dio.read_line(), "hello");
    ASSERT_EQ(dio.read_line(), "hello");
    ASSERT(!dio.has_more_lines());
}

int main (int argc, char** argv) {
#ifdef UNIT
    testLinkedListBuffer();
    testGapBuffer();
    testLLBufferStructure();
    testGBufferStructure();
    testDocumentIO();
#else
    auto app = new Tpp::Editor(Tpp::TppArgs(argc, argv));
    while (app->run());
    delete app;
#endif
    return 0;
}
