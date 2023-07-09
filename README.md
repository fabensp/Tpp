# Tpp
**C++ remake of CS150 Java text editor.**

## To Build
Build with CMake v3.5+, to run unit tests build with -DTESTS=1 in the CMake build params
Depending on run environment, you may need to have `mingw32-w64` installed and have the path to it's `/bin` directory in your PATH variable so Windows can find some .dll files it needs.
To run the project as-is you need Qt Creator installed on your computer in the C:/ drive in order to access `ncurses`. If you have `ncurses` somewhere else you can configure CMakeLists.txt to point there.
