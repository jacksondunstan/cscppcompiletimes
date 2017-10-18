cmake_minimum_required(VERSION 2.8)
project(GeneratedApp)
file(GLOB ClassCppFiles Class*.cpp)
add_executable(MyExecutable ${ClassCppFiles} Main.cpp)