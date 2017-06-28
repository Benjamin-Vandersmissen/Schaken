    cmake_minimum_required(VERSION 3.6)
project(Schaken)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Pion.cpp Pion.h Koning.cpp Koning.h Koningin.cpp Koningin.h Paard.cpp Paard.h Loper.cpp Loper.h Toren.cpp Toren.h Schaakbord.cpp Schaakbord.h GameWindow.cpp GameWindow.h)


include_directories(FLTK)
link_directories(usr/local/lib)

add_executable(Schaken ${SOURCE_FILES})
target_link_libraries(Schaken fltk_images fltk X11 Xext pthread Xfixes dl m)
