cmake_minimum_required(VERSION 3.2)
project(CPP_UTILS CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS ON)

add_compile_options(-Wall)
add_compile_options(-pthread)


add_executable(run_singleton_test singleton_test.cc)