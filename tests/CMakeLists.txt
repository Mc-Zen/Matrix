cmake_minimum_required(VERSION 3.13)

project(Matrix_Tests)

find_package(Catch2 3 REQUIRED)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tests matrix_tests.cpp solvers_tests.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

