cmake_minimum_required(VERSION 3.24)
project(Tpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tpp src/main.cpp src/editor/Editor.cpp src/editor/Document.cpp src/editor/submodules/BufferStructure.cpp src/editor/submodules/DocumentIO.cpp src/editor/submodules/buffers/GapBuffer.cpp src/editor/submodules/buffers/LinkedListBuffer.cpp src/editor/submodules/buffers/Buffer.cpp src/editor/submodules/buffers/CursorNode.cpp src/tests/tests.h src/editor/Screen.cpp src/editor/Screen.h)

include_directories(C:/QT/Tools/mingw1120_64/opt/include/ncursesw)
include_directories(C:/QT/Tools/mingw1120_64/opt/include)

find_library(LIBNCURSES ncurses C:/QT/Tools/mingw1120_64/opt/lib)

target_link_libraries(Tpp ${LIBNCURSES})

if (TESTS)
    add_definitions(-DTESTS=1)
endif (TESTS)