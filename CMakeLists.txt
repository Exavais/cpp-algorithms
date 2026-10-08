cmake_minimum_required(VERSION 3.16)

project(cpp_algorithms
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_sort
    tests/test_sort.cpp
)

add_executable(test_search
    tests/test_search.cpp
)

target_include_directories(test_sort
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(test_search
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
