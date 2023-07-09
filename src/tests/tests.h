#include "../editor/Editor.h"
#include "../unit.h"

TEST("linked list buffer can move in line and edit contents", LinkedListBuffer, {
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
    ASSERT_EQ(b.length(), 12);
    ASSERT_EQ(b.cursor_index(), 1);
    ASSERT(b.rm_left());
    ASSERT_EQ(b.line2str(), "hello wordl"); // remove first char correctly
    ASSERT(!b.rm_left());
    ASSERT_EQ(b.line2str(), "hello wordl"); // do nothing and return false when cursor at beginning of line
});

TEST("gap buffer can move in line and edit contents", GapBuffer, {
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
    ASSERT(b.rm_left());
    ASSERT_EQ(b.line2str(), "hello wordl"); // remove first char correctly
    ASSERT(!b.rm_left());
    ASSERT_EQ(b.line2str(), "hello wordl"); // do nothing and return false when cursor at beginning of line
});

TEST("buffer structure can traverse and edit lines", BufferStructure, {
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
    ASSERT_EQ(s.line_count(), 5);
});

TEST("document io can read and write", DocumentIO, {
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
});

TEST("document can interface buffer structure and doc io", Document, {
    Tpp::Document doc ("./testing.txt", Tpp::Buffer::Gap);
    
    ASSERT_EQ(doc.line2str(), "hello");
    ASSERT(doc.ins_text("why "));
    ASSERT_EQ(doc.line2str(), "why hello");
    ASSERT(doc.cursor_down());
    ASSERT(doc.cursor_endl());
    ASSERT(doc.ins_text(" there"));
    ASSERT_EQ(doc.line2str(), "hello there");
    ASSERT(doc.cursor_down());
    ASSERT(doc.ins_text(" :)"));
    ASSERT_EQ(doc.line2str(), "hello :)");
});

TEST("document can be edited but not saved when given no file name", DocumentNoFile, {
    Tpp::Document doc;
    
    ASSERT(doc.ins_text("my test"));
    ASSERT(doc.ins_lb());
    ASSERT(doc.cursor_down());
    ASSERT(doc.ins_text("second line"));
    ASSERT_EQ(doc.doc2str(), "my test\nsecond line\n");
    ASSERT(doc.current_file_name().empty());
    ASSERT(!doc.store_file());
});
